#pragma once

#include "generator.h"
#include "solver.h"

class __declspec(dllexport) Core
{
private:
    

public:
	
    void generate(int number, int mode, int result[][81]);
    void generate(int number, int lower, int upper, bool unique, int result[][81]);
    bool solve(int puzzle[81], int solution[81]);
	void testLink();
};

