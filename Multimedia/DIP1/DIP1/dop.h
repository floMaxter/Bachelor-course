#include <iostream>
#include <vector>
#include <fstream>
#include "bmp.h"

using namespace std;

class Subframes {
private:
	int height;
	int width;
	YCbCr** ycbcr;
	RGB** new_rgb;
	double H = 0;
	double* freq = new double[256];
	BITMAPFILEHEADER* bfh;
	BITMAPINFOHEADER* bih;
	
public:

	Subframes(int h, int w, YCbCr** y, BITMAPFILEHEADER* bf, BITMAPINFOHEADER* bi) {
		height = h;
		width = w;
		ycbcr = y;
		bfh = bf;
		bih = bi;
		new_rgb = new RGB * [height / 2];
		for (int i = 0; i < height / 2; i++) {
			new_rgb[i] = new RGB[width / 2];
		}
		cout << endl << "Subframes:" << endl;
		Y_00();
		Y_01();
		Y_10();
		Y_11();
		cout << endl;
	}
	void Y_00() {
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (i % 2 == 0 && j % 2 == 0) {
					new_rgb[i / 2][j / 2].R = ycbcr[i][j].Y;
					new_rgb[i / 2][j / 2].G = ycbcr[i][j].Y;
					new_rgb[i / 2][j / 2].B = ycbcr[i][j].Y;
				}
			}
		}
		FILE* file;
		file = fopen("dopY_00.bmp", "wb");
		write_bmp(file, new_rgb, bfh, bih, height / 2, width / 2);
		fclose(file);
		clear();
		get_YCbCr("dopFreqY_00.txt");
		entropy("Y_00");
	}

	void Y_01() {

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (i % 2 == 0 && j % 2 == 1) {
					new_rgb[i / 2][j / 2].R = ycbcr[i][j].Y;
					new_rgb[i / 2][j / 2].G = ycbcr[i][j].Y;
					new_rgb[i / 2][j / 2].B = ycbcr[i][j].Y;
				}
			}
		}
		FILE* file;
		file = fopen("dopY_01.bmp", "wb");
		write_bmp(file, new_rgb, bfh, bih, height / 2, width / 2);
		fclose(file);
		clear();
		get_YCbCr("dopFreqY_01.txt");
		entropy("Y_01");
	}

	void Y_10() {

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (i % 2 == 1 && j % 2 == 0) {
					new_rgb[i / 2][j / 2].R = ycbcr[i][j].Y;
					new_rgb[i / 2][j / 2].G = ycbcr[i][j].Y;
					new_rgb[i / 2][j / 2].B = ycbcr[i][j].Y;
				}
			}
		}
		FILE* file;
		file = fopen("dopY_10.bmp", "wb");
		write_bmp(file, new_rgb, bfh, bih, height / 2, width / 2);
		fclose(file);
		clear();
		get_YCbCr("dopFreqY_10.txt");
		entropy("Y_10");
	}
	void Y_11() {
	
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (i % 2 == 1 && j % 2 == 1) {
					new_rgb[i / 2][j / 2].R = ycbcr[i][j].Y;
					new_rgb[i / 2][j / 2].G = ycbcr[i][j].Y;
					new_rgb[i / 2][j / 2].B = ycbcr[i][j].Y;
				}
			}
		}
		FILE* file;
		file = fopen("dopY_11.bmp", "wb");
		write_bmp(file, new_rgb, bfh, bih, height / 2, width / 2);
		fclose(file);
		clear();
		get_YCbCr("dopFreqY_11.txt");
		entropy("Y_11");
	}

	void clear() {
		for (int i = 0; i < 256; i++)
			freq[i] = 0;
		H = 0;
	}

	void get_YCbCr(const char* filename) {
		ofstream out;
		out.open(filename);
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
					freq[(int)new_rgb[i/2][j/2].R]++;
			}
		}
		for (int i = 0; i < 256; i++) {
			out << i << " " << freq[i] << endl;
		}
		out.close();
	}
	void entropy(string letter) {
		for (int i = 0; i < 256; i++) {
			double p = (double)freq[i] / (height * width);
			if (p != 0) {
				H += p * log2(p);
			}
		}
		H *= (-1);
		cout << "H(" << letter << ") = " << H << endl;

	}
};