#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <list>
#include "AdditiveNoise.h"
#include "bmp.h"

class GaussianFilter {
private:
	BITMAPFILEHEADER* bfh;
	BITMAPINFOHEADER* bih;
	YCbCr** noise_ycbcr;
	YCbCr** result_ycbcr;
	YCbCr** ycbcr;
	RGB** rgb;
	int height;
	int width;
	int R = 0;
	double sigma;
	double max_PSNR = 0;
	int max_R = 0;
	double max_sigma_filter = 0;

public:
	GaussianFilter(RGB** color, YCbCr** y, YCbCr** y1, int h, int w, BITMAPFILEHEADER* bf, BITMAPINFOHEADER* bi, int r, double s) {
		rgb = color;
		ycbcr = y1;
		noise_ycbcr = y;
		height = h;
		width = w;
		bfh = bf;
		bih = bi;
		R = r;
		sigma = s;

		result_ycbcr = new YCbCr * [height];
		for (int i = 0; i < height; i++)
			result_ycbcr[i] = new YCbCr[width];

		gaussian_method();
		
	}

	GaussianFilter(RGB** color, YCbCr** y1, int h, int w, BITMAPFILEHEADER* bf, BITMAPINFOHEADER* bi) {
		rgb = color;
		ycbcr = y1;
		height = h;
		width = w;
		bfh = bf;
		bih = bi;


		result_ycbcr = new YCbCr * [height];
		for (int i = 0; i < height; i++)
			result_ycbcr[i] = new YCbCr[width];

	}
	void get_image(const char* filename) {
		FILE* file;
		file = fopen(filename, "wb");
		write_bmp_ycbcr(file, result_ycbcr, bfh, bih, height, width);
		fclose(file);
	}


	~GaussianFilter() {
		for (int i = 0; i < height; i++)
			delete (result_ycbcr[i]);
		delete result_ycbcr;
	}

	void gaussian_method() {
		YCbCr** new_ycbcr = new YCbCr * [height + R * 2];
		for (int i = 0; i < height + R * 2; i++) {
			new_ycbcr[i] = new YCbCr[width + R * 2];
			for (int j = 0; j < width + R * 2; j++) {
				new_ycbcr[i][j].Y = 0;
			}
		}
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				new_ycbcr[i + R][j + R].Y = noise_ycbcr[i][j].Y;
			}
		}

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				double tmp = 0;
				double sum_w = 0;
				for (int k = -R; k <= R; k++) {
					for (int m = -R; m <= R; m++) {
						double w = exp((-((pow(k,2) + pow(m,2))) / (2 * pow(sigma,2))));
						sum_w += w;
						tmp += w * new_ycbcr[i + R + k][j + R + m].Y;
					}
				}
				result_ycbcr[i][j].Y = tmp / sum_w;
			}
		}

		for (int i = 0; i < height + 2 * R; i++)
			delete (new_ycbcr[i]);
		delete new_ycbcr;
	}

	double PSNR() {
		double tmp = width * height * pow(256 - 1, 2);
		double PSNR = 0;
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				PSNR += pow((ycbcr[i][j].Y - result_ycbcr[i][j].Y), 2);
			}
		}
		PSNR = 10 * log10(tmp / PSNR);
		//cout << "PSNR = " << PSNR << endl;
		return PSNR;
	}

	void write_to_file(const char* filename, double res) {
		ofstream file;
		file.open(filename, ios::app);
		file << sigma << " " << res << endl;
		file.close();
	}

	void find_max_PSNR() {
		vector<int> sigma_noise = { 1,10,30,50,80 };
		vector<int> radius = { 1,3,5 };
		for (int i = 0; i < sigma_noise.size(); i++) {
			max_PSNR = 0;
			max_R = 0;
			max_sigma_filter = 0;
			for (int j = 0; j < radius.size(); j++) {				
				double PSNR_from_file = 0;
				double sigma_filter_from_file = 0;
				int R_from_file = radius[j];
				string filename = "R" + to_string(R_from_file) + "sigmaNoise" + to_string(sigma_noise[i]) + ".txt";
				ifstream in(filename);				
				if (in.is_open())
				{
					while (in >> sigma_filter_from_file >> PSNR_from_file)
					{
						if (max_PSNR < PSNR_from_file)
						{
							max_PSNR = PSNR_from_file;
							max_R = R_from_file;
							max_sigma_filter = sigma_filter_from_file;
						}
					}
				}
				in.close();
			}
			cout << "sigma_noise = " << sigma_noise[i] << endl;
			cout << "max PSNR = " << max_PSNR << " R = " << max_R << " sigma_filter = " << max_sigma_filter << endl << endl;
		}
	}

	void get_best_picrute() {
		sigma = max_sigma_filter;
		R = max_R;
		AdditiveNoise gaussian_noise(ycbcr, rgb, height, width, bfh, bih, 1);
		noise_ycbcr = gaussian_noise.get_YCbCr();
		gaussian_method();
		get_image("2.1.4.6BestGaussianPSNR.bmp");
	}

	void check_PSNR() {
		vector<int> sigma_noise = { 1,10,30,50,80 };
		vector<int> radius = { 1,3,5 };
		vector<double> sigma_filter = { 0.1, 0.25, 0.5, 0.75, 1, 1.25, 1.5, 2 };
		for (int n = 0; n < radius.size(); n++) {
			R = radius[n];
			for (int i = 0; i < sigma_noise.size(); i++) {
				AdditiveNoise gaussian_noise(ycbcr, rgb, height, width, bfh, bih, sigma_noise[i]);
				noise_ycbcr = gaussian_noise.get_YCbCr();
				for (int j = 0; j < sigma_filter.size(); j++) {
					sigma = sigma_filter[j];
					gaussian_method();
					double psnr = PSNR();
					string filename = "R" + to_string(R) + "sigmaNoise" + to_string(sigma_noise[i]) + ".txt";
					write_to_file(filename.c_str(), psnr);
				}
			}
		}
	}
};