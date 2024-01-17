#include<iostream>

int main()
{
	setlocale(LC_ALL, "ru");

	int* p = new int[1];
	int* p2;
	int value = 0;
	int size = 0;

	
	while (value >= 0)
	{
		std::cout << "¬ведите целое число: ";
		std::cin >> value;
		if (value < 0)
		{
			break;
		}

		if (size == 0)
		{
			p[size] = value;
			std::cout << p[size] << std::endl;
			size++;
		}
		else 
		{
			p2 = new int[size + 1];
			for (int i = 0; i < size; i++)
			{
				p2[i] = p[i];
			}
			p2[size] = value;

			delete[] p;

			p = new int[size + 1];
			for (int i = 0; i < size + 1; i++)
			{
				p[i] = p2[i];
				std::cout << p[i] << " ";
			}
			std::cout << std::endl;
			delete[] p2;
			size++;
		}
	}

	delete[] p;

	return 0;
}