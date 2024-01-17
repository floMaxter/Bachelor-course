#include <stdio.h>
#include <ctype.h>
#include <locale.h>
#include "Header.h"
#define N 100
/*Написать функцию для перевода введенной строки в число типа long и тестирующую программу к ней.
Строка может содержать десятичное, восьмеричное и шестнадцатеричное представление числа.*/
/*Доп. на вход пишутся числа с началом 0b - двоичная,  0 - восьмеричная, 0х - шестнадцатеричная, функция
должна обработать эти значения*/

int main() {
	setlocale(LC_ALL, "Rus");
	char numbers[N] = { 0 };
	char pEnd = 0;
	int basis = 0, quan = 0, x = 1;
	long int res = 0;
	char c = 0;
	int i = 0;
	int get = 0;
	int size = 0;

	printf("Сколько чисел будет введено?\n");
	if (scanf_s("%d", &quan) != 1 || quan < 0)
	{
		printf_s("Похоже вы ввели не цифры :(\n");
		return 2;
	}
	c = getchar();
	if (c != '\n')
	{
		printf_s("Похоже вы ввели не только цифры\n");
		return 2;
	}	
	if (quan > N)
	{
		printf("Не хватает памяти\n");
		return 2;
	}
	printf("\n");

	printf("Введите строку:\n");
	while ((c = getchar()) != '\n' && i < N - 1) {
		numbers[i] = c;
		i++;
	}
	numbers[i] = '\0';
	printf("\n");

	while (x <= quan) {
		printf("В какой системе счисления число %d?\n", x);
		if (scanf_s("%d", &basis) != 1 || basis < 0)
		{
			printf_s("Похоже вы ввели не цифры :(\n");
			return 2;
		}
		c = getchar();
		if (c != '\n')
		{
			printf_s("Похоже вы ввели не только цифры\n");
			return 2;
		}
		if (basis == 16) {
			printf("Сколько символов в числе?\n");
			if (scanf_s("%d", &size) != 1 || size < 0)
			{
				printf_s("Похоже вы ввели не цифры :(\n");
				return 2;
			}
			c = getchar();
			if (c != '\n')
			{
				printf_s("Похоже вы ввели не только цифры\n");
				return 2;
			}
		}
		res = strol(numbers, &pEnd, basis, size);
		printf("Result: %ld\n", res);
		x++;
		printf("\n");
	}

	return 0;
}