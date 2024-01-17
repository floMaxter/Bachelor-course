#include <iostream>
#include <vector>
#include <stack>
#include <fstream>
#include <time.h>
#include <math.h>

using namespace std;

#define VERTEX 9
#define EDGES 14
#define START 0 //1
#define FINISH 8 //9

int edges[EDGES][2] = { {0, 1}, {0, 2}, {0, 3}, {1, 3}, {2, 3}, {2, 4}, {3, 4}, {4, 5}, {4, 6}, {5, 6}, {5, 7}, {5, 8}, {6, 8}, {7, 8} };
vector<vector<int>> matrix(VERTEX, vector<int>(VERTEX));
bool visited[VERTEX] = { false };
bool found = false;
int Lmin = 4; // кратчайший путь
int Lmax = 12; // число ребер - число ребер, с которыми точно не будет пути

void dfs(int start) {
    stack<int> s;
    visited[start] = 1;
    s.push(start);
    int i = 0;
    while (!s.empty()) {
        int cur = s.top();
        if (cur == FINISH) {
            found = true;
            return;
        }
        for (i; i < VERTEX; i++) {
            if (matrix[cur][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                s.push(i);
                break;
            }
        }
        if (i == VERTEX) {
            i = s.top() + 1;
            s.pop();
        }
        else {
            i = 0;
        }
    }
}

int factorial(int a) {
    int res = 1;
    for (int i = 1; i <= a; ++i) {
        res *= i;
    }
    return res;
}

int combination(int n, int k) {
    int tmp = factorial(n) / (factorial(n - k) * factorial(k));
    return tmp;
}

int main() {
    fstream out1("brute_force.txt", ios::out), out2("model.txt", ios::out),
        out3("fast_model.txt", ios::out);
    double E = 0.01;
    int N = 2.25 / pow(E, 2);
    vector<int> y;
    srand(time(0));
    for (double p = 0; p <= 1; p += 0.1) {
        int S = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < EDGES; ++j) {
                if ((double)rand() / RAND_MAX <= p) { // генерация случайного вектора
                    y.push_back(1);
                }
                else {
                    y.push_back(0);
                }
            }
            for (int j = 0; j < y.size(); j++) {
                if (y[j] == 1) {
                    matrix[edges[j][0]][edges[j][1]] = 1; // строим подграф по вектору
                    matrix[edges[j][1]][edges[j][0]] = 1;
                }
            }
            y.clear();
            dfs(START); // определяем наличие пути в подграфе
            if (found) {
                S++;
            }
            for (int j = 0; j < matrix.size(); j++) { // обнуляем вектор
                matrix[j].clear();
                matrix[j].resize(VERTEX, 0);
            }
            for (int j = 0; j < VERTEX; j++) { // обнуляем посещения
                visited[j] = 0;
            }
            found = false;
        }
        double res2 = (double)S / N; // вероятность пути

        S = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < EDGES; ++j) {
                if ((double)rand() / RAND_MAX <= p) {
                    y.push_back(1);
                }
                else {
                    y.push_back(0);
                }
            }
            int count = 0;
            for (int k = 0; k < y.size(); ++k) {
                if (y[k] == 1) {
                    count++;
                }
            }
            if (count < Lmin) {
                y.clear();
                continue;
            }
            if (count > Lmax) {
                y.clear();
                S++;
                continue;
            }
            for (int j = 0; j < y.size(); j++) {
                if (y[j] == 1) {
                    matrix[edges[j][0]][edges[j][1]] = 1;
                    matrix[edges[j][1]][edges[j][0]] = 1;
                }
            }
            y.clear();
            dfs(START);
            if (found) {
                S++;
            }
            for (int j = 0; j < matrix.size(); j++) {
                matrix[j].clear();
                matrix[j].resize(VERTEX, 0);
            }
            for (int j = 0; j < VERTEX; j++) {
                visited[j] = 0;
            }
            found = false;
            int numb = 0;
            if (i != 0) {
                numb = N / i;
            }
            out1 << p << " " << numb << endl;
        }
        double res3 = (double)S / N;

        double res1 = (1 - p) * (4 * pow(p, 3) - 2 * pow(p, 5) - pow((2 * pow(p, 3) - pow(p, 5)), 2))
            + p * pow(p + 2 * pow(p, 2) - 2 * pow(p, 3) - pow(p, 4)
                + pow(p, 5), 2);
        out1 << p << " " << res1 << endl; // brute force
        out2 << p << " " << res2 << endl; // imit
        out3 << p << " " << res3 << endl; // fast imit
    }
    out1.close();
    out2.close();
    out3.close();


    out1.open("winning.txt", ios::out);
    for (double p = 0.1; p < 1; p += 0.1) {
        double sum = 0;
        for (int i = Lmin; i <= Lmax; ++i) {
            sum += combination(EDGES, i) * pow(p, i) * pow(1 - p, EDGES - i);
        }
        double res4 = 1 / sum;
        out1 << p << " " << res4 << endl;
    }
    out1.close();
}