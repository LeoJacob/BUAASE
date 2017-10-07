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
    QLCDNumber *lcdNumber;
    QSlider *horizontalSlider;
    QLineEdit *lineEdit;
    QTextEdit *textEdit;
    QLineEdit *lineEdit_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLCDNumber *lcdNumber_2;
    QSlider *horizontalSlider_2;
    QLCDNumber *lcdNumber_3;
    QSlider *horizontalSlider_3;
    QCheckBox *checkBox;

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

        lcdNumber = new QLCDNumber(Dialog);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(310, 20, 64, 23));
        horizontalSlider = new QSlider(Dialog);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(10, 50, 371, 22));
        horizontalSlider->setOrientation(Qt::Horizontal);
        lineEdit = new QLineEdit(Dialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setEnabled(false);
        lineEdit->setGeometry(QRect(10, 20, 251, 20));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(10);
        font.setBold(false);
        font.setWeight(50);
        lineEdit->setFont(font);
        textEdit = new QTextEdit(Dialog);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setEnabled(false);
        textEdit->setGeometry(QRect(260, 80, 131, 41));
        lineEdit_2 = new QLineEdit(Dialog);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setEnabled(false);
        lineEdit_2->setGeometry(QRect(10, 80, 31, 20));
        radioButton = new QRadioButton(Dialog);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(60, 80, 89, 16));
        radioButton_2 = new QRadioButton(Dialog);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(120, 80, 89, 16));
        radioButton_3 = new QRadioButton(Dialog);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setGeometry(QRect(190, 80, 89, 16));
        lineEdit_3 = new QLineEdit(Dialog);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setEnabled(false);
        lineEdit_3->setGeometry(QRect(10, 120, 71, 20));
        lineEdit_4 = new QLineEdit(Dialog);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setEnabled(false);
        lineEdit_4->setGeometry(QRect(10, 160, 71, 20));
        lcdNumber_2 = new QLCDNumber(Dialog);
        lcdNumber_2->setObjectName(QStringLiteral("lcdNumber_2"));
        lcdNumber_2->setGeometry(QRect(120, 120, 64, 23));
        horizontalSlider_2 = new QSlider(Dialog);
        horizontalSlider_2->setObjectName(QStringLiteral("horizontalSlider_2"));
        horizontalSlider_2->setGeometry(QRect(210, 120, 160, 22));
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        lcdNumber_3 = new QLCDNumber(Dialog);
        lcdNumber_3->setObjectName(QStringLiteral("lcdNumber_3"));
        lcdNumber_3->setGeometry(QRect(120, 160, 64, 23));
        horizontalSlider_3 = new QSlider(Dialog);
        horizontalSlider_3->setObjectName(QStringLiteral("horizontalSlider_3"));
        horizontalSlider_3->setGeometry(QRect(210, 160, 160, 22));
        horizontalSlider_3->setOrientation(Qt::Horizontal);
        checkBox = new QCheckBox(Dialog);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(10, 210, 181, 16));

        retranslateUi(Dialog);
        QObject::connect(okButton, SIGNAL(clicked()), Dialog, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", Q_NULLPTR));
        okButton->setText(QApplication::translate("Dialog", "OK", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("Dialog", "Cancel", Q_NULLPTR));
        lineEdit->setText(QApplication::translate("Dialog", "\350\257\267\345\267\246\345\217\263\347\247\273\345\212\250\346\273\221\345\235\227\351\200\211\346\213\251\346\225\260\347\213\254\346\225\260\347\233\256", Q_NULLPTR));
        textEdit->setHtml(QApplication::translate("Dialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\344\272\262\357\274\214\351\232\276\345\272\246\344\270\216\344\270\213\351\235\242\347\232\204\351\200\211\351\241\271\344\270\215\350\203\275\345\220\214\346\227\266\351\200\211\346\213\251\345\223\246~</p></body></html>", Q_NULLPTR));
        lineEdit_2->setText(QApplication::translate("Dialog", "\351\232\276\345\272\246", Q_NULLPTR));
        radioButton->setText(QApplication::translate("Dialog", "hard", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("Dialog", "medium", Q_NULLPTR));
        radioButton_3->setText(QApplication::translate("Dialog", "easy", Q_NULLPTR));
        lineEdit_3->setText(QApplication::translate("Dialog", "\346\234\200\345\260\217\347\251\272\346\240\274\346\225\260", Q_NULLPTR));
        lineEdit_4->setText(QApplication::translate("Dialog", "\346\234\200\345\244\247\347\251\272\346\240\274\346\225\260", Q_NULLPTR));
        checkBox->setText(QApplication::translate("Dialog", "\346\210\221\345\217\252\346\203\263\345\201\232\346\234\211\345\224\257\344\270\200\350\247\243\347\232\204\346\225\260\347\213\254\351\242\230\357\274\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GETGENERATEREQUEST_H
