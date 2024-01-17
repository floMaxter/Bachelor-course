#include <iostream>
#include <fstream>
#include <locale.h>
#include <vector>
#include "bmp.h"
#include "AdditiveNoise.h"
#include "ImpulseNoise.h"
#include "AverageMethod.h"
#include "GaussianFilter.h"
#include "MedianFilteringMethod.h"
#include "LaplaceOperator.h"
#include "SobelOperator.h"
#include"AnchorPoints.h"
#include "GammaTransform.h"
#include "HistogramEqualization.h"
#include "GradationTransform.h"

using namespace std;

void get_YCbCr(YCbCr** ycbcr, RGB** rgb, int height, int width) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			ycbcr[i][j].Y = ((double)rgb[i][j].R * 0.299 + (double)rgb[i][j].G * 0.587 + (double)rgb[i][j].B * 0.114);
			ycbcr[i][j].Cb = (0.5643 * ((double)rgb[i][j].B - ycbcr[i][j].Y) + 128);
			ycbcr[i][j].Cr = 0.7132 * (((double)rgb[i][j].R - ycbcr[i][j].Y) + 128);
		}
	}	
}


int main() {
	setlocale(LC_ALL, "Russian");

	BITMAPFILEHEADER bfh;
	BITMAPINFOHEADER bih;
	FILE* f = fopen("Original.bmp", "rb");
	if (f == NULL) {
		return -1;
	}
	RGB** rgb = read_bmp(f, &bfh, &bih);
	fclose(f);
	int height = bih.biHeight;
	int width = bih.biWidth;

	YCbCr** ycbcr = new YCbCr * [height];
	for (int i = 0; i < height; i++) {
		ycbcr[i] = new YCbCr[width];
	}
	get_YCbCr(ycbcr, rgb, height, width);


	cout << "2.1.1 Реализация модели аддитивного шума" << endl;
	int sigma = 80;
	AdditiveNoise additive_noise(ycbcr, rgb, height, width, &bfh, &bih, sigma);
	additive_noise.get_image("2.1.1GaussianNoise.bmp");
	cout << "Успешно выполенено для sigma = " << sigma << endl << endl;



	cout << "2.1.2 Реализация модели импульсного шума" << endl;
	double p_a = 0.05;
	double p_b = 0.05;
	ImpulseNoise impulse_noise(ycbcr, rgb, height, width, &bfh, &bih, p_a, p_b);
	impulse_noise.get_image("2.1.2ImpulseNoise.bmp");
	cout << "Успешно выполенено для p_a = " << p_a << " и p_b = " << p_b << endl << endl;

	cout << "2.1.3 Построение графиков PSNR" << endl;
	cout << "Модель аддитивного шума:" << endl;
	additive_noise.PSNR_graph();
	cout << endl << "Модель импульсного шума:" << endl;
	impulse_noise.PSNR_graph();
	cout << endl;


	
	cout << "2.1.4.1 Метод скользящего среднего" << endl;
	int R = 1;
	int sigma2 = 30;
	AdditiveNoise additive_noise2(ycbcr, rgb, height, width, &bfh, &bih, sigma2);
	additive_noise2.get_image("2.1.4.1GaussianNoise.bmp");
	MovingAverageMethod average_method(ycbcr,additive_noise2.get_YCbCr(), height, width, &bfh, &bih, R);
	average_method.get_image("2.1.4.1AverageMethod.bmp");
	cout << "Успешно выполенено для R = " << R  << " и sigma = " << sigma2 << endl << endl;

	cout << "2.1.4.2 Подбор размера окна для метода скользящего среднего" << endl;
	vector<int> sigma_vector = { 1,10,30,50,80 };
	int R2 = 1;
	for (int i = 0; i < sigma_vector.size(); i++) {
		cout << "sigma = " << sigma_vector[i] << endl;
		AdditiveNoise a(ycbcr, rgb, height, width, &bfh, &bih, sigma_vector[i]);
		MovingAverageMethod average_method(ycbcr, a.get_YCbCr(), height, width, &bfh, &bih, R2);
		average_method.check_radius();
	}
	cout << endl;

	
	cout << "2.1.4.3 Фильтр Гаусса" << endl;
	int R3 = 1;
	double sigma_filter = 0.1;
	double sigma3 = 30;
	AdditiveNoise an(ycbcr, rgb, height, width, &bfh, &bih, sigma3);
	an.get_image("2.1.4.3GaussianNoise.bmp");
	GaussianFilter gaussian_method(rgb, an.get_YCbCr(), ycbcr, height, width, &bfh, &bih,R3 ,sigma3);
	gaussian_method.get_image("2.1.4.3GaussianMethod.bmp");
	cout << "Успешно выполенено для R = " << R3 << " и sigma = " << sigma_filter << endl << endl;


	
	cout << "2.1.4.5 Графики PSNR" << endl;
	GaussianFilter gf(rgb, ycbcr, height, width, &bfh, &bih);
	//ОЧЕНЬ МЕДЛЕННО 
	//gf.check_PSNR();
	cout << "Графики построены" << endl;
	cout << "plot 'R1sigmaNoise1.txt' w l, 'R1sigmaNoise10.txt' w l, 'R1sigmaNoise30.txt' w l, 'R1sigmaNoise50.txt' w l, 'R1sigmaNoise80.txt' w l" << endl;
	cout << "plot 'R3sigmaNoise1.txt' w l, 'R3sigmaNoise10.txt' w l, 'R3sigmaNoise30.txt' w l, 'R3sigmaNoise50.txt' w l, 'R3sigmaNoise80.txt' w l" << endl;
	cout << "plot 'R5sigmaNoise1.txt' w l, 'R5sigmaNoise10.txt' w l, 'R5sigmaNoise30.txt' w l, 'R5sigmaNoise50.txt' w l, 'R5sigmaNoise80.txt' w l" << endl;
	cout << endl;

	
	cout << "2.1.4.4 Максимальные значения PSNR" << endl;
	gf.find_max_PSNR();
	cout << endl;


	cout << "2.1.4.7 Метод медианной фильтрации" << endl;
	int R8 = 1;
	int sigma8 = 30;
	AdditiveNoise additive_noise4(ycbcr, rgb, height, width, &bfh, &bih, sigma8);
	additive_noise4.get_image("2.1.4.7GaussianNoise.bmp");
	MedianFilteringMethod median_method(ycbcr,additive_noise4.get_YCbCr(), height, width, &bfh, &bih, R8);
	median_method.get_image("2.1.4.7MedianMethod.bmp");
	cout << "Успешно выполенено для R = " << R8  << " и sigma = " << sigma8 << endl << endl;

	//ОЧЕНЬ МЕДЛЕННО РАБОТАЕТ
	cout << "2.1.4.8 Подбор размера окна для метода медианной фильтрации" << endl;
		vector<int> sigma_vector2 = { 1,10,30,50,80 };
		int R9 = 1;
		for (int i = 0; i < sigma_vector2.size(); i++) {
			cout << "sigma = " << sigma_vector2[i] << endl;
			AdditiveNoise a(ycbcr, rgb, height, width, &bfh, &bih, sigma_vector2[i]);
			MedianFilteringMethod median_method1(ycbcr, a.get_YCbCr(), height, width, &bfh, &bih, R9);
			median_method1.check_radius();
		}
		cout << endl;




	//МЕДЛЕННО
	cout << "2.1.4.9 Сравнение результатов при разных методах фильтрации" << endl;
	vector<int> sigma_vector9 = { 1,10,30,50,80 };
	vector<int> best_R_average = {1,1,2,3,5};
	vector<int> best_R_gaussian = {1,1,5,2,5};
	vector<int> best_R_median = {1,1,3,4,5};
	vector<double> best_sigma_filter_gaussian = {0.25, 0.75, 1.5, 2, 2};
	vector<double> PSNR_average;
	vector<double> PSNR_gaussian;
	vector<double> PSNR_median;
	ofstream file1;
	file1.open("2.1.4.10AdditiveNoise.txt");
	ofstream file2;
	file2.open("2.1.4.10AverageMethod.txt");
	ofstream file3;
	file3.open("2.1.4.10GaussianMethod.txt");
	ofstream file4;
	file4.open("2.1.4.10MedianMethod.txt");
	for (int i = 0; i < sigma_vector9.size(); i++) {
		cout << "sigma = " << sigma_vector9[i] << endl;
		AdditiveNoise a9(ycbcr, rgb, height, width, &bfh, &bih, sigma_vector9[i]);
		a9.get_image(("2.1.4.9.AdditiveNoise" + to_string(sigma_vector9[i]) + ".bmp").c_str());
		file1 << (int)sigma_vector9[i] << " " << (double)a9.PSNR() << endl;
		MovingAverageMethod am9(ycbcr, a9.get_YCbCr(), height, width, &bfh, &bih, best_R_average[i]);
		am9.get_image(("2.1.4.9.AverageMethod" + to_string(sigma_vector9[i]) + ".bmp").c_str());
		file2 << (int)sigma_vector9[i] << " " << (double)am9.PSNR() << endl;
		GaussianFilter gf9(rgb, a9.get_YCbCr(), ycbcr, height, width, &bfh, &bih, best_R_gaussian[i], best_sigma_filter_gaussian[i]);
		gf9.get_image(("2.1.4.9.GaussianMethod" + to_string(sigma_vector9[i]) + ".bmp").c_str());
		file3 << (int)sigma_vector9[i] << " " << (double)gf9.PSNR() << endl;
		MedianFilteringMethod mm9(ycbcr, a9.get_YCbCr(), height, width, &bfh, &bih, best_R_median[i]);
		mm9.get_image(("2.1.4.9.MedianMethod" + to_string(sigma_vector9[i]) + ".bmp").c_str());
		file4 << (int)sigma_vector9[i] << " " << (double)mm9.PSNR() << endl;
	}
	file1.close();
	file2.close();
	file3.close();
	file4.close();
	cout << "plot '2.1.4.10AdditiveNoise.txt' w l, '2.1.4.10AverageMethod.txt' w l, '2.1.4.10GaussianMethod.txt' w l, '2.1.4.10MedianMethod.txt' w l" << endl;
	cout << endl; 


	cout << "2.1.5.2 Вычисление значения PSNR" << endl;
	vector<double> p = { 0.025, 0.05, 0.125, 0.25 };
		for (int i = 0; i < p.size(); i++) {
			ImpulseNoise impulse_noise1(ycbcr, rgb, height, width, &bfh, &bih, p[i], p[i]);
			impulse_noise1.get_image(("2.1.5.1ImpulseNoise" + to_string(p[i]) + ".bmp").c_str());
			impulse_noise1.PSNR();
		}
		cout << endl;

	cout << "2.1.5.3 Метод медианной фильтрации для импульсного шума" << endl;
	vector<double> p3 = { 0.025, 0.05, 0.125, 0.25 };
	vector<double> R33 = {3};
	for (int i = 0; i < p3.size(); i++) {
		for (int j = 0; j < R33.size(); j++) {
			ImpulseNoise impulse_noise3(ycbcr, rgb, height, width, &bfh, &bih, p3[i], p3[i]);
			MedianFilteringMethod m3(ycbcr, impulse_noise3.get_YCbCr(), height, width, &bfh, &bih, R33[j]);
			m3.get_image(("2.1.5.3MedianMethod" + to_string(p3[i]) + ".bmp").c_str());
		}
	}
	cout << endl;

	cout << "2.1.5.3 График PSNR(R)" << endl;
	vector<double> p35 = { 0.025, 0.05, 0.125, 0.25 };
	vector<double> R35 = { 1,2,3,4};
	for (int i = 0; i < p35.size(); i++) {
		vector<double> res;
		for (int j = 0; j < R35.size(); j++) {
			ImpulseNoise impulse_noise5(ycbcr, rgb, height, width, &bfh, &bih, p35[i], p35[i]);
			MedianFilteringMethod m5(ycbcr, impulse_noise5.get_YCbCr(), height, width, &bfh, &bih, R35[j]);
			res.push_back(m5.PSNR());
		}
		ofstream file_PSNR_Median;
		file_PSNR_Median.open(("2.1.5.3MedianPSNR" + to_string(p35[i]) + ".txt").c_str());
		for (int k = 0; k < R35.size(); k++)
			file_PSNR_Median << R35[k] << " " << res[k] << endl;

	}
	cout << endl;
	cout << "plot '2.1.5.3MedianPSNR0,025000.txt' w l, '2.1.5.3MedianPSNR0,050000.txt' w l, '2.1.5.3MedianPSNR0,125000.txt' w l, '2.1.5.3MedianPSNR0,250000.txt' w l" << endl;

	





	//2.2

	cout << "2.2.1.1 Примение оператора Лапласа I_new = L(I) к изображению" << endl;
	LaplaceOperator lp1(ycbcr, height, width, &bfh, &bih);
	lp1.create_laplace_operator1(1,-4);
	lp1.get_operator_laplace_image("2.2\\2.2.1.1.LaplaceOperator1.bmp");
	lp1.get_image_response("2.2\\2.2.1.1.LaplaceOperatorImage1.bmp");

	cout << endl <<  "2.2.1.2 Формирование изображения по отклику" << endl;
	LaplaceOperator lp2(ycbcr, height, width, &bfh, &bih);
	lp2.create_laplace_operator1(-1, 4);
	lp2.get_operator_laplace_image("2.2\\2.2.1.1.LaplaceOperator2.bmp");
	lp2.get_image_response("2.2\\2.2.1.1.LaplaceOperatorImage2.bmp");

	cout << endl << "2.2.1.3 Усиление высоких частот" << endl;
	lp2.high_frequency("2.2\\2.2.1.3.LaplaceOperatorImage.bmp");



	cout << endl << "2.2.1.4-5 Изображения с маской с различными alpha" << endl;
	vector<double> alpha = { 1, 1.1, 1.2, 1.3, 1.4, 1.5 };
	for (int i = 0; i < alpha.size(); i++) {
		LaplaceOperator lp(ycbcr, height, width, &bfh, &bih);
		lp.create_high_frequency_alpha(alpha[i], ("2.2\\2.2.1.4.LaplaceOperatorImage" + to_string(alpha[i]) + ".bmp").c_str());
		cout << "alpha = " << alpha[i] << " Средняя яркость = " << lp.average_bright() << endl;
		lp.get_freq_new(("2.2\\2.2.1.7.LaplaceOperatorImage" + to_string(alpha[i]) + ".txt").c_str());
	}
	LaplaceOperator lp_original(ycbcr, height, width, &bfh, &bih);
	lp_original.get_freq_original("2.2\\2.2.1.7.LaplaceOperatorImage.txt");



	cout << "2.2.2.1 Применение оператора Собеля " << endl;
	SobelOperator sobel_original(ycbcr, height, width, &bfh, &bih);
	sobel_original.sobel_operator(127);
	sobel_original.get_image("2.2\\2.2.2.1.SobelOperator.bmp");
	
	cout << "2.2.2.4 Применение оператора Собеля с различными значениями thr" << endl;
	vector<int> thr = { 30, 60, 90, 120, 150, 180, 210};
	for (int i = 0; i < thr.size(); i++) {
		SobelOperator s(ycbcr, height, width, &bfh, &bih);
		s.sobel_operator(thr[i]);
		s.get_image(("2.2\\2.2.2.4.SobelOperatorImage" + to_string(thr[i]) + ".bmp").c_str());
	}

	cout << "2.2.2.5 Карта направлений градиентов" << endl;
	sobel_original.gradient("2.2\\2.2.2.5.SobelOperatorGradient.bmp");


	//2.3
	cout << "2.3.1 Метод опорных точек" << endl;
	AnchorPoints a_original(ycbcr, height, width, &bfh, &bih);
	a_original.get_freq_original("2.3\\2.3.1.3OriginalBefore.txt");
	a_original.anchor_points(65, 40, 180, 210);
	a_original.get_image("2.3\\2.3.1.2Original2Points.bmp");
	a_original.get_freq_new("2.3\\2.3.1.3OriginalAfter.txt");

	AnchorPoints ad(ycbcr, height, width, &bfh, &bih);
	ad.blackout(70);
	ad.get_image("2.3\\2.3.1.1DarkImage.bmp");
	ad.get_freq_new("2.3\\2.3.1.3DarkImageBefore.txt");
	ad.anchor_points(20,70,140,220);
	ad.get_image("2.3\\2.3.1.2DarkImage2Points.bmp");
	ad.get_freq_new("2.3\\2.3.1.3DarkImageAfter.txt");

	AnchorPoints al(ycbcr, height, width, &bfh, &bih);
	al.lightening(70);
	al.get_image("2.3\\2.3.1.1LightImage.bmp");
	al.get_freq_new("2.3\\2.3.1.3LightImageBefore.txt");
	al.anchor_points(120,20,210,180);
	al.get_image("2.3\\2.3.1.2LightImage2Points.bmp");
	al.get_freq_new("2.3\\2.3.1.3LightImageAfter.txt");


	cout << "2.3.2 Гамма преобразование" << endl;
	vector<double> gamma = { 0.1, 0.5, 1, 2, 8 };
	//original
	for (int i = 0; i < gamma.size(); i++) {
		GammaTransform g_original(ycbcr, height, width, &bfh, &bih);
		g_original.gamma_transform(1, gamma[i]);
		g_original.get_image(("2.3\\2.3.2.GammaTransformOriginal" + to_string(gamma[i]) + ".bmp").c_str());
		g_original.get_freq_new(("2.3\\2.3.3.GammaTransformOriginalAfter" + to_string(gamma[i]) + ".txt").c_str());
	}
	 
	//dark
	for (int i = 0; i < gamma.size(); i++) {
		GammaTransform g_dark(ycbcr, height, width, &bfh, &bih);
		g_dark.blackout(70);
		g_dark.gamma_transform(1, gamma[i]);
		g_dark.get_image(("2.3\\2.3.2.GammaTransformDark" + to_string(gamma[i]) + ".bmp").c_str());
		g_dark.get_freq_new(("2.3\\2.3.3.GammaTransformDarkAfter" + to_string(gamma[i]) + ".txt").c_str());
	}

	//light
	for (int i = 0; i < gamma.size(); i++) {
		GammaTransform g_light(ycbcr, height, width, &bfh, &bih);
		g_light.lightening(70);
		g_light.gamma_transform(1, gamma[i]);
		g_light.get_image(("2.3\\2.3.2.GammaTransformLight" + to_string(gamma[i]) + ".bmp").c_str());
		g_light.get_freq_new(("2.3\\2.3.3.GammaTransformLightAfter" + to_string(gamma[i]) + ".txt").c_str());
	}


	cout << "2.3.3 Метод выравнивания гистограмм" << endl;
	HistogramEqualization h_original(ycbcr, height, width, &bfh, &bih);
	h_original.histogram_equalization();
	h_original.get_image("2.3\\2.3.3.3HistogramOriginalAfter.bmp");
	h_original.get_freq_new("2.3\\2.3.3.3HistogramOriginalAfter.txt");

	HistogramEqualization h_dark(ycbcr, height, width, &bfh, &bih);
	h_dark.blackout(70);
	h_dark.histogram_equalization();
	h_dark.get_image("2.3\\2.3.3.3HistogramDarkAfter.bmp");
	h_dark.get_freq_new("2.3\\2.3.3.3HistogramDarkAfter.txt");

	HistogramEqualization h_light(ycbcr, height, width, &bfh, &bih);
	h_light.lightening(70);
	h_light.histogram_equalization();
	h_light.get_image("2.3\\2.3.3.3HistogramLightAfter.bmp");
	h_light.get_freq_new("2.3\\2.3.3.3HistogramLightAfter.txt");

	cout << "2.3.4 5.6 Методы построения карты контуров на основе градационных преобразований" << endl;
	vector<int> T = { 16, 48, 80, 112, 144, 176, 208, 240 };
	GradationTransform grad(ycbcr, height, width, &bfh, &bih);
	for (int i = 0; i < T.size(); i++) {
		grad.gradation_transform(T[i]);
		grad.get_image(("2.3\\2.3.4GradationTransform" + to_string(T[i]) + ".bmp").c_str());
	}


	return 0;
}