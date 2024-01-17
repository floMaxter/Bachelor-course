#include <stdio.h>
#include <ctype.h>
#include <locale.h>
#include "Header.h"
#define N 100

long int strol(char* str, char* pEnd, int basis, int size) {
	int i = 0, n = 0, sign = 0;
	i = *pEnd;

	for (i; isspace(str[i]); i++) {
	};

	sign = (str[i] == '-') ? -1 : 1;

	if (str[i] == '+' || str[i] == '-') {
		i++;
	}

	if (basis == 10) {
		for (n = 0; isdigit(str[i]); i++) {
			n = 10 * n + (str[i] - '0');
		}
	}
	if (basis == 8) {
		for (n = 0; isdigit(str[i]); i++) {
			n = 8 * n + (str[i] - '0');
		}
	}
	if (basis == 16)
	{
		int sum = 0;
		int j = 0;
		int tmp = i;
		char c = 0;

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
			default: printf("Вы ввели не число\n"); break;
			}
		}
		i = tmp + size;
	}

	*pEnd = i;

	return sign * n;
}

int power(int base, int n) {
	int i = 1, p = 1;
	for (i = 1; i <= n; ++i) {
		p = p * base;
	}
	return p;
}





