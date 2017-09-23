#pragma once
#include "sudoku9.h"

class Sudoku9NaiveSolver
{
private:
	Sudoku9 puzzle, stack, res;
	int block[9], row[9], col[9];
	bool flag;

	inline int blockId(int x, int y);

	inline int lowbit(int x);

	inline int mask2num(int x);

	void dfs(int pos, bool init);
public:
	Sudoku9NaiveSolver(Sudoku9 &__puzzle);

	bool solve();

	Sudoku9 solution();
};
