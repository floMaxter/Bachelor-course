#include <stdio.h>
#include "Header.h"

void derivative(unsigned int size, double* array, double* array_x)
{
	for (int i = 0, a = size; i < size; i++, a--)
	{
		array_x[i] = a * array[i];
	}
}

void composition(double* array3, double* array4, double* array_x, int size)
{
	for (int i = 0; i < size; i++)
	{
		array_x[i] = array3[i] * array4[i];
	}
}