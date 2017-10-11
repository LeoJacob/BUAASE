#pragma once
#include <vector>
#include "sudoku9.h"

class NaiveSudoku9Generator
{
private:
	static const int baseSolutionCnt = 25, blockCnt = 40320;
	static const int solutionCnt = baseSolutionCnt * blockCnt;
	static const Sudoku9 baseSolution[baseSolutionCnt];
	int cur;
	std::vector<int> solutionIdSequence;

	void cantorExpand(int id, int perm[], int n);

public:
	NaiveSudoku9Generator();

	Sudoku9 generate();
};

class Sudoku9Generator
{
private:
    void __generate(int number, int lowerBlank, int upperBlank, int lowerSize, int upperSize, int result[][81]);
    void generateMode1(int number, int result[][81]);
    void generateMode2(int number, int result[][81]);
    void generateMode3(int number, int result[][81]);
public:
    void generate(int number, int mode, int result[][81]);
    void generate(int number, int lower, int upper, bool unique, int result[][81]);
};
