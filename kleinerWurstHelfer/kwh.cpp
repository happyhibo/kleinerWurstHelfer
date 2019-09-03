
#include "kwh.h"

KWH::KWH(QWidget* parent) : QMainWindow(parent)
{

	setupUi(this);
	erstelleAktionen();
	erstelleMenue();
	initUi();
	ladeZutatenlisten();
	fuelleRezeptauswahl();

	//connect(tableWidget_Rezeptauswahl, SIGNAL(), this, SLOT());
	//connect(tableWidget_Rezeptauswahl, SIGNAL(cellClicked(int, int)), this, SLOT(slot_itemchanged()));
	connect(pushButton_Rezept_anlegen, SIGNAL(clicked()), this, SLOT(slot_pushButton_Rezept_anlegen_clicked()));
	connect(pushButton_Rezept_kopieren, SIGNAL(clicked()), this, SLOT(slot_pushButton_Rezept_kopieren_clicked()));
	connect(pushButton_Rezept_loeschen, SIGNAL(clicked()), this, SLOT(slot_pushButton_Rezept_loeschen_clicked()));
	//connect(tabWidget_oben, SIGNAL(currentChanged(int)), this, SLOT(slot_tabWidgetChanged(int)));
	//connect(spinBox_Verwurstung, SIGNAL(ReturnPressed()), this, SLOT(ladeRezeptberechnet()));
	connect(spinBox_Verwurstung, &MyQSpinbox::ReturnPressed, this, &KWH::ladeRezeptberechnet);
	//connect(tableWidget_Zutaten_Fleisch, SIGNAL(cellDoubleClicked(int,int)), this, SLOT(tableItemClicked(int,int)));
	connect(tableWidget_Zutaten_Fleisch, &QTableWidget::cellDoubleClicked, this, &KWH::changeEintragFleisch);
	connect(tableWidget_Zutaten_Gewuerze, &QTableWidget::cellDoubleClicked, this, &KWH::changeEintragGewuerz);
	connect(tableWidget_Zutaten_Darm, &QTableWidget::cellDoubleClicked, this, &KWH::changeEintragDarm);
	connect(actionEinstellungen, &QAction::triggered, this, &KWH::oeffneEinstellungen);
	connect(actionExit, &QAction::triggered, qApp, QApplication::quit);
}

KWH::~KWH()
{
}

void KWH::on_tableWidget_Rezeptauswahl_itemSelectionChanged()
{
	tableWidget_Rezeptauswahl->setFocus();
}

void KWH::on_tableWidget_Rezeptauswahl_cellDoubleClicked(int, int)
{
	ladeRezeptDetails();
}


void KWH::initUi() {

	label_ID_Art->setMinimumSize(0, 0);
	label_ID_Darm->setMinimumSize(0, 0);
	label_ID_Name->setMinimumSize(0, 0);
#ifdef DEBUG
	{
		label_ID_Art->setMaximumSize(50, 50);
		label_ID_Darm->setMaximumSize(50, 50);
		label_ID_Name->setMaximumSize(50, 50);
	}
#else
	{
		label_ID_Art->setMaximumSize(0, 0);
		label_ID_Darm->setMaximumSize(0, 0);
		label_ID_Name->setMaximumSize(0, 0);

	}
#endif //DEBUG	

	// Windowicon setzten
	kwh_icon.addFile(":/kwh_icon.ico", QSize(64, 64));
	setWindowIcon(kwh_icon);

	tableWidget_Rezeptauswahl->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
	tableWidget_Rezeptauswahl->horizontalHeader()->resizeSection(0, 30); //ID
	tableWidget_Rezeptauswahl->horizontalHeader()->resizeSection(1, 240); //Name
	tableWidget_Rezeptauswahl->horizontalHeader()->resizeSection(2, 200); //Art
	tableWidget_Rezeptauswahl->horizontalHeader()->resizeSection(3, 160); //Darm
	tableWidget_Rezeptauswahl->horizontalHeader()->resizeSection(4, 240); //Bemerkung
	tableWidget_Rezeptauswahl->horizontalHeader()->resizeSection(5, 115); //Erstellt
	tableWidget_Rezeptauswahl->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
	tableWidget_Rezeptauswahl->setSelectionBehavior(QAbstractItemView::SelectRows);
	tableWidget_Rezeptauswahl->setSelectionMode(QAbstractItemView::SingleSelection);
	tableWidget_Rezeptauswahl->verticalHeader()->setVisible(true);

	tableWidget_Fleisch->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
	tableWidget_Fleisch->horizontalHeader()->resizeSection(0, 30); //ID
	tableWidget_Fleisch->horizontalHeader()->resizeSection(1, 200); //Zutat
	tableWidget_Fleisch->horizontalHeader()->resizeSection(2, 80); //Menge%
	tableWidget_Fleisch->horizontalHeader()->resizeSection(3, 250); //Verarbeitung
	tableWidget_Fleisch->horizontalHeader()->resizeSection(4, 20); //+
	tableWidget_Fleisch->horizontalHeader()->resizeSection(5, 20); //-
	tableWidget_Fleisch->horizontalHeader()->resizeSection(6, 20); //Verarbeitungs-ID
	tableWidget_Fleisch->horizontalHeader()->resizeSection(7, 20); //Preis_PE
	tableWidget_Fleisch->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
	tableWidget_Fleisch->setSelectionBehavior(QAbstractItemView::SelectRows);
	tableWidget_Fleisch->setSelectionMode(QAbstractItemView::SingleSelection);
	tableWidget_Fleisch->verticalHeader()->setVisible(true);

	tableWidget_Gewuerze->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
	tableWidget_Gewuerze->horizontalHeader()->resizeSection(0, 30); //ID
	tableWidget_Gewuerze->horizontalHeader()->resizeSection(1, 200); //Zutat
	tableWidget_Gewuerze->horizontalHeader()->resizeSection(2, 100); //Menge/kg
	tableWidget_Gewuerze->horizontalHeader()->resizeSection(3, 50); //Menge_einh
	tableWidget_Gewuerze->horizontalHeader()->resizeSection(4, 250); //Verarbeitung
	tableWidget_Gewuerze->horizontalHeader()->resizeSection(5, 20); //+
	tableWidget_Gewuerze->horizontalHeader()->resizeSection(6, 20); //-
	tableWidget_Gewuerze->horizontalHeader()->resizeSection(7, 20); //Verarbeitungs-ID
	tableWidget_Gewuerze->horizontalHeader()->resizeSection(8, 20); //Preis_PE
	tableWidget_Gewuerze->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
	tableWidget_Gewuerze->setSelectionBehavior(QAbstractItemView::SelectRows);
	tableWidget_Gewuerze->setSelectionMode(QAbstractItemView::SingleSelection);
	tableWidget_Gewuerze->verticalHeader()->setVisible(true);

	tableWidget_Zutaten_Fleisch->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
	tableWidget_Zutaten_Fleisch->horizontalHeader()->resizeSection(0, 30); //ID
	tableWidget_Zutaten_Fleisch->horizontalHeader()->resizeSection(1, 200); //Name
	tableWidget_Zutaten_Fleisch->horizontalHeader()->resizeSection(2, 100); //Fettanteil %
	tableWidget_Zutaten_Fleisch->horizontalHeader()->resizeSection(3, 80); //Verschnitt %
	tableWidget_Zutaten_Fleisch->horizontalHeader()->resizeSection(4, 80); //Einheit
	tableWidget_Zutaten_Fleisch->horizontalHeader()->resizeSection(5, 80); //Preis
	tableWidget_Zutaten_Fleisch->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
	tableWidget_Zutaten_Fleisch->setSelectionBehavior(QAbstractItemView::SelectRows);
	tableWidget_Zutaten_Fleisch->setSelectionMode(QAbstractItemView::SingleSelection);
	tableWidget_Zutaten_Fleisch->verticalHeader()->setVisible(true);
	pushButton_EintragKopie_Fleisch->setVisible(false);

	tableWidget_Zutaten_Gewuerze->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
	tableWidget_Zutaten_Gewuerze->horizontalHeader()->resizeSection(0, 30); //ID
	tableWidget_Zutaten_Gewuerze->horizontalHeader()->resizeSection(1, 200); //Name
	tableWidget_Zutaten_Gewuerze->horizontalHeader()->resizeSection(2, 100); //Einheit
	tableWidget_Zutaten_Gewuerze->horizontalHeader()->resizeSection(3, 80); //Preis
	tableWidget_Zutaten_Gewuerze->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
	tableWidget_Zutaten_Gewuerze->setSelectionBehavior(QAbstractItemView::SelectRows);
	tableWidget_Zutaten_Gewuerze->setSelectionMode(QAbstractItemView::SingleSelection);
	tableWidget_Zutaten_Gewuerze->verticalHeader()->setVisible(true);
	pushButton_EintragKopie_Gewuerze->setVisible(false);

	tableWidget_Zutaten_Darm->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
	tableWidget_Zutaten_Darm->horizontalHeader()->resizeSection(0, 30); //ID
	tableWidget_Zutaten_Darm->horizontalHeader()->resizeSection(1, 200); //Name
	tableWidget_Zutaten_Darm->horizontalHeader()->resizeSection(2, 80); //Einheit
	tableWidget_Zutaten_Darm->horizontalHeader()->resizeSection(3, 80); //Preis
	tableWidget_Zutaten_Darm->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
	tableWidget_Zutaten_Darm->setSelectionBehavior(QAbstractItemView::SelectRows);
	tableWidget_Zutaten_Darm->setSelectionMode(QAbstractItemView::SingleSelection);
	tableWidget_Zutaten_Darm->verticalHeader()->setVisible(true);
	pushButton_EintragKopie_Darm->setVisible(false);

	tableWidget_Zutaten_Wurstart->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
	tableWidget_Zutaten_Wurstart->horizontalHeader()->resizeSection(0, 30); //ID
	tableWidget_Zutaten_Wurstart->horizontalHeader()->resizeSection(1, 200); //Name
	tableWidget_Zutaten_Wurstart->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
	tableWidget_Zutaten_Wurstart->setSelectionBehavior(QAbstractItemView::SelectRows);
	tableWidget_Zutaten_Wurstart->setSelectionMode(QAbstractItemView::SingleSelection);
	tableWidget_Zutaten_Wurstart->verticalHeader()->setVisible(true);
	pushButton_EintragKopie_Wurstart->setVisible(false);

	tableWidget_Zutaten_Verarbeitung->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
	tableWidget_Zutaten_Verarbeitung->horizontalHeader()->resizeSection(0, 30); //ID
	tableWidget_Zutaten_Verarbeitung->horizontalHeader()->resizeSection(1, 200); //Name
	tableWidget_Zutaten_Verarbeitung->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
	tableWidget_Zutaten_Verarbeitung->setSelectionBehavior(QAbstractItemView::SelectRows);
	tableWidget_Zutaten_Verarbeitung->setSelectionMode(QAbstractItemView::SingleSelection);
	tableWidget_Zutaten_Verarbeitung->verticalHeader()->setVisible(true);
	pushButton_EintragKopie_Verarbeitung->setVisible(false);

	tableWidget_Zutaten_Einheiten->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
	tableWidget_Zutaten_Einheiten->horizontalHeader()->resizeSection(0, 30); //ID
	tableWidget_Zutaten_Einheiten->horizontalHeader()->resizeSection(1, 200); //Name
	tableWidget_Zutaten_Einheiten->horizontalHeader()->resizeSection(2, 80); //Kurzzeichen
	tableWidget_Zutaten_Einheiten->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
	tableWidget_Zutaten_Einheiten->setSelectionBehavior(QAbstractItemView::SelectRows);
	tableWidget_Zutaten_Einheiten->setSelectionMode(QAbstractItemView::SingleSelection);
	tableWidget_Zutaten_Einheiten->verticalHeader()->setVisible(true);
	pushButton_EintragKopie_Einheiten->setVisible(false);

#ifndef DEBUG //Spalten ausblenden
	tableWidget_Rezeptauswahl->setColumnHidden(0, true); // ID
	tableWidget_Fleisch->setColumnHidden(0, true); // ID
	tableWidget_Fleisch->setColumnHidden(6, true); // Verarbeitungs-ID
	tableWidget_Fleisch->setColumnHidden(7, true); //Preis_PE
	tableWidget_Gewuerze->setColumnHidden(0, true); // ID
	tableWidget_Gewuerze->setColumnHidden(7, true); // Verarbeitungs-ID
	tableWidget_Gewuerze->setColumnHidden(8, true); // Preis_PE
	tableWidget_Zutaten_Fleisch->setColumnHidden(0, true); // ID
	tableWidget_Zutaten_Gewuerze->setColumnHidden(0, true); // ID
	tableWidget_Zutaten_Darm->setColumnHidden(0, true); // ID
	tableWidget_Zutaten_Wurstart->setColumnHidden(0, true); // ID
	tableWidget_Zutaten_Verarbeitung->setColumnHidden(0, true); // ID
	tableWidget_Zutaten_Einheiten->setColumnHidden(0, true); // ID
	tableWidget_Rezeptauswahl->verticalHeader()->setVisible(false);
	tableWidget_Fleisch->verticalHeader()->setVisible(false);
	tableWidget_Gewuerze->verticalHeader()->setVisible(false);
	tableWidget_Zutaten_Fleisch->verticalHeader()->setVisible(false);
	tableWidget_Zutaten_Gewuerze->verticalHeader()->setVisible(false);
	tableWidget_Zutaten_Darm->verticalHeader()->setVisible(false);
	tableWidget_Zutaten_Wurstart->verticalHeader()->setVisible(false);
	tableWidget_Zutaten_Verarbeitung->verticalHeader()->setVisible(false);
	tableWidget_Zutaten_Einheiten->verticalHeader()->setVisible(false);
#endif // !DEBUG

	tabWidget_oben->setCurrentIndex(0); // Tab Rezeptübersicht
	toolBox_Zutaten->setCurrentIndex(0);

}

void KWH::fuelleRezeptauswahl() 
{

	int FeldNr;
	int SelZeile = tableWidget_Rezeptauswahl->currentRow();
	if (SelZeile == -1)	SelZeile = 0;

	QString sql = "SELECT r.*, d.d_art, w.w_wurstart FROM rezeptliste as r ";
	sql += "LEFT JOIN darmliste as d on r.r_darm = d.ID ";
	sql += "LEFT JOIN wurstarten as w on r.r_art = w.ID;";
	QSqlQuery query;
	if(query.exec(sql)) {
		int i = 0;
		tableWidget_Rezeptauswahl->clearContents();
		tableWidget_Rezeptauswahl->setRowCount(0);
		tableWidget_Rezeptauswahl->setSortingEnabled(false);
		//tableWidget_Rezeptauswahl->setColumnHidden(6, true);
		while (query.next()) {
			tableWidget_Rezeptauswahl->setRowCount(tableWidget_Rezeptauswahl->rowCount() + 1);
			// ID
			FeldNr = query.record().indexOf("ID");
			QTableWidgetItem* newItem0 = new QTableWidgetItem(query.value(FeldNr).toString());
			tableWidget_Rezeptauswahl->setItem(i, 0, newItem0);
			// Rezeptname
			FeldNr = query.record().indexOf("r_name");
			QTableWidgetItem* newItem1 = new QTableWidgetItem(query.value(FeldNr).toString());
			tableWidget_Rezeptauswahl->setItem(i, 1, newItem1);
			// Rezeptart
			FeldNr = query.record().indexOf("w_wurstart");
			QTableWidgetItem* newItem2 = new QTableWidgetItem(query.value(FeldNr).toString());
			tableWidget_Rezeptauswahl->setItem(i, 2, newItem2);
			// Rezeptdarm
			FeldNr = query.record().indexOf("d_art");
			QTableWidgetItem* newItem3 = new QTableWidgetItem(query.value(FeldNr).toString());
			tableWidget_Rezeptauswahl->setItem(i, 3, newItem3);
			// Rezeptbemerkung
			FeldNr = query.record().indexOf("r_bemerkung");
			QTableWidgetItem* newItem4 = new QTableWidgetItem(query.value(FeldNr).toString());
			tableWidget_Rezeptauswahl->setItem(i, 4, newItem4);
			// Rezeptdarm
			FeldNr = query.record().indexOf("r_erstellt");
			QTableWidgetItem* newItem5 = new QTableWidgetItem(query.value(FeldNr).toString());
			newItem5->setData(Qt::DisplayRole, QDateTime::fromString(query.value(FeldNr).toString(), Qt::ISODate));
			newItem5->setTextAlignment(Qt::AlignCenter);
			tableWidget_Rezeptauswahl->setItem(i, 5, newItem5);
			i++;
		}
		tableWidget_Rezeptauswahl->setSortingEnabled(true);
		tableWidget_Rezeptauswahl->setCurrentCell(SelZeile, 0);
	}
	if (tableWidget_Rezeptauswahl->rowCount() == 0)
	{
		slot_pushButton_Rezept_anlegen_clicked();
		tableWidget_Rezeptauswahl->setSortingEnabled(true);
		tableWidget_Rezeptauswahl->setCurrentCell(0, 0);
	}

}

void KWH::slot_itemchanged() 
{
	int var[6];
	int count = tableWidget_Rezeptauswahl->columnCount();
	for (int i = 0; i < count; ++i) {
		var[i] = tableWidget_Rezeptauswahl->horizontalHeader()->sectionSize(i);
	}
}


void KWH::slot_pushButton_Rezept_anlegen_clicked() 
{


	pushButton_Rezept_anlegen->setEnabled(false);
	int ID = tableWidget_Rezeptauswahl->currentRow();

	// Neuen Datensatz anlegen
	QString sql = "INSERT INTO rezeptliste (r_name, r_erstellt) ";
	sql += "VALUES(";
	sql += "'Neues Rezept', ";
	sql += "'" + QDateTime::currentDateTime().toString(Qt::ISODate) + "')";
	QSqlQuery query;
	if (query.exec(sql)) {
		ID = tableWidget_Rezeptauswahl->rowCount();
	}

	fuelleRezeptauswahl();

	tableWidget_Rezeptauswahl->selectRow(ID);
	//tableWidget_Rezeptauswahl->setCurrentCell(ID, 0);
	pushButton_Rezept_anlegen->setEnabled(true);
}

void KWH::slot_pushButton_Rezept_kopieren_clicked() {

	bool io = true;
	QString id = tableWidget_Rezeptauswahl->item(tableWidget_Rezeptauswahl->currentRow(), 0)->text();
	QString name = tableWidget_Rezeptauswahl->item(tableWidget_Rezeptauswahl->currentRow(), 1)->text() + QString::fromLatin1(" Kopie");
	pushButton_Rezept_kopieren->setEnabled(false);
	QString ID_Neu;
	//Rezept kopieren
	QSqlDatabase::database().transaction();
	// Rezept
	QString sql = "INSERT INTO rezeptliste (";
	sql += "r_name, r_art, r_darm, r_bemerkung, r_erstellt";
	sql += ") SELECT ";
	sql += "'" + name + "', ";
	sql += "r_art, r_darm, r_bemerkung, ";
	sql += "'" + QDateTime::currentDateTime().toString(Qt::ISODate) + "'"; // r_erstellt
	sql += " FROM rezeptliste WHERE ID=" + id;
	QSqlQuery query;
	if (!query.exec(sql)) 
	{
	}
	// neue ID abrufen
	sql = "SELECT last_insert_rowid()";
	//QSqlQuery query;
	if (!query.exec(sql)) 
	{
		io = false;
	}
	else
	{
		query.first();
		ID_Neu = query.value(0).toString();
	}

	// Rezept Pos Fleisch
	sql = "INSERT INTO rezept_pos_fleisch (";
	sql += "rpf_rezept_id, rpf_zutat, rpf_menge_prozent, rpf_verarbeitung";
	sql += ") SELECT ";
	sql += "'" + ID_Neu + "', ";
	sql += "rpf_zutat, rpf_menge_prozent, rpf_verarbeitung";
	sql += " FROM rezept_pos_fleisch WHERE rpf_rezept_id=" + id;
	//QSqlQuery query;
	if (!query.exec(sql))
	{
		io = false;
	}

	// Rezept Pos Gewürz
	sql = "INSERT INTO rezept_pos_gewuerze (";
	sql += "rpg_rezept_id, rpg_zutat, rpg_menge_einheit, rpg_einheit, rpg_verarbeitung";
	sql += ") SELECT ";
	sql += "'" + ID_Neu + "', ";
	sql += "rpg_zutat, rpg_menge_einheit, rpg_einheit, rpg_verarbeitung";
	sql += " FROM rezept_pos_gewuerze WHERE rpg_rezept_id=" + id;
	//QSqlQuery query;
	if (!query.exec(sql))
	{
		io = false;
	}

	if (!io) {
		// Fehlermeldung konnte Rezept nicht kopieren
		ErrorMessage* errorMessage = new ErrorMessage();
		errorMessage->showMessage(ERR_SQL_DB_USER_KOPIE, TYPE_KRITISCH,
			CANCEL_PROGRAM, QObject::tr("Rezept konnte nicht kopiert werden!!"));
		return;
	}
	else
	{
		QSqlDatabase::database().commit();
		fuelleRezeptauswahl();
	}

	pushButton_Rezept_loeschen->setEnabled(true);

}

void KWH::slot_pushButton_Rezept_loeschen_clicked() {

	pushButton_Rezept_loeschen->setEnabled(false);
	int row = tableWidget_Rezeptauswahl->currentRow();
	QString ID = tableWidget_Rezeptauswahl->item(row, 0)->text();
	QString Rezeptname = tableWidget_Rezeptauswahl->item(row, 1)->text();

	// Abfrage ob gelöscht werden soll
	QMessageBox msgBox;
	msgBox.setWindowTitle(QString::fromLatin1("Löschen?"));
	msgBox.setText(QString::fromLatin1("Soll das Rezept<b> ") + Rezeptname + QString::fromLatin1(" </b>gelöscht werden?"));
	msgBox.setInformativeText(QString::fromLatin1("<b>Achtung, dies kann nicht rückgängig gemacht werden!</b>"));
	msgBox.setIcon(QMessageBox::Warning);
	QPushButton* LoeschButton = msgBox.addButton(QString::fromLatin1("Löschen"), QMessageBox::ActionRole);
	msgBox.setDefaultButton(msgBox.addButton(QString::fromLatin1("Abrechen"), QMessageBox::ActionRole));

	msgBox.exec();

	if (msgBox.clickedButton() == LoeschButton) {
		QSqlQuery query;
		// Rezeptliste Datensatz löschen
		QString sql = "DELETE FROM rezeptliste WHERE ID=" + ID + ";";
		if (!query.exec(sql))
		{
		}
		// RezeptPosFleisch Datensatz löschen
		sql = "DELETE FROM rezept_pos_fleisch WHERE ID=" + ID + ";";
		//QSqlQuery query;
		if (!query.exec(sql))
		{
		}

		// RezeptPosGewuerz Datensatz löschen
		sql = "DELETE FROM rezept_pos_gewuerze WHERE ID=" + ID + ";";
		//QSqlQuery query;
		if (!query.exec(sql))
		{
		}

		fuelleRezeptauswahl();
	}
	pushButton_Rezept_loeschen->setEnabled(true);
}

void KWH::NeueZeileFleisch(int id, int menge_prozent, int verarbeitung) {

	int n = tableWidget_Fleisch->rowCount();
	tableWidget_Fleisch->setRowCount(n + 1);

	//ID
	tableWidget_Fleisch->setItem(n, 0, new QTableWidgetItem(QString::number(id)));

	// Zutat
	QString sql ="SELECT * FROM zutatenliste_fleisch ORDER BY zlf_name;";
	QSqlQuery query;
	if (!query.exec(sql))
	{
	}
	QSqlQueryModel* model_zutat = new QSqlQueryModel;
	model_zutat->setQuery(query);
	model_zutat->setHeaderData(0, Qt::Horizontal, "ID");
	model_zutat->setHeaderData(1, Qt::Horizontal, "zlf_name");
	model_zutat->setHeaderData(2, Qt::Horizontal, "zlf_fettanteil");
	model_zutat->setHeaderData(3, Qt::Horizontal, "zlf_verschnitt");
	model_zutat->setHeaderData(4, Qt::Horizontal, "zlf_einheit");
	model_zutat->setHeaderData(5, Qt::Horizontal, "zlf_preis_p_einh");

	MyQComboBox* comboBox_Zutat = new MyQComboBox();
	comboBox_Zutat->clear();
	comboBox_Zutat->setModel(model_zutat);
	comboBox_Zutat->setModelColumn(1);
	int mRows = comboBox_Zutat->model()->rowCount();
	// auswahl anwÃ¤hlen		
	for (int i = 0; i < mRows; i++) {
		QModelIndex mIndex = comboBox_Zutat->model()->index(i, 0, comboBox_Zutat->rootModelIndex());
		QModelIndex mIndex2 = comboBox_Zutat->model()->index(i, 5);
		int mID = comboBox_Zutat->model()->data(mIndex, 0).toInt();
		QString PreisPE = comboBox_Zutat->model()->data(mIndex2, 0).toString();
		if (mID == id) {
			comboBox_Zutat->setCurrentIndex(i);
			tableWidget_Fleisch->setItem(n, 7, new QTableWidgetItem(PreisPE));
			tableWidget_Fleisch->item(n, 7)->setTextAlignment(Qt::AlignCenter);
			break;
		}
	}
	tableWidget_Fleisch->setCellWidget(n, 1, comboBox_Zutat);
	tableWidget_Fleisch->setItem(n, 1, new QTableWidgetItem(comboBox_Zutat->currentText()));
	//comboBox_Zutat->setProperty("TableWidgetItem", QVariant::fromValue(static_cast<void *>(tableWidget_Fleisch->item(i, 1))));
	connect(comboBox_Zutat, SIGNAL(currentIndexChanged(int)), this, SLOT(slot_FleischZutatChanged(int)));

	// Menge %
	MyQDoubleSpinBox* spinBox_Menge = new MyQDoubleSpinBox();
	spinBox_Menge->setAlignment(Qt::AlignHCenter);
	spinBox_Menge->setMinimum(0);
	spinBox_Menge->setMaximum(100);
	spinBox_Menge->setDecimals(0);
	spinBox_Menge->setSingleStep(1);
	spinBox_Menge->setValue(menge_prozent);
	tableWidget_Fleisch->setCellWidget(n, 2, spinBox_Menge);
	tableWidget_Fleisch->setItem(n, 2, new QTableWidgetItem(spinBox_Menge->value()));

	//spinBox_Menge->setProperty("TableWidgetItem",QVariant::fromValue(static_cast<void *>(tableWidget_Fleisch->item(i, 2))));
	connect(spinBox_Menge, SIGNAL(valueChanged(double)), this, SLOT(slot_FleischMengeValueChanged(double)));


	//V_ID
	tableWidget_Fleisch->setItem(n, 6, new QTableWidgetItem(QString::number(verarbeitung)));
	//Verarbeitung
	sql = "SELECT ID, v_art FROM verarbeitung ORDER BY v_art;";
	//QSqlQuery query;
	if (!query.exec(sql))
	{
	}
	QSqlQueryModel* model_verarb = new QSqlQueryModel();
	model_verarb->setQuery(query);
	model_verarb->setHeaderData(0, Qt::Horizontal, "ID");
	model_verarb->setHeaderData(1, Qt::Horizontal, "v_art");

	MyQComboBox* comboBox_Verarb = new MyQComboBox();
	comboBox_Verarb->clear();
	comboBox_Verarb->setModel(model_verarb);
	comboBox_Verarb->setModelColumn(1);
	mRows = comboBox_Verarb->model()->rowCount();
	// auswahl anwÃ¤hlen		
	for (int i = 0; i < mRows; i++) {
		QModelIndex mIndex = comboBox_Verarb->model()->index(i, 0, comboBox_Verarb->rootModelIndex());
		int mID = comboBox_Verarb->model()->data(mIndex, 0).toInt();
		if (mID == verarbeitung) {
			comboBox_Verarb->setCurrentIndex(i);
			break;
		}
	}

	tableWidget_Fleisch->setCellWidget(n, 3, comboBox_Verarb);
	tableWidget_Fleisch->setItem(n, 3, new QTableWidgetItem(comboBox_Verarb->currentText()));
	//comboBox_Verarb->setProperty("TableWidgetItem", QVariant::fromValue(static_cast<void *>(tableWidget_Fleisch->item(i, 3))));
	connect(comboBox_Verarb, SIGNAL(currentIndexChanged(int)), this, SLOT(slot_FleischVerarbeitungChanged(int)));

}

void KWH::NeueZeileGewuerze(int id, int menge_einh, int verarbeitung)
{
	int n = tableWidget_Gewuerze->rowCount();
	tableWidget_Gewuerze->setRowCount(n + 1);

	//ID
	tableWidget_Gewuerze->setItem(n, 0, new QTableWidgetItem(QString::number(id)));

	// Zutat
	QString sql = "SELECT zg.ID, zg.zlg_name, eh.e_kurzzeichen, zg.zlg_einheit, zg.zlg_preis_p_einh FROM zutatenliste_gewuerze zg LEFT JOIN einheiten eh ON zg.zlg_einheit = eh.ID ORDER BY zlg_name;";
	QSqlQuery query;
	if (!query.exec(sql))
	{
	}
	QSqlQueryModel* model_gew_zutat = new QSqlQueryModel;
	model_gew_zutat->setQuery(query);
	model_gew_zutat->setHeaderData(0, Qt::Horizontal, "ID");
	model_gew_zutat->setHeaderData(1, Qt::Horizontal, "zlg_name");
	model_gew_zutat->setHeaderData(2, Qt::Horizontal, "e_kurzzzeichen");
	model_gew_zutat->setHeaderData(3, Qt::Horizontal, "zlg_einheit");
	model_gew_zutat->setHeaderData(4, Qt::Horizontal, "zlg_preis_p_einh");
	MyQComboBox* comboBox_Gew_Zutat = new MyQComboBox();
	comboBox_Gew_Zutat->clear();
	comboBox_Gew_Zutat->setModel(model_gew_zutat);
	comboBox_Gew_Zutat->setModelColumn(1);
	// Dann mit den Zutaten füllen
	int mRows = comboBox_Gew_Zutat->model()->rowCount();
	// auswahl anwÃ¤hlen		
	for (int i = 0; i < mRows; i++) {
		QModelIndex mIndex = comboBox_Gew_Zutat->model()->index(i, 0);
		QModelIndex mIndex2 = comboBox_Gew_Zutat->model()->index(i, 2);
		QModelIndex mIndex3 = comboBox_Gew_Zutat->model()->index(i, 4);
		int mID = comboBox_Gew_Zutat->model()->data(mIndex, 0).toInt();
		QString mEinh = comboBox_Gew_Zutat->model()->data(mIndex2, 0).toString();
		QString mPreisPE = comboBox_Gew_Zutat->model()->data(mIndex3, 0).toString();
		if (mID == id) {
			comboBox_Gew_Zutat->setCurrentIndex(i);
			//Einheit
			tableWidget_Gewuerze->setItem(n, 3, new QTableWidgetItem(mEinh));
			tableWidget_Gewuerze->item(n, 3)->setTextAlignment(Qt::AlignCenter);
			tableWidget_Gewuerze->setItem(n, 8, new QTableWidgetItem(mPreisPE));
			tableWidget_Gewuerze->item(n, 8)->setTextAlignment(Qt::AlignCenter);
			break;
		}
	}

	tableWidget_Gewuerze->setCellWidget(n, 1, comboBox_Gew_Zutat);
	tableWidget_Gewuerze->setItem(n, 1, new QTableWidgetItem(comboBox_Gew_Zutat->currentText()));
	//comboBox_Gew_Zutat->setProperty("TableWidgetItem", QVariant::fromValue(static_cast<void *>(tableWidget_Gewuerze->item(i, 1))));
	connect(comboBox_Gew_Zutat, SIGNAL(currentIndexChanged(int)), this, SLOT(slot_GewuerzZutatChanged(int)));

	// Menge Einh
	MyQDoubleSpinBox* spinBox_Gew_Menge = new MyQDoubleSpinBox();
	spinBox_Gew_Menge->setAlignment(Qt::AlignHCenter);
	spinBox_Gew_Menge->setMinimum(0);
	spinBox_Gew_Menge->setMaximum(9999.99);
	spinBox_Gew_Menge->setDecimals(2);
	spinBox_Gew_Menge->setSingleStep(0.1);
	spinBox_Gew_Menge->setValue(menge_einh);
	tableWidget_Gewuerze->setCellWidget(n, 2, spinBox_Gew_Menge);
	tableWidget_Gewuerze->setItem(n, 2, new QTableWidgetItem(spinBox_Gew_Menge->value()));

	//spinBox_Gew_Menge->setProperty("TableWidgetItem", QVariant::fromValue(static_cast<void *>(tableWidget_Gewuerze->item(i, 2))));
	connect(spinBox_Gew_Menge, SIGNAL(valueChanged(double)), this, SLOT(slot_GewuerzMengeValueChanged(double)));

	//Verarbeitung
	//V_ID
	tableWidget_Gewuerze->setItem(n, 7, new QTableWidgetItem(QString::number(verarbeitung)));
	//Verarbeitung
	sql = "SELECT ID, v_art FROM verarbeitung ORDER BY v_art;";
	//QSqlQuery query;
	if (!query.exec(sql))
	{
	}
	QSqlQueryModel* model_verarb = new QSqlQueryModel;
	model_verarb->setQuery(query);
	model_verarb->setHeaderData(0, Qt::Horizontal, "ID");
	model_verarb->setHeaderData(1, Qt::Horizontal, "v_art");
	MyQComboBox* comboBox_Gew_Verarb = new MyQComboBox();
	comboBox_Gew_Verarb->clear();
	comboBox_Gew_Verarb->setModel(model_verarb);
	comboBox_Gew_Verarb->setModelColumn(1);
	// Dann mit den Zutaten füllen
	mRows = comboBox_Gew_Verarb->model()->rowCount();
	// auswahl anwÃ¤hlen		
	for (int i = 0; i < mRows; i++) {
		QModelIndex mIndex = comboBox_Gew_Verarb->model()->index(i, 0, comboBox_Gew_Verarb->rootModelIndex());
		int mID = comboBox_Gew_Verarb->model()->data(mIndex, 0).toInt();
		if (mID == verarbeitung) {
			comboBox_Gew_Verarb->setCurrentIndex(i);
			break;
		}
	}

	tableWidget_Gewuerze->setCellWidget(n, 4, comboBox_Gew_Verarb);
	tableWidget_Gewuerze->setItem(n, 4, new QTableWidgetItem(comboBox_Gew_Verarb->currentText()));
	//comboBox_Gew_Verarb->setProperty("TableWidgetItem", QVariant::fromValue(static_cast<void *>(tableWidget_Gewuerze->item(i, 4))));
	connect(comboBox_Gew_Verarb, SIGNAL(currentIndexChanged(int)), this, SLOT(slot_GewuerzVerarbeitungChanged(int)));

	//V_ID
	//tableWidget_Gewuerze->setItem(i, 7, new QTableWidgetItem(""));

}

void KWH::ladeRezeptDetails()
{
	int r_art_id, r_darm_id, r_zubereitung_id;
	QString w_art, d_art, v_art;
	bool neuesRezept = false;
	int FeldNr;

	clearRezeptDetails();

	//Rezeptid abfragen
	int row = tableWidget_Rezeptauswahl->currentRow();
	QString ID = tableWidget_Rezeptauswahl->item(row, 0)->text();

	//Rezeptdaten laden
	label_ID_Name->setText(ID);

	//Name
	lineEdit_Name->setText(tableWidget_Rezeptauswahl->item(row, 1)->text());
	if (tableWidget_Rezeptauswahl->item(row, 1)->text() == "Neues Rezept")
	{
		neuesRezept = true;
	}

	//Combo Wurstart
	QString sql = "SELECT * FROM rezeptliste WHERE ID=" + ID + ";";
	QSqlQuery query;
	if (!query.exec(sql))
	{
	}
	query.first();
	r_art_id = query.value(2).toInt();
	r_darm_id = query.value(3).toInt();
	r_zubereitung_id = query.value(4).toInt();

	if (!neuesRezept)
	{
		sql = "SELECT * FROM wurstarten WHERE ID=" + QString::number(r_art_id) + ";";
		if (!query.exec(sql))
		{
		}
		query.first();
		w_art = query.value(1).toString();

		sql = "SELECT * FROM darmliste WHERE ID=" + QString::number(r_darm_id) + ";";
		if (!query.exec(sql))
		{
		}
		query.first();
		d_art = query.value(1).toString();
	}

	sql = "SELECT ID, w_wurstart FROM wurstarten ORDER BY w_wurstart";
	//QSqlQuery query;
	if (!query.exec(sql))
	{
	}
	QSqlQueryModel* model_art = new QSqlQueryModel;
	model_art->setQuery(query);
	model_art->setHeaderData(0, Qt::Horizontal, "ID");
	model_art->setHeaderData(1, Qt::Horizontal, "w_wurstart");

	connect(comboBox_Art, SIGNAL(currentIndexChanged(int)), this, SLOT(slot_WurstartChanged(int)));
	// Aktuelle Auswahl zwischenspeichern
	comboBox_Art->clear();
	comboBox_Art->setModel(model_art);
	comboBox_Art->setModelColumn(1);

	if (neuesRezept)
	{
		comboBox_Art->setCurrentIndex(0);
	}
	else
	{
		int mRows = comboBox_Art->model()->rowCount();
		// auswahl anwÃ¤hlen		
		for (int i = 0; i < mRows - 1; i++) {
			QModelIndex mIndex = comboBox_Art->model()->index(i, 0, comboBox_Art->rootModelIndex());
			int mID = comboBox_Art->model()->data(mIndex, 0).toInt();
			if (mID == r_art_id) comboBox_Art->setCurrentIndex(i);
		}
	}
	
	sql = "SELECT * FROM darmliste ORDER BY d_art";
	//QSqlQuery query;
	if (!query.exec(sql))
	{
	}
	QSqlQueryModel* model_darm = new QSqlQueryModel;
	model_darm->setQuery(query);
	model_darm->setHeaderData(0, Qt::Horizontal, "ID");
	model_darm->setHeaderData(1, Qt::Horizontal, "d_art");
	model_darm->setHeaderData(2, Qt::Horizontal, "d_preis_p_einh");

	connect(comboBox_Darm, SIGNAL(currentIndexChanged(int)), this, SLOT(slot_HuelleChanged(int)));
	comboBox_Darm->clear();
	comboBox_Darm->setModel(model_darm);
	comboBox_Darm->setModelColumn(1);
	if (neuesRezept)
	{
		comboBox_Darm->setCurrentIndex(0);
	}
	else
	{
		int mRows = comboBox_Darm->model()->rowCount();
		// auswahl anwÃ¤hlen		
		for (int i = 0; i < mRows - 1; i++) {
			QModelIndex mIndex = comboBox_Darm->model()->index(i, 0, comboBox_Darm->rootModelIndex());
			int mID = comboBox_Darm->model()->data(mIndex, 0).toInt();
			if (mID == r_darm_id) comboBox_Darm->setCurrentIndex(i);
		}
	}

	//Fleischzutatenliste füllen
	if (neuesRezept)
	{
		NeueZeileFleisch(1, 0, 1);
	}
	else
	{
		//Rezeptdetails aus Fleisch_Pos
		sql = "SELECT * FROM rezept_pos_fleisch WHERE rpf_rezept_id=" + ID + ";";
		//QSqlQuery query;
		if (!query.exec(sql))
		{
		}
		tableWidget_Fleisch->clearContents();
		tableWidget_Fleisch->setRowCount(0);
		tableWidget_Fleisch->setSortingEnabled(false);
		//int i = 0;
		while (query.next()) {
			// Zutat
			FeldNr = query.record().indexOf("rpf_zutat");
			int FeldZutatID = query.value(FeldNr).toInt();

			// Menge_%
			FeldNr = query.record().indexOf("rpf_menge_prozent");
			int FeldMenge = query.value(FeldNr).toInt();

			// Verarbeitung
			FeldNr = query.record().indexOf("rpf_verarbeitung");
			int FeldVerarbID = query.value(FeldNr).toInt();

			NeueZeileFleisch(FeldZutatID, FeldMenge, FeldVerarbID);

		}
		tableWidget_Fleisch->setSortingEnabled(true);
	}


	//Gewüzeliste füllen
	if (neuesRezept)
	{
		NeueZeileGewuerze(1, 0, 1);
	}
	else
	{
		//Rezeptdetails aus Gewürze_Pos
		sql = "SELECT * FROM rezept_pos_gewuerze WHERE rpg_rezept_id=" + ID + ";";
		//QSqlQuery query;
		if (!query.exec(sql))
		{
		}
		//int i = 0;
		tableWidget_Gewuerze->clearContents();
		tableWidget_Gewuerze->setRowCount(0);
		tableWidget_Gewuerze->setSortingEnabled(false);
		while (query.next()) {
			// Zutat
			FeldNr = query.record().indexOf("rpg_zutat");
			int GewZutatID = query.value(FeldNr).toInt();

			// Menge/kg
			FeldNr = query.record().indexOf("rpg_menge_einheit");
			int GewMenge = query.value(FeldNr).toInt();

			// Verarbeitung
			FeldNr = query.record().indexOf("rpg_verarbeitung");
			int GewVerarbID = query.value(FeldNr).toInt();

			NeueZeileGewuerze(GewZutatID, GewMenge, GewVerarbID);

		}
		tableWidget_Gewuerze->setSortingEnabled(true);
	}

	if (neuesRezept)
	{
		textEdit_Zubereitung->clear();
	}
	else
	{
		//Rezepttext aus der Zubereitung
		sql = "SELECT rpz_zubereitung FROM rezept_pos_zubereitung WHERE rpz_rezept_id=" + ID + ";";
		//QSqlQuery query;
		if (!query.exec(sql))
		{
		}
		if (query.first())
		{
			textEdit_Zubereitung->setPlainText(query.value(0).toString());
		}
	}
	tabWidget_oben->setCurrentIndex(1); //Tab Rezeptdetails	
}

void KWH::clearRezeptDetails()
{
	lineEdit_Name->clear();
	label_ID_Name->clear();
	label_ID_Art->clear();
	label_ID_Darm->clear();
	comboBox_Art->clear();
	comboBox_Art->setCurrentIndex(0);
	comboBox_Darm->clear();
	comboBox_Darm->setCurrentIndex(0);
	textEdit_Zubereitung->clear();
	for (int i = 0; i < tableWidget_Fleisch->rowCount(); i++)
	{
		tableWidget_Fleisch->removeRow(i);
	}
	tableWidget_Fleisch->setRowCount(0);
	tableWidget_Fleisch->clearContents();
	for (int i = 0; i < tableWidget_Gewuerze->rowCount(); i++)
	{
		tableWidget_Gewuerze->removeRow(i);
	}
	tableWidget_Gewuerze->setRowCount(0);
	tableWidget_Gewuerze->clearContents();

}

void KWH::ladeRezeptberechnet()
{
	erstelleRezeptVorschau2();
	tabWidget_oben->setCurrentIndex(2);
}


void KWH::ladeZutatenlisten()
{
	//sql = "SELECT * FROM zutatenliste_fleisch WHERE ID > 1 ORDER BY zlf_name ASC;";
	QString sql = "SELECT f.ID, f.zlf_name, f.zlf_fettanteil, f.zlf_verschnitt, e.e_kurzzeichen, f.zlf_preis_p_einh FROM zutatenliste_fleisch as f ";
	sql += "LEFT JOIN einheiten as e on f.zlf_einheit = e.ID ";
	sql += "WHERE f.ID > 1 ORDER BY f.zlf_name ASC;";
	QSqlQuery query;
	if (!query.exec(sql))
	{
	}
	int n = 0;
	tableWidget_Zutaten_Fleisch->clearContents();
	tableWidget_Zutaten_Fleisch->setRowCount(0);
	tableWidget_Zutaten_Fleisch->setSortingEnabled(false);
	tableWidget_Zutaten_Fleisch->setEditTriggers(QAbstractItemView::NoEditTriggers);
	while (query.next()) {
		tableWidget_Zutaten_Fleisch->setRowCount(tableWidget_Zutaten_Fleisch->rowCount() + 1);
		int rc = query.record().count();
		for (int i = 0; i < rc; i++)
		{
			QTableWidgetItem* newItem = new QTableWidgetItem(query.value(i).toString());
			tableWidget_Zutaten_Fleisch->setItem(n, i, newItem);
		}
		n++;
	}
	tableWidget_Zutaten_Fleisch->setSortingEnabled(true);
	

	//sql = "SELECT * FROM zutatenliste_gewuerze WHERE ID > 1 ORDER BY zlg_name ASC;";
	sql = "SELECT g.ID, g.zlg_name, e.e_kurzzeichen, g.zlg_preis_p_einh FROM zutatenliste_gewuerze as g ";
	sql += "LEFT JOIN einheiten as e on g.zlg_einheit = e.ID ";
	sql += "WHERE g.ID > 1 ORDER BY g.zlg_name ASC;";
	//QSqlQuery query;
	if (!query.exec(sql))
	{
	}
	n = 0;
	tableWidget_Zutaten_Gewuerze->clearContents();
	tableWidget_Zutaten_Gewuerze->setRowCount(0);
	tableWidget_Zutaten_Gewuerze->setSortingEnabled(false);
	tableWidget_Zutaten_Gewuerze->setEditTriggers(QAbstractItemView::NoEditTriggers);
	while (query.next()) {
		tableWidget_Zutaten_Gewuerze->setRowCount(tableWidget_Zutaten_Gewuerze->rowCount() + 1);
		int rc = query.record().count();
		for (int i = 0; i < rc; i++)
		{
			QTableWidgetItem* newItem = new QTableWidgetItem(query.value(i).toString());
			tableWidget_Zutaten_Gewuerze->setItem(n, i, newItem);
		}
		n++;
	}
	tableWidget_Zutaten_Gewuerze->setSortingEnabled(true);

	//sql = "SELECT * FROM darmliste WHERE ID > 1 ORDER BY d_art ASC;";
	sql = "SELECT dl.ID, dl.d_art, dl.d_durchmesser, e.e_kurzzeichen, dl.d_preis_p_einh FROM darmliste as dl ";
	sql += "LEFT JOIN einheiten as e on dl.d_einheit = e.ID ";
	sql += "WHERE dl.ID > 1 ORDER BY dl.d_art ASC;";
	//QSqlQuery query;
	if (!query.exec(sql))
	{
	}
	n = 0;
	tableWidget_Zutaten_Darm->clearContents();
	tableWidget_Zutaten_Darm->setRowCount(0);
	tableWidget_Zutaten_Darm->setSortingEnabled(false);
	tableWidget_Zutaten_Darm->setEditTriggers(QAbstractItemView::NoEditTriggers);
	while (query.next()) {
		tableWidget_Zutaten_Darm->setRowCount(tableWidget_Zutaten_Darm->rowCount() + 1);
		int rc = query.record().count();
		for (int i = 0; i < rc; i++)
		{
			QTableWidgetItem* newItem = new QTableWidgetItem(query.value(i).toString());
			tableWidget_Zutaten_Darm->setItem(n, i, newItem);
		}
		n++;
	}
	tableWidget_Zutaten_Darm->setSortingEnabled(true);

	sql = "SELECT * FROM wurstarten WHERE ID > 1 ORDER BY w_wurstart ASC;";
	//QSqlQuery query;
	if (!query.exec(sql))
	{
	}
	n = 0;
	tableWidget_Zutaten_Wurstart->clearContents();
	tableWidget_Zutaten_Wurstart->setRowCount(0);
	tableWidget_Zutaten_Wurstart->setSortingEnabled(false);
	tableWidget_Zutaten_Wurstart->setEditTriggers(QAbstractItemView::NoEditTriggers);
	while (query.next()) {
		tableWidget_Zutaten_Wurstart->setRowCount(tableWidget_Zutaten_Wurstart->rowCount() + 1);
		int rc = query.record().count();
		for (int i = 0; i < rc; i++)
		{
			QTableWidgetItem* newItem = new QTableWidgetItem(query.value(i).toString());
			tableWidget_Zutaten_Wurstart->setItem(n, i, newItem);
		}
		n++;
	}
	tableWidget_Zutaten_Wurstart->setSortingEnabled(true);

	sql = "SELECT * FROM verarbeitung WHERE ID > 1 ORDER BY v_art ASC;";
	//QSqlQuery query;
	if (!query.exec(sql))
	{
	}
	n = 0;
	tableWidget_Zutaten_Verarbeitung->clearContents();
	tableWidget_Zutaten_Verarbeitung->setRowCount(0);
	tableWidget_Zutaten_Verarbeitung->setSortingEnabled(false);
	tableWidget_Zutaten_Verarbeitung->setEditTriggers(QAbstractItemView::NoEditTriggers);
	while (query.next()) {
		tableWidget_Zutaten_Verarbeitung->setRowCount(tableWidget_Zutaten_Verarbeitung->rowCount() + 1);
		int rc = query.record().count();
		for (int i = 0; i < rc; i++)
		{
			QTableWidgetItem* newItem = new QTableWidgetItem(query.value(i).toString());
			tableWidget_Zutaten_Verarbeitung->setItem(n, i, newItem);
		}
		n++;
	}
	tableWidget_Zutaten_Verarbeitung->setSortingEnabled(true);

	sql = "SELECT * FROM einheiten WHERE ID > 1 ORDER BY e_name ASC;";
	//QSqlQuery query;
	if (!query.exec(sql))
	{
	}
	n = 0;
	tableWidget_Zutaten_Einheiten->clearContents();
	tableWidget_Zutaten_Einheiten->setRowCount(0);
	tableWidget_Zutaten_Einheiten->setSortingEnabled(false);
	tableWidget_Zutaten_Einheiten->setEditTriggers(QAbstractItemView::NoEditTriggers);
	while (query.next()) {
		tableWidget_Zutaten_Einheiten->setRowCount(tableWidget_Zutaten_Einheiten->rowCount() + 1);
		int rc = query.record().count();
		for (int i = 0; i < rc; i++)
		{
			QTableWidgetItem* newItem = new QTableWidgetItem(query.value(i).toString());
			tableWidget_Zutaten_Einheiten->setItem(n, i, newItem);
		}
		n++;
	}
	tableWidget_Zutaten_Wurstart->setSortingEnabled(true);
}

void KWH::schreibeRezeptPosFleisch(QString aktID)
{
	//schreibe ReztepPosFleisch
	QString	sql = "DELETE FROM rezept_pos_fleisch WHERE rpf_rezept_id =" + aktID;
	QSqlQuery query;
	if (!query.exec(sql))
	{
	}
	for (int i = 0; i < tableWidget_Fleisch->rowCount(); i++) {
		QDoubleSpinBox* spinBox_Menge = (QDoubleSpinBox*)tableWidget_Fleisch->cellWidget(i, 2);
		sql = "INSERT INTO rezept_pos_fleisch('rpf_rezept_id', 'rpf_zutat', 'rpf_menge_prozent', 'rpf_verarbeitung') VALUES('";
		sql += aktID + "', '";
		sql += tableWidget_Fleisch->item(i, 0)->text() + "', '";
		sql += QString::number(spinBox_Menge->value()) + "', '";
		sql += tableWidget_Fleisch->item(i, 6)->text() + "');";
		//QSqlQuery query;
		if (!query.exec(sql))
		{
		}
	}
}

void KWH::schreibeRezeptPosGewuerze(QString aktID)
{
	//schreibe ReztepPosFleisch
	QString sql = "DELETE FROM rezept_pos_gewuerze WHERE rpg_rezept_id =" + aktID;
	QSqlQuery query;
	if (!query.exec(sql))
	{
	}

	for (int i = 0; i < tableWidget_Gewuerze->rowCount(); i++) {
		QDoubleSpinBox* spinBox_Gew_Menge = (QDoubleSpinBox*)tableWidget_Gewuerze->cellWidget(i, 2);
		QComboBox* comboBox_Gew_Zutat = (QComboBox*)tableWidget_Gewuerze->cellWidget(i, 1);
		QModelIndex mIndex = comboBox_Gew_Zutat->model()->index(comboBox_Gew_Zutat->currentIndex(), 3); //EinheitenID auslesen 3.Col
		int mID = comboBox_Gew_Zutat->model()->data(mIndex, 0).toInt();
		sql = "INSERT INTO rezept_pos_gewuerze('rpg_rezept_id', 'rpg_zutat', 'rpg_menge_einheit', 'rpg_einheit', 'rpg_verarbeitung') VALUES('";
		sql += aktID + "', '";
		sql += tableWidget_Gewuerze->item(i, 0)->text() + "', '";
		sql += QString::number(spinBox_Gew_Menge->value()) + "', '";
		//sql += tableWidget_Gewuerze->item(i, 2)->text() + "', '";
		sql += QString::number(mID) + "', '";
		sql += tableWidget_Gewuerze->item(i, 7)->text() + "');";
		//QSqlQuery query;
		if (!query.exec(sql))
		{
		}
	}
}

void KWH::schreibeRezeptPosZubereitung(QString aktID)
{
	QString lastID;
	//schreibe RezeptPosZubereitung
	QString sql = "DELETE FROM rezept_pos_zubereitung WHERE rpz_rezept_id =" + aktID;
	QSqlQuery query;
	if (!query.exec(sql))
	{
	}

	sql = "INSERT INTO rezept_pos_zubereitung('rpz_rezept_id', 'rpz_zubereitung') VALUES('";
	sql += aktID + "', '";
	sql += textEdit_Zubereitung->document()->toPlainText().replace("'", "''") + "');";
	//QSqlQuery query;
	if (!query.exec(sql))
	{
	}

	sql = "SELECT last_insert_rowid()";
	//QSqlQuery query;
	if (!query.exec(sql))
	{
	}
	query.first();
	lastID = query.value(0).toString();

	sql = "UPDATE rezeptliste SET ";
	sql += "r_zubereitung = '" + lastID + "';";
	//QSqlQuery query;
	if (!query.exec(sql))
	{
	}
}


void KWH::on_tableWidget_Fleisch_cellClicked(int row, int col) {

	int plusCol = 4;
	int minusCol = 5;
	int aktRow = tableWidget_Fleisch->currentRow();
	int lastRow = tableWidget_Fleisch->rowCount() - 1;

	if (row == lastRow && col == plusCol) //nur in der letzte Zeile kann eine neue Zeile eingefügt werden
	{
		NeueZeileFleisch(1, 0, 1);
		tableWidget_Fleisch->setCurrentCell(tableWidget_Fleisch->rowCount() - 1, 0);
	}

	if (row == aktRow && col == minusCol) //aktuelle zeile löschen
	{
		//akt Zeile löschen
		if (tableWidget_Fleisch->rowCount() > 1)
		{
			tableWidget_Fleisch->removeRow(tableWidget_Fleisch->currentRow());
		}

	}

}

void KWH::on_tableWidget_Gewuerze_cellClicked(int row, int col)
{
	int plusCol = 5;
	int minusCol = 6;
	int aktRow = tableWidget_Gewuerze->currentRow();
	int lastRow = tableWidget_Gewuerze->rowCount() - 1;

	if (row == lastRow && col == plusCol) //nur in der letzte Zeile kann eine neue Zeile eingefügt werden
	{
		NeueZeileGewuerze(1, 0, 1);
		tableWidget_Gewuerze->setCurrentCell(tableWidget_Gewuerze->rowCount() - 1, 0);
	}

	if (row == aktRow && col == minusCol) //aktuelle zeile löschen
	{
		//akt Zeile löschen
		if (tableWidget_Gewuerze->rowCount() > 1)
		{
			tableWidget_Gewuerze->removeRow(tableWidget_Gewuerze->currentRow());
		}

	}

}

void KWH::on_pushButton_Rezept_speichern_clicked()
{
	QString aktId = label_ID_Name->text();

	QString sql = "UPDATE rezeptliste SET ";
	sql += "r_name = '" + lineEdit_Name->text() + "', ";
	sql += "r_art = '" + label_ID_Art->text() + "', ";
	sql += "r_darm = '" + label_ID_Darm->text() + "' ";
	sql += "WHERE ID = " + aktId + ";";
	// Abfrage Abschicken
	QSqlQuery query;
	if (!query.exec(sql))
	{
	}
	schreibeRezeptPosFleisch(aktId);
	schreibeRezeptPosGewuerze(aktId);
	schreibeRezeptPosZubereitung(aktId);
	fuelleRezeptauswahl();
}

void KWH::slot_FleischZutatChanged(int index)
{
	int row = tableWidget_Fleisch->currentRow();

	QComboBox* comboBox_Zutat = (QComboBox*)tableWidget_Fleisch->cellWidget(row, 1);
	QModelIndex mIndex = comboBox_Zutat->model()->index(index, 0, comboBox_Zutat->rootModelIndex());
	QModelIndex mIndex2 = comboBox_Zutat->model()->index(index, 5);
	int dbID = comboBox_Zutat->model()->data(mIndex, 0).toInt();
	QString PreisPE = comboBox_Zutat->model()->data(mIndex2, 0).toString();
	tableWidget_Fleisch->item(row, 0)->setText(QString::number(dbID));
	tableWidget_Fleisch->item(row, 7)->setText(PreisPE);
}

void KWH::slot_GewuerzZutatChanged(int index)
{
	int row = tableWidget_Gewuerze->currentRow();
	
	QComboBox* comboBox_Gew_Zutat = (QComboBox*)tableWidget_Gewuerze->cellWidget(row, 1);
	QModelIndex mIndex = comboBox_Gew_Zutat->model()->index(index, 0);
	QModelIndex mIndex2 = comboBox_Gew_Zutat->model()->index(index, 2);
	QModelIndex mIndex3 = comboBox_Gew_Zutat->model()->index(index, 4);
	int mID = comboBox_Gew_Zutat->model()->data(mIndex, 0).toInt();
	QString mEinh = comboBox_Gew_Zutat->model()->data(mIndex2, 0).toString();
	QString mPreisPE = comboBox_Gew_Zutat->model()->data(mIndex3, 0).toString();
	tableWidget_Gewuerze->item(row, 0)->setText(QString::number(mID));
	tableWidget_Gewuerze->item(row, 3)->setText(mEinh);
	tableWidget_Gewuerze->item(row, 8)->setText(mPreisPE);
}

void KWH::slot_FleischVerarbeitungChanged(int index)
{
	int row = tableWidget_Fleisch->currentRow();

	QComboBox* comboBox_Zutat = (QComboBox*)tableWidget_Fleisch->cellWidget(row, 3);
	QModelIndex mIndex = comboBox_Zutat->model()->index(index, 0, comboBox_Zutat->rootModelIndex());
	int dbID = comboBox_Zutat->model()->data(mIndex, 0).toInt();
	tableWidget_Fleisch->item(row, 6)->setText(QString::number(dbID));

}

void KWH::slot_GewuerzVerarbeitungChanged(int index)
{
	int row = tableWidget_Gewuerze->currentRow();

	QComboBox* comboBox_Gew_Verarb = (QComboBox*)tableWidget_Gewuerze->cellWidget(row, 4);
	int colrow = comboBox_Gew_Verarb->currentIndex();
	QModelIndex mIndex = comboBox_Gew_Verarb->model()->index(index, 0, comboBox_Gew_Verarb->rootModelIndex());
	int dbID = comboBox_Gew_Verarb->model()->data(mIndex, 0).toInt();
	tableWidget_Gewuerze->item(row, 7)->setText(QString::number(dbID));

}

void KWH::slot_WurstartChanged(int index)
{
	int row = comboBox_Art->currentIndex();

	QModelIndex Mindex = comboBox_Art->model()->index(index, 0, comboBox_Art->rootModelIndex());
	int dbID = comboBox_Art->model()->data(Mindex, 0).toInt();
	label_ID_Art->setText(QString::number(dbID));

}

void KWH::slot_HuelleChanged(int index)
{
	int row = comboBox_Darm->currentIndex();
	
	QModelIndex Mindex = comboBox_Darm->model()->index(index, 0, comboBox_Darm->rootModelIndex());
	int dbID = comboBox_Darm->model()->data(Mindex, 0).toInt();
	label_ID_Darm->setText(QString::number(dbID));
}

void KWH::on_pushButton_Clear_clicked()
{
	//clearRezeptDetails();
	ladeRezeptberechnet();
}

void KWH::on_pushButton_EintragNeu_Einheiten_clicked()
{
	myNewDialog mNDlg("Neuer Eintrag", "Eintrag :", "Kurzzeichen :");
	QString db_tab = "einheiten";
	QString db_cell1 = "e_name";
	QString db_cell2 = "e_kurzzeichen";
	QString einheit;
	QString kurzz;
	QString sql;
	QSqlQuery query;
	bool ok = false;
	bool schreibeDB = false;
	do
	{
		mNDlg.show();

		if (mNDlg.exec() == QDialog::Accepted)
		{
			einheit = mNDlg.lineEdit[0]->text();
			kurzz = mNDlg.lineEdit[1]->text();
			sql = "SELECT Count(" + db_cell1 + ") FROM " + db_tab + " WHERE " + db_cell1 + " = '" + einheit + "';";
			if (!query.exec(sql))
			{
			}
			query.first();
			int eCount = query.value(0).toInt();
			if (eCount != 0)
			{
				QMessageBox msgBox;
				msgBox.setWindowTitle(QString::fromLatin1("Einheit vorhanden"));
				msgBox.setText(QString::fromLatin1("Die Einheit<b> ") + einheit + QString::fromLatin1(" </b>existiert bereits!"));
				msgBox.setIcon(QMessageBox::Information);
				msgBox.setStandardButtons(QMessageBox::Ok);
				msgBox.exec();
				return;
			}

			sql = "SELECT Count(" + db_cell2 + ") FROM " + db_tab + " WHERE " + db_cell2 + " = '" + kurzz + "';";
			//QSqlQuery query;
			if (!query.exec(sql))
			{
			}
			query.first();
			eCount = query.value(0).toInt();
			if (eCount != 0)
			{
				QMessageBox msgBox;
				msgBox.setWindowTitle(QString::fromLatin1("Kurzzeichen vorhanden"));
				msgBox.setText(QString::fromLatin1("Das Kurzzeichen<b> ") + kurzz + QString::fromLatin1(" </b>existiert bereits!"));
				msgBox.setIcon(QMessageBox::Information);
				msgBox.setStandardButtons(QMessageBox::Ok);
				msgBox.exec();
				return;
			}
			
			sql = "INSERT INTO '" + db_tab + "' (" + db_cell1 + ", " + db_cell2 + ") ";
			sql += "VALUES('" + einheit + "', '" + kurzz + "'); ";
			//QSqlQuery query;
			if (!query.exec(sql))
			{
			}
			ladeZutatenlisten();
			return;
		}
		else
		{
			ok = true;
		}
	} while (!ok);

}

void KWH::on_pushButton_EintragDel_Einheiten_clicked()
{
	QMessageBox msgBox;
	if (tableWidget_Zutaten_Einheiten->currentRow() == -1)
	{
		msgBox.setWindowTitle(QString::fromLatin1("Keine Einheit markiert"));
		msgBox.setText(QString::fromLatin1("Es wurde keine Einheit zu löschen markiert!"));
		msgBox.setIcon(QMessageBox::Information);
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.exec();
		return;
	}
	int rc = 0;
	QString db_tab = "einheiten";
	QString id = tableWidget_Zutaten_Einheiten->item(tableWidget_Zutaten_Einheiten->currentRow(), 0)->text();
	QString einh_txt = tableWidget_Zutaten_Einheiten->item(tableWidget_Zutaten_Einheiten->currentRow(), 1)->text();
	//Überprüfen ob zu löschende Verarbeitung in Rezepten verwendet wird
	QString sql = "SELECT * FROM rezept_pos_gewuerze WHERE rpg_einheit = " + id + ";";
	QSqlQuery query;
	if (!query.exec(sql))
	{
	}
	while (query.next())
	{
		rc += 1;
	}

	sql = "SELECT * FROM zutatenliste_fleisch WHERE zlf_einheit = " + id + ";";
	//QSqlQuery query;
	if (!query.exec(sql))
	{
	}
	while (query.next())
	{
		rc += 1;
	}

	sql = "SELECT * FROM zutatenliste_gewuerze WHERE zlg_einheit = " + id + ";";
	//QSqlQuery query;
	if (!query.exec(sql))
	{
	}
	while (query.next())
	{
		rc += 1;
	}

	sql = "SELECT * FROM darmliste WHERE d_einheit = " + id + ";";
	//QSqlQuery query;
	if (!query.exec(sql))
	{
	}
	while (query.next())
	{
		rc += 1;
	}

	if (rc != 0)
	{
		msgBox.setWindowTitle(QString::fromLatin1("In Rezepten gefunden"));
		QString msgtxt = QString::fromLatin1("Der Eintrag <br><b>") + einh_txt;
		msgtxt += QString::fromLatin1("</b><br> ist in <b>") + QString::number(rc);
		msgtxt += QString::fromLatin1("</b> Zutat(en) vorhanden<br><br>");
		msgtxt += QString::fromLatin1("<b>Löschen nicht möglich!!</b>");
		msgBox.setText(msgtxt);
		msgBox.setIcon(QMessageBox::Critical);
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.exec();
		return;
	}

	sql = "DELETE FROM " + db_tab + " WHERE ID = " + id + ";";
	msgBox.setWindowTitle(QString::fromLatin1("Einheit Löschen?"));
	msgBox.setText(QString::fromLatin1("Den Eintrag<b> ") + einh_txt + QString::fromLatin1(" </b>löschen?"));
	msgBox.setIcon(QMessageBox::Information);
	msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	int ret = msgBox.exec();

	if (ret == QMessageBox::Ok)
	{
		//QSqlQuery query;
		if (!query.exec(sql))
		{
		}
		ladeZutatenlisten();
	}
}

void KWH::on_pushButton_EintragNeu_Verarbeitung_clicked()
{
	myNewDialog mNDlg("Neuer Eintrag", "Eintrag :");
	QString eintrag;
	QString db_tab = "verarbeitung";
	QSqlQuery query;
	bool ok = false;
	do
	{
		mNDlg.show();

		if (mNDlg.exec() == QDialog::Accepted)
		{
			eintrag = mNDlg.lineEdit[0]->text();
			QString sql = "SELECT Count(v_art) FROM " + db_tab + " WHERE v_art = '" + eintrag + "';";
			if (!query.exec(sql))
			{
			}
			query.first();
			int eCount = query.value(0).toInt();
			if (eCount != 0)
			{
				QMessageBox msgBox;
				msgBox.setWindowTitle(QString::fromLatin1("Eintrag vorhanden!"));
				msgBox.setText(QString::fromLatin1("Der Eintrag <b>") + eintrag + QString::fromLatin1("</b> existiert bereits!"));
				msgBox.setIcon(QMessageBox::Information);
				msgBox.setStandardButtons(QMessageBox::Ok);
				msgBox.exec();
				return;
			}
			else
			{
				QString sql = "INSERT INTO '" + db_tab + "' ('v_art') VALUES ('" + eintrag + "');";
				//QSqlQuery query;
				if (!query.exec(sql))
				{
				}
				ladeZutatenlisten();
				return;
			}
		}
		else
		{
			ok = true;
		}
	} while (!ok);

}

void KWH::on_pushButton_EintragDel_Verarbeitung_clicked()
{
	QMessageBox msgBox;
	if (tableWidget_Zutaten_Verarbeitung->currentRow() == -1)
	{
		msgBox.setWindowTitle(QString::fromLatin1("Kein Eintrag markiert"));
		msgBox.setText(QString::fromLatin1("Es wurde kein Eintrag zum löschen markiert!"));
		msgBox.setIcon(QMessageBox::Information);
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.exec();
		return;
	}
	int rc = 0;
	QString db_tab = "verarbeitung";
	QString id = tableWidget_Zutaten_Verarbeitung->item(tableWidget_Zutaten_Verarbeitung->currentRow(), 0)->text();
	QString einh_txt = tableWidget_Zutaten_Verarbeitung->item(tableWidget_Zutaten_Verarbeitung->currentRow(), 1)->text();
	//Überprüfen ob zu löschende Verarbeitung in Rezepten verwendet wird
	QString sql = "SELECT * FROM rezept_pos_fleisch WHERE rpf_verarbeitung = " + id + ";";
	QSqlQuery query;
	if (!query.exec(sql))
	{
	}
	while (query.next())
	{
		rc += 1;
	}

	sql = "SELECT * FROM rezept_pos_gewuerze WHERE rpg_verarbeitung = " + id + ";";
	//QSqlQuery query;
	if (!query.exec(sql))
	{
	}
	while (query.next())
	{
		rc += 1;
	}

	if (rc != 0)
	{
		msgBox.setWindowTitle(QString::fromLatin1("In Rezepten gefunden"));
		QString msgtxt = QString::fromLatin1("Der Eintrag <br><b>") + einh_txt;
		msgtxt += QString::fromLatin1("</b><br> ist in <b>") + QString::number(rc);
		msgtxt += QString::fromLatin1("</b> Rezept(en) vorhanden<br><br>");
		msgtxt += QString::fromLatin1("<b>Löschen nicht möglich!!</b>");
		msgBox.setText(msgtxt);
		msgBox.setIcon(QMessageBox::Critical);
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.exec();
		return;
	}

	sql = "DELETE FROM " + db_tab + " WHERE ID = " + id + ";";
	msgBox.setWindowTitle(QString::fromLatin1("Eintrag löschen?"));
	msgBox.setText(QString::fromLatin1("Der Eintrag <b>") + einh_txt + QString::fromLatin1("</b> löschen?"));
	msgBox.setIcon(QMessageBox::Information);
	msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	int ret = msgBox.exec();

	if (ret == QMessageBox::Ok)
	{
		//QSqlQuery query;
		if (!query.exec(sql))
		{
		}
		ladeZutatenlisten();
	}
}

void KWH::on_pushButton_EintragNeu_Wurstart_clicked()
{
	myNewDialog mNDlg("Neuer Eintrag", "Wurstart-Name :");
	QString eintrag;
	QString db_tab = "wurstarten";
	QSqlQuery query;
	bool ok = false;
	bool schreibeDB = false;
	do
	{
		mNDlg.show();

		if (mNDlg.exec() == QDialog::Accepted)
		{
			eintrag = mNDlg.lineEdit[0]->text();
			QString sql = "SELECT Count(w_wurstart) FROM " + db_tab + " WHERE w_wurstart = '" + eintrag + "';";
			if (!query.exec(sql))
			{
			}
			query.first();
			int eCount = query.value(0).toInt();
			if (eCount != 0)
			{
				QMessageBox msgBox;
				msgBox.setWindowTitle(QString::fromLatin1("Eintrag vorhanden!"));
				msgBox.setText(QString::fromLatin1("Der Eintrag <b>") + eintrag + QString::fromLatin1("</b> existiert bereits!"));
				msgBox.setIcon(QMessageBox::Information);
				msgBox.setStandardButtons(QMessageBox::Ok);
				msgBox.exec();
				ok = false;
				schreibeDB = false;
			}
			else
			{
				ok = true;
				schreibeDB = true;
			}
		}
		else
		{
			ok = true;
		}
	} while (!ok);

	if (schreibeDB)
	{
		QString sql = "INSERT INTO '" + db_tab + "' ('w_wurstart') VALUES ('" + eintrag + "');";
		//QSqlQuery query;
		if (!query.exec(sql))
		{
		}
		ladeZutatenlisten();
	}

}

void KWH::on_pushButton_EintragDel_Wurstart_clicked()
{
	QMessageBox msgBox;
	if (tableWidget_Zutaten_Wurstart->currentRow() == -1)
	{
		msgBox.setWindowTitle(QString::fromLatin1("Kein Eintrag markiert"));
		msgBox.setText(QString::fromLatin1("Es wurde kein Eintrag zum löschen markiert!"));
		msgBox.setIcon(QMessageBox::Information);
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.exec();
		return;
	}
	//Überprüfen ob zu löschende wurstart in Rezepten verwendet wird
	int rc = 0;
	QString db_tab = "wurstarten";
	QString id = tableWidget_Zutaten_Wurstart->item(tableWidget_Zutaten_Wurstart->currentRow(), 0)->text();
	QString einh_txt = tableWidget_Zutaten_Wurstart->item(tableWidget_Zutaten_Wurstart->currentRow(), 1)->text();

	QString sql = "SELECT * FROM rezeptliste WHERE r_art = " + id + ";";
	QSqlQuery query;
	if (!query.exec(sql))
	{
	}
	while (query.next())
	{
		rc += 1;
	}
	if (rc != 0)
	{
		msgBox.setWindowTitle(QString::fromLatin1("In Rezepten gefunden"));
		QString msgtxt = QString::fromLatin1("Der Eintrag <br><b>") + einh_txt;
		msgtxt += QString::fromLatin1("</b><br> ist in <b>") + QString::number(rc);
		msgtxt += QString::fromLatin1("</b> Rezept(en) vorhanden<br><br>");
		msgtxt += QString::fromLatin1("<b>Löschen nicht möglich!!</b>");
		msgBox.setText(msgtxt);
		msgBox.setIcon(QMessageBox::Critical);
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.exec();
		return;
	}

	//Eintrag aus der DB löschen
	sql = "DELETE FROM " + db_tab + " WHERE ID = " + id + ";";
	msgBox.setWindowTitle(QString::fromLatin1("Eintrag löschen?"));
	msgBox.setText(QString::fromLatin1("Der Eintrag <b>") + einh_txt + QString::fromLatin1("</b> löschen?"));
	msgBox.setIcon(QMessageBox::Information);
	msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	int ret = msgBox.exec();

	if (ret == QMessageBox::Ok)
	{
		//QSqlQuery query;
		if (!query.exec(sql))
		{
		}
		ladeZutatenlisten();
	}
}


void KWH::slot_FleischMengeValueChanged(double val)
{

}

void KWH::slot_GewuerzMengeValueChanged(double val)
{

}


void KWH::on_pushButton_Rezept_PDF_clicked() {

	// Rezept neu erstellen
	erstelleRezeptVorschau2();

	QString rezeptname = lineEdit_Name->text();
	QString pfad = QDir::homePath();
	QString fileName = QFileDialog::getSaveFileName(this, QString::fromLatin1("PDF speichern unter"),
		pfad + "/" + rezeptname + ".pdf", "PDF (*.pdf)");
	if (!fileName.isEmpty()) {
		// pdf speichern
		webEngineView->page()->printToPdf(fileName);
		// open PDF
		QDesktopServices::openUrl(QUrl("file:///" + fileName));
	}
}


void KWH::on_pushButton_EintragNeu_Darm_clicked() {

	myNewDialog mNDlg("Neuer Eintrag", "Name :","Ø [mm] :" , "Einheit :", "Preis per Einh. :");
	QString d_name, d_einh, d_ppe, d_drm; 
	QString db_tab = "darmliste";
	QString db_cell1 = "d_art";
	QString db_cell2 = "d_durchmesser";
	QString db_cell3 = "d_einheit";
	QString db_cell4 = "d_preis_p_einh";
	QSqlQuery query;
	bool ok = false;
	bool schreibeDB = false;
	do
	{
		mNDlg.show();

		if (mNDlg.exec() == QDialog::Accepted)
		{
			d_name = mNDlg.lineEdit[0]->text();
			d_drm = mNDlg.lineEdit[1]->text();
			d_einh = mNDlg.label_einh_id->text();
			d_ppe = mNDlg.lineEdit[3]->text();
			d_ppe.replace(",", ".");
			QString sql = "SELECT Count(" + db_cell1 + ") FROM " + db_tab + " WHERE "+ db_cell1 + " = '" + d_name + "';";
			if (!query.exec(sql))
			{
			}
			query.first();
			int eCount = query.value(0).toInt();
			if (eCount != 0)
			{
				QMessageBox msgBox;
				msgBox.setWindowTitle(QString::fromLatin1("Eintrag vorhanden!"));
				msgBox.setText(QString::fromLatin1("Der Eintrag <b>") + d_name + QString::fromLatin1("</b> existiert bereits!"));
				msgBox.setIcon(QMessageBox::Information);
				msgBox.setStandardButtons(QMessageBox::Ok);
				msgBox.exec();
				ok = false;
				schreibeDB = false;
			}
			else
			{
				ok = true;
				schreibeDB = true;
			}
		}
		else
		{
			ok = true;
		}
	} while (!ok);

	if (schreibeDB)
	{
		
		QString sql = "INSERT INTO '" + db_tab + "' (" + db_cell1 + ", " + db_cell2 + ", " + db_cell3 + ", " + db_cell4 + ") ";
		sql += "VALUES('" + d_name + "', '" + d_drm + "', '" + d_einh + "', '" + d_ppe + "'); ";
		//QSqlQuery query;
		if (!query.exec(sql))
		{
		}
		ladeZutatenlisten();
	}

}

void KWH::on_pushButton_EintragDel_Darm_clicked() {

	QMessageBox msgBox;
	QSqlQuery query;

	if (tableWidget_Zutaten_Darm->currentRow() == -1)
	{
		QString _sText = QString::fromLatin1("Es wurde keine Zeile zum löschen markiert!");
		msgBox.setWindowTitle("Keine Zeile markiert");
		msgBox.setText(_sText);
		msgBox.setIcon(QMessageBox::Information);
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.exec();
		return;
	}

	QString db_tab = "darmliste";
	QString db_cell = "r_darm";
	QString id = tableWidget_Zutaten_Darm->item(tableWidget_Zutaten_Darm->currentRow(), 0)->text();
	QString name = tableWidget_Zutaten_Darm->item(tableWidget_Zutaten_Darm->currentRow(), 1)->text();

	//Überprüfen ob zu löschender Darm in Rezepten verwendet wird
	QString cnt_tab = "rezeptliste";
	QString cnt_cell = "r_darm";
	QString sql = "SELECT Count("+cnt_cell+") FROM " +cnt_tab+ " WHERE "+cnt_cell+" = '"+id+"';";
	if (!query.exec(sql))
	{
	}
	query.first();
	int eCount = query.value(0).toInt();
	if (eCount != 0)
	{
		msgBox.setWindowTitle(QString::fromLatin1("In Rezepten gefunden"));
		QString msgtxt = QString::fromLatin1("Der Darm <br><b>") + name;
		msgtxt += QString::fromLatin1("</b><br> ist in <b>") + QString::number(eCount);
		msgtxt += QString::fromLatin1("</b> Rezept(en) vorhanden<br><br>");
		msgtxt += QString::fromLatin1("<b>Löschen nicht möglich!!</b>");
		msgBox.setText(msgtxt);
		msgBox.setIcon(QMessageBox::Critical);
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.exec();
		return;
	}

	sql = "DELETE FROM " + db_tab + " WHERE ID = " + id + ";";
	msgBox.setWindowTitle(QString::fromLatin1("Darm löschen?"));
	msgBox.setText(QString::fromLatin1("Den Eintrag<b> ") + name + QString::fromLatin1(" </b>löschen?"));
	msgBox.setIcon(QMessageBox::Information);
	msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	int ret = msgBox.exec();

	if (ret == QMessageBox::Ok)
	{
		if (!query.exec(sql))
		{
		}
		ladeZutatenlisten();
	}

}

void KWH::on_pushButton_EintragNeu_Gewuerze_clicked() {

	myNewDialog mNDlg("Neuer Eintrag", QString::fromLatin1("Gewürz-Name :"), "Einheit :", "Preis per Einh. :");
	QString g_name, g_einh, g_ppe;
	QString db_tab = "zutatenliste_gewuerze";
	QString db_cell1 = "zlg_name";
	QString db_cell2 = "zlg_einheit";
	QString db_cell3 = "zlg_preis_p_einh";
	QString sql;
	QSqlQuery query;
	bool ok = false;
	do
	{
		mNDlg.show();

		if (mNDlg.exec() == QDialog::Accepted)
		{
			g_name = mNDlg.lineEdit[0]->text();
			g_einh = mNDlg.label_einh_id->text();
			g_ppe = mNDlg.lineEdit[2]->text();
			g_ppe.replace(",", ".");
			sql = "SELECT Count(" + db_cell1 + ") FROM " + db_tab + " WHERE " + db_cell1 + " = '" + g_name + "';";
			if (!query.exec(sql))
			{
			}
			query.first();
			int eCount = query.value(0).toInt();
			if (eCount != 0)
			{
				QMessageBox msgBox;
				msgBox.setWindowTitle(QString::fromLatin1("Eintrag vorhanden!"));
				msgBox.setText(QString::fromLatin1("Der Eintrag <b>") + g_name + QString::fromLatin1("</b> existiert bereits!"));
				msgBox.setIcon(QMessageBox::Information);
				msgBox.setStandardButtons(QMessageBox::Ok);
				msgBox.exec();
				return;
			}
			else
			{
				sql = "INSERT INTO '" + db_tab + "' (" + db_cell1 + ", " + db_cell2 + ", " + db_cell3 + ") ";
				sql += "VALUES('" + g_name + "', '" + g_einh + "', '" + g_ppe + "'); ";
				//QSqlQuery query;
				if (!query.exec(sql))
				{
				}
				ladeZutatenlisten();
				return;
			}
		}
		else
		{
			ok = true;
		}
	} while (!ok);

}

void KWH::on_pushButton_EintragDel_Gewuerze_clicked() {

	QMessageBox msgBox;
	QSqlQuery query;

	if (tableWidget_Zutaten_Gewuerze->currentRow() == -1)
	{
		msgBox.setWindowTitle(QString::fromLatin1("Keine Zeile markiert"));
		msgBox.setText(QString::fromLatin1("Es wurde keine Zeile zum löschen markiert!"));
		msgBox.setIcon(QMessageBox::Information);
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.exec();
		return;
	}

	QString db_tab = "zutatenliste_gewuerze";
	QString db_cell = "zlg_name";
	QString id = tableWidget_Zutaten_Gewuerze->item(tableWidget_Zutaten_Gewuerze->currentRow(), 0)->text();
	QString name = tableWidget_Zutaten_Gewuerze->item(tableWidget_Zutaten_Gewuerze->currentRow(), 1)->text();

	//Überprüfen ob zu löschendes Gewürz in Rezepten verwendet wird
	QString cnt_tab = "rezept_pos_gewuerze";
	QString cnt_cell = "rpg_zutat";
	QString sql = "SELECT Count(" + cnt_cell + ") FROM " + cnt_tab + " WHERE " + cnt_cell + " = '" + id + "';";
	if (!query.exec(sql))
	{
	}
	query.first();
	int eCount = query.value(0).toInt();
	if (eCount != 0)
	{
		msgBox.setWindowTitle(QString::fromLatin1("In Rezepten gefunden"));
		QString msgtxt = QString::fromLatin1("Das Gewürz <br><b>") + name;
		msgtxt += QString::fromLatin1("</b><br> ist in <b>") + QString::number(eCount);
		msgtxt += QString::fromLatin1("</b> Rezept(en) vorhanden<br><br>");
		msgtxt += QString::fromLatin1("<b>Löschen nicht möglich!!</b>");
		msgBox.setText(msgtxt);
		msgBox.setIcon(QMessageBox::Critical);
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.exec();
		return;
	}

	sql = "DELETE FROM " + db_tab + " WHERE ID = " + id + ";";
	msgBox.setWindowTitle(QString::fromLatin1("Gewürz Löschen?"));
	msgBox.setText(QString::fromLatin1("Der Eintrag<b> ") + name + QString::fromLatin1(" </b>löschen?"));
	msgBox.setIcon(QMessageBox::Information);
	msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	int ret = msgBox.exec();

	if (ret == QMessageBox::Ok)
	{
		if (!query.exec(sql))
		{
		}
		ladeZutatenlisten();
	}


}

void KWH::on_pushButton_EintragNeu_Fleisch_clicked() {

	myNewDialog mNDlg("Neuer Eintrag", "Fleischart :", "Fettanteil %: ", "Verschnitt %: ", "Einheit :", "Preis per Einh. :");
	QString f_name, f_fettant, f_verschn, f_einh, f_ppe;
	QString db_tab = "zutatenliste_fleisch";
	QString db_cell1 = "zlf_name";
	QString db_cell2 = "zlf_fettanteil";
	QString db_cell3 = "zlf_verschnitt";
	QString db_cell4 = "zlf_einheit";
	QString db_cell5 = "zlf_preis_p_einh";
	QString sql;
	QSqlQuery query;
	bool ok = false;
	do
	{
		mNDlg.show();

		if (mNDlg.exec() == QDialog::Accepted)
		{
			f_name = mNDlg.lineEdit[0]->text();
			f_fettant = mNDlg.lineEdit[1]->text();
			f_verschn = mNDlg.lineEdit[2]->text();
			f_einh = mNDlg.label_einh_id->text();
			f_ppe = mNDlg.lineEdit[4]->text();
			f_ppe.replace(",", ".");
			sql = "SELECT Count(" + db_cell1 + ") FROM " + db_tab + " WHERE " + db_cell1 + " = '" + f_name + "';";
			if (!query.exec(sql))
			{
			}
			query.first();
			int eCount = query.value(0).toInt();
			if (eCount != 0)
			{
				QMessageBox msgBox;
				msgBox.setWindowTitle(QString::fromLatin1("Eintrag vorhanden!"));
				msgBox.setText(QString::fromLatin1("Der Eintrag <b>") + f_name + QString::fromLatin1("</b> existiert bereits!"));
				msgBox.setIcon(QMessageBox::Information);
				msgBox.setStandardButtons(QMessageBox::Ok);
				msgBox.exec();
				return;
			}
			else
			{
				sql = "INSERT INTO '" + db_tab + "' (" + db_cell1 + ", " + db_cell2 + ", " + db_cell3 + ", " + db_cell4 + ", " + db_cell5 + ") ";
				sql += "VALUES('" + f_name + "', '" + f_fettant + "', '" + f_verschn + "', '" + f_einh + "', '" + f_ppe + "'); ";
				//QSqlQuery query;
				if (!query.exec(sql))
				{
					ErrorMessage *errorMessage = new ErrorMessage();
					errorMessage->showMessage(ERR_SQL_DB_ABFRAGE, TYPE_WARNUNG,
						CANCEL_NO, QString::fromLatin1("Rückgabe:\n") + query.lastError().databaseText()
						+ QString::fromLatin1("\nSQL-Befehl:\n") + sql);
				}
				ladeZutatenlisten();
				return;
			}
		}
		else
		{
			ok = true;
		}
	} while (!ok);

}

void KWH::on_pushButton_EintragDel_Fleisch_clicked() {

	QMessageBox msgBox;
	QSqlQuery query;

	if (tableWidget_Zutaten_Fleisch->currentRow() == -1)
	{
		msgBox.setWindowTitle(QString::fromLatin1("Keine Zeile markiert"));
		msgBox.setText(QString::fromLatin1("Es wurde keine Zeile zum löschen markiert!"));
		msgBox.setIcon(QMessageBox::Information);
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.exec();
		return;
	}

	QString db_tab = "zutatenliste_fleisch";
	QString db_cell = "zlf_name";
	QString id = tableWidget_Zutaten_Fleisch->item(tableWidget_Zutaten_Fleisch->currentRow(), 0)->text();
	QString name = tableWidget_Zutaten_Fleisch->item(tableWidget_Zutaten_Fleisch->currentRow(), 1)->text();

	//Überprüfen ob zu löschendes Gewürz in Rezepten verwendet wird
	QString cnt_tab = "rezept_pos_fleisch";
	QString cnt_cell = "rpf_zutat";
	QString sql = "SELECT Count(" + cnt_cell + ") FROM " + cnt_tab + " WHERE " + cnt_cell + " = '" + id + "';";
	if (!query.exec(sql))
	{
	}
	query.first();
	int eCount = query.value(0).toInt();
	if (eCount != 0)
	{
		msgBox.setWindowTitle(QString::fromLatin1("In Rezepten gefunden"));
		QString msgtxt = QString::fromLatin1("Das Fleisch <br><b>") + name;
		msgtxt += QString::fromLatin1("</b><br> ist in <b>") + QString::number(eCount);
		msgtxt += QString::fromLatin1("</b> Rezept(en) vorhanden<br><br>");
		msgtxt += QString::fromLatin1("<b>Löschen nicht möglich!!</b>");
		msgBox.setText(msgtxt);
		msgBox.setIcon(QMessageBox::Critical);
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.exec();
		return;
	}

	sql = "DELETE FROM " + db_tab + " WHERE ID = " + id + ";";
	msgBox.setWindowTitle(QString::fromLatin1("Fleisch löschen?"));
	msgBox.setText(QString::fromLatin1("Der Eintrag<b> ") + name + QString::fromLatin1(" </b>löschen?"));
	msgBox.setIcon(QMessageBox::Information);
	msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	int ret = msgBox.exec();

	if (ret == QMessageBox::Ok)
	{
		if (!query.exec(sql))
		{
		}
		ladeZutatenlisten();
	}


}

void KWH::on_pushButton_EintragKopie_Fleisch_clicked() {

	//myNewDialog mNDlg("Name :", "Einheit :", "Preis per Einh. :");

	//bool ok = false;
	//do
	//{
	//	mNDlg.show();

	//	if (mNDlg.exec() == QDialog::Accepted)
	//	{
	//		ok = true;
	//	}
	//	else
	//	{
	//		ok = true;
	//	}

	//} while (!ok);


}

void KWH::changeEintragFleisch(int row, int col)
{

	QString id = tableWidget_Zutaten_Fleisch->item(row, 0)->text();

	myNewDialog mNDlg(QString::fromLatin1("Eintrag ändern"), "Fleischart :", "Fettanteil %: ", "Verschnitt %: ", "Preis per Einh. :");
	mNDlg.lineEdit[0]->setText(tableWidget_Zutaten_Fleisch->item(row, 1)->text());
	mNDlg.lineEdit[1]->setText(tableWidget_Zutaten_Fleisch->item(row, 2)->text());
	mNDlg.lineEdit[2]->setText(tableWidget_Zutaten_Fleisch->item(row, 3)->text());
	mNDlg.lineEdit[3]->setText(tableWidget_Zutaten_Fleisch->item(row, 5)->text());
	mNDlg.lineEdit[0]->setDisabled(true);

	QString upd1, upd2, upd3, upd4;
	QString db_tab = "zutatenliste_fleisch";
	QString db_col1 = "zlf_fettanteil";
	QString db_col2 = "zlf_verschnitt";
	QString db_col3 = "zlf_preis_p_einh";
	//QString db_col4 = "";
	//QString db_col5 = "";
	QString sql;
	QSqlQuery query;
	bool ok = false;
	do
	{
		mNDlg.show();

		if (mNDlg.exec() == QDialog::Accepted)
		{
			upd1 = mNDlg.lineEdit[1]->text();
			upd2 = mNDlg.lineEdit[2]->text();
			upd3 = mNDlg.lineEdit[3]->text();
			upd3.replace(",", ".");

			/*UPDATE table_name
				SET column1 = value1, column2 = value2, ...
				WHERE condition;*/

			sql = "UPDATE " + db_tab + " ";
			sql += "SET " + db_col1 + " = '" + upd1 + "', " + db_col2 + " = '" + upd2 + "', " + db_col3 + " = '" + upd3 + "' "; 
			sql += "WHERE ID = " + id + ";";
			//QSqlQuery query;
			if (!query.exec(sql))
			{
				ErrorMessage *errorMessage = new ErrorMessage();
				errorMessage->showMessage(ERR_SQL_DB_ABFRAGE, TYPE_WARNUNG,
					CANCEL_NO, QString::fromLatin1("Rückgabe:\n") + query.lastError().databaseText()
					+ QString::fromLatin1("\nSQL-Befehl:\n") + sql);
			}
			ladeZutatenlisten();
			return;
		}
		else
		{
			ok = true;
		}
	} while (!ok);

}

void KWH::changeEintragGewuerz(int row, int col) 
{
	QString id = tableWidget_Zutaten_Gewuerze->item(row, 0)->text();

	myNewDialog mNDlg(QString::fromLatin1("Eintrag ändern"), QString::fromLatin1("Gewürz :"), "Preis per Einh. :");
	mNDlg.lineEdit[0]->setText(tableWidget_Zutaten_Gewuerze->item(row, 1)->text());
	mNDlg.lineEdit[1]->setText(tableWidget_Zutaten_Gewuerze->item(row, 3)->text());
	mNDlg.lineEdit[0]->setDisabled(true);

	QString upd1;
	QString db_tab = "zutatenliste_gewuerze";
	QString db_col1 = "zlg_preis_p_einh";
	QString sql;
	QSqlQuery query;
	bool ok = false;
	do
	{
		mNDlg.show();

		if (mNDlg.exec() == QDialog::Accepted)
		{
			upd1 = mNDlg.lineEdit[1]->text();
			upd1.replace(",", ".");

			/*UPDATE table_name
				SET column1 = value1, column2 = value2, ...
				WHERE condition;*/

			sql = "UPDATE " + db_tab + " ";
			sql += "SET " + db_col1 + " = '" + upd1 + "' ";
			sql += "WHERE ID = " + id + ";";
			//QSqlQuery query;
			if (!query.exec(sql))
			{
				ErrorMessage *errorMessage = new ErrorMessage();
				errorMessage->showMessage(ERR_SQL_DB_ABFRAGE, TYPE_WARNUNG,
					CANCEL_NO, QString::fromLatin1("Rückgabe:\n") + query.lastError().databaseText()
					+ QString::fromLatin1("\nSQL-Befehl:\n") + sql);
			}
			ladeZutatenlisten();
			return;
		}
		else
		{
			ok = true;
		}
	} while (!ok);

}

void KWH::changeEintragDarm(int row, int col)
{
	QString id = tableWidget_Zutaten_Darm->item(row, 0)->text();

	myNewDialog mNDlg(QString::fromLatin1("Eintrag ändern"), "Darmart :", "Drm [mm]:" ,"Preis per Einh. :");
	mNDlg.lineEdit[0]->setText(tableWidget_Zutaten_Darm->item(row, 1)->text());
	mNDlg.lineEdit[1]->setText(tableWidget_Zutaten_Darm->item(row, 2)->text());
	mNDlg.lineEdit[2]->setText(tableWidget_Zutaten_Darm->item(row, 4)->text());
	mNDlg.lineEdit[0]->setDisabled(true);

	QString upd1, upd2;
	QString db_tab = "darmliste";
	QString db_col1 = "d_durchmesser";
	QString db_col2 = "d_preis_p_einh";
	QString sql;
	QSqlQuery query;
	bool ok = false;
	do
	{
		mNDlg.show();

		if (mNDlg.exec() == QDialog::Accepted)
		{
			upd1 = mNDlg.lineEdit[1]->text();
			upd2 = mNDlg.lineEdit[2]->text();
			upd2.replace(",", ".");

			/*UPDATE table_name
				SET column1 = value1, column2 = value2, ...
				WHERE condition;*/

			sql = "UPDATE " + db_tab + " ";
			sql += "SET " + db_col1 + " = '" + upd1 + "', " + db_col2 + " = '" + upd2 + "' ";
			sql += "WHERE ID = " + id + ";";

			if (!query.exec(sql))
			{
				ErrorMessage *errorMessage = new ErrorMessage();
				errorMessage->showMessage(ERR_SQL_DB_ABFRAGE, TYPE_WARNUNG,
					CANCEL_NO, QString::fromLatin1("Rückgabe:\n") + query.lastError().databaseText()
					+ QString::fromLatin1("\nSQL-Befehl:\n") + sql);
			}
			ladeZutatenlisten();
			return;
		}
		else
		{
			ok = true;
		}
	} while (!ok);

}

void KWH::erstelleAktionen()
{
	// Aktion exit in Menue Datei
	//ActExit = new QAction("Exit", this);
	//ActExit->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Q));
	////connect(ActExit, SIGNAL(triggered()), this, SLOT(close()));
	//connect(ActExit, &QAction::triggered, qApp, QApplication::quit);

	//// Aktion einstellungen in Menü Extras
	//ActEinstellungen = new QAction("", this);
	//ActEinstellungen->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_O));
	////connect(ActEinstellungen, SIGNAL(triggered()), this, SLOT(slot_einstellungen()));
	//connect(ActEinstellungen, &QAction::triggered, this, &KWH::oeffneEinstellungen);

}

void KWH::erstelleMenue()
{
	//// Menü Datei

	//MenueDatei = menuBar()->addMenu("Datei");
	//MenueDatei->addAction(ActExit);
	//MenueDatei->addSeparator();
	
}

void KWH::oeffneEinstellungen()
{

	QMessageBox::information(this,"Test","slot öffne Einstellungen");

}