#ifndef MYNEWDIALOG_H
#define MYNEWDIALOG_H

#include <qdialog.h>
#include <qapplication.h>
#include <qwidget.h>
#include <qcombobox.h>
#include <qboxlayout.h>
#include <qlayout.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include "ui_mynewdialog.h"
#include <qsqlquery.h>
#include <qsqlerror.h>
#include <qsqlrecord.h>
#include <qmessagebox.h>
#include <qsqlquerymodel.h>
#include "errormessage.h"
#include "definitionen.h"
#include <qstringlist.h>


class myNewDialog : public QDialog, public Ui::myNewDialog
{
	Q_OBJECT

public:
	//myNewDialog(QWidget *parent =0);
	myNewDialog(QString txtTitel, QString txtZeile1 = "Name :", QString txtZeile2 = "", QString txtZeile3 = "", QString txtZeile4 = "", QString txtZeile5 = "", QWidget *parent = 0);

	//~myNewDialog();
	QLineEdit *lineEdit[6];
	QComboBox *comboBox_Einh;
	QLabel *label_einh_id;
	void db_query_einheiten();

private:
	//Ui::myNewDialog ui;
	QVBoxLayout *mainLayout;
	QHBoxLayout *horizontalLayout[6];
	QLabel *label[6];
	QFont font;
	QSpacerItem *horizontalSpacer[6];
	QPushButton *pushButton_New_Ok;
	QPushButton *pushButton_New_Cnl;

	void NewInputLine(int index, QString Label);
	void NewComboLine(int index, QString Label);
	

private slots:
	void comboBox_Einh_currentIndexChanged(int index);
	void btnOKEnable();

};

#endif // !MYNEWDIALOG_H


