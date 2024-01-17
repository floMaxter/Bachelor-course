#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "bmp.h"
#include "DCT.h"
#include "Quantization.h"
#include "Сompression.h"


using namespace std;

void read_PNSR_form_file(vector<double>* PSNR, string filename) {
	ifstream in;
	in.open(filename);
	double R;
	double psnr;
	while (in >> R >> psnr) {
		PSNR->push_back(psnr);
	}
	in.close();
}

void write_PSNR_to_file(vector<double> compress, vector<double> PSNR, string filename) {
	ofstream f;
	f.open(filename);
	for (int i = 0; i < compress.size(); i++) {
		f << compress[i] << " " << PSNR[i] << endl;
	}
	f.close();
}


int main() {
	setlocale(LC_ALL, "Russian");

	//открытие и чтение всех файлов
	BITMAPFILEHEADER bfh_lena;
	BITMAPINFOHEADER bih_lena;
	FILE* f_lena = fopen("lena.bmp", "rb");
	if (f_lena == NULL) {
		return -1;
	}
	RGB** rgb_lena = read_bmp(f_lena, &bfh_lena, &bih_lena);
	fclose(f_lena);
	int height_lena = bih_lena.biHeight;
	int width_lena = bih_lena.biWidth;

	YCbCr** ycbcr_lena = new YCbCr * [height_lena];
	for (int i = 0; i < height_lena; i++) {
		ycbcr_lena[i] = new YCbCr[width_lena];
	}



	BITMAPFILEHEADER bfh_baboon;
	BITMAPINFOHEADER bih_baboon;
	FILE* f_baboon = fopen("baboon.bmp", "rb");
	if (f_baboon == NULL) {
		return -2;
	}
	RGB** rgb_baboon = read_bmp(f_baboon, &bfh_baboon, &bih_baboon);
	fclose(f_baboon);
	int height_baboon = bih_baboon.biHeight;
	int width_baboon = bih_baboon.biWidth;

	YCbCr** ycbcr_baboon = new YCbCr * [height_baboon];
	for (int i = 0; i < height_baboon; i++) {
		ycbcr_baboon[i] = new YCbCr[width_baboon];
	}

	BITMAPFILEHEADER bfh_original;
	BITMAPINFOHEADER bih_original;
	FILE* f_original = fopen("Original.bmp", "rb");
	if (f_original == NULL) {
		return -1;
	}
	RGB** rgb_original = read_bmp(f_original, &bfh_original, &bih_original);
	fclose(f_original);
	int height_original = bih_original.biHeight;
	int width_original = bih_original.biWidth;

	YCbCr** ycbcr_original = new YCbCr * [height_original];
	for (int i = 0; i < height_original; i++) {
		ycbcr_original[i] = new YCbCr[width_original];
	}

	////DCT and IDCT
	cout << endl << "Прямое и обратное ДКП" << endl;

	cout << "Lena" << endl;
	DCT DCT_lena(rgb_lena, ycbcr_lena, height_lena, width_lena, &bfh_lena, &bih_lena);
	DCT_lena.get_YCbCr();
	DCT_lena.direct_DCT();
	DCT_lena.IDCT();
	DCT_lena.get_image("LenaAfter.bmp");
	DCT_lena.get_PSNR(true);

	cout << "Baboon" << endl;
	DCT DCT_baboon(rgb_baboon, ycbcr_baboon, height_baboon, width_baboon, &bfh_baboon, &bih_baboon);
	DCT_baboon.get_YCbCr();
	DCT_baboon.direct_DCT();
	DCT_baboon.IDCT();
	DCT_baboon.get_image("BaboonAfter.bmp");
	DCT_baboon.get_PSNR(true);

	cout << "Original" << endl;
	DCT DCT_original(rgb_original, ycbcr_original, height_original, width_original, &bfh_original, &bih_original);
	DCT_original.get_YCbCr();
	DCT_original.direct_DCT();
	DCT_original.IDCT();
	DCT_original.get_image("OriginalAfter.bmp");
	DCT_original.get_PSNR(true);


	//// квантование и деквантование с графиками PSNR
	cout << endl << "Квантования и деквантование с графиком PSNR" << endl;
	cout << "Lena" << endl;
	vector<int> R = { 0,1,2,3,4,5,6,7,8,9,10 };
	Quantization quantization_lena(DCT_lena.get_DCT(), height_lena, width_lena, &bfh_lena, &bih_lena);
	for (int i = 0; i < R.size(); i++) {
		cout << endl << "R = " << R[i] << endl;
		if (R[i] != 0) {
			quantization_lena.quantization(R[i]);
			quantization_lena.dequantization(R[i]);
			DCT_lena.set_new_YCbCr(quantization_lena.get_dequantization());
		}
		DCT_lena.IDCT();
		DCT_lena.get_PSNR_graphic(R[i], false);
		if (R[i] == 1 || R[i] == 5 || R[i] == 10) {
			DCT_lena.get_image(("2//Lena" + to_string(R[i]) + ".bmp").c_str());
		}
	}
	DCT_lena.write_PSNR_file("2//Lena", R);
	cout << "plot 'LenaY.txt' w l, 'LenaCb.txt' w l, 'LenaCr.txt' w l" << endl;

	cout << "Baboon" << endl;
	vector<int> R_baboon = { 0,1,2,3,4,5,6,7,8,9,10 };
	Quantization quantization_baboon(DCT_baboon.get_DCT(), height_baboon, width_baboon, &bfh_baboon, &bih_baboon);
	for (int i = 0; i < R_baboon.size(); i++) {
		cout << endl << "R = " << R_baboon[i] << endl;
		if (R_baboon[i] != 0) {
			quantization_baboon.quantization(R_baboon[i]);
			quantization_baboon.dequantization(R_baboon[i]);
			DCT_baboon.set_new_YCbCr(quantization_baboon.get_dequantization());
		}
		DCT_baboon.IDCT();
		DCT_baboon.get_PSNR_graphic(R_baboon[i], false);
		if (R_baboon[i] == 1 || R_baboon[i] == 5 || R_baboon[i] == 10) {
			DCT_baboon.get_image(("2//Baboon" + to_string(R_baboon[i]) + ".bmp").c_str());
		}
	}
	DCT_baboon.write_PSNR_file("2//Baboon", R_baboon);
	cout << "plot 'BaboonY.txt' w l, 'BaboonCb.txt' w l, 'BaboonCr.txt' w l" << endl;


	cout << "Original" << endl;
	vector<int> R_original = { 0,1,2,3,4,5,6,7,8,9,10 };
	Quantization quantization_original(DCT_original.get_DCT(), height_original, width_original, &bfh_original, &bih_original);
	for (int i = 0; i < R_original.size(); i++) {
		cout << endl << "R = " << R_original[i] << endl;
		if (R_original[i] != 0) {
			quantization_original.quantization(R_original[i]);
			quantization_original.dequantization(R_original[i]);
			DCT_original.set_new_YCbCr(quantization_original.get_dequantization());
		}
		DCT_original.IDCT();
		DCT_original.get_PSNR_graphic(R_original[i], false);
		if (R_original[i] == 1 || R_original[i] == 5 || R_original[i] == 10) {
			DCT_original.get_image(("2//Original" + to_string(R_original[i]) + ".bmp").c_str());
		}
	}
	DCT_original.write_PSNR_file("2//Original", R_original);
	cout << "plot 'OriginalY.txt' w l, 'OriginalCb.txt' w l, 'OriginalCr.txt' w l" << endl;


	// кодирование ДС
	cout << endl << "Кодирование квантованных коэффициентов постоянного тока DC" << endl;
	cout << "Lena" << endl;
	Quantization quantization_lena2(DCT_lena.get_DCT(), height_lena, width_lena, &bfh_lena, &bih_lena);
	quantization_lena2.quantization(1);
	Compression compression_lena(quantization_lena2.get_quantization(), height_lena, width_lena, &bfh_lena, &bih_lena);
	compression_lena.create_DC();
	compression_lena.coding_DC();

	compression_lena.get_histogram_dc("3//LenaDcY.txt", "Y");
	compression_lena.get_histogram_dc("3//LenaDcCb.txt", "Cb");
	compression_lena.get_histogram_dc("3//LenaDcCr.txt", "Cr");

	compression_lena.get_histogram_code_dc("3//LenaCodeDcY.txt", "Y");
	compression_lena.get_histogram_code_dc("3//LenaCodeDcCb.txt", "Cb");
	compression_lena.get_histogram_code_dc("3//LenaCodeDcCr.txt", "Cr");

	compression_lena.entropy();


	cout << "Baboon" << endl;
	Quantization quantization_baboon2(DCT_baboon.get_DCT(), height_baboon, width_baboon, &bfh_baboon, &bih_baboon);
	quantization_baboon2.quantization(1);
	Compression compression_baboon(quantization_baboon2.get_quantization(), height_baboon, width_baboon, &bfh_baboon, &bih_baboon);
	compression_baboon.create_DC();
	compression_baboon.coding_DC();

	compression_baboon.get_histogram_dc("3//BaboonDcY.txt", "Y");
	compression_baboon.get_histogram_dc("3//BaboonDcCb.txt", "Cb");
	compression_baboon.get_histogram_dc("3//BaboonDcCr.txt", "Cr");

	compression_baboon.get_histogram_code_dc("3//BaboonCodeDcY.txt", "Y");
	compression_baboon.get_histogram_code_dc("3//BaboonCodeDcCb.txt", "Cb");
	compression_baboon.get_histogram_code_dc("3//BaboonCodeDcCr.txt", "Cr");

	compression_baboon.entropy();

	
	cout << "Original" << endl;
	Quantization quantization_original2(DCT_original.get_DCT(), height_original, width_original, &bfh_original, &bih_original);
	quantization_original2.quantization(1);
	Compression compression_original(quantization_original2.get_quantization(), height_original, width_original, &bfh_original, &bih_original);
	compression_original.create_DC();
	compression_original.coding_DC();

	compression_original.get_histogram_dc("3//OriginalDcY.txt", "Y");
	compression_original.get_histogram_dc("3//OriginalDcCb.txt", "Cb");
	compression_original.get_histogram_dc("3//OriginalDcCr.txt", "Cr");

	compression_original.get_histogram_code_dc("3//OriginalCodeDcY.txt", "Y");
	compression_original.get_histogram_code_dc("3//OriginalCodeDcCb.txt", "Cb");
	compression_original.get_histogram_code_dc("3//OriginalCodeDcCr.txt", "Cr");

	compression_original.entropy();


	// Кодирование AC, оценка сжатого потока и PSNR
	vector<int> R3 = { 1,10 };
	DCT DCT_lena3(rgb_lena, ycbcr_lena, height_lena, width_lena, &bfh_lena, &bih_lena);
	DCT_lena3.get_YCbCr();
	DCT_lena3.direct_DCT();
	cout << "Lena" << endl;
	cout << endl << R3[0] << endl;
	Quantization quantization_lena3(DCT_lena3.get_DCT(), height_lena, width_lena, &bfh_lena, &bih_lena);
	quantization_lena3.quantization(R3[0]);
	Compression compression_lena3(quantization_lena3.get_quantization(), height_lena, width_lena, &bfh_lena, &bih_lena);
	compression_lena3.create_DC();
	compression_lena3.coding_DC();

	cout << "Y" << endl;
	compression_lena3.create_AC("Y");
	compression_lena3.coding_AC("Y");
	compression_lena3.stream_size("Y");

	cout << "Cb" << endl;
	compression_lena3.create_AC("Cb");
	compression_lena3.coding_AC("Cb");
	compression_lena3.stream_size("Cb");

	cout << "Cr" << endl;
	compression_lena3.create_AC("Cr");
	compression_lena3.coding_AC("Cr");
	compression_lena3.stream_size("Cr");

	cout << endl << R3[1] << endl;
	DCT DCT_lena4(rgb_lena, ycbcr_lena, height_lena, width_lena, &bfh_lena, &bih_lena);
	DCT_lena4.get_YCbCr();
	DCT_lena4.direct_DCT();
	Quantization quantization_lena4(DCT_lena4.get_DCT(), height_lena, width_lena, &bfh_lena, &bih_lena);
	quantization_lena4.quantization(R3[1]);
	Compression compression_lena4(quantization_lena4.get_quantization(), height_lena, width_lena, &bfh_lena, &bih_lena);
	compression_lena4.create_DC();
	compression_lena4.coding_DC();

	cout << "Y" << endl;
	compression_lena4.create_AC("Y");
	compression_lena4.coding_AC("Y");
	compression_lena4.stream_size("Y");

	cout << "Cb" << endl;
	compression_lena4.create_AC("Cb");
	compression_lena4.coding_AC("Cb");
	compression_lena4.stream_size("Cb");

	cout << "Cr" << endl;
	compression_lena4.create_AC("Cr");
	compression_lena4.coding_AC("Cr");
	compression_lena4.stream_size("Cr");

	cout << "Baboon" << endl;
	DCT DCT_baboon3(rgb_baboon, ycbcr_baboon, height_baboon, width_baboon, &bfh_baboon, &bih_baboon);
	DCT_baboon3.get_YCbCr();
	DCT_baboon3.direct_DCT();
	cout << endl << R3[0] << endl;
	Quantization quantization_baboon3(DCT_baboon3.get_DCT(), height_baboon, width_baboon, &bfh_baboon, &bih_baboon);
	quantization_baboon3.quantization(R3[0]);
	Compression compression_baboon3(quantization_baboon3.get_quantization(), height_baboon, width_baboon, &bfh_baboon, &bih_baboon);
	compression_baboon3.create_DC();
	compression_baboon3.coding_DC();

	cout << "Y" << endl;
	compression_baboon3.create_AC("Y");
	compression_baboon3.coding_AC("Y");
	compression_baboon3.stream_size("Y");

	cout << "Cb" << endl;
	compression_baboon3.create_AC("Cb");
	compression_baboon3.coding_AC("Cb");
	compression_baboon3.stream_size("Cb");

	cout << "Cr" << endl;
	compression_baboon3.create_AC("Cr");
	compression_baboon3.coding_AC("Cr");
	compression_baboon3.stream_size("Cr");

	cout << endl << R3[1] << endl;
	DCT DCT_baboon4(rgb_baboon, ycbcr_baboon, height_baboon, width_baboon, &bfh_baboon, &bih_baboon);
	DCT_baboon4.get_YCbCr();
	DCT_baboon4.direct_DCT();
	Quantization quantization_baboon4(DCT_baboon4.get_DCT(), height_baboon, width_baboon, &bfh_baboon, &bih_baboon);
	quantization_baboon4.quantization(R3[1]);
	Compression compression_baboon4(quantization_baboon4.get_quantization(), height_baboon, width_baboon, &bfh_baboon, &bih_baboon);
	compression_baboon4.create_DC();
	compression_baboon4.coding_DC();

	cout << "Y" << endl;
	compression_baboon4.create_AC("Y");
	compression_baboon4.coding_AC("Y");
	compression_baboon4.stream_size("Y");

	cout << "Cb" << endl;
	compression_baboon4.create_AC("Cb");
	compression_baboon4.coding_AC("Cb");
	compression_baboon4.stream_size("Cb");

	cout << "Cr" << endl;
	compression_baboon4.create_AC("Cr");
	compression_baboon4.coding_AC("Cr");
	compression_baboon4.stream_size("Cr");


	cout << "Original" << endl;
	DCT DCT_original3(rgb_original, ycbcr_original, height_original, width_original, &bfh_original, &bih_original);
	DCT_original3.get_YCbCr();
	DCT_original3.direct_DCT();
	cout << endl << R3[0] << endl;
	Quantization quantization_original3(DCT_original3.get_DCT(), height_original, width_original, &bfh_original, &bih_original);
	quantization_original3.quantization(R3[0]);
	Compression compression_original3(quantization_original3.get_quantization(), height_original, width_original, &bfh_original, &bih_original);
	compression_original3.create_DC();
	compression_original3.coding_DC();


	cout << "Y" << endl;
	compression_original3.create_AC("Y");
	compression_original3.coding_AC("Y");
	compression_original3.stream_size("Y");

	cout << "Cb" << endl;
	compression_original3.create_AC("Cb");
	compression_original3.coding_AC("Cb");
	compression_original3.stream_size("Cb");

	cout << "Cr" << endl;
	compression_original3.create_AC("Cr");
	compression_original3.coding_AC("Cr");
	compression_original3.stream_size("Cr");

	cout << endl << R3[1] << endl;
	DCT DCT_original4(rgb_original, ycbcr_original, height_original, width_original, &bfh_original, &bih_original);
	DCT_original4.get_YCbCr();
	DCT_original4.direct_DCT();
	Quantization quantization_original4(DCT_original4.get_DCT(), height_original, width_original, &bfh_original, &bih_original);
	quantization_original4.quantization(R3[1]);
	Compression compression_original4(quantization_original4.get_quantization(), height_original, width_original, &bfh_original, &bih_original);
	compression_original4.create_DC();
	compression_original4.coding_DC();

	cout << "Y" << endl;
	compression_original4.create_AC("Y");
	compression_original4.coding_AC("Y");
	compression_original4.stream_size("Y");

	cout << "Cb" << endl;
	compression_original4.create_AC("Cb");
	compression_original4.coding_AC("Cb");
	compression_original4.stream_size("Cb");

	cout << "Cr" << endl;
	compression_original4.create_AC("Cr");
	compression_original4.coding_AC("Cr");
	compression_original4.stream_size("Cr");


	//PSNR(степени сжатия)
	cout << endl << "График PSNR(степень сжатия)" << endl;
	vector<int> R_vector = { 0,1,2,3,4,5,6,7,8,9,10 };

	cout << "Lena" << endl; 
	DCT DCT_lena_PSNR(rgb_lena, ycbcr_lena, height_lena, width_lena, &bfh_lena, &bih_lena);
	DCT_lena_PSNR.get_YCbCr();
	DCT_lena_PSNR.direct_DCT();
	Quantization quantization_lena_PSNR(DCT_lena_PSNR.get_DCT(), height_lena, width_lena, &bfh_lena, &bih_lena);
	vector<double> compress_Y_lena;
	vector<double> compress_Cb_lena;
	vector<double> compress_Cr_lena;
	for (int i = 0; i < R_vector.size(); i++) {
		cout << endl << "R = " << i << endl;
		quantization_lena_PSNR.quantization(i);
		Compression compression_lena_PSNR(quantization_lena_PSNR.get_quantization(), height_lena, width_lena, &bfh_lena, &bih_lena);
		compression_lena_PSNR.create_DC();
		compression_lena_PSNR.coding_DC();
		compression_lena_PSNR.create_AC("Y");
		compression_lena_PSNR.coding_AC("Y");
		compress_Y_lena.push_back(compression_lena_PSNR.stream_size2("Y"));
		compression_lena_PSNR.create_AC("Cb");
		compression_lena_PSNR.coding_AC("Cb");
		compress_Cb_lena.push_back(compression_lena_PSNR.stream_size2("Cb"));
		compression_lena_PSNR.create_AC("Cr");
		compression_lena_PSNR.coding_AC("Cr");
		compress_Cr_lena.push_back(compression_lena_PSNR.stream_size2("Cr"));
	}
	vector<double> PSNR_lena_Y;
	vector<double> PSNR_lena_Cb;
	vector<double> PSNR_lena_Cr;
	read_PNSR_form_file(&PSNR_lena_Y, "2\\LenaY.txt");
	write_PSNR_to_file(compress_Y_lena, PSNR_lena_Y, "33//LenaY.txt");
	read_PNSR_form_file(&PSNR_lena_Cb, "2\\LenaCb.txt");
	write_PSNR_to_file(compress_Cb_lena, PSNR_lena_Cb, "33\\LenaCb.txt");
	read_PNSR_form_file(&PSNR_lena_Cr, "2\\LenaCr.txt");
	write_PSNR_to_file(compress_Cr_lena, PSNR_lena_Cr, "33\\LenaCr.txt");
	cout << "plot 'LenaY.txt' w l, 'LenaCb.txt' w l, 'LenaCr.txt' w l" << endl;


	cout << "Baboon" << endl;
	DCT DCT_baboon_PSNR(rgb_lena, ycbcr_lena, height_lena, width_lena, &bfh_lena, &bih_lena);
	DCT_baboon_PSNR.get_YCbCr();
	DCT_baboon_PSNR.direct_DCT();
	Quantization quantization_baboon_PSNR(DCT_baboon.get_DCT(), height_baboon, width_baboon, &bfh_baboon, &bih_baboon);
	vector<double> compress_Y_baboon;
	vector<double> compress_Cb_baboon;
	vector<double> compress_Cr_baboon;
	for (int i = 0; i < R_vector.size(); i++) {
		cout << endl << "R = " << i << endl;
		quantization_baboon_PSNR.quantization(i);
		Compression compression_baboon_PSNR(quantization_baboon_PSNR.get_quantization(), height_baboon, width_baboon, &bfh_baboon, &bih_baboon);
		compression_baboon_PSNR.create_DC();
		compression_baboon_PSNR.coding_DC();
		compression_baboon_PSNR.create_AC("Y");
		compression_baboon_PSNR.coding_AC("Y");
		compress_Y_baboon.push_back(compression_baboon_PSNR.stream_size2("Y"));
		compression_baboon_PSNR.create_AC("Cb");
		compression_baboon_PSNR.coding_AC("Cb");
		compress_Cb_baboon.push_back(compression_baboon_PSNR.stream_size2("Cb"));
		compression_baboon_PSNR.create_AC("Cr");
		compression_baboon_PSNR.coding_AC("Cr");
		compress_Cr_baboon.push_back(compression_baboon_PSNR.stream_size2("Cr"));
	}
	vector<double> PSNR_baboon_Y;
	vector<double> PSNR_baboon_Cb;
	vector<double> PSNR_baboon_Cr;
	read_PNSR_form_file(&PSNR_baboon_Y, "2\\BaboonY.txt");
	write_PSNR_to_file(compress_Y_baboon, PSNR_baboon_Y, "33//BaboonY.txt");
	read_PNSR_form_file(&PSNR_baboon_Cb, "2\\BaboonCb.txt");
	write_PSNR_to_file(compress_Cb_baboon, PSNR_baboon_Cb, "33\\BaboonCb.txt");
	read_PNSR_form_file(&PSNR_baboon_Cr, "2\\BaboonCr.txt");
	write_PSNR_to_file(compress_Cr_baboon, PSNR_baboon_Cr, "33\\BaboonCr.txt");
	cout << "plot 'BaboonY.txt' w l, 'BaboonCb.txt' w l, 'BaboonCr.txt' w l" << endl;


	cout << "Original" << endl;
	DCT DCT_original_PSNR(rgb_lena, ycbcr_lena, height_lena, width_lena, &bfh_lena, &bih_lena);
	DCT_original_PSNR.get_YCbCr();
	DCT_original_PSNR.direct_DCT();
	Quantization quantization_original_PSNR(DCT_original.get_DCT(), height_original, width_original, &bfh_original, &bih_original);
	vector<double> compress_Y_original;
	vector<double> compress_Cb_original;
	vector<double> compress_Cr_original;
	for (int i = 0; i < R_vector.size(); i++) {
		cout << endl << "R = " << i << endl;
		quantization_original_PSNR.quantization(i);
		Compression compression_original_PSNR(quantization_original_PSNR.get_quantization(), height_original, width_original, &bfh_baboon, &bih_original);
		compression_original_PSNR.create_DC();
		compression_original_PSNR.coding_DC();
		compression_original_PSNR.create_AC("Y");
		compression_original_PSNR.coding_AC("Y");
		compress_Y_original.push_back(compression_original_PSNR.stream_size2("Y"));
		compression_original_PSNR.create_AC("Cb");
		compression_original_PSNR.coding_AC("Cb");
		compress_Cb_original.push_back(compression_original_PSNR.stream_size2("Cb"));
		compression_original_PSNR.create_AC("Cr");
		compression_original_PSNR.coding_AC("Cr");
		compress_Cr_original.push_back(compression_original_PSNR.stream_size2("Cr"));
	}
	vector<double> PSNR_original_Y;
	vector<double> PSNR_original_Cb;
	vector<double> PSNR_original_Cr;
	read_PNSR_form_file(&PSNR_original_Y, "2\\OriginalY.txt");
	write_PSNR_to_file(compress_Y_original, PSNR_original_Y, "33//OriginalY.txt");
	read_PNSR_form_file(&PSNR_original_Cb, "2\\OriginalCb.txt");
	write_PSNR_to_file(compress_Cb_original, PSNR_original_Cb, "33\\OriginalCb.txt");
	read_PNSR_form_file(&PSNR_original_Cr, "2\\OriginalCr.txt");
	write_PSNR_to_file(compress_Cr_original, PSNR_original_Cr, "33\\OriginalCr.txt");
	cout << "plot 'OriginalY.txt' w l, 'OriginalCb.txt' w l, 'OriginalCr.txt' w l" << endl;

	//Dop
	
	cout << "Dop Lena" << endl;
	ofstream file_dop_run;
	ofstream file_dop_mg;
	file_dop_run.open("dop\\LenaRunDop.txt");
	file_dop_mg.open("dop\\LenaMgDop.txt");
	for (int i = 1; i <= 60; i+=3) {
		//cout << "R = " << i << endl;
		Quantization quantization_lena_dop(DCT_lena.get_DCT(), height_lena, width_lena, &bfh_lena, &bih_lena);
		quantization_lena_dop.quantization(i);
		Compression compression_lena_dop(quantization_lena_dop.get_quantization(), height_lena, width_lena, &bfh_lena, &bih_lena);
		compression_lena_dop.create_DC();
		compression_lena_dop.coding_DC();
		compression_lena_dop.create_AC("Y");
		compression_lena_dop.coding_AC("Y");
		double Run = compression_lena_dop.stream_size3("Y", 1);
		double Mg = compression_lena_dop.stream_size3("Y", 2);
		file_dop_run << i << " " << Run << endl;
		file_dop_mg << i << " " << Mg << endl;
	}
	file_dop_run.close();
	file_dop_mg.close();


	cout << "Dop baboon" << endl;
	ofstream file_dop_run2;
	ofstream file_dop_mg2;
	file_dop_run2.open("dop\\BaboonRunDop.txt");
	file_dop_mg2.open("dop\\BaboonMgDop.txt");
	for (int i = 1; i <= 60; i +=3) {
		//cout << "R = " << i << endl;
		Quantization quantization_baboon_dop(DCT_baboon.get_DCT(), height_baboon, width_baboon, &bfh_baboon, &bih_baboon);
		quantization_baboon_dop.quantization(i);
		Compression compression_baboon_dop(quantization_baboon_dop.get_quantization(), height_baboon, width_baboon, &bfh_baboon, &bih_baboon);
		compression_baboon_dop.create_DC();
		compression_baboon_dop.coding_DC();
		compression_baboon_dop.create_AC("Y");
		compression_baboon_dop.coding_AC("Y");
		double Run = compression_baboon_dop.stream_size3("Y", 1);
		double Mg = compression_baboon_dop.stream_size3("Y", 2);
		file_dop_run2 << i << " " << Run << endl;
		file_dop_mg2 << i << " " << Mg << endl;
	}
	file_dop_run2.close();
	file_dop_mg2.close();


	cout << "Dop original" << endl;
	ofstream file_dop_run3;
	ofstream file_dop_mg3;
	file_dop_run3.open("dop\\OriginalRunDop.txt");
	file_dop_mg3.open("dop\\OriginalMgDop.txt");
	for (int i = 1; i <= 60; i += 3) {
		//cout << "R = " << i << endl;
		Quantization quantization_original_dop(DCT_original.get_DCT(), height_original, width_original, &bfh_original, &bih_original);
		quantization_original_dop.quantization(i);
		Compression compression_original_dop(quantization_original_dop.get_quantization(), height_original, width_baboon, &bfh_original, &bih_original);
		compression_original_dop.create_DC();
		compression_original_dop.coding_DC();
		compression_original_dop.create_AC("Y");
		compression_original_dop.coding_AC("Y");
		double Run = compression_original_dop.stream_size3("Y", 1);
		double Mg = compression_original_dop.stream_size3("Y", 2);
		file_dop_run3 << i << " " << Run << endl;
		file_dop_mg3 << i << " " << Mg << endl;
	}
	file_dop_run3.close();
	file_dop_mg3.close();
	
	return 0;
}
