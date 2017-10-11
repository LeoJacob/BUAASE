#include "SudokuUI.h"
#include "GenetateNumber.h"
#include <QtWidgets/QApplication>
#include <stdio.h>


int main(int argc, char *argv[])
{
	
	QApplication a(argc, argv);
	SudokuUI w;
	w.show();
	a.setActiveWindow(&w);
	return a.exec();
}
