/*Написать функцию нахождения в массиве вещественных чисел числа с наименьшей дробной частью (дробная часть всегда положительна).*/
/*Написать функцию, которая считает среднее арифметического всех дробных чисел.*/
#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000

double find_frac(double* str, int asize);
double find_average(double* str, int asize);

int main()
{
	int size = 0;
	char c = 0;
	double* frac = 0;

	printf("How many real numbers do you want to enter: ");
	if (scanf_s("%d", &size) != 1 || size < 0)
	{
		printf_s("Looks like you didn't enter numbers :(");
		return 2;
	}
	c = getchar();
	if (c != '\n')
	{
		printf_s("It looks like you entered more than numbers.");
		return 2;
	}
	if (size > MAXLINE)
	{
		printf("Not enough storage.");
		return 2;
	}

	frac = (double*)malloc(size * sizeof(double));
	if (frac == 0)
	{
		printf("Oops!Not enough memory!\n");
		return -1;
	}

	printf("Enter real numbers: ");
	for (int i = 0; i < size; i++)
	{
		if (scanf_s("%lf", &frac[i]) != 1)
		{
			printf_s("Looks like you didn't enter numbers :(");
			return 2;
		}
	}
	printf("%2.2f\n", find_frac(frac, size));
	printf("%2.4f\n", find_average(frac, size));

	free(frac);
	return 0;
}

double find_frac(double* str, int asize) // функция поиска наименьшей дробной части
{
	double min = 9.9;
	double number = 0;
	double temp = 0;
	for (int i = 0; i < asize; i++)
	{
		temp = str[i];
		if (temp < 0)
		{
			temp = -str[i];
		}
		if (temp - (int)temp < min)
		{
			min = temp - (int)temp;
			number = str[i];
		}
	}
	return number;
}

double find_average(double* str, int asize) // функция поиска среднего арифметического по дробной части
{
	double sum = 0;
	double average = 0;
	double temp = 0;
	for (int i = 0; i < asize; i++)
	{
		temp = str[i];
		if (temp < 0)
		{
			temp = -temp;
		}
		sum += (temp - (int)temp);
	}
	average = sum / asize;

	return average;
}