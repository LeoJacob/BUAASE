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
			//��ʾ���������ȷ���֡�����ط�������ʵʱ���ֵ������10000��С��1ʱ��ok�ǲ��ɵ����
		}
	}
	else
	{
		//����δ��������������Ŀ����ok���쳣������Ĭ��Ϊ1����
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
	else  //���û�й�ѡ�Ѷȣ��ͽ���-r, -u
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