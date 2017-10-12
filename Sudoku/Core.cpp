#include "stdafx.h"
#include "Core.h"
#include "generator.h"
#include "solver.h"

void Core::generate(int number, int mode, int result[][81])
{
    generator.generate(number, mode, result);
}

void Core::generate(int number, int lower, int upper, bool unique, int result[][81])
{
    generator.generate(number, lower, upper, unique, result);
}

bool Core::solve(int puzzle[81], int solution[81])
{
    int i, j;
    bool res;
    Sudoku9 __puzzle, ans;
    for (i = 0; i < 9; i += 1)
    {
        for (j = 0; j < 9; j += 1)
            __puzzle.data[i][j] = puzzle[i * 9 + j];
    }

    if (!__puzzle.isValidPuzzle())
        throw std::invalid_argument("The puzzle is not valid!");

    solver.set(__puzzle);
    res = solver.solve();
    if (res)
    {
        ans = solver.solution();
        for (i = 0; i < 9; i += 1)
        {
            for (j = 0; j < 9; j += 1)
                solution[i * 9 + j] = ans.data[i][j];
        }
    }
    return res;
}