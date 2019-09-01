/********************************************************************************
** Form generated from reading UI file 'mynewdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYNEWDIALOG_H
#define UI_MYNEWDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_myNewDialog
{
public:

    void setupUi(QDialog *myNewDialog)
    {
        if (myNewDialog->objectName().isEmpty())
            myNewDialog->setObjectName(QString::fromUtf8("myNewDialog"));
        myNewDialog->resize(400, 300);

        retranslateUi(myNewDialog);

        QMetaObject::connectSlotsByName(myNewDialog);
    } // setupUi

    void retranslateUi(QDialog *myNewDialog)
    {
        myNewDialog->setWindowTitle(QCoreApplication::translate("myNewDialog", "myNewDialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class myNewDialog: public Ui_myNewDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYNEWDIALOG_H
