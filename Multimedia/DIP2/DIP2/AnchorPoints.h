#include <iostream>
#include <fstream>
#include <vector>
#include "bmp.h"

class AnchorPoints {
private:
	YCbCr** ycbcr;
	int height;
	int width;
	BITMAPFILEHEADER* bfh;
	BITMAPINFOHEADER* bih;
	YCbCr** new_ycbcr;
public:

	AnchorPoints(YCbCr** y, int h, int w, BITMAPFILEHEADER* bf, BITMAPINFOHEADER* bi) {
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

	unsigned char linear_inter(double x0, double y0, double x1, double y1, double x) {
		double res = 0;
		res = y0 + (x - x0) * (y1 - y0) / (x1 - x0);
		return (unsigned char)round(res);
	}

	//https://portal.tpu.ru/SHARED/m/MBB/uchebnaya_rabota/Model/Tab/Interp_app.pdf
	void anchor_points(unsigned char x0, unsigned char y0, unsigned char x1, unsigned char y1) {
		const unsigned char R = 0;
		const unsigned char S = 255;
		for (size_t i = 0; i < height; i++) {
			for (size_t j = 0; j < width; j++) {
				unsigned char res = new_ycbcr[i][j].Y;
				if (res == x0) res = y0;
				else if (res == x1) res = y1;
				else if (res < x0 && res > R) res = linear_inter(R, R, x0, y0,
					res);
				else if (res > x0 && res < x1) res = linear_inter(x0, y0, x1, y1,
					res);
				else if (res > x1 && res < S) res = linear_inter(x1, y1, S, S,
					res);
				new_ycbcr[i][j].Y = res;
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
