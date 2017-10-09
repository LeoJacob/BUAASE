#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_SudokuUI.h"
#include "GenetateNumber.h"
#include "ui_finishMessage.h"
#include <QTime>
#include <QTimer>

class SudokuUI : public QMainWindow
{
	Q_OBJECT

public:
	
	Ui::SudokuUIClass ui;
	GenetateNumber *generateDialog = new GenetateNumber;
	QTimer *timer=new QTimer;
	QTime startTime, absTime, relativeTime, minTime;
	QWidget *cursorQWidget;
	int **ques;
	int iGenerateNumber;
	int curQuesNumber = 0;
	SudokuUI(QWidget *parent = Q_NULLPTR);
	void readSudokuBox(int(&data)[81]);
	void updateSudokuBox(int value[81], int rowId = -1, int colId = -1);
	
	bool searchTipsPos(int &rowId, int &colId);
	
	bool testOneBoxValid(int rowId, int colId);
	void testValuechange();
	void refreshGetTips();
	bool testAnswer();
	void refreshLCDMinTime();
	void keyPressEvent(QKeyEvent * event);

public slots:
	void receiveQues(int **ques, int iGenerateNumber);
	void refreshAboutSudokuBox();
	void responseGetTips();
	void responseFinish();
	void refreshLCDCurTime();
	void refreshPreAndNextButton();
	void responsePreGame();
	void responseNextGame();
	void refreshJump();
	void responseJump();
	void responsePlayAgain();
};
