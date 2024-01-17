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
#include <time.h>
using namespace std;

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

MRGBQUAD** readBmp(FILE* f, MBITMAPFILEHEADER* bfh, MBITMAPINFOHEADER* bih)
{
	int k = 0;
	k = fread(bfh, sizeof(*bfh) - 2, 1, f);
	if (k == 0) {
		cout << "Error!" << endl;
		return 0;
	}

	k = fread(bih, sizeof(*bih), 1, f);
	if (k == NULL) {
		cout << "Error!" << endl;
		return 0;
	}
	int height = abs(bih->biHeight);
	int width = abs(bih->biWidth);
	MRGBQUAD** rgb = new MRGBQUAD * [height];
	for (int i = 0; i < height; i++) {
		rgb[i] = new MRGBQUAD[width];
	}
	int pad = 4 - (width * 3) % 4;
	for (int i = 0; i < height; i++) {
		fread(rgb[i], sizeof(MRGBQUAD), width, f);
		if (pad != 4) {
			fseek(f, pad, SEEK_CUR);
		}
	}
	return rgb;
}

void writeBMP(FILE* f, MRGBQUAD** rgbb, MBITMAPFILEHEADER* bfh, MBITMAPINFOHEADER* bih, int height, int width) {
	bih->biHeight = height;
	bih->biWidth = width;
	fwrite(bfh, sizeof(*bfh) - 2, 1, f);
	fwrite(bih, sizeof(*bih), 1, f);
	int pad = 4 - ((width) * 3) % 4;
	char buf = 0;
	for (int i = 0; i < height; i++) {
		fwrite((rgbb[i]), sizeof(MRGBQUAD), width, f);
		if (pad != 4) {
			fwrite(&buf, 1, pad, f);
		}
	}
}


void findMinMax(MRGBQUAD** rgb, int height, int width) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (rgb[i][j].rgbRed > max_R)	max_R = rgb[i][j].rgbRed;
			if (rgb[i][j].rgbGreen > max_G)	max_G = rgb[i][j].rgbGreen;
			if (rgb[i][j].rgbBlue > max_B)	max_B = rgb[i][j].rgbBlue;
			if (rgb[i][j].rgbRed < min_R)	min_R = rgb[i][j].rgbRed;
			if (rgb[i][j].rgbGreen < min_G)	min_G = rgb[i][j].rgbGreen;
			if (rgb[i][j].rgbBlue < min_B)	min_B = rgb[i][j].rgbBlue;
		}
	}
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

MRGBQUAD** getRGBfromY(vector<vector<double>> Y, int height, int width) {
	MRGBQUAD** rgb = new MRGBQUAD * [height];
	for (int i = 0; i < height; i++) {
		rgb[i] = new MRGBQUAD[width];
	}
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			rgb[i][j].rgbGreen = Y[i][j];
			rgb[i][j].rgbBlue = Y[i][j];
			rgb[i][j].rgbRed = Y[i][j];
		}
	}
	return rgb;
}

double calculteRandomDouble() {
	return (double)(rand() % 1000) / 1000.0;
}

double calculteRandomDoubleV2() {
	return (double)(rand() % 2000 - 1000) / 1000;
}

vector<vector<double>> generateImpulseNoise(vector<vector<double>>& rgb, int height, int width, double probabilityA, double probabilityB) {
	probabilityB = probabilityB + probabilityA;
	vector<vector<double>> result(height);
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			double tmp = calculteRandomDouble();
			if (tmp <= probabilityA) {
				result[i].push_back(0);
				continue;
			}
			if (tmp <= probabilityB) {
				result[i].push_back(255);
				continue;
			}
			result[i].push_back(rgb[i][j]);
		}
	}
	return result;
}
vector<vector<double>> generateGaussianNoise(vector<vector<double>>& rgb, int height, int width, double sigma) {
	vector<vector<double>> result(height);
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j += 2) {
			double r = calculteRandomDouble();
			double phi = calculteRandomDouble();
			result[i].push_back(sigma * sqrt((-2) * log(r)) * cos(2 * M_PI * phi));
			result[i].push_back(sigma * sqrt((-2) * log(r)) * sin(2 * M_PI * phi));
		}
	}
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			result[i][j] = clipping(rgb[i][j] + result[i][j]);
		}
	}
	return result;
}

vector<vector<double>> generateGaussianNoiseV2(vector<vector<double>>& rgb, int height, int width, double sigma) {
	vector<vector<double>> result(height);
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j += 2) {
			double x = calculteRandomDoubleV2();
			double y = calculteRandomDoubleV2();
			double s = (x * x) + (y * y);
			while (s > 1 || s == 0)
			{
				x = calculteRandomDoubleV2();
				y = calculteRandomDoubleV2();
				s = (x * x) + (y * y);
			}
			result[i].push_back(sigma * x * sqrt(-2 * log(s) / s));
			result[i].push_back(sigma * y * sqrt(-2 * log(s) / s));
		}
	}
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			result[i][j] = clipping(rgb[i][j] + result[i][j]);
		}
	}
	return result;
}


void writeFile(string filename, vector<double>& array) {
	ofstream fout;
	fout.open(filename);
	for (int i = 0; i < array.size(); ++i) {
		fout << array[i] << "\n";
	}
	fout.close();
}

void writeFile(string filename, vector<double>& x, vector<double>& y) {
	ofstream fout;
	fout.open(filename);
	for (int i = 0; i < x.size(); ++i) {
		fout << x[i] << "     " << y[i] << "\n";
	}
	fout.close();
}

void writeFile(string filename, vector<vector<double>>& v, int height, int width) {
	ofstream fout;
	fout.open(filename);
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			fout << v[i][j] << " ";
		}
		fout << "\n";
	}
	fout.close();
}

double calculateSumSquareDifferense(vector<vector<double>> firstArray, vector<vector<double>> secondArray) {
	double result = 0;
	for (int i = 0; i < firstArray.size(); i++) {
		for (int j = 0; j < firstArray[0].size(); j++) {
			result += pow((firstArray[i][j] - secondArray[i][j]), 2);
		}
	}
	return result;
}

double calculatePSNR(vector<vector<double>> firstArray, vector<vector<double>> secondArray) {
	return 10 * log10(firstArray.size() * firstArray[0].size() * pow((pow(2, 8) - 1), 2) / calculateSumSquareDifferense(firstArray, secondArray));
}

void buildGraphicsPSNR(vector<vector<double>>& array) {
	vector<double> result;
	vector<double> sigma = { 1, 10, 30, 50, 80 };
	for (int i = 0; i < sigma.size(); i++) {
		vector<vector<double>> gausY = generateGaussianNoiseV2(array, array.size(), array[0].size(), sigma[i]);
		result.push_back(calculatePSNR(array, gausY));
	}
	writeFile("gausPSNR.txt", sigma, result);
	vector<double> impulseResult;
	vector<double> freq = { 0.025, 0.05, 0.125, 0.25 };
	for (int i = 0; i < freq.size(); i++) {
		vector<vector<double>> impulseY = generateImpulseNoise(array, array.size(), array[0].size(), freq[i], freq[i]);
		impulseResult.push_back(calculatePSNR(array, impulseY));
	}
	writeFile("impulsePSNR.txt", freq, impulseResult);
}

vector<vector<double>> generateMovingAverage(vector<vector<double>>& array, int R) {
	vector<vector<double>> result(array.size());
	for (int i = 0; i < array.size(); i++) {
		for (int j = 0; j < array[0].size(); j++) {
			double tmp = 0;
			for (int k = -R; k <= R; k++) {
				for (int m = -R; m <= R; m++) {
					int x = i + k;
					int y = j + m;
					if (x < 0) {
						x = 0;
					}
					if (x > array.size() - 1) {
						x = array.size() - 1;
					}
					if (y < 0) {
						y = 0;
					}
					if (y > array[0].size() - 1) {
						y = array[0].size() - 1;
					}
					tmp += array[x][y];
				}

			}
			result[i].push_back(tmp / (double)pow((2 * R + 1), 2));
		}
	}
	return result;
}

void printSigmaPsnrR(vector<vector<double>>& array) {
	double sigma[] = { 1, 10, 30, 50, 80 };
	for (int i = 0; i < 5; i++) {
		cout << "SIGMA = " << sigma[i] << endl;
		vector<vector<double>> Y = generateGaussianNoiseV2(array, array.size(), array[0].size(), sigma[i]);
		for (int R = 1; R <= 5; R++) {
			vector<vector<double>> YR = generateMovingAverage(Y, R);
			cout << "R = " << R << " PSNR = " << calculatePSNR(array, YR) << endl;
		}
	}
}

vector<vector<double>> doGaussianFilter(vector<vector<double>>& array, int R, double sigma) {
	vector<vector<double>> result(array.size());
	for (int i = 0; i < array.size(); i++) {
		for (int j = 0; j < array[0].size(); j++) {
			double w = 0;
			double sum = 0;
			double Z = 0;
			for (int k = -R; k <= R; k++) {
				for (int m = -R; m <= R; m++) {
					int x = i + k;
					int y = j + m;
					if (x < 0) {
						x = 0;
					}
					if (x > array.size() - 1) {
						x = array.size() - 1;
					}
					if (y < 0) {
						y = 0;
					}
					if (y > array[0].size() - 1) {
						y = array[0].size() - 1;
					}
					w = exp((-(k * k + m * m)) / (2.0 * sigma * sigma));
					Z = Z + w;
					sum = sum + array[x][y] * w;
				}

			}
			result[i].push_back(sum / (double)Z);
		}
	}
	return result;
}



void buildGaussianFilterGraphicsPSNR(vector<vector<double>>& array) {
	vector<double> sigmaNoise = { 1, 10, 30, 50, 80 };
	vector<double> sigmaFilter = { 0.1, 0.25, 0.5, 0.75, 1, 1.25, 1.5, 2};

	for (int R = 1; R <= 5; R += 2) {
		for (int i = 0; i < sigmaNoise.size(); i++) {
			vector<double> result(sigmaFilter.size());
			vector<vector<double>> Y = generateGaussianNoiseV2(array, array.size(), array[0].size(), sigmaNoise[i]);
			for (int j = 0; j < sigmaFilter.size(); j++) {
				vector<vector<double>> YR = doGaussianFilter(Y, R, sigmaFilter[j]);
				result[j] = (calculatePSNR(array, YR));
				//cout << result[j] << " done R: " << R << ";   N:  " << j + i * sigmaFilter.size() << endl;
			}
			
			writeFile("R" + to_string(R) + "SN" + to_string(i) + ".txt", sigmaFilter, result);
			result.clear();
		}

	}
}

vector<vector<double>> doMedianFilter(vector<vector<double>>& array, int R) {
	vector<vector<double>> result(array.size());
	for (int i = 0; i < array.size(); i++) {
		for (int j = 0; j < array[0].size(); j++) {
			vector<double> tmp;
			for (int k = -R; k <= R; k++) {
				for (int m = -R; m <= R; m++) {
					int x = i + k;
					int y = j + m;
					if (x < 0) {
						x = 0;
					}
					if (x > array.size() - 1) {
						x = array.size() - 1;
					}
					if (y < 0) {
						y = 0;
					}
					if (y > array[0].size() - 1) {
						y = array[0].size() - 1;
					}
					tmp.push_back(array[x][y]);
				}

			}
			sort(tmp.begin(), tmp.end());
			result[i].push_back(tmp[tmp.size() / 2]);
		}
	}
	return result;
}

void printGausNoiseMedianFilterPSNR(vector<vector<double>>& array) {
	cout << "<<<<<< Median Filter >>>>\n";
	double sigma[] = { 1, 10, 30, 50, 80 };
	for (int i = 0; i < 5; i++) {
		cout << "SIGMA = " << sigma[i] << endl;
		vector<vector<double>> Y = generateGaussianNoiseV2(array, array.size(), array[0].size(), sigma[i]);
		for (int R = 1; R <= 5; R++) {
			vector<vector<double>> YR = doMedianFilter(Y, R);
			cout << "R = " << R << " PSNR = " << calculatePSNR(array, YR) << endl;
		}
	}
}

void printImpulseNoiseMedianFilterPSNR(vector<vector<double>>& array) {
	cout << "<<<<<< Median Filter >>>>\n";
	vector<double> p = { 0.025, 0.05, 0.125, 0.25 };
	vector<double> R = { 1, 2, 3, 4, 5 };
	for (int i = 0; i < p.size(); i++) {
		cout << "a = b = " << p[i] << endl;
		vector<vector<double>> Y = generateImpulseNoise(array, array.size(), array[0].size(), p[i], p[i]);
		vector<double> PSNR(R.size());
		for (int j = 0; j < R.size(); j++) {
			vector<vector<double>> YR = doMedianFilter(Y, (int)R[j]);
			PSNR[j] = calculatePSNR(array, YR);
			cout << "R = " << (int)R[j] << " PSNR = " << PSNR[j] << endl;
		}
		writeFile("MFilterP" + to_string(p[i]) +".txt", R, PSNR);
		PSNR.clear();
	}
}

void writeImage(string filename, MRGBQUAD** rgb, MBITMAPFILEHEADER* bfh, MBITMAPINFOHEADER* bih, int height, int width) {
	FILE* f = fopen(filename.c_str(), "wb");
	writeBMP(f, rgb, bfh, bih, height, width);
	fclose(f);
}

void printComparisonFilters(vector<vector<double>>& Y, MBITMAPFILEHEADER* bfh, MBITMAPINFOHEADER* bih, double sigma, 
	double filterR, double filterSigma, double movingAverageR, double medianFilterR, size_t i, vector<double>& resGausNoise,
	vector<double>& resGausFilter, vector<double>& resMovingAverage, vector<double>& resMedianFilter) {
	int height = Y.size();
	int width = Y[0].size();
	vector<vector<double>> gausY = generateGaussianNoiseV2(Y, Y.size(), Y[0].size(), sigma);
	vector<vector<double>> gausFilterY = doGaussianFilter(gausY, filterR, filterSigma);
	MRGBQUAD** restoredRGB1 = getRGBfromY(gausY, height, width);
	MRGBQUAD** restoredRGB2 = getRGBfromY(gausFilterY, height, width);

	double psnrNoise = calculatePSNR(Y, gausY);
	resGausNoise[i] = psnrNoise;
	double psnrGauseFilter = calculatePSNR(Y, gausFilterY);
	resGausFilter[i] = psnrGauseFilter;
	writeImage("gaussianNoise" + to_string((int)sigma) +".bmp", restoredRGB1, bfh, bih, height, width);
	writeImage("gaussianFilter" + to_string((int)sigma) + ".bmp", restoredRGB2, bfh, bih, height, width);
	cout << "sigma = " << sigma << "; gaussian noise PSNR = " << psnrNoise << "\n";
	cout << "sigma = " << sigma << "; gaussian filter PSNR = " << psnrGauseFilter << "\n";

	vector<vector<double>> movingAverageY = generateMovingAverage(gausY, movingAverageR);
	MRGBQUAD** restoredRGB3 = getRGBfromY(movingAverageY, height, width);
	double psnrMovingAverage = calculatePSNR(Y, movingAverageY);
	resMovingAverage[i] = psnrMovingAverage;
	cout << "sigma = " << sigma << "; moving average PSNR = " << psnrMovingAverage << "\n";
	writeImage("movingAverage" + to_string((int)sigma) + ".bmp", restoredRGB3, bfh, bih, height, width);

	vector<vector<double>> medianFilterY = doMedianFilter(gausY, medianFilterR);
	MRGBQUAD** restoredRGB4 = getRGBfromY(medianFilterY, height, width);
	double psnrMedianFilter = calculatePSNR(Y, medianFilterY);
	resMedianFilter[i] = psnrMedianFilter;
	cout << "sigma = " << sigma << "; median filter PSNR = " << psnrMedianFilter << "\n";
	writeImage("medianFilter" + to_string((int)sigma) + ".bmp", restoredRGB4, bfh, bih, height, width);
	cout << endl;
}

void compareFilters(vector<vector<double>>& Y, MBITMAPFILEHEADER* bfh, MBITMAPINFOHEADER* bih) {
	vector<double> sigma = {1, 10, 30, 50, 80};
	vector<double> filterR = { 1, 1, 3, 5, 5 };
	vector<double> filterSigma = {0.25, 0.75, 1.25, 2, 2};
	vector<double> movingAverageR = {1, 1, 2, 3, 4};
	vector<double> medianFilterR = { 1, 1, 3, 4, 5 };
	vector<double> resultGausNoise(sigma.size());
	vector<double> resultGausFilter(sigma.size());
	vector<double> resultMovingAverage(sigma.size());
	vector<double> resultMedianFilter(sigma.size());
	for (size_t i = 0; i < sigma.size(); i++) {
		printComparisonFilters(Y, bfh, bih, sigma[i], filterR[i], filterSigma[i], movingAverageR[i], medianFilterR[i], i, resultGausNoise, resultGausFilter, resultMovingAverage, resultMedianFilter);
	}
	writeFile("resultGausNoise.txt", sigma, resultGausNoise);
	writeFile("resultGausFilter.txt", sigma, resultGausFilter);
	writeFile("resultMovingAverage.txt", sigma, resultMovingAverage);
	writeFile("resultMedianFilter.txt", sigma, resultMedianFilter);
}

vector<vector<double>> laplasian(vector<vector<double>>& rgb, int height, int width, double pl) {
	const int R = 1;
	vector<vector<double>> n(rgb.size());
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (i + 1 < height && i - 1 >= 0 && j + 1 < width && j - 1 >= 0) {
				n[i].push_back(clipping((rgb[i][j + 1] + rgb[i][j - 1] + rgb[i + 1][j] + rgb[i - 1][j] - (4 * rgb[i][j])) + pl));
			}
			else
			{
				n[i].push_back(rgb[i][j]);
			}
		}
	}
	return n;
}

vector<vector<double>> laplasianAlpha(vector<vector<double>>& rgb, int height, int width) {
	const int R = 1;
	double weight_matrix[3][3] = { { 0, -1, 0 } ,{ -1,  4, -1 },{ 0, -1, 0 } };

	vector<vector<double>> n(rgb.size());
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			double result = 0;
			for (int k = -R; k <= R; k++) {
				for (int m = -R; m <= R; m++) {
					int x = i + k;
					int y = j + m;
					if (x < 0)
						x = 0;
					if (x > rgb.size() - 1)
						x = rgb.size() - 1;
					if (y < 0)
						y = 0;
					if (y > rgb[0].size() - 1)
						y = rgb[0].size() - 1;
					double tmp = rgb[x][y];
					result += tmp * weight_matrix[k + 1][m + 1];
				}
			}
			n[i].push_back(clipping(rgb[i][j] + result));
		}
	}
	return n;
}

vector<vector<double>> laplasian2(vector<vector<double>>& rgb, int height, int width, double pl) {
	const int R = 1;
	vector<vector<double>> n(rgb.size());
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (i + 1 < height && i - 1 >= 0 && j + 1 < width && j - 1 >= 0) {
				n[i].push_back(clipping((-rgb[i][j + 1] - rgb[i][j - 1] - rgb[i + 1][j] - rgb[i - 1][j] + (4 * rgb[i][j])) + pl));
			}
			else
			{
				n[i].push_back(rgb[i][j]);
			}
		}
	}
	return n;
}

vector<vector<double>> laplasianAlpha2(vector<vector<double>>& rgb, double alpha, int height, int width, double pl) {
	const int R = 1;
	vector<vector<double>> n(rgb.size());
	double weight_matrix[3][3] = { { 0, -1, 0 } ,{ -1, alpha + 4, -1 },{ 0, -1, 0 } };
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			double result = 0;
			for (int k = -R; k <= R; k++) {
				for (int m = -R; m <= R; m++) {
					int x = i + k;
					int y = j + m;
					if (x < 0)
						x = 0;
					if (x > rgb.size() - 1)
						x = rgb.size() - 1;
					if (y < 0)
						y = 0;
					if (y > rgb[0].size() - 1)
						y = rgb[0].size() - 1;
					double tmp = rgb[x][y];
					result += tmp * weight_matrix[k + 1][m + 1];
				}
			}
			n[i].push_back(clipping(rgb[i][j] * (alpha - 1) + result));
		}
	}
	return n;
}

double calculateAverageBright(vector<vector<double>>& rgb) {
	double result = 0;
	for (int i = 0; i < rgb.size(); i++) {
		for (int j = 0; j < rgb[0].size(); j++) {
			result += rgb[i][j];
		}
	}
	return result / (rgb.size() * rgb[0].size());
}

typedef struct Sobel {
	double Gh;
	double Gv;
	double I;
	double theta;
} Sobel;

vector<vector<double>> sobel(vector<vector<double>> rgb, int thr, int height, int width) {
	vector<vector<double>> mas(height);
	const int R = 1;
	const double mask_h[3][3] = { { -1, 0, 1 } ,{ -2, 0, 2 },{ -1, 0, 1 } };
	const double mask_v[3][3] = { { 1, 2, 1 } ,{ 0, 0, 0 },{ -1, -2, -1 } };
	for (int i = 0; i < height; i++) {
		vector<Sobel> vec;
		for (int j = 0; j < width; j++) {
			double Gh = 0, Gv = 0;
			for (int k = -R; k <= R; k++) {
				for (int m = -R; m <= R; m++) {
					int x = i + k;
					int y = j + m;
					if (x < 0) x = 0;
					if (x > (height - 1)) x = height - 1;
					if (y < 0) y = 0;
					if (y > (width - 1)) y = width - 1;
					double cur = rgb[x][y];
					Gh += cur * mask_h[k + 1][m + 1];
					Gv += cur * mask_v[k + 1][m + 1];
				}
			}
			double I = sqrt(pow(Gh, 2) + pow(Gv, 2));
			if (I > thr) I = 255;
			else I = 0;
			double theta = atan2(Gv, Gh);
			mas[i].push_back(I);
		}
	}
	return mas;
}

vector<vector<Sobel>> sobel_param(vector<vector<double>> rgb, int thr, int height, int width) {
	vector<vector<Sobel>> sobelData;
	vector<vector<double>> mas(height);
	const int R = 1;
	const double mask_h[3][3] = { { -1, 0, 1 } ,{ -2, 0, 2 },{ -1, 0, 1 } };
	const double mask_v[3][3] = { { 1, 2, 1 } ,{ 0, 0, 0 },{ -1, -2, -1 } };
	for (int i = 0; i < height; i++) {
		vector<Sobel> vec;
		for (int j = 0; j < width; j++) {
			Sobel tmp;
			double Gh = 0, Gv = 0;
			for (int k = -R; k <= R; k++) {
				for (int m = -R; m <= R; m++) {
					int x = i + k;
					int y = j + m;
					if (x < 0) x = 0;
					if (x > (height - 1)) x = height - 1;
					if (y < 0) y = 0;
					if (y > (width - 1)) y = width - 1;
					double cur = rgb[x][y];
					Gh += cur * mask_h[k + 1][m + 1];
					Gv += cur * mask_v[k + 1][m + 1];
				}
			}
			tmp.Gh = Gh;
			tmp.Gv = Gv;
			tmp.I = sqrt(pow(Gh, 2) + pow(Gv, 2));
			if (tmp.I > thr) tmp.I = 255;
			else tmp.I = 0;
			tmp.theta = atan2(Gv, Gh);
			mas[i].push_back(tmp.I);
			vec.push_back(tmp);
		}
		sobelData.push_back(vec);
	}
	return sobelData;
}

MRGBQUAD** gradient(std::vector<std::vector<Sobel>>& sobel_data, int h, int w) {
	MRGBQUAD** rgb;
	rgb = new MRGBQUAD * [h];
	for (int i = 0; i < h; i++) {
		rgb[i] = new MRGBQUAD[w];
	}
	RGB blue = { 0, 0, 255 };
	RGB green = { 0, 255, 0 };
	RGB red = { 255, 0, 0 };
	RGB white = { 255, 255, 255 };
	for (size_t i = 0; i < h; i++) {
		for (size_t j = 0; j < w; j++) {
			if (sobel_data[i][j].Gh > 0 && sobel_data[i][j].Gv > 0) rgb[i][j] =
				red;
			if (sobel_data[i][j].Gh < 0 && sobel_data[i][j].Gv > 0) rgb[i][j] =
				green;
			if (sobel_data[i][j].Gh < 0 && sobel_data[i][j].Gv < 0) rgb[i][j] =
				blue;
			if (sobel_data[i][j].Gh > 0 && sobel_data[i][j].Gv < 0) rgb[i][j] =
				white;
		}
	}
	return rgb;
}

int main() {
	MBITMAPFILEHEADER bfh;
	MBITMAPINFOHEADER bih;
	FILE* f = fopen("Original.bmp", "rb");
	if (f == NULL){
		cout << "reading error";
		return 0;
	}
	MRGBQUAD** rgb = readBmp(f, &bfh, &bih);
	fclose(f);
	int height = abs(bih.biHeight);
	int width = abs(bih.biWidth);

	vector<vector<double>> Y(height);
	vector<vector<double>> Cb(height);
	vector<vector<double>> Cr(height);

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			Y[i].push_back((double)rgb[i][j].rgbRed * 0.299 + (double)rgb[i][j].rgbGreen * 0.587 + (double)rgb[i][j].rgbBlue * 0.114);
			Cb[i].push_back(0.5643 * ((double)rgb[i][j].rgbBlue - Y[i][j]) + 128);
			Cr[i].push_back(0.7132 * ((double)rgb[i][j].rgbRed - Y[i][j]) + 128);
		}
	}

	findMinMax(rgb, height, width);
	srand(time(NULL));
	vector<vector<double>> gausY = generateGaussianNoiseV2(Y, height, width, 30); // 1
	rgb = getRGBfromY(gausY, height, width);
	f = fopen("gaussianNoise50.bmp", "wb");
	writeBMP(f, rgb, &bfh, &bih, height, width);
	fclose(f);
	
	vector<vector<double>> impulseY = generateImpulseNoise(Y, height, width, 0.125, 0.125); // 2
	rgb = getRGBfromY(impulseY, height, width);
	f = fopen("impulseNoise0.125.bmp", "wb");
	writeBMP(f, rgb, &bfh, &bih, height, width);
	fclose(f);
	
	buildGraphicsPSNR(Y); //3
	
	vector<vector<double>> movingAverageY = generateMovingAverage(gausY, 1); // 4.1, 4.2
	rgb = getRGBfromY(movingAverageY, height, width);
	cout << "\n" << "old PSNR: " << calculatePSNR(Y, gausY);
	cout << "\n" << "new PSNR: " << calculatePSNR(Y, movingAverageY) << endl;
	f = fopen("gaussianNoiseMovingAverage.bmp", "wb");
	writeBMP(f, rgb, &bfh, &bih, height, width);
	fclose(f);
	printSigmaPsnrR(Y);
	
	vector<vector<double>> gausFilterY = doGaussianFilter(gausY, 3, 1); // 4.3, 4.4
	rgb = getRGBfromY(gausFilterY, height, width);
	cout << "\n" << "old PSNR: " << calculatePSNR(Y, gausY);
	cout << "\n" << "new PSNR: " << calculatePSNR(Y, gausFilterY) << endl;
	f = fopen("gaussianFilter.bmp", "wb");
	writeBMP(f, rgb, &bfh, &bih, height, width);
	fclose(f);
	
	buildGaussianFilterGraphicsPSNR(Y); // 4.5
	
	vector<vector<double>> medianFilterY = doMedianFilter(gausY, 3); //4.7
	rgb = getRGBfromY(medianFilterY, height, width);
	cout << "\n" << "old PSNR: " << calculatePSNR(Y, gausY);
	cout << "\n" << "new PSNR: " << calculatePSNR(Y, medianFilterY) << endl;
	f = fopen("medianFilter.bmp", "wb");
	writeBMP(f, rgb, &bfh, &bih, height, width);
	fclose(f);

	printGausNoiseMedianFilterPSNR(Y); // 4.8

	compareFilters(Y, &bfh, &bih); // 4.6 и 4.9

	
	/*
	vector<vector<double>> impulseY1 = generateImpulseNoise(Y, height, width, 0.025, 0.025); //5.1
	rgb = getRGBfromY(impulseY1, height, width);
	f = fopen("impulseNoise0.025.bmp", "wb");
	writeBMP(f, rgb, &bfh, &bih, height, width);
	fclose(f);

	vector<vector<double>> impulseY2 = generateImpulseNoise(Y, height, width, 0.05, 0.05);
	rgb = getRGBfromY(impulseY2, height, width);
	f = fopen("impulseNoise0.05.bmp", "wb");
	writeBMP(f, rgb, &bfh, &bih, height, width);
	fclose(f);

	vector<vector<double>> impulseY3 = generateImpulseNoise(Y, height, width, 0.125, 0.125);
	rgb = getRGBfromY(impulseY3, height, width);
	f = fopen("impulseNoise0.125.bmp", "wb");
	writeBMP(f, rgb, &bfh, &bih, height, width);
	fclose(f);

	vector<vector<double>> impulseY4 = generateImpulseNoise(Y, height, width, 0.25, 0.25);
	rgb = getRGBfromY(impulseY4, height, width);
	f = fopen("impulseNoise0.25.bmp", "wb");
	writeBMP(f, rgb, &bfh, &bih, height, width);
	fclose(f);

	cout << "\n" << "5% PSNR = " << calculatePSNR(Y, impulseY1); // 5.2
	cout << "\n" << "10% PSNR = " << calculatePSNR(Y, impulseY2);
	cout << "\n" << "25% PSNR = " << calculatePSNR(Y, impulseY3);
	cout << "\n" << "50% PSNR = " << calculatePSNR(Y, impulseY4) << "\n";

	rgb = getRGBfromY(doMedianFilter(impulseY1, 1), height, width); //5. 3
	f = fopen("impulseNoiseMedianFilterPSNR5.bmp", "wb");
	writeBMP(f, rgb, &bfh, &bih, height, width);
	fclose(f);

	rgb = getRGBfromY(doMedianFilter(impulseY2, 1), height, width);
	f = fopen("impulseNoiseMedianFilterPSNR10.bmp", "wb");
	writeBMP(f, rgb, &bfh, &bih, height, width);
	fclose(f);

	rgb = getRGBfromY(doMedianFilter(impulseY3, 2), height, width);
	f = fopen("impulseNoiseMedianFilterPSNR25.bmp", "wb");
	writeBMP(f, rgb, &bfh, &bih, height, width);
	fclose(f);

	rgb = getRGBfromY(doMedianFilter(impulseY4, 3), height, width);
	f = fopen("impulseNoiseMedianFilterPSNR50.bmp", "wb");
	writeBMP(f, rgb, &bfh, &bih, height, width);
	fclose(f);
	

	printImpulseNoiseMedianFilterPSNR(Y); // без графиков
	*/

	/*
	f = fopen("laplasianImage1.bmp", "wb");
	writeBMP(f, getRGBfromY(laplasian(Y, height, width, 0), height, width), &bfh, &bih, height, width);
	fclose(f);

	f = fopen("laplasianImage2.bmp", "wb");
	writeBMP(f, getRGBfromY(laplasian(Y, height, width, 128), height, width), &bfh, &bih, height, width);
	fclose(f);

	f = fopen("laplasianImage3.bmp", "wb");
	writeBMP(f, getRGBfromY(laplasian2(Y, height, width, 0), height, width), &bfh, &bih, height, width);
	fclose(f);

	f = fopen("laplasianImage4.bmp", "wb");
	writeBMP(f, getRGBfromY(laplasian2(Y, height, width, 128), height, width), &bfh, &bih, height, width);
	fclose(f);

	//1.3-1.5
	f = fopen("laplasianImage1,3.bmp", "wb");
	writeBMP(f, getRGBfromY(laplasianAlpha( Y, height, width), height, width), &bfh, &bih, height, width);
	fclose(f);

	

	vector<vector<double>> Ylap1 = laplasianAlpha2(Y, 1, height, width, 0);
	f = fopen("laplasianImages/laplasianImageAlpha1,0.bmp", "wb");
	writeBMP(f, getRGBfromY(Ylap1, height, width), &bfh, &bih, height, width);
	fclose(f);

	vector<vector<double>> Ylap2 = laplasianAlpha2(Y, 1.1, height, width, 0);
	f = fopen("laplasianImages/laplasianImageAlpha1,1.bmp", "wb");
	writeBMP(f, getRGBfromY(Ylap2, height, width), &bfh, &bih, height, width);
	fclose(f);

	vector<vector<double>> Ylap3 = laplasianAlpha2(Y, 1.2, height, width, 0);
	f = fopen("laplasianImages/laplasianImageAlpha1,2.bmp", "wb");
	writeBMP(f, getRGBfromY(Ylap3, height, width), &bfh, &bih, height, width);
	fclose(f);

	vector<vector<double>> Ylap4 = laplasianAlpha2(Y, 1.3, height, width, 0);
	f = fopen("laplasianImages/laplasianImageAlpha1,3.bmp", "wb");
	writeBMP(f, getRGBfromY(Ylap4, height, width), &bfh, &bih, height, width);
	fclose(f);

	vector<vector<double>> Ylap5 = laplasianAlpha2(Y, 1.4, height, width, 0);
	f = fopen("laplasianImages/laplasianImageAlpha1,4.bmp", "wb");
	writeBMP(f, getRGBfromY(Ylap5, height, width), &bfh, &bih, height, width);
	fclose(f);

	vector<vector<double>> Ylap6 = laplasianAlpha2(Y, 1.5, height, width, 0);
	f = fopen("laplasianImages/laplasianImageAlpha1,5.bmp", "wb");
	writeBMP(f, getRGBfromY(Ylap6, height, width), &bfh, &bih, height, width);
	fclose(f);

	//f = fopen("laplasianImages/laplasiankk.bmp", "wb");
	//writeBMP(f, getRGBfromY(laplasian2(Y, 0, height, width), height, width), &bfh, &bih, height, width);
	//fclose(f);

	cout << "Alpha = 1.0: " << calculateAverageBright(Ylap1) << endl;
	cout << "Alpha = 1.1: " << calculateAverageBright(Ylap2) << endl;
	cout << "Alpha = 1.2: " << calculateAverageBright(Ylap3) << endl;
	cout << "Alpha = 1.3: " << calculateAverageBright(Ylap4) << endl;
	cout << "Alpha = 1.4: " << calculateAverageBright(Ylap5) << endl;
	cout << "Alpha = 1.5: " << calculateAverageBright(Ylap6) << endl;
	
	writeFile("laplasianImages/laplasianOriginal.txt", Y, height, width);
	writeFile("laplasianImages/laplasianAlpha1,0.txt", Ylap1, height, width);
	writeFile("laplasianImages/laplasianAlpha1,1.txt", Ylap2, height, width);
	writeFile("laplasianImages/laplasianAlpha1,2.txt", Ylap3, height, width);
	writeFile("laplasianImages/laplasianAlpha1,3.txt", Ylap4, height, width);
	writeFile("laplasianImages/laplasianAlpha1,4.txt", Ylap5, height, width);
	writeFile("laplasianImages/laplasianAlpha1,5.txt", Ylap6, height, width);
	
	//sobel
	f = fopen("sobelImages/sobel_isx.bmp", "wb");
	writeBMP(f, getRGBfromY(sobel(Y, 127, height, width), height, width), &bfh, &bih, height, width);
	fclose(f);

	f = fopen("sobelImages/sobel_30.bmp", "wb");
	writeBMP(f, getRGBfromY(sobel(Y, 30, height, width), height, width), &bfh, &bih, height, width);
	fclose(f);

	f = fopen("sobelImages/sobel_60.bmp", "wb");
	writeBMP(f, getRGBfromY(sobel(Y, 60, height, width), height, width), &bfh, &bih, height, width);
	fclose(f);

	f = fopen("sobelImages/sobel_90.bmp", "wb");
	writeBMP(f, getRGBfromY(sobel(Y, 90, height, width), height, width), &bfh, &bih, height, width);
	fclose(f);

	f = fopen("sobelImages/sobel_120.bmp", "wb");
	writeBMP(f, getRGBfromY(sobel(Y, 120, height, width), height, width), &bfh, &bih, height, width);
	fclose(f);

	f = fopen("sobelImages/sobel_150.bmp", "wb");
	writeBMP(f, getRGBfromY(sobel(Y, 150, height, width), height, width), &bfh, &bih, height, width);
	fclose(f);

	f = fopen("sobelImages/sobel_180.bmp", "wb");
	writeBMP(f, getRGBfromY(sobel(Y, 180, height, width), height, width), &bfh, &bih, height, width);
	fclose(f);

	f = fopen("sobelImages/sobel_map.bmp", "wb");
	vector<vector<Sobel>> sobel_data = sobel_param(Y, 120, height, width);
	MRGBQUAD** sob_map = gradient(sobel_data, height, width);
	writeBMP(f, sob_map, &bfh, &bih, height, width);
	fclose(f);
	*/
	return 0;
}