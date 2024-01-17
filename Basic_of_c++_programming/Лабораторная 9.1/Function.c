#include <stdio.h>
#include <stdlib.h>
#include "LibPolynomial.h"
#define N 100

int getUserIput(struct polynomial* t)
{
	char c = 0;
	//������� ��������
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

	//������������ ��������
	printf("Enter the coefficients of the polynomial:\n");
	for (int i = (t->deg) - 1, j = 1; i >= 0; i--, j++)
	{
		printf("x%d - ", j);
		if (scanf_s("%lf", &(t->odds[i])) != 1)
		{
			printf_s("It looks like you didn't enter numbers :(\n");
			return -1;
		}
		printf("\n");
	}
	printf("\n");
	printf("\n");

	return 0;
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
	printf("\n");
	printf("\n");

	return op;
}

void calculateResult(struct polynomial pol1, int op, struct polynomial pol2, struct polynomial* pol3, struct polynomial* pol4)
{
	//��������
	if (op == 1)
	{
		if (pol1.deg > pol2.deg)
		{
			pol3->deg = pol1.deg;
			for (int i = (pol1.deg - 1), j = 0; i >= 0; i--, j++)
			{
				pol3->odds[j] = pol1.odds[i] + pol2.odds[i];
			}
		}
		if (pol1.deg < pol2.deg)
		{
			pol3->deg = pol2.deg;
			for (int i = (pol2.deg - 1), j = 0; i >= 0; i--, j++)
			{
				pol3->odds[j] = pol1.odds[i] + pol2.odds[i];
			}
		}
		if (pol1.deg == pol2.deg)
		{
			pol3->deg = pol1.deg;
			for (int i = (pol1.deg - 1), j = 0; i >= 0; i--, j++)
			{
				pol3->odds[j] = pol1.odds[i] + pol2.odds[i];
			}
		}
	}
	//���������
	if (op == 2)
	{
		if (pol1.deg > pol2.deg)
		{
			pol3->deg = pol1.deg;
			for (int i = (pol1.deg - 1), j = 0; i >= 0; i--, j++)
			{
				pol3->odds[j] = pol1.odds[i] - pol2.odds[i];
			}
		}
		if (pol1.deg < pol2.deg)
		{
			pol3->deg = pol2.deg;
			for (int i = (pol2.deg - 1), j = 0; i >= 0; i--, j++)
			{
				pol3->odds[j] = pol1.odds[i] - pol2.odds[i];
			}
		}
		if (pol1.deg == pol2.deg)
		{
			pol3->deg = pol1.deg;
			for (int i = (pol1.deg - 1), j = 0; i >= 0; i--, j++)
			{
				pol3->odds[j] = pol1.odds[i] - pol2.odds[i];
			}
		}
	}
	//���������
	if (op == 3)
	{
		pol3->deg = pol1.deg + pol2.deg;
		if (pol1.deg >= pol2.deg)
		{
			for (int i = 0; i < pol3->deg; i++)
			{
				pol3->odds[i] = 0.0;
			}
			for (int i = pol2.deg - 1, m = 0; i >= 0; i--, m++)
			{
				for (int j = pol1.deg - 1, n = 0; j >= 0; j--, n++)
				{
					pol3->odds[n + m] = (pol1.odds[j] * pol2.odds[i]) + pol3->odds[n + m];
				}
			}
		}
		if (pol1.deg < pol2.deg)
		{
			for (int i = 0; i < pol3->deg; i++)
			{
				pol3->odds[i] = 0.0;
			}
			for (int i = pol1.deg - 1, m = 0; i >= 0; i--, m++)
			{
				for (int j = pol2.deg - 1, n = 0; j >= 0; j--, n++)
				{
					pol3->odds[n + m] = (pol1.odds[j] * pol2.odds[i]) + pol3->odds[n + m];
				}
			}
		}
	}
	//�������
	if (op == 4)
	{
		struct polynomial pol1cop;
		struct polynomial pol2cop;
		pol1cop.deg = pol1.deg;
		pol2cop.deg = pol2.deg;
		if (pol1.deg > pol2.deg)
		{
			pol3->deg = pol1.deg - pol2.deg + 1;
			pol4->deg = pol1.deg + 1;
		}
		if (pol2.deg > pol1.deg)
		{
			pol3->deg = pol2.deg - pol1.deg + 1;
			pol4->deg = pol2.deg + 1;
		}
		for (int i = pol1.deg - 1, j = 0; i >= 0; i--, j++)
		{
			pol1cop.odds[j] = pol1.odds[i];
		}
		for (int i = pol2.deg - 1, j = 0; i >= 0; i--, j++)
		{
			pol2cop.odds[j] = pol2.odds[i];
		}
		for (int i = 0; i < pol1cop.deg + 1; i++)
		{
			pol4->odds[i] = pol1cop.odds[i];
		}
		for (int i = 0; i <= (pol1cop.deg - pol2cop.deg); i++)
		{
			pol3->odds[i] = pol4->odds[i] / pol2cop.odds[0];
			for (int j = i, h = 0; j <= (pol2cop.deg) + i; j++, h++)
			{
				pol4->odds[j] = pol4->odds[j] - (pol3->odds[i] * pol2cop.odds[h]);
			}
		}
	}
}

void insert_sero(struct polynomial* pol1, struct polynomial* pol2)
{
	int shift = 0;
	if (pol1->deg > pol2->deg)
	{
		shift = pol1->deg - pol2->deg;
		for (int i = pol1->deg - 1; i > pol1->deg - shift - 1; i--)
		{
			pol2->odds[i] = 0.0;
		}
	}
	if (pol2->deg > pol1->deg)
	{
		shift = pol2->deg - pol1->deg;
		for (int i = pol2->deg - 1; i > pol2->deg - shift - 1; i--)
		{
			pol1->odds[i] = 0.0;
		}
	}
}

void printResult(struct polynomial pol1, struct polynomial pol2, struct polynomial pol3, struct polynomial pol4, int op)
{
	printf("First polynomial:\n");
	for (int i = (pol1.deg - 1), j = pol1.deg; i >= 0; i--, j--)
	{
		printf("%.2lfX^%d ", pol1.odds[i], j);
	}
	printf("\n");
	printf("\n");
	printf("Second polynomial:\n");
	for (int i = (pol2.deg - 1), j = pol2.deg; i >= 0; i--, j--)
	{
		printf("%.2lfX^%d ", pol2.odds[i], j);
	}
	printf("\n");
	printf("\n");
	printf("Result polynomial:\n");
	for (int i = 0, j = pol3.deg; i < pol3.deg; i++, j--)
	{
		printf("%.2lfX^%d ", pol3.odds[i], j);
	}
	printf("\n");
	printf("\n");
	if (op == 4)
	{
		printf("The remainder is: ");
		for (int i = 0, j = pol4.deg; i < pol4.deg; i++, j--)
		{
			printf("%.2lfX^%d ", pol4.odds[i], j);
		}
	}
	printf("\n");
	printf("\n");
}


