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
	bool flag = false;
	DLXNode *head = NULL;
	vector<int> choose, res;

	int pid = 0;
	vector<DLXNode *> pool;

	void coverColumn(DLXNode *colHead);

	void uncoverColumn(DLXNode *colHead);

	void dfs();

	inline DLXNode *allocateNode();

public:
	DLXSolver();

	DLXSolver(vector<pair<int, int> > &ones, int colCnt);

	~DLXSolver();

	void set(vector<pair<int, int> > &ones, int colCnt);

	bool solve();

	vector<int> solution();
};