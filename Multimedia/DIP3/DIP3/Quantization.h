#include <iostream>
#include <cmath>
#include "bmp.h"

using namespace std;

class Quantization {
private:
	int height;
	int width;
	int N = 8;
	YCbCr** ycbcr_DCT;
	YCbCr** quantization_ycbcr;
	YCbCr** dequantization_ycbcr;
	BITMAPFILEHEADER* bfh;
	BITMAPINFOHEADER* bih;

public:
	Quantization(YCbCr** y, int h, int w, BITMAPFILEHEADER* bf, BITMAPINFOHEADER* bi) {
		ycbcr_DCT = y;
		height = h;
		width = w;
		bfh = bf;
		bih = bi;

		quantization_ycbcr = new YCbCr * [height];
		for (int i = 0; i < height; i++)
			quantization_ycbcr[i] = new YCbCr[width];

		dequantization_ycbcr = new YCbCr * [height];
		for (int i = 0; i < height; i++)
			dequantization_ycbcr[i] = new YCbCr[width];
	}
	void quantization(double R) {
		const int N = 8;
		double Q[N][N];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				Q[i][j] = 1 + ((i + j) * R);
			}
		}

		for (int h = 0; h < height; h += N) {
			for (int w = 0; w < width; w += N) {
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < N; j++) {
						quantization_ycbcr[i+h][j+w].Y = round((double)ycbcr_DCT[i+h][j+w].Y / Q[i][j]);
						quantization_ycbcr[i+h][j+w].Cb = round((double)ycbcr_DCT[i+h][j+w].Cb / Q[i][j]);
						quantization_ycbcr[i+h][j+w].Cr = round((double)ycbcr_DCT[i+h][j+w].Cr / Q[i][j]);
					}
				}
			}
		}
	}
	YCbCr** get_quantization() {
		return quantization_ycbcr;
	}
	void dequantization(double R) {
		const int N = 8;
		double Q[N][N];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				Q[i][j] = 1 + ((i + j) * R);
			}
		}

		for (int h = 0; h < height; h += N) {
			for (int w = 0; w < width; w += N) {
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < N; j++) {
						dequantization_ycbcr[i + h][j + w].Y = (double)quantization_ycbcr[i + h][j + w].Y * Q[i][j];
						dequantization_ycbcr[i + h][j + w].Cb = (double)quantization_ycbcr[i + h][j + w].Cb * Q[i][j];
						dequantization_ycbcr[i + h][j + w].Cr = (double)quantization_ycbcr[i + h][j + w].Cr * Q[i][j];
					}
				}
			}
		}
	}

	YCbCr** get_dequantization() {
		return dequantization_ycbcr;
	}
};
