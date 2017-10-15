
#include <QDialog>  
#include "ui_getGenerateRequest.h"

class getGenetateNumber : public QDialog
{

	Q_OBJECT

public:
	Ui::Dialog ui;
	//默认生成数目为1， 模式不初始化，最小和最大空均为20。根据模式是否初始化来划分是-n, -m组合还是-n, -r(, -u)组合
	int iGenerateNumber = 1, iMode = 0, iMinSpace = 20, iMaxSpace = 20;
	bool iUnique=false;

	getGenetateNumber(int &iGenerateNumber, int &iMode, int &iMinSpace, int &iMaxSpace, bool &iUnique, QDialog *parent = 0);
	~getGenetateNumber();
	bool testGenerateNumber();	//检查输入的数独数目是否合法

signals:

public slots :
	void responseOK();
	void refreshOKStatus();		//更新ok按钮状态1
};

