#ifndef CONNECT_H
#define CONNECT_H
	
#include <qapplication.h>
#include <qsqldatabase.h>
#include <QtSql/qtsqlglobal.h>
#include <qfile.h>
#include <qstring.h>
#include <qmessagebox.h>
#include <qsqlerror.h>
#include <qsqlrecord.h>
#include <qsqlquery.h>
#include <qdir.h>
#include <qdatetime.h>

#include "definitionen.h"
#include "errormessage.h"

static bool DB_verbindung() {

	//Datenbank ist vorhanden
	//bool dbVorhanden = false;
	// Pfad zur Datenbank
	QString dbPfad;
	// Dateiname Datenbankvorlage
	QString dbNameVorlage = DB_VORLAGE;
	QString SQLDaten = DATEN_VORLAGE;
	// Dateiname der Datenbank Benutzer
	QString dbNameUser = DB_USER_NAME;
	// SQL String erstellen
	QString sql;

	// Verbindung zu SQLite
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

	QApplication::addLibraryPath("./");

	//dbPfad = QDir::homePath() + "/" + dbNameUser;;
	dbPfad = QDir::currentPath() + "/" + dbNameUser;

	if (dbPfad != "") 
	{
		//Überprüfen ob Datenbankdatei existiert
		if (!QFile::exists(dbPfad)) 
		{
			// Vorlage wird Kopiert wenn vorhanden
			if (QFile::exists(dbNameVorlage)) {
				//Datenbank wird kopiert
				QFile file(dbNameVorlage);
				if (file.copy(dbPfad)) {
					QFile::setPermissions(dbPfad, QFile::ReadOwner | QFile::WriteOwner);
				}
				else {
					ErrorMessage *errorMessage = new ErrorMessage();
					errorMessage->showMessage(ERR_SQL_DB_USER_KOPIE, TYPE_KRITISCH,
						CANCEL_PROGRAM, QString::fromLatin1("Betroffener Kopierpfad:\n") + dbPfad);
					return false;
				}
			}
			else {
				// Fehlermeldung keine Datenbankvorlage gefunden
				ErrorMessage *errorMessage = new ErrorMessage();
				errorMessage->showMessage(ERR_SQL_DB_VORLAGE, TYPE_KRITISCH,
					CANCEL_PROGRAM, QString::fromLatin1("Betroffene Datei:\n") + dbNameVorlage);
				return false;
			}
		}
	}
	// Setzte Datenbank
	db.setDatabaseName(dbPfad);
	//db.setConnectOptions("ISC_DPB_LC_CTYPE=Latin1");
	// Datenbank öffnen
	if (!db.open()) {
		// Fehlermeldung
		ErrorMessage *errorMessage = new ErrorMessage();
		errorMessage->showMessage(ERR_SQL_DB_OPEN, TYPE_KRITISCH,
			CANCEL_PROGRAM, QString::fromLatin1("Betroffene Datei:\n") + dbPfad);
		return false;
	}

	QSqlQuery query;

	int updateNr = 0;
	QString updatestr;

	//Überprüfung Versionstand Datenbank
	if (!query.exec("SELECT db_version FROM version;")) {
		ErrorMessage *errorMessage = new ErrorMessage();
		errorMessage->showMessage(ERR_SQL_DB_VERSION, TYPE_KRITISCH,
			CANCEL_PROGRAM, QString::fromLatin1("Betroffene Datei:\n") + dbPfad);
		return false;
	}
	else {
		if (!query.first()) {
			// Fehlermeldung Kann Versionstand der Datenbank nicht abfragen
			ErrorMessage *errorMessage = new ErrorMessage();
			errorMessage->showMessage(ERR_SQL_DB_VERSION, TYPE_KRITISCH,
				CANCEL_PROGRAM, QString::fromLatin1("Betroffene Datei:\n") + dbPfad);
			return false;
		}
		else 
		{
			updateNr = query.value(0).toInt();
		}
	}

	if (updateNr == 0)
	{
		bool io = true;
		QSqlDatabase::database().transaction();

		QFile schemaFile(SQLDaten);
		schemaFile.open(QFile::ReadOnly);
		QStringList schemaTableList = QString(schemaFile.readAll()).split(";");
		foreach(const QString schemaTable, schemaTableList)
		{
			QString req = schemaTable;
			if (!schemaTable.trimmed().isEmpty())
			{
				if (!query.exec(schemaTable))
				{
					ErrorMessage *errorMessage = new ErrorMessage();
					errorMessage->showMessage(ERR_SQL_DB_ABFRAGE, TYPE_WARNUNG,
						CANCEL_NO, QString::fromLatin1("Rückgabe:\n") + query.lastError().databaseText()
						+ QString::fromLatin1("\nSQL-Befehl:\n") + req);
				}
			}
		}
		schemaFile.close();

		//Versionsstand auf 1 setzen
		sql = "UPDATE 'version' SET 'db_version'=1";
		if (!query.exec(sql)) 
		{
			ErrorMessage *errorMessage = new ErrorMessage();
			errorMessage->showMessage(ERR_SQL_DB_ABFRAGE, TYPE_WARNUNG,
				CANCEL_NO, QString::fromLatin1("Rückgabe:\n") + query.lastError().databaseText()
				+ QString::fromLatin1("\nSQL-Befehl:\n") + sql);
			io = false;
		}
		else
		{
			updateNr = 1;
		}

		if (!io) 
		{
			// Fehlermeldung Konnte Datenbank nicht updaten
			ErrorMessage *errorMessage = new ErrorMessage();
			errorMessage->showMessage(ERR_SQL_DB_CREATE, TYPE_KRITISCH,
				CANCEL_PROGRAM, QString::fromLatin1("Betroffene Datei:\n") + dbPfad);
			return false;
		}
		QSqlDatabase::database().commit();

	}

	return true;

}







#endif // !CONNECTION_H
