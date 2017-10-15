#include "getGenetateNumber.h"



getGenetateNumber::getGenetateNumber(int &iGenerateNumber, int &iMode, int &iMinSpace, int &iMaxSpace, bool &iUnique, QDialog *parent)
	:QDialog(parent)
{
	ui.setupUi(this);
	QObject::connect(ui.okButton, SIGNAL(clicked()), this, SLOT(responseOK()));
	QObject::connect(ui.generationNumber, SIGNAL(textChanged(QString)), this, SLOT(refreshOKStatus()));
}


getGenetateNumber::~getGenetateNumber()
{
}

void getGenetateNumber::responseOK()
{
	if (ui.lineEditGenerationNumber->text().length() > 0)
	{
		iGenerateNumber = ui.lineEditGenerationNumber->text().toInt();
		if (iGenerateNumber < 1 || iGenerateNumber > 10000)
		{
			//提示玩家输入正确数字。这个地方最好设成实时监测值，大于10000或小于1时，ok是不可点击的
		}
	}
	else
	{
		//处理未输入生成数独数目便点击ok的异常（可以默认为1？）
	}

	if (ui.easy->isChecked()) 
	{
		iMode = 1;
		goto ACCEPT;
	}
	else if (ui.medium->isChecked())
	{
		iMode = 2;
		goto ACCEPT;
	}
	else if (ui.hard->isChecked())
	{
		iMode = 3;
		goto ACCEPT;
	}
	else  //如果没有勾选难度，就进入-r, -u
	{
		iMinSpace = ui.hSliderMinSpace->value();
		iMaxSpace = ui.hSliderMaxSpace->value();
		iUnique = ui.uniqueSign->isChecked();
	}
ACCEPT:
	this->accept();
}

bool getGenetateNumber::testGenerateNumber()
{
	if (ui.generationNumber->text().length() <= 0)
		return false;
	
	int generateNumber = ui.generationNumber->text().toInt();
	if (generateNumber < 1 || generateNumber > 10000)
		return false;

	return true;
}

void getGenetateNumber::refreshOKStatus()
{
		ui.okButton->setEnabled(testGenerateNumber());
}