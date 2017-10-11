#pragma once

#include <QDialog>  
#include "ui_getGenerateRequest.h"
#include <QCloseEvent>
#include <QMessageBox>

class GenetateNumber : public QDialog
{

	Q_OBJECT

public:
	Ui::Dialog ui;
	//Ĭ��������ĿΪ1�� ģʽ����ʼ������С�����վ�Ϊ20������ģʽ�Ƿ��ʼ����������-n, -m��ϻ���-n, -r(, -u)���
	int iGenerateNumber = 1, iMode = 0, iMinSpace = 20, iMaxSpace = 20;
	bool bUnique=false;
	int **result;

	GenetateNumber(QDialog *parent = 0);
	~GenetateNumber();
	bool testGenerateNumber();	//��������������Ŀ�Ƿ�Ϸ�
	void closeEvent(QCloseEvent * event);
	void refreshHSliderMinSpace();
	void refreshHSliderMaxSpace();
	void refreshUniqueSign();
signals:
	void generateSuccessfully(int **result, int iGenerateNumber, int iMode);
public slots :
	void responseOK();
	void refreshOKStatus();		//����ok��ť״̬
	void responseCustomStatusChanged();
	void responseGetHelp();
};

