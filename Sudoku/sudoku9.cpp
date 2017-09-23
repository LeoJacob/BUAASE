#include "stdafx.h"
#include <cstring>
#include <string>
#include "sudoku9.h"

using namespace std;

inline int Sudoku9::blockId(int x, int y)
{
	return x / 3 * 3 + y / 3;
}

Sudoku9::Sudoku9()
{
	memset(data, 0, sizeof(data));
}

Sudoku9::Sudoku9(string __data)
{
	int i, j;
	for (i = 0; i < 9; i += 1)
	{
		for (j = 0; j < 9; j += 1)
			data[i][j] = __data[i * 9 + j] - '0';
	}
}

bool Sudoku9::isValid()
{
	int i, j;
	int block[9] = {}, row[9] = {}, col[9] = {};
	int mask;
	for (i = 0; i < 9; i += 1)
	{
		for (j = 0; j < 9; j += 1)
		{
			if (data[i][j] > 9 || data[i][j] <= 0)
				return false;
			mask = 1 << (data[i][j] - 1);
			if (row[i] & mask || col[j] & mask || block[blockId(i, j)] & mask)
				return false;
			row[i] |= mask;
			col[j] |= mask;
			block[blockId(i, j)] |= mask;
		}
	}
	return true;
}

string Sudoku9::toString()
{
	int i, j;
	char res[90] = {};
	for (i = 0; i < 9; i += 1)
	{
		for (j = 0; j < 9; j += 1)
			res[i * 9 + j] = data[i][j] + '0';
	}
	return res;
}
