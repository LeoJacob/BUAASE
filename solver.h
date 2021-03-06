#pragma once
#include "sudoku9.h"
#include "dlx.h"

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

class Sudoku9DLXSolver
{
public:
	Sudoku9 puzzle;
	DLXSolver solver;

	inline int blockId(int x, int y);

	inline int rowId(int x, int y, int z);


	__declspec(dllexport) Sudoku9DLXSolver();

	__declspec(dllexport) Sudoku9DLXSolver(Sudoku9 __puzzle);

	__declspec(dllexport) void set(Sudoku9 __puzzle);

	__declspec(dllexport) bool solve();

	__declspec(dllexport) int onlyOne();

	__declspec(dllexport) Sudoku9 solution();
};
