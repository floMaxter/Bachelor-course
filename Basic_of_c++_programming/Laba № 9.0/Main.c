#include <stdio.h>
#include "Header.h"
#define N 100
/*Ввести степени и коэффициенты двух многочленов. Вывести коэффициенты многочлена,
равного произведению производных от введенных многочленов.*/
/*Разработать библиотеку для работы с многочленами, структура с инициализацией, со степенью,коэффициентами,
арифметические действия над многочленами, разрушение структуры*/

int main()
{
	unsigned int deg1 = 0;
	unsigned int deg2 = 0;
	double coef1[N] = { 0 }; // первый полином 
	double coef2[N] = { 0 }; // второй полином 
	double coef3[N] = { 0 }; // производная первого полинома
	double coef4[N] = { 0 }; // производная второго полинома
	double coef_x[N] = { 0 }; // коэффициенты искомого полинома
	int size = 0;
	char c = 0;
	// Степень первого полинома
	printf("What is the degree of the first polynomial: ");
	if (scanf_s("%d", &deg1) != 1 || deg1 < 0)
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
	if (deg1 > N)
	{
		printf("Not enough memory");
		return -1;
	}
	printf("\n");
	// Степень второго полинома
	printf("What is the degree of the second polynomial: ");
	if (scanf_s("%d", &deg2) != 1 || deg2 < 0)
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
	if (deg2 > N)
	{
		printf("Not enough memory");
		return -1;
	}
	printf("\n");

	if (deg1 > deg2)
	{
		// коэффициенты первого
		printf("Enter the coefficients of the first polynomial:\n");
		for (int i = 0; i < deg1; i++)
		{
			printf("x%d - ", i + 1);
			if (scanf_s("%lf", &coef1[i]) != 1)
			{
				printf_s("It looks like you didn't enter numbers :(\n");
				return -1;
			}
			printf("\n");
		}
		// коэффициенты второго
		printf("Enter the coefficients of the second polynomial:\n");
		for (int i = (deg1 - deg2), j = 1; i < deg1; i++, j++)
		{
			printf("x%d - ", j);
			if (scanf_s("%lf", &coef2[i]) != 1)
			{
				printf_s("It looks like you didn't enter numbers :(\n");
				return -1;
			}
			printf("\n");
		}
		derivative(deg1, coef1, coef3);
		derivative(deg1, coef2, coef4);
		size = deg1;
		for (int j = 0; j < deg1; j++)
		{
			printf("%.2lf ", coef1[j]);
		}
		printf("\n");
		for (int j = 0; j < deg1; j++)
		{
			printf("%.2lf ", coef2[j]);
		}
		printf("\n");
		printf("\n");
	}
	if (deg1 < deg2)
	{
		// коэффициенты первого
		printf("Enter the coefficients of the first polynomial:\n");
		for (int i = (deg2 - deg1), j = 1; i < deg2; i++, j++)
		{
			printf("x%d - ", j);
			if (scanf_s("%lf", &coef1[i]) != 1)
			{
				printf_s("It looks like you didn't enter numbers :(\n");
				return -1;
			}
			printf("\n");
		}
		// коэффициенты второго
		printf("Enter the coefficients of the second polynomial:\n");
		for (int i = 0; i < deg2; i++)
		{
			printf("x%d - ", i + 1);
			if (scanf_s("%lf", &coef2[i]) != 1)
			{
				printf_s("It looks like you didn't enter numbers :(\n");
				return -1;
			}
			printf("\n");
		}
		derivative(deg2, coef1, coef3);
		derivative(deg2, coef2, coef4);
		size = deg2;
		for (int j = 0; j < deg2; j++)
		{
			printf("%.2lf ", coef1[j]);
		}
		printf("\n");
		for (int j = 0; j < deg2; j++)
		{
			printf("%.2lf ", coef2[j]);
		}
		printf("\n");
		printf("\n");
	}
	if (deg1 == deg2)
	{
		// коэффициенты первого
		printf("Enter the coefficients of the first polynomial:\n");
		for (int i = 0; i < deg1; i++)
		{
			printf("x%d - ", i + 1);
			if (scanf_s("%lf", &coef1[i]) != 1)
			{
				printf_s("It looks like you didn't enter numbers :(\n");
				return -1;
			}
			printf("\n");
			printf("\n");
		}
		// коэффициенты второго
		printf("Enter the coefficients of the second polynomial:\n");
		for (int i = 0; i < deg2; i++)
		{
			printf("x%d - ", i + 1);
			if (scanf_s("%lf", &coef2[i]) != 1)
			{
				printf_s("It looks like you didn't enter numbers :(\n");
				return -1;
			}
			printf("\n");
			printf("\n");
		}
		derivative(deg1, coef1, coef3);
		derivative(deg2, coef2, coef4);
		size = deg1;
		for (int j = 0; j < deg1; j++)
		{
			printf("%.2lf ", coef1[j]);
		}
		printf("\n");
		for (int j = 0; j < deg2; j++)
		{
			printf("%.2lf ", coef2[j]);
		}
		printf("\n");
		printf("\n");
	}

	composition(coef3, coef4, coef_x, size);

	// Вывод коэффициентов при искомом полиноме
	for (int j = 0; j < size; j++)
	{
		int a = j;
		double res = coef_x[j];
		if (res != 0)
		{
			printf("x%d -> %.2lf\n", a + 1, res);
		}
		else
		{
			a++;
		}
	}

	return 0;
}