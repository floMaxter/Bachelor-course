#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "Header.h"
#define N 1000

/*�������� ������� char* getword(char* line, char word[]), ������� ��� ������  ��������� ��������� �� ������
��������� �����(word) � ���������� ���������  �� ���������� ����� ������ ��� NULL, ���� ������ �����, � �����������
��������� � ���.*/

int main()
{
	setlocale(LC_ALL, "Russian");
	char word[N] = { 0 };
	const char delim[] = " ";						//������ ������������, ������� ����� �������� �� /0
	int quan = 0, x = 0, tmp = 0;
	char* res = 0;										//����������, � ������� ����� ���������� ��������� ������ ������ ������
	int check = 0;

	//���� �� ������������
	tmp = getUserInput(word);
	if (tmp == -1)
	{
		printf_s("Error!\n");
		return -1;
	}
	//������� ����
	quan = word_count(word);
	if (quan == 0)
	{
		printf_s("There are no words in the line :(");
		printf_s("\n");
		return -1;
	}
	//��������� ������ �� �������
	printf_s("�������� ������:\n");
	for (int i = 0; i < N; i++)
	{
		printf_s("%c", word[i]);
	}

	printf_s("��������� ���������:\n");
	
	res = getword(delim, word);

	while (res != NULL)
	{
		//����� ����� ������
		printf_s("%s\n", res);
		//��������� ��������� ����� ������
		res = getword(delim, NULL);
	}

	
	
	return 0;
}