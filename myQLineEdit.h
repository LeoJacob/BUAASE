#pragma once
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <Qpalette>
#define NUMBER_OF_ROWS 9
#define NUMBER_OF_COLUMNS NUMBER_OF_ROWS
#define TOP_MARGIN 50
#define LEFT_MARGIN 50
#define BOX_SIDE_LENGTH 40
#define LINE_LENGTH NUMBER_OF_ROWS*BOX_SIDE_LENGTH
#define LINE_WIDTH 5
#define MAX_GENERATE_NUMBER 10000
#define ZERO 0


class myQLineEdit : public QLineEdit
{

	Q_OBJECT

public:
	myQLineEdit(QWidget *parent = Q_NULLPTR);
	~myQLineEdit();
	//void mousePressEvent(QMouseEvent *event);
	void contextMenuEvent(QContextMenuEvent *event);
signals:
	void getTips(int rowId, int colId);

};

