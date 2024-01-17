#ifndef LAB1_SETI_CALC_H
#define LAB1_SETI_CALC_H
#include <vector>
using namespace std;

class Calc {
private:
    uint64_t g;
    uint64_t l;
    uint64_t r;
    vector<size_t> weights;
    int d;
    
    [[nodiscard]] uint64_t codeWord(uint64_t i) const;

public:
    Calc(uint64_t g, uint64_t l);

    [[nodiscard]] long double upperBound(long double p) const;

    long double calcErr(long double p);

};

#endif //LAB1_SETI_CALC_H

