
#include <QDialog>  
#include "ui_getGenerateRequest.h"

class getGenetateNumber : public QDialog
{

	Q_OBJECT

public:
	Ui::Dialog ui;
	//Ĭ��������ĿΪ1�� ģʽ����ʼ������С�����վ�Ϊ20������ģʽ�Ƿ��ʼ����������-n, -m��ϻ���-n, -r(, -u)���
	int iGenerateNumber = 1, iMode = 0, iMinSpace = 20, iMaxSpace = 20;
	bool iUnique=false;

	getGenetateNumber(int &iGenerateNumber, int &iMode, int &iMinSpace, int &iMaxSpace, bool &iUnique, QDialog *parent = 0);
	~getGenetateNumber();
	bool testGenerateNumber();	//��������������Ŀ�Ƿ�Ϸ�

signals:

public slots :
	void responseOK();
	void refreshOKStatus();		//����ok��ť״̬1
};

