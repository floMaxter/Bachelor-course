#include <stdio.h>
#include <ctype.h>
#define N 1000

//Ввод от пользователя
int getUserInput(char* arr)
{
	char c = 0;
	int i = 0;
	printf_s("Enter the string:\n");
	while ((c = getchar()) != '\n' && i < N - 1)
	{
		if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c == ' ' || c == '!' || c == ',' || c == '.' || c == '?' || c == '-')
		{
			arr[i] = c;
			i++;
		}
		else
		{
			return -1;
		}
	}
	arr[i] = '\0';
	printf_s("\n");

	return 0;
}
//Подсчет слов
int word_count(char* array)
{
	int in_word = 0, i = 0, word_count = 0;
	while (array[i] != 0)
	{
		if (array[i] != ' ')
		{
			in_word = 1;
		}
		else
		{
			if (in_word == 1)
			{
				word_count++;
			}
			in_word = 0;
		}
		i++;
	}
	if (in_word == 1)
	{
		word_count++;
	}

	return word_count;
}
//Разбиение строки на лексемы
char* getword(const char* line, char word[])
{
	static char* pEnd;

	if (word != NULL)
	{
		pEnd = NULL;
		int i = 0;

		while (word[i] != ' ')
		{
			i++;
		}
		word[i] = '\0';
		i++;
		pEnd = word[i];
	}
}

