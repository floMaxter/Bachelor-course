#include <stdio.h>
#include "LibPolynomial.h"
int main()
{
	char c = 0;
	struct polynomial pol1;
	struct polynomial pol2;
	int op = 0;

	//Первый полином
	getUserIput(&pol1);

	//Второй полином
	getUserIput(&pol2);

	//Математическая знак
	op = getOper(op);
	if(op == -1)
	{
		return -1;
	}
	printf_s("%d", op);
	
	//вычисление результата
	calculateResult(pol1, op, pol2);

	//Вывод результата

	return 0;
}