#include "stdafx.h"
#include <cstdio>
#include <cstring>
#include "solver.h"

using namespace std;

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
