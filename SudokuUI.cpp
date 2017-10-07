#include "SudokuUI.h"

SudokuUI::SudokuUI(QWidget *parent)
	: QMainWindow(parent)
{
	int i, j;
	ui.setupUi(this);
	
	QObject::connect(ui._quit, SIGNAL(clicked()), qApp, SLOT(quit()));
	//想每修改一次就检查一遍是否合法，调用语句后半部分有问题
	for (i = 0; i < NUMBER_OF_ROWS; i++)
	{
		for (j = 0; j < NUMBER_OF_COLUMNS; j++)
		{
			bool flag = false;
			flag = QObject::connect(ui.sudokuBox[i][j], SIGNAL(textChanged(QString)), this, SLOT(testValuechange()));//失败
			assert(flag);
		}
	}
	
}

void SudokuUI::readSudokuBox(int(&data)[NUMBER_OF_ROWS*NUMBER_OF_COLUMNS])
{
	int i, j;
	for (i = 0; i < NUMBER_OF_ROWS; i++)
	{
		for (j = 0; j < NUMBER_OF_COLUMNS; j++)
		{
			if (ui./*puzzle.*/sudokuBox[i][j]->text().length() == 0)
				data[i*NUMBER_OF_COLUMNS + j] = 0;
			else
				data[i*NUMBER_OF_COLUMNS + j] = ui./*puzzle.*/sudokuBox[i][j]->text().toInt();
		}
	}
}

void SudokuUI::updateSudokuBox(int(&value)[81], int rowId, int colId)
{
	int i, j;
	//提示功能，只更新一个格子，并修改状态为不可编辑
	if (rowId >= 0 && rowId < NUMBER_OF_ROWS - 1 && colId >= 0 && colId < NUMBER_OF_COLUMNS) 
	{
		ui.sudokuBox[rowId][colId]->setText(QString::number(value[rowId*NUMBER_OF_COLUMNS + colId]));
		ui.sudokuBox[rowId][colId]->setEnabled(false);
		return ;
	}

	//更新题目，更新所有格子
	for (i = 0; i < NUMBER_OF_ROWS; i++)
	{
		for (j = 0; j < NUMBER_OF_COLUMNS; j++)
		{
			if (value[i*NUMBER_OF_COLUMNS + j] == 0) 
			{
				ui.sudokuBox[i][j]->setText("");
				ui.sudokuBox[i][j]->setEnabled(true);
			}
			else
			{
				ui.sudokuBox[i][j]->setText(QString::number(value[i*NUMBER_OF_COLUMNS + j]));
				ui.sudokuBox[i][j]->setEnabled(false);
			}
		}
	}
}

bool SudokuUI::searchTipsPos(int &rowId, int &colId)
{
	int i, j;
	rowId = colId = -1;
	for (i = 0; i < NUMBER_OF_ROWS; i++)
	{
		for (j = 0; j < NUMBER_OF_COLUMNS; j++)
		{
			if (ui.sudokuBox[i][j]->text().length() == 0)
			{
				rowId = i;
				colId = j;
				return true;
			}
		}
	}
	return false;
}

/*“提示”按钮响应函数
		1.若找到空，根据当前数独状态计算结果，
			若有解，则调用updateSudokuBox函数，提示一个数，
			若无解，提示玩家无解
		2.若找不到空，提示玩家不需要提示
*/
void SudokuUI::responseGetTips()
{
	int rowId, colId;
	if (searchTipsPos(rowId, colId)) 
	{
		int puzzle[NUMBER_OF_ROWS*NUMBER_OF_COLUMNS] = {};
		int solution[NUMBER_OF_ROWS*NUMBER_OF_COLUMNS] = {};
		readSudokuBox(puzzle);
		//solve(&puzzle, solution);			//调用求解数独接口，求得当前状态数独的解
		updateSudokuBox(curQues->content, rowId, colId);
	}
	else
	{
		//处理玩家已填满空格，却按提示的情况。
	}
}

bool SudokuUI::testOneBoxValid(int rowId, int colId)
{
	if (ui.sudokuBox[rowId][colId]->text().length() == 1)
	{
		int i, j;
		int newValue;
		if (ui.sudokuBox[rowId][colId]->text().length() != 1)
			return true;
		else
			newValue = ui.sudokuBox[rowId][colId]->text().toInt();

		for (i = 0; i < NUMBER_OF_ROWS; i++)
		{
			if (rowId == i || ui.sudokuBox[i][colId]->text().length() != 1)
				continue;
			else if (newValue == ui.sudokuBox[i][colId]->text().toInt())
				return false;
		}

		for (j = 0; j < NUMBER_OF_COLUMNS; j++)
		{
			if (colId == j || ui.sudokuBox[rowId][j]->text().length() != 1)
				continue;
			else if (newValue == ui.sudokuBox[rowId][j]->text().toInt())
				return false;
		}

		int blockRowId = rowId / 3 * 3;
		int blockColId = colId / 3 * 3;
		for (i = blockRowId; i < blockRowId + 3; i++)
		{
			for (j = blockColId; j < blockColId + 3; j++)
			{
				if ((i == rowId && j == colId) || ui.sudokuBox[i][j]->text().length() != 1)
					continue;
				else if (newValue == ui.sudokuBox[i][j]->text().toInt())
					return false;
			}
		}
	}
	return true;
}

void SudokuUI::testValuechange()
{
	int rowId, colId;
	for (rowId = 0; rowId < NUMBER_OF_ROWS; rowId++)
	{
		for (colId = 0; colId < NUMBER_OF_COLUMNS; colId++)
		{
			if (!testOneBoxValid(rowId, colId))
				ui.sudokuBox[rowId][colId]->setStyleSheet("color:red");
			else
				ui.sudokuBox[rowId][colId]->setStyleSheet("color:black");
		}
	}
}


