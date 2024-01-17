#include <stdio.h>
#include <ctype.h>
#include <locale.h>
#include "Header.h"
#define N 100

long int strol(char* str, char* pEnd) {
	int i = 0, n = 0, sign = 0;
	i = *pEnd;

	for (i; isspace(str[i]); i++) {
	};

	sign = (str[i] == '-') ? -1 : 1;

	if (str[i] == '+' || str[i] == '-') {
		i++;
	}
	// десятичная система счисления
	if (str[i] >= '1' && str[i] <= '9')
	{
		int count = i;
		int tmp = i;

		while ((str[count] >= '0' && str[count] <= '9') || (str[count] >= 'a' && str[count <= 'z']) || (str[count] >= 'A' && str[count] <= 'Z'))
		{
			count++;
		}
		
		for (n = 0; i < count ; i++)
		{
			if (str[i] >= '0' && str[i] <= '9')
			{
				n = 10 * n + (str[i] - '0');
			}
			else
			{
				return -1;
			}
		}
	}
	// восьмеричная система
	else if (str[i] == '0' && str[i+1] != 'x')
	{
		int count = i;
		int tmp = i;

		while ((str[count] >= '0' && str[count] <= '9') || (str[count] >= 'a' && str[count <= 'z'])
			    || (str[count] >= 'A' && str[count] <= 'Z'))
		{
			count++;
		}

		for (n = 0; i < count; i++)
		{
			if (str[i] >= '0' && str[i] <= '7')
			{
				n = 8 * n + (str[i] - '0');
			}
			else
			{
				return -1;
			}
		}
	}
	// шестнадцатеричная система
	else if (str[i] == '0' && str[i + 1] == 'x')
	{
		i = i + 2;
		int size = 0;
		int sum = 0;
		int j = 0;
		int tmp = i;
		int count = i;
		char c = 0;

		while (str[count] != ' ' && str[count] != '\0') {
			count++;
		}
		size = count - tmp;

		for (j = 0, i = (i + (size - 1)); i >= tmp; j++, i--)
		{
			switch (str[i])
			{
			case '0': n = n + (str[i] - '0') * power(16, j); break;
			case '1': n = n + (str[i] - '0') * power(16, j); break;
			case '2': n = n + (str[i] - '0') * power(16, j); break;
			case '3': n = n + (str[i] - '0') * power(16, j); break;
			case '4': n = n + (str[i] - '0') * power(16, j); break;
			case '5': n = n + (str[i] - '0') * power(16, j); break;
			case '6': n = n + (str[i] - '0') * power(16, j); break;
			case '7': n = n + (str[i] - '0') * power(16, j); break;
			case '8': n = n + (str[i] - '0') * power(16, j); break;
			case '9': n = n + (str[i] - '0') * power(16, j); break;
			case 'A': n = n + 10 * power(16, j); break;
			case 'B': n = n + 11 * power(16, j); break;
			case 'C': n = n + 12 * power(16, j); break;
			case 'D': n = n + 13 * power(16, j); break;
			case 'E': n = n + 14 * power(16, j); break;
			case 'F': n = n + 15 * power(16, j); break;
			default: 
				return -1;
				break;
			}
		}
		i = tmp + size;
	}
	else
    {
		return -1;
	}
	*pEnd = i;

	return sign * n;
}

int power(int base, int n)
{
	int i = 1, p = 1;
	for (i = 1; i <= n; ++i)
	{
		p = p * base;
	}
	return p;
}