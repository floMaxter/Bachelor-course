#pragma once
#define N 100

struct polynomial
{	
	int deg;		// ������� 
	double odds[N]; // ������������
};

int getUserIput(struct polynomial* t);
int getOper(int op);
int calculateResult(struct polynomial pol1, int op, struct polynomial pol2);
