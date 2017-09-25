#pragma once
#include <string>

using namespace std;

struct Sudoku9Node
{
	long long x[5];

	bool operator<(Sudoku9Node &v) const;

	bool operator==(Sudoku9Node &v) const;
};

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

	Sudoku9Node node();
};
