#include "SudokuUI.h"

SudokuUI::SudokuUI(QWidget *parent)
	: QMainWindow(parent)
{
	int i, j;
	ui.setupUi(this);
	this->ques = ques;
	this->iGenerateNumber = iGenerateNumber;
	bool flag = false;
	flag = QObject::connect(generateDialog, SIGNAL(generateSuccessfully(int **, int)), this, SLOT(receiveQues(int **, int)));
	assert(flag);
	generateDialog->show();
	flag = QObject::connect(ui._quit, SIGNAL(clicked()), qApp, SLOT(quit()));
	assert(flag);
	flag = QObject::connect(ui.getTips, SIGNAL(clicked()), this, SLOT(responseGetTips()));
	assert(flag);

	for (i = 0; i < NUMBER_OF_ROWS; i++)
	{
		for (j = 0; j < NUMBER_OF_COLUMNS; j++)
		{
			bool flag = false;
			flag = QObject::connect(ui.sudokuBox[i][j], SIGNAL(textChanged(QString)), this, SLOT(refreshAll()));
			assert(flag);
		}
	}
	refreshAll();
}

void SudokuUI::readSudokuBox(int(&data)[81])
{
	int i, j;
	for (i = 0; i < NUMBER_OF_ROWS; i++)
	{
		for (j = 0; j < NUMBER_OF_COLUMNS; j++)
		{
			if (ui.sudokuBox[i][j]->text().isEmpty())
				data[i*NUMBER_OF_COLUMNS + j] = 0;
			else
				data[i*NUMBER_OF_COLUMNS + j] = ui.sudokuBox[i][j]->text().toInt();
		}
	}
}

void SudokuUI::updateSudokuBox(int value[81], int rowId, int colId)
{
	int i, j;
	//��ʾ���ܣ�ֻ����һ�����ӣ����޸�״̬Ϊ���ɱ༭
	if (rowId >= 0 && rowId < NUMBER_OF_ROWS - 1 && colId >= 0 && colId < NUMBER_OF_COLUMNS) 
	{
		ui.sudokuBox[rowId][colId]->setText(QString::number(value[rowId*NUMBER_OF_COLUMNS + colId]));
		ui.sudokuBox[rowId][colId]->setEnabled(false);
		return ;
	}

	//������Ŀ���������и���
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
			if (ui.sudokuBox[i][j]->text().isEmpty())
			{
				rowId = i;
				colId = j;
				return true;
			}
		}
	}
	return false;
}

/*����ʾ����ť��Ӧ����
		1.���ҵ��գ����ݵ�ǰ����״̬��������
			���н⣬�����updateSudokuBox��������ʾһ������
			���޽⣬��ʾ����޽�
		2.���Ҳ����գ���ʾ��Ҳ���Ҫ��ʾ
*/
void SudokuUI::responseGetTips()
{
	int rowId, colId;
	if (searchTipsPos(rowId, colId)) 
	{
		int puzzle[NUMBER_OF_ROWS*NUMBER_OF_COLUMNS] = {};
		int solution[NUMBER_OF_ROWS*NUMBER_OF_COLUMNS] = {};
		readSudokuBox(puzzle);
		//solve(&puzzle, solution);			//������������ӿڣ���õ�ǰ״̬�����Ľ�
		int temp[81] = { 1, 2, 3, 4, 5, 6, 7, 8, 9,
							4, 5, 6, 7, 8, 9, 1, 2, 3,
							7, 8, 9, 1, 2, 3, 4, 5, 6,
							2, 3, 1, 5, 6, 4, 8, 9, 7,
							5, 6, 4, 8, 9, 0, 2, 3, 1,
							8, 9, 7, 2, 3, 1, 5, 6, 4,
							3, 1, 2, 6, 4, 5, 9, 0, 8,
							6, 4, 5, 9, 7, 0, 3, 1, 2,
							0, 7, 8, 0, 1, 2, 6, 4, 5 };
		for (int i = 0; i < 81; i++)
			solution[i] = temp[i];
		updateSudokuBox(solution, 2, 3);
		//updateSudokuBox(solution, rowId, colId);
	}
	else
	{
		//��������������ո�ȴ����ʾ�������
	}
}

bool SudokuUI::testOneBoxValid(int rowId, int colId)
{
	if (ui.sudokuBox[rowId][colId]->text().length() == 1)
	{
		int i, j;
		int newValue;
		if (ui.sudokuBox[rowId][colId]->text().isEmpty())
			return true;
		else
			newValue = ui.sudokuBox[rowId][colId]->text().toInt();

		for (i = 0; i < NUMBER_OF_ROWS; i++)
		{
			if (rowId == i || ui.sudokuBox[i][colId]->text().isEmpty())
				continue;
			else if (newValue == ui.sudokuBox[i][colId]->text().toInt())
				return false;
		}

		for (j = 0; j < NUMBER_OF_COLUMNS; j++)
		{
			if (colId == j || ui.sudokuBox[rowId][j]->text().isEmpty())
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
				if ((i == rowId && j == colId) || ui.sudokuBox[i][j]->text().isEmpty())
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

void SudokuUI::refreshGetTips()
{
	bool en;
	int i, j;
	for (i = 0; i < NUMBER_OF_ROWS; i++)
	{
		for (j = 0; j < NUMBER_OF_COLUMNS; j++)
		{
			if (ui.sudokuBox[i][j]->text().isEmpty())
			{
				en = true;
				break;
			}
		}
	}
	ui.getTips->setEnabled(en);
}

void SudokuUI::refreshAll()
{
	testValuechange();
	refreshGetTips();
}

void SudokuUI::receiveQues(int **ques, int iGenerateNumber)
{
	this->ques = ques;
	this->iGenerateNumber = iGenerateNumber;
	updateSudokuBox(this->ques[curQuesNumber]);
}

void SudokuUI::responseFinish()
{

}
