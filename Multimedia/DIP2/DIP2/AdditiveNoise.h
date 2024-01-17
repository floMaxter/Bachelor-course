#ifndef gaussianNoise
#define gaussianNoise
#include <iostream>
#include <fstream>
#include <vector>
#include "bmp.h"

#define Pi 3.141592653589793

using namespace std;

class AdditiveNoise {
private:
	BITMAPFILEHEADER* bfh;
	BITMAPINFOHEADER* bih;
	YCbCr** new_ycbcr;
	YCbCr** ycbcr;
	int height;
	int width;
	RGB** rgb;
	double** noise;
	double sigma;
	unsigned char min_R = 0;;
	unsigned char min_G = 0;
	unsigned char min_B = 0;
	unsigned char max_R = 0;
	unsigned char max_G = 0;
	unsigned char max_B = 0;
public:
	AdditiveNoise(YCbCr** y, RGB** color, int h, int w, BITMAPFILEHEADER* bf, BITMAPINFOHEADER* bi, double s) {
		height = h;
		width = w;
		rgb = color;
		bfh = bf;
		bih = bi;
		sigma = s;
		ycbcr = y;

		new_ycbcr = new YCbCr * [height];
		noise = new double* [height];
		for (int i = 0; i < height; i++) {
			new_ycbcr[i] = new YCbCr[width];
			noise[i] = new double[width];
		}

		//find_min_max();
		sigma = s;
		noise_overlay();
	
	}

	void get_image(const char* filename) {
		FILE* file;
		file = fopen(filename, "wb");
		write_bmp_ycbcr(file, new_ycbcr, bfh, bih, height, width);
		fclose(file);	
	}
	~AdditiveNoise() {
		for (int i = 0; i < height; i++) {
			delete(noise[i]);
			delete(new_ycbcr[i]);
		}
		delete noise;
		delete new_ycbcr;
	}

	void noise_overlay() {
		srand(time(NULL));
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j += 2) {
				double r = (double)(rand() % 2000 - 1000) / 1000;
				double phi = (double)(rand() % 2000 - 1000) / 1000;
				double s = (r * r) + (phi * phi);
				while (s > 1 || s == 0) {
					r = (double)(rand() % 2000 - 1000) / 1000;
					phi = (double)(rand() % 2000 - 1000) / 1000;
					s = (r * r) + (phi * phi);
				}
				noise[i][j] = sigma * r * sqrt(-2 * log(s) / s);
				noise[i][j + 1] = sigma * phi * sqrt(-2 * log(s) / s);
			}
		}
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				new_ycbcr[i][j].Y = clipping(ycbcr[i][j].Y + noise[i][j]);
			}
		}
	}


	/*void find_min_max() {
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (rgb[i][j].R > max_R)	max_R = rgb[i][j].R;
				if (rgb[i][j].G > max_G)	max_G = rgb[i][j].G;
				if (rgb[i][j].B > max_B)	max_B = rgb[i][j].B;
				if (rgb[i][j].R < min_R)	min_R = rgb[i][j].R;
				if (rgb[i][j].G < min_G)	min_G = rgb[i][j].G;
				if (rgb[i][j].B < min_B)	min_B = rgb[i][j].B;
			}
		}
	}*/
	double clipping(double value) {
		if (value > 255.0) {
			value = 255.0;
		}
		if (value < 0.0) {
			value = 0;
		}
		return round(value);
	}

	double PSNR() {
		double tmp = width * height * pow(256 - 1, 2);
			double PSNR= 0;
			for (int i = 0; i < height; i++) {
				for (int j = 0; j < width; j++) {
					PSNR += pow((ycbcr[i][j].Y - new_ycbcr[i][j].Y), 2);
				}
			}
			PSNR = 10 * log10(tmp / PSNR);
			cout << "PSNR = " << PSNR << endl;
			return PSNR;
	}

	void PSNR_graph() {
		ofstream file;
		file.open("2.1.3PSNR(sigma).txt");
		vector<double> x = {1,10,30,50,80};
		for (int i = 0; i < x.size(); i++) {
			sigma = x[i];
			noise_overlay();
			file << sigma << " " << PSNR() << endl;
		}
		file.close();
	}
	YCbCr** get_YCbCr() {
		return new_ycbcr;
	}
};

#endif gaussianNoise