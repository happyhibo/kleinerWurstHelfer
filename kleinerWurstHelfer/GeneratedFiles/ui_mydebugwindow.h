/********************************************************************************
** Form generated from reading UI file 'mydebugwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYDEBUGWINDOW_H
#define UI_MYDEBUGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mydebugwindow
{
public:
    QGroupBox *groupBox;
    QLineEdit *lineEdit;
    QLabel *label;

    void setupUi(QWidget *mydebugwindow)
    {
        if (mydebugwindow->objectName().isEmpty())
            mydebugwindow->setObjectName(QString::fromUtf8("mydebugwindow"));
        mydebugwindow->resize(240, 128);
        groupBox = new QGroupBox(mydebugwindow);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 20, 181, 51));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(50, 20, 113, 20));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 51, 21));

        retranslateUi(mydebugwindow);

        QMetaObject::connectSlotsByName(mydebugwindow);
    } // setupUi

    void retranslateUi(QWidget *mydebugwindow)
    {
        mydebugwindow->setWindowTitle(QCoreApplication::translate("mydebugwindow", "mydebugwindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("mydebugwindow", "GroupBox", nullptr));
        label->setText(QCoreApplication::translate("mydebugwindow", "Daten:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mydebugwindow: public Ui_mydebugwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYDEBUGWINDOW_H
