#pragma once
#include <string>

struct Sudoku9Node
{
	long long x[5];

	bool operator<(const Sudoku9Node v) const;

	bool operator==(const Sudoku9Node v) const;
};

class Sudoku9
{
private:
	inline int blockId(int x, int y);
public:
	int data[9][9];

	Sudoku9();

	Sudoku9(std::string __data);

	bool isValid();

    bool isValidPuzzle();

	std::string toString();

    std::string toNormString();

    Sudoku9 normForm();

	Sudoku9Node node();

    Sudoku9Node normNode();
};
