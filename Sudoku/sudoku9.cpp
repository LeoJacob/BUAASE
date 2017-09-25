#include "stdafx.h"
#include <cstring>
#include <string>
#include "sudoku9.h"

using namespace std;

bool Sudoku9Node::operator<(Sudoku9Node &v)
const {
	int i;
	long long r;
	for (i = 0; i < 5; i += 1)
	{
		r = x[i] - v.x[i];
		if (r != 0)
			return r < 0;
	}
	return false;
}

bool Sudoku9Node::operator==(Sudoku9Node &v)
const {
	int i;
	for (i = 0; i < 5; i += 1)
	{
		if (x[i] != v.x[i])
			return false;
	}
	return true;
}

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

Sudoku9Node Sudoku9::node()
{
	int i, j, id;
	Sudoku9Node res;
	for (i = 0; i < 6; i += 1)
	{
		res.x[i] = 0;
		for (j = 0; j < 17 && (id = i * 17 + j) < 81; j += 1)
			res.x[i] = res.x[i] * 10 + data[id / 9][id % 9];
	}
	return res;
}