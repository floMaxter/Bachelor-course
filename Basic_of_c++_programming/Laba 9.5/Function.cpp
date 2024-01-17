#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

int getUserIput(struct polynomial* pol, int* deg)
{
	char c = 0;

	//Степень полинома
	printf("What is the degree of the polynomial: ");
	if (scanf_s("%d", &(pol->deg)) != 1 || pol->deg < 0)
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
	return 0;
}

int enter_the_array(struct polynomial* pol, int len)
{

	for (int i = 0; i < (len + 1); i++)
	{
		if ((scanf_s("%f", &pol->mas[i]) != 1) || (getchar() != '\n'))
		{
			printf("Error Of Arr");
			return -1;
		}
	}

	return 0;
}

void init(struct polynomial* pol, int n)
{
	pol->mas = (float*)malloc(sizeof(float) * (n + 2));
	pol->deg = n;
	for (int i = 0; i < n; i++)
		pol->mas[i] = 0.0;
}

void destroy(struct polynomial* pol)
{
	if (pol->deg > 0)
	{
		free(pol->mas);
		pol->deg = 0;
	}
}

int maxy(int a, int b)
{
	if (a == b)
		return a;
	else
		return a > b ? a : b;
}

struct polynomial sub(struct polynomial* pol1, struct polynomial* pol2)
{
	struct polynomial fad;
	init(&fad, maxy(pol1->deg, pol2->deg));
	if (pol1->deg > pol2->deg)
	{
		for (int i = 0; i < (pol1->deg - pol2->deg); i++)
		{
			fad.mas[i] = pol1->mas[i];
		}
		int j = 0;
		for (int i = 0; i <= pol2->deg; i++)
		{
			fad.mas[(pol1->deg - pol2->deg) + i] = pol1->mas[pol1->deg - pol2->deg + j] - pol2->mas[i];
			j++;
		}
	}
	if (pol1->deg < pol2->deg)
	{
		for (int i = 0; i < (pol2->deg - pol1->deg); i++)
		{
			fad.mas[i] = pol2->mas[i] * (-1);
		}
		int j = 0;
		for (int i = 0; i <= pol1->deg; i++)
		{
			fad.mas[(pol2->deg - pol1->deg) + i] = pol1->mas[i] - pol2->mas[(pol2->deg - pol1->deg) + i];
			j++;
		}
	}
	if (pol1->deg == pol2->deg)
	{
		for (int i = 0; i <= (pol1->deg + 2); i++)
		{
			fad.mas[i] = pol1->mas[i] - pol2->mas[i];
		}
	}
	return fad;
}

struct polynomial sum(struct polynomial* pol1, struct polynomial* pol2)
{
	struct polynomial fad;
	init(&fad, maxy(pol1->deg, pol2->deg));
	if (pol1->deg > pol2->deg)
	{
		for (int i = 0; i < (pol1->deg - pol2->deg); i++)
		{
			fad.mas[i] = pol1->mas[i];
		}
		int j = 0;
		for (int i = 0; i <= pol2->deg; i++)
		{
			fad.mas[(pol1->deg - pol2->deg) + i] = pol1->mas[pol1->deg - pol2->deg + j] + pol2->mas[(pol1->deg - pol2->deg) - (pol1->deg - pol2->deg) + i];
			j++;
		}
	}
	if (pol1->deg < pol2->deg)
	{
		for (int i = 0; i < (pol2->deg - pol1->deg); i++)
		{
			fad.mas[i] = pol2->mas[i];
		}
		int j = 0;
		for (int i = 0; i <= pol1->deg; i++)
		{
			fad.mas[(pol2->deg - pol1->deg) + i] = pol2->mas[pol2->deg - pol1->deg + j] + pol1->mas[(pol2->deg - pol1->deg) - (pol2->deg - pol1->deg) + i];
			j++;
		}
	}
	if (pol1->deg == pol2->deg)
	{
		for (int i = 0; i <= (pol1->deg + 2); i++)
		{
			fad.mas[i] = pol1->mas[i] + pol2->mas[i];
		}
	}
	return fad;
}

int miny(int a, int b)
{
	if (a == b)
		return a;
	else
		return a < b ? a : b;
}
struct polynomial divide_remainder(struct polynomial* pol1, struct polynomial* pol2)//остаток от деления
{
	struct polynomial hate; // остаток
	struct polynomial fad; // неполное частное
	init(&hate, pol1->deg + 1);
	init(&fad, (pol1->deg - pol2->deg) + 1);
	for (int i = 0; i < (pol1->deg + 1); i++)
	{
		hate.mas[i] = pol1->mas[i];
	}
	for (int i = 0; i <= (pol1->deg - pol2->deg); i++)
	{
		fad.mas[i] = hate.mas[i] / pol2->mas[0];
		int h = 0;
		for (int j = i; j <= (pol2->deg) + i; j++)
		{
			hate.mas[j] = hate.mas[j] - (fad.mas[i] * pol2->mas[h]);
			h++;
		}
	}
	destroy(&fad);
	return hate;
}
struct polynomial divide_partial_quotient(struct polynomial* pol1, struct polynomial* pol2) // целая часть
{
	struct polynomial hate; // остаток
	struct polynomial fad; // неполное частное
	init(&hate, pol1->deg + 1);
	init(&fad, (pol1->deg - pol2->deg) + 1);
	for (int i = 0; i < (pol1->deg + 1); i++)
	{
		hate.mas[i] = pol1->mas[i];
	}
	for (int i = 0; i <= (pol1->deg - pol2->deg); i++)
	{
		fad.mas[i] = hate.mas[i] / pol2->mas[0];
		int h = 0;
		for (int j = i; j <= (pol2->deg) + i; j++)
		{
			hate.mas[j] = hate.mas[j] - (fad.mas[i] * pol2->mas[h]);
			h++;
		}
	}
	destroy(&hate);
	return fad;
}

struct polynomial multiplication(struct polynomial* pol1, struct polynomial* pol2)
{
	struct polynomial fad;
	init(&fad, (pol1->deg + pol2->deg + 1));
	if (pol1->deg >= pol2->deg)
	{
		for (int i = 0; i < (pol1->deg + 1); i++)
		{
			fad.mas[i] = pol1->mas[i] * pol2->mas[0];
		}
		for (int i = 1; i < (pol2->deg + 1); i++)
		{

			for (int j = 0; j < (pol1->deg + 1); j++)
			{
				fad.mas[j + i] = (pol1->mas[j] * pol2->mas[i]) + fad.mas[j + i];
			}
		}
	}
	if (pol1->deg < pol2->deg)
	{
		for (int i = 0; i < (pol2->deg + 1); i++)
		{
			fad.mas[i] = pol2->mas[i] * pol1->mas[0];
		}
		for (int i = 1; i < (pol1->deg + 1); i++)
		{
			int j = 0;

			for (; j < (pol2->deg + 1); j++)
			{
				fad.mas[j + i] = (pol2->mas[j] * pol1->mas[i]) + fad.mas[j + i];

			}
		}
	}
	return fad;
}

void print(struct polynomial* fad, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf_s("%0.2f ", fad->mas[i]);
	}
}
