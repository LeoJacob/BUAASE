#include "SudokuUI.h"

SudokuUI::SudokuUI(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	
	QObject::connect(ui._quit, SIGNAL(clicked()), qApp, SLOT(quit()));
}
