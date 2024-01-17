#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <queue>
#include <list>
#include <fstream>
#include <random>
#include <stack>
#include <math.h>

using namespace std;

// Inputs For Dopusk ======================================================================

double lambda = 0.0;
int interCount = 1000; // ����� ��������� � ������� � ������� ��������
vector<double> intervals;

// Inputs For Aloha ========================================================================
float lambdaBase = 0.0; // ������� �������������
bool var = true; // ����� true - ����������������, ����� false - �������
int M = 50; // ���������� ���������
int W = 99; // �������� ����
int sizeD = 0; // ���������� �������

struct message
{
    double timeIn;
    int winForSend = 0;
};
struct abonent
{
    list<message> allMessage;
    queue<message> q;
};
abonent* ab = new abonent[M];

// ��������� ���� ��� ����� ================================================================
std::random_device r;
std::mt19937 generator(r());
std::uniform_int_distribution<> distribution(0, W - 1);
int generate_window(int win)
{
    return distribution(generator) + win;
}

// ��������� ��� �������������� ������ ====================================================

double puasson_generate(bool flag)
{
    double randNum = (double)(rand()) / RAND_MAX;
    while (randNum == 0.0)
    {
        randNum = (double)(rand()) / RAND_MAX;
    }

    double tmp1 = log(randNum);
    double tmp2;
    if (flag == false)
    {
        tmp2 = (double)(tmp1 / lambda);
    }
    else
    {
        double tmp3 = (double)(lambda / (double)M);
        tmp2 = (double)(tmp1 / tmp3);
    }
    randNum = (-1.0) * tmp2;

    return randNum;
}

// ������������ ���������� ================================================================

void get_intevals(vector<double>* vec)
{
    double sum = 0.0;
    int step = 0;
    while (step < interCount)
    {
        double resGenerate = puasson_generate(false);
        sum = sum + resGenerate;
        vec->push_back(sum);
        step++;
    }
}

// ������������ ���������� ��� M ��������� ����� ===========================================

void get_ab_intervals()
{
    for (int i = 0; i < M; i++)
    {
        double sum = 0.0;
        int step = 0;
        while (step < interCount)
        {
            step++;
            message mes;
            double resGenerate = puasson_generate(true);
            sum = sum + resGenerate;
            mes.timeIn = sum;
            ab[i].allMessage.push_back(mes);
        }
    }
}

// ������������� ���������� ����������� ������������� ��� ����� � ������� ������ ===========
void alohaWinDiff(double Tc, double Ts, double Te)
{
    cout.precision(20);
    double pAloha = 0.01;
    for (; pAloha < 1.0; pAloha = pAloha + 0.01)
    {
        double pS = pow(1.0 - pAloha, M - 1) * M * pAloha;
        double pE = pow(1.0 - pAloha, M);
        double pC = 1 - pS - pE;

        double lamCr = (double)(pS / (double)(Tc * pC + Ts * pS + Te * pE));
        printf("%f\t", pAloha);
        cout << lamCr << endl;
    }
}

// ������������ �������� ����� ============================================================

void aloha()
{
    sizeD = 0;
    double delay = 0.0;
    int window = 1;
    int nSr = 0;
    while (1)
    {
        int countdel = 0;
        // ���������� � ������� ��������� ��������� ---------------------------------------
        for (int i = 0; i < M; i++)
        {
            if (ab[i].allMessage.size() == 0 && ab[i].q.size() == 0) { countdel++; }
            if (ab[i].allMessage.size() > 0)
            {
                auto iter1 = ab[i].allMessage.begin();
                message tmpMess = *iter1;
                while (tmpMess.timeIn < window)
                {
                    //if (ab[i].q.size() == 0 && var == true) //����������� �������
                    //{
                    //    tmpMess.winForSend = window;
                    //}
                    ab[i].q.push(tmpMess);
                    ab[i].allMessage.pop_front();
                    if (ab[i].allMessage.size() > 0)
                    {
                        iter1 = ab[i].allMessage.begin();
                        tmpMess = *iter1;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        if (countdel == M) { break; } // �� ������, ���� �� ������ ��������� � ��������� �� ���� ���������

        // ���� �� �������� ������� � ���������� ����� ���� �������� � ������� ������� ��������� ���������� � ������� ���� ----------------------
        int countAb = 0;
        for (int i = 0; i < M; i++)
        {
            if (!ab[i].q.empty())
            {
                nSr += ab[i].q.size();
                if (ab[i].q.front().winForSend == 0)
                {
                    ab[i].q.front().winForSend = generate_window(window);
                }
                if (ab[i].q.front().winForSend == window)
                {
                    countAb++;
                }
            }
        }

        bool isSuc = false;
        if (countAb == 0) // �����
        {
            window++;
            continue;
        }
        else if (countAb == 1) // �����
        {
            isSuc = true;
            sizeD++;
        }
        else if (countAb >= 2) // ��������
        {
            isSuc = false;
        }

        for (int i = 0; i < M; i++)
        {
            //cout << "M = " << i << endl;
            if (!ab[i].q.empty())
            {
                // �������� ��������, ������ ���������� ����� ���� ��� �������� � ��, ������� ���� � ���������
                /*if (ab[i].q.front().winForSend == window && isSuc == false)
                {
                    ab[i].q.front().winForSend = generate_window(window + 3);
                }*/

                //� ������ ��������� �������� ���� ��� ���������� ��������� � ����������� �� �� ������ (���������� �� �������)
                if (ab[i].q.front().winForSend == window && isSuc == false)
                {
                    ab[i].q.front().winForSend = window + i + 3;
                    /*for (int j = M - 1; j >= 0; j--) {
                        if (j != i && ab[j].q.size() > 0) {
                            if (ab[j].q.front().winForSend == window + i) {
                                cout << "For " << j << "changed window on " << window + i + 1 << endl;
                                ab[j].q.front().winForSend = window + i + 1;
                            }
                        }
                    }*/
                }

                // �������� �����, ������� ��������
                if (ab[i].q.front().winForSend == window && isSuc == true)
                {
                    delay = delay + window + 1 - ab[i].q.front().timeIn;
                    ab[i].q.pop();
                }
            }
        }
        window++;
    }
    //cout << lambda << " " << (double)(delay / (double)sizeD) << endl; //��������
    window--;
    //cout << lambda << " " << (double)((double)nSr / (double)window) << endl; //������� ����� ���������
    cout << lambda << " " << (double)((double)sizeD / (double)window) << endl; //�������� �������������
}


void randomAccess()
{
    srand(time(NULL));
    cout << "Aloha()\n";
    for (lambda = 0.1; lambda < 0.41; lambda = lambda + 0.01)
    {
        get_ab_intervals();
        aloha();
    }

    /*srand(time(NULL));
    cout << "Base():\n";
    for (lambda = 0.1; lambda < 1; lambda = lambda + 0.1)
    {
        get_ab_intervals();
        aloha();
    }*/
}

void startAloha() {
    W = 20;
    cout << W << " ";
    randomAccess();
   /* W = 60;
    cout << W << " ";
    randomAccess();
    W = 120;
    cout << W << " ";
    randomAccess();*/
}

int main()
{
    startAloha();

    return 0;
}