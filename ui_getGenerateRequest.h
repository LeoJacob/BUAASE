/********************************************************************************
** Form generated from reading UI file 'getGenerateRequest.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GETGENERATEREQUEST_H
#define UI_GETGENERATEREQUEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *okButton;
    QPushButton *cancelButton;
    
    QLineEdit *lineEditGenerationNumber;
    QTextEdit *tips;
    QLineEdit *difficulty;
    QRadioButton *easy;
    QRadioButton *medium;
    QRadioButton *hard;
    QLineEdit *minSpace;
    QLineEdit *maxSpace;
    QLCDNumber *LCDMinSpace;
    QSlider *hSliderMinSpace;
    QLCDNumber *LCDMaxSpace;
    QSlider *hSliderMaxSpace;
    QCheckBox *uniqueSign;
	QLineEdit *generationNumber;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(400, 300);
        layoutWidget = new QWidget(Dialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 250, 351, 33));
        hboxLayout = new QHBoxLayout(layoutWidget);
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        spacerItem = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        okButton = new QPushButton(layoutWidget);
        okButton->setObjectName(QStringLiteral("okButton"));

        hboxLayout->addWidget(okButton);

        cancelButton = new QPushButton(layoutWidget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        hboxLayout->addWidget(cancelButton);

        
        lineEditGenerationNumber = new QLineEdit(Dialog);
        lineEditGenerationNumber->setObjectName(QStringLiteral("lineEditGenerationNumber"));
        //lineEditGenerationNumber->setEnabled(false);
        lineEditGenerationNumber->setGeometry(QRect(10, 20, 251, 20));
		lineEditGenerationNumber->setStyleSheet("background:transparent;border-width:0;border-style:outset");
		lineEditGenerationNumber->setReadOnly(true);
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(10);
        font.setBold(false);
        font.setWeight(50);
        lineEditGenerationNumber->setFont(font);
        lineEditGenerationNumber->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
        lineEditGenerationNumber->setReadOnly(true);
		generationNumber = new QLineEdit(Dialog);
		generationNumber->setObjectName(QStringLiteral("generationNumber"));
		generationNumber->setGeometry(QRect(260, 20, 113, 20));
		generationNumber->setMaxLength(5);
		generationNumber->setAlignment(Qt::AlignRight | Qt::AlignTrailing | Qt::AlignVCenter);
		generationNumber->setValidator(new QIntValidator(1, 10000, generationNumber));
		generationNumber->setText("1");

        tips = new QTextEdit(Dialog);
        tips->setObjectName(QStringLiteral("tips"));
		tips->setReadOnly(true);
        //tips->setEnabled(false);
        tips->setGeometry(QRect(260, 80, 131, 41));
        tips->setReadOnly(true);
		tips->setStyleSheet("background:transparent;border-width:0;border-style:outset");
        difficulty = new QLineEdit(Dialog);
        difficulty->setObjectName(QStringLiteral("difficulty"));
        //difficulty->setEnabled(false);
        difficulty->setGeometry(QRect(10, 80, 31, 20));
		difficulty->setStyleSheet("background:transparent;border-width:0;border-style:outset");
		difficulty->setReadOnly(true);
		
        easy = new QRadioButton(Dialog);
        easy->setObjectName(QStringLiteral("easy"));
        easy->setGeometry(QRect(60, 80, 51, 16));
        medium = new QRadioButton(Dialog);
        medium->setObjectName(QStringLiteral("medium"));
        medium->setGeometry(QRect(120, 80, 61, 16));
        hard = new QRadioButton(Dialog);
        hard->setObjectName(QStringLiteral("hard"));
        hard->setGeometry(QRect(190, 80, 61, 16));
        minSpace = new QLineEdit(Dialog);
        minSpace->setObjectName(QStringLiteral("minSpace"));
        //minSpace->setEnabled(false);
        minSpace->setGeometry(QRect(10, 120, 71, 20));
		minSpace->setStyleSheet("background:transparent;border-width:0;border-style:outset");
		minSpace->setReadOnly(true);
        maxSpace = new QLineEdit(Dialog);
        maxSpace->setObjectName(QStringLiteral("maxSpace"));
        //maxSpace->setEnabled(false);
        maxSpace->setGeometry(QRect(10, 160, 71, 20));
		maxSpace->setStyleSheet("background:transparent;border-width:0;border-style:outset");
		maxSpace->setReadOnly(true);
		QFont font2;
		font2.setFamily(QStringLiteral("Arial"));
		font2.setPointSize(14);
		font2.setBold(true);
		font2.setWeight(75);
        LCDMinSpace = new QLCDNumber(Dialog);
        LCDMinSpace->setObjectName(QStringLiteral("LCDMinSpace"));
        LCDMinSpace->setGeometry(QRect(120, 120, 64, 23));
		LCDMinSpace->setDigitCount(2);
		LCDMinSpace->display(20);
		LCDMinSpace->setFont(font2);
        hSliderMinSpace = new QSlider(Dialog);
        hSliderMinSpace->setObjectName(QStringLiteral("hSliderMinSpace"));
        hSliderMinSpace->setGeometry(QRect(210, 120, 160, 22));
        hSliderMinSpace->setOrientation(Qt::Horizontal);
		hSliderMinSpace->setRange(20, 55);
		hSliderMinSpace->setValue(20);
        LCDMaxSpace = new QLCDNumber(Dialog);
        LCDMaxSpace->setObjectName(QStringLiteral("LCDMaxSpace"));
        LCDMaxSpace->setGeometry(QRect(120, 160, 64, 23));
		LCDMaxSpace->setDigitCount(2);
		LCDMaxSpace->display(20);
		LCDMaxSpace->setFont(font2);
        hSliderMaxSpace = new QSlider(Dialog);
        hSliderMaxSpace->setObjectName(QStringLiteral("hSliderMaxSpace"));
        hSliderMaxSpace->setGeometry(QRect(210, 160, 160, 22));
        hSliderMaxSpace->setOrientation(Qt::Horizontal);
		hSliderMaxSpace->setRange(20, 55);
		hSliderMaxSpace->setValue(20);
        uniqueSign = new QCheckBox(Dialog);
        uniqueSign->setObjectName(QStringLiteral("uniqueSign"));
        uniqueSign->setGeometry(QRect(10, 210, 181, 16));

        retranslateUi(Dialog);
        
        QObject::connect(cancelButton, SIGNAL(clicked()), qApp, SLOT(quit()));
        QObject::connect(hSliderMinSpace, SIGNAL(valueChanged(int)), LCDMinSpace, SLOT(display(int)));
        QObject::connect(hSliderMaxSpace, SIGNAL(valueChanged(int)), LCDMaxSpace, SLOT(display(int)));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Welcome", Q_NULLPTR));
        okButton->setText(QApplication::translate("Dialog", "OK", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("Dialog", "Cancel", Q_NULLPTR));
        lineEditGenerationNumber->setText(QApplication::translate("Dialog", "\350\257\267\350\276\223\345\205\245\346\202\250\351\234\200\350\246\201\347\232\204\346\225\260\347\213\254\346\225\260\347\233\256", Q_NULLPTR));
        tips->setHtml(QApplication::translate("Dialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\344\272\262\357\274\214\351\232\276\345\272\246\344\270\216\344\270\213\351\235\242\347\232\204\351\200\211\351\241\271\344\270\215\350\203\275\345\220\214\346\227\266\351\200\211\346\213\251\345\223\246~</p></body></html>", Q_NULLPTR));
        difficulty->setText(QApplication::translate("Dialog", "\351\232\276\345\272\246", Q_NULLPTR));
        easy->setText(QApplication::translate("Dialog", "\347\256\200\345\215\225", Q_NULLPTR));
        medium->setText(QApplication::translate("Dialog", "\345\205\245\351\227\250", Q_NULLPTR));
        hard->setText(QApplication::translate("Dialog", "\345\233\260\351\232\276", Q_NULLPTR));
        minSpace->setText(QApplication::translate("Dialog", "\346\234\200\345\260\217\347\251\272\346\240\274\346\225\260", Q_NULLPTR));
        maxSpace->setText(QApplication::translate("Dialog", "\346\234\200\345\244\247\347\251\272\346\240\274\346\225\260", Q_NULLPTR));
        uniqueSign->setText(QApplication::translate("Dialog", "\346\210\221\345\217\252\346\203\263\345\201\232\346\234\211\345\224\257\344\270\200\350\247\243\347\232\204\346\225\260\347\213\254\351\242\230\357\274\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GETGENERATEREQUEST_H
