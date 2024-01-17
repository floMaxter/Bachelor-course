#include <iostream>
#include <fstream>
#include <vector>
#include "bmp.h"

class GradationTransform {
private:
	YCbCr** ycbcr;
	int height;
	int width;
	BITMAPFILEHEADER* bfh;
	BITMAPINFOHEADER* bih;
	YCbCr** new_ycbcr;
	int* freq = new int[256];
public:
	GradationTransform(YCbCr** y, int h, int w, BITMAPFILEHEADER* bf, BITMAPINFOHEADER* bi) {
		ycbcr = y;
		height = h;
		width = w;
		bfh = bf;
		bih = bi;

		new_ycbcr = new YCbCr * [height];
		for (int i = 0; i < height; i++)
			new_ycbcr[i] = new YCbCr[width];

	}
	void get_image(const char* filename) {
		FILE* file;
		file = fopen(filename, "wb");
		write_bmp_ycbcr(file, new_ycbcr, bfh, bih, height, width);
		fclose(file);
	}
	void gradation_transform(int T) {
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (ycbcr[i][j].Y > T) 
					new_ycbcr[i][j].Y = 0;
				else
					new_ycbcr[i][j].Y = 255;
			}
		}
	}

};


