#include <stdio.h>
#define N 100
/*Ввести степени и коэффициенты двух многочленов. Вывести коэффициенты многочлена,
равного произведению производных от введенных многочленов.*/

int main()
{
	unsigned int deg1 = 0;
	unsigned int deg2 = 0;
	int coef1[N] = { 0 };
	int coef2[N] = { 0 };
	char c = 0;

	// запись первого полинома
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
	printf("\n");
	printf("Enter the coefficients of the first polynomial:\n");

	for (int i = 0; i < deg1; i++)
	{
		printf("x%d - ", i + 1);
		if (scanf_s("%d", &coef1[i]) != 1)
		{
			printf_s("It looks like you didn't enter numbers :(\n");
			return 2;
		}
		printf("\n");
	}
	// запись второго полинома
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
	printf("\n");

	printf("Enter the coefficients of the first polynomial:\n");
	for (int i = 0; i < deg2; i++)
	{
		printf("x%d - ", i + 1);
		if (scanf_s("%d", &coef2[i]) != 1)
		{
			printf_s("It looks like you didn't enter numbers :(\n");
			return 2;
		}
		printf("\n");
	}



	return 0;
}