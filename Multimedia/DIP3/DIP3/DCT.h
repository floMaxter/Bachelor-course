#include <iostream>
#include <cmath>
#include <fstream>
#include "bmp.h"

const double Pi = 3.141592653589793;

class DCT {
private:
	int height;
	int width;
	int N = 8;
	YCbCr** ycbcr;
	YCbCr** new_ycbcr;
	YCbCr** reverse_ycbcr;
	RGB** rgb;
	RGB** new_rgb;
	BITMAPFILEHEADER* bfh;
	BITMAPINFOHEADER* bih;
	vector<double> Y_PSNR; 
	vector<double> Cb_PSNR; 
	vector<double> Cr_PSNR; 
public:
	DCT(RGB** color, YCbCr** y, int h, int w, BITMAPFILEHEADER* bf, BITMAPINFOHEADER* bi) {
		rgb = color;
		ycbcr = y;
		height = h;
		width = w;
		bfh = bf;
		bih = bi;

		new_ycbcr = new YCbCr*[height];
		for (int i = 0; i < height; i++)
			new_ycbcr[i] = new YCbCr[width];

		reverse_ycbcr = new YCbCr * [height];
		for (int i = 0; i < height; i++)
			reverse_ycbcr[i] = new YCbCr[width];

		new_rgb = new RGB * [height];
		for (int i = 0; i < height; i++)
			new_rgb[i] = new RGB[width];
	}
	~DCT() {
		for (int i = 0; i < height; i++) {
			delete(new_ycbcr[i]);
			delete(new_rgb[i]);
			delete(reverse_ycbcr[i]);
		}
		delete(new_ycbcr);
		delete(new_rgb);
		delete(reverse_ycbcr);
	}
	void get_image(const char* filename) {
		get_RGB();
		FILE* file;
		file = fopen(filename, "wb");
		write_bmp(file, new_rgb, bfh, bih, height, width);
		fclose(file);
	}

	double get_cos(int i, int k) {
		return cos(((2.0 * i + 1) * Pi * k) / (2 * (double)N));
	}

	void direct_DCT() {
		double Ck = 0;
		double Cl = 0;
		for (int h = 0; h < height; h += N) {
			for (int w = 0; w < width; w += N) {
				for (int k = 0; k < N; k++) {
					for (int l = 0; l < N; l++) {
						if (k == 0)
							Ck = (double)1.0 / N;
						else
							Ck = (double)2.0 / N;
						if (l == 0)
							Cl = (double)1.0 / N;
						else
							Cl = (double)2.0 / N;
						double sumY = 0;
						double sumCb = 0;
						double sumCr = 0;
						for (int i = 0; i < N; i++) {
							for (int j = 0; j < N; j++) {
								sumY += ycbcr[i+h][j+w].Y * get_cos(i, k) * get_cos(j, l);
								sumCb += ycbcr[i+h][j+w].Cb * get_cos(i, k) * get_cos(j, l);
								sumCr += ycbcr[i+h][j+w].Cr * get_cos(i, k) * get_cos(j, l);
							}
						}
						new_ycbcr[h + k][w + l].Y = round(sqrt(Ck) * sqrt(Cl) * sumY);
						new_ycbcr[h + k][w + l].Cb = round(sqrt(Ck) * sqrt(Cl) * sumCb);
						new_ycbcr[h + k][w + l].Cr = round(sqrt(Ck) * sqrt(Cl) * sumCr);
					}
				}
			}
		}
	}

	YCbCr** get_DCT() {
		return new_ycbcr;
	}

	void set_new_YCbCr(YCbCr** n) {
		new_ycbcr = n;
	}

	void set_reverse_YCbCr(YCbCr** n) {
		reverse_ycbcr = n;
	}

	void IDCT() {
		double Ck = 0;
		double Cl = 0;
		for (int h = 0; h < height; h += N) {
			for (int w = 0; w < width; w += N) {
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < N; j++) {
						double sumY = 0;
						double sumCb = 0;
						double sumCr = 0;
						for (int k = 0; k < N; k++) {
							for (int l = 0; l < N; l++) {
								if (k == 0)
									Ck = (double)1 / N;
								else
									Ck = (double)2 / N;
								if (l == 0)
									Cl = (double)1 / N;
								else
									Cl = (double)2 / N;
								sumY += sqrt(Ck) * sqrt(Cl) * new_ycbcr[k + h][l + w].Y * get_cos(i,k) * get_cos(j,l);
								sumCb += sqrt(Ck) * sqrt(Cl) * new_ycbcr[k + h][l + w].Cb * get_cos(i,k) * get_cos(j,l);
								sumCr += sqrt(Ck) * sqrt(Cl) * new_ycbcr[k + h][l + w].Cr * get_cos(i,k) * get_cos(j,l);
							}
						}
						reverse_ycbcr[h+i][w+j].Y = round(sumY);
						reverse_ycbcr[h+i][w+j].Cb = round(sumCb);
						reverse_ycbcr[h+i][w+j].Cr = round(sumCr);
					}
				}
			}
		}
	}

	void get_PSNR(bool isWriten) {
		PSNR("Y", isWriten);
		PSNR("Cb", isWriten);
		PSNR("Cr", isWriten);
	}

	void get_PSNR_graphic(int R, bool isWriten) {
		Y_PSNR.push_back(PSNR("Y", isWriten));
		Cb_PSNR.push_back(PSNR("Cb", isWriten));
		Cr_PSNR.push_back(PSNR("Cr", isWriten));
	}

	void write_PSNR_file(string image_name, vector<int> R) {
		ofstream Y_file;
		Y_file.open(image_name + "Y.txt");
		ofstream Cb_file;
		Cb_file.open(image_name + "Cb.txt");
		ofstream Cr_file;
		Cr_file.open(image_name + "Cr.txt");
		for (int i = 0; i < R.size(); i++) {
			Y_file << R[i] << " " << Y_PSNR[i] << endl;
			Cb_file << R[i] << " " << Cb_PSNR[i] << endl;
			Cr_file << R[i] << " " << Cr_PSNR[i] << endl;
		}
		Y_file.close();
		Cb_file.close();
		Cr_file.close();
	}

	double PSNR(string component, bool isWriten) {
		double tmp = width * height * pow(256 - 1, 2);
		double PSNR = 0;
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (component == "Y") {
					PSNR += pow((ycbcr[i][j].Y - reverse_ycbcr[i][j].Y), 2);
					continue;
				}
				if (component == "Cb") {
					PSNR += pow((ycbcr[i][j].Cb - reverse_ycbcr[i][j].Cb), 2);
					continue;
				}
				if (component == "Cr") {
					PSNR += pow((ycbcr[i][j].Cr - reverse_ycbcr[i][j].Cr), 2);
					continue;
				}
			}
		}
		PSNR = 10 * log10(tmp / PSNR);
		if (isWriten)
		 cout << "PSNR " << component << " = " << PSNR << endl;
		return PSNR;
	}
	void get_RGB() {
		for (int i = 0; i < height; i++) {
			double tmp = 0;
			for (int j = 0; j < width; j++) {
				tmp = (reverse_ycbcr[i][j].Y - 0.714 * (reverse_ycbcr[i][j].Cr - 128) - 0.334 * (reverse_ycbcr[i][j].Cb - 128));
				new_rgb[i][j].G = clipping(tmp);
				tmp = reverse_ycbcr[i][j].Y + 1.402 * (reverse_ycbcr[i][j].Cr - 128);
				new_rgb[i][j].R = clipping(tmp);
				tmp = reverse_ycbcr[i][j].Y + 1.772 * (reverse_ycbcr[i][j].Cb - 128);
				new_rgb[i][j].B = clipping(tmp);
			}
		}
	}

	
	unsigned char clipping(double x) {
		unsigned char res;
		if (x > 255) {
			res = 255;
			return res;
		}
		else if (x < 0) {
			res = 0;
			return res;
		}
		return static_cast<unsigned char>(round(x));
	}

	void get_YCbCr() {
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				ycbcr[i][j].Y = clipping(((double)rgb[i][j].R * 0.299 + (double)rgb[i][j].G * 0.587 + (double)rgb[i][j].B * 0.114));
				ycbcr[i][j].Cb = clipping(0.5643 * ((double)rgb[i][j].B - ycbcr[i][j].Y) + 128);
				ycbcr[i][j].Cr = clipping(0.7132 * ((double)rgb[i][j].R - ycbcr[i][j].Y) + 128);
			}
		}
	}

};
