#include "GenetateNumber.h"
#include <assert.h>

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
	bool flag = false;
	flag = QObject::connect(ui.okButton, SIGNAL(clicked()), this, SLOT(responseOK()));
	assert(flag);
	flag = QObject::connect(ui.generationNumber, SIGNAL(textChanged(QString)), this, SLOT(refreshOKStatus()));
	assert(flag);
	flag = QObject::connect(ui.custom, SIGNAL(clicked()), this, SLOT(responseCustomStatusChanged()));
	assert(flag);
	flag = QObject::connect(ui.easy, SIGNAL(clicked()), this, SLOT(responseCustomStatusChanged()));
	assert(flag);
	flag = QObject::connect(ui.medium, SIGNAL(clicked()), this, SLOT(responseCustomStatusChanged()));
	assert(flag);
	flag = QObject::connect(ui.hard, SIGNAL(clicked()), this, SLOT(responseCustomStatusChanged()));
	assert(flag);
	flag = QObject::connect(ui.getHelp, SIGNAL(clicked()), this, SLOT(responseGetHelp()));
	assert(flag);
	setWindowModality(Qt::ApplicationModal);
	refreshHSliderMinSpace();
	refreshHSliderMaxSpace();
	refreshUniqueSign();
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
	else 
	{
		iMode = 0;
		iMinSpace = ui.hSliderMinSpace->value();
		iMaxSpace = ui.hSliderMaxSpace->value();
		bUnique = ui.uniqueSign->isChecked();
		if (iMinSpace > iMaxSpace)
		{
			QMessageBox::information(NULL, "\346\217\220\347\244\272", "\345\223\216\345\221\200\357\274\201\n\346\234\200\345\244\247\347\251\272\346\240\274\346\225\260\345\260\217\344\272\216\346\234\200\345\260\217\347\251\272\346\240\274\346\225\260\345\225\246\357\274\201\n\350\257\267\351\207\215\346\226\260\351\200\211\346\213\251\346\234\200\345\260\217\347\251\272\346\240\274"
				"\346\225\260\345\222\214\346\234\200\345\244\247\347\251\272\346\240\274\346\225\260\357\274\214\350\246\201\350\256\251\346\234\200\345\244\247\347\251\272\346\240\274\346\225\260\344\270\215\345\260\217\344\272\216\346\234\200\345\260\217\347\251\272\346\240\274\346\225\260\345\223\246~", QMessageBox::Yes, QMessageBox::Yes);
			return;
		}
	}
ACCEPT:
	int **result = new int*[iGenerateNumber];
	for (i = 0; i < iGenerateNumber; i++)
		result[i] = new int[81];
	if (iMode == 0){}
		//generate(iGenerateNumber, iMinSpace, iMaxSpace, bUnique, result);
	else{}
		//generate(iGenerateNumber, iMode, result);
	
	int temp[81] = {0, 2, 3, 4, 0, 6, 7, 8, 0,
				 4, 5, 6, 7, 8, 9, 1, 2, 3,
				 7, 8, 9, 0, 2, 3, 4, 5, 6,
				 2, 3, 1, 0, 6, 0, 8, 9, 7,
				 0, 6, 4, 8, 9, 7, 2, 3, 0,
				 8, 9, 7, 0, 3, 0, 5, 6, 4,
				 3, 1, 2, 6, 4, 5, 9, 0, 8,
				 6, 4, 5, 9, 7, 0, 3, 1, 2,
				 0, 7, 8, 3, 0, 2, 6, 4, 0};
	int temp_2[81] = { 1, 2, 3, 4, 5, 6, 7, 8, 9,
		4, 5, 6, 7, 8, 9, 1, 2, 3,
		7, 8, 9, 0, 2, 3, 4, 5, 6,
		2, 3, 1, 0, 6, 0, 8, 9, 7,
		0, 6, 4, 8, 9, 7, 2, 3, 0,
		8, 9, 7, 0, 3, 0, 5, 6, 4,
		3, 1, 2, 6, 4, 5, 9, 0, 8,
		6, 4, 5, 9, 7, 0, 3, 1, 2,
		0, 7, 8, 3, 0, 2, 6, 4, 0 };
	for (i = 0; i < 81; i++) 
	{
		result[0][i] = temp[i];
		if (iGenerateNumber == 2)
			result[1][i] = temp_2[i];
	}
	
	emit generateSuccessfully(result, iGenerateNumber, iMode);
	this->accept();
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

//获取生成参数的页面不允许按‘x’键强行关闭。
void GenetateNumber::closeEvent(QCloseEvent * event)
{
	event->ignore();
	QMessageBox::information(NULL, "\346\217\220\347\244\272", "\344\272\262\357\274\214\350\257\267\346\267\241\345\256\232\357\274\214\345\215\225\345\207\273\342\200\234OK\342\200\235\347\224\237\346\210\220\346\225\260\347\213\254\345\271\266\346\270\270\346\210\217\357\274\214\345\215\225\345\207\273\342\200\234cancel\342\200\235\351\200\200\345\207\272\343\200\202", QMessageBox::Yes, QMessageBox::Yes);
}

void GenetateNumber::refreshHSliderMaxSpace()
{
	ui.hSliderMaxSpace->setEnabled(ui.custom->isChecked());
}

void GenetateNumber::refreshHSliderMinSpace()
{
	ui.hSliderMinSpace->setEnabled(ui.custom->isChecked());
}


void GenetateNumber::refreshUniqueSign()
{
	ui.uniqueSign->setEnabled(ui.custom->isChecked());
}

void GenetateNumber::responseCustomStatusChanged()
{
	refreshHSliderMinSpace();
	refreshHSliderMaxSpace();
	refreshUniqueSign();
}

void GenetateNumber::responseGetHelp()
{
	QMessageBox::information(NULL, "\345\270\256\345\212\251\346\211\213\345\206\214", "\346\254\242\350\277\216\346\235\245\345\210\260\345\270\256\345\212\251\346\211\213\345\206\214\357\274\201\345\270\214\346\234\233\350\203\275\345\244\237\345\270\256\345\212\251\344\275\240~\n\n    1.\350\257\267\345\234\250\347\274\226\350\276\221\346\241\206\345\206\205\350\276\223"
		"\345\205\245\346\202\250\346\203\263\347\216\251\347\232\204\346\225\260\347\213\254\345\261\200\346\225\260\357\274\214\344\271\237\345\260\261\346\230\257\345\205\263\345\215\241\346\225\260\357\274\214\351\273\230\350\256\244\344\270\2721\n    2.\350\257\267\351\200\211\346\213\251\346\270\270\346\210\217\351\232\276\345\272\246\357\274\232\347\256\200\345\215\225/\345\205\245\351\227\250/\345\233\260\351\232\276/\350\207\252\345\256\232\344\271\211\357\274\214\351\273\230\350\256\244\346\250\241\345\274\217\344\270\272\350\207\252\345\256\232\344\271\211\n    3.\345\246\202\346\236\234\346\250\241\345\274\217\344\270\272\350\207\252\345\256\232\344\271\211\357\274\214\345\210\231\345\220\216\344\270\211\350\241\214\347\232\204\345\206\205\345\256\271\346\230"
		"\257\345\217\257\351\200\211\347\232\204\343\200\202\n    4.\346\213\226\345\212\250\344\270\212\351\235\242\347\232\204\346\273\221\345\235\227\357\274\214\351\200\211\346\213\251\346\225\260\347\213\254\351\242\230\347\233\256\346\234\200\345\260\221\346\234\211\345\207\240\344\270\252\347\251\272\343\200\202\346\234\200\345\260\22120\344\270\252\357\274\214\346\234\200\345\244\23255\344\270\252\357\274\214\351\273\230\350\256\244\346\234\200\345\260\221\343\200\202\n    5.\346\213\226\345\212\250\344\270\213\351\235\242\347\232\204\346\273\221\345\235\227\357\274\214\351\200\211\346\213\251\346\225\260\347\213\254\351\242\230\347\233\256\346\234\200\345\244\232\346\234\211\345\207\240\344\270\252\347\251\272\343\200\202\346\234\200\345\260\22120\344\270\252"
		"\357\274\214\346\234\200\345\244\23255\344\270\252\357\274\214\351\273\230\350\256\244\346\234\200\345\260\221\343\200\202\n    6.\350\257\267\346\263\250\346\204\217\357\274\214\346\234\200\345\244\247\347\251\272\346\240\274\346\225\260\344\270\215\350\203\275\345\260\217\344\272\216\346\234\200\345\260\217\347\251\272\346\240\274\346\225\260\345\223\246\343\200\202\n    7.\345\246\202\346\236\234\346\202\250\346\203\263\347\216\251\345\217\252\346\234\211\345\224\257\344\270\200\350\247\243\347\232\204\346\225\260\347\213\254\346\270\270\346\210\217\357\274\214\350\257\267\345\213\276\351\200\211\346\234\200\344\270\213\351\235\242\347\232\204\346\241\206\346\241\206~\n\n\345\217\213\346\203\205\346\217\220\347\244\272\357\274\232\347\224\237\346\210\220\346\225\260\347\213\254\351\242\230\347\233\256\350\200\227\346\227\266\350\276\203\351\225\277\357\274\214\350\257\267\350\200\220\345\277\203\347\255\211\345\276\205~", QMessageBox::Yes, QMessageBox::Yes);
}