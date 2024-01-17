#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

int main()
{
	struct polynomial pol1, pol2;
	int deg1, deg2;
	int tmp = 0;

	tmp = getUserIput(&pol1, &deg1);
	if (tmp == -1)
	{
		printf("Error!");
		printf("\n");
	}
	tmp = getUserIput(&pol2, &deg2);
	if (tmp == -1)
	{
		printf("Error!");
		printf("\n");
	}

	init(&pol1, deg1);
	init(&pol2, deg2);
	printf("Enter mas1:\n");
	enter_the_array(&pol1, deg1);
	printf("Enter mas2:\n");
	enter_the_array(&pol2, deg2);
	struct polynomial summ = sum(&pol1, &pol2);
	printf("Sum:\n");
	print(&summ, (maxy(deg1, deg2) + 1));
	struct polynomial TDG = sub(&pol1, &pol2);
	printf("\nSub:\n");
	print(&TDG, (maxy(deg1, deg2) + 1));
	struct polynomial mul = multiplication(&pol1, &pol2);
	printf("\nMultiplication\n");
	print(&mul, (deg1 + deg2 + 1));
	if (deg1 <= deg2)
	{
		printf("\nDividing Is Impossible\n");
	}
	else
	{
		struct polynomial HU = divide_partial_quotient(&pol1, &pol2);
		printf("\nDivide Partial Quotient\n");
		print(&HU, (deg1 - deg2 + 1));
		struct polynomial BVB = divide_remainder(&pol1, &pol2);
		printf("\nDividing Remainder\n");
		print(&BVB, (deg1 + 1));
		destroy(&HU);
		destroy(&BVB);
	}
	destroy(&summ);
	destroy(&TDG);
	destroy(&mul);
	destroy(&pol1);
	destroy(&pol2);

	return 0;
}
