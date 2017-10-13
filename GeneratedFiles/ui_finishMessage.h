/********************************************************************************
** Form generated from reading UI file 'finishMessage.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINISHMESSAGE_H
#define UI_FINISHMESSAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QPushButton *okButton;
    QTextEdit *message;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QTextEdit *textEdit_3;
    QTextEdit *textEdit_4;
    QTextEdit *textEdit_5;
    QTextEdit *textEdit_6;
    QTextEdit *textEdit_7;
    QTextEdit *textEdit_8;
    QTextEdit *textEdit_9;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(578, 379);
        okButton = new QPushButton(Form);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setGeometry(QRect(100, 340, 75, 23));
        message = new QTextEdit(Form);
        message->setObjectName(QStringLiteral("message"));
        message->setGeometry(QRect(10, 20, 281, 21));
        message->setReadOnly(true);
        textEdit = new QTextEdit(Form);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(10, 50, 104, 71));
        textEdit_2 = new QTextEdit(Form);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(180, 50, 104, 71));
        textEdit_3 = new QTextEdit(Form);
        textEdit_3->setObjectName(QStringLiteral("textEdit_3"));
        textEdit_3->setGeometry(QRect(10, 140, 104, 71));
        textEdit_4 = new QTextEdit(Form);
        textEdit_4->setObjectName(QStringLiteral("textEdit_4"));
        textEdit_4->setGeometry(QRect(180, 140, 104, 71));
        textEdit_5 = new QTextEdit(Form);
        textEdit_5->setObjectName(QStringLiteral("textEdit_5"));
        textEdit_5->setGeometry(QRect(10, 230, 104, 71));
        textEdit_6 = new QTextEdit(Form);
        textEdit_6->setObjectName(QStringLiteral("textEdit_6"));
        textEdit_6->setGeometry(QRect(180, 230, 104, 71));
        textEdit_7 = new QTextEdit(Form);
        textEdit_7->setObjectName(QStringLiteral("textEdit_7"));
        textEdit_7->setGeometry(QRect(350, 50, 104, 71));
        textEdit_8 = new QTextEdit(Form);
        textEdit_8->setObjectName(QStringLiteral("textEdit_8"));
        textEdit_8->setGeometry(QRect(350, 150, 104, 71));
        textEdit_9 = new QTextEdit(Form);
        textEdit_9->setObjectName(QStringLiteral("textEdit_9"));
        textEdit_9->setGeometry(QRect(350, 240, 104, 71));

        retranslateUi(Form);
        QObject::connect(okButton, SIGNAL(clicked()), Form, SLOT(close()));

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "\346\217\220\347\244\272\346\266\210\346\201\257", Q_NULLPTR));
        okButton->setText(QApplication::translate("Form", "\347\241\256\345\256\232", Q_NULLPTR));
        message->setHtml(QApplication::translate("Form", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\202\250\345\267\262\347\273\217\347\264\257\350\256\241\347\216\251\350\277\231\347\233\230\346\225\260\347\213\25424\345\260\217\346\227\266\344\272\206\357\274\214\350\257\267\346\263\250\346\204\217\350\272\253\344\275\223\357\274\214\345\201\245\345\272\267\346\270\270\346\210\217\357\274\214\345\246\202\346\236\234\346\202\250\346\210\220\345\212\237\351\227\257\350\277\207\346\255\244\345\205\263\357\274\214\346\202\250\347\232\204\346\210\220\347\273\251\345\260\206\350\242\253\350\256\260\344\270\27223\357\274\23259\357\274\23259\357\274\214\347\273\247"
                        "\347\273\255\345\212\240\346\262\271\345\223\246~</p></body></html>", Q_NULLPTR));
        textEdit->setHtml(QApplication::translate("Form", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\347\256\200\345\215\225</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\205\245\351\227\250</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\233\260\351\232\276</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\350\207\252\345\256\232\344\271\211</p></body></html>", Q_NULLPTR));
        textEdit_2->setHtml(QApplication::translate("Form", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\347\234\237\351\201\227\346\206\276\357\274\201\347\273\247\347\273\255\345\212\252\345\212\233\357\274\201</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\351\200\201\344\275\240\344\270\244\346\235\241\351\224\246\345\233\212\345\246\231\350\256\241\357\274\232</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">1.\345\241\253\346\273\241\346\211\200\346\234\211\347\251\272\346\240\274</p>\n"
"<p style=\" "
                        "margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">2.\346\266\210\351\231\244\347\272\242\350\211\262\346\225\260\345\255\227</p></body></html>", Q_NULLPTR));
        textEdit_3->setHtml(QApplication::translate("Form", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\344\272\262\357\274\214\350\257\267\346\267\241\345\256\232\357\274\214\345\215\225\345\207\273\342\200\234OK\342\200\235\347\224\237\346\210\220\346\225\260\347\213\254\345\271\266\346\270\270\346\210\217\357\274\214\345\215\225\345\207\273\342\200\234cancel\342\200\235\351\200\200\345\207\272\343\200\202</p></body></html>", Q_NULLPTR));
        textEdit_4->setHtml(QApplication::translate("Form", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\201\255\345\226\234\357\274\201\346\202\250\345\267\262\345\201\232\345\257\271\346\211\200\346\234\211\346\225\260\347\213\254\351\242\230\347\233\256\357\274\201\346\214\211\342\200\234\351\200\200\345\207\272\342\200\235\345\210\231\351\200\200\345\207\272\346\270\270\346\210\217\357\274\214\346\214\211\342\200\234\345\206\215\347\216\251\344\270\200\347\273\204\342\200\235\345\210\231\351\207\215\346\226\260\347\224\237\346\210\220\346\225\260\347\213\254\351\242\230\347\233\256</p></body></html>", Q_NULLPTR));
        textEdit_5->setHtml(QApplication::translate("Form", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\254\242\350\277\216\346\235\245\345\210\260\345\270\256\345\212\251\346\211\213\345\206\214\357\274\201\345\270\214\346\234\233\350\203\275\345\244\237\345\270\256\345\212\251\344\275\240~</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">    1.\345\275\223\346\202\250\346\203\263\347\216\251\344\270\212\344\270\200\345\205\263"
                        "\346\227\266\357\274\214\350\257\267\345\215\225\345\207\273\342\200\234\344\270\212\344\270\200\345\205\263\342\200\235(\345\277\253\346\215\267\351\224\256F1)\357\274\214\346\233\264\346\215\242\350\207\263\344\270\212\344\270\200\351\242\230\343\200\202</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">    2.\345\275\223\346\202\250\346\203\263\347\216\251\344\270\213\344\270\200\345\205\263\346\227\266\357\274\214\350\257\267\345\215\225\345\207\273\342\200\234\344\270\213\344\270\200\345\205\263\342\200\235(\345\277\253\346\215\267\351\224\256F2)\357\274\214\346\233\264\346\215\242\350\207\263\344\270\213\344\270\200\351\242\230\343\200\202</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">    3.\345\275\223\346\202\250\346\203\263\347\216\251\346\237\220\344\270\200\345\205\263\346\227\266\357\274\214\344\271\237\345\217\257\344\273\245\346\211\213\345"
                        "\212\250\351\200\211\345\205\263\357\274\232\345\234\250\345\217\263\344\276\247\350\276\223\345\205\245\346\241\206(\345\277\253\346\215\267\351\224\256F3)\344\270\255\350\276\223\345\205\245\345\205\263\345\215\241\347\274\226\345\217\267\357\274\214\347\204\266\345\220\216\345\215\225\345\207\273\342\200\234\350\267\263\350\275\254\342\200\235(\345\277\253\346\215\267\351\224\256F4)\343\200\202</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">    4.\345\275\223\346\202\250\351\201\207\345\210\260\345\233\260\351\232\276\346\227\266\357\274\214\350\257\267\344\275\277\347\224\250\351\274\240\346\240\207\345\217\263\351\224\256\345\215\225\345\207\273\344\270\272\346\202\250\345\270\246\346\235\245\345\233\260\351\232\276\347\232\204\347\251\272\346\240\274\357\274\214\347\263\273\347\273\237\345\260\206\346\217\220\347\244\272\346\202\250\350\257\245\347\251\272\346\240\274\347\232\204\345\206\205\345\256\271\343\200\202</p>\n"
""
                        "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">    5.\345\275\223\346\202\250\345\256\214\346\210\220\346\270\270\346\210\217\346\227\266\357\274\214\350\257\267\345\215\225\345\207\273\342\200\234\345\256\214\346\210\220\342\200\235(\345\277\253\346\215\267\351\224\256F6)\357\274\214\345\272\224\347\224\250\345\260\206\344\270\272\346\202\250\346\243\200\346\237\245\347\273\223\346\236\234\343\200\202</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">    6.\345\246\202\346\236\234\346\202\250\345\270\214\346\234\233\345\206\215\347\216\251\344\270\200\347\273\204\346\225\260\347\213\254\346\270\270\346\210\217\357\274\214\350\257\267\345\215\225\345\207\273\342\200\234\345\206\215\347\216\251\344\270\200\347\273\204\342\200\235(\345\277\253\346\215\267\351\224\256F7)\357\274\214\346\216\245\344\270\213\346\235\245\346\202\250\345\260\206\345\217\257\344\273\245"
                        "\351\207\215\346\226\260\351\200\211\346\213\251\346\270\270\346\210\217\346\250\241\345\274\217\345\222\214\345\205\263\345\215\241\346\225\260\343\200\202</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">    7.\346\232\202\345\201\234/\347\273\247\347\273\255\346\270\270\346\210\217\350\257\267\345\215\225\345\207\273\342\200\234\346\232\202\345\201\234\346\270\270\346\210\217\342\200\235(\345\277\253\346\215\267\351\224\256F8)/\342\200\234\347\273\247\347\273\255\346\270\270\346\210\217\342\200\235(\345\277\253\346\215\267\351\224\256F9)\346\214\211\351\222\256\343\200\202</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">    8.\346\237\245\347\234\213\346\234\254\345\270\256\345\212\251\346\211\213\345\206\214\345\277\253\346\215\267\351\224\256\344\270\272F10</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left"
                        ":0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\217\213\346\203\205\346\217\220\347\244\272\357\274\232\346\257\217\344\270\200\345\205\263\347\232\204\351\232\276\345\272\246\351\203\275\346\230\257\344\270\200\346\240\267\347\232\204\345\223\246~</p></body></html>", Q_NULLPTR));
        textEdit_6->setHtml(QApplication::translate("Form", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\254\242\350\277\216\346\235\245\345\210\260\345\270\256\345\212\251\346\211\213\345\206\214\357\274\201\345\270\214\346\234\233\350\203\275\345\244\237\345\270\256\345\212\251\344\275\240~</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">    1.\350\257\267\345\234\250\347\274\226\350\276\221\346\241\206\345\206\205\350\276\223"
                        "\345\205\245\346\202\250\346\203\263\347\216\251\347\232\204\346\225\260\347\213\254\345\261\200\346\225\260\357\274\214\344\271\237\345\260\261\346\230\257\345\205\263\345\215\241\346\225\260\357\274\214\351\273\230\350\256\244\344\270\2721</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">    2.\350\257\267\351\200\211\346\213\251\346\270\270\346\210\217\351\232\276\345\272\246\357\274\232\347\256\200\345\215\225/\345\205\245\351\227\250/\345\233\260\351\232\276/\350\207\252\345\256\232\344\271\211\357\274\214\351\273\230\350\256\244\346\250\241\345\274\217\344\270\272\350\207\252\345\256\232\344\271\211</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">    3.\345\246\202\346\236\234\346\250\241\345\274\217\344\270\272\350\207\252\345\256\232\344\271\211\357\274\214\345\210\231\345\220\216\344\270\211\350\241\214\347\232\204\345\206\205\345\256\271\346\230"
                        "\257\345\217\257\351\200\211\347\232\204\343\200\202</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">    4.\346\213\226\345\212\250\344\270\212\351\235\242\347\232\204\346\273\221\345\235\227\357\274\214\351\200\211\346\213\251\346\225\260\347\213\254\351\242\230\347\233\256\346\234\200\345\260\221\346\234\211\345\207\240\344\270\252\347\251\272\343\200\202\346\234\200\345\260\22120\344\270\252\357\274\214\346\234\200\345\244\23255\344\270\252\357\274\214\351\273\230\350\256\244\346\234\200\345\260\221\343\200\202</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">    5.\346\213\226\345\212\250\344\270\213\351\235\242\347\232\204\346\273\221\345\235\227\357\274\214\351\200\211\346\213\251\346\225\260\347\213\254\351\242\230\347\233\256\346\234\200\345\244\232\346\234\211\345\207\240\344\270\252\347\251\272\343\200\202\346\234\200\345\260\22120\344\270\252"
                        "\357\274\214\346\234\200\345\244\23255\344\270\252\357\274\214\351\273\230\350\256\244\346\234\200\345\260\221\343\200\202</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">    6.\350\257\267\346\263\250\346\204\217\357\274\214\346\234\200\345\244\247\347\251\272\346\240\274\346\225\260\344\270\215\350\203\275\345\260\217\344\272\216\346\234\200\345\260\217\347\251\272\346\240\274\346\225\260\345\223\246\343\200\202</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">    7.\345\246\202\346\236\234\346\202\250\346\203\263\347\216\251\345\217\252\346\234\211\345\224\257\344\270\200\350\247\243\347\232\204\346\225\260\347\213\254\346\270\270\346\210\217\357\274\214\350\257\267\345\213\276\351\200\211\346\234\200\344\270\213\351\235\242\347\232\204\346\241\206\346\241\206~</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-le"
                        "ft:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\217\213\346\203\205\346\217\220\347\244\272\357\274\232\347\224\237\346\210\220\346\225\260\347\213\254\351\242\230\347\233\256\350\200\227\346\227\266\350\276\203\351\225\277\357\274\214\350\257\267\350\200\220\345\277\203\347\255\211\345\276\205~</p></body></html>", Q_NULLPTR));
        textEdit_7->setHtml(QApplication::translate("Form", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\223\216\345\221\200\357\274\201</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\234\200\345\244\247\347\251\272\346\240\274\346\225\260\345\260\217\344\272\216\346\234\200\345\260\217\347\251\272\346\240\274\346\225\260\345\225\246\357\274\201</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\350\257\267\351\207\215\346\226\260\351\200\211\346\213\251\346\234\200\345\260\217\347\251\272\346\240\274"
                        "\346\225\260\345\222\214\346\234\200\345\244\247\347\251\272\346\240\274\346\225\260\357\274\214\350\246\201\350\256\251\346\234\200\345\244\247\347\251\272\346\240\274\346\225\260\344\270\215\345\260\217\344\272\216\346\234\200\345\260\217\347\251\272\346\240\274\346\225\260\345\223\246~</p></body></html>", Q_NULLPTR));
        textEdit_8->setHtml(QApplication::translate("Form", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\270\256\345\212\251\346\211\213\345\206\214</p></body></html>", Q_NULLPTR));
        textEdit_9->setHtml(QApplication::translate("Form", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\202\250\344\271\213\345\211\215\346\237\220\344\270\252\347\251\272\345\241\253\351\224\231\345\225\246~\345\275\223\345\211\215\346\225\260\347\213\254\346\227\240\350\247\243</p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINISHMESSAGE_H
