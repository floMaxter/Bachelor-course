#include <stdio.h>
#include "LibPolynomial.h"
/*Ввести степени и коэффициенты двух многочленов. Вывести коэффициенты многочлена,
равного произведению производных от введенных многочленов.*/
/*Разработать библиотеку для работы с многочленами, структура с инициализацией, со степенью,коэффициентами,
арифметические действия над многочленами, разрушение структуры*/

int main()
{
	char c = 0;
	struct polynomial pol1; // Первый полином
	struct polynomial pol2; // Второй полином 
	struct polynomial pol3; // Полином, который получается в результате
	struct polynomial pol4; // Остаток от деления 
	int op = 0;
	

	//Первый полином
	if (getUserIput(&pol1) == -1)
	{
		return -1;
	}

	//Второй полином
	if (getUserIput(&pol2) == -1)
	{
		return -1;
	}

	//Математическая знак
	op = getOper(op);
	if (op == -1)
		{
			return -1;
		}

	//Вставка нулей
	insert_sero(&pol1, &pol2);

	//Математическая операция	
	calculateResult(pol1, op, pol2, &pol3, &pol4);

	//Вывод результата
	printResult(pol1, pol2, pol3, pol4, op);




	return 0;
}