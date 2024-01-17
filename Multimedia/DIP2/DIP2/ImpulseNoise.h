#include <iostream>
#include <fstream>
#include "bmp.h"
#define Pi 3.141592653589793

using namespace std;


class ImpulseNoise {
private:
	BITMAPFILEHEADER* bfh;
	BITMAPINFOHEADER* bih;
	YCbCr** ycbcr;
	YCbCr** new_ycbcr;
	int height;
	int width;
	RGB** rgb;
	double** noise;
	double p_a = 0;
	double p_b = 0;
public:
	ImpulseNoise(YCbCr** y, RGB** color, int h, int w, BITMAPFILEHEADER* bf, BITMAPINFOHEADER* bi, double p1, double p2) {
		height = h;
		width = w;
		rgb = color;
		bfh = bf;
		bih = bi;
		p_a = p1;
		p_b = p2;
		ycbcr = y;

		new_ycbcr = new YCbCr * [height];
		noise = new double* [height];
		for (int i = 0; i < height; i++) {
			new_ycbcr[i] = new YCbCr[width];
			noise[i] = new double[width];
		}

		noise_overlay();
	}
	void get_image(const char* filename) {
		FILE* file;
		file = fopen(filename, "wb");
		write_bmp_ycbcr(file, new_ycbcr, bfh, bih, height, width);
		fclose(file);
	}
	~ImpulseNoise() {
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
			for (int j = 0; j < width; j++) {
				double tmp = (double)(rand() % 100) / 100;
				if (tmp <= p_a) {
					new_ycbcr[i][j].Y = 0;
					continue;
				}
				if (tmp <= (p_a + p_b)) {
					new_ycbcr[i][j].Y = 255;
					continue;
				}
				new_ycbcr[i][j].Y = ycbcr[i][j].Y;
			}
		}
	}

	double PSNR() {
		double tmp = width * height * pow(256 - 1, 2);
		double PSNR = 0;
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
		file.open("2.1.3PSNR(p_a,p_b).txt");
		vector<double> p = { 0.025,0.05,0.125,0.25};
		for (int i = 0; i < p.size(); i++) {
			p_a = p[i];
			p_b = p[i];
			noise_overlay();
			file << p[i] << " " << PSNR() << endl;
		}
		file.close();
	}

	YCbCr** get_YCbCr() {
		return new_ycbcr;
	}
};
