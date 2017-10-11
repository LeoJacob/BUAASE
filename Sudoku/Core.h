#pragma once
#include "generator.h"
#include "solver.h"

class Core
{
private:
    Sudoku9Generator generator;
    Sudoku9DLXSolver solver;

public:
    void generate(int number, int mode, int result[][81]);
    void generate(int number, int lower, int upper, bool unique, int result[][81]);
    bool solve(int puzzle[81], int solution[81]);
};
