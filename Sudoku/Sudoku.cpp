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
	if (argc != 3
		|| strlen(argv[1]) != 2
		|| argv[1][0] != '-'
		|| (argv[1][1] != 'c' && argv[1][1] != 's'))
		goto WRONG_PARAMETERS;

	if (argv[1][1] == 's')
	{
		int i, j;
		int cnt = 0;
		Sudoku9DLXSolver solver;
		Sudoku9 puzzle, ans;
		char buffer[200] = {};
		FILE *fout;
		if (!freopen(argv[2], "r", stdin))
			goto WRONG_PARAMETERS;
		fout = fopen("sudoku.txt", "w");
		while (1)
		{
			for (i = 0; i < 9; i += 1)
			{
				for (j = 0; j < 9; j += 1)
				{
					if (scanf("%d", &puzzle.data[i][j]) == EOF)
						break;
				}
				if (j < 9)
					break;
			}
			if (i < 9)
				break;
			if (cnt)
				fputc('\n', fout);
			solver.set(puzzle);
			if (solver.solve())
			{
				ans = solver.solution();
				for (i = 0; i < 9; i += 1)
				{
					for (j = 0; j < 9; j += 1)
					{
						buffer[(i * 9 + j) * 2] = ans.data[i][j] + '0';
						buffer[(i * 9 + j) * 2 + 1] = " \n"[j + 1 == 9 ? 1 : 0];
					}
				}
				fwrite(buffer, 1, 162, fout);
			}
			else
				fprintf(fout, "No Solution!\n");
			cnt += 1;
		}
		fclose(fout);
	}
	else if (argv[1][1] == 'c')
	{
		if (strlen(argv[2]) > 7)
			goto WRONG_PARAMETERS;

		int T = 0;
		int t, i, j;
		for(i = 0;argv[2][i];i += 1)
		{
			if (!isdigit(argv[2][i]))
				goto WRONG_PARAMETERS;
			T = T * 10 + argv[2][i] - '0';
		}
		if (T > 1000000)
			goto WRONG_PARAMETERS;

		Sudoku9 puzzle;
		NaiveSudoku9Generator generator;
		FILE *fout;
		char buffer[200] = {};
		fout = fopen("sudoku.txt", "w");
		for (t = 0; t < T; t += 1)
		{
			puzzle = generator.generate();
			for (i = 0; i < 9; i += 1)
			{
				for (j = 0; j < 9; j += 1)
				{
					buffer[(i * 9 + j) * 2] = puzzle.data[i][j] + '0';
					buffer[(i * 9 + j) * 2 + 1] = " \n"[j + 1 == 9 ? 1 : 0];
				}
			}
			fwrite(buffer, 1, 162, fout);
			if (t + 1 < T)
				fputc('\n', fout);
		}
		fclose(fout);
	}

EXIT:
	return 0;

WRONG_PARAMETERS:
	printf("Wrong Parameters!\n");
	goto EXIT;
}

