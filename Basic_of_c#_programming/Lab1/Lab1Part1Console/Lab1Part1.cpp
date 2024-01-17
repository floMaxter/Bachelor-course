/*
Реализовать процедуры умножения беззнакового целого
числа (вводится с клавиатуры) число, равное степени 2, с использованием
побитовой операции сдвига влево <<. Выполнить проверку, что смещение
разряда не приведет к утрате исходных двоичных данных.
*/
#include <iostream>

bool isCorrectValue(int inputValue, int degree, int resultValue);

int main()
{
	register unsigned int inputValue = 0;
	register int degree = 0;
	register unsigned int result = 0;
	
	std::cout << "Enter unsigned integer value: ";
	std::cin >> inputValue;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cout << "Invalid data type" << std::endl;
		return -1;
	}
	
	std::cout << "Enter degree: ";
	std::cin >> degree;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cout << "Invalid data type" << std::endl;
		return -1;
	}

	result = inputValue << degree;
	std::cout << "Result: " << std::endl;
	std::cout << inputValue << " << " << degree << " = " << result << std::endl;

	if (isCorrectValue(inputValue, degree, result)) {
		std::cout << "Result is correct" << std::endl;
	}
	else {
		std::cout << "Result is incorrect" << std::endl;
	}
}

bool isCorrectValue(int inputValue, int degree, int resultValue) {
	if (resultValue != inputValue * pow(2, degree)) {
		std::cout << "Correct result = " << inputValue * pow(2, degree) << std::endl;
		return false;
	}
	return true;
}
