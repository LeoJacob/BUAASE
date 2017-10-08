#include "GenetateNumber.h"

GenetateNumber::GenetateNumber(QDialog *parent)
	:QDialog(parent)
{
	ui.setupUi(this);
	this->iGenerateNumber = iGenerateNumber;
	this->iMode = iMode;
	this->iMinSpace = iMinSpace;
	this->iMaxSpace = iMaxSpace;
	this->bUnique = bUnique;
	this->result = result;
	QObject::connect(ui.okButton, SIGNAL(clicked()), this, SLOT(responseOK()));
	QObject::connect(ui.generationNumber, SIGNAL(textChanged(QString)), this, SLOT(refreshOKStatus()));
	setWindowModality(Qt::ApplicationModal);
}

GenetateNumber::~GenetateNumber()
{
	delete(result);
}

void GenetateNumber::responseOK()
{
	int i, j;
	iGenerateNumber = ui.generationNumber->text().toInt();
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
		bUnique = ui.uniqueSign->isChecked();
	}
ACCEPT:
	int **result = new int*[iGenerateNumber];
	for (i = 0; i < iGenerateNumber; i++)
		result[i] = new int[81];
	if (iMode == 0){}
		//generate(iGenerateNumber, iMinSpace, iMaxSpace, bUnique, result);
	else{}
		//generate(iGenerateNumber, iMode, result);
	
	int temp[81] = {1, 2, 3, 4, 5, 6, 7, 8, 9,
				 4, 5, 6, 7, 8, 9, 1, 2, 3,
				 7, 8, 9, 0, 2, 3, 4, 5, 6,
				 2, 3, 1, 5, 6, 4, 8, 9, 7,
				 5, 6, 4, 8, 9, 0, 2, 3, 1,
				 8, 9, 7, 2, 3, 1, 5, 6, 4,
				 3, 1, 2, 6, 4, 5, 9, 0, 8,
				 6, 4, 5, 9, 7, 0, 3, 1, 2,
				 0, 7, 8, 0, 1, 2, 6, 4, 5};
	for (i = 0; i < 81; i++)
		result[0][i] = temp[i];
	emit generateSuccessfully(result, iGenerateNumber);
	setWindowModality(Qt::NonModal);
	this->accept();
	this->destroy();
}

bool GenetateNumber::testGenerateNumber()
{
	if (ui.generationNumber->text().length() <= 0)
		return false;
	
	int generateNumber = ui.generationNumber->text().toInt();
	if (generateNumber < 1 || generateNumber > 10000)
		return false;

	return true;
}

void GenetateNumber::refreshOKStatus()
{
		ui.okButton->setEnabled(testGenerateNumber());
}