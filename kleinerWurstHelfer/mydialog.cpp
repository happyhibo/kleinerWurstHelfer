#include "mydialog.h"

mydialog::mydialog(QString titel, QString labeltxt1, QString labeltxt2, QString labeltxt3, QString labeltxt4, QString labeltxt5, QWidget * parent) : QDialog(parent)
{
	setupUi(this);
	this->setWindowTitle(titel);
	if (labeltxt5 == "")
	{
		label_5->setVisible(false);
		lineEdit_New_Label5->setVisible(false);
	}
	else
	{
		label_5->setVisible(true);
		lineEdit_New_Label5->setVisible(true);
		label_5->setText(labeltxt5);
	}

	if (labeltxt4 == "")
	{
		label_4->setVisible(false);
		label_einh_id->setVisible(false);
		comboBox_Einh->clear();
		comboBox_Einh->setVisible(false);
	}
	else
	{
		label_4->setVisible(true);
		comboBox_Einh->setVisible(true);
		label_4->setText(labeltxt4);
		label_einh_id->setVisible(true);
		db_query_einheiten();
	}

	if (labeltxt3 == "")
	{
		label_3->setVisible(false);
		lineEdit_New_Label3->setVisible(false);
	}
	else
	{
		label_3->setVisible(true);
		lineEdit_New_Label3->setVisible(true);
		label_3->setText(labeltxt3);
	}

	if (labeltxt2 == "")
	{
		label_2->setVisible(false);
		lineEdit_New_Label2->setVisible(false);
	}
	else
	{
		label_2->setVisible(true);
		lineEdit_New_Label2->setVisible(true);
		label_2->setText(labeltxt2);
	}

	label_1->setText(labeltxt1);
	pushButton_New_Ok->setEnabled(false);
	connect(pushButton_New_Ok, SIGNAL(clicked()), this, SLOT(accept()));
	connect(pushButton_New_cnl, SIGNAL(clicked()), this, SLOT(reject()));

}

//mydialog::~mydialog() 
//{
//	
//}

void mydialog::on_lineEdit_New_Label1_textChanged()
{
	pushButton_New_Ok->setEnabled(lineEdit_New_Label1->hasAcceptableInput());
}

void mydialog::db_query_einheiten() {

	// Combobox mit EInheiten füllen
	QSqlQuery dbquery_einh("SELECT * FROM einheiten ORDER BY e_name;");
	if (!dbquery_einh.isActive())
	{
		// Fehlermeldung Datenbankabfrage
		ErrorMessage* errorMessage = new ErrorMessage();
		errorMessage->showMessage(ERR_SQL_DB_ABFRAGE, TYPE_WARNUNG, CANCEL_NO,
			trUtf8("Rückgabe:\n") +
			dbquery_einh.lastError().databaseText() + trUtf8("\nSQL-Befehl:\n") + dbquery_einh.lastError().text());
	}
	QSqlQueryModel* model_einheiten = new QSqlQueryModel;
	model_einheiten->setQuery(dbquery_einh);
	model_einheiten->setHeaderData(0, Qt::Horizontal, "ID");
	model_einheiten->setHeaderData(1, Qt::Horizontal, "e_name");
	model_einheiten->setHeaderData(2, Qt::Horizontal, "e_kurzzzeichen");
	comboBox_Einh->clear();
	comboBox_Einh->setModel(model_einheiten);
	comboBox_Einh->setModelColumn(1);

}

void mydialog::on_comboBox_Einh_currentIndexChanged(int index)
{
	int row = comboBox_Einh->currentIndex();

	QModelIndex mindex = comboBox_Einh->model()->index(index, 0, comboBox_Einh->rootModelIndex());
	int dbID = comboBox_Einh->model()->data(mindex, 0).toInt();
	label_einh_id->setText(QString::number(dbID));
}