#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>
#include "ui_mydialog.h"
#include <qsqlquery.h>
#include <qsqlerror.h>
#include <qsqlrecord.h>
#include <qmessagebox.h>
#include <qsqlquerymodel.h>
#include "errormessage.h"
#include "definitionen.h"

class mydialog : public QDialog, public Ui::mydialog 
{
	Q_OBJECT

public:
	mydialog(QString titel, QString labeltxt1, QString labeltxt2 = "", QString labeltxt3 = "", QString labeltxt4 = "", QString labeltxt5 = "", QWidget * parent = 0);
	//~mydialog();

private:
	//Ui::mydialog *ui;
	void db_query_einheiten();

private slots:
	void on_lineEdit_New_Label1_textChanged();
	void on_comboBox_Einh_currentIndexChanged(int index);
};

#endif // MYDIALOG_H