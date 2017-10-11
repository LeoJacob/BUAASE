#include "stdafx.h"
#include <cstdio>
#include <cstring>
#include "solver.h"
#include "dlx.h"

inline int Sudoku9NaiveSolver::blockId(int x, int y)
{
	return x / 3 * 3 + y / 3;
}

inline int Sudoku9NaiveSolver::lowbit(int x)
{
	return x & (-x);
}

inline int Sudoku9NaiveSolver::mask2num(int x)
{
	switch (x)
	{
	case 1:
		return 1;
	case 2:
		return 2;
	case 4:
		return 3;
	case 8:
		return 4;
	case 16:
		return 5;
	case 32:
		return 6;
	case 64:
		return 7;
	case 128:
		return 8;
	case 256:
		return 9;
	}
	return -1;
}

void Sudoku9NaiveSolver::dfs(int pos, bool init)
{
	if (pos >= 81)
	{
		if (!init)
		{
			flag = true;
			res = stack;
		}
		return;
	}
	int x = pos / 9, y = pos % 9;
	int mask, nxt;
	mask = row[x] | col[y] | block[blockId(x, y)];
	mask = ((1 << 9) - 1) & ~mask;
	if (puzzle.data[x][y] > 0)
	{
		stack.data[x][y] = puzzle.data[x][y];
		dfs(pos + 1, init);
	}
	else
	{
		while (mask && !flag)
		{
			nxt = lowbit(mask);
			row[x] |= nxt;
			col[y] |= nxt;
			block[blockId(x, y)] |= nxt;
			stack.data[x][y] = mask2num(nxt);
			if (!init || stack.data[x][y] >= res.data[x][y])
				dfs(pos + 1, stack.data[x][y] == res.data[x][y]?init:false);
			row[x] ^= nxt;
			col[y] ^= nxt;
			block[blockId(x, y)] ^= nxt;
			mask -= nxt;
		}
	}
}

Sudoku9NaiveSolver::Sudoku9NaiveSolver(Sudoku9 &__puzzle)
{
	int i, j, mask;
	puzzle = __puzzle;
	memset(block, 0, sizeof(block));
	memset(row, 0, sizeof(row));
	memset(col, 0, sizeof(col));
	flag = false;
	for (i = 0; i < 9; i += 1)
	{
		for (j = 0; j < 9; j += 1)
		{
			if (puzzle.data[i][j] <= 0)
				continue;
			mask = 1<<(puzzle.data[i][j] - 1);
			row[i] |= mask;
			col[j] |= mask;
			block[blockId(i, j)] |= mask;
		}
	}
}

bool Sudoku9NaiveSolver::solve()
{
	flag = false;
	dfs(0, true);
	return flag;
}

Sudoku9 Sudoku9NaiveSolver::solution()
{
	return res;
}

inline int Sudoku9DLXSolver::blockId(int x, int y)
{
	return x / 3 * 3 + y / 3;
}

inline int Sudoku9DLXSolver::rowId(int x, int y, int z)
{
	return x * 81 + y * 9 + z - 1;
}

Sudoku9DLXSolver::Sudoku9DLXSolver()
{
}

Sudoku9DLXSolver::Sudoku9DLXSolver(Sudoku9 __puzzle)
{
	set(__puzzle);
}

void Sudoku9DLXSolver::set(Sudoku9 __puzzle)
{
	int i, j, k, ban, mask;
	int row[9] = {}, col[9] = {}, block[9] = {};
	static std::vector<std::pair<int, int> > ones;
	ones.erase(ones.begin(), ones.end());
	puzzle = __puzzle;
	for (i = 0; i < 9; i += 1)
	{
		for (j = 0; j < 9; j += 1)
		{
			if (puzzle.data[i][j] <= 0)
				continue;
			mask = 1 << (puzzle.data[i][j] - 1);
			row[i] |= mask;
			col[j] |= mask;
			block[blockId(i, j)] |= mask;
			ones.push_back(std::make_pair(rowId(i, j, puzzle.data[i][j]), i * 9 + puzzle.data[i][j] - 1));
			ones.push_back(std::make_pair(rowId(i, j, puzzle.data[i][j]), 81 + j * 9 + puzzle.data[i][j] - 1));
			ones.push_back(std::make_pair(rowId(i, j, puzzle.data[i][j]), 162 + blockId(i, j) * 9 + puzzle.data[i][j] - 1));
			ones.push_back(std::make_pair(rowId(i, j, puzzle.data[i][j]), 243 + i * 9 + j));
		}
	}
	for (i = 0; i < 9; i += 1)
	{
		for (j = 0; j < 9; j += 1)
		{
			ban = row[i] | col[j] | block[blockId(i, j)];
			for (k = 1; k <= 9; k += 1)
			{
				mask = 1 << (k - 1);
				if (ban & mask)
					continue;
				ones.push_back(std::make_pair(rowId(i, j, k), i * 9 + k - 1));
				ones.push_back(std::make_pair(rowId(i, j, k), 81 + j * 9 + k - 1));
				ones.push_back(std::make_pair(rowId(i, j, k), 162 + blockId(i, j) * 9 + k - 1));
				ones.push_back(std::make_pair(rowId(i, j, k), 243 + i * 9 + j));
			}
		}
	}
	solver.set(ones, 324);
}

bool Sudoku9DLXSolver::solve()
{
	return solver.solve();
}

int Sudoku9DLXSolver::onlyOne()
{
    bool r = solver.onlyOne();
    return r ? solver.size() : -1;
}

Sudoku9 Sudoku9DLXSolver::solution()
{
	int i, x, y, z;
	std::vector<int> res;
	Sudoku9 ans;
	res = solver.solution();
	for (i = 0; i < res.size(); i += 1)
	{
		x = res[i] / 81;
		y = res[i] / 9 % 9;
		z = res[i] % 9 + 1;
		ans.data[x][y] = z;
	}
	return ans;
}