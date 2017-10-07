#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_SudokuUI.h"

struct ques
{
	int content[NUMBER_OF_ROWS*NUMBER_OF_COLUMNS] = {};
	struct ques *next=nullptr;
};

class SudokuUI : public QMainWindow
{
	Q_OBJECT

public:
	
	Ui::SudokuUIClass ui;
	struct ques *curQues=nullptr;

	SudokuUI(QWidget *parent = Q_NULLPTR);
	void readSudokuBox(int (&data)[NUMBER_OF_ROWS*NUMBER_OF_COLUMNS]);

	void updateSudokuBox(int (&value)[81], int rowId = -1, int colId = -1);
	bool searchTipsPos(int &rowId, int &colId);
	void responseGetTips();
	bool testOneBoxValid(int rowId, int colId);

public slots:
	void testValuechange();
};
