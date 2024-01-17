#include <stdio.h>
#include "LibPolynomial.h"
/*������ ������� � ������������ ���� �����������. ������� ������������ ����������,
������� ������������ ����������� �� ��������� �����������.*/
/*����������� ���������� ��� ������ � ������������, ��������� � ��������������, �� ��������,��������������,
�������������� �������� ��� ������������, ���������� ���������*/

int main()
{
	char c = 0;
	struct polynomial pol1; // ������ �������
	struct polynomial pol2; // ������ ������� 
	struct polynomial pol3; // �������, ������� ���������� � ����������
	struct polynomial pol4; // ������� �� ������� 
	int op = 0;
	

	//������ �������
	if (getUserIput(&pol1) == -1)
	{
		return -1;
	}

	//������ �������
	if (getUserIput(&pol2) == -1)
	{
		return -1;
	}

	//�������������� ����
	op = getOper(op);
	if (op == -1)
		{
			return -1;
		}

	//������� �����
	insert_sero(&pol1, &pol2);

	//�������������� ��������	
	calculateResult(pol1, op, pol2, &pol3, &pol4);

	//����� ����������
	printResult(pol1, pol2, pol3, pol4, op);




	return 0;
}