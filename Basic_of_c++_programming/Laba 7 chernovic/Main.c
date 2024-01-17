#include <stdio.h>
#include <ctype.h>
#include <locale.h>
#include "Header.h"
#define N 100
/*�������� ������� ��� �������� ��������� ������ � ����� ���� long � ����������� ��������� � ���.
������ ����� ��������� ����������, ������������ � ����������������� ������������� �����.*/
/*���. �� ���� ������� ����� � ������� 0b - ��������,  0 - ������������, 0� - �����������������, �������
������ ���������� ��� ��������*/

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

	printf("������� ����� ����� �������?\n");
	if (scanf_s("%d", &quan) != 1 || quan < 0)
	{
		printf_s("������ �� ����� �� ����� :(\n");
		return 2;
	}
	c = getchar();
	if (c != '\n')
	{
		printf_s("������ �� ����� �� ������ �����\n");
		return 2;
	}	
	if (quan > N)
	{
		printf("�� ������� ������\n");
		return 2;
	}
	printf("\n");

	printf("������� ������:\n");
	while ((c = getchar()) != '\n' && i < N - 1) {
		numbers[i] = c;
		i++;
	}
	numbers[i] = '\0';
	printf("\n");

	while (x <= quan) {
		printf("� ����� ������� ��������� ����� %d?\n", x);
		if (scanf_s("%d", &basis) != 1 || basis < 0)
		{
			printf_s("������ �� ����� �� ����� :(\n");
			return 2;
		}
		c = getchar();
		if (c != '\n')
		{
			printf_s("������ �� ����� �� ������ �����\n");
			return 2;
		}
		if (basis == 16) {
			printf("������� �������� � �����?\n");
			if (scanf_s("%d", &size) != 1 || size < 0)
			{
				printf_s("������ �� ����� �� ����� :(\n");
				return 2;
			}
			c = getchar();
			if (c != '\n')
			{
				printf_s("������ �� ����� �� ������ �����\n");
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