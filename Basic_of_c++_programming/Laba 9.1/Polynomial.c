#include <stdio.h>
#include "LibPolynomial.h"
int main()
{
	char c = 0;
	struct polynomial pol1;
	struct polynomial pol2;
	int op = 0;

	//������ �������
	getUserIput(&pol1);

	//������ �������
	getUserIput(&pol2);

	//�������������� ����
	op = getOper(op);
	if(op == -1)
	{
		return -1;
	}
	printf_s("%d", op);
	
	//���������� ����������
	calculateResult(pol1, op, pol2);

	//����� ����������

	return 0;
}