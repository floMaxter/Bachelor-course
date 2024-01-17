#include "Maze.h"
#define MaxLength 100000000
using namespace std;

//The input function
Maze::Maze()
{
	this->xstart = 0;
	this->ystart = 0;
	this->xfinish = 0;
	this->yfinish = 0;
	this->rows = 0;
	this->columns = 0;
	this->MinCounter = MaxLength;
	this->ResFound = false;
}

//Constructor with parameters
Maze::Maze(int rows, int columns)
{
	this->xstart = 0;
	this->ystart = 0;
	this->xfinish = 0;
	this->yfinish = 0;
	this->rows = rows;
	this->columns = columns;
	this->MinCounter = MaxLength;
	this->ResFound = false;

	//Allocating memory in a matrix
	matrix.resize(rows);
	for (int i = 0; i < rows; i++)
	{
		matrix[i].resize(columns);
	}

	//Filling in the matrix '#'
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			matrix[i][j] = '#';
		}
	}

	//Allocating memory for the shortest path matrix
	ShortWay.resize(rows);
	for (int i = 0; i < rows; i++)
	{
		ShortWay[i].resize(columns);
	}

	//Filling in the matrix '#'
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			ShortWay[i][j] = '#';
		}
	}
}

//Returns the x coordinate of the start
int Maze::GetXStart()
{
	return xstart;
}

//Returns the y coordinate of the start
int Maze::GetYStart()
{
	return ystart;
}

//Returns the value of the minimum path
int Maze::GetMinCount()
{
	return MinCounter;
}

//Counting rows and columns of a matrix from a file
void Maze::DimensionCounting(ifstream& fin)
{
	char ch;
	int rows = 1;
	int col = 0;
	bool flag = false;
	while (fin.get(ch))
	{
		if (ch == '\n')
		{
			rows++;
			flag = true;
		}
		else
		{
			if ((ch != ' ') && (flag == false))
			{
				col++;
			}
		}
	}
	//Allocating memory in a matrix
	this->columns = col;
	this->rows = rows;
	matrix.resize(rows);
	for (int i = 0; i < rows; i++)
	{
		matrix[i].resize(col);
	}
	//Filling in the matrix '#'
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < col; j++)
		{
			matrix[i][j] = '#';
		}
	}

	//Allocating memory for the shortest path matrix
	ShortWay.resize(rows);
	for (int i = 0; i < rows; i++)
	{
		ShortWay[i].resize(columns);
	}

	//Filling in the matrix '#'
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			ShortWay[i][j] = '#';
		}
	}
}

//Main matrix printing
void Maze::PrintMatrix()
{
	cout << "Matrix:" << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

//Entering a matrix(maze) from a file into an array of a class
void InputMaze(ifstream& fin, Maze& mz)
{
	char tmp;
	for (int i = 0; i < mz.rows; i++)
	{
		for (int j = 0; j < mz.columns; j++)
		{
			fin >> tmp;
			mz.matrix[i][j] = tmp;
		}
	}
}

//Sets the coordinates of the entry and exit to the system coordinates(x, y)
void FindCoord(Maze& mz)
{
	char tmps = 's';
	int tmpf = 'f';
	for (int i = 0; i < mz.rows; i++)
	{
		for (int j = 0; j < mz.columns; j++)
		{
			if (mz.matrix[i][j] == tmps)
			{
				mz.xstart = i;
				mz.ystart = j;
			}
			if (mz.matrix[i][j] == tmpf)
			{
				mz.xfinish = i;
				mz.yfinish = j;
			}
		}
	}
}

/**
* \brief Finding for a path from start to finish
*
* This function is basic, it includes a pathfinding algorithm in a maze. The input receives the coordinates
of a point and an object of the Maze class, as well as an output stream to a file. A boolean variable is returned
from the function, indicating whether the exit was found or not.

\param[in] mz object of class Maze
\param[in] xs x coordinate to start
\param[in] ys s coordinate to start
\param[in] count step counter
\param[in] fout output stream to file
\param[out] res found a way or not

*/
bool FindingWay(Maze& mz, int xs, int ys, int count, ofstream& fout)
{
	char ck = '*';
	int x = xs;
	int y = ys;
	if (x == mz.xfinish && y == mz.yfinish)
	{
		mz.matrix[x][y] = ck;
		ShortCutRecording(mz, count);
		mz.matrix[x][y] = 'f';
		mz.ResFound = true;
	}
	else
	{
		mz.matrix[x][y] = ck;
		for (int i = 0; i < 4; i++)
		{
			if (CheckingOut(mz, x + mz.dx[i], y + mz.dy[i]))
			{
				mz.ResFound = FindingWay(mz, x + mz.dx[i], y + mz.dy[i], count + 1, fout);
			}
		}
		mz.matrix[x][y] = '.';
	}
	return mz.ResFound;
}

//Checking the availability of a cell
bool CheckingOut(Maze& mz, int x, int y)
{
	bool res = false;
	char tmp1 = '.';
	char tmp2 = 'f';

	if (mz.matrix[x][y] == tmp1 || mz.matrix[x][y] == tmp2)
	{
		res = true;
	}

	return res;
}

//Putting the path into the file
void OutputMaze(ofstream& fout, Maze& mz, int k)
{
	char tmp;
	fout << "Step: ";
	fout << k;
	fout << '\n';
	for (int i = 0; i < mz.rows; i++)
	{
		for (int j = 0; j < mz.columns; j++)
		{
			tmp = mz.ShortWay[i][j];
			fout << tmp << " ";
		}
		fout << '\n';
	}
	fout << '\n' << '\n';
}

//Shortest Path Recording
void ShortCutRecording(Maze& mz, int k)
{
	if (k < mz.MinCounter)
	{
		mz.MinCounter = k;
		for (int i = 0; i < mz.rows; i++)
		{
			for (int j = 0; j < mz.columns; j++)
			{
				mz.ShortWay[i][j] = mz.matrix[i][j];
			}
		}
	}
}

//Printing the resulting path from a file
void PrintFile(ifstream& fin)
{
	char tmp;
	while (fin.get(tmp))
	{
		cout << tmp;
	}
}
