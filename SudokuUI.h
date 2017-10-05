#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_SudokuUI.h"

class SudokuUI : public QMainWindow
{
	Q_OBJECT

public:
	SudokuUI(QWidget *parent = Q_NULLPTR);

//private:
	Ui::SudokuUIClass ui;
};
