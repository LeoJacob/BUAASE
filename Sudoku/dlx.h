#pragma once
#include <vector>
#include <algorithm>

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
	bool flag = false, duplicate = false;
	DLXNode *head = NULL;
	std::vector<int> choose, res;
    std::vector<DLXNode *> pre;

	int pid = 0;
    int cnt = 0;
	std::vector<DLXNode *> pool;

	void coverColumn(DLXNode *colHead);

	void uncoverColumn(DLXNode *colHead);

	void dfs(int level, bool init);

    void onlyDFS();

	inline DLXNode *allocateNode();

public:
	DLXSolver();

	DLXSolver(std::vector<std::pair<int, int> > &ones, int colCnt);

	~DLXSolver();

	void set(std::vector<std::pair<int, int> > &ones, int colCnt);

	bool solve();

    bool onlyOne();

    int size();

	std::vector<int> solution();
};