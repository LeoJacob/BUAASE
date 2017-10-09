#include "SudokuUI.h"

SudokuUI::SudokuUI(QWidget *parent)
	: QMainWindow(parent)
{
	int i, j;
	ui.setupUi(this);
	minTime.setHMS(23, 59, 59);
	ui.LCDMinTimeCost->display(minTime.toString("hh:mm:ss"));
	timer->setInterval(1000);
	bool flag = false;
	flag = QObject::connect(generateDialog, SIGNAL(generateSuccessfully(int **, int)), this, SLOT(receiveQues(int **, int)));
	assert(flag);
	generateDialog->show();
	flag = QObject::connect(ui._quit, SIGNAL(clicked()), qApp, SLOT(quit()));
	assert(flag);
	flag = QObject::connect(ui.getTips, SIGNAL(clicked()), this, SLOT(responseGetTips()));
	assert(flag);
	flag = QObject::connect(generateDialog, SIGNAL(destroyed()), qApp, SLOT(quit()));
	assert(flag);
	flag = QObject::connect(ui.finish, SIGNAL(clicked()), this, SLOT(responseFinish()));
	assert(flag);
	flag = QObject::connect(timer, SIGNAL(timeout()), this, SLOT(refreshLCDCurTime()));
	assert(flag);
	flag = QObject::connect(ui.curGameNumberContent, SIGNAL(textChanged(QString)), this, SLOT(refreshPreAndNextButton()));
	assert(flag);
	flag = QObject::connect(ui.preGame, SIGNAL(clicked()), this, SLOT(responsePreGame()));
	assert(flag);
	flag = QObject::connect(ui.nextGame, SIGNAL(clicked()), this, SLOT(responseNextGame()));
	assert(flag);
	flag = QObject::connect(ui.chooseGameContent, SIGNAL(textChanged(QString)), this, SLOT(refreshJump()));
	assert(flag);
	flag = QObject::connect(ui.jump, SIGNAL(clicked()), this, SLOT(responseJump()));
	assert(flag);
	flag = QObject::connect(ui.playAgain, SIGNAL(clicked()), this, SLOT(responsePlayAgain()));
	assert(flag);

	for (i = 0; i < NUMBER_OF_ROWS; i++)
	{
		for (j = 0; j < NUMBER_OF_COLUMNS; j++)
		{
			bool flag = false;
			flag = QObject::connect(ui.sudokuBox[i][j], SIGNAL(textChanged(QString)), this, SLOT(refreshAboutSudokuBox()));
			assert(flag);
		}
	}
	refreshAboutSudokuBox();
	refreshJump();
	refreshPreAndNextButton();
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

bool SudokuUI::testAnswer()
{
	int i, j;
	for (i = 0; i < NUMBER_OF_ROWS; i++)
	{
		for (j = 0; j < NUMBER_OF_COLUMNS; j++)
		{
			if (!testOneBoxValid(i, j) || ui.sudokuBox[i][j]->text().isEmpty() || ui.sudokuBox[i][j]->text().toInt() == 0)
				return false;
		}
	}
	return true;
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

void SudokuUI::refreshAboutSudokuBox()
{
	testValuechange();
	refreshGetTips();
}

void SudokuUI::receiveQues(int **ques, int iGenerateNumber)
{
	this->ques = ques;
	this->iGenerateNumber = iGenerateNumber;
	updateSudokuBox(this->ques[curQuesNumber]);
	ui.curGameNumberContent->setText(QString::number(curQuesNumber + 1));
	ui.totalGameNumberContent->setText(QString::number(iGenerateNumber));
	startTime = QTime::currentTime();
	timer->start();
	refreshAboutSudokuBox();
	refreshJump();
	refreshPreAndNextButton();
}

void SudokuUI::responseFinish()
{
	if (testAnswer())
	{
		refreshLCDMinTime();
		timer->stop();
		QMessageBox::information(NULL, "info", "\346\201\255\345\226\234\346\202\250\347\255\224\345\257\271\344\272\206\357\274\201", QMessageBox::Yes, QMessageBox::Yes);
		if (curQuesNumber + 1 < iGenerateNumber)
		{
			curQuesNumber++;
			updateSudokuBox(ques[curQuesNumber]);
			startTime = QTime::currentTime();
			timer->start();
			ui.curGameNumberContent->setText(QString::number(curQuesNumber + 1));
		}
		//提示玩家已解决所有数独题目，按“退出”键退出游戏，按“再玩一组”键重新生成数独题目并继续游戏
		QMessageBox::information(NULL, "info", "\346\201\255\345\226\234\357\274\201\346\202\250\345\267\262\345\201\232\345\257\271\346\211\200\346\234\211\346\225\260\347\213\254\351\242\230\347\233\256\357\274\201\346\214\211\342\200\234\351\200\200\345\207\272\342\200\235\345\210\231\351\200\200\345\207\272\346\270\270\346\210\217\357\274\214\346\214\211\342\200\234\345\206\215\347\216\251\344\270\200\347\273\204\342\200\235\345\210\231\351\207\215\346\226\260\347\224\237\346\210\220\346\225\260\347\213\254\351\242\230\347\233\256", QMessageBox::Yes, QMessageBox::Yes);
	}
	else {
		QMessageBox::warning(NULL, "warning", "\347\234\237\351\201\227\346\206\276\357\274\201\347\273\247\347\273\255\345\212\252\345\212\233\357\274\201\n\351\200\201\344\275\240\344\270\244\346\235\241\351\224\246\345\233\212\345\246\231\350\256\241\357\274\232\n1.\345\241\253\346\273\241\346\211\200\346\234\211\347\251\272\346\240\274\n2.\346\266\210\351\231\244\347\272\242\350\211\262\346\225\260\345\255\227", QMessageBox::Yes, QMessageBox::Yes);
	}	
}

void SudokuUI::refreshLCDCurTime()
{
	int hh, mm, ss;
	absTime = QTime::currentTime();
	hh = absTime.hour() - startTime.hour();
	mm = absTime.minute() - startTime.minute();
	ss = absTime.second() - startTime.second();
	if (ss < 0) 
	{
		ss += 60;
		mm--;
	}
	if (mm < 0)
	{
		mm += 60;
		hh--;
	}
	if (hh < 0)
		hh += 24;
	relativeTime.setHMS(hh, mm, ss);
	ui.LCDCurTimeCost->display(relativeTime.toString("hh:mm:ss"));
}

void SudokuUI::refreshLCDMinTime()
{
	if (relativeTime < minTime)
	{
		minTime = relativeTime;
		ui.LCDMinTimeCost->display(relativeTime.toString("hh:mm:ss"));
	}
}

void SudokuUI::keyPressEvent(QKeyEvent * event)
{
	cursorQWidget = QWidget::focusWidget();
	int rowId = (cursorQWidget->geometry().top() - TOP_MARGIN) / BOX_SIDE_LENGTH;
	int colId = (cursorQWidget->geometry().left() - LEFT_MARGIN) / BOX_SIDE_LENGTH;
	int i;
	if (event->key() == Qt::Key_Up)
	{
		for (i = rowId - 1; i >= 0; i--)
		{
			if (ui.sudokuBox[i][colId]->isEnabled())
			{
				rowId = i;
				break;
			}
		}
		ui.sudokuBox[rowId][colId]->setFocus();
	}
	else if (event->key() == Qt::Key_Down)
	{
		for (i = rowId + 1; i < NUMBER_OF_ROWS; i++)
		{
			if (ui.sudokuBox[i][colId]->isEnabled())
			{
				rowId = i;
				break;
			}
		}
		ui.sudokuBox[rowId][colId]->setFocus();
	}
	else if (event->key() == Qt::Key_Control)
	{
		for (i = colId - 1; i >= 0; i--)
		{
			if (ui.sudokuBox[rowId][i]->isEnabled())
			{
				colId = i;
				break;
			}
		}
		ui.sudokuBox[rowId][colId]->setFocus();
	}
	else if (event->key() == Qt::Key_Alt)
	{
		for (i = colId + 1; i < NUMBER_OF_COLUMNS; i++)
		{
			if (ui.sudokuBox[rowId][i]->isEnabled())
			{
				colId = i;
				break;
			}
		}
		ui.sudokuBox[rowId][colId]->setFocus();
	}
}

void SudokuUI::refreshPreAndNextButton()
{
	ui.preGame->setEnabled(ui.curGameNumberContent->text().toInt() > 1);
	ui.nextGame->setEnabled(ui.curGameNumberContent->text().toInt() < iGenerateNumber);
}

void SudokuUI::responsePreGame()
{
	if (curQuesNumber > 0)
	{
		timer->stop();
		curQuesNumber--;
		updateSudokuBox(ques[curQuesNumber]);
		ui.curGameNumberContent->setText(QString::number(curQuesNumber + 1));
		startTime = QTime::currentTime();
		timer->start();
	}
}

void SudokuUI::responseNextGame()
{
	if (curQuesNumber + 1 < iGenerateNumber)
	{
		timer->stop();
		curQuesNumber++;
		updateSudokuBox(ques[curQuesNumber]);
		ui.curGameNumberContent->setText(QString::number(curQuesNumber + 1));
		startTime = QTime::currentTime();
		timer->start();
	}
}

void SudokuUI::refreshJump()
{
	if (ui.chooseGameContent->text().isEmpty() || ui.chooseGameContent->text().toInt() < 1 || ui.chooseGameContent->text().toInt() > iGenerateNumber)
		ui.jump->setEnabled(false);
	else
		ui.jump->setEnabled(true);
}

void SudokuUI::responseJump()
{
	timer->stop();
	curQuesNumber = ui.chooseGameContent->text().toInt() - 1;
	updateSudokuBox(ques[curQuesNumber]);
	ui.curGameNumberContent->setText(QString::number(curQuesNumber + 1));
	startTime = QTime::currentTime();
	timer->start();
}

void SudokuUI::responsePlayAgain()
{
	generateDialog->open();
}