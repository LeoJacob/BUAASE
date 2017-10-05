#include "SudokuUI.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SudokuUI w;
	w.show();
	return a.exec();
}
