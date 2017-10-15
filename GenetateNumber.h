#pragma once
//#pragma comment(lib, "sudoku.lib")

#include <QDialog>  
#include "ui_getGenerateRequest.h"
#include <QCloseEvent>
#include <QMessageBox>

#include "Core.h"

class GenetateNumber : public QDialog
{

	Q_OBJECT

public:
	Core c;
	Ui::Dialog ui;
	int iGenerateNumber = 1, iMode = 0, iMinSpace = 20, iMaxSpace = 20;
	bool bUnique=false;
	int **result;

	GenetateNumber(QDialog *parent = 0);
	~GenetateNumber();
	bool testGenerateNumber();	//检查输入的数独数目是否合法
	void closeEvent(QCloseEvent * event);
	void refreshHSliderMinSpace();
	void refreshHSliderMaxSpace();
	void refreshUniqueSign();

signals:
	void generateSuccessfully();

public slots :
	void responseOK();
	void refreshOKStatus();		//更新ok按钮状态
	void responseCustomStatusChanged();
	void responseGetHelp();
};

