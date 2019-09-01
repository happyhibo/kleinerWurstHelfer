/********************************************************************************
** Form generated from reading UI file 'mydialog.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYDIALOG_H
#define UI_MYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_mydialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_1;
    QSpacerItem *horizontalSpacer;
    QLineEdit *lineEdit_New_Label1;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *lineEdit_New_Label2;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *lineEdit_New_Label3;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_einh_id;
    QComboBox *comboBox_Einh;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_6;
    QLineEdit *lineEdit_New_Label5;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_New_Ok;
    QPushButton *pushButton_New_cnl;

    void setupUi(QDialog *mydialog)
    {
        if (mydialog->objectName().isEmpty())
            mydialog->setObjectName(QString::fromUtf8("mydialog"));
        mydialog->resize(264, 230);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mydialog->sizePolicy().hasHeightForWidth());
        mydialog->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(10);
        mydialog->setFont(font);
        mydialog->setSizeGripEnabled(false);
        verticalLayout = new QVBoxLayout(mydialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_1 = new QLabel(mydialog);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        label_1->setFont(font);

        horizontalLayout->addWidget(label_1);

        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        lineEdit_New_Label1 = new QLineEdit(mydialog);
        lineEdit_New_Label1->setObjectName(QString::fromUtf8("lineEdit_New_Label1"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit_New_Label1->sizePolicy().hasHeightForWidth());
        lineEdit_New_Label1->setSizePolicy(sizePolicy1);
        lineEdit_New_Label1->setMinimumSize(QSize(150, 0));
        lineEdit_New_Label1->setFont(font);

        horizontalLayout->addWidget(lineEdit_New_Label1);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(mydialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        horizontalSpacer_2 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        lineEdit_New_Label2 = new QLineEdit(mydialog);
        lineEdit_New_Label2->setObjectName(QString::fromUtf8("lineEdit_New_Label2"));
        sizePolicy1.setHeightForWidth(lineEdit_New_Label2->sizePolicy().hasHeightForWidth());
        lineEdit_New_Label2->setSizePolicy(sizePolicy1);
        lineEdit_New_Label2->setMinimumSize(QSize(150, 0));
        lineEdit_New_Label2->setFont(font);

        horizontalLayout_2->addWidget(lineEdit_New_Label2);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_3 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_3 = new QLabel(mydialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        horizontalLayout_4->addWidget(label_3);

        horizontalSpacer_4 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        lineEdit_New_Label3 = new QLineEdit(mydialog);
        lineEdit_New_Label3->setObjectName(QString::fromUtf8("lineEdit_New_Label3"));
        sizePolicy1.setHeightForWidth(lineEdit_New_Label3->sizePolicy().hasHeightForWidth());
        lineEdit_New_Label3->setSizePolicy(sizePolicy1);
        lineEdit_New_Label3->setMinimumSize(QSize(150, 0));
        lineEdit_New_Label3->setFont(font);

        horizontalLayout_4->addWidget(lineEdit_New_Label3);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalSpacer_4 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_4 = new QLabel(mydialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        horizontalLayout_5->addWidget(label_4);

        horizontalSpacer_5 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        label_einh_id = new QLabel(mydialog);
        label_einh_id->setObjectName(QString::fromUtf8("label_einh_id"));
        label_einh_id->setEnabled(false);
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_einh_id->sizePolicy().hasHeightForWidth());
        label_einh_id->setSizePolicy(sizePolicy2);
        label_einh_id->setMinimumSize(QSize(1, 22));

        horizontalLayout_5->addWidget(label_einh_id);

        comboBox_Einh = new QComboBox(mydialog);
        comboBox_Einh->setObjectName(QString::fromUtf8("comboBox_Einh"));
        comboBox_Einh->setEnabled(true);
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(comboBox_Einh->sizePolicy().hasHeightForWidth());
        comboBox_Einh->setSizePolicy(sizePolicy3);
        comboBox_Einh->setMinimumSize(QSize(150, 22));
        comboBox_Einh->setFocusPolicy(Qt::ClickFocus);
        comboBox_Einh->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        comboBox_Einh->setEditable(false);
        comboBox_Einh->setFrame(true);

        horizontalLayout_5->addWidget(comboBox_Einh);


        verticalLayout->addLayout(horizontalLayout_5);

        verticalSpacer_5 = new QSpacerItem(20, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_5 = new QLabel(mydialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        horizontalLayout_6->addWidget(label_5);

        horizontalSpacer_6 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);

        lineEdit_New_Label5 = new QLineEdit(mydialog);
        lineEdit_New_Label5->setObjectName(QString::fromUtf8("lineEdit_New_Label5"));
        sizePolicy1.setHeightForWidth(lineEdit_New_Label5->sizePolicy().hasHeightForWidth());
        lineEdit_New_Label5->setSizePolicy(sizePolicy1);
        lineEdit_New_Label5->setMinimumSize(QSize(150, 0));
        lineEdit_New_Label5->setFont(font);
        lineEdit_New_Label5->setInputMethodHints(Qt::ImhPreferNumbers);

        horizontalLayout_6->addWidget(lineEdit_New_Label5);


        verticalLayout->addLayout(horizontalLayout_6);

        verticalSpacer = new QSpacerItem(242, 5, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        pushButton_New_Ok = new QPushButton(mydialog);
        pushButton_New_Ok->setObjectName(QString::fromUtf8("pushButton_New_Ok"));
        pushButton_New_Ok->setEnabled(false);
        pushButton_New_Ok->setFont(font);

        horizontalLayout_3->addWidget(pushButton_New_Ok);

        pushButton_New_cnl = new QPushButton(mydialog);
        pushButton_New_cnl->setObjectName(QString::fromUtf8("pushButton_New_cnl"));
        pushButton_New_cnl->setFont(font);

        horizontalLayout_3->addWidget(pushButton_New_cnl);


        verticalLayout->addLayout(horizontalLayout_3);

#if QT_CONFIG(shortcut)
        label_1->setBuddy(lineEdit_New_Label1);
        label_2->setBuddy(lineEdit_New_Label2);
        label_3->setBuddy(lineEdit_New_Label2);
        label_4->setBuddy(lineEdit_New_Label2);
        label_5->setBuddy(lineEdit_New_Label2);
#endif // QT_CONFIG(shortcut)
        QWidget::setTabOrder(lineEdit_New_Label1, lineEdit_New_Label2);
        QWidget::setTabOrder(lineEdit_New_Label2, pushButton_New_Ok);
        QWidget::setTabOrder(pushButton_New_Ok, pushButton_New_cnl);

        retranslateUi(mydialog);

        pushButton_New_Ok->setDefault(true);


        QMetaObject::connectSlotsByName(mydialog);
    } // setupUi

    void retranslateUi(QDialog *mydialog)
    {
        mydialog->setWindowTitle(QCoreApplication::translate("mydialog", "Neue Einheit", nullptr));
        label_1->setText(QCoreApplication::translate("mydialog", "Name", nullptr));
        label_2->setText(QCoreApplication::translate("mydialog", "Fettanteil", nullptr));
        label_3->setText(QCoreApplication::translate("mydialog", "Verschnitt", nullptr));
        label_4->setText(QCoreApplication::translate("mydialog", "Einheit", nullptr));
        label_einh_id->setText(QCoreApplication::translate("mydialog", "E_ID", nullptr));
        label_5->setText(QCoreApplication::translate("mydialog", "Preis p Einh.", nullptr));
        pushButton_New_Ok->setText(QCoreApplication::translate("mydialog", "OK", nullptr));
        pushButton_New_cnl->setText(QCoreApplication::translate("mydialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mydialog: public Ui_mydialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYDIALOG_H
