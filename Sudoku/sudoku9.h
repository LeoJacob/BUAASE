#pragma once
#include <string>

using namespace std;

class Sudoku9
{
private:
	inline int blockId(int x, int y);
public:
	int data[9][9];

	Sudoku9();

	Sudoku9(string __data);

	bool isValid();

	string toString();
};
