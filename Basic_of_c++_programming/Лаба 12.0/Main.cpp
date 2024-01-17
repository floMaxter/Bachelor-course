#include <iostream>
#include <locale>
#include "Header.h"
using namespace std;

/*Создайте класс с именем IntModulo для выполнения действий с целыми по модулю P, указанному в конструкторе.*/

int main()
{
	setlocale(LC_ALL, "Ru");
	int tmp = 0;
	int oper = 0;																		// Арифметический знак
	IntModulo A;
	IntModulo B;
	IntModulo Result;

	tmp = GetUserInput(A, B, oper);														// Ввод от пользователя
	if (tmp == -1)
	{
		cout << endl;
		cout << "Ошибка" << endl;
		return -1;
	}

	tmp = CompOfMod(A, B, oper);													    //Проверка модулей на равенство
	if (tmp == -1)
	{
		cout << endl;
		cout << "Мы не можем делать действия над числами по разному модулю" << endl;
		return -1;
	}
	if (oper == 1 || oper == 2 || oper == 3)
	{
		Result = Modulo_Calculator(A, B, oper);											//Калькулятор по модулю
		
		cout << endl;
		cout << "Результат равен " << Result.GetNumber() << " по модулю " << Result.GetMod() << endl;
	}
	else
	{
		cout << endl;
		cout << "Ошибка, неверный знак" << endl;
		return -1;
	}

	
	int m = 0;
	m = m;

	return 0;
}