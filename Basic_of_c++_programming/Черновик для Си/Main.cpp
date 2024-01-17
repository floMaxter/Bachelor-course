#include <iostream>
#include <string>
#include <locale>
#include <fstream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	string path = "myFile.txt";
	/*ofstream fout;
	
	fout.open(path, ofstream::app);

	if (!fout.is_open())
	{
		cout << "Ошибка открытия файла!" << endl;
	}
	else
	{
		for (int  i = 0; i < 5; i++)
		{
			cout << "Введите число" << endl;
			int a = 0;
			cin >> a;
			fout << a;
			fout << "\n";
		}
		
	}
	fout.close();*/

	ifstream fin;
	fin.open(path);
	
	if (!fin.is_open())
	{
		cout << "Ошибка открытия файла!" << endl;
	}
	else
	{
		cout << "Файл открыт" << endl;
		//string str;

		char str[50];

		while (!fin.eof())
		{	
			fin.getline(str, 50);

			cout << str << endl;  
		}
	}

	fin.close();
	
	
	return 0;
}