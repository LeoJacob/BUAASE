#ifndef UI_SUDOKUUI_H
#define UI_SUDOKUUI_H

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
#include <assert.h>
#include "myQLineEdit.h"
#define NUMBER_OF_ROWS 9
#define NUMBER_OF_COLUMNS NUMBER_OF_ROWS
#define TOP_MARGIN 50
#define LEFT_MARGIN 50
#define BOX_SIDE_LENGTH 40
#define LINE_LENGTH NUMBER_OF_ROWS*BOX_SIDE_LENGTH
#define LINE_WIDTH 5
#define MAX_GENERATE_NUMBER 10000
#define ZERO 0
#define EASY_CODE "\347\256\200\345\215\225"
#define MEDIUM_CODE "\345\205\245\351\227\250"
#define HARD_CODE "\345\233\260\351\232\276"
#define CUSTOM_CODE "\350\207\252\345\256\232\344\271\211"


QT_BEGIN_NAMESPACE

class Ui_SudokuUIClass:public QWidget
{
public:
    QWidget *centralWidget;
	myQLineEdit *sudokuBox[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS];
    QFrame *vline[4];
    QFrame *hline[4];
	QLCDNumber *LCDCurTimeCost;
	QLineEdit *curTimecost;
	QLineEdit *minTimeCost;
	QLCDNumber *LCDMinTimeCost;
    QPushButton *finish;
    QPushButton *_quit;
	QPushButton *preGame;
	QPushButton *nextGame;
	QPushButton *playAgain;
	QLineEdit *currentGame;
	QLineEdit *curGameNumberContent;
	QLineEdit *totalGameNumber;
	QLineEdit *totalGameNumberContent;
	QLineEdit *chooseGameContent;
	QPushButton *jump;
	QLineEdit *chooseGame;
	QLineEdit *difficulty;
	QLineEdit *difficultyContent;
	QPushButton *pauseButton;
	QPushButton *getHelp;
	QPushButton *continueButton;

    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;


    void setupUi(QMainWindow *SudokuUIClass)
    {
        if (SudokuUIClass->objectName().isEmpty())
            SudokuUIClass->setObjectName(QStringLiteral("SudokuUIClass"));
        SudokuUIClass->resize(649, 502);
        centralWidget = new QWidget(SudokuUIClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));

		int i, j;
		

		for (i = 0; i < NUMBER_OF_ROWS; i++)
		{
			for (j = 0; j < NUMBER_OF_COLUMNS; j++)
			{
				sudokuBox[i][j] = new myQLineEdit(centralWidget);
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
				sudokuBox[i][j]->setMaxLength(1);
				sudokuBox[i][j]->setValidator(new QIntValidator(1, 9, sudokuBox[i][j]));
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

        
        finish = new QPushButton(centralWidget);
		finish->setGeometry(QRect(450, 350, 71, 23));
        _quit = new QPushButton(centralWidget);
		_quit->setGeometry(QRect(450, 390, 71, 23));

		LCDCurTimeCost = new QLCDNumber(centralWidget);
		LCDCurTimeCost->setObjectName(QStringLiteral("LCDCurTimeCost"));
		LCDCurTimeCost->setGeometry(QRect(550, 50, 81, 21));
		QFont font1;
		font1.setFamily(QStringLiteral("Arial"));
		font1.setPointSize(14);
		font1.setBold(true);
		font1.setItalic(false);
		font1.setWeight(75);
		LCDCurTimeCost->setFont(font1);
		LCDCurTimeCost->setDigitCount(8);
		LCDCurTimeCost->setSegmentStyle(QLCDNumber::Flat);
		curTimecost = new QLineEdit(centralWidget);
		curTimecost->setObjectName(QStringLiteral("curTimecost"));
		curTimecost->setGeometry(QRect(450, 50, 71, 20));
		curTimecost->setReadOnly(true);
		curTimecost->setStyleSheet("background:transparent;border-width:0;border-style:outset");
		curTimecost->setDisabled(true);
		minTimeCost = new QLineEdit(centralWidget);
		minTimeCost->setObjectName(QStringLiteral("minTimeCost"));
		minTimeCost->setGeometry(QRect(450, 80, 71, 20));
		minTimeCost->setReadOnly(true);
		minTimeCost->setStyleSheet("background:transparent;border-width:0;border-style:outset");
		minTimeCost->setDisabled(true);
		LCDMinTimeCost = new QLCDNumber(centralWidget);
		LCDMinTimeCost->setObjectName(QStringLiteral("LCDMinTimeCost"));
		LCDMinTimeCost->setGeometry(QRect(550, 80, 81, 21));
		LCDMinTimeCost->setSegmentStyle(QLCDNumber::Flat);
		QFont font2;
		font2.setFamily(QStringLiteral("Arial"));
		font2.setPointSize(14);
		font2.setBold(true);
		font2.setWeight(75);
		LCDMinTimeCost->setFont(font2);
		LCDMinTimeCost->setDigitCount(8);

		preGame = new QPushButton(centralWidget);
		preGame->setObjectName(QStringLiteral("preGame"));
		preGame->setGeometry(QRect(450, 310, 71, 23));
		nextGame = new QPushButton(centralWidget);
		nextGame->setObjectName(QStringLiteral("nextGame"));
		nextGame->setGeometry(QRect(550, 310, 71, 23));
		playAgain = new QPushButton(centralWidget);
		playAgain->setObjectName(QStringLiteral("playAgain"));
		playAgain->setGeometry(QRect(550, 350, 71, 23));
		currentGame = new QLineEdit(centralWidget);
		currentGame->setObjectName(QStringLiteral("currentGame"));
		currentGame->setEnabled(false);
		currentGame->setGeometry(QRect(450, 140, 71, 20));
		currentGame->setReadOnly(true);
		currentGame->setStyleSheet("background:transparent;border-width:0;border-style:outset");
		curGameNumberContent = new QLineEdit(centralWidget);
		curGameNumberContent->setObjectName(QStringLiteral("curGameNumberContent"));
		curGameNumberContent->setGeometry(QRect(550, 140, 41, 20));
		curGameNumberContent->setStyleSheet("background:transparent;border-width:0;border-style:outset");
		curGameNumberContent->setReadOnly(true);
		totalGameNumber = new QLineEdit(centralWidget);
		totalGameNumber->setObjectName(QStringLiteral("totalGameNumber"));
		totalGameNumber->setEnabled(false);
		totalGameNumber->setGeometry(QRect(450, 170, 71, 20));
		totalGameNumber->setStyleSheet("background:transparent;border-width:0;border-style:outset");
		totalGameNumberContent = new QLineEdit(centralWidget);
		totalGameNumberContent->setObjectName(QStringLiteral("totalGameNumberContent"));
		totalGameNumberContent->setGeometry(QRect(550, 170, 41, 20));
		totalGameNumberContent->setStyleSheet("background:transparent;border-width:0;border-style:outset");
		totalGameNumberContent->setReadOnly(true);
		chooseGameContent = new QLineEdit(centralWidget);
		chooseGameContent->setObjectName(QStringLiteral("chooseGameContent"));
		chooseGameContent->setGeometry(QRect(530, 200, 41, 20));
		chooseGameContent->setMaxLength(5);
		chooseGameContent->setAlignment(Qt::AlignRight | Qt::AlignTrailing | Qt::AlignVCenter);
		chooseGameContent->setValidator(new QIntValidator(1, 10000, chooseGameContent));
		jump = new QPushButton(centralWidget);
		jump->setObjectName(QStringLiteral("jump"));
		jump->setGeometry(QRect(590, 200, 41, 23));
		chooseGame = new QLineEdit(centralWidget);
		chooseGame->setObjectName(QStringLiteral("chooseGame"));
		chooseGame->setEnabled(false);
		chooseGame->setGeometry(QRect(450, 200, 71, 20));
		chooseGame->setReadOnly(true);
		chooseGame->setStyleSheet("background:transparent;border-width:0;border-style:outset");

		difficulty = new QLineEdit(centralWidget);
		difficulty->setObjectName(QStringLiteral("difficulty"));
		difficulty->setEnabled(false);
		difficulty->setGeometry(QRect(450, 110, 71, 20));
		difficulty->setFocusPolicy(Qt::StrongFocus);
		difficulty->setReadOnly(true);
		difficulty->setStyleSheet("background:transparent;border-width:0;border-style:outset");
		difficultyContent = new QLineEdit(centralWidget);
		difficultyContent->setObjectName(QStringLiteral("difficultyContent"));
		difficultyContent->setEnabled(false);
		difficultyContent->setGeometry(QRect(550, 110, 71, 20));
		difficultyContent->setFocusPolicy(Qt::StrongFocus);
		difficultyContent->setReadOnly(true);
		difficultyContent->setStyleSheet("background:transparent;border-width:0;border-style:outset");
		pauseButton = new QPushButton(centralWidget);
		pauseButton->setObjectName(QStringLiteral("pauseButton"));
		pauseButton->setGeometry(QRect(450, 270, 71, 23));
		continueButton = new QPushButton(centralWidget);
		continueButton->setObjectName(QStringLiteral("continueButton"));
		continueButton->setGeometry(QRect(550, 270, 71, 23));
		getHelp = new QPushButton(centralWidget);
		getHelp->setObjectName(QStringLiteral("getHelp"));
		getHelp->setGeometry(QRect(450, 235, 171, 21));

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
				sudokuBox[i][j]->setText(QApplication::translate("SudokuUIClass", "", Q_NULLPTR));
		}
        finish->setText(QApplication::translate("SudokuUIClass", "\345\256\214\346\210\220", Q_NULLPTR));
        _quit->setText(QApplication::translate("SudokuUIClass", "\351\200\200\345\207\272", Q_NULLPTR));
		curTimecost->setText(QApplication::translate("SudokuUIClass", "\345\275\223\345\211\215\350\200\227\346\227\266\357\274\232", Q_NULLPTR));
		minTimeCost->setText(QApplication::translate("SudokuUIClass", "\346\234\200\344\275\263\347\272\252\345\275\225\357\274\232", Q_NULLPTR));
		curTimecost->setText(QApplication::translate("SudokuUIClass", "\345\275\223\345\211\215\350\200\227\346\227\266\357\274\232", Q_NULLPTR));
		minTimeCost->setText(QApplication::translate("SudokuUIClass", "\346\234\200\344\275\263\347\272\252\345\275\225\357\274\232", Q_NULLPTR));
		preGame->setText(QApplication::translate("SudokuUIClass", "\344\270\212\344\270\200\345\205\263", Q_NULLPTR));
		nextGame->setText(QApplication::translate("SudokuUIClass", "\344\270\213\344\270\200\345\205\263", Q_NULLPTR));
		playAgain->setText(QApplication::translate("SudokuUIClass", "\345\206\215\347\216\251\344\270\200\347\273\204", Q_NULLPTR));
		chooseGame->setText(QApplication::translate("SudokuUIClass", "\346\211\213\345\212\250\351\200\211\345\205\263", Q_NULLPTR));
		currentGame->setText(QApplication::translate("SudokuUIClass", "\345\275\223\345\211\215\345\205\263\345\215\241\357\274\232", Q_NULLPTR));
		totalGameNumber->setText(QApplication::translate("SudokuUIClass", "\345\205\263\345\215\241\346\200\273\346\225\260\357\274\232", Q_NULLPTR));
		jump->setText(QApplication::translate("SudokuUIClass", "\350\267\263\350\275\254", Q_NULLPTR));
		chooseGame->setText(QApplication::translate("SudokuUIClass", "\351\200\211\346\213\251\345\205\263\345\215\241\357\274\232", Q_NULLPTR));
		difficulty->setText(QApplication::translate("SudokuUIClass", "\346\270\270\346\210\217\351\232\276\345\272\246\357\274\232", Q_NULLPTR));
		pauseButton->setText(QApplication::translate("SudokuUIClass", "\346\232\202\345\201\234\346\270\270\346\210\217", Q_NULLPTR));
		getHelp->setText(QApplication::translate("SudokuUIClass", "\345\277\230\344\272\206\346\200\216\344\271\210\347\216\251\357\274\237\347\202\271\346\210\221\345\205\250\347\237\245\351\201\223\357\274\201", Q_NULLPTR));
		continueButton->setText(QApplication::translate("SudokuUIClass", "\347\273\247\347\273\255\346\270\270\346\210\217", Q_NULLPTR));
    } // retranslateUi

};



namespace Ui {
    class SudokuUIClass: public Ui_SudokuUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUDOKUUI_H
