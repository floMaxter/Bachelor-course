#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "Header.h"
#define N 1000

/*Написать функцию char* getword(char* line, char word[]), которая при каждом  обращении извлекает из строки
очередное слово(word) и возвращает указатель  на оставшуюся часть строки или NULL, если строка пуста, и тестирующую
программу к ней.*/

int main()
{
	setlocale(LC_ALL, "Russian");
	char word[N] = { 0 };
	const char delim[] = " ";						//Массив разделителей, которые нужно заменить на /0
	int quan = 0, x = 0, tmp = 0;
	char* res = 0;										//Переменная, в которую будут заноситься начальные адреса частей строки
	int check = 0;

	//Ввод от пользователя
	tmp = getUserInput(word);
	if (tmp == -1)
	{
		printf_s("Error!\n");
		return -1;
	}
	//Подсчет слов
	quan = word_count(word);
	if (quan == 0)
	{
		printf_s("There are no words in the line :(");
		printf_s("\n");
		return -1;
	}
	//Разбиение строки на лексемы
	printf_s("Исходная строка:\n");
	for (int i = 0; i < N; i++)
	{
		printf_s("%c", word[i]);
	}

	printf_s("Результат разбиения:\n");
	
	res = getword(delim, word);

	while (res != NULL)
	{
		//Вывод части строки
		printf_s("%s\n", res);
		//Выделение следующей части строки
		res = getword(delim, NULL);
	}

	
	
	return 0;
}