#pragma once
#include <vector>
#include <algorithm>

class __declspec(dllexport) DLXNode
{
public:
	int size, rid;
	DLXNode *L, *R, *U, *D, *colHead;

	DLXNode();
};

class DLXSolver
{
public:
	bool flag = false, duplicate = false;
	DLXNode *head = NULL;
	std::vector<int> choose, res;
    std::vector<DLXNode *> pre;

	int pid = 0;
    int cnt = 0;
	std::vector<DLXNode *> pool;

	__declspec(dllexport) void coverColumn(DLXNode *colHead);

	__declspec(dllexport) void uncoverColumn(DLXNode *colHead);

	__declspec(dllexport) void dfs(int level, bool init);

	__declspec(dllexport) void onlyDFS();

	__declspec(dllexport) inline DLXNode *allocateNode();


	__declspec(dllexport) DLXSolver();

	__declspec(dllexport) DLXSolver(std::vector<std::pair<int, int> > &ones, int colCnt);

	__declspec(dllexport) ~DLXSolver();

	__declspec(dllexport) void set(std::vector<std::pair<int, int> > &ones, int colCnt);

	__declspec(dllexport) bool solve();

	__declspec(dllexport) bool onlyOne();

	__declspec(dllexport) int size();

	__declspec(dllexport) std::vector<int> solution();
};