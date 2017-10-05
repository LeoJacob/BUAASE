#ifndef UI_SUDOKUUI_H
#define UI_SUDOKUUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#define NUMBER_OF_ROWS 9
#define NUMBER_OF_COLUMNS NUMBER_OF_ROWS
#define TOP_MARGIN 50
#define LEFT_MARGIN 50
#define BOX_SIDE_LENGTH 40
#define LINE_LENGTH NUMBER_OF_ROWS*BOX_SIDE_LENGTH
#define LINE_WIDTH 5

QT_BEGIN_NAMESPACE

class Ui_SudokuUIClass
{
public:
    QWidget *centralWidget;
	QLineEdit *sudokuBox[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS];
    
    QFrame *vline[4];
    QFrame *hline[4];
   
    QPushButton *getTip;
    QPushButton *finish;
    QPushButton *_quit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SudokuUIClass)
    {
        if (SudokuUIClass->objectName().isEmpty())
            SudokuUIClass->setObjectName(QStringLiteral("SudokuUIClass"));
        SudokuUIClass->resize(649, 554);
        centralWidget = new QWidget(SudokuUIClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));

		int i, j;
		for (i = 0; i < NUMBER_OF_ROWS; i++)
		{
			for (j = 0; j < NUMBER_OF_COLUMNS; j++)
			{
				sudokuBox[i][j] = new QLineEdit(centralWidget);
				sudokuBox[i][j]->setGeometry(QRect(LEFT_MARGIN+BOX_SIDE_LENGTH*j, TOP_MARGIN + BOX_SIDE_LENGTH*i, BOX_SIDE_LENGTH, BOX_SIDE_LENGTH));
				QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
				sizePolicy.setHorizontalStretch(0);
				sizePolicy.setVerticalStretch(0);
				sizePolicy.setHeightForWidth(sudokuBox[i][j]->sizePolicy().hasHeightForWidth());
				sudokuBox[i][j]->setSizePolicy(sizePolicy);
				sudokuBox[i][j]->setMinimumSize(QSize(BOX_SIDE_LENGTH, BOX_SIDE_LENGTH));
				sudokuBox[i][j]->setMaximumSize(QSize(BOX_SIDE_LENGTH, BOX_SIDE_LENGTH));
				QFont font;
				font.setFamily(QStringLiteral("Arial"));
				font.setPointSize(18);
				font.setBold(true);
				font.setWeight(75);
				sudokuBox[i][j]->setFont(font);
				sudokuBox[i][j]->setAlignment(Qt::AlignCenter);
			}
		}

		for (i = 0; i < 4; i++) {
			hline[i] = new QFrame(centralWidget);
			hline[i]->setGeometry(QRect(LEFT_MARGIN, TOP_MARGIN+3*BOX_SIDE_LENGTH*i, LINE_LENGTH, LINE_WIDTH));
			hline[i]->setFrameShape(QFrame::HLine);
			hline[i]->setFrameShadow(QFrame::Sunken);
			vline[i] = new QFrame(centralWidget);
			vline[i]->setGeometry(QRect(LEFT_MARGIN+3*BOX_SIDE_LENGTH*i, TOP_MARGIN, LINE_WIDTH, LINE_LENGTH));
			vline[i]->setFrameShape(QFrame::VLine);
			vline[i]->setFrameShadow(QFrame::Sunken);
		}

        getTip = new QPushButton(centralWidget);
		getTip->setGeometry(QRect(
			sudokuBox[0][NUMBER_OF_COLUMNS-1]->geometry().right()+BOX_SIDE_LENGTH,
			TOP_MARGIN,
			75, 
			23));

        finish = new QPushButton(centralWidget);
		finish->setGeometry(QRect(
			sudokuBox[NUMBER_OF_ROWS - 2][NUMBER_OF_COLUMNS - 1]->geometry().right() + BOX_SIDE_LENGTH,
			sudokuBox[NUMBER_OF_ROWS - 2][NUMBER_OF_COLUMNS - 1]->geometry().top() + BOX_SIDE_LENGTH / 2,
			75,
			23));
        _quit = new QPushButton(centralWidget);
        _quit->setGeometry(QRect(
			sudokuBox[NUMBER_OF_COLUMNS - 1][NUMBER_OF_COLUMNS - 1]->geometry().right() + BOX_SIDE_LENGTH,
			sudokuBox[NUMBER_OF_COLUMNS - 1][NUMBER_OF_COLUMNS - 1]->geometry().top() + BOX_SIDE_LENGTH / 2,
			75, 
			23));

        SudokuUIClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SudokuUIClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 649, 23));
        SudokuUIClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SudokuUIClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        SudokuUIClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SudokuUIClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SudokuUIClass->setStatusBar(statusBar);

        retranslateUi(SudokuUIClass);

        QMetaObject::connectSlotsByName(SudokuUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *SudokuUIClass)
    {
		int i, j;
        SudokuUIClass->setWindowTitle(QApplication::translate("SudokuUIClass", "Sudoku Game", Q_NULLPTR));
		for (i = 0; i < NUMBER_OF_ROWS; i++)
		{
			for (j = 0; j < NUMBER_OF_COLUMNS; j++)
				sudokuBox[i][j]->setText(QApplication::translate("SudokuUIClass", "1", Q_NULLPTR));
		}
       
        getTip->setText(QApplication::translate("SudokuUIClass", "\346\217\220\347\244\272", Q_NULLPTR));
        finish->setText(QApplication::translate("SudokuUIClass", "\345\256\214\346\210\220", Q_NULLPTR));
        _quit->setText(QApplication::translate("SudokuUIClass", "\351\200\200\345\207\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SudokuUIClass: public Ui_SudokuUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUDOKUUI_H
