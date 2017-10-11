#include "SudokuUI.h"
#define CUSTOM_MODE 0
#define EASY_MODE 1
#define MEDIUM_MODE 2
#define HARD_MODE 3

SudokuUI::SudokuUI(QWidget *parent)
	: QMainWindow(parent)
{
	int i, j;
	ui.setupUi(this);
	easyMinTime.setHMS(23, 59, 59);
	mediumMinTime.setHMS(23, 59, 59);
	hardMinTime.setHMS(23, 59, 59);
	customMinTime.setHMS(23, 59, 59);
	minTime = &easyMinTime;
	relativeTime.setHMS(0, 0, 0);
	generateDialog = new GenetateNumber;
	timer = new QTimer;
	ui.LCDMinTimeCost->display(minTime->toString("hh:mm:ss"));
	ui.LCDCurTimeCost->display(relativeTime.toString("hh:mm:ss"));
	timer->setInterval(1000);
	bool flag = false;
	flag = QObject::connect(generateDialog, SIGNAL(generateSuccessfully(int **, int, int)), this, SLOT(receiveQues(int **, int, int)));
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
	flag = QObject::connect(ui.pauseButton, SIGNAL(clicked()), this, SLOT(responsePause()));
	assert(flag);
	flag = QObject::connect(ui.continueButton, SIGNAL(clicked()), this, SLOT(responseContinue()));
	assert(flag);
	flag = QObject::connect(ui.getHelp, SIGNAL(clicked()), this, SLOT(responseGetHelp()));
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
	refreshContinueButton();
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

void SudokuUI::receiveQues(int **ques, int iGenerateNumber, int iMode)
{
	this->ques = ques;
	this->iGenerateNumber = iGenerateNumber;
	curQuesNumber = 0;
	switch (iMode)
	{
	case CUSTOM_MODE:
		minTime = &customMinTime;
		ui.difficultyContent->setText(CUSTOM_CODE);
		break;
	case EASY_MODE:
		minTime = &easyMinTime;
		ui.difficultyContent->setText(EASY_CODE);
		break;
	case MEDIUM_MODE:
		minTime = &mediumMinTime;
		ui.difficultyContent->setText(MEDIUM_CODE);
		break;
	case HARD_MODE:
		minTime = &hardMinTime;
		ui.difficultyContent->setText(HARD_CODE);
		break;
	default:
		break;
	}
	updateSudokuBox(this->ques[curQuesNumber]);
	ui.curGameNumberContent->setText(QString::number(curQuesNumber + 1));
	ui.totalGameNumberContent->setText(QString::number(iGenerateNumber));
	relativeTime.setHMS(0, 0, 0);
	ui.LCDCurTimeCost->display(relativeTime.toString("hh:mm:ss"));
	ui.LCDMinTimeCost->display(minTime->toString("hh:mm:ss"));
	timer->start();
	ui.continueButton->setDisabled(true);
	ui.pauseButton->setEnabled(true);
	ui.getTips->setEnabled(true);
	ui.finish->setEnabled(true);
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
		QMessageBox::information(NULL, "\346\217\220\347\244\272", "\346\201\255\345\226\234\346\202\250\347\255\224\345\257\271\344\272\206\357\274\201", QMessageBox::Yes, QMessageBox::Yes);
		if (curQuesNumber + 1 < iGenerateNumber)
		{
			curQuesNumber++;
			updateSudokuBox(ques[curQuesNumber]);
			relativeTime.setHMS(0, 0, 0);
			timer->start();
			ui.curGameNumberContent->setText(QString::number(curQuesNumber + 1));
			
		}else 
		//提示玩家已解决所有数独题目，按“退出”键退出游戏，按“再玩一组”键重新生成数独题目并继续游戏
			QMessageBox::information(NULL, "\346\217\220\347\244\272", "\346\201\255\345\226\234\357\274\201\346\202\250\345\267\262\345\201\232\345\257\271\346\211\200\346\234\211\346\225\260\347\213\254\351\242\230\347\233\256\357\274\201\346\214\211\342\200\234\351\200\200\345\207\272\342\200\235\345\210\231\351\200\200\345\207\272\346\270\270\346\210\217\357\274\214\346\214\211\342\200\234\345\206\215\347\216\251\344\270\200\347\273\204\342\200\235\345\210\231\351\207\215\346\226\260\347\224\237\346\210\220\346\225\260\347\213\254\351\242\230\347\233\256", QMessageBox::Yes, QMessageBox::Yes);
	}
	else {
		QMessageBox::warning(NULL, "\346\217\220\347\244\272", "\347\234\237\351\201\227\346\206\276\357\274\201\347\273\247\347\273\255\345\212\252\345\212\233\357\274\201\n\351\200\201\344\275\240\344\270\244\346\235\241\351\224\246\345\233\212\345\246\231\350\256\241\357\274\232\n1.\345\241\253\346\273\241\346\211\200\346\234\211\347\251\272\346\240\274\n2.\346\266\210\351\231\244\347\272\242\350\211\262\346\225\260\345\255\227", QMessageBox::Yes, QMessageBox::Yes);
	}	
}

void SudokuUI::refreshLCDCurTime()
{
	int hh, mm, ss;
	hh = relativeTime.hour();
	mm = relativeTime.minute();
	ss = relativeTime.second();
	if (hh > 23)
		return;
	ss += 1;
	if (ss == 60)
	{
		ss -= 60;
		mm += 1;
	}
	if (mm == 60)
	{
		mm -= 60;
		hh += 1;
	}
	if (hh == 24)
		QMessageBox::information(NULL, "\346\217\220\347\244\272", "\346\202\250\345\267\262\347\273\217\347\264\257\350\256\241\347\216\251\350\277\231\347\233\230\346\225\260\347\213\25424\345\260\217\346\227\266\344\272\206\357\274\214\350\257\267\346\263\250\346\204\217\350\272\253\344\275\223\357\274\214\345\201\245\345\272\267\346\270\270\346\210\217\357\274\214\345\246\202\346\236\234\346\202\250\346\210\220\345\212\237\351\227\257\350\277\207\346\255\244\345\205\263\357\274\214\346\202\250\347\232\204\346\210\220\347\273\251\345\260\206\350\242\253\350\256\260\344\270\27223\357\274\23259\357\274\23259\357\274\214\347\273\247"
			"\347\273\255\345\212\240\346\262\271\345\223\246~", QMessageBox::Yes, QMessageBox::Yes);
	else
	{
		relativeTime.setHMS(hh, mm, ss);
		ui.LCDCurTimeCost->display(relativeTime.toString("hh:mm:ss"));
	}
}

void SudokuUI::refreshLCDMinTime()
{
	if (relativeTime < *minTime)
	{
		*minTime = relativeTime;
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
	else if (event->key() == Qt::Key_F1)
	{
		if (ui.preGame->isEnabled())
			responsePreGame();
	}
	else if (event->key() == Qt::Key_F2)
	{
		if (ui.nextGame->isEnabled())
			responseNextGame();
	}
	else if (event->key() == Qt::Key_F3)
	{
		ui.chooseGameContent->setFocus();
	}
	else if (event->key() == Qt::Key_F4)
	{
		if (ui.jump->isEnabled())
			responseJump();
	}
	else if (event->key() == Qt::Key_F5)
	{
		if (ui.getTips->isEnabled())
			responseGetTips();
	}
	else if (event->key() == Qt::Key_F6)
	{
		if (ui.finish->isEnabled())
			responseFinish();
	}
	else if (event->key() == Qt::Key_F7)
	{
		if (ui.playAgain->isEnabled())
			responsePlayAgain();
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
		relativeTime.setHMS(0, 0, 0);
		timer->start();
		ui.continueButton->setDisabled(true);
		ui.pauseButton->setEnabled(true);
		ui.getTips->setEnabled(true);
		ui.finish->setEnabled(true);
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
		relativeTime.setHMS(0, 0, 0);
		timer->start();
		ui.continueButton->setDisabled(true);
		ui.pauseButton->setEnabled(true);
		ui.getTips->setEnabled(true);
		ui.finish->setEnabled(true);
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
	relativeTime.setHMS(0, 0, 0);
	timer->start();
	ui.continueButton->setDisabled(true);
	ui.pauseButton->setEnabled(true);
	ui.getTips->setEnabled(true);
	ui.finish->setEnabled(true);
}

void SudokuUI::responsePlayAgain()
{
	generateDialog->open();
}

void SudokuUI::responsePause()
{
	timer->stop();
	ui.pauseButton->setDisabled(true);
	ui.continueButton->setEnabled(true);
	ui.getTips->setDisabled(true);
	ui.finish->setDisabled(true);
}

void SudokuUI::responseContinue()
{
	timer->start();
	ui.continueButton->setDisabled(true);
	ui.pauseButton->setEnabled(true);
	ui.getTips->setEnabled(true);
	ui.finish->setEnabled(true);
}

void SudokuUI::refreshContinueButton()
{
	ui.continueButton->setEnabled(!ui.pauseButton->isEnabled());
}

void SudokuUI::responseGetHelp()
{
	QMessageBox::information(NULL, "\345\270\256\345\212\251\346\211\213\345\206\214", "\346\254\242\350\277\216\346\235\245\345\210\260\345\270\256\345\212\251\346\211\213\345\206\214\357\274\201\345\270\214\346\234\233\350\203\275\345\244\237\345\270\256\345\212\251\344\275\240~\n\n    1.\345\275\223\346\202\250\346\203\263\347\216\251\344\270\212\344\270\200\345\205\263"
		"\346\227\266\357\274\214\350\257\267\345\215\225\345\207\273\342\200\234\344\270\212\344\270\200\345\205\263\342\200\235(\345\277\253\346\215\267\351\224\256F1)\357\274\214\346\233\264\346\215\242\350\207\263\344\270\212\344\270\200\351\242\230\343\200\202\n    2.\345\275\223\346\202\250\346\203\263\347\216\251\344\270\213\344\270\200\345\205\263\346\227\266\357\274\214\350\257\267\345\215\225\345\207\273\342\200\234\344\270\213\344\270\200\345\205\263\342\200\235(\345\277\253\346\215\267\351\224\256F2)\357\274\214\346\233\264\346\215\242\350\207\263\344\270\213\344\270\200\351\242\230\343\200\202\n    3.\345\275\223\346\202\250\346\203\263\347\216\251\346\237\220\344\270\200\345\205\263\346\227\266\357\274\214\344\271\237\345\217\257\344\273\245\346\211\213\345"
		"\212\250\351\200\211\345\205\263\357\274\232\345\234\250\345\217\263\344\276\247\350\276\223\345\205\245\346\241\206(\345\277\253\346\215\267\351\224\256F3)\344\270\255\350\276\223\345\205\245\345\205\263\345\215\241\347\274\226\345\217\267\357\274\214\347\204\266\345\220\216\345\215\225\345\207\273\342\200\234\350\267\263\350\275\254\342\200\235(\345\277\253\346\215\267\351\224\256F4)\343\200\202\n    4.\345\275\223\346\202\250\351\201\207\345\210\260\345\233\260\351\232\276\346\227\266\357\274\214\350\257\267\345\215\225\345\207\273\342\200\234\346\217\220\347\244\272\342\200\235(\345\277\253\346\215\267\351\224\256F5)\357\274\214\345\272\224\347\224\250\345\260\206\346\214\211\347\205\247\351\273\230\350\256\244\351\241\272\345\272\217\344\270\272\346\202\250\345\241\253\344\270\200\344\270\252\346\225\260\343\200\202\n    5.\345\275\223\346\202\250\345\256\214\346\210\220\346\270\270\346\210\217\346\227\266\357\274\214\350\257\267\345\215\225\345\207\273\342\200\234\345\256\214\346\210\220\342\200\235(\345\277\253\346\215\267\351\224\256F6)\357\274\214\345\272\224\347\224\250\345\260\206\344\270\272\346\202\250\346\243\200\346\237\245\347\273\223\346\236\234\343\200\202\n    6.\345\246\202\346\236\234\346\202\250\345\270\214\346\234\233\345\206\215\347\216\251\344\270\200\347\273\204\346\225\260\347\213\254\346\270\270\346\210\217\357\274\214\350\257\267\345\215\225\345\207\273\342\200\234\345\206\215\347\216\251\344\270\200\347\273\204\342\200\235(\345\277\253\346\215\267\351\224\256F7)\357\274\214\346\216\245\344\270\213\346\235\245\346\202\250\345\260\206\345\217\257\344\273\245\351\207\215\346\226\260\351\200\211\346\213\251\346\270"
		"\270\346\210\217\346\250\241\345\274\217\345\222\214\345\205\263\345\215\241\346\225\260\343\200\202\n    7.\346\232\202\345\201\234/\347\273\247\347\273\255\346\270\270\346\210\217\350\257\267\345\215\225\345\207\273\342\200\234\346\232\202\345\201\234\346\270\270\346\210\217\342\200\235(\345\277\253\346\215\267\351\224\256F8)/\342\200\234\347\273\247\347\273\255\346\270\270\346\210\217\342\200\235(\345\277\253\346\215\267\351\224\256F9)\346\214\211\351\222\256\343\200\202\n    8.\346\237\245\347\234\213\346\234\254\345\270\256\345\212\251\346\211\213\345\206\214\345\277\253\346\215\267\351\224\256\344\270\272F10\n\n\345\217\213\346\203\205\346\217\220\347\244\272\357\274\232\346\257\217\344\270\200\345\205\263\347\232\204\351\232\276\345\272\246\351\203\275\346\230\257\344\270\200\346\240\267\347\232\204\345\223\246~", QMessageBox::Yes, QMessageBox::Yes);
}
