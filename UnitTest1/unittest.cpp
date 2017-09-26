#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Sudoku/sudoku9.h"
#include "../Sudoku/solver.h"
#include "../Sudoku/generator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
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
			vector<Sudoku9Node> check;
			T = 1000000;
			for (t = 0; t < T; t += 1)
			{
				puzzle = generator.generate();
				check.push_back(puzzle.node());
			}
			sort(check.begin(), check.end());
			check.erase(unique(check.begin(), check.end()), check.end());
			Assert::IsTrue(check.size() == T);
		}

		TEST_METHOD(DLXSolverTestHasSolution)
		{
			vector<pair<int, int> > ones;
			ones.push_back(make_pair(0, 2));
			ones.push_back(make_pair(0, 4));
			ones.push_back(make_pair(0, 5));
			ones.push_back(make_pair(1, 0));
			ones.push_back(make_pair(1, 3));
			ones.push_back(make_pair(1, 6));
			ones.push_back(make_pair(2, 1));
			ones.push_back(make_pair(2, 2));
			ones.push_back(make_pair(2, 5));
			ones.push_back(make_pair(3, 0));
			ones.push_back(make_pair(3, 3));
			ones.push_back(make_pair(4, 1));
			ones.push_back(make_pair(4, 6));
			ones.push_back(make_pair(5, 3));
			ones.push_back(make_pair(5, 4));
			ones.push_back(make_pair(5, 6));
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

	};
}