#include "SudokuUI.h"
#include "getGenetateNumber.h"
#include <QtWidgets/QApplication>

int iGenerateNumber = 0;
int iMode = 1;
int iMinSpace = 20;
int iMaxSpace = 20;
bool bUnique = false;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	getGenetateNumber getNumber(iGenerateNumber, iMode, iMinSpace, iMaxSpace, bUnique);
	a.setActiveWindow(&getNumber);
	getNumber.show();
	SudokuUI w;
	//w.show();
	return a.exec();
}
