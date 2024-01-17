#include <stdio.h>
#include "LibPolynomial.h"
#define N 100

int getUserIput(struct polynomial* t)
{
	char c = 0;
	//Степень полинома
	printf("What is the degree of the polynomial: ");
	if (scanf_s("%d", &(t->deg)) != 1 || t->deg < 0)
	{
		printf_s("It looks like you didn't enter numbers :(\n");
		return -1;
	}
	c = getchar();
	if (c != '\n')
	{
		printf_s("It looks like you entered more than numbers\n");
		return -1;
	}
	if (t->deg > N)
	{
		printf("Not enough memory");
		return -1;
	}
	printf("\n");

	//Коэффициенты полинома
	printf("Enter the coefficients of the polynomial:\n");
	for (int i = 0; i < (t->deg); i++)
	{
		printf("x%d - ", i + 1);
		if (scanf_s("%lf", &(t->odds[i])) != 1)
		{
			printf_s("It looks like you didn't enter numbers :(\n");
			return -1;
		}
		printf("\n");
	}
}


int getOper(int op)
{
	char c = 0;
	printf("Please enter the operator you want (1 = +, 2 = -, 3 = *, 4 = /): ");
	if (scanf_s("%d", &op) != 1 || op < 0)
	{
		printf_s("It looks like you didn't enter numbers :(\n");
		return -1;
	}
	c = getchar();
	if (c != '\n')
	{
		printf_s("It looks like you entered more than numbers\n");
		return -1;
	}

	return op;
}


int calculateResult(struct polynomial pol1, int op, struct polynomial pol2)
{
	//Сдвиг
	int shift = 0;
	if (pol1.deg > pol2.deg)
	{
		shift = pol1.deg - pol2.deg;
		for (int j = 0; j < shift; j++)	
		{
			for (int i = (pol2.deg - 1); i > 0; i--)
			{
				pol2.odds[i] = pol2.odds[i - 1];
			}
		}
	}
	/*if (pol1.deg < pol2.deg)
	{
		shift = pol2.deg - pol1.deg;
	}
	if (pol1.deg == pol2.deg)
	{
		shift = 0;
	}*/


	for (int i = 0; i < pol2.deg; i++)
	{
		printf("%d ", pol2.odds[i]);
	}




}
