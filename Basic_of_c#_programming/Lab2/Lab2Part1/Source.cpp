#include <iostream>

extern "C" void logic_shift_left_ASM(void);
extern "C" unsigned int value_asm = 0;
extern "C" unsigned int multiplier_asm = 0;
extern "C" unsigned int res_asm = 0;

int inputInt(const char*, int);
bool isDegreeNumberTwo(int);

unsigned int Logical_Left_Shift_CPP(int value, int multiplier) {
	return value * multiplier;
}

int main() {
	register unsigned int inputValue = inputInt("Enter unsigned value: ", USHRT_MAX);
	register int multiplier = inputInt("Enter multiplier equal to a power of two: ", INT_MAX);
	while (!isDegreeNumberTwo(multiplier)) {
		std::cout << "The number isn't equal to a power of two. Try again!" << std::endl;
		multiplier = inputInt("Enter multiplier equal to a power of two: ", INT_MAX);
	}
	register unsigned int result = 0;

	std::cout << "(C++): result = " << Logical_Left_Shift_CPP(inputValue, multiplier) << std::endl;
	value_asm = inputValue;
	multiplier_asm = multiplier;
	logic_shift_left_ASM();
	std::cout << "(ASM) result = " << res_asm << std::endl;
}

int inputInt(const char* message, int max) {
	int value = 0;
	while (true) {
		std::cout << message << std::flush;
		if ((std::cin >> value).good() && (value >= 0) && (value <= max)) {
			return value;
		}
		if (std::cin.fail()) {
			std::cin.clear();
			std::cout << "Invalid data! Try again:" << std::endl;
		}
		else {
			std::cout << "The number is out of range. Try again:" << std::endl;
		}
        std::cin.ignore(100,'\n');
	}
}

bool isDegreeNumberTwo(int value) {
	return value > 0 && (value & -value) == value;
}
