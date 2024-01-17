#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>


using namespace std;

double p[] = { 0.6, 0.4 };
double lambda[] = { 0.7, 1.0 };
int N = 10000;

void write(string nameF, vector<double> Ti, int num);
void period1();
void period2();
void period3();
void summ();

int main() {
    period1();
    period2();
    period3();
    summ();
}

void write(string nameF, vector<double> Ti, int num) {
    vector<double> R;
    vector<double> Lambda;
    vector<double> R_T;
    vector<double> Lambda_T;
    int Nt = 0;
    int Ntdt = 0;
    fstream outR(nameF + "_R_practice.txt", ios::out);
    fstream outL(nameF + "_L_practice.txt", ios::out);
    for (double t = 0; t < 3; t += 0.01) {
        for (int i = 0; i < N; ++i) {
            if (Ti[i] >= t) {
                Nt++;
            }
            if (Ti[i] >= (t + 0.001)) {
                Ntdt++;
            }
        }
        R.push_back((double)Nt / (double)N);
        Lambda.push_back(((double)Nt - (double)Ntdt) / ((double)Nt * 0.001));
        outR << t << " " << R[R.size() - 1] << endl;
        outL << t << " " << Lambda[Lambda.size() - 1] << endl;
        Nt = 0;
        Ntdt = 0;
    }
    outR.close();
    outL.close();
    outR.open(nameF + "_R_theor.txt", ios::out);
    outL.open(nameF + "_L_theor.txt", ios::out);
    for (double t = 0; t < 3; t += 0.01) {
        if (num == 1) {
            R_T.push_back(exp((-1) * lambda[0] * t) * p[0] + exp((-1) * lambda[1] * t) * p[1]);

            Lambda_T.push_back(-((exp(-lambda[0] * t) * p[0] * (-lambda[0]) + exp(-lambda[1] * t) * p[1] * (-lambda[1])) / R_T[R_T.size() - 1]));
        }
        if (num == 2) {
            R_T.push_back(exp(-lambda[0] * t) * exp(-lambda[1] * t));
            Lambda_T.push_back(lambda[0] + lambda[1]);
        }
        if (num == 3) {
            R_T.push_back(exp(-lambda[0] * t) + exp(-lambda[1] * t) - exp(-(lambda[0] + lambda[1]) * t));
            Lambda_T.push_back(-(((-lambda[0] * exp(-lambda[0] * t)) - (lambda[1] * exp(-lambda[1] * t)) + (lambda[0] + lambda[1]) * exp(-(lambda[0] + lambda[1]) * t)) / (R_T[R_T.size() - 1])));
        }
        outR << t << " " << R_T[R_T.size() - 1] << endl;
        outL << t << " " << Lambda_T[Lambda_T.size() - 1] << endl;
    }
    outR.close();
    outL.close();
}

void period1() {
    vector<double> Ti;
    srand(time(0));
    for (int i = 0; i < N; ++i) {
        double tmp = ((double)rand() + 1) / RAND_MAX;
        if ((rand() / RAND_MAX) < (double)i / N - p[0]) {
            Ti.push_back(-log(tmp) / lambda[1]);
        }
        else {
            Ti.push_back(-log(tmp) / lambda[0]);
        }
    }
    write("m1", Ti, 1);
}

void period2() {
    vector<double> Ti;
    for (int i = 0; i < N; ++i) {
        double first = -log((double)rand() / RAND_MAX) / lambda[0];
        double second = -log((double)rand() / RAND_MAX) / lambda[1];
        Ti.push_back(min(first, second));
    }
    write("m2", Ti, 2);
}

void summ() {
    vector<double> Ti;
    double res = 0;
    for (int j = 0; j < N; j++) {
        // double tmp = ((double) rand() + 1) / RAND_MAX;
        double first = -log((double)rand() / RAND_MAX) / lambda[0];
        double second = -log((double)rand() / RAND_MAX) / lambda[1];

        res = first + second;

        Ti.push_back(res);

    }
    write("m3_2", Ti, 3);
}

void period3() {
    vector<double> Ti;
    double first = 0, second = 0;
    for (int i = 0; i < N; ++i) {
        double tmp = ((double)rand() + 1) / RAND_MAX;
        first = -log(tmp) / lambda[0];
        tmp = ((double)rand() + 1) / RAND_MAX;
        second = -log(tmp) / lambda[1];
        Ti.push_back(max(first, second));
    }
    write("m3", Ti, 3);
}
