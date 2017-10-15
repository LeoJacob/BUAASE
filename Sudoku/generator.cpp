#include "stdafx.h"
#include <cassert>
#include <algorithm>
#include <set>
#include "sudoku9.h"
#include "solver.h"
#include "generator.h"

//#define DEBUG 0
//#define GENERATE 0

void NaiveSudoku9Generator::cantorExpand(int id, int perm[], int n)
{
	int i, j;
	int factor[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
	bool use[10] = {};
	//printf("id: %d\n", id);
	for (i = 0; i < n; i += 1)
	{
		//printf("i: %d, n: %d, id: %d\n", i, n, id);
		for (j = 0; j < n; j += 1)
		{
			if (use[j])
				continue;
			if (id < factor[n - i - 1])
			{
				use[j] = true;
				perm[i] = j + 1;
				break;
			}
			id -= factor[n - i - 1];
		}
		//printf("%d%c", perm[i], " \n"[i + 1 == n?1:0]);
	}
}

NaiveSudoku9Generator::NaiveSudoku9Generator()
{
	int i;
	solutionIdSequence.resize(solutionCnt);
	for (i = 0; i < solutionCnt; i += 1)
		solutionIdSequence[i] = i;
	cur = 0;
	random_shuffle(solutionIdSequence.begin(), solutionIdSequence.end());
}

Sudoku9 NaiveSudoku9Generator::generate()
{
	int i, j, id = solutionIdSequence[cur++];
	int baseId = id / blockCnt, permId = id % blockCnt;
	int perm[9];
	Sudoku9 res;
	//printf("baseId: %d\n", baseId);
	cantorExpand(permId + (((0 + 6) % 9 + 1) - 1) * blockCnt, perm, 9);
	for (i = 0; i < 9; i += 1)
	{
		for (j = 0; j < 9; j += 1)
			res.data[i][j] = perm[baseSolution[baseId].data[i][j] - 1];
	}
	return res;
}

const Sudoku9 NaiveSudoku9Generator::baseSolution[NaiveSudoku9Generator::baseSolutionCnt] = {
Sudoku9(
	"123456789"
	"456789123"
	"789123456"
	"214365897"
	"365897214"
	"897214365"
	"531642978"
	"642978531"
	"978531642"
),
Sudoku9(
	"123456789"
	"456789123"
	"789123456"
	"214365897"
	"365897214"
	"897214365"
	"531642978"
	"648971532"
	"972538641"
),
Sudoku9(
	"123456789"
	"456789123"
	"789123456"
	"214365897"
	"365897214"
	"897214365"
	"531642978"
	"672938541"
	"948571632"
),
Sudoku9(
	"123456789"
	"456789123"
	"789123456"
	"214365897"
	"365897214"
	"897214365"
	"531642978"
	"678931542"
	"942578631"
),
Sudoku9(
	"123456789"
	"456789123"
	"789123456"
	"214365897"
	"365897214"
	"897214365"
	"531642978"
	"942578631"
	"678931542"
),
Sudoku9(
	"123456789"
	"456789123"
	"789123456"
	"214365897"
	"365897214"
	"897214365"
	"531642978"
	"948571632"
	"672938541"
),
Sudoku9(
	"123456789"
	"456789123"
	"789123456"
	"214365897"
	"365897214"
	"897214365"
	"531642978"
	"972538641"
	"648971532"
),
Sudoku9(
	"123456789"
	"456789123"
	"789123456"
	"214365897"
	"365897214"
	"897214365"
	"531642978"
	"978531642"
	"642978531"
),
Sudoku9(
	"123456789"
	"456789123"
	"789123456"
	"214365897"
	"365897214"
	"897214365"
	"531648972"
	"642971538"
	"978532641"
),
Sudoku9(
	"123456789"
	"456789123"
	"789123456"
	"214365897"
	"365897214"
	"897214365"
	"531648972"
	"648972531"
	"972531648"
),
Sudoku9(
	"123456789"
	"456789123"
	"789123456"
	"214365897"
	"365897214"
	"897214365"
	"531648972"
	"672931548"
	"948572631"
),
Sudoku9(
	"123456789"
	"456789123"
	"789123456"
	"214365897"
	"365897214"
	"897214365"
	"531648972"
	"678932541"
	"942571638"
),
Sudoku9(
	"123456789"
	"456789123"
	"789123456"
	"214365897"
	"365897214"
	"897214365"
	"531648972"
	"942571638"
	"678932541"
),
Sudoku9(
	"123456789"
	"456789123"
	"789123456"
	"214365897"
	"365897214"
	"897214365"
	"531648972"
	"948572631"
	"672931548"
),
Sudoku9(
	"123456789"
	"456789123"
	"789123456"
	"214365897"
	"365897214"
	"897214365"
	"531648972"
	"972531648"
	"648972531"
),
Sudoku9(
	"123456789"
	"456789123"
	"789123456"
	"214365897"
	"365897214"
	"897214365"
	"531648972"
	"978532641"
	"642971538"
),
Sudoku9(
	"123456789"
	"456789123"
	"789123456"
	"214365897"
	"365897214"
	"897214365"
	"531672948"
	"642938571"
	"978541632"
),
Sudoku9(
	"123456789"
	"456789123"
	"789123456"
	"214365897"
	"365897214"
	"897214365"
	"531672948"
	"648931572"
	"972548631"
),
Sudoku9(
	"123456789"
	"456789123"
	"789123456"
	"214365897"
	"365897214"
	"897214365"
	"531672948"
	"672948531"
	"948531672"
),
Sudoku9(
	"123456789"
	"456789123"
	"789123456"
	"214365897"
	"365897214"
	"897214365"
	"531672948"
	"678941532"
	"942538671"
),
Sudoku9(
	"123456789"
	"456789123"
	"789123456"
	"214365897"
	"365897214"
	"897214365"
	"531672948"
	"942538671"
	"678941532"
),
Sudoku9(
	"123456789"
	"456789123"
	"789123456"
	"214365897"
	"365897214"
	"897214365"
	"531672948"
	"948531672"
	"672948531"
),
Sudoku9(
	"123456789"
	"456789123"
	"789123456"
	"214365897"
	"365897214"
	"897214365"
	"531672948"
	"972548631"
	"648931572"
),
Sudoku9(
	"123456789"
	"456789123"
	"789123456"
	"214365897"
	"365897214"
	"897214365"
	"531672948"
	"978541632"
	"642938571"
),
Sudoku9(
	"123456789"
	"456789123"
	"789123456"
	"214365897"
	"365897214"
	"897214365"
	"531678942"
	"642931578"
	"978542631"
)
};

void Sudoku9Generator::__generate(int number, int lowerBlank, int upperBlank, int lowerSize, int upperSize, int result[][81])
{
    if (!(0 <= lowerBlank && lowerBlank <= 64))
        throw std::invalid_argument("lowerBlank should be in [0, 64]!");
    if (!(upperBlank < 0 || (lowerBlank <= upperBlank)))
        throw std::invalid_argument("When upperBlank is valid, lowerBlank should be less than or equal to upperBlank!");
    if(!(upperBlank <= 64))
        throw std::invalid_argument("When upperBlank is valid, it should be less than 64!");
    if(!(lowerSize < 0 || 81 <= lowerSize))
        throw std::invalid_argument("When lowerSize is valid, it should be greater than or equal to 81!");
    if(!(upperSize < 0 || 81 <= upperSize))
        throw std::invalid_argument("When upperSize is valid, it should be greater than or equal to 81!");
    if(!(upperSize < 0 || lowerSize < 0 || lowerSize <= upperSize))
        throw std::invalid_argument("When both lowerSize and upperSize are valid, lowerSize should be less than or equal to upperSize!");
    assert(0 <= lowerBlank && lowerBlank <= 64);
    assert(upperBlank < 0 || (lowerBlank <= upperBlank && upperBlank <= 64));
    assert(lowerSize < 0 || 81 <= lowerSize);
    assert(upperSize < 0 || 81 <= lowerSize);
    assert(upperSize < 0 || lowerSize < 0 || lowerSize <= upperSize);

    int i, j, r, tar, init, done;
    int cell[81];
    Sudoku9 blank(
        "123456789"
        "000000000"
        "000000000"
        "000000000"
        "000000000"
        "000000000"
        "000000000"
        "000000000"
        "000000000"
    ), base;
    Sudoku9DLXSolver solver(blank), checkSolver;
    for (i = 0; i < 81; i += 1)
        cell[i] = i;
    for (i = 0; i < number; i += 1)
    {
        if (upperBlank < 0)
            tar = -1;
        else
            tar = lowerBlank + rand() % (upperBlank - lowerBlank + 1);
        solver.solve();
        base = solver.solution();
        std::random_shuffle(cell, cell + 81);
        for (j = done = 0; j < 81 && (tar < 0 || done < tar); j += 1)
        {
            init = base.data[cell[j] / 9][cell[j] % 9];
            base.data[cell[j] / 9][cell[j] % 9] = 0;
            checkSolver.set(base);
            if ((r = checkSolver.onlyOne()) > 0)
                done += 1;
            else
                base.data[cell[j] / 9][cell[j] % 9] = init;
        }
        if ((tar >= 0 && done < tar)
            || (done < lowerBlank))
        {
            i -= 1;
            continue;
        }
        if (lowerSize >= 0 || upperSize >= 0)
        {
            checkSolver.set(base);
            r = checkSolver.onlyOne();
            if (lowerSize >= 0 && r < lowerSize)
            {
                i -= 1;
                continue;
            }
            if (upperSize >= 0 && r > upperSize)
            {
                i -= 1;
                continue;
            }
        }
#ifdef DEBUG
        if(!(i % (number / 100)))
            printf("i: %d\n", i);
#endif //DEBUG
        for (j = 0; j < 81; j += 1)
            result[i][j] = base.data[j / 9][j % 9];
    }
}

void shuffleSudoku9(int number, int result[][81])
{
    int i, j;
    int permutation[11] = {};
    for (i = 0; i < 10; i += 1)
        permutation[i] = i;
    for (i = 0; i < number; i += 1)
    {
        std::random_shuffle(permutation + 1, permutation + 10);
        for (j = 0; j < 81; j += 1)
            result[i][j] = permutation[result[i][j]];
    }
}

void loadNSudoku9FromFile(int number, const char *filename, int result[][81])
{
    FILE *fin;
    int i, j, N;
    fin = fopen(filename, "r");
    fscanf(fin, "%d", &N);
    char str[100];
    std::vector<std::string> repository;
    for (i = 0; i < N; i += 1)
    {
        fscanf(fin, "%s", str);
        repository.push_back(str);
    }
    fclose(fin);
    std::random_shuffle(repository.begin(), repository.end());
    for (i = 0; i < number; i += 1)
    {
        for (j = 0; j < 81; j += 1)
            result[i][j] = repository[i % repository.size()][j] - '0';
    }
    shuffleSudoku9(number, result);
}

void Sudoku9Generator::generateMode1(int number, int result[][81])
{
#ifdef GENERATE
    const int lowerBlank = 25, upperBlank = 40;
    const int lowerSize = 81, upperSize = 81;
    __generate(number, lowerBlank, upperBlank, lowerSize, upperSize, result);
#else
    loadNSudoku9FromFile(number, "mode1.txt", result);
#endif //GENERATE
}

void Sudoku9Generator::generateMode2(int number, int result[][81])
{
#ifdef GENERATE
    const int lowerBlank = 35, upperBlank = 50;
    const int lowerSize = 82, upperSize = 100;
    __generate(number, lowerBlank, upperBlank, lowerSize, upperSize, result);
#else
    loadNSudoku9FromFile(number, "mode2.txt", result);
#endif //GENERATE
}

void Sudoku9Generator::generateMode3(int number, int result[][81])
{
#ifdef GENERATE
    const int lowerBlank = 45, upperBlank = -1;
    const int lowerSize = 121, upperSize = -1;
    __generate(number, lowerBlank, upperBlank, lowerSize, upperSize, result);
#else
    loadNSudoku9FromFile(number, "mode3.txt", result);
#endif //GENERATE
}

void Sudoku9Generator::generate(int number, int mode, int result[][81])
{
    switch (mode)
    {
    case 1:
        generateMode1(number, result);
        break;
    case 2:
        generateMode2(number, result);
        break;
    case 3:
        generateMode3(number, result);
        break;
    default:
        throw std::invalid_argument("mode should be in {1, 2, 3}!");
    }
}

void Sudoku9Generator::generate(int number, int lower, int upper, bool unique, int result[][81])
{
    __generate(number, lower, upper, -1, -1, result);
    shuffleSudoku9(number, result);
}

/*
int main(int argc, char *argv[])
{
	int t;
	int i, j;
	Sudoku9 init, ans;
	Sudoku9NaiveSolver solver(init);
	set<string> hash;
	string tmp;
	freopen("init.txt", "w", stdout);
	for (t = 0; t < 25; t += 1)
	{
		if (solver.solve())
		{
			//printf("Yes\n");
			ans = solver.solution();
			tmp = ans.toString();
			if (!ans.isValid())
			{
				printf("invalid solution!\n");
				exit(-1);
			}
			//printf("valid: %s\n", ans.isValid() ? "Yes" : "No");
			printf("Sudoku9(\n");
			for (i = 0; i < 9; i += 1)
			{
				printf("\t\"");
				for (j = 0; j < 9; j += 1)
					printf("%d", ans.data[i][j]);
				printf("\"");
				if (i + 1 < 9)
					printf("\n");
			}
			printf("\n)");
			if (t + 1 < 25)
				printf(",");
			printf("\n");
			if (hash.find(tmp) != hash.end())
			{
				printf("**hash check error!**\n");
				exit(-1);
			}
			else
				hash.insert(tmp);
		}
		else
		{
			printf("No\n");
			exit(-1);
		}
	}
	//system("pause");
    return 0;
}
*/
