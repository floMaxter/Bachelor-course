#include "Calc.h"
#include <cmath>
#include <bitset>
#include <iostream>
using namespace std;

const uint64_t m1 = 0x5555555555555555; // маска для четных битов 010101
const uint64_t m2 = 0x3333333333333333; // 110011001100
const uint64_t m4 = 0x0f0f0f0f0f0f0f0f; // 1111000011110000
const uint64_t h01 = 0x0101010101010101; // 00000001

int hammingWeight(uint64_t x) {
    x -= (x >> 1) & m1;
    x = (x & m2) + ((x >> 2) & m2);
    x = (x + (x >> 4)) & m4;
    return (x * h01) >> 56;
}

Calc::Calc(uint64_t g, uint64_t l) {
    this->g = g;
    this->l = l;
    for (int i = 0; i < 32; ++i) {
        if ((g >> i) == 1) {
            r = i;
        }
    }
    weights.resize(r + l + 1);

    for (size_t i = 1; i < powl(2, l); i++) { // формируем кодовые слова + вычисляем их вес
        ++weights[hammingWeight(codeWord(i))];
    }

    for (int i = 0; i < weights.size(); ++i) {
        if (weights[i] != 0) {
            d = i;
            break;
        }
    }
    cout <<"d: " <<d <<"\n";
    ++weights[0];

    for(int i = 0; i < weights.size(); i++) {
       cout<< "Number of words with weight " << i << " : " << weights[i]<< endl;
    }
}

long double Calc::upperBound(long double p) const {
    long double res = 1;
    long double summ = 0;
    for (size_t i = 0; i < d; ++i) {
        long double fact = tgammal(r + l + 1) / (tgammal(i + 1) * tgammal(r + l + 1 - i));
        summ += fact * powl(p, i) * powl(1 - p, r + l - i);
    }
    res -= summ;
    return res;
}

long double Calc::calcErr(long double p) {
    long double res = 0;
    for (size_t i = d; i <= r + l; ++i) {
        res += weights[i] * powl(p, i) * powl(1 - p, r + l - i);
    }
    return res;
}

uint64_t Calc::codeWord(uint64_t i) const {
    //cout << "HERE i: " << i << std::endl;
    uint64_t res = i << r;
    while (1) {
        int j = 0;
        for (int i = 0; i < 32; i++) {
            if (res & (1 << i)) {
                j = i;
            }
        }
        if (j <= r) {
            break;
        }
        res ^= (g << (j - r));
    }
    if ((res & (1 << r)) >> r == 1) {
        res ^= g;
    }
    res |= (i << r);
    cout<<"Code word: ";
    cout << bitset<7>(res) << std::endl;
    return res;
}
