#include "Header.h"
#include <iostream>
using namespace std;

int GetUserInput(IntModulo& First, IntModulo& Second, int& oper)			// ���� ����� � ��������������� �����
{
	int a = 0;
	int b = 0;
	int mod_a = 0;
	int mod_b = 0;

	cout << "������� ������ �����: " << endl;
	cin >> a;
	if (getchar() != '\n')
	{
		return -1;
	}
	
	cout << "������� ������ ������� �����: " << endl;
	cin >> mod_a;
	if (mod_a <= 0)
	{
		return -1;
	}
	if (getchar() != '\n')
	{
		return -1;
	}
	if (a < 0)
	{
		while (a < 0)
		{
			a += mod_a;
		}
	}
	First.SetNumber(a);
	First.SetMod(mod_a);


	cout << "������� ������ �����: " << endl;
	cin >> b;
	if (getchar() != '\n')
	{
		return -1;
	}

	cout << "������� ������ ������� �����: " << endl;
	cin >> mod_b;
	if (mod_b <= 0)
	{
		return -1;
	}
	if (getchar() != '\n')
	{
		return -1;
	}
	if (b < 0)
	{
		while (b < 0)
		{
			b += mod_b;
		}
	}
	Second.SetNumber(b);
	Second.SetMod(mod_b);

	cout << "������� �������������� ��������: 1 - '+', 2 - '-', 3 - '*'" << endl;
	cin >> oper;
	if (getchar() != '\n')
	{
		return -1;
	}


	return 0;
}

IntModulo Modulo_Calculator(IntModulo First, IntModulo Second, int oper)   //����������� �� ������
{
	IntModulo Res;
	int value = 0;
	int mod = 0;

		if (oper == 1)
		{
			Res = First.Addition(First, Second);
		}
		if (oper == 2)
		{
			Res = First.Subtraction(First, Second);
		}
		if (oper == 3)
		{
			Res = First.Multiplication(First, Second);
		}
	
		value = Res.GetNumber();
		mod = Res.GetMod();

		if (value < 0)
		{
			while (value < 0)
			{
				value += mod;
			}
		}

		Res.SetNumber(value);

	return Res;
}
																		//��������� �������, ��� ����������� - ������ 
int CompOfMod(IntModulo First, IntModulo Second, int oper)
{
	if (First.GetMod() == Second.GetMod())
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

																		//�������� 
IntModulo IntModulo::Addition(IntModulo First, IntModulo Second)
{
	IntModulo Res;
	int a = First.GetNumber();
	int b = Second.GetNumber();
	int p = First.GetMod();

	Res.SetMod(p);

	Res.SetNumber(((a % p) + (b % p)) % p);

	return Res;
}
																		//��������
IntModulo IntModulo::Subtraction(IntModulo First, IntModulo Second)
{
	IntModulo Res;
	int a = First.GetNumber();
	int b = Second.GetNumber();
	int p = First.GetMod();

	Res.SetMod(p);

	Res.SetNumber(((a % p) - (b % p)) % p);

	return Res;
}
																		//���������
IntModulo IntModulo::Multiplication(IntModulo First, IntModulo Second)
{
	IntModulo Res;
	int a = First.GetNumber();
	int b = Second.GetNumber();
	int p = First.GetMod();

	Res.SetMod(p);

	Res.SetNumber(((a % p) * (b % p)) % p);

	return Res;
}

																		//�����������
IntModulo::IntModulo()
{
	number = mod = 0;
}

void IntModulo::SetNumber(int value)
{
	this->number = value;
}

void IntModulo::SetMod(int mod)
{
	this->mod = mod;
}

int IntModulo::GetNumber()
{
	return number;
}

int IntModulo::GetMod()
{
	return mod;
}