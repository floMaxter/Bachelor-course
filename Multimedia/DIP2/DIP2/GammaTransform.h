#include <iostream>
#include <fstream>
#include <vector>
#include "bmp.h"

class GammaTransform {
private:
	YCbCr** ycbcr;
	int height;
	int width;
	BITMAPFILEHEADER* bfh;
	BITMAPINFOHEADER* bih;
	YCbCr** new_ycbcr;
public:
	GammaTransform(YCbCr** y, int h, int w, BITMAPFILEHEADER* bf, BITMAPINFOHEADER* bi) {
		ycbcr = y;
		height = h;
		width = w;
		bfh = bf;
		bih = bi;

		new_ycbcr = new YCbCr * [height];
		for (int i = 0; i < height; i++)
			new_ycbcr[i] = new YCbCr[width];

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				new_ycbcr[i][j].Y = ycbcr[i][j].Y;
			}
		}

	}
	void get_image(const char* filename) {
		FILE* file;
		file = fopen(filename, "wb");
		write_bmp_ycbcr(file, new_ycbcr, bfh, bih, height, width);
		fclose(file);
	}
	double clipping(double value) {
		if (value > 255.0) {
			value = 255.0;
		}
		if (value < 0.0) {
			value = 0;
		}
		return round(value);
	}
	void gamma_transform(double c, double gamma) {
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				double tmp = new_ycbcr[i][j].Y / 255;
				tmp = c * pow(tmp, gamma);
				new_ycbcr[i][j].Y = clipping(tmp * 255);
			}
		}
	}

	void blackout(double val) {
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				new_ycbcr[i][j].Y = clipping(ycbcr[i][j].Y - val);
			}
		}
	}

	void lightening(double val) {
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				new_ycbcr[i][j].Y = clipping(ycbcr[i][j].Y + val);
			}
		}
	}
	void get_freq_original(const char* filename) {
		get_frequency(ycbcr, filename);
	}

	void get_freq_new(const char* filename) {
		get_frequency(new_ycbcr, filename);
	}
	void get_frequency(YCbCr** y, const char* filename) {
		ofstream out;
		out.open(filename);
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				out << y[i][j].Y << endl;
			}
		}
		out.close();
	}

};
