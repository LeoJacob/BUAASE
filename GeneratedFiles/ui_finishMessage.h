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

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(300, 162);
        okButton = new QPushButton(Form);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setGeometry(QRect(100, 120, 75, 23));
        message = new QTextEdit(Form);
        message->setObjectName(QStringLiteral("message"));
        message->setGeometry(QRect(10, 20, 281, 71));
        message->setReadOnly(true);

        retranslateUi(Form);
        QObject::connect(okButton, SIGNAL(clicked()), Form, SLOT(close()));

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "\346\217\220\347\244\272\346\266\210\346\201\257", Q_NULLPTR));
        okButton->setText(QApplication::translate("Form", "\347\241\256\345\256\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINISHMESSAGE_H
