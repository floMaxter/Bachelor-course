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
		cout << "������ �������� �����!" << endl;
	}
	else
	{
		for (int  i = 0; i < 5; i++)
		{
			cout << "������� �����" << endl;
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
		cout << "������ �������� �����!" << endl;
	}
	else
	{
		cout << "���� ������" << endl;
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