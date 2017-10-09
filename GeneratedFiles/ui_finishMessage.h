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

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(300, 379);
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
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\201\255\345\226\234\346\202\250\347\255\224\345\257\271\344\272\206\357\274\201</p></body></html>", Q_NULLPTR));
        textEdit->setHtml(QApplication::translate("Form", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\201\255\345\226\234\346\202\250\347\255\224\345\257\271\344\272\206\357\274\201</p></body></html>", Q_NULLPTR));
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
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINISHMESSAGE_H
