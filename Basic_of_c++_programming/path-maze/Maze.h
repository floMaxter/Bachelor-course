#pragma once
#define DirectionsNumber 4 
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Maze
{
private:
	int xstart;
	int ystart;
	int xfinish;
	int yfinish;
	int rows;
	int columns;
	int MinCounter;
	bool ResFound;

	int dx[DirectionsNumber] = { -1, 0, 1, 0 };
	int dy[DirectionsNumber] = { 0, 1, 0, -1 };
	vector<vector<char>> matrix;
	vector<vector<char>> ShortWay;

public:
	Maze();																		//Default constructor
	Maze(int rows, int column);													//Constructor with parameters
	int GetXStart();															//Returns the x coordinate of the start
	int GetYStart();															//Returns the y coordinate of the start
	int GetMinCount();															//Returns the value of the minimum path

	void PrintMatrix();															//Main matrix printing
	friend void InputMaze(ifstream& fin, Maze& mz);								/*Entering a matrix(maze) from a file
																				into an array of a class*/
	friend void FindCoord(Maze& mz);											/*Sets the coordinates of the entry and exit
																				to the system coordinates (x, y)*/
	friend bool FindingWay(Maze& mz, int xs, int ys, int count, ofstream& fout);//Finding for a path from start to finish
	friend bool CheckingOut(Maze& mz, int x, int y);							//Checking the availability of a cell
	friend void OutputMaze(ofstream& fout, Maze& mz, int k);					//Putting the path into the file
	void DimensionCounting(ifstream& fin);										//Counting rows and columns of a matrix from a file
	friend void ShortCutRecording(Maze& mz, int k);								//Shortest Path Recording
};

void PrintFile(ifstream& fin);													//Printing the resulting path from a file