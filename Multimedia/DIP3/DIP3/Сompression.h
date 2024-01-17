#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <map>
#include "bmp.h"

using namespace std;

class Compression {
private:
	int height;
	int width;
	int N = 8;
	YCbCr** quantization_ycbcr;
	BITMAPFILEHEADER* bfh;
	BITMAPINFOHEADER* bih;
	vector<vector<int>> dc;
	vector<vector<pair<unsigned char, int>>> code_dc;
	vector<vector<int>> ac_Y;
	vector<vector<int>> ac_Cb;
	vector<vector<int>> ac_Cr;
	vector<vector<pair<unsigned char, pair<unsigned char, int>>>> code_ac_Y;
	vector<vector<pair<unsigned char, pair<unsigned char, int>>>> code_ac_Cb;
	vector<vector<pair<unsigned char, pair<unsigned char, int>>>> code_ac_Cr;

public:
	Compression(YCbCr** y_q, int h, int w, BITMAPFILEHEADER* bf, BITMAPINFOHEADER* bi) {
		quantization_ycbcr = y_q;
		height = h;
		width = w;
		bfh = bf;
		bih = bi;
	}

	void create_DC() {
		// проход по полосе
			size_t numOfBlocks = height / N;
			vector<int> YDC;
			vector<int> CbDC;
			vector<int> CrDC;
			for (size_t i = 0; i < numOfBlocks; i++) {
				for (size_t j = 0; j < numOfBlocks; j++) {
					YDC.push_back(static_cast<int>(quantization_ycbcr[i * N][j * N].Y));
					CbDC.push_back(static_cast<int>(quantization_ycbcr[i * N][j * N].Cb));
					CrDC.push_back(static_cast<int>(quantization_ycbcr[i * N][j * N].Cr));
				}
			}
			dc.push_back(YDC);
			dc.push_back(CbDC);
			dc.push_back(CrDC);
	}

	pair<unsigned char, int> get_BC(double diff) { // запись битовой категории BC и амплитуды MG
		pair<unsigned char, int> res;
		int mg = static_cast<int>(round(diff));
		if (mg == 0) {
			res.first = 0;
			res.second = 0;
			return res;
		}
		for (size_t i = 1; i < 16; i++) { // отнесение к одной из 16 битовых категорий
			int m_min = 1 - pow(2, i);
			int m_max = 0 - pow(2, i - 1);
			int p_min = pow(2, i - 1);
			int p_max = pow(2, i) - 1;
			if ((mg >= m_min && mg <= m_max) || (mg >= p_min && mg <= p_max)) {
				res.first = static_cast<unsigned char>(i);
				res.second = mg;
				return res;
			}
		}
	}

	void coding_DC() { // разностное кодирование для DC
		size_t numOfBlocks = dc[0].size();
		double average_Y = 0;
		double average_Cb = 0;
		double average_Cr = 0;

		for (size_t i = 0; i < numOfBlocks; i++) {
			average_Y += dc[0][i];
			average_Cb += dc[1][i];
			average_Cr += dc[2][i];
		}
		average_Y /= numOfBlocks;
		average_Cb /= numOfBlocks;
		average_Cr /= numOfBlocks;

		vector<pair<unsigned char, int>> vec_Y; 
		vector<pair<unsigned char, int>> vec_Cb;
		vector<pair<unsigned char, int>> vec_Cr; 
		for (size_t i = 0; i < numOfBlocks; i++) {
			if (i == 0) {
				vec_Y.push_back(get_BC(dc[0][0] - average_Y));
				vec_Cb.push_back(get_BC(dc[1][0] - average_Cb));
				vec_Cr.push_back(get_BC(dc[2][0] - average_Cr));
			}
			else {
				vec_Y.push_back(get_BC(dc[0][i] - dc[0][i - 1]));
				vec_Cb.push_back(get_BC(dc[1][i] - dc[1][i - 1]));
				vec_Cr.push_back(get_BC(dc[2][i] - dc[2][i - 1]));
			}
		}
		code_dc.push_back(vec_Y);
		code_dc.push_back(vec_Cb);
		code_dc.push_back(vec_Cr);
	}

	void get_histogram_dc(string fileName, string component) {
		ofstream file(fileName);
		int row = 0;
		if (component == "Y")
			row = 0;
		if (component == "Cb")
			row = 1;
		if (component == "Cr")
			row = 2;
		for (size_t i = 0; i < dc[row].size(); i++) {
			file << static_cast<double>(dc[row][i]) << endl;
		}

		file.close();
	}

	void get_histogram_code_dc(string fileName, string component) {
		ofstream file(fileName);
		int row = 0;
		if (component == "Y")
			row = 0;
		if (component == "Cb")
			row = 1;
		if (component == "Cr")
			row = 2;
		for (size_t i = 0; i < code_dc[row].size(); i++) {
			file << static_cast<double>(code_dc[row][i].second) << endl;
		}

		file.close();
	}

	void entropy() {
		map<double, double> p_dc_Y;
		map <double, double> p_dc_Cb;
		map <double, double> p_dc_Cr;
		map <double, double> p_code_dc_Y;
		map <double, double> p_code_dc_Cb;
		map <double, double> p_code_dc_Cr;

		for (size_t i = 0; i < dc[0].size(); i++) {
			if (p_dc_Y.find(dc[0][i]) != p_dc_Y.end())
				p_dc_Y[dc[0][i]]++;
			else 
				p_dc_Y.insert(pair<double, double>(dc[0][i], 1));

			if (p_dc_Cb.find(dc[1][i]) != p_dc_Cb.end())
				p_dc_Cb[dc[1][i]]++;
			else 
				p_dc_Cb.insert(pair<double, double>(dc[1][i], 1));

			if (p_dc_Cr.find(dc[2][i]) != p_dc_Cr.end())
				p_dc_Cr[dc[2][i]]++;
			else 
				p_dc_Cr.insert(pair<double, double>(dc[2][i], 1));

			if (p_code_dc_Y.find(code_dc[0][i].second) != p_code_dc_Y.end())
				p_code_dc_Y[code_dc[0][i].second]++;
			else 
				p_code_dc_Y.insert(pair<double, double>(code_dc[0][i].second, 1));

			if (p_code_dc_Cb.find(code_dc[1][i].second) != p_code_dc_Cb.end())
				p_code_dc_Cb[code_dc[1][i].second]++;
			else 
				p_code_dc_Cb.insert(pair<double, double>(code_dc[1][i].second, 1));

			if (p_code_dc_Cr.find(code_dc[2][i].second) != p_code_dc_Cr.end())
				p_code_dc_Cr[code_dc[2][i].second]++;
			else 
				p_code_dc_Cr.insert(pair<double, double>(code_dc[2][i].second, 1));
		}

		double H_dc_Y = 0, H_dc_Cb = 0, H_dc_Cr = 0, H_cdc_Y = 0, H_cdc_Cb = 0, H_cdc_Cr = 0;
		for (pair<double, double> it : p_dc_Y) {
			it.second /= dc[0].size();
			if (!isinf(log2(it.second))) {
				H_dc_Y += it.second * log2(it.second);
			}
		}
		for (pair<double, double> it : p_dc_Cb) {
			it.second /= dc[0].size();
			if (!isinf(log2(it.second))) {
				H_dc_Cb += it.second * log2(it.second);
			}
		}
		for (pair<double, double> it : p_dc_Cr) {
			it.second /= dc[0].size();
			if (!isinf(log2(it.second))) {
				H_dc_Cr += it.second * log2(it.second);
			}
		}
		for (pair<double, double> it : p_code_dc_Y) {
			it.second /= dc[0].size();
			if (!isinf(log2(it.second))) {
				H_cdc_Y += it.second * log2(it.second);
			}
		}
		for (pair<double, double> it : p_code_dc_Cb) {
			it.second /= dc[0].size();
			if (!isinf(log2(it.second))) {
				H_cdc_Cb += it.second * log2(it.second);
			}
		}
		for (pair<double, double> it : p_code_dc_Cr) {
			it.second /= dc[0].size();
			if (!isinf(log2(it.second))) {
				H_cdc_Cr += it.second * log2(it.second);
			}
		}
		cout << "\nH(DC_Y): " << -H_dc_Y;
		cout << "\nH(DC_Cb): " << -H_dc_Cb;
		cout << "\nH(DC_Cr): " << -H_dc_Cr << endl;
		cout << "\nH(code_DC_Y): " << -H_cdc_Y;
		cout << "\nH(code_DC_Cb): " << -H_cdc_Cb;
		cout << "\nH(code_DC_Cr): " << -H_cdc_Cr << endl;
	}

	// Перегруппировка AC коэффициентов в соответствии с зигзагообразной последовательностью
	void create_AC(string component) {

		for (size_t i = 0; i < height; i += N) {
			for (size_t j = 0; j < width; j += N) {
				vector<int> vec;
				for (size_t diag = 0; diag < N; diag++) {
					if (diag % 2 == 0) {
						int x = diag;
						int y = 0;
						while (x >= 0) {
							if (x == 0 && y == 0) 
								break;
							if (component == "Y")
								vec.push_back(static_cast<int>(round(quantization_ycbcr[i + x][j + y].Y)));
							else {
								if (component == "Cb")
									vec.push_back(static_cast<int>(round(quantization_ycbcr[i + x][j + y].Cb)));
								else
									vec.push_back(static_cast<int>(round(quantization_ycbcr[i + x][j + y].Cr)));
							}
							x--;
							y++;
						}
					}
					else {
						int x = 0;
						int y = diag;
						while (y >= 0) {
							if (component == "Y")
							 vec.push_back(static_cast<int>(round(quantization_ycbcr[i + x][j + y].Y)));
							else {
								if (component == "Cb")
									vec.push_back(static_cast<int>(round(quantization_ycbcr[i + x][j + y].Cb)));
								else
									vec.push_back(static_cast<int>(round(quantization_ycbcr[i + x][j + y].Cr)));
							}
							x++;
							y--;
						}
					}
				}
				for (size_t diag = 1; diag < N; diag++) {
					if (diag % 2 == 0) {
						int x = diag;
						int y = N - 1;
						while (x <= N - 1) {
							if (component == "Y")
							 vec.push_back(static_cast<int>(round(quantization_ycbcr[i + x][j + y].Y)));
							else {
								if (component == "Cb")
									vec.push_back(static_cast<int>(round(quantization_ycbcr[i + x][j + y].Cb)));
								else
									vec.push_back(static_cast<int>(round(quantization_ycbcr[i + x][j + y].Cr)));
							}
							x++;
							y--;
						}
					}
					else {
						int x = N - 1;
						int y = diag;
						while (y <= N - 1) {
							if (component == "Y")
								vec.push_back(static_cast<int>(round(quantization_ycbcr[i + x][j + y].Y)));
							else {
								if (component == "Cb")
									vec.push_back(static_cast<int>(round(quantization_ycbcr[i + x][j + y].Cb)));
								else
									vec.push_back(static_cast<int>(round(quantization_ycbcr[i + x][j + y].Cr)));
							}
							x--;
							y++;
						}
					}
				}
				if (component == "Y")
				 ac_Y.push_back(vec);
				else {
					if (component == "Cb")
						ac_Cb.push_back(vec);
					else
						ac_Cr.push_back(vec);
				}
			}
		}
	}

	void coding_AC(string component) { // формирование RUN = (Run, BC(Level)) и Level = Magnitude(Level)
		vector<vector<int>> AC;
		if (component == "Y")
			AC = ac_Y;
		else {
			if (component == "Cb")
				AC = ac_Cb;
			else
				AC = ac_Cr;
		}
		vector<vector<pair<unsigned char, pair<unsigned char, int>>>> res;
		for (size_t i = 0; i < ac_Y.size(); i++) {
			vector<pair<unsigned char, pair<unsigned char, int>>> vec;
			size_t lastNotNull = 0;
			for (size_t j = 0; j < 63; j++) {
				if (AC[i][j] != 0) 
					lastNotNull = j;
			}

			for (size_t j = 0; j <= lastNotNull; j++) {
				if (AC[i][j] != 0) {
					pair<unsigned char, pair<unsigned char, int>> tmp;
					tmp.first = 0;
					tmp.second = get_BC(AC[i][j]);
					vec.push_back(tmp);
				}
				else {
					pair<unsigned char, pair<unsigned char, int>> tmp;
					tmp.first = 1;
					size_t j1 = j + 1;
					size_t count = 1;
					while (AC[i][j1] == 0 && count <= 16 && j1 < lastNotNull) {
						j1++;
						count++;
						tmp.first++;
					}
					if (AC[i][j1] != 0 && count < 16) {
						tmp.second = get_BC(AC[i][j1]);
						vec.push_back(tmp);
						j = j1;
					}
					else if (count == 16) {
						tmp.first = 15;
						tmp.second.first = 0;
						tmp.second.second = 0;
						vec.push_back(tmp);
						j = j1;
					}
				}
			}

			pair<unsigned char, pair<unsigned char, int>> last;
			last.first = 0;
			last.second.first = 0;
			last.second.second = 0;
			vec.push_back(last);

			if (component == "Y")
				code_ac_Y.push_back(vec);
			else {
				if (component == "Cb")
					code_ac_Cb.push_back(vec);
				else
					code_ac_Cr.push_back(vec);
			}

		}
	}

	void stream_size(string component) {
		vector<vector<pair<unsigned char, pair<unsigned char, int>>>> codAC;
		int I = 0;
		if (component == "Y") {
			codAC = code_ac_Y;
			I = 0;
		}
		else
		{
			if (component == "Cb") {
				codAC = code_ac_Cb;
				I = 1;
			}
			else {
				codAC = code_ac_Cr;
				I = 2;
			}
		}
		size_t Ndc = dc[0].size();
		size_t Nrl = get_pair_num(codAC);

		size_t sum_BC_dDC = 0;
		map<double, double> p_BC_dDC;
		for (size_t i = 0; i < code_dc[I].size(); i++) {
			sum_BC_dDC += code_dc[I][i].first;

			if (p_BC_dDC.find(code_dc[I][i].first) != p_BC_dDC.end()) {
				p_BC_dDC[code_dc[I][i].first]++;
			}
			else 
				p_BC_dDC.insert(pair<double, double>(code_dc[I][i].first, 1));
		}


		double H_BC_dDC = 0;
		for (pair<double, double> it : p_BC_dDC) {
			it.second /= code_dc[I].size();
			if (!isinf(log2(it.second))) {
				H_BC_dDC += it.second * log2(it.second);
			}
		}
		H_BC_dDC *= -1;

		size_t sum_BC_level = 0;
		map<pair<unsigned char, unsigned char>, double> p_rl;
		for (size_t i = 0; i < codAC.size(); i++) {
			for (size_t j = 0; j < codAC[i].size(); j++) {
				sum_BC_level += codAC[i][j].second.first;

				pair<unsigned char, unsigned char> tmp;
				tmp.first = codAC[i][j].first;
				tmp.second = codAC[i][j].second.first;
				if (p_rl.find(tmp) != p_rl.end())
					p_rl[tmp]++;
				else p_rl.insert(pair<pair<unsigned char, unsigned char>, double>(tmp, 1));
			}
		}
		double H_rl = 0;
		for (pair<pair<unsigned char, unsigned char>, double> it : p_rl) {
			it.second /= Nrl;
			if (!isinf(log2(it.second))) {
				H_rl += it.second * log2(it.second);
			}
		}
		H_rl *= -1;

		size_t res = (H_BC_dDC * Ndc) + sum_BC_dDC + (H_rl * Nrl) + sum_BC_level;

		size_t origin = 8 * height * width;

		double d = (double)origin / (double)res;

		//double a1 = (double)((H_rl * Nrl * 100) / (double)((H_rl * Nrl) + sum_BC_level));
		//double a2 = (double)((sum_BC_level * 100) / (double)((H_rl * Nrl) + sum_BC_level));

		double bcdc = (double)((double)(H_BC_dDC * Ndc * 100) / (double)(res));
		double magnitude = (double)((double)(sum_BC_dDC * 100) / (double)(res));
		double runBClevel = (double)((H_rl * Nrl * 100) / (double)(res));
		double magnitudeLevel = (double)((sum_BC_level * 100) / (double)(res));
		cout << "BC(code DC): " << bcdc << "%" << endl;
		cout << "MG(code DC): " << magnitude << "%" << endl;
		cout << "(Run, BC(Level)): " << runBClevel << "%" << endl;
		cout << "MG(Level): " << magnitudeLevel << "%" << endl;
	}
	double stream_size2(string component) {
		vector<vector<pair<unsigned char, pair<unsigned char, int>>>> codAC;
		int I = 0;
		if (component == "Y") {
			codAC = code_ac_Y;
			I = 0;
		}
		else
		{
			if (component == "Cb") {
				codAC = code_ac_Cb;
				I = 1;
			}
			else {
				codAC = code_ac_Cr;
				I = 2;
			}
		}
		size_t Ndc = dc[0].size();
		size_t Nrl = get_pair_num(codAC);

		size_t sum_BC_dDC = 0;
		map<double, double> p_BC_dDC;
		for (size_t i = 0; i < code_dc[I].size(); i++) {
			sum_BC_dDC += code_dc[I][i].first;

			if (p_BC_dDC.find(code_dc[I][i].first) != p_BC_dDC.end()) {
				p_BC_dDC[code_dc[I][i].first]++;
			}
			else
				p_BC_dDC.insert(pair<double, double>(code_dc[I][i].first, 1));
		}


		double H_BC_dDC = 0;
		for (pair<double, double> it : p_BC_dDC) {
			it.second /= code_dc[I].size();
			if (!isinf(log2(it.second))) {
				H_BC_dDC += it.second * log2(it.second);
			}
		}
		H_BC_dDC *= -1;

		size_t sum_BC_level = 0;
		map<pair<unsigned char, unsigned char>, double> p_rl;
		for (size_t i = 0; i < codAC.size(); i++) {
			for (size_t j = 0; j < codAC[i].size(); j++) {
				sum_BC_level += codAC[i][j].second.first;

				pair<unsigned char, unsigned char> tmp;
				tmp.first = codAC[i][j].first;
				tmp.second = codAC[i][j].second.first;
				if (p_rl.find(tmp) != p_rl.end())
					p_rl[tmp]++;
				else p_rl.insert(pair<pair<unsigned char, unsigned char>, double>(tmp, 1));
			}
		}
		double H_rl = 0;
		for (pair<pair<unsigned char, unsigned char>, double> it : p_rl) {
			it.second /= Nrl;
			if (!isinf(log2(it.second))) {
				H_rl += it.second * log2(it.second);
			}
		}
		H_rl *= -1;

		size_t res = (H_BC_dDC * Ndc) + sum_BC_dDC + (H_rl * Nrl) + sum_BC_level;
		size_t origin = 8 * height * width;
		double d = (double)origin / (double)res;
		return d;
	}

	double stream_size3(string component, int flag) {
		vector<vector<pair<unsigned char, pair<unsigned char, int>>>> codAC;
		int I = 0;
		if (component == "Y") {
			codAC = code_ac_Y;
			I = 0;
		}
		else
		{
			if (component == "Cb") {
				codAC = code_ac_Cb;
				I = 1;
			}
			else {
				codAC = code_ac_Cr;
				I = 2;
			}
		}
		size_t Ndc = dc[0].size();
		size_t Nrl = get_pair_num(codAC);

		size_t sum_BC_dDC = 0;
		map<double, double> p_BC_dDC;
		for (size_t i = 0; i < code_dc[I].size(); i++) {
			sum_BC_dDC += code_dc[I][i].first;

			if (p_BC_dDC.find(code_dc[I][i].first) != p_BC_dDC.end()) {
				p_BC_dDC[code_dc[I][i].first]++;
			}
			else
				p_BC_dDC.insert(pair<double, double>(code_dc[I][i].first, 1));
		}


		double H_BC_dDC = 0;
		for (pair<double, double> it : p_BC_dDC) {
			it.second /= code_dc[I].size();
			if (!isinf(log2(it.second))) {
				H_BC_dDC += it.second * log2(it.second);
			}
		}
		H_BC_dDC *= -1;

		size_t sum_BC_level = 0;
		map<pair<unsigned char, unsigned char>, double> p_rl;
		for (size_t i = 0; i < codAC.size(); i++) {
			for (size_t j = 0; j < codAC[i].size(); j++) {
				sum_BC_level += codAC[i][j].second.first;

				pair<unsigned char, unsigned char> tmp;
				tmp.first = codAC[i][j].first;
				tmp.second = codAC[i][j].second.first;
				if (p_rl.find(tmp) != p_rl.end())
					p_rl[tmp]++;
				else p_rl.insert(pair<pair<unsigned char, unsigned char>, double>(tmp, 1));
			}
		}
		double H_rl = 0;
		for (pair<pair<unsigned char, unsigned char>, double> it : p_rl) {
			it.second /= Nrl;
			if (!isinf(log2(it.second))) {
				H_rl += it.second * log2(it.second);
			}
		}
		H_rl *= -1;

		size_t res = (H_BC_dDC * Ndc) + sum_BC_dDC + (H_rl * Nrl) + sum_BC_level;
		size_t origin = 8 * height * width;
		double d = (double)origin / (double)res;
		double a1 = (double)((H_rl * Nrl * 100) / (double)((H_rl * Nrl) + sum_BC_level));
		double a2 = (double)((sum_BC_level * 100) / (double)((H_rl * Nrl) + sum_BC_level));

		double bcdc = (double)((double)(H_BC_dDC * Ndc * 100) / (double)(res));
		double magnitude = (double)((double)(sum_BC_dDC * 100) / (double)(res));
		double runBClevel = (double)((H_rl * Nrl * 100) / (double)(res));
		double magnitudeLevel = (double)((sum_BC_level * 100) / (double)(res));
		/*cout << "BC: " << a1 << "%" << endl;
		cout << "Magnitude: " << a2 << "%" << endl;*/
		if (flag == 1)
			return a1;
		else if (flag == 2)
			return a2;
	}
	int get_pair_num(vector<vector<pair<unsigned char, pair<unsigned char, int>>>> codAC) {
		int res = 0;
		for (size_t i = 0; i < codAC.size(); i++) {
			res += codAC[i].size();
		}
		return res;
	}


};
