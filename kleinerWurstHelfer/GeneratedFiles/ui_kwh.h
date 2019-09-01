/********************************************************************************
** Form generated from reading UI file 'kwh.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KWH_H
#define UI_KWH_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "myqspinbox.h"

QT_BEGIN_NAMESPACE

class Ui_KWHClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QTabWidget *tabWidget_oben;
    QWidget *tab_rezepte;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget_Rezeptauswahl;
    QGridLayout *gridLayout;
    QPushButton *pushButton_Rezept_kopieren;
    QPushButton *pushButton_Rezept_anlegen;
    QPushButton *pushButton_Rezept_loeschen;
    QWidget *tab_Rezeptdetails;
    QGridLayout *gridLayout_10;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_Fleisch;
    QTableWidget *tableWidget_Fleisch;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_Gewuerze;
    QTableWidget *tableWidget_Gewuerze;
    QPushButton *pushButton_Clear;
    QPushButton *pushButton_Rezept_speichern;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_Name;
    QLabel *label_ID_Name;
    QLineEdit *lineEdit_Name;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_Art;
    QLabel *label_ID_Art;
    QComboBox *comboBox_Art;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_Darm;
    QLabel *label_ID_Darm;
    QComboBox *comboBox_Darm;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_Name_2;
    QSpacerItem *horizontalSpacer;
    MyQSpinbox *spinBox_Verwurstung;
    QLabel *label_Verw_gewicht;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QTextEdit *textEdit_Zubereitung;
    QWidget *tab_RezeptAusdruck;
    QGridLayout *gridLayout_2;
    QWebEngineView *webEngineView;
    QPushButton *pushButton_Rezept_PDF;
    QWidget *tab_Zutaten;
    QGridLayout *gridLayout_4;
    QToolBox *toolBox_Zutaten;
    QWidget *page_Fleisch;
    QVBoxLayout *verticalLayout_9;
    QVBoxLayout *verticalLayout_8;
    QTableWidget *tableWidget_Zutaten_Fleisch;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *pushButton_EintragNeu_Fleisch;
    QPushButton *pushButton_EintragKopie_Fleisch;
    QPushButton *pushButton_EintragDel_Fleisch;
    QWidget *page_Gewuerze;
    QVBoxLayout *verticalLayout_11;
    QVBoxLayout *verticalLayout_10;
    QTableWidget *tableWidget_Zutaten_Gewuerze;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *pushButton_EintragNeu_Gewuerze;
    QPushButton *pushButton_EintragKopie_Gewuerze;
    QPushButton *pushButton_EintragDel_Gewuerze;
    QWidget *page_Darm;
    QGridLayout *gridLayout_5;
    QVBoxLayout *verticalLayout_12;
    QTableWidget *tableWidget_Zutaten_Darm;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *pushButton_EintragNeu_Darm;
    QPushButton *pushButton_EintragKopie_Darm;
    QPushButton *pushButton_EintragDel_Darm;
    QWidget *page_Wurstarten;
    QGridLayout *gridLayout_9;
    QHBoxLayout *horizontalLayout_15;
    QGridLayout *gridLayout_6;
    QLabel *label_Wurstarten;
    QVBoxLayout *verticalLayout_13;
    QTableWidget *tableWidget_Zutaten_Wurstart;
    QHBoxLayout *horizontalLayout_12;
    QPushButton *pushButton_EintragNeu_Wurstart;
    QPushButton *pushButton_EintragKopie_Wurstart;
    QPushButton *pushButton_EintragDel_Wurstart;
    QGridLayout *gridLayout_7;
    QLabel *label_Verarbeitung;
    QVBoxLayout *verticalLayout_14;
    QTableWidget *tableWidget_Zutaten_Verarbeitung;
    QHBoxLayout *horizontalLayout_13;
    QPushButton *pushButton_EintragNeu_Verarbeitung;
    QPushButton *pushButton_EintragKopie_Verarbeitung;
    QPushButton *pushButton_EintragDel_Verarbeitung;
    QGridLayout *gridLayout_8;
    QLabel *label_Einheiten;
    QVBoxLayout *verticalLayout_15;
    QTableWidget *tableWidget_Zutaten_Einheiten;
    QHBoxLayout *horizontalLayout_14;
    QPushButton *pushButton_EintragNeu_Einheiten;
    QPushButton *pushButton_EintragKopie_Einheiten;
    QPushButton *pushButton_EintragDel_Einheiten;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *KWHClass)
    {
        if (KWHClass->objectName().isEmpty())
            KWHClass->setObjectName(QString::fromUtf8("KWHClass"));
        KWHClass->resize(1263, 768);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/KWH/kwh_icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        KWHClass->setWindowIcon(icon);
        centralWidget = new QWidget(KWHClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        tabWidget_oben = new QTabWidget(centralWidget);
        tabWidget_oben->setObjectName(QString::fromUtf8("tabWidget_oben"));
        tabWidget_oben->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget_oben->sizePolicy().hasHeightForWidth());
        tabWidget_oben->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(10);
        tabWidget_oben->setFont(font);
        tabWidget_oben->setStyleSheet(QString::fromUtf8("background-color: rgb(232, 232, 232);"));
        tabWidget_oben->setDocumentMode(false);
        tab_rezepte = new QWidget();
        tab_rezepte->setObjectName(QString::fromUtf8("tab_rezepte"));
        horizontalLayout = new QHBoxLayout(tab_rezepte);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableWidget_Rezeptauswahl = new QTableWidget(tab_rezepte);
        if (tableWidget_Rezeptauswahl->columnCount() < 6)
            tableWidget_Rezeptauswahl->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_Rezeptauswahl->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_Rezeptauswahl->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_Rezeptauswahl->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_Rezeptauswahl->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_Rezeptauswahl->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_Rezeptauswahl->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableWidget_Rezeptauswahl->setObjectName(QString::fromUtf8("tableWidget_Rezeptauswahl"));
        sizePolicy.setHeightForWidth(tableWidget_Rezeptauswahl->sizePolicy().hasHeightForWidth());
        tableWidget_Rezeptauswahl->setSizePolicy(sizePolicy);
        tableWidget_Rezeptauswahl->setStyleSheet(QString::fromUtf8("background-color: rgb(250, 250, 250);"));
        tableWidget_Rezeptauswahl->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_Rezeptauswahl->setSortingEnabled(true);
        tableWidget_Rezeptauswahl->setRowCount(0);
        tableWidget_Rezeptauswahl->setColumnCount(6);

        verticalLayout->addWidget(tableWidget_Rezeptauswahl);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_Rezept_kopieren = new QPushButton(tab_rezepte);
        pushButton_Rezept_kopieren->setObjectName(QString::fromUtf8("pushButton_Rezept_kopieren"));

        gridLayout->addWidget(pushButton_Rezept_kopieren, 0, 2, 1, 1);

        pushButton_Rezept_anlegen = new QPushButton(tab_rezepte);
        pushButton_Rezept_anlegen->setObjectName(QString::fromUtf8("pushButton_Rezept_anlegen"));

        gridLayout->addWidget(pushButton_Rezept_anlegen, 0, 0, 1, 1);

        pushButton_Rezept_loeschen = new QPushButton(tab_rezepte);
        pushButton_Rezept_loeschen->setObjectName(QString::fromUtf8("pushButton_Rezept_loeschen"));

        gridLayout->addWidget(pushButton_Rezept_loeschen, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);


        horizontalLayout->addLayout(verticalLayout);

        tabWidget_oben->addTab(tab_rezepte, QString());
        tab_Rezeptdetails = new QWidget();
        tab_Rezeptdetails->setObjectName(QString::fromUtf8("tab_Rezeptdetails"));
        gridLayout_10 = new QGridLayout(tab_Rezeptdetails);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_Fleisch = new QLabel(tab_Rezeptdetails);
        label_Fleisch->setObjectName(QString::fromUtf8("label_Fleisch"));
        label_Fleisch->setFont(font);

        verticalLayout_6->addWidget(label_Fleisch);

        tableWidget_Fleisch = new QTableWidget(tab_Rezeptdetails);
        if (tableWidget_Fleisch->columnCount() < 8)
            tableWidget_Fleisch->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font);
        tableWidget_Fleisch->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setFont(font);
        tableWidget_Fleisch->setHorizontalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem8->setFont(font);
        tableWidget_Fleisch->setHorizontalHeaderItem(2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setFont(font);
        tableWidget_Fleisch->setHorizontalHeaderItem(3, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setTextAlignment(Qt::AlignCenter);
        tableWidget_Fleisch->setHorizontalHeaderItem(4, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setTextAlignment(Qt::AlignCenter);
        tableWidget_Fleisch->setHorizontalHeaderItem(5, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        __qtablewidgetitem12->setTextAlignment(Qt::AlignCenter);
        tableWidget_Fleisch->setHorizontalHeaderItem(6, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget_Fleisch->setHorizontalHeaderItem(7, __qtablewidgetitem13);
        tableWidget_Fleisch->setObjectName(QString::fromUtf8("tableWidget_Fleisch"));
        tableWidget_Fleisch->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        tableWidget_Fleisch->setEditTriggers(QAbstractItemView::AnyKeyPressed);
        tableWidget_Fleisch->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget_Fleisch->setColumnCount(8);

        verticalLayout_6->addWidget(tableWidget_Fleisch);


        verticalLayout_3->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label_Gewuerze = new QLabel(tab_Rezeptdetails);
        label_Gewuerze->setObjectName(QString::fromUtf8("label_Gewuerze"));
        label_Gewuerze->setFont(font);

        verticalLayout_7->addWidget(label_Gewuerze);

        tableWidget_Gewuerze = new QTableWidget(tab_Rezeptdetails);
        if (tableWidget_Gewuerze->columnCount() < 9)
            tableWidget_Gewuerze->setColumnCount(9);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        __qtablewidgetitem14->setFont(font);
        tableWidget_Gewuerze->setHorizontalHeaderItem(0, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        __qtablewidgetitem15->setFont(font);
        tableWidget_Gewuerze->setHorizontalHeaderItem(1, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        __qtablewidgetitem16->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem16->setFont(font);
        tableWidget_Gewuerze->setHorizontalHeaderItem(2, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        __qtablewidgetitem17->setFont(font);
        tableWidget_Gewuerze->setHorizontalHeaderItem(3, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        __qtablewidgetitem18->setFont(font);
        tableWidget_Gewuerze->setHorizontalHeaderItem(4, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        __qtablewidgetitem19->setTextAlignment(Qt::AlignCenter);
        tableWidget_Gewuerze->setHorizontalHeaderItem(5, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        __qtablewidgetitem20->setTextAlignment(Qt::AlignCenter);
        tableWidget_Gewuerze->setHorizontalHeaderItem(6, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        __qtablewidgetitem21->setTextAlignment(Qt::AlignCenter);
        tableWidget_Gewuerze->setHorizontalHeaderItem(7, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget_Gewuerze->setHorizontalHeaderItem(8, __qtablewidgetitem22);
        tableWidget_Gewuerze->setObjectName(QString::fromUtf8("tableWidget_Gewuerze"));
        tableWidget_Gewuerze->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        tableWidget_Gewuerze->setEditTriggers(QAbstractItemView::AnyKeyPressed);
        tableWidget_Gewuerze->setColumnCount(9);

        verticalLayout_7->addWidget(tableWidget_Gewuerze);


        verticalLayout_3->addLayout(verticalLayout_7);


        gridLayout_10->addLayout(verticalLayout_3, 0, 2, 2, 1);

        pushButton_Clear = new QPushButton(tab_Rezeptdetails);
        pushButton_Clear->setObjectName(QString::fromUtf8("pushButton_Clear"));

        gridLayout_10->addWidget(pushButton_Clear, 1, 1, 1, 1);

        pushButton_Rezept_speichern = new QPushButton(tab_Rezeptdetails);
        pushButton_Rezept_speichern->setObjectName(QString::fromUtf8("pushButton_Rezept_speichern"));

        gridLayout_10->addWidget(pushButton_Rezept_speichern, 1, 0, 1, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_Name = new QLabel(tab_Rezeptdetails);
        label_Name->setObjectName(QString::fromUtf8("label_Name"));
        label_Name->setMaximumSize(QSize(100, 16777215));
        label_Name->setFont(font);

        horizontalLayout_2->addWidget(label_Name);

        label_ID_Name = new QLabel(tab_Rezeptdetails);
        label_ID_Name->setObjectName(QString::fromUtf8("label_ID_Name"));
        label_ID_Name->setEnabled(false);
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_ID_Name->sizePolicy().hasHeightForWidth());
        label_ID_Name->setSizePolicy(sizePolicy1);
        label_ID_Name->setMaximumSize(QSize(50, 50));

        horizontalLayout_2->addWidget(label_ID_Name);

        lineEdit_Name = new QLineEdit(tab_Rezeptdetails);
        lineEdit_Name->setObjectName(QString::fromUtf8("lineEdit_Name"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEdit_Name->sizePolicy().hasHeightForWidth());
        lineEdit_Name->setSizePolicy(sizePolicy2);
        lineEdit_Name->setMinimumSize(QSize(150, 22));
        lineEdit_Name->setBaseSize(QSize(133, 23));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        lineEdit_Name->setFont(font1);
        lineEdit_Name->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(lineEdit_Name);


        verticalLayout_5->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_Art = new QLabel(tab_Rezeptdetails);
        label_Art->setObjectName(QString::fromUtf8("label_Art"));
        label_Art->setMaximumSize(QSize(100, 16777215));
        label_Art->setFont(font);

        horizontalLayout_3->addWidget(label_Art);

        label_ID_Art = new QLabel(tab_Rezeptdetails);
        label_ID_Art->setObjectName(QString::fromUtf8("label_ID_Art"));
        label_ID_Art->setEnabled(false);
        sizePolicy1.setHeightForWidth(label_ID_Art->sizePolicy().hasHeightForWidth());
        label_ID_Art->setSizePolicy(sizePolicy1);
        label_ID_Art->setMinimumSize(QSize(0, 0));
        label_ID_Art->setMaximumSize(QSize(50, 50));

        horizontalLayout_3->addWidget(label_ID_Art);

        comboBox_Art = new QComboBox(tab_Rezeptdetails);
        comboBox_Art->setObjectName(QString::fromUtf8("comboBox_Art"));
        comboBox_Art->setMinimumSize(QSize(150, 22));
        comboBox_Art->setBaseSize(QSize(133, 23));
        comboBox_Art->setFont(font);
        comboBox_Art->setFocusPolicy(Qt::ClickFocus);
        comboBox_Art->setContextMenuPolicy(Qt::DefaultContextMenu);
        comboBox_Art->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        comboBox_Art->setEditable(false);

        horizontalLayout_3->addWidget(comboBox_Art);


        verticalLayout_5->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_Darm = new QLabel(tab_Rezeptdetails);
        label_Darm->setObjectName(QString::fromUtf8("label_Darm"));
        label_Darm->setMaximumSize(QSize(100, 16777215));
        label_Darm->setFont(font);

        horizontalLayout_4->addWidget(label_Darm);

        label_ID_Darm = new QLabel(tab_Rezeptdetails);
        label_ID_Darm->setObjectName(QString::fromUtf8("label_ID_Darm"));
        label_ID_Darm->setEnabled(false);
        sizePolicy1.setHeightForWidth(label_ID_Darm->sizePolicy().hasHeightForWidth());
        label_ID_Darm->setSizePolicy(sizePolicy1);
        label_ID_Darm->setMaximumSize(QSize(50, 50));

        horizontalLayout_4->addWidget(label_ID_Darm);

        comboBox_Darm = new QComboBox(tab_Rezeptdetails);
        comboBox_Darm->setObjectName(QString::fromUtf8("comboBox_Darm"));
        comboBox_Darm->setMinimumSize(QSize(150, 22));
        comboBox_Darm->setBaseSize(QSize(133, 23));
        comboBox_Darm->setFont(font);
        comboBox_Darm->setFocusPolicy(Qt::ClickFocus);
        comboBox_Darm->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        comboBox_Darm->setEditable(false);

        horizontalLayout_4->addWidget(comboBox_Darm);


        verticalLayout_5->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_Name_2 = new QLabel(tab_Rezeptdetails);
        label_Name_2->setObjectName(QString::fromUtf8("label_Name_2"));
        label_Name_2->setMaximumSize(QSize(100, 16777215));
        label_Name_2->setFont(font);

        horizontalLayout_5->addWidget(label_Name_2);

        horizontalSpacer = new QSpacerItem(30, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        spinBox_Verwurstung = new MyQSpinbox(tab_Rezeptdetails);
        spinBox_Verwurstung->setObjectName(QString::fromUtf8("spinBox_Verwurstung"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(spinBox_Verwurstung->sizePolicy().hasHeightForWidth());
        spinBox_Verwurstung->setSizePolicy(sizePolicy3);
        spinBox_Verwurstung->setMinimumSize(QSize(100, 0));
        spinBox_Verwurstung->setFont(font);
        spinBox_Verwurstung->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        spinBox_Verwurstung->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_Verwurstung->setReadOnly(false);
        spinBox_Verwurstung->setMaximum(9999999);

        horizontalLayout_5->addWidget(spinBox_Verwurstung);

        label_Verw_gewicht = new QLabel(tab_Rezeptdetails);
        label_Verw_gewicht->setObjectName(QString::fromUtf8("label_Verw_gewicht"));
        label_Verw_gewicht->setEnabled(true);
        sizePolicy1.setHeightForWidth(label_Verw_gewicht->sizePolicy().hasHeightForWidth());
        label_Verw_gewicht->setSizePolicy(sizePolicy1);
        label_Verw_gewicht->setMinimumSize(QSize(15, 0));
        label_Verw_gewicht->setMaximumSize(QSize(50, 50));
        label_Verw_gewicht->setFont(font);

        horizontalLayout_5->addWidget(label_Verw_gewicht);


        verticalLayout_5->addLayout(horizontalLayout_5);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(tab_Rezeptdetails);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        verticalLayout_2->addWidget(label);

        textEdit_Zubereitung = new QTextEdit(tab_Rezeptdetails);
        textEdit_Zubereitung->setObjectName(QString::fromUtf8("textEdit_Zubereitung"));
        textEdit_Zubereitung->setMinimumSize(QSize(200, 0));
        textEdit_Zubereitung->setFont(font);
        textEdit_Zubereitung->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(textEdit_Zubereitung);


        verticalLayout_5->addLayout(verticalLayout_2);


        gridLayout_10->addLayout(verticalLayout_5, 0, 0, 1, 2);

        tabWidget_oben->addTab(tab_Rezeptdetails, QString());
        tab_RezeptAusdruck = new QWidget();
        tab_RezeptAusdruck->setObjectName(QString::fromUtf8("tab_RezeptAusdruck"));
        gridLayout_2 = new QGridLayout(tab_RezeptAusdruck);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        webEngineView = new QWebEngineView(tab_RezeptAusdruck);
        webEngineView->setObjectName(QString::fromUtf8("webEngineView"));
        webEngineView->setUrl(QUrl(QString::fromUtf8("about:blank")));

        gridLayout_2->addWidget(webEngineView, 0, 0, 1, 1);

        pushButton_Rezept_PDF = new QPushButton(tab_RezeptAusdruck);
        pushButton_Rezept_PDF->setObjectName(QString::fromUtf8("pushButton_Rezept_PDF"));

        gridLayout_2->addWidget(pushButton_Rezept_PDF, 1, 0, 1, 1);

        tabWidget_oben->addTab(tab_RezeptAusdruck, QString());
        tab_Zutaten = new QWidget();
        tab_Zutaten->setObjectName(QString::fromUtf8("tab_Zutaten"));
        gridLayout_4 = new QGridLayout(tab_Zutaten);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        toolBox_Zutaten = new QToolBox(tab_Zutaten);
        toolBox_Zutaten->setObjectName(QString::fromUtf8("toolBox_Zutaten"));
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        toolBox_Zutaten->setFont(font2);
        page_Fleisch = new QWidget();
        page_Fleisch->setObjectName(QString::fromUtf8("page_Fleisch"));
        page_Fleisch->setGeometry(QRect(0, 0, 1221, 542));
        verticalLayout_9 = new QVBoxLayout(page_Fleisch);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        tableWidget_Zutaten_Fleisch = new QTableWidget(page_Fleisch);
        if (tableWidget_Zutaten_Fleisch->columnCount() < 6)
            tableWidget_Zutaten_Fleisch->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        __qtablewidgetitem23->setFont(font);
        tableWidget_Zutaten_Fleisch->setHorizontalHeaderItem(0, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        __qtablewidgetitem24->setFont(font);
        tableWidget_Zutaten_Fleisch->setHorizontalHeaderItem(1, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        __qtablewidgetitem25->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem25->setFont(font);
        tableWidget_Zutaten_Fleisch->setHorizontalHeaderItem(2, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        __qtablewidgetitem26->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem26->setFont(font);
        tableWidget_Zutaten_Fleisch->setHorizontalHeaderItem(3, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        __qtablewidgetitem27->setFont(font);
        tableWidget_Zutaten_Fleisch->setHorizontalHeaderItem(4, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        __qtablewidgetitem28->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem28->setFont(font);
        tableWidget_Zutaten_Fleisch->setHorizontalHeaderItem(5, __qtablewidgetitem28);
        tableWidget_Zutaten_Fleisch->setObjectName(QString::fromUtf8("tableWidget_Zutaten_Fleisch"));

        verticalLayout_8->addWidget(tableWidget_Zutaten_Fleisch);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        pushButton_EintragNeu_Fleisch = new QPushButton(page_Fleisch);
        pushButton_EintragNeu_Fleisch->setObjectName(QString::fromUtf8("pushButton_EintragNeu_Fleisch"));

        horizontalLayout_9->addWidget(pushButton_EintragNeu_Fleisch);

        pushButton_EintragKopie_Fleisch = new QPushButton(page_Fleisch);
        pushButton_EintragKopie_Fleisch->setObjectName(QString::fromUtf8("pushButton_EintragKopie_Fleisch"));

        horizontalLayout_9->addWidget(pushButton_EintragKopie_Fleisch);

        pushButton_EintragDel_Fleisch = new QPushButton(page_Fleisch);
        pushButton_EintragDel_Fleisch->setObjectName(QString::fromUtf8("pushButton_EintragDel_Fleisch"));

        horizontalLayout_9->addWidget(pushButton_EintragDel_Fleisch);


        verticalLayout_8->addLayout(horizontalLayout_9);


        verticalLayout_9->addLayout(verticalLayout_8);

        toolBox_Zutaten->addItem(page_Fleisch, QString::fromUtf8("Fleisch"));
        page_Gewuerze = new QWidget();
        page_Gewuerze->setObjectName(QString::fromUtf8("page_Gewuerze"));
        page_Gewuerze->setGeometry(QRect(0, 0, 1221, 542));
        verticalLayout_11 = new QVBoxLayout(page_Gewuerze);
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        tableWidget_Zutaten_Gewuerze = new QTableWidget(page_Gewuerze);
        if (tableWidget_Zutaten_Gewuerze->columnCount() < 4)
            tableWidget_Zutaten_Gewuerze->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        __qtablewidgetitem29->setFont(font);
        tableWidget_Zutaten_Gewuerze->setHorizontalHeaderItem(0, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        __qtablewidgetitem30->setFont(font);
        tableWidget_Zutaten_Gewuerze->setHorizontalHeaderItem(1, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        __qtablewidgetitem31->setFont(font);
        tableWidget_Zutaten_Gewuerze->setHorizontalHeaderItem(2, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        __qtablewidgetitem32->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem32->setFont(font);
        tableWidget_Zutaten_Gewuerze->setHorizontalHeaderItem(3, __qtablewidgetitem32);
        tableWidget_Zutaten_Gewuerze->setObjectName(QString::fromUtf8("tableWidget_Zutaten_Gewuerze"));

        verticalLayout_10->addWidget(tableWidget_Zutaten_Gewuerze);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        pushButton_EintragNeu_Gewuerze = new QPushButton(page_Gewuerze);
        pushButton_EintragNeu_Gewuerze->setObjectName(QString::fromUtf8("pushButton_EintragNeu_Gewuerze"));

        horizontalLayout_10->addWidget(pushButton_EintragNeu_Gewuerze);

        pushButton_EintragKopie_Gewuerze = new QPushButton(page_Gewuerze);
        pushButton_EintragKopie_Gewuerze->setObjectName(QString::fromUtf8("pushButton_EintragKopie_Gewuerze"));

        horizontalLayout_10->addWidget(pushButton_EintragKopie_Gewuerze);

        pushButton_EintragDel_Gewuerze = new QPushButton(page_Gewuerze);
        pushButton_EintragDel_Gewuerze->setObjectName(QString::fromUtf8("pushButton_EintragDel_Gewuerze"));

        horizontalLayout_10->addWidget(pushButton_EintragDel_Gewuerze);


        verticalLayout_10->addLayout(horizontalLayout_10);


        verticalLayout_11->addLayout(verticalLayout_10);

        toolBox_Zutaten->addItem(page_Gewuerze, QString::fromUtf8("Gew\303\274rze"));
        page_Darm = new QWidget();
        page_Darm->setObjectName(QString::fromUtf8("page_Darm"));
        page_Darm->setGeometry(QRect(0, 0, 1221, 542));
        gridLayout_5 = new QGridLayout(page_Darm);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        tableWidget_Zutaten_Darm = new QTableWidget(page_Darm);
        if (tableWidget_Zutaten_Darm->columnCount() < 4)
            tableWidget_Zutaten_Darm->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        __qtablewidgetitem33->setFont(font);
        tableWidget_Zutaten_Darm->setHorizontalHeaderItem(0, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        __qtablewidgetitem34->setFont(font);
        tableWidget_Zutaten_Darm->setHorizontalHeaderItem(1, __qtablewidgetitem34);
        QFont font3;
        font3.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font3.setPointSize(10);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        __qtablewidgetitem35->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem35->setFont(font3);
        tableWidget_Zutaten_Darm->setHorizontalHeaderItem(2, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        __qtablewidgetitem36->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem36->setFont(font);
        tableWidget_Zutaten_Darm->setHorizontalHeaderItem(3, __qtablewidgetitem36);
        tableWidget_Zutaten_Darm->setObjectName(QString::fromUtf8("tableWidget_Zutaten_Darm"));

        verticalLayout_12->addWidget(tableWidget_Zutaten_Darm);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        pushButton_EintragNeu_Darm = new QPushButton(page_Darm);
        pushButton_EintragNeu_Darm->setObjectName(QString::fromUtf8("pushButton_EintragNeu_Darm"));

        horizontalLayout_11->addWidget(pushButton_EintragNeu_Darm);

        pushButton_EintragKopie_Darm = new QPushButton(page_Darm);
        pushButton_EintragKopie_Darm->setObjectName(QString::fromUtf8("pushButton_EintragKopie_Darm"));

        horizontalLayout_11->addWidget(pushButton_EintragKopie_Darm);

        pushButton_EintragDel_Darm = new QPushButton(page_Darm);
        pushButton_EintragDel_Darm->setObjectName(QString::fromUtf8("pushButton_EintragDel_Darm"));

        horizontalLayout_11->addWidget(pushButton_EintragDel_Darm);


        verticalLayout_12->addLayout(horizontalLayout_11);


        gridLayout_5->addLayout(verticalLayout_12, 0, 0, 1, 1);

        toolBox_Zutaten->addItem(page_Darm, QString::fromUtf8("D\303\244rme"));
        page_Wurstarten = new QWidget();
        page_Wurstarten->setObjectName(QString::fromUtf8("page_Wurstarten"));
        page_Wurstarten->setGeometry(QRect(0, 0, 1221, 542));
        gridLayout_9 = new QGridLayout(page_Wurstarten);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        label_Wurstarten = new QLabel(page_Wurstarten);
        label_Wurstarten->setObjectName(QString::fromUtf8("label_Wurstarten"));
        label_Wurstarten->setFont(font);

        gridLayout_6->addWidget(label_Wurstarten, 0, 0, 1, 1);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        tableWidget_Zutaten_Wurstart = new QTableWidget(page_Wurstarten);
        if (tableWidget_Zutaten_Wurstart->columnCount() < 2)
            tableWidget_Zutaten_Wurstart->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        __qtablewidgetitem37->setFont(font);
        tableWidget_Zutaten_Wurstart->setHorizontalHeaderItem(0, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        __qtablewidgetitem38->setFont(font);
        tableWidget_Zutaten_Wurstart->setHorizontalHeaderItem(1, __qtablewidgetitem38);
        tableWidget_Zutaten_Wurstart->setObjectName(QString::fromUtf8("tableWidget_Zutaten_Wurstart"));

        verticalLayout_13->addWidget(tableWidget_Zutaten_Wurstart);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        pushButton_EintragNeu_Wurstart = new QPushButton(page_Wurstarten);
        pushButton_EintragNeu_Wurstart->setObjectName(QString::fromUtf8("pushButton_EintragNeu_Wurstart"));

        horizontalLayout_12->addWidget(pushButton_EintragNeu_Wurstart);

        pushButton_EintragKopie_Wurstart = new QPushButton(page_Wurstarten);
        pushButton_EintragKopie_Wurstart->setObjectName(QString::fromUtf8("pushButton_EintragKopie_Wurstart"));

        horizontalLayout_12->addWidget(pushButton_EintragKopie_Wurstart);

        pushButton_EintragDel_Wurstart = new QPushButton(page_Wurstarten);
        pushButton_EintragDel_Wurstart->setObjectName(QString::fromUtf8("pushButton_EintragDel_Wurstart"));

        horizontalLayout_12->addWidget(pushButton_EintragDel_Wurstart);


        verticalLayout_13->addLayout(horizontalLayout_12);


        gridLayout_6->addLayout(verticalLayout_13, 1, 0, 1, 1);


        horizontalLayout_15->addLayout(gridLayout_6);

        gridLayout_7 = new QGridLayout();
        gridLayout_7->setSpacing(6);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        label_Verarbeitung = new QLabel(page_Wurstarten);
        label_Verarbeitung->setObjectName(QString::fromUtf8("label_Verarbeitung"));
        label_Verarbeitung->setFont(font);

        gridLayout_7->addWidget(label_Verarbeitung, 0, 0, 1, 1);

        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setSpacing(6);
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        tableWidget_Zutaten_Verarbeitung = new QTableWidget(page_Wurstarten);
        if (tableWidget_Zutaten_Verarbeitung->columnCount() < 2)
            tableWidget_Zutaten_Verarbeitung->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        __qtablewidgetitem39->setFont(font);
        tableWidget_Zutaten_Verarbeitung->setHorizontalHeaderItem(0, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        __qtablewidgetitem40->setFont(font);
        tableWidget_Zutaten_Verarbeitung->setHorizontalHeaderItem(1, __qtablewidgetitem40);
        tableWidget_Zutaten_Verarbeitung->setObjectName(QString::fromUtf8("tableWidget_Zutaten_Verarbeitung"));

        verticalLayout_14->addWidget(tableWidget_Zutaten_Verarbeitung);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        pushButton_EintragNeu_Verarbeitung = new QPushButton(page_Wurstarten);
        pushButton_EintragNeu_Verarbeitung->setObjectName(QString::fromUtf8("pushButton_EintragNeu_Verarbeitung"));

        horizontalLayout_13->addWidget(pushButton_EintragNeu_Verarbeitung);

        pushButton_EintragKopie_Verarbeitung = new QPushButton(page_Wurstarten);
        pushButton_EintragKopie_Verarbeitung->setObjectName(QString::fromUtf8("pushButton_EintragKopie_Verarbeitung"));

        horizontalLayout_13->addWidget(pushButton_EintragKopie_Verarbeitung);

        pushButton_EintragDel_Verarbeitung = new QPushButton(page_Wurstarten);
        pushButton_EintragDel_Verarbeitung->setObjectName(QString::fromUtf8("pushButton_EintragDel_Verarbeitung"));

        horizontalLayout_13->addWidget(pushButton_EintragDel_Verarbeitung);


        verticalLayout_14->addLayout(horizontalLayout_13);


        gridLayout_7->addLayout(verticalLayout_14, 1, 0, 1, 1);


        horizontalLayout_15->addLayout(gridLayout_7);

        gridLayout_8 = new QGridLayout();
        gridLayout_8->setSpacing(6);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        label_Einheiten = new QLabel(page_Wurstarten);
        label_Einheiten->setObjectName(QString::fromUtf8("label_Einheiten"));
        label_Einheiten->setFont(font);

        gridLayout_8->addWidget(label_Einheiten, 0, 0, 1, 1);

        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setSpacing(6);
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        tableWidget_Zutaten_Einheiten = new QTableWidget(page_Wurstarten);
        if (tableWidget_Zutaten_Einheiten->columnCount() < 3)
            tableWidget_Zutaten_Einheiten->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        __qtablewidgetitem41->setFont(font);
        tableWidget_Zutaten_Einheiten->setHorizontalHeaderItem(0, __qtablewidgetitem41);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        __qtablewidgetitem42->setFont(font);
        tableWidget_Zutaten_Einheiten->setHorizontalHeaderItem(1, __qtablewidgetitem42);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        tableWidget_Zutaten_Einheiten->setHorizontalHeaderItem(2, __qtablewidgetitem43);
        tableWidget_Zutaten_Einheiten->setObjectName(QString::fromUtf8("tableWidget_Zutaten_Einheiten"));

        verticalLayout_15->addWidget(tableWidget_Zutaten_Einheiten);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        pushButton_EintragNeu_Einheiten = new QPushButton(page_Wurstarten);
        pushButton_EintragNeu_Einheiten->setObjectName(QString::fromUtf8("pushButton_EintragNeu_Einheiten"));

        horizontalLayout_14->addWidget(pushButton_EintragNeu_Einheiten);

        pushButton_EintragKopie_Einheiten = new QPushButton(page_Wurstarten);
        pushButton_EintragKopie_Einheiten->setObjectName(QString::fromUtf8("pushButton_EintragKopie_Einheiten"));

        horizontalLayout_14->addWidget(pushButton_EintragKopie_Einheiten);

        pushButton_EintragDel_Einheiten = new QPushButton(page_Wurstarten);
        pushButton_EintragDel_Einheiten->setObjectName(QString::fromUtf8("pushButton_EintragDel_Einheiten"));

        horizontalLayout_14->addWidget(pushButton_EintragDel_Einheiten);


        verticalLayout_15->addLayout(horizontalLayout_14);


        gridLayout_8->addLayout(verticalLayout_15, 1, 0, 1, 1);


        horizontalLayout_15->addLayout(gridLayout_8);


        gridLayout_9->addLayout(horizontalLayout_15, 0, 0, 1, 1);

        toolBox_Zutaten->addItem(page_Wurstarten, QString::fromUtf8("Wurstarten / Verarbeitung / Einheiten"));

        gridLayout_4->addWidget(toolBox_Zutaten, 0, 0, 1, 1);

        tabWidget_oben->addTab(tab_Zutaten, QString());

        gridLayout_3->addWidget(tabWidget_oben, 0, 0, 1, 1);

        KWHClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(KWHClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setEnabled(false);
        menuBar->setGeometry(QRect(0, 0, 1263, 21));
        KWHClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(KWHClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setEnabled(false);
        KWHClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(KWHClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        KWHClass->setStatusBar(statusBar);

        retranslateUi(KWHClass);

        tabWidget_oben->setCurrentIndex(0);
        toolBox_Zutaten->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(KWHClass);
    } // setupUi

    void retranslateUi(QMainWindow *KWHClass)
    {
        KWHClass->setWindowTitle(QCoreApplication::translate("KWHClass", "kleiner Wursthelfer", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_Rezeptauswahl->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("KWHClass", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_Rezeptauswahl->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("KWHClass", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_Rezeptauswahl->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("KWHClass", "Art", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_Rezeptauswahl->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("KWHClass", "Darm", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_Rezeptauswahl->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("KWHClass", "Bemerkung", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_Rezeptauswahl->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("KWHClass", "Erstellt", nullptr));
        pushButton_Rezept_kopieren->setText(QCoreApplication::translate("KWHClass", "Rezept kopieren", nullptr));
        pushButton_Rezept_anlegen->setText(QCoreApplication::translate("KWHClass", "Rezept anlegen", nullptr));
        pushButton_Rezept_loeschen->setText(QCoreApplication::translate("KWHClass", "Rezept l\303\266schen", nullptr));
        tabWidget_oben->setTabText(tabWidget_oben->indexOf(tab_rezepte), QCoreApplication::translate("KWHClass", "Rezeptliste", nullptr));
        label_Fleisch->setText(QCoreApplication::translate("KWHClass", "Fleisch", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_Fleisch->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("KWHClass", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_Fleisch->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("KWHClass", "Zutat", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_Fleisch->horizontalHeaderItem(2);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("KWHClass", "Menge %", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_Fleisch->horizontalHeaderItem(3);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("KWHClass", "Verarbeitung", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_Fleisch->horizontalHeaderItem(4);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("KWHClass", "+", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_Fleisch->horizontalHeaderItem(5);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("KWHClass", "-", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget_Fleisch->horizontalHeaderItem(6);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("KWHClass", "V_ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget_Fleisch->horizontalHeaderItem(7);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("KWHClass", "Preis_p_Einh", nullptr));
        label_Gewuerze->setText(QCoreApplication::translate("KWHClass", "Gew\303\274rze / Kg", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget_Gewuerze->horizontalHeaderItem(0);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("KWHClass", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget_Gewuerze->horizontalHeaderItem(1);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("KWHClass", "Zutat", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget_Gewuerze->horizontalHeaderItem(2);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("KWHClass", "Menge / Einh.", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget_Gewuerze->horizontalHeaderItem(3);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("KWHClass", "Einheit", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget_Gewuerze->horizontalHeaderItem(4);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("KWHClass", "Verarbeitung", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget_Gewuerze->horizontalHeaderItem(5);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("KWHClass", "+", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget_Gewuerze->horizontalHeaderItem(6);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("KWHClass", "-", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget_Gewuerze->horizontalHeaderItem(7);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("KWHClass", "V_ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget_Gewuerze->horizontalHeaderItem(8);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("KWHClass", "Preis_p_Einh", nullptr));
        pushButton_Clear->setText(QCoreApplication::translate("KWHClass", "Clear", nullptr));
        pushButton_Rezept_speichern->setText(QCoreApplication::translate("KWHClass", "Speichern", nullptr));
        label_Name->setText(QCoreApplication::translate("KWHClass", "Name", nullptr));
        label_ID_Name->setText(QCoreApplication::translate("KWHClass", "NameID", nullptr));
        label_Art->setText(QCoreApplication::translate("KWHClass", "Art", nullptr));
        label_ID_Art->setText(QCoreApplication::translate("KWHClass", "IDArt", nullptr));
        label_Darm->setText(QCoreApplication::translate("KWHClass", "H\303\274lle", nullptr));
        label_ID_Darm->setText(QCoreApplication::translate("KWHClass", "IDH\303\274lle", nullptr));
        label_Name_2->setText(QCoreApplication::translate("KWHClass", "Verwurstung", nullptr));
        label_Verw_gewicht->setText(QCoreApplication::translate("KWHClass", "g", nullptr));
        label->setText(QCoreApplication::translate("KWHClass", "Zubereitung", nullptr));
        tabWidget_oben->setTabText(tabWidget_oben->indexOf(tab_Rezeptdetails), QCoreApplication::translate("KWHClass", "Rezeptdetails", nullptr));
        pushButton_Rezept_PDF->setText(QCoreApplication::translate("KWHClass", "speichern PDF", nullptr));
        tabWidget_oben->setTabText(tabWidget_oben->indexOf(tab_RezeptAusdruck), QCoreApplication::translate("KWHClass", "Rezeptausdruck", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget_Zutaten_Fleisch->horizontalHeaderItem(0);
        ___qtablewidgetitem23->setText(QCoreApplication::translate("KWHClass", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget_Zutaten_Fleisch->horizontalHeaderItem(1);
        ___qtablewidgetitem24->setText(QCoreApplication::translate("KWHClass", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget_Zutaten_Fleisch->horizontalHeaderItem(2);
        ___qtablewidgetitem25->setText(QCoreApplication::translate("KWHClass", "Fettanteil_%", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget_Zutaten_Fleisch->horizontalHeaderItem(3);
        ___qtablewidgetitem26->setText(QCoreApplication::translate("KWHClass", "Verschnitt_%", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget_Zutaten_Fleisch->horizontalHeaderItem(4);
        ___qtablewidgetitem27->setText(QCoreApplication::translate("KWHClass", "Einheit", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget_Zutaten_Fleisch->horizontalHeaderItem(5);
        ___qtablewidgetitem28->setText(QCoreApplication::translate("KWHClass", "Preis_p_Einh", nullptr));
        pushButton_EintragNeu_Fleisch->setText(QCoreApplication::translate("KWHClass", "Neuer Eintrag", nullptr));
        pushButton_EintragKopie_Fleisch->setText(QCoreApplication::translate("KWHClass", "Eintrag kopieren", nullptr));
        pushButton_EintragDel_Fleisch->setText(QCoreApplication::translate("KWHClass", "Eintrag l\303\266schen", nullptr));
        toolBox_Zutaten->setItemText(toolBox_Zutaten->indexOf(page_Fleisch), QCoreApplication::translate("KWHClass", "Fleisch", nullptr));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget_Zutaten_Gewuerze->horizontalHeaderItem(0);
        ___qtablewidgetitem29->setText(QCoreApplication::translate("KWHClass", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidget_Zutaten_Gewuerze->horizontalHeaderItem(1);
        ___qtablewidgetitem30->setText(QCoreApplication::translate("KWHClass", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem31 = tableWidget_Zutaten_Gewuerze->horizontalHeaderItem(2);
        ___qtablewidgetitem31->setText(QCoreApplication::translate("KWHClass", "Einheit", nullptr));
        QTableWidgetItem *___qtablewidgetitem32 = tableWidget_Zutaten_Gewuerze->horizontalHeaderItem(3);
        ___qtablewidgetitem32->setText(QCoreApplication::translate("KWHClass", "Preis", nullptr));
        pushButton_EintragNeu_Gewuerze->setText(QCoreApplication::translate("KWHClass", "Neuer Eintrag", nullptr));
        pushButton_EintragKopie_Gewuerze->setText(QCoreApplication::translate("KWHClass", "Eintrag kopieren", nullptr));
        pushButton_EintragDel_Gewuerze->setText(QCoreApplication::translate("KWHClass", "Eintrag l\303\266schen", nullptr));
        toolBox_Zutaten->setItemText(toolBox_Zutaten->indexOf(page_Gewuerze), QCoreApplication::translate("KWHClass", "Gew\303\274rze", nullptr));
        QTableWidgetItem *___qtablewidgetitem33 = tableWidget_Zutaten_Darm->horizontalHeaderItem(0);
        ___qtablewidgetitem33->setText(QCoreApplication::translate("KWHClass", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem34 = tableWidget_Zutaten_Darm->horizontalHeaderItem(1);
        ___qtablewidgetitem34->setText(QCoreApplication::translate("KWHClass", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem35 = tableWidget_Zutaten_Darm->horizontalHeaderItem(2);
        ___qtablewidgetitem35->setText(QCoreApplication::translate("KWHClass", "Einheit", nullptr));
        QTableWidgetItem *___qtablewidgetitem36 = tableWidget_Zutaten_Darm->horizontalHeaderItem(3);
        ___qtablewidgetitem36->setText(QCoreApplication::translate("KWHClass", "Preis", nullptr));
        pushButton_EintragNeu_Darm->setText(QCoreApplication::translate("KWHClass", "Neuer Eintrag", nullptr));
        pushButton_EintragKopie_Darm->setText(QCoreApplication::translate("KWHClass", "Eintrag kopieren", nullptr));
        pushButton_EintragDel_Darm->setText(QCoreApplication::translate("KWHClass", "Eintrag l\303\266schen", nullptr));
        toolBox_Zutaten->setItemText(toolBox_Zutaten->indexOf(page_Darm), QCoreApplication::translate("KWHClass", "D\303\244rme", nullptr));
        label_Wurstarten->setText(QCoreApplication::translate("KWHClass", "Wurstarten:", nullptr));
        QTableWidgetItem *___qtablewidgetitem37 = tableWidget_Zutaten_Wurstart->horizontalHeaderItem(0);
        ___qtablewidgetitem37->setText(QCoreApplication::translate("KWHClass", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem38 = tableWidget_Zutaten_Wurstart->horizontalHeaderItem(1);
        ___qtablewidgetitem38->setText(QCoreApplication::translate("KWHClass", "Name", nullptr));
        pushButton_EintragNeu_Wurstart->setText(QCoreApplication::translate("KWHClass", "Neuer Eintrag", nullptr));
        pushButton_EintragKopie_Wurstart->setText(QCoreApplication::translate("KWHClass", "Eintrag kopieren", nullptr));
        pushButton_EintragDel_Wurstart->setText(QCoreApplication::translate("KWHClass", "Eintrag l\303\266schen", nullptr));
        label_Verarbeitung->setText(QCoreApplication::translate("KWHClass", "Verarbeitung:", nullptr));
        QTableWidgetItem *___qtablewidgetitem39 = tableWidget_Zutaten_Verarbeitung->horizontalHeaderItem(0);
        ___qtablewidgetitem39->setText(QCoreApplication::translate("KWHClass", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem40 = tableWidget_Zutaten_Verarbeitung->horizontalHeaderItem(1);
        ___qtablewidgetitem40->setText(QCoreApplication::translate("KWHClass", "Verarbeitung", nullptr));
        pushButton_EintragNeu_Verarbeitung->setText(QCoreApplication::translate("KWHClass", "Neuer Eintrag", nullptr));
        pushButton_EintragKopie_Verarbeitung->setText(QCoreApplication::translate("KWHClass", "Eintrag kopieren", nullptr));
        pushButton_EintragDel_Verarbeitung->setText(QCoreApplication::translate("KWHClass", "Eintrag l\303\266schen", nullptr));
        label_Einheiten->setText(QCoreApplication::translate("KWHClass", "Einheiten", nullptr));
        QTableWidgetItem *___qtablewidgetitem41 = tableWidget_Zutaten_Einheiten->horizontalHeaderItem(0);
        ___qtablewidgetitem41->setText(QCoreApplication::translate("KWHClass", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem42 = tableWidget_Zutaten_Einheiten->horizontalHeaderItem(1);
        ___qtablewidgetitem42->setText(QCoreApplication::translate("KWHClass", "Einheit", nullptr));
        QTableWidgetItem *___qtablewidgetitem43 = tableWidget_Zutaten_Einheiten->horizontalHeaderItem(2);
        ___qtablewidgetitem43->setText(QCoreApplication::translate("KWHClass", "Kurzz.", nullptr));
        pushButton_EintragNeu_Einheiten->setText(QCoreApplication::translate("KWHClass", "Neuer Eintrag", nullptr));
        pushButton_EintragKopie_Einheiten->setText(QCoreApplication::translate("KWHClass", "Eintrag kopieren", nullptr));
        pushButton_EintragDel_Einheiten->setText(QCoreApplication::translate("KWHClass", "Eintrag l\303\266schen", nullptr));
        toolBox_Zutaten->setItemText(toolBox_Zutaten->indexOf(page_Wurstarten), QCoreApplication::translate("KWHClass", "Wurstarten / Verarbeitung / Einheiten", nullptr));
        tabWidget_oben->setTabText(tabWidget_oben->indexOf(tab_Zutaten), QCoreApplication::translate("KWHClass", "Zutaten", nullptr));
    } // retranslateUi

};

namespace Ui {
    class KWHClass: public Ui_KWHClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KWH_H
