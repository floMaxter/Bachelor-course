#pragma once
#define N 100

struct polynomial
{
	int deg;																								// ������� 
	double odds[N];																							// ������������
};

int getUserIput(struct polynomial* t);																		//���� ��������
int getOper(int op);																						//���� ��������������� ��������
void calculateResult(struct polynomial pol1, int op, struct polynomial pol2, struct polynomial* pol3, struct polynomial* pol4);//������� ����������
void insert_sero(struct polynomial* pol1, struct polynomial* pol2);											//������� ����� � ������
void printResult(struct polynomial pol1, struct polynomial pol2, struct polynomial pol3, struct polynomial pol4, int op);					//����� ����������	
