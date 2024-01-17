#include <iostream>
#include <fstream>
#include <vector>
#include "bmp.h"

class MovingAverageMethod {
private:
	BITMAPFILEHEADER* bfh;
	BITMAPINFOHEADER* bih;
	YCbCr** noise_ycbcr;
	YCbCr** result_ycbcr;
	YCbCr** ycbcr;
	int height;
	int width;
	int R = 0;

public:
	MovingAverageMethod(YCbCr** y1, YCbCr** y, int h, int w, BITMAPFILEHEADER* bf, BITMAPINFOHEADER* bi, int r) {
		noise_ycbcr = y;
		ycbcr = y1;
		height = h;
		width = w;
		bfh = bf;
		bih = bi;
		R = r;

	
		result_ycbcr = new YCbCr * [height];
		for (int i = 0; i < height; i++)
			result_ycbcr[i] = new YCbCr[width];

		average_method();

	}

	void get_image(const char* filename) {
		FILE* file;
		file = fopen(filename, "wb");
		write_bmp_ycbcr(file, result_ycbcr, bfh, bih, height, width);
		fclose(file);
	}

	~MovingAverageMethod() {
		for (int i = 0; i < height; i++)
			delete (result_ycbcr[i]);
		delete result_ycbcr;
	}

	void average_method() {
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
				for (int k = -R; k <= R; k++) {
					for (int m = -R; m <= R; m++) {
						tmp += new_ycbcr[i + R + k][j + R + m].Y;
					}
				}
				result_ycbcr[i][j].Y = tmp / pow((2 * R + 1), 2);
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
		cout << "PSNR = " << PSNR << endl;
		return PSNR;
	}
	int check_radius() {
		double max_PSNR = 0;
		int max_R = 0;
		vector<int> radius = {1,2,3,4,5};
			for (int i = 0; i < radius.size(); i++)
			{
				R = radius[i];
				average_method();
				double psnr = PSNR();
				if (psnr > max_PSNR) {
					max_PSNR = psnr;
					max_R = R;
				}
			}
			cout << "max PSNR = " << max_PSNR << " R = " << max_R << endl;
			return max_R;
	}

};
