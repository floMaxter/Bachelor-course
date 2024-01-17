#include <iostream>
#include <locale>
#include "Header.h"
using namespace std;

/*�������� ����� � ������ IntModulo ��� ���������� �������� � ������ �� ������ P, ���������� � ������������.*/

int main()
{
	setlocale(LC_ALL, "Ru");
	int tmp = 0;
	int oper = 0;																		// �������������� ����
	IntModulo A;
	IntModulo B;
	IntModulo Result;

	tmp = GetUserInput(A, B, oper);														// ���� �� ������������
	if (tmp == -1)
	{
		cout << endl;
		cout << "������" << endl;
		return -1;
	}

	tmp = CompOfMod(A, B, oper);													    //�������� ������� �� ���������
	if (tmp == -1)
	{
		cout << endl;
		cout << "�� �� ����� ������ �������� ��� ������� �� ������� ������" << endl;
		return -1;
	}
	if (oper == 1 || oper == 2 || oper == 3)
	{
		Result = Modulo_Calculator(A, B, oper);											//����������� �� ������
		
		cout << endl;
		cout << "��������� ����� " << Result.GetNumber() << " �� ������ " << Result.GetMod() << endl;
	}
	else
	{
		cout << endl;
		cout << "������, �������� ����" << endl;
		return -1;
	}

	
	int m = 0;
	m = m;

	return 0;
}