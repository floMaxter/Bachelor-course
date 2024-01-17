#pragma once

class IntModulo
{
public:
	IntModulo();

	IntModulo Addition(IntModulo First, IntModulo Second);
	IntModulo Subtraction(IntModulo First, IntModulo Second);
	IntModulo Multiplication(IntModulo First, IntModulo Second);

	void SetNumber(int value);
	int GetNumber();

	void SetMod(int mod);
	int GetMod();

private:
	int number;
	int mod;
};

int GetUserInput(IntModulo& First, IntModulo& Second, int& oper);							// ���� �� ������������ 

int CompOfMod(IntModulo First, IntModulo Second, int oper);									// ��������� �������

IntModulo Modulo_Calculator(IntModulo First, IntModulo Second, int oper);  // ����������� �� ������

