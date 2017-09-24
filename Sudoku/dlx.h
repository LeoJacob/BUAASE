#pragma once
#include <vector>
#include <algorithm>

using namespace std;

class DLXNode
{
public:
	int size, rid;
	DLXNode *L, *R, *U, *D, *colHead;

	DLXNode();
};

class DLXSolver
{
private:
	bool flag;
	DLXNode *head;
	vector<int> choose, res;

	void coverColumn(DLXNode *colHead);

	void uncoverColumn(DLXNode *colHead);

	void dfs();

public:
	DLXSolver(vector<pair<int, int> > ones, int colCnt);

	~DLXSolver();

	bool solve();

	vector<int> solution();
};