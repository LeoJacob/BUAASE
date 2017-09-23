#pragma once
#include <vector>
#include "sudoku9.h"

using namespace std;

class NaiveSudoku9Generator
{
private:
	static const int baseSolutionCnt = 25, blockCnt = 40320;
	static const int solutionCnt = baseSolutionCnt * blockCnt;
	static const Sudoku9 baseSolution[baseSolutionCnt];
	int cur;
	vector<int> solutionIdSequence;

	void cantorExpand(int id, int perm[], int n);

public:
	NaiveSudoku9Generator();

	Sudoku9 generate();
};
