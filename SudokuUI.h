#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_SudokuUI.h"
#include "GenetateNumber.h"
#include <QTime>
#include <QTimer>
#include <QCloseEvent>

class SudokuUI : public QMainWindow
{
	Q_OBJECT

public:
	
	Ui::SudokuUIClass ui;
	GenetateNumber *generateDialog; 
	QTimer *timer; 
	QTime relativeTime, easyMinTime, mediumMinTime, hardMinTime, customMinTime;
	QTime *minTime;
	QWidget *cursorQWidget;
	FILE *fin;
	FILE *fout;
	int **ques;
	int iGenerateNumber;
	int curQuesNumber = 0;
	SudokuUI(QWidget *parent = Q_NULLPTR);
	void readSudokuBox(int(&data)[81]);
	void updateSudokuBox(int value[81], int rowId = -1, int colId = -1);
	
	bool searchTipsPos(int &rowId, int &colId);
	
	bool testOneBoxValid(int rowId, int colId);
	void testValuechange();
	bool testAnswer();
	void refreshLCDMinTime();
	void refreshContinueButton();
	void closeEvent(QCloseEvent * event);

protected:
	void keyPressEvent(QKeyEvent * event);

public slots:
	void _quit();
	void receiveQues();
	void refreshAboutSudokuBox();
	void responseGetTips(int rowId, int colId);
	void responseFinish();
	void refreshLCDCurTime();
	void refreshPreAndNextButton();
	void responsePreGame();
	void responseNextGame();
	void refreshJump();
	void responseJump();
	void responsePlayAgain();
	void responsePause();
	void responseContinue();
	void responseGetHelp();
};
