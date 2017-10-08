#pragma once

#include <QDialog>  
#include "ui_getGenerateRequest.h"

class GenetateNumber : public QDialog
{

	Q_OBJECT

public:
	Ui::Dialog ui;
	//默认生成数目为1， 模式不初始化，最小和最大空均为20。根据模式是否初始化来划分是-n, -m组合还是-n, -r(, -u)组合
	int iGenerateNumber = 1, iMode = 0, iMinSpace = 20, iMaxSpace = 20;
	bool bUnique=false;
	int **result;

	GenetateNumber(QDialog *parent = 0);
	~GenetateNumber();
	bool testGenerateNumber();	//检查输入的数独数目是否合法

signals:
	void generateSuccessfully(int **result, int iGenerateNumber);
public slots :
	void responseOK();
	void refreshOKStatus();		//更新ok按钮状态
};

