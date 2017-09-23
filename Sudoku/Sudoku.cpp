// Sudoku.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include "sudoku9.h"
#include "generator.h"
#include "solver.h"

using namespace std;

void outputNum(FILE *&fout, int x)
{
	if (x >= 10)
		outputNum(fout, x / 10);
	fputc('0' + x % 10, fout);
}

int main(int argc, char *argv[])
{
	int T;
	int t, i, j;
	Sudoku9 puzzle;
	NaiveSudoku9Generator generator;
	FILE *fout;
	fout = fopen("sudoku.txt", "w");
	//scanf("%d", &T);
	T = 1000000;
	for (t = 0; t < T; t += 1)
	{
		puzzle = generator.generate();
		for (i = 0; i < 9; i += 1)
		{
			for (j = 0; j < 9; j += 1)
			{
				outputNum(fout, puzzle.data[i][j]);
				fputc(" \n"[j + 1 == 9 ? 1 : 0], fout);
				//fprintf(fout, "%d%c", puzzle.data[i][j], " \n"[j + 1 == 9 ? 1 : 0]);
			}
		}
		if (t + 1 < T)
		{
			fputc('\n', fout);
			//fprintf(fout, "\n");
		}
	}
	fclose(fout);
    return 0;
}

