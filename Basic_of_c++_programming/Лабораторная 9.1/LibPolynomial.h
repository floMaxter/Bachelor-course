#pragma once
#define N 100

struct polynomial
{
	int deg;																								// степень 
	double odds[N];																							// коэффициенты
};

int getUserIput(struct polynomial* t);																		//Ввод полинома
int getOper(int op);																						//Ввод алгебраического оператор
void calculateResult(struct polynomial pol1, int op, struct polynomial pol2, struct polynomial* pol3, struct polynomial* pol4);//Подсчет результата
void insert_sero(struct polynomial* pol1, struct polynomial* pol2);											//Вставка нулей в массив
void printResult(struct polynomial pol1, struct polynomial pol2, struct polynomial pol3, struct polynomial pol4, int op);					//Вывод результата	
