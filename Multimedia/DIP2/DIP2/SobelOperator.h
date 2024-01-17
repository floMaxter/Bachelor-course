#include <iostream>
#include <fstream>
#include <vector>
#include "bmp.h"

using namespace std;

class SobelOperator {
private:
	YCbCr** ycbcr;
	int height;
	int width;
	BITMAPFILEHEADER* bfh;
	BITMAPINFOHEADER* bih;
	YCbCr** new_ycbcr;
	RGB** new_rgb;
	double** teta;
	double** Gh;
	double** Gv;
public:

	SobelOperator(YCbCr** y, int h, int w, BITMAPFILEHEADER* bf, BITMAPINFOHEADER* bi) {
		ycbcr = y;
		height = h;
		width = w;
		bfh = bf;
		bih = bi;


		new_ycbcr = new YCbCr * [height];
		for (int i = 0; i < height; i++)
			new_ycbcr[i] = new YCbCr[width];

		new_rgb = new RGB * [height];
		for (int i = 0; i < height; i++)
			new_rgb[i] = new RGB[width];

		teta = new double * [height];
		for (int i = 0; i < height; i++)
			teta[i] = new double[width];

		Gh = new double* [height];
		for (int i = 0; i < height; i++)
			Gh[i] = new double[width];

		Gv = new double* [height];
		for (int i = 0; i < height; i++)
			Gv[i] = new double[width];
	}

	void sobel_operator(double thr) {
		const int R = 1;
		double I;
		const double mask_h[3][3] = { { -1, 0, 1 } ,{ -2, 0, 2 },{ -1, 0, 1 } };
		const double mask_v[3][3] = { { 1, 2, 1 } ,{ 0, 0, 0 },{ -1, -2, -1 } };
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				double h = 0, v = 0;
				for (int k = -R; k <= R; k++) {
					for (int m = -R; m <= R; m++) {
						int x = i + k;
						int y = j + m;
						if (x < 0) x = 0;
						if (x > (height - 1)) x = height - 1;
						if (y < 0) y = 0;
						if (y > (width - 1)) y = width - 1;
						double cur = ycbcr[x][y].Y;
						h += cur * mask_h[k + 1][m + 1];
						v += cur * mask_v[k + 1][m + 1];
					}
				}
				Gh[i][j] = h;
				Gv[i][j] = v;
				double I = sqrt(pow(h, 2) + pow(v, 2));
				if (I > thr) I = 255; // если детктирован как контур, то белый
				else I = 0;
				teta[i][j] = atan2(v, h);
				new_ycbcr[i][j].Y = I;
			}
		}
	}
	void get_image(const char* filename) {
		FILE* file;
		file = fopen(filename, "wb");
		write_bmp_ycbcr(file, new_ycbcr, bfh, bih, height, width);
		fclose(file);
	}

	void gradient(const char* filename) {
		RGB blue = { 0, 0, 255 };
		RGB green = { 0, 255, 0 };
		RGB red = { 255, 0, 0 };
		RGB white = { 255, 255, 255 };
		for (size_t i = 0; i < height; i++) {
			for (size_t j = 0; j < width; j++) {
				if (Gh[i][j] > 0 && Gv[i][j] > 0) 
					new_rgb[i][j] = red;
				if (Gh[i][j] < 0 && Gv[i][j] > 0) 
					new_rgb[i][j] = green;
				if (Gh[i][j] < 0 && Gv[i][j] < 0) 
					new_rgb[i][j] = blue;
				if (Gh[i][j] > 0 && Gv[i][j] < 0) 
					new_rgb[i][j] = white;
			}
		}
		FILE* file;
		file = fopen(filename, "wb");
		write_bmp(file, new_rgb, bfh, bih, height, width);
		fclose(file);
	}
};
