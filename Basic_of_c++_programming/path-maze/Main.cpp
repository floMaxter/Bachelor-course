#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include "Maze.h"
using namespace std;

int main(int argc, char* argv[])
{
	string pathinput(argv[1]);
	string pathoutput(argv[2]);

	ifstream fin;
	ofstream fout;

	Maze MyMaze;

	//Counting rows and columns in a file
	fin.open(pathinput);
	if (!fin.is_open())
	{
		cout << "File open error!" << endl;
		cout << "Name file: " << pathinput << endl;
		return -1;
	}
	MyMaze.DimensionCounting(fin);
	fin.close();

	//Reading a maze from a file
	fin.open(pathinput);
	if (!fin.is_open())
	{
		cout << "File open error 2!" << endl;
		cout << "Name file: " << pathinput << endl;
		return -1;
	}
	InputMaze(fin, MyMaze);
	fin.close();

	//Finding the coordinates of the start and finish point
	FindCoord(MyMaze);

	//Finding a path in a maze and writing it to a file
	fout.open(pathoutput);
	if (!fout.is_open())
	{
		cout << "File open error!" << endl;
		cout << "Name file: " << pathoutput << endl;
		return -1;
	}
	bool SearchResult = FindingWay(MyMaze, MyMaze.GetXStart(), MyMaze.GetYStart(), 1, fout);
	if (SearchResult == 0)
	{
		cout << "Path not found" << endl;
	}
	else
	{
		OutputMaze(fout, MyMaze, MyMaze.GetMinCount());
	}
	fout.close();


	//Outputting a matrix from a file
	fin.open(pathoutput);
	if (!fin.is_open())
	{
		cout << "File opened error!" << endl;
		cout << "Name file: " << pathoutput << endl;
		return -1;
	}
	PrintFile(fin);
	fin.close();


	return 0;
}