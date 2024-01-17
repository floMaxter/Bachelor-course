#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <complex>
#include <map>
#include <math.h>
#include <algorithm>
typedef struct BFH
{
	short bfType;
	int bfSize;
	short bfReserved1;
	short bfOffBits;;
	int bfReserved2;
} MBITMAPFILEHEADER;

typedef struct BIH
{
	int biSize;
	int biWidth;
	int biHeight;
	short int biPlanes;
	short int biBitCount;
	int biCompression;
	int biSizeImage;
	int biXPelsPerMeter;
	int biYPelsPerMeter;
	int biClrUsed;
	int biClrImportant;
} MBITMAPINFOHEADER;
typedef struct RGB
{
	unsigned char rgbBlue;
	unsigned char rgbGreen;
	unsigned char rgbRed;
}MRGBQUAD;

unsigned char min_R = 0;;
unsigned char min_G = 0;
unsigned char min_B = 0;
unsigned char max_R = 0;
unsigned char max_G = 0;
unsigned char max_B = 0;

MRGBQUAD** read_bmp(FILE* f, MBITMAPFILEHEADER* bfh, MBITMAPINFOHEADER* bih)
{
	int k = 0;
	k = fread(bfh, sizeof(*bfh) - 2, 1, f);       //читаем файловый заголовок в структуру BITMAPFILEHEADER
	if (k == 0)
	{
		std::cout << "reading error";
		return 0;
	}

	k = fread(bih, sizeof(*bih), 1, f);       //Читаем заголовок изображения в структуру BITMAPINFOHEADER
	if (k == NULL)
	{
		std::cout << "reading error";
		return 0;
	}
	int a = abs(bih->biHeight);
	int b = abs(bih->biWidth);
	MRGBQUAD** rgb = new MRGBQUAD * [a];
	for (int i = 0; i < a; i++)
	{
		rgb[i] = new MRGBQUAD[b];
	}
	int pad = 4 - (b * 3) % 4;
	for (int i = 0; i < a; i++)
	{
		fread(rgb[i], sizeof(MRGBQUAD), b, f);
		if (pad != 4)
		{
			fseek(f, pad, SEEK_CUR);
		}
	}
	return rgb;
}

void write_bmp(FILE* f, MRGBQUAD** rgbb, MBITMAPFILEHEADER* bfh, MBITMAPINFOHEADER* bih, int a, int b)
{
	bih->biHeight = a;
	bih->biWidth = b;
	fwrite(bfh, sizeof(*bfh) - 2, 1, f);
	fwrite(bih, sizeof(*bih), 1, f);
	int pad = 4 - ((b) * 3) % 4;
	char buf = 0;
	for (int i = 0; i < a; i++)
	{
		fwrite((rgbb[i]), sizeof(MRGBQUAD), b, f);
		if (pad != 4)
		{
			fwrite(&buf, 1, pad, f);
		}
	}
}


//void clipping(MRGBQUAD** rgb, int h1, int w1) {
//	for (int i = 0; i < h1; i++) {
//		for (int j = 0; j < w1; j++) {
//			rgb[i][j].rgbRed = clip(rgb[i][j].rgbRed, min_R, max_R);
//			rgb[i][j].rgbGreen = clip(rgb[i][j].rgbGreen, min_G, max_G);
//			rgb[i][j].rgbBlue = clip(rgb[i][j].rgbBlue, min_B, max_B);
//		}
//	}
//}

MRGBQUAD** getR(MRGBQUAD** rgb1, int a, int b) {
	MRGBQUAD** g = new MRGBQUAD * [a];
	for (int i = 0; i < a; i++)
	{
		g[i] = new MRGBQUAD[b];
	}
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			g[i][j].rgbGreen = 0;
			g[i][j].rgbBlue = 0;
			g[i][j].rgbRed = rgb1[i][j].rgbRed;
		}
	}
	return g;
}

MRGBQUAD** getG(MRGBQUAD** rgb1, int a, int b) {
	MRGBQUAD** g = new MRGBQUAD * [a];
	for (int i = 0; i < a; i++)
	{
		g[i] = new MRGBQUAD[b];
	}
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			g[i][j].rgbGreen = rgb1[i][j].rgbGreen;
			g[i][j].rgbBlue = 0;
			g[i][j].rgbRed = 0;
		}
	}
	return g;
}

MRGBQUAD** get_zerkal(MRGBQUAD** rgb1, int a, int b) {
	MRGBQUAD** g = new MRGBQUAD * [a];
	for (int i = 0; i < a; i++)
	{
		g[i] = new MRGBQUAD[b];
	}
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			g[i][j].rgbRed = rgb1[a - i - 1][j].rgbRed;
			g[i][j].rgbGreen = rgb1[a - i - 1][j].rgbGreen;
			g[i][j].rgbBlue = rgb1[a - i - 1][j].rgbBlue;
		}
	}
	return g;
}

MRGBQUAD** getB(MRGBQUAD** rgb1, int a, int b) {
	MRGBQUAD** g = new MRGBQUAD * [a];
	for (int i = 0; i < a; i++)
	{
		g[i] = new MRGBQUAD[b];
	}
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			g[i][j].rgbGreen = 0;
			g[i][j].rgbBlue = rgb1[i][j].rgbBlue;
			g[i][j].rgbRed = 0;
		}
	}
	return g;
}

double get_math_ozh(std::vector<std::vector<double>> rgb, int h, int w) {
	double res = 0;
	double WH = (double)w * (double)h;
	for (int i = 0; i < rgb.size(); i++) {
		for (int j = 0; j < rgb[0].size(); j++) {
			if (rgb[i].size() != 0)
				res += rgb[i][j];
		}
	}
	res = res / WH;
	return res;
}

double get_disp(std::vector<std::vector<double>> rgb, int h, int w) {
	double res = 0;
	double WH = (double)w * (double)h;
	double m = get_math_ozh(rgb, h, w);
	for (int i = 0; i < rgb.size(); i++) {
		for (int j = 0; j < rgb[0].size(); j++) {
			if (rgb[i].size() != 0)
				res += pow((rgb[i][j] - m), 2);
		}
	}
	res = res / (WH - 1);
	return sqrt(res);
}

double get_correl(std::vector<std::vector<double>> A, std::vector<std::vector<double>> B, int h, int w) {
	double d1 = get_disp(A, h, w);
	double d2 = get_disp(B, h, w);
	double m1 = get_math_ozh(A, h, w);
	double m2 = get_math_ozh(B, h, w);
	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < A[0].size(); j++) {
			if (A[i].size() != 0 && B[i].size() != 0) {
				A[i][j] = A[i][j] - m1;
				B[i][j] = B[i][j] - m2;
				A[i][j] = A[i][j] * B[i][j];
			}
		}
	}
	double res = get_math_ozh(A, h, w) / (d1 * d2);
	return res;
}




MRGBQUAD** getRGBfromY(std::vector<std::vector<double>> Y, int a, int b) {
	MRGBQUAD** g = new MRGBQUAD * [a];
	for (int i = 0; i < a; i++)
	{
		g[i] = new MRGBQUAD[b];
	}
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			g[i][j].rgbGreen = Y[i][j];
			g[i][j].rgbBlue = Y[i][j];
			g[i][j].rgbRed = Y[i][j];
		}
	}
	return g;
}

//RGBQUAD** getrestoredCbCr(std::vector<std::vector<double>> Y, std::vector<std::vector<double>> Cb, std::vector<std::vector<double>> Cr, int a, int b) {
//	RGBQUAD** g = new RGBQUAD * [a];
//	for (int i = 0; i < a; i++)
//	{
//		g[i] = new RGBQUAD[b];
//	}
//	int counti = 0;
//	int countj = 0;
//	for (int i = 0; i < a; i++) {
//		for (int j = 0; j < b; j++) {
//			g[i][j].rgbGreen = clip((Y[i][j] + 1.402 * (Cr[counti][countj] - 128)), min_G, max_G);
//			g[i][j].rgbRed = clip((Y[i][j] - 0.714 * (Cr[counti][countj] - 128) - 0.334 * (Cb[counti][countj] - 128)), min_R, max_R);
//			g[i][j].rgbBlue = clip(Y[i][j] + 1.1772 * (Cb[counti][countj] - 128), min_B, max_B);
//			if (j > 0 && j % 2 == 0)
//				countj++;
//		}
//		countj = 0;
//		if (i > 0 && i % 2 == 0)
//			counti++;
//	}
//	return g;
//}

unsigned char clip(double x, int xmin, int xmax) {
	if (x < (double)xmin)
		x = (double)xmin;
	if (x > (double)xmax)
		x = (double)xmax;
	return (unsigned char)x;
}

MRGBQUAD** getRGBfromYreverse(std::vector<std::vector<double>> Y, std::vector<std::vector<double>> Cb, std::vector<std::vector<double>> Cr, int a, int b) {
	MRGBQUAD** g = new MRGBQUAD * [a];
	for (int i = 0; i < a; i++)
	{
		g[i] = new MRGBQUAD[b];
	}
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			g[i][j].rgbGreen = clip(Y[i][j] - 0.714 * (Cr[i][j] - 128.0) - 0.334 * (Cb[i][j] - 128.0), min_G, max_G);
			g[i][j].rgbRed = clip(Y[i][j] + 1.402 * (Cr[i][j] - 128.0), min_R, max_R);
			g[i][j].rgbBlue = clip(Y[i][j] + 1.772 * (Cb[i][j] - 128.0), min_B, max_B);
		}
	}
	return g;
}

double sum_sqr_differense(std::vector<std::vector<double>> v1, std::vector<std::vector<double>> v2) {
	double res = 0;
	for (int i = 0; i < v1.size(); i++) {
		for (int j = 0; j < v1[0].size(); j++) {
			res += pow((v1[i][j] - v2[i][j]), 2);
		}
	}
	return res;
}

double get_PSNR(std::vector<std::vector<double>> v1, std::vector<std::vector<double>> v2) {
	double PSNR = 10 * log10(v1.size() * v1[0].size() * pow((pow(2, 8) - 1), 2) / sum_sqr_differense(v1, v2));
	return PSNR;
}

void find_minmax(MRGBQUAD** rgb, int h1, int w1) {
	for (int i = 0; i < h1; i++) {
		for (int j = 0; j < w1; j++) {
			if (rgb[i][j].rgbRed > max_R)
				max_R = rgb[i][j].rgbRed;
			if (rgb[i][j].rgbGreen > max_G)
				max_G = rgb[i][j].rgbGreen;
			if (rgb[i][j].rgbBlue > max_B)
				max_B = rgb[i][j].rgbBlue;
			if (rgb[i][j].rgbRed < min_R)
				min_R = rgb[i][j].rgbRed;
			if (rgb[i][j].rgbGreen < min_G)
				min_G = rgb[i][j].rgbGreen;
			if (rgb[i][j].rgbBlue < min_B)
				min_B = rgb[i][j].rgbBlue;
		}
	}
}

std::vector<std::vector<double>> decimation1(std::vector<std::vector<double>> Cb, int h1, int w1, int n) {
	std::vector<std::vector<double>> newCb(h1 / n);
	int count = 0;
	for (int i = 0; i < h1; i += n) {
		for (int j = 0; j < w1; j += n) {
			newCb[count].push_back(Cb[i][j]);
		}
		count++;
	}
	//restore
	std::vector<std::vector<double>> restCb(h1);
	for (int i = 0; i < h1; i++) {
		for (int j = 0; j < w1; j++) {
			restCb[i].push_back(newCb[i / n][j / n]);
		}
	}
	return restCb;
}

double arith_mean(std::vector<std::vector<double>>& Cb, int i, int j, int n) {
	double sum = 0;
	for (int k = 0; k < n; k++) {
		for (int t = 0; t < n; t++) {
			sum += Cb[i + k][j + t];
		}
	}
	sum = sum / (double)(n * n);
	return sum;
}

std::vector<std::vector<double>> decimation2(std::vector<std::vector<double>>& Cb, int h1, int w1, int n) {
	std::vector<std::vector<double>> newCb(h1 / n);
	int count = 0;
	for (int i = 0; i < h1; i += n) {
		for (int j = 0; j < w1; j += n) {
			newCb[count].push_back(arith_mean(Cb, i, j, n));
		}
		count++;
	}
	//restore
	std::vector<std::vector<double>> restCb(h1);
	for (int i = 0; i < h1; i++) {
		for (int j = 0; j < w1; j++) {
			restCb[i].push_back(newCb[i / n][j / n]);
		}
	}
	return restCb;
}

double get_PSNR_only_R(MRGBQUAD** restoredRGB, std::vector<std::vector<double>>& R, int h1, int w1) {
	std::vector<std::vector<double>> restR(h1);
	for (int i = 0; i < h1; i++) {
		for (int j = 0; j < w1; j++) {
			restR[i].push_back(restoredRGB[i][j].rgbRed);
		}
	}
	return get_PSNR(R, restR);

}

double get_PSNR_only_G(MRGBQUAD** restoredRGB, std::vector<std::vector<double>>& G, int h1, int w1) {
	std::vector<std::vector<double>> restG(h1);
	for (int i = 0; i < h1; i++) {
		for (int j = 0; j < w1; j++) {
			restG[i].push_back(restoredRGB[i][j].rgbGreen);
		}
	}
	return get_PSNR(G, restG);
}

double get_PSNR_only_B(MRGBQUAD** restoredRGB, std::vector<std::vector<double>>& B, int h1, int w1) {

	std::vector<std::vector<double>> restB(h1);
	for (int i = 0; i < h1; i++) {
		for (int j = 0; j < w1; j++) {

			restB[i].push_back(restoredRGB[i][j].rgbBlue);
		}
	}
	return get_PSNR(B, restB);
}

void file_write(const char* s, std::vector<std::vector<double>>& v, int h1, int w1) {
	std::ofstream fout1;
	fout1.open(s);
	for (int i = 0; i < h1; i++) {
		for (int j = 0; j < w1; j++) {
			fout1 << v[i][j] << "\n";
		}
	}
	fout1.close();
}

void file_write(const char* s, std::vector<double>& v) {
	std::ofstream fout1;
	fout1.open(s);
	for (int i = 0; i < v.size(); i++) {
		fout1 << v[i] << "\n";
	}
	fout1.close();
}

std::vector<std::vector<double>> get_DPCM1(std::vector<std::vector<double>>& v) {
	std::vector<std::vector<double>> res(v.size());
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[0].size(); j++) {
			if (j == 0 || i == 0) {
				res[i].push_back(v[i][j]);
				continue;
			}
			res[i].push_back((v[i][j] - v[i][j - 1]));

		}
	}
	return res;
}

std::vector<std::vector<double>> get_DPCM2(std::vector<std::vector<double>>& v) {
	std::vector<std::vector<double>> res(v.size());
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[0].size(); j++) {
			if (i == 0) {
				res[i].push_back(v[i][j]);
				continue;
			}
			res[i].push_back(v[i][j] - v[i - 1][j]);

		}
	}
	return res;
}

std::vector<std::vector<double>> get_DPCM3(std::vector<std::vector<double>>& v) {
	std::vector<std::vector<double>> res(v.size());
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[0].size(); j++) {
			if (i == 0 || j == 0) {
				res[i].push_back(v[i][j]);
				continue;
			}
			res[i].push_back(v[i][j] - v[i - 1][j - 1]);

		}
	}
	return res;
}

std::vector<std::vector<double>> get_DPCM4(std::vector<std::vector<double>>& v) {
	std::vector<std::vector<double>> res(v.size());
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[0].size(); j++) {
			if (i == 0 || j == 0) {
				res[i].push_back(v[i][j]);
				continue;
			}
			res[i].push_back(v[i][j] - (v[i - 1][j] + v[i][j - 1] + v[i - 1][j - 1]) / 3);

		}
	}
	return res;
}

double entropy(std::vector<std::vector<double>> rgb) {
	double H = 0.0;
	std::vector<double> p;
	for (int i = 0; i < 256; i++) {
		p.push_back(0);
	}
	for (int i = 0; i < rgb.size(); i++) {
		for (int j = 0; j < rgb[0].size(); j++) {
			int tmp = rgb[i][j];
			tmp += 256;
			tmp = tmp % 256;
			p[tmp]++;
		}
	}
	for (int i = 0; i < 256; i++) {
		p[i] = p[i] / (double)(rgb.size() * rgb[0].size());
	}

	for (int i = 0; i < 256; i++) {
		if (p[i] != 0)
			H += (double)(p[i] * std::log2(p[i]));
	}
	H = (double)(-H);
	return H;
}

double entropy1(std::vector<std::vector<double>>& rgb) {
	double H = 0.0;
	std::map<double, double> p;
	double N = (double)rgb.size() * rgb[0].size();
	double delta = 256 / (double)N;
	for (int i = 0; i < rgb.size(); i++) {
		for (int j = 0; j < rgb[0].size(); j++) {
			if (p.find(rgb[i][j]) != p.end()) {
				p[(size_t)rgb[i][j]]++;
			}
			else p.insert(std::pair<double, double>(rgb[i][j], 0));
		}
	}
	for (std::pair<double, double> it : p) {
		it.second /= (double)N;
		if (!std::isinf(std::log2(it.second))) {
			H += it.second * std::log2(it.second);
		}
	}
	return (double)(-H);
}

int mod(int a, int b) {
	int res = a % b;
	if (res < 0) {
		res += b;
	}
	return res;

}

std::vector<std::vector<double>> shuffle_1(std::vector<std::vector<double>>& v, int y, int x) {
	std::vector<std::vector<double>> tmp;
	if (y >= 0) {
		if (x >= 0) {
			for (int i = 0; i < v.size() - y; i++) {
				std::vector<double> res;
				for (int j = 0; j < v[0].size() - x; j++) {
					res.push_back(v[i][j]);
				}
				tmp.push_back(res);
			}
		}
		else {
			for (int i = 0; i < v.size() - y; i++) {
				std::vector<double> res;
				for (int j = -x; j < v[0].size(); j++) {
					res.push_back(v[i][j]);
				}
				tmp.push_back(res);
			}
		}
	}
	else {
		if (x >= 0) {
			for (int i = -y; i < v.size(); i++) {
				std::vector<double> res;
				for (int j = 0; j < v[0].size() - x; j++) {
					res.push_back(v[i][j]);
				}
				tmp.push_back(res);
			}
		}
		else {
			for (int i = -y; i < v.size(); i++) {
				std::vector<double> res;
				for (int j = -x; j < v[0].size(); j++) {
					res.push_back(v[i][j]);
				}
				tmp.push_back(res);
			}
		}
	}
	return tmp;
}

std::vector<std::vector<double>> shuffle_3(std::vector<std::vector<double>>& v, int y, int x) {
	std::vector<std::vector<double>> tmp;
	if (y >= 0) {
		if (x >= 0) {
			for (int i = y; i < v.size(); i++) {
				std::vector<double> res;
				for (int j = x; j < v[0].size(); j++) {
					res.push_back(v[i][j]);
				}
				tmp.push_back(res);
			}
		}
		else {
			for (int i = y; i < v.size(); i++) {
				std::vector<double> res;
				for (int j = 0; j < v[0].size() + x; j++) {
					res.push_back(v[i][j]);
				}
				tmp.push_back(res);
			}
		}
	}
	else {
		if (x >= 0) {
			for (int i = 0; i < v.size() + y; i++) {
				std::vector<double> res;
				for (int j = x; j < v[0].size(); j++) {
					res.push_back(v[i][j]);
				}
				tmp.push_back(res);
			}
		}
		else {
			for (int i = 0; i < v.size() + y; i++) {
				std::vector<double> res;
				for (int j = 0; j < v[0].size() + x; j++) {
					res.push_back(v[i][j]);
				}
				tmp.push_back(res);
			}
		}
	}
	return tmp;
}

std::vector<std::vector<double>> shuffle_2(std::vector<std::vector<double>>& v, int y, int x) {
	std::vector<std::vector<double>> res(v.size());
	if (y >= 0) {
		if (x >= 0) {
			for (int i = y + 1; i < v.size() + y + 1; i++) {
				for (int j = x + 1; j < v[0].size() + x + 1; j++) {
					res[i - y + 1].push_back(v[mod(i, v.size())][mod(j, v[0].size())]);
				}
			}
		}
		else {
			for (int i = y + 1; i < v.size() + y + 1; i++) {
				for (int j = 0; j < v[0].size(); j++) {
					res[i - y + 1, v.size()].push_back(v[mod(i, v.size())][mod((j + x + 1), v[0].size())]);
				}
			}
		}
	}
	else {
		if (x >= 0) {
			for (int i = 0; i < v.size(); i++) {
				for (int j = x + 1; j < v[0].size() + x + 1; j++) {
					res[mod((i + y + 1), v.size())].push_back(v[i][mod(j, v[0].size())]);
				}
			}
		}
		else {
			for (int i = 0; i < v.size(); i++) {
				for (int j = 0; j < v[0].size(); j++) {
					res[mod((i + y + 1), v.size())].push_back(v[i][mod((j + x + 1), v[0].size())]);
				}
			}
		}
	}
	return res;
}



void avtocoorel(std::vector<std::vector<double>>& v, std::vector<std::vector<double>>& v1, std::vector<std::vector<double>>& v2) {
	std::ofstream fout;
	fout.open("x.txt");
	int h = v.size();
	int w = v[0].size();
	int y[] = { -10, -5, 0, 5, 10 };
	for (int i = 0; i < 5; i++) {
		std::vector<double> res;
		int invY = -(y[i]);
		for (int x = -40; x <= 40; x++) {
			std::vector<std::vector<double>> r1 = shuffle_1(v,y[i],x);
			std::vector<std::vector<double>> r2 = shuffle_3(v,-y[i],x);
			res.push_back(get_correl(r1, r2,v.size(),v[0].size()));
			if (i == 0) {
				fout << x << "\n";
			}
		}
		if (i == 0) {
			for (int k = -100; k <= 100; k++)
				fout << k << "\n";
		}

		if (y[i] <= 0) {
			for (int x = 0; x <= 100; x++) {
				std::vector<std::vector<double>> tmp1, tmp2;
				for (int i1 = 0, i2 = invY; i1 < h - invY, i2 < h; i1++, i2++) {
					std::vector<double> vec1, vec2;
					for (int j1 = 0, j2 = x; j1 < w - x, j2 < w; j1++, j2++) {
						vec1.push_back(v2[mod(i1, h)][j1]);
						vec2.push_back(v2[mod(i2, h)][j2]);
					}
					tmp1.push_back(vec1);
					tmp2.push_back(vec2);
				}
				res.push_back(get_correl(tmp1, tmp2, tmp1.size(), tmp1[0].size()));
			}
			}
			else {
				for (int x = 0; x <= 100; x++) {
					std::vector<std::vector<double>> tmp1, tmp2;
					for (int i1 = 0, i2 = invY-1; i1 < h - invY-1, i2 < h; i1++, i2++) {
						std::vector<double> vec1, vec2;
						for (int j1 = 0, j2 = x; j1 < w - x, j2 < w; j1++, j2++) {
							vec1.push_back(v[mod(i1, h)][j1]);
							vec2.push_back(v[mod(i2, h)][j2]);
						}
						tmp1.push_back(vec1);
						tmp2.push_back(vec2);
					}
					res.push_back(get_correl(tmp1, tmp2, tmp1.size(), tmp1[0].size()));
				}
			}
			std::reverse(res.begin(), res.end());
			for (int t = 0; t < 100; t++) {
				res.push_back(res[100 - t - 1]);
			}
			if (i == 0) {
				file_write("blueavtocorrel0.txt", res);
				std::cout << "-10 Complete" << std::endl;
			}
			if (i == 1) {
				file_write("blueavtocorrel1.txt", res);
				std::cout << "-5 Complete" << std::endl;
			}
			if (i == 2) {
				file_write("blueavtocorrel2.txt", res);
				std::cout << "0 Complete" << std::endl;
			}
			if (i == 3) {
				file_write("blueavtocorrel3.txt", res);
				std::cout << "5 Complete" << std::endl;
			}
			if (i == 4) {
				file_write("blueavtocorrel4.txt", res);
				std::cout << "10 Complete" << std::endl;
			}
			res.clear();
			//blue
			//continue;
			for (int x = 0; x <= 100; x++) {
				std::vector<std::vector<double>> tmp1, tmp2;
				for (int i1 = 0, i2 = invY; i1 < h - invY, i2 < h; i1++, i2++) {
					std::vector<double> vec1, vec2;
					for (int j1 = 0, j2 = x; j1 < w - x, j2 < w; j1++, j2++) {
						vec1.push_back(v[mod(i1, h)][j1]);
						vec2.push_back(v[mod(i2, h)][j2]);
					}
					tmp1.push_back(vec1);
					tmp2.push_back(vec2);
				}
				res.push_back(get_correl(tmp1, tmp2, tmp2.size(), tmp2[0].size()));
			}
			std::reverse(res.begin(), res.end());
			for (int t = 0; t < 100; t++) {
				res.push_back(res[100 - t - 1]);
			}
			if (i == 0)
				file_write("redavtocorrel0.txt", res);
			if (i == 1)
				file_write("redavtocorrel1.txt", res);
			if (i == 2)
				file_write("redavtocorrel2.txt", res);
			if (i == 3)
				file_write("redavtocorrel3.txt", res);
			if (i == 4)
				file_write("redavtocorrel4.txt", res);
			res.clear();
			continue;
			//green


			for (int x = 0; x <= 100; x++) {
				std::vector<std::vector<double>> tmp1, tmp2;
				for (int i1 = 0, i2 = invY; i1 < h - invY, i2 < h; i1++, i2++) {
					std::vector<double> vec1, vec2;
					for (int j1 = 0, j2 = x; j1 < w - x, j2 < w; j1++, j2++) {
						vec1.push_back(v1[mod(i1, h)][j1]);
						vec2.push_back(v1[mod(i2, h)][j2]);
					}
					tmp1.push_back(vec1);
					tmp2.push_back(vec2);
				}
				res.push_back(get_correl(tmp1, tmp2, tmp1.size(), tmp1[0].size()));
			}
			std::reverse(res.begin(), res.end());
			for (int t = 0; t < 100; t++) {
				res.push_back(res[100 - t - 1]);
			}
			if (i == 0)
				file_write("greenavtocorrel0.txt", res);
			if (i == 1)
				file_write("greenavtocorrel1.txt", res);
			if (i == 2)
				file_write("greenavtocorrel2.txt", res);
			if (i == 3)
				file_write("greenavtocorrel3.txt", res);
			if (i == 4)
				file_write("greenavtocorrel4.txt", res);
			res.clear();
		}
	}
}






int main() {
	MBITMAPFILEHEADER bfh;
	MBITMAPINFOHEADER bih;
	FILE* f1;
	f1 = fopen("Original.bmp", "rb");
	if (f1 == NULL)
	{
		std::cout << "reading error";
		return 0;
	}
	MRGBQUAD** rgb1 = read_bmp(f1, &bfh, &bih);
	fclose(f1);
	int h1 = abs(bih.biHeight);
	int w1 = abs(bih.biWidth);
	int k = bfh.bfOffBits;
	std::cout << k << std::endl;

	MRGBQUAD** green = getG(rgb1, h1, w1);
	std::vector<std::vector<double>> g(h1);
	for (int i = 0; i < h1; i++) {
		for (int j = 0; j < w1; j++) {
			g[i].push_back((double)green[i][j].rgbGreen);
		}
	}
	//FILE* fgreen = fopen("outG.bmp", "wb");
	//write_bmp(fgreen, green, &bfh, &bih, h1, w1);
	//fclose(fgreen);

	MRGBQUAD** blue = getB(rgb1, h1, w1);
	std::vector<std::vector<double>> b(h1);
	for (int i = 0; i < h1; i++) {
		for (int j = 0; j < w1; j++) {
			b[i].push_back((double)blue[i][j].rgbBlue);
		}
	}
	//FILE* fblue = fopen("outB.bmp", "wb");
	//write_bmp(fblue, blue, &bfh, &bih, h1, w1);
	//fclose(fblue);

	MRGBQUAD** red = getR(rgb1, h1, w1);
	std::vector<std::vector<double>> r(h1);
	for (int i = 0; i < h1; i++) {
		for (int j = 0; j < w1; j++) {
			r[i].push_back((double)red[i][j].rgbRed);
		}
	}
	//FILE* fred = fopen("outR.bmp", "wb");
	//write_bmp(fred, red, &bfh, &bih, h1, w1);
	//fclose(fred);


	//correlation
	//avtocoorel(r);
	std::cout << "correl R-G = " << get_correl(r, g, h1, w1) << std::endl;
	std::cout << "correl R-B = " << get_correl(r, b, h1, w1) << std::endl;
	std::cout << "correl B-G = " << get_correl(b, g, h1, w1) << std::endl;

	//MRGBQUAD** zerkal = get_zerkal(rgb1, h1, w1);
	//FILE* fzerkal = fopen("zerkal.bmp", "wb");
	//write_bmp(fzerkal, zerkal, &bfh, &bih, h1, w1);
	//fclose(fzerkal);
	std::cout << std::endl;
	//avtocoorel(r,g,b);
	//std::cout << "complete!" << std::endl;
	//b /
	//..

	//5.0
	std::vector<std::vector<double>> Y(h1);
	std::vector<std::vector<double>> Cb(h1);
	std::vector<std::vector<double>> Cr(h1);
	for (int i = 0; i < h1; i++) {
		for (int j = 0; j < w1; j++) {
			Y[i].push_back((double)rgb1[i][j].rgbRed * 0.299 + (double)rgb1[i][j].rgbGreen * 0.587 + (double)rgb1[i][j].rgbBlue * 0.114);
			Cb[i].push_back(0.5643 * ((double)rgb1[i][j].rgbBlue - Y[i][j]) + 128);
			Cr[i].push_back(0.7132 * ((double)rgb1[i][j].rgbRed - Y[i][j]) + 128);
		}
	}
	//	std::cout << "DPCM_2_Y =" << entropy(Y) << std::endl;
		//nachalo
	std::cout << "correl Y-Cb = " << get_correl(Y, Cb, h1, w1) << std::endl;
	std::cout << "correl Y-Cr = " << get_correl(Y, Cr, h1, w1) << std::endl;
	std::cout << "correl Cb-Cr = " << get_correl(Cb, Cr, h1, w1) << std::endl;
	std::cout << std::endl;
	////start
	//MRGBQUAD** Yrgb = getRGBfromY(Y, h1, w1);
	//MRGBQUAD** Crrgb = getRGBfromY(Cr, h1, w1);
	//MRGBQUAD** Cbrgb = getRGBfromY(Cb, h1, w1);
	//
	////FILE* fY = fopen("outY.bmp", "wb");
	////FILE* fCb = fopen("outCb.bmp", "wb");
	////FILE* fCr = fopen("outCr.bmp", "wb");
	////write_bmp(fY, Yrgb, &bfh, &bih, h1, w1);
	////write_bmp(fCb, Cbrgb, &bfh, &bih, h1, w1);
	////write_bmp(fCr, Crrgb, &bfh, &bih, h1, w1);
	////fclose(fY);
	////fclose(fCb);
	////fclose(fCr);

	find_minmax(rgb1, h1, w1);
	MRGBQUAD** restoredRGB = getRGBfromYreverse(Y, Cb, Cr, h1, w1);
	//finish
	//FILE* frestRGB = fopen("restored.bmp", "wb");
	//write_bmp(frestRGB, restoredRGB, &bfh, &bih, h1, w1);
	//fclose(frestRGB);

	std::cout << "PSNR R = " << get_PSNR_only_R(restoredRGB, r, h1, w1) << std::endl;
	std::cout << "PSNR G = " << get_PSNR_only_G(restoredRGB, g, h1, w1) << std::endl;
	std::cout << "PSNR B = " << get_PSNR_only_B(restoredRGB, b, h1, w1) << std::endl;
	std::cout << std::endl;
	//8.0 a)

	std::vector<std::vector<double>> restCb1 = decimation1(Cb, h1, w1, 2);
	std::vector<std::vector<double>> restCr1 = decimation1(Cr, h1, w1, 2);
	MRGBQUAD** restoredRGB1 = getRGBfromYreverse(Y, restCb1, restCr1, h1, w1);
	//clipping(restoredRGB1, h1, w1);
	FILE* frestRGB1 = fopen("restored8a.bmp", "wb");
	write_bmp(frestRGB1, restoredRGB1, &bfh, &bih, h1, w1);
	fclose(frestRGB1);

	//8.0 б)

	std::vector<std::vector<double>> restCb2 = decimation2(Cb, h1, w1, 2);
	std::vector<std::vector<double>> restCr2 = decimation2(Cr, h1, w1, 2);
	MRGBQUAD** restoredRGB2 = getRGBfromYreverse(Y, restCb2, restCr2, h1, w1);
	//clipping(restoredRGB1, h1, w1);
	FILE* frestRGB2 = fopen("restored8b.bmp", "wb");
	write_bmp(frestRGB2, restoredRGB2, &bfh, &bih, h1, w1);
	fclose(frestRGB2);

	//pSNR
	std::cout << "PSNR Decimation1(a) YCbCr" << std::endl;
	std::cout << "PSNR Cb = " << get_PSNR(Cb, restCb1) << std::endl;
	std::cout << "PSNR Cr = " << get_PSNR(Cr, restCr1) << std::endl;

	std::cout << "PSNR Decimation1(a) RGB" << std::endl;
	std::cout << "PSNR R = " << get_PSNR_only_R(restoredRGB1, r, h1, w1) << std::endl;
	std::cout << "PSNR G = " << get_PSNR_only_G(restoredRGB1, g, h1, w1) << std::endl;
	std::cout << "PSNR B = " << get_PSNR_only_B(restoredRGB1, b, h1, w1) << std::endl;
	std::cout << std::endl;
	std::cout << "PSNR Decimation2(a) YCbCr" << std::endl;
	std::cout << "PSNR Cb = " << get_PSNR(Cb, restCb2) << std::endl;
	std::cout << "PSNR Cr = " << get_PSNR(Cr, restCr2) << std::endl;

	std::cout << "PSNR Decimation2(a) RGB" << std::endl;
	std::cout << "PSNR R = " << get_PSNR_only_R(restoredRGB2, r, h1, w1) << std::endl;
	std::cout << "PSNR G = " << get_PSNR_only_G(restoredRGB2, g, h1, w1) << std::endl;
	std::cout << "PSNR B = " << get_PSNR_only_B(restoredRGB2, b, h1, w1) << std::endl;

	//8.0 a)

	std::vector<std::vector<double>> restCb3 = decimation1(Cb, h1, w1, 4);
	std::vector<std::vector<double>> restCr3 = decimation1(Cr, h1, w1, 4);
	MRGBQUAD** restoredRGB3 = getRGBfromYreverse(Y, restCb3, restCr3, h1, w1);
	//clipping(restoredRGB1, h1, w1);
	FILE* frestRGB3 = fopen("restored2_8a.bmp", "wb");
	write_bmp(frestRGB3, restoredRGB3, &bfh, &bih, h1, w1);
	fclose(frestRGB3);

	//8.0 б)

	std::vector<std::vector<double>> restCb4 = decimation2(Cb, h1, w1, 4);
	std::vector<std::vector<double>> restCr4 = decimation2(Cr, h1, w1, 4);
	MRGBQUAD** restoredRGB4 = getRGBfromYreverse(Y, restCb4, restCr4, h1, w1);
	FILE* frestRGB4 = fopen("restored2_8b.bmp", "wb");
	write_bmp(frestRGB4, restoredRGB4, &bfh, &bih, h1, w1);
	fclose(frestRGB4);

	//pSNR
	std::cout << "\n <<<<<<<4-fold reduction>>>>>>> " << std::endl;
	std::cout << "PSNR Decimation1(a) YCbCr" << std::endl;
	std::cout << "PSNR Cb = " << get_PSNR(Cb, restCb3) << std::endl;
	std::cout << "PSNR Cr = " << get_PSNR(Cr, restCr3) << std::endl;

	std::cout << "PSNR Decimation1(a) RGB" << std::endl;
	std::cout << "PSNR R = " << get_PSNR_only_R(restoredRGB3, r, h1, w1) << std::endl;
	std::cout << "PSNR G = " << get_PSNR_only_G(restoredRGB3, g, h1, w1) << std::endl;
	std::cout << "PSNR B = " << get_PSNR_only_B(restoredRGB3, b, h1, w1) << std::endl;
	std::cout << std::endl;
	std::cout << "PSNR Decimation2(a) YCbCr" << std::endl;
	std::cout << "PSNR Cb = " << get_PSNR(Cb, restCb4) << std::endl;
	std::cout << "PSNR Cr = " << get_PSNR(Cr, restCr4) << std::endl;

	std::cout << "PSNR Decimation2(a) RGB" << std::endl;
	std::cout << "PSNR R = " << get_PSNR_only_R(restoredRGB4, r, h1, w1) << std::endl;
	std::cout << "PSNR G = " << get_PSNR_only_G(restoredRGB4, g, h1, w1) << std::endl;
	std::cout << "PSNR B = " << get_PSNR_only_B(restoredRGB4, b, h1, w1) << std::endl;


	file_write("R.txt", r, h1, w1);
	file_write("G.txt", g, h1, w1);
	file_write("B.txt", b, h1, w1);
	file_write("Y.txt", Y, h1, w1);
	file_write("Cb.txt", Cb, h1, w1);
	file_write("Cr.txt", Cr, h1, w1);

	std::cout << "H_R =" << entropy(r) << std::endl;
	std::cout << "H_G =" << entropy(g) << std::endl;
	std::cout << "H_B =" << entropy(b) << std::endl;
	std::cout << "H_Y =" << entropy(Y) << std::endl;
	std::cout << "H_Cb =" << entropy(Cb) << std::endl;
	std::cout << "H_Cr =" << entropy(Cr) << "\n" << std::endl;

	std::vector<std::vector<double>> dpcmr1 = get_DPCM1(r);
	std::vector<std::vector<double>> dpcmg1 = get_DPCM1(g);
	std::vector<std::vector<double>> dpcmb1 = get_DPCM1(b);
	std::vector<std::vector<double>> dpcmY1 = get_DPCM1(Y);
	std::vector<std::vector<double>> dpcmCb1 = get_DPCM1(Cb);
	std::vector<std::vector<double>> dpcmCr1 = get_DPCM1(Cr);

	file_write("dpcmR.txt", dpcmr1, h1, w1);
	file_write("dpcmG.txt", dpcmg1, h1, w1);
	file_write("dpcmB.txt", dpcmb1, h1, w1);
	file_write("dpcmY.txt", dpcmY1, h1, w1);
	file_write("dpcmCb.txt", dpcmCb1, h1, w1);
	file_write("dpcmCr.txt", dpcmCr1, h1, w1);
	//raznost

	std::cout << "H_DPCM_1_R =" << entropy(dpcmr1) << std::endl;
	std::cout << "H_DPCM_1_G =" << entropy(dpcmg1) << std::endl;
	std::cout << "H_DPCM_1_B =" << entropy(dpcmb1) << std::endl;
	std::cout << "H_DPCM_1_Y =" << entropy(dpcmY1) << std::endl;
	std::cout << "H_DPCM_1_Cb =" << entropy(dpcmCb1) << std::endl;
	std::cout << "H_DPCM_1_Cr =" << entropy(dpcmCr1) << "\n" << std::endl;

	//up
	std::vector<std::vector<double>> dpcmr2 = get_DPCM2(r);
	std::vector<std::vector<double>> dpcmg2 = get_DPCM2(g);
	std::vector<std::vector<double>> dpcmb2 = get_DPCM2(b);
	std::vector<std::vector<double>> dpcmY2 = get_DPCM2(Y);
	std::vector<std::vector<double>> dpcmCb2 = get_DPCM2(Cb);
	std::vector<std::vector<double>> dpcmCr2 = get_DPCM2(Cr);

	file_write("dpcmR2.txt", dpcmr2, h1, w1);
	file_write("dpcmG2.txt", dpcmg2, h1, w1);
	file_write("dpcmB2.txt", dpcmb2, h1, w1);
	file_write("dpcmY2.txt", dpcmY2, h1, w1);
	file_write("dpcmCb2.txt", dpcmCb2, h1, w1);
	file_write("dpcmCr2.txt", dpcmCr2, h1, w1);

	std::cout << "H_DPCM_2_R =" << entropy(dpcmr2) << std::endl;
	std::cout << "H_DPCM_2_G =" << entropy(dpcmg2) << std::endl;
	std::cout << "H_DPCM_2_B =" << entropy(dpcmb2) << std::endl;
	std::cout << "H_DPCM_2_Y =" << entropy(dpcmY2) << std::endl;
	std::cout << "H_DPCM_2_Cb =" << entropy(dpcmCb2) << std::endl;
	std::cout << "H_DPCM_2_Cr =" << entropy(dpcmCr2) << "\n" << std::endl;

	//upleft
	std::vector<std::vector<double>> dpcmr3 = get_DPCM3(r);
	std::vector<std::vector<double>> dpcmg3 = get_DPCM3(g);
	std::vector<std::vector<double>> dpcmb3 = get_DPCM3(b);
	std::vector<std::vector<double>> dpcmY3 = get_DPCM3(Y);
	std::vector<std::vector<double>> dpcmCb3 = get_DPCM3(Cb);
	std::vector<std::vector<double>> dpcmCr3 = get_DPCM3(Cr);

	file_write("dpcmR3.txt", dpcmr3, h1, w1);
	file_write("dpcmG3.txt", dpcmg3, h1, w1);
	file_write("dpcmB3.txt", dpcmb3, h1, w1);
	file_write("dpcmY3.txt", dpcmY3, h1, w1);
	file_write("dpcmCb3.txt", dpcmCb3, h1, w1);
	file_write("dpcmCr3.txt", dpcmCr3, h1, w1);

	std::cout << "H_DPCM_3_R =" << entropy(dpcmr3) << std::endl;
	std::cout << "H_DPCM_3_G =" << entropy(dpcmg3) << std::endl;
	std::cout << "H_DPCM_3_B =" << entropy(dpcmb3) << std::endl;
	std::cout << "H_DPCM_3_Y =" << entropy(dpcmY3) << std::endl;
	std::cout << "H_DPCM_3_Cb =" << entropy(dpcmCb3) << std::endl;
	std::cout << "H_DPCM_3_Cr =" << entropy(dpcmCr3) << "\n" << std::endl;

	//arith
	std::vector<std::vector<double>> dpcmr4 = get_DPCM4(r);
	std::vector<std::vector<double>> dpcmg4 = get_DPCM4(g);
	std::vector<std::vector<double>> dpcmb4 = get_DPCM4(b);
	std::vector<std::vector<double>> dpcmY4 = get_DPCM4(Y);
	std::vector<std::vector<double>> dpcmCb4 = get_DPCM4(Cb);
	std::vector<std::vector<double>> dpcmCr4 = get_DPCM4(Cr);

	file_write("dpcmR4.txt", dpcmr4, h1, w1);
	file_write("dpcmG4.txt", dpcmg4, h1, w1);
	file_write("dpcmB4.txt", dpcmb4, h1, w1);
	file_write("dpcmY4.txt", dpcmY4, h1, w1);
	file_write("dpcmCb4.txt", dpcmCb4, h1, w1);
	file_write("dpcmCr4.txt", dpcmCr4, h1, w1);

	std::cout << "H_DPCM_4_R =" << entropy(dpcmr4) << std::endl;
	std::cout << "H_DPCM_4_G =" << entropy(dpcmg4) << std::endl;
	std::cout << "H_DPCM_4_B =" << entropy(dpcmb4) << std::endl;
	std::cout << "H_DPCM_4_Y =" << entropy(dpcmY4) << std::endl;
	std::cout << "H_DPCM_4_Cb =" << entropy(dpcmCb4) << std::endl;
	std::cout << "H_DPCM_4_Cr =" << entropy(dpcmCr4) << "\n" << std::endl;


	return 0;
}