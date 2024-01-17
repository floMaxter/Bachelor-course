#include <iostream>
#include <fstream>
#include <vector>
#include "bmp.h"

class HistogramEqualization {
private:
	YCbCr** ycbcr;
	int height;
	int width;
	BITMAPFILEHEADER* bfh;
	BITMAPINFOHEADER* bih;
	YCbCr** new_ycbcr;
	int* freq = new int[256];
public:
	HistogramEqualization(YCbCr** y, int h, int w, BITMAPFILEHEADER* bf, BITMAPINFOHEADER* bi) {
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

		for (int i = 0; i < 256; i++)
			freq[i] = 0;

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
	void histogram_equalization() {
		for (size_t i = 0; i < height; i++) {
			for (size_t j = 0; j < width; j++) {
				freq[(int)new_ycbcr[i][j].Y]++;
			}
		}

		unsigned char* new_freq = new unsigned char[256];
		for (size_t i = 0; i < 256; i++) {
			double tmp = 0;
			for (size_t j = 0; j <= i; j++) {
				tmp += freq[j];
			}
			tmp = tmp * 255 / (height * width);
			new_freq[i] = (clipping(tmp));
		}
		for (size_t i = 0; i < height; i++) {
			for (size_t j = 0; j < width; j++) {
				new_ycbcr[i][j].Y = (new_freq[(int)new_ycbcr[i][j].Y]);
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

