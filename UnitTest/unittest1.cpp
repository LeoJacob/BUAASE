#include "stdafx.h"
#include "CppUnitTest.h"
#include "../sudoku/sudoku9.h"
#include "../sudoku/dlx.h"
#include "../sudoku/solver.h"
#include "../sudoku/generator.h"
#include "../sudoku/Core.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(CheckValidPuzzle1)
		{
			Sudoku9 puzzle(
				"800000000"
				"003600000"
				"070090200"
				"050007000"
				"000045700"
				"000100030"
				"001000068"
				"008500010"
				"090000400");
            Assert::IsTrue(puzzle.isValidPuzzle());
		}

		TEST_METHOD(CheckValidPuzzle2)
		{
			Sudoku9 puzzle(
				"880000000"
				"003600000"
				"070090200"
				"050007000"
				"000045700"
				"000100030"
				"001000068"
				"008500010"
				"090000400");
            Assert::IsTrue(puzzle.isValidPuzzle());
		}

		TEST_METHOD(CheckValidPuzzle3)
		{
			Sudoku9 puzzle(
				"880000000"
				"003600000"
				"070090200"
				"050007000"
				"000045700"
				"000100030"
				"001000068"
				"008500010"
				"090000400");
            puzzle.data[0][0] = -1;
            Assert::IsFalse(puzzle.isValidPuzzle());
		}

		TEST_METHOD(CheckValidPuzzle4)
		{
			Sudoku9 puzzle(
				"880000000"
				"003600000"
				"070090200"
				"050007000"
				"000045700"
				"000100030"
				"001000068"
				"008500010"
				"090000400");
            puzzle.data[8][8] = 10;
            Assert::IsFalse(puzzle.isValidPuzzle());
		}
		
		TEST_METHOD(HasSolution1)
		{
			Sudoku9 puzzle(
				"800000000"
				"003600000"
				"070090200"
				"050007000"
				"000045700"
				"000100030"
				"001000068"
				"008500010"
				"090000400"), origin, ans;
			origin = puzzle;
			Sudoku9DLXSolver solver(puzzle);
			Assert::IsTrue(solver.solve());
			ans = solver.solution();
			Assert::IsTrue(ans.isValid());
			int i, j;
			for (i = 0; i < 9; i += 1)
			{
				for (j = 0; j < 9; j += 1)
				{
					if (origin.data[i][j] > 0)
						Assert::IsTrue(origin.data[i][j] == ans.data[i][j]);
				}
			}
		}

		TEST_METHOD(HasSolution2)
		{
			Sudoku9 puzzle(
				"000000000"
				"000000000"
				"000000000"
				"000000000"
				"000000000"
				"000000000"
				"000000000"
				"000000000"
				"000000000"), origin, ans;
			origin = puzzle;
			Sudoku9DLXSolver solver(puzzle);
			Assert::IsTrue(solver.solve());
			ans = solver.solution();
			Assert::IsTrue(ans.isValid());
			int i, j;
			for (i = 0; i < 9; i += 1)
			{
				for (j = 0; j < 9; j += 1)
				{
					if (origin.data[i][j] > 0)
						Assert::IsTrue(origin.data[i][j] == ans.data[i][j]);
				}
			}
		}

		TEST_METHOD(NoSolution1)
		{
			Sudoku9 puzzle(
				"801000000"
				"003600000"
				"070090200"
				"050007000"
				"000045700"
				"000100030"
				"001000068"
				"008500010"
				"090000400");
			Sudoku9DLXSolver solver(puzzle);
			Assert::IsFalse(solver.solve());
		}

		TEST_METHOD(NoSolution2)
		{
			Sudoku9 puzzle(
				"800000000"
				"000000000"
				"008000000"
				"000000000"
				"000000000"
				"000000000"
				"000000000"
				"000000000"
				"000000000");
			Sudoku9DLXSolver solver(puzzle);
			Assert::IsFalse(solver.solve());
		}

		TEST_METHOD(NoSolution3)
		{
			Sudoku9 puzzle(
				"800000008"
				"000000000"
				"000000000"
				"000000000"
				"000000000"
				"000000000"
				"000000000"
				"000000000"
				"000000000");
			Sudoku9DLXSolver solver(puzzle);
			Assert::IsFalse(solver.solve());
		}

		TEST_METHOD(NoSolution4)
		{
			Sudoku9 puzzle(
				"800000000"
				"000000000"
				"000000000"
				"000000000"
				"000000000"
				"000000000"
				"000000000"
				"000000000"
				"800000000");
			Sudoku9DLXSolver solver(puzzle);
			Assert::IsFalse(solver.solve());
		}

		TEST_METHOD(NoRepeat)
		{
			int T;
			int t;
			Sudoku9 puzzle;
			NaiveSudoku9Generator generator;
			std::vector<Sudoku9Node> check;
			T = 1000000;
			for (t = 0; t < T; t += 1)
			{
				puzzle = generator.generate();
				check.push_back(puzzle.node());
			}
			std::sort(check.begin(), check.end());
			check.erase(std::unique(check.begin(), check.end()), check.end());
			Assert::IsTrue(check.size() == T);
		}

		TEST_METHOD(DLXSolverTestHasSolution)
		{
			std::vector<std::pair<int, int> > ones;
			ones.push_back(std::make_pair(0, 2));
			ones.push_back(std::make_pair(0, 4));
			ones.push_back(std::make_pair(0, 5));
			ones.push_back(std::make_pair(1, 0));
			ones.push_back(std::make_pair(1, 3));
			ones.push_back(std::make_pair(1, 6));
			ones.push_back(std::make_pair(2, 1));
			ones.push_back(std::make_pair(2, 2));
			ones.push_back(std::make_pair(2, 5));
			ones.push_back(std::make_pair(3, 0));
			ones.push_back(std::make_pair(3, 3));
			ones.push_back(std::make_pair(4, 1));
			ones.push_back(std::make_pair(4, 6));
			ones.push_back(std::make_pair(5, 3));
			ones.push_back(std::make_pair(5, 4));
			ones.push_back(std::make_pair(5, 6));
			DLXSolver solver(ones, 7);
			Assert::IsTrue(solver.solve());
		}

		TEST_METHOD(GenerateValidPuzzle)
		{
			NaiveSudoku9Generator generator;
			Sudoku9 puzzle;
			puzzle = generator.generate();
			Assert::IsTrue(puzzle.isValid());
			Assert::IsTrue(puzzle.data[0][0] == (0 + 6) % 9 + 1);
		}

		TEST_METHOD(Generate1000000ValidPuzzle)
		{
			int T = 1000000;
			NaiveSudoku9Generator generator;
			Sudoku9 puzzle;
			for(int t = 0;t < T;t += 1)
			{
				puzzle = generator.generate();
				Assert::IsTrue(puzzle.isValid());
				Assert::IsTrue(puzzle.data[0][0] == (0 + 6) % 9 + 1);
			}
		}

		TEST_METHOD(MultipleSolutionTest1)
		{
			Sudoku9 puzzle(
				"800000000"
				"003600000"
				"070090200"
				"050007000"
				"000045700"
				"000100030"
				"001000068"
				"008500010"
				"090000400"), origin, ans;
			origin = puzzle;
			Sudoku9DLXSolver solver(puzzle);
			Assert::IsTrue(solver.solve());
			ans = solver.solution();
			Assert::IsTrue(ans.isValid());
			int i, j;
			for (i = 0; i < 9; i += 1)
			{
				for (j = 0; j < 9; j += 1)
				{
					if (origin.data[i][j] > 0)
						Assert::IsTrue(origin.data[i][j] == ans.data[i][j]);
				}
			}
            Assert::IsFalse(solver.solve());
		}

		TEST_METHOD(MultipleSolutionTest2)
		{
			Sudoku9 puzzle(
				"000000000"
				"000000000"
				"000000000"
				"000000000"
				"000000000"
				"000000000"
				"000000000"
				"000000000"
				"000000000"), origin, ans1, ans2;
			origin = puzzle;
			Sudoku9DLXSolver solver(puzzle);
			Assert::IsTrue(solver.solve());
			ans1 = solver.solution();
			Assert::IsTrue(ans1.isValid());
			int i, j;
			for (i = 0; i < 9; i += 1)
			{
				for (j = 0; j < 9; j += 1)
				{
					if (origin.data[i][j] > 0)
						Assert::IsTrue(origin.data[i][j] == ans1.data[i][j]);
				}
			}
            Assert::IsTrue(solver.solve());
            ans2 = solver.solution();
            Assert::IsTrue(ans2.isValid());
			for (i = 0; i < 9; i += 1)
			{
				for (j = 0; j < 9; j += 1)
				{
					if (origin.data[i][j] > 0)
						Assert::IsTrue(origin.data[i][j] == ans1.data[i][j]);
				}
			}
            bool flag = true;
			for (i = 0; i < 9; i += 1)
			{
                for (j = 0; j < 9; j += 1)
                    flag = flag && ans1.data[i][j] == ans2.data[i][j];
			}
            Assert::IsFalse(flag);
		}

		TEST_METHOD(MultipleSolutionTest3)
		{
			Sudoku9 puzzle(
				"000000000"
				"000000000"
				"000000000"
				"000000000"
				"000000000"
				"000000000"
				"000000000"
				"000000000"
				"000000000");
			Sudoku9DLXSolver solver(puzzle);
            int i;
            for(i = 0;i < 1000;i += 1)
                Assert::IsTrue(solver.solve());
		}

		TEST_METHOD(OnlyOneTest1)
		{
			Sudoku9 puzzle(
                "800000000"
				"003600000"
				"070090200"
				"050007000"
				"000045700"
				"000100030"
				"001000068"
				"008500010"
				"090000400");
			Sudoku9DLXSolver solver(puzzle);
            Assert::IsTrue(solver.onlyOne() > 0);
		}

		TEST_METHOD(OnlyOneTest2)
		{
			Sudoku9 puzzle(
                "801000000"
				"003600000"
				"070090200"
				"050007000"
				"000045700"
				"000100030"
				"001000068"
				"008500010"
				"090000400");
			Sudoku9DLXSolver solver(puzzle);
            Assert::IsTrue(solver.onlyOne() < 0);
		}

		TEST_METHOD(OnlyOneTest3)
		{
			Sudoku9 puzzle(
                "000000000"
				"003600000"
				"070090200"
				"050007000"
				"000045700"
				"000100030"
				"001000068"
				"008500010"
				"090000400");
			Sudoku9DLXSolver solver(puzzle);
            Assert::IsTrue(solver.onlyOne() < 0);
		}

		TEST_METHOD(CheckMode1File)
		{
            Sudoku9 puzzle, ans;
            Sudoku9DLXSolver checkSolver;
            std::vector<Sudoku9Node> table;
            int i, j, k, blank, N, r;
            char str[100];
            FILE *fin;
            fin = fopen("mode1.txt", "r");
            fscanf(fin, "%d", &N);
            Assert::IsTrue(N == 10000, L"N is less than 10000.");
            for (i = 0; i < N; i += 1)
            {
                fscanf(fin, "%s", str);
                puzzle = Sudoku9(str);
                Assert::IsTrue(puzzle.isValidPuzzle());
                for (j = blank = 0; j < 9; j += 1)
                {
                    for (k = 0; k < 9; k += 1)
                    {
                        if (!puzzle.data[j][k])
                            blank += 1;
                    }
                }
                Assert::IsTrue(25 <= blank && blank <= 40, L"The number of blank is inconsistent.");
                checkSolver.set(puzzle);
                Assert::IsTrue(checkSolver.solve());
                Assert::IsFalse(checkSolver.solve());
                r = checkSolver.onlyOne();
                Assert::IsTrue(r == 81);
                ans = checkSolver.solution();
                Assert::IsTrue(ans.isValid());
                table.push_back(ans.normNode());
            }
            fclose(fin);
            std::sort(table.begin(), table.end());
            table.erase(std::unique(table.begin(), table.end()), table.end());
            Assert::IsTrue(table.size() == N, L"The number is inconsistent.");
		}

		TEST_METHOD(CheckMode2File)
		{
            Sudoku9 puzzle, ans;
            Sudoku9DLXSolver checkSolver;
            std::vector<Sudoku9Node> table;
            int i, j, k, blank, N, r;
            char str[100];
            FILE *fin;
            fin = fopen("mode2.txt", "r");
            fscanf(fin, "%d", &N);
            Assert::IsTrue(N == 10000, L"N is less than 10000.");
            for (i = 0; i < N; i += 1)
            {
                fscanf(fin, "%s", str);
                puzzle = Sudoku9(str);
                Assert::IsTrue(puzzle.isValidPuzzle());
                for (j = blank = 0; j < 9; j += 1)
                {
                    for (k = 0; k < 9; k += 1)
                    {
                        if (!puzzle.data[j][k])
                            blank += 1;
                    }
                }
                Assert::IsTrue(35 <= blank && blank <= 50, L"The number of blank is inconsistent.");
                checkSolver.set(puzzle);
                Assert::IsTrue(checkSolver.solve());
                Assert::IsFalse(checkSolver.solve());
                r = checkSolver.onlyOne();
                Assert::IsTrue(82 <= r && r <= 100, L"Difficulty is inconsistent.");
                ans = checkSolver.solution();
                Assert::IsTrue(ans.isValid());
                table.push_back(ans.normNode());
            }
            fclose(fin);
            std::sort(table.begin(), table.end());
            table.erase(std::unique(table.begin(), table.end()), table.end());
            Assert::IsTrue(table.size() == N, L"The number is inconsistent.");
		}

		TEST_METHOD(CheckMode3File)
		{
            Sudoku9 puzzle, ans;
            Sudoku9DLXSolver checkSolver;
            std::vector<Sudoku9Node> table;
            int i, j, k, blank, N, r;
            char str[100];
            FILE *fin;
            fin = fopen("mode3.txt", "r");
            fscanf(fin, "%d", &N);
            Assert::IsTrue(N == 10000, L"N is less than 10000.");
            for (i = 0; i < N; i += 1)
            {
                fscanf(fin, "%s", str);
                puzzle = Sudoku9(str);
                Assert::IsTrue(puzzle.isValidPuzzle());
                for (j = blank = 0; j < 9; j += 1)
                {
                    for (k = 0; k < 9; k += 1)
                    {
                        if (!puzzle.data[j][k])
                            blank += 1;
                    }
                }
                Assert::IsTrue(45 <= blank, L"The number of blank is inconsistent.");
                checkSolver.set(puzzle);
                Assert::IsTrue(checkSolver.solve());
                Assert::IsFalse(checkSolver.solve());
                r = checkSolver.onlyOne();
                Assert::IsTrue(121 <= r, L"Difficulty is inconsistent.");
                ans = checkSolver.solution();
                Assert::IsTrue(ans.isValid());
                table.push_back(ans.normNode());
            }
            fclose(fin);
            std::sort(table.begin(), table.end());
            table.erase(std::unique(table.begin(), table.end()), table.end());
            Assert::IsTrue(table.size() == N, L"The number is inconsistent.");
		}

		TEST_METHOD(CheckMode1Generate)
		{
            Sudoku9 puzzle, ans;
            Sudoku9DLXSolver checkSolver;
            Core core;
            std::vector<Sudoku9Node> table;
            int i, j, k, blank, N = 10000, r;
            int(*result)[81] = new int[10000][81];
            core.generate(N, 1, result);
            char info[1000];
            for (i = 0; i < N; i += 1)
            {
                for (j = 0; j < 9; j += 1)
                {
                    for (k = 0; k < 9; k += 1)
                        puzzle.data[j][k] = result[i][j * 9 + k];
                }
                Assert::IsTrue(puzzle.isValidPuzzle());
                for (j = blank = 0; j < 9; j += 1)
                {
                    for (k = 0; k < 9; k += 1)
                    {
                        if (!puzzle.data[j][k])
                            blank += 1;
                    }
                }
                Assert::IsTrue(25 <= blank && blank <= 40, L"The number of blank is inconsistent.");
                checkSolver.set(puzzle);
                Assert::IsTrue(checkSolver.solve(), L"The puzzle has no solution.");
                Assert::IsFalse(checkSolver.solve(), L"The puzzle has multiple solution.");
                ans = checkSolver.solution();
                Assert::IsTrue(ans.isValid());
                table.push_back(ans.normNode());
            }
            std::sort(table.begin(), table.end());
            table.erase(std::unique(table.begin(), table.end()), table.end());
            Assert::IsTrue(table.size() == N, L"The number is inconsistent.");
            delete[] result;
		}

		TEST_METHOD(CheckMode2Generate)
		{
            Sudoku9 puzzle, ans;
            Sudoku9DLXSolver checkSolver;
            Core core;
            std::vector<Sudoku9Node> table;
            int i, j, k, blank, N = 10000, r;
            int(*result)[81] = new int[10000][81];
            core.generate(N, 2, result);
            char info[1000];
            for (i = 0; i < N; i += 1)
            {
                for (j = 0; j < 9; j += 1)
                {
                    for (k = 0; k < 9; k += 1)
                        puzzle.data[j][k] = result[i][j * 9 + k];
                }
                Assert::IsTrue(puzzle.isValidPuzzle());
                for (j = blank = 0; j < 9; j += 1)
                {
                    for (k = 0; k < 9; k += 1)
                    {
                        if (!puzzle.data[j][k])
                            blank += 1;
                    }
                }
                Assert::IsTrue(35 <= blank && blank <= 50, L"The number of blank is inconsistent.");
                checkSolver.set(puzzle);
                Assert::IsTrue(checkSolver.solve(), L"The puzzle has no solution.");
                Assert::IsFalse(checkSolver.solve(), L"The puzzle has multiple solution.");
                ans = checkSolver.solution();
                Assert::IsTrue(ans.isValid());
                table.push_back(ans.normNode());
            }
            std::sort(table.begin(), table.end());
            table.erase(std::unique(table.begin(), table.end()), table.end());
            Assert::IsTrue(table.size() == N, L"The number is inconsistent.");
            delete[] result;
		}

		TEST_METHOD(CheckMode3Generate)
		{
            Sudoku9 puzzle, ans;
            Sudoku9DLXSolver checkSolver;
            Core core;
            std::vector<Sudoku9Node> table;
            int i, j, k, blank, N = 10000, r;
            int(*result)[81] = new int[10000][81];
            core.generate(N, 3, result);
            char info[1000];
            for (i = 0; i < N; i += 1)
            {
                for (j = 0; j < 9; j += 1)
                {
                    for (k = 0; k < 9; k += 1)
                        puzzle.data[j][k] = result[i][j * 9 + k];
                }
                Assert::IsTrue(puzzle.isValidPuzzle());
                for (j = blank = 0; j < 9; j += 1)
                {
                    for (k = 0; k < 9; k += 1)
                    {
                        if (!puzzle.data[j][k])
                            blank += 1;
                    }
                }
                Assert::IsTrue(45 <= blank, L"The number of blank is inconsistent.");
                checkSolver.set(puzzle);
                Assert::IsTrue(checkSolver.solve(), L"The puzzle has no solution.");
                Assert::IsFalse(checkSolver.solve(), L"The puzzle has multiple solution.");
                r = checkSolver.onlyOne();
                ans = checkSolver.solution();
                Assert::IsTrue(ans.isValid());
                table.push_back(ans.normNode());
            }
            std::sort(table.begin(), table.end());
            table.erase(std::unique(table.begin(), table.end()), table.end());
            Assert::IsTrue(table.size() == N, L"The number is inconsistent.");
            delete[] result;
		}

		TEST_METHOD(CheckEqualBlank20Generate)
		{
            Sudoku9 puzzle, ans;
            Sudoku9DLXSolver checkSolver;
            Core core;
            std::vector<Sudoku9Node> table;
            int i, j, k, blank, N = 10000, r;
            int(*result)[81] = new int[10000][81];
            core.generate(N, 20, 20, true, result);
            char info[1000];
            for (i = 0; i < N; i += 1)
            {
                for (j = 0; j < 9; j += 1)
                {
                    for (k = 0; k < 9; k += 1)
                        puzzle.data[j][k] = result[i][j * 9 + k];
                }
                Assert::IsTrue(puzzle.isValidPuzzle());
                for (j = blank = 0; j < 9; j += 1)
                {
                    for (k = 0; k < 9; k += 1)
                    {
                        if (!puzzle.data[j][k])
                            blank += 1;
                    }
                }
                Assert::IsTrue(blank == 20, L"The number of blank is inconsistent.");
                checkSolver.set(puzzle);
                Assert::IsTrue(checkSolver.solve(), L"The puzzle has no solution.");
                Assert::IsFalse(checkSolver.solve(), L"The puzzle has multiple solution.");
                ans = checkSolver.solution();
                Assert::IsTrue(ans.isValid());
                table.push_back(ans.normNode());
            }
            std::sort(table.begin(), table.end());
            table.erase(std::unique(table.begin(), table.end()), table.end());
            Assert::IsTrue(table.size() == N, L"The number is inconsistent.");
            delete[] result;
		}

		TEST_METHOD(CheckEqualBlank55Generate)
		{
            Sudoku9 puzzle, ans;
            Sudoku9DLXSolver checkSolver;
            Core core;
            std::vector<Sudoku9Node> table;
            int i, j, k, blank, N = 10000, r;
            int(*result)[81] = new int[10000][81];
            core.generate(N, 55, 55, true, result);
            char info[1000];
            for (i = 0; i < N; i += 1)
            {
                for (j = 0; j < 9; j += 1)
                {
                    for (k = 0; k < 9; k += 1)
                        puzzle.data[j][k] = result[i][j * 9 + k];
                }
                Assert::IsTrue(puzzle.isValidPuzzle());
                for (j = blank = 0; j < 9; j += 1)
                {
                    for (k = 0; k < 9; k += 1)
                    {
                        if (!puzzle.data[j][k])
                            blank += 1;
                    }
                }
                Assert::IsTrue(blank == 55, L"The number of blank is inconsistent.");
                checkSolver.set(puzzle);
                Assert::IsTrue(checkSolver.solve(), L"The puzzle has no solution.");
                Assert::IsFalse(checkSolver.solve(), L"The puzzle has multiple solution.");
                ans = checkSolver.solution();
                Assert::IsTrue(ans.isValid());
                table.push_back(ans.normNode());
            }
            std::sort(table.begin(), table.end());
            table.erase(std::unique(table.begin(), table.end()), table.end());
            Assert::IsTrue(table.size() == N, L"The number is inconsistent.");
            delete[] result;
		}

		TEST_METHOD(CheckCoreSolve1)
		{
            int i, j;
            int origin[81], result[81];
            Core core;
			Sudoku9 puzzle(
				"800000000"
				"003600000"
				"070090200"
				"050007000"
				"000045700"
				"000100030"
				"001000068"
				"008500010"
				"090000400"), ans;
            for (i = 0; i < 9; i += 1)
            {
                for (j = 0; j < 9; j += 1)
                    origin[i * 9 + j] = puzzle.data[i][j];
            }
			Assert::IsTrue(core.solve(origin, result));
            for (i = 0; i < 9; i += 1)
            {
                for (j = 0; j < 9; j += 1)
                    ans.data[i][j] = result[i * 9 + j];
            }
			Assert::IsTrue(ans.isValid());
			for (i = 0; i < 9; i += 1)
			{
				for (j = 0; j < 9; j += 1)
				{
					if (puzzle.data[i][j] > 0)
						Assert::IsTrue(puzzle.data[i][j] == ans.data[i][j]);
				}
			}
		}

		TEST_METHOD(CheckCoreSolve2)
		{
            int i, j;
            int origin[81], result[81];
            Core core;
			Sudoku9 puzzle(
				"000000000"
				"000000000"
				"000000000"
				"000000000"
				"000000000"
				"000000000"
				"000000000"
				"000000000"
				"000000000"), ans;
            for (i = 0; i < 9; i += 1)
            {
                for (j = 0; j < 9; j += 1)
                    origin[i * 9 + j] = puzzle.data[i][j];
            }
			Assert::IsTrue(core.solve(origin, result));
            for (i = 0; i < 9; i += 1)
            {
                for (j = 0; j < 9; j += 1)
                    ans.data[i][j] = result[i * 9 + j];
            }
			Assert::IsTrue(ans.isValid());
			for (i = 0; i < 9; i += 1)
			{
				for (j = 0; j < 9; j += 1)
				{
					if (puzzle.data[i][j] > 0)
						Assert::IsTrue(puzzle.data[i][j] == ans.data[i][j]);
				}
			}
		}

		TEST_METHOD(CheckCoreSolveNoSolution1)
		{
            int i, j;
            int origin[81], result[81];
            Core core;
			Sudoku9 puzzle(
				"801000000"
				"003600000"
				"070090200"
				"050007000"
				"000045700"
				"000100030"
				"001000068"
				"008500010"
				"090000400"), ans;
            for (i = 0; i < 9; i += 1)
            {
                for (j = 0; j < 9; j += 1)
                    origin[i * 9 + j] = puzzle.data[i][j];
            }
			Assert::IsFalse(core.solve(origin, result));
		}

		TEST_METHOD(CheckSolveException)
		{
            int i, j;
            int origin[81], result[81];
            bool catchException = false;
            Core core;
			Sudoku9 puzzle(
				"800000000"
				"003600000"
				"070090200"
				"050007000"
				"000045700"
				"000100030"
				"001000068"
				"008500010"
				"090000400"), ans;
            for (i = 0; i < 9; i += 1)
            {
                for (j = 0; j < 9; j += 1)
                    origin[i * 9 + j] = puzzle.data[i][j];
            }
            origin[80] = -1;
            try {
                core.solve(origin, result);
            }
            catch (std::invalid_argument e)
            {
                catchException = true;
                Logger::WriteMessage(e.what());
            }
            Assert::IsTrue(catchException);
		}

		TEST_METHOD(CheckGenerateException1)
		{
            int result[10][81];
            bool catchException = false;
            Core core;
            try {
                core.generate(10, 4, result);
            }
            catch (std::invalid_argument e)
            {
                catchException = true;
                Logger::WriteMessage(e.what());
            }
            Assert::IsTrue(catchException);
		}

		TEST_METHOD(CheckGenerateException2)
		{
            int result[10][81];
            bool catchException = false;
            Core core;
            try {
                core.generate(10, -1, result);
            }
            catch (std::invalid_argument e)
            {
                catchException = true;
                Logger::WriteMessage(e.what());
            }
            Assert::IsTrue(catchException);
		}

		TEST_METHOD(CheckGenerateException3)
		{
            int result[10][81];
            bool catchException = false;
            Core core;
            try {
                core.generate(10, -1, 0, true, result);
            }
            catch (std::invalid_argument e)
            {
                catchException = true;
                Logger::WriteMessage(e.what());
            }
            Assert::IsTrue(catchException);
		}

		TEST_METHOD(CheckGenerateException4)
		{
            int result[10][81];
            bool catchException = false;
            Core core;
            try {
                core.generate(10, 65, 0, true, result);
            }
            catch (std::invalid_argument e)
            {
                catchException = true;
                Logger::WriteMessage(e.what());
            }
            Assert::IsTrue(catchException);
		}

		TEST_METHOD(CheckGenerateException5)
		{
            int result[10][81];
            bool catchException = false;
            Core core;
            try {
                core.generate(10, 30, 0, true, result);
            }
            catch (std::invalid_argument e)
            {
                catchException = true;
                Logger::WriteMessage(e.what());
            }
            Assert::IsTrue(catchException);
		}
	};
}
