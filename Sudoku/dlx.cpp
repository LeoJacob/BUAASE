#include "stdafx.h"
#include "dlx.h"
#include <vector>
#include <algorithm>

using namespace std;

DLXNode::DLXNode()
{
	size = 0;
	rid = -1;
	L = R = U = D = colHead = NULL;
}

void DLXSolver::coverColumn(DLXNode *colHead)
{
	DLXNode *row, *col;
	//printf("cover col %d\n", colHead->rid);
	colHead->R->L = colHead->L;
	colHead->L->R = colHead->R;
	for (row = colHead->D; row != colHead; row = row->D)
	{
		for (col = row->R; col != row; col = col->R)
		{
			col->U->D = col->D;
			col->D->U = col->U;
			col->colHead->size -= 1;
		}
	}
}

void DLXSolver::uncoverColumn(DLXNode *colHead)
{
	DLXNode *row, *col;
	//printf("uncover col %d\n", colHead->rid);
	for (row = colHead->U; row != colHead; row = row->U)
	{
		for (col = row->L; col != row; col = col->L)
		{
			col->colHead->size += 1;
			col->U->D = col;
			col->D->U = col;
		}
	}
	colHead->R->L = colHead;
	colHead->L->R = colHead;
}

void DLXSolver::dfs()
{
	int size = ~0u >> 1;
	DLXNode *colHead = head, *row, *nxt, *col;
	if (head->R == head)
	{
		flag = true;
		res = choose;
		sort(res.begin(), res.end());
		return;
	}
	for(colHead = nxt = head->R, size = colHead->size;colHead != head;colHead = colHead->R)
	{
		if (colHead->size < size)
		{
			nxt = colHead;
			size = colHead->size;
		}
		//printf("col %d, size: %d\n", colHead->rid, colHead->size);
	}
	//printf("choose col %d to cover, size: %d\n", nxt->rid, nxt->size);
	row = colHead = nxt;
	coverColumn(colHead);
	for (row = colHead->D; row != colHead && !flag; row = row->D)
	{
		for (col = row->R; col != row; col = col->R)
			coverColumn(col->colHead);
		choose.push_back(row->rid);
		dfs();
		choose.pop_back();
		for (col = row->L; col != row; col = col->L)
			uncoverColumn(col->colHead);
	}
	uncoverColumn(colHead);
}

inline DLXNode *DLXSolver::allocateNode()
{
	if (pid >= pool.size())
		pool.push_back(new DLXNode());
	return pool[pid++];
}

DLXSolver::DLXSolver()
{
	pid = 0;
	flag = false;
	head = NULL;
}

DLXSolver::DLXSolver(vector<pair<int, int> > &ones, int colCnt)
{
	set(ones, colCnt);
}

void DLXSolver::set(vector<pair<int, int> > &ones, int colCnt)
{
	int i, rid, x, y;
	vector<DLXNode *> colHead;
	DLXNode *rowHead = NULL, *p;
	pid = 0;
	choose.erase(choose.begin(), choose.end());
	head = allocateNode();
	head->L = head->R = head;
	for (i = 0; i < colCnt; i += 1)
	{
		colHead.push_back(allocateNode());
		colHead[i]->rid = i;
		colHead[i]->R = head;
		colHead[i]->L = head->L;
		colHead[i]->L->R = colHead[i];
		colHead[i]->R->L = colHead[i];
		colHead[i]->U = colHead[i]->D = colHead[i];
		colHead[i]->size = 0;
	}
	//sort(ones.begin(), ones.end());
	//ones.erase(unique(ones.begin(), ones.end()), ones.end());
	for (i = 0, rid = -1; i < ones.size(); i += 1)
	{
		x = ones[i].first;
		y = ones[i].second;
		p = allocateNode();
		p->rid = x;
		p->U = colHead[y]->U;
		p->D = colHead[y];
		p->U->D = p;
		p->D->U = p;
		if (!i || rid != x)
		{
			rid = x;
			rowHead = p;
			p->L = p->R = p;
		}
		p->R = rowHead;
		p->L = rowHead->L;
		p->L->R = p;
		p->R->L = p;
		p->colHead = colHead[y];
		p->colHead->size += 1;
	}
	flag = false;
}

bool DLXSolver::solve()
{
	dfs();
	return flag;
}

vector<int> DLXSolver::solution()
{
	return res;
}

DLXSolver::~DLXSolver()
{
	int i;
	for (i = 0; i < pool.size(); i += 1)
		delete pool[i];
}