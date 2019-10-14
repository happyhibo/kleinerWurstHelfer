#include "dlgeinstellungen.h"


dlgEinstellungen::dlgEinstellungen(QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);
	setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
	groupBox_DB->setTitle("Pfad zur Datendank : " + QString(DB_NAME));

	QListWidgetItem *DBBtn = new QListWidgetItem(QIcon(":/KWH/Resources/database.png"), "Datenbank");
	//DBBtn->setIcon(QIcon(":/KWH/Resources/database.png"));
	//DBBtn->setSizeHint(QSize(80, 80));
	listWidget_Einstellungen->addItem(DBBtn);
	DBBtn->setTextAlignment(Qt::AlignHCenter | Qt::AlignBottom);
	DBBtn->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

	QListWidgetItem *BerBtn = new QListWidgetItem(QIcon(":/KWH/Resources/calculus.png"), "Berechnung");
	//BerBtn->setIcon(QIcon(":/KWH/Resources/database.png"));
	//BerBtn->setSizeHint(QSize(96, 84));
	listWidget_Einstellungen->addItem(BerBtn);
	BerBtn->setTextAlignment(Qt::AlignHCenter);
	BerBtn->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
	

	connect(listWidget_Einstellungen, &QListWidget::currentItemChanged, this, &dlgEinstellungen::Seitenwechsel);
	connect(pushButton_Ok, &QPushButton::clicked, this, &dlgEinstellungen::accepted);
	connect(pushButton_Cnl, &QPushButton::clicked, this, &dlgEinstellungen::reject);

	leseSettingDB();
	
}

dlgEinstellungen::~dlgEinstellungen()
{
}


void dlgEinstellungen::Seitenwechsel(QListWidgetItem *current, QListWidgetItem *previous)
{
	if (!current)
		current = previous;

	stackedWidget->setCurrentIndex(listWidget_Einstellungen->row(current));

}

void dlgEinstellungen::leseSettingDB()
{
	//QSettings settings(QSettings::IniFormat, QSettings::UserScope, APP_KURZNAME, APP_NAME);

	//settings->beginGroup("DB");
	//QString dbPfadini = settings->value("DB_Pfad").toString();
	//settings->endGroup();
	QString dbPfadini = settings.getDatabasePath();

	lineEdit_DBPath->setText(dbPfadini);

}

void dlgEinstellungen::schreibeSettingDB()
{

	//QSettings settings(QSettings::IniFormat, QSettings::UserScope, APP_KURZNAME, APP_NAME);
#ifdef DEBUG
	settings.beginGroup("DEBUG_DB");
#else
	settings.beginGroup("DB");
#endif // DEBUG

	if (CopyDB) 
	{
		bool b = true;
		//Abfrage ob Datenbank zu dem Neuen Pfad verschoben werden soll
		QMessageBox::StandardButton reply;
		reply = QMessageBox::question(this, QString::fromLatin1("Datenbank verschieben?"),
			QString::fromLatin1("Der Datenbankpfad wurde geändert!\nSoll die Datenbank an den neuen Ort kopiert werden?\n\nDas Programm wird nach dem Kopieren beendet und muss neu gestartet werden."),
			QMessageBox::Yes | QMessageBox::No);
		if (reply == QMessageBox::Yes) 
		{
			//Datenbank wird an den Neuen Ort verschoben
			QFile file(DBPfadAlt + "/" + DB_NAME);
			if (!file.copy(lineEdit_DBPath->text() + "/" + DB_NAME)) {
				CopyDB = false;
				b = false;
				// Fehlermeldung Kann Datenbankdatei nicht kopieren
				ErrorMessage *errorMessage = new ErrorMessage();
				errorMessage->showMessage(ERR_DB_KOPIE_NEU_ORT, TYPE_WARNUNG,
					CANCEL_NO, QString::fromLatin1("Betroffene Datei:\n") + file.fileName());
			}
		}

		if (b) 
		{
			//Neuen Pfad Speichern
#ifdef DEBUG
			settings.setValue("DEBUG_DB_Pfad", lineEdit_DBPath->text());
#else
			settings.setValue("DB_Pfad", lineEdit_DBPath->text());
#endif // DEBUG

			
		}
	}
	settings.endGroup();

}


void dlgEinstellungen::on_pushButton_getPath_clicked()
{
	DBPfadAlt = lineEdit_DBPath->text();
	//QFileDialog::Options options = QFileDialog::DontResolveSymlinks | QFileDialog::ShowDirsOnly | QFileDialog::DontUseNativeDialog;
	QFileDialog::Options options = QFileDialog::DontResolveSymlinks | QFileDialog::ShowDirsOnly;
	QString directory = QFileDialog::getExistingDirectory(this,
		QString::fromLatin1("Datenbankpfad Auswählen"),
		lineEdit_DBPath->text(),
		options);

	if (!directory.isEmpty()) {
		lineEdit_DBPath->setText(directory);
		if (DBPfadAlt != directory) {
			CopyDB = true;
		}
		else
		{
			CopyDB = false;
		}
	}
	else
	{
		CopyDB = false;
	}

}


void dlgEinstellungen::accepted() {

	schreibeSettingDB();
	accept();

}