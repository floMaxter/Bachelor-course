#include <iostream>
#include <fstream>
#include <vector>
#include "bmp.h"

using namespace std;

class LaplaceOperator {
private:
	YCbCr** ycbcr;
	int height;
	int width;
	BITMAPFILEHEADER* bfh;
	BITMAPINFOHEADER* bih;
	double** laplace_operator;
	YCbCr** new_ycbcr;
public:

	LaplaceOperator(YCbCr** y, int h, int w, BITMAPFILEHEADER* bf, BITMAPINFOHEADER* bi) {
		ycbcr = y;
		height = h;
		width = w;
		bfh = bf;
		bih = bi;

		laplace_operator = new double* [height];
		for (int i = 0; i < height; i++) {
			laplace_operator[i] = new double[width];
		}

		new_ycbcr = new YCbCr * [height];
		for (int i = 0; i < height; i++)
			new_ycbcr[i] = new YCbCr[width];
	}

	void create_laplace_operator1(int w, int w_center) {
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (i + 1 < height && i - 1 >= 0 && j + 1 < width && j - 1 >= 0) {
					laplace_operator[i][j] = w*ycbcr[i][j+1].Y + w*ycbcr[i][j-1].Y + w*ycbcr[i+1][j].Y + w*ycbcr[i-1][j].Y + w_center * ycbcr[i][j].Y;
				}
				else
				{
					laplace_operator[i][j] = 0;
				}
			}
		}
	}
	void get_operator_laplace_image(const char* filename) {
		
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				new_ycbcr[i][j].Y = clipping(laplace_operator[i][j]);
			}
		}
		FILE* file;
		file = fopen(filename, "wb");
		write_bmp_ycbcr(file, new_ycbcr, bfh, bih, height, width);
		fclose(file);
	}

	void get_image_response(const char* filename) {
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				new_ycbcr[i][j].Y = clipping(laplace_operator[i][j] + 128);
			}
		}
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
	void high_frequency(const char* filename) {
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				new_ycbcr[i][j].Y = clipping(laplace_operator[i][j] + ycbcr[i][j].Y);
			}
		}
		FILE* file;
		file = fopen(filename, "wb");
		write_bmp_ycbcr(file, new_ycbcr, bfh, bih, height, width);
		fclose(file);
	}

	void create_high_frequency_alpha(double alpha, const char* filename) {
		const int R = 1;
		double w[3][3] = { { 0, -1, 0 } ,{ -1, alpha + 4, -1 },{ 0, -1, 0 } };
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				double result = 0;
				for (int k = -R; k <= R; k++) {
					for (int m = -R; m <= R; m++) {
						int x = i + k;
						int y = j + m;
						if (x < 0)
							x = 0;
						if (x > height - 1)
							x = height - 1;
						if (y < 0)
							y = 0;
						if (y > width - 1)
							y = width - 1;
						double tmp = ycbcr[x][y].Y;
						result += tmp * w[k + 1][m + 1];
					}
				}
				new_ycbcr[i][j].Y = (clipping(ycbcr[i][j].Y * (alpha - 1) + result));
			}
		}
		FILE* file;
		file = fopen(filename, "wb");
		write_bmp_ycbcr(file, new_ycbcr, bfh, bih, height, width);
		fclose(file);
	}

	double average_bright() {
		long double sum = 0;
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				sum += new_ycbcr[i][j].Y;
			}
		}
		return sum / (height * width);
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