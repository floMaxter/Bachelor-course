 #include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
using namespace std;

/*class Point
{
public:
	Point()
	{
		x = y = z = 0;
	}

	Point(int x, int y, int z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

private:
	int x;
	int y;
	int z;

	friend ostream& operator<<(ostream& os, const Point& point);
	friend istream& operator>> (istream& is, Point& point);

};

ostream& operator<<(ostream& os, const Point& point)
{
	os << point.x << " " << point.y << " " << point.z;
	return os;
}
 
istream& operator>> (istream& is, Point& point)
{
	is >> point.x >> point.y >> point.z;
	return is;
}*/



int main()
{
	setlocale(LC_ALL, "ru");

	string path = "myFile.txt";

	/*Point point(142, 754, 8956);

	ofstream fout;	
	fout.open(path, ofstream::app);
	if (!fout.is_open())
	{
		cout << "Error!" << endl;
	}
	else
	{
		cout << "Файл открылся!" << endl;
		fout.write((char*)&point, sizeof(Point));
	}

	fout.close();

	ifstream fin;
	fin.open(path);

	if (!fin.is_open())
	{
		cout << "Error" << endl;
	}
	else
	{
		cout << "Файл открылся" << endl;
		Point pnt;
		while (fin.read((char*)&pnt, sizeof(Point)))
		{
			pnt.Print();
		}
	}

	fin.close();*/


	ifstream fin;

	fin.exceptions(ifstream::badbit | ifstream::failbit);

	try
	{
		cout << "Попытка открыть файл" << endl;
		fin.open(path);

		cout << "Файл успешно открыт!" << endl;

	}
	catch (const ifstream::failure& ex)
	{
		cout << ex.what() << endl;
		cout << ex.code() << endl;
		cout << "Ошибка открытия файла" << endl;
	}

	
	return 0;
}
