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


QString sql;
QSqlQuery query;

static bool DB_verbindung() {

	//Datenbank ist vorhanden
	//bool dbVorhanden = false;
	// Pfad zur Datenbank
	QString dbPfad;
	// Dateiname Datenbankvorlage
	QString dbNameVorlage = DB_VORLAGE;
	// Dateiname der Datenbank Benutzer
	QString dbNameUser = DB_USER_NAME;
	
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

	
	int updateNr = 0;

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

	bool io = true;

	// todo: Wenn updateNr differenz größer 1 ist, update in schleife abarbeiten

	switch (updateNr)
	{
	case 0:
		if (!UpdateDB_v0_v1())
		{
			// Fehlermeldung Konnte Datenbank nicht updaten
			ErrorMessage *errorMessage = new ErrorMessage();
			errorMessage->showMessage(ERR_SQL_DB_CREATE, TYPE_KRITISCH,
				CANCEL_PROGRAM, QString::fromLatin1("Update V0 auf V1\nBetroffene Datei:\n") + dbPfad);
			return false;
		}
		io = true;
		break;

	case 1:
		if (!UpdateDB_v1_v2())
		{
			// Fehlermeldung Konnte Datenbank nicht updaten
			ErrorMessage *errorMessage = new ErrorMessage();
			errorMessage->showMessage(ERR_SQL_DB_CREATE, TYPE_KRITISCH,
				CANCEL_PROGRAM, QString::fromLatin1("Update V1 auf V2\nBetroffene Datei:\n") + dbPfad);
			return false;
		}
		io = true;
		break;

	case 2:
		break;

	default:
		io = false;
		break;
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

	return true;
}

static bool UpdateDB_v0_v1()
{
	// Daten aus SQL-Datei lesen
	QSqlDatabase::database().transaction();
	QString SQLDaten = DATEN_VORLAGE;
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
				return false;
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
		return false;
	}

	QSqlDatabase::database().commit();
	return true;
}


static bool UpdateDB_v1_v2() 
{
	QSqlDatabase::database().transaction();
	//Prüfen ob Spalte schon vorhanden
	sql = "PRAGMA table_info('darmliste')";
	bool alterTable = true;
	if (query.exec(sql)) {
		while (query.next()) {
			// der zweite Inhalt ( 1 ) ist der Spaltenname
			if (query.value(1).toString() == "d_durchmesser") {
				alterTable = false;
			}
		}
	}
	else {
		ErrorMessage *errorMessage = new ErrorMessage();
		errorMessage->showMessage(ERR_SQL_DB_ABFRAGE, TYPE_WARNUNG,
			CANCEL_NO, QObject::trUtf8("Rückgabe:\n") + query.lastError().databaseText()
			+ QObject::trUtf8("\nSQL-Befehl:\n") + sql);
		return false;
	}


	//Eintrag hinzufügen zur Berechnung der Darmlängen
	if (alterTable)
	{
		sql = "ALTER TABLE 'darmliste' ADD COLUMN 'd_durchmesser' INTEGER";
		if (!query.exec(sql)) {
			ErrorMessage *errorMessage = new ErrorMessage();
			errorMessage->showMessage(ERR_SQL_DB_ABFRAGE, TYPE_WARNUNG,
				CANCEL_NO, QObject::trUtf8("Rückgabe:\n") + query.lastError().databaseText()
				+ QObject::trUtf8("\nSQL-Befehl:\n") + sql);
			return false;
		}
	}
	
	//Versionsstand auf 2 setzen
	sql = "UPDATE 'version' SET 'db_version'=2";
	if (!query.exec(sql))
	{
		ErrorMessage *errorMessage = new ErrorMessage();
		errorMessage->showMessage(ERR_SQL_DB_ABFRAGE, TYPE_WARNUNG,
			CANCEL_NO, QString::fromLatin1("Rückgabe:\n") + query.lastError().databaseText()
			+ QString::fromLatin1("\nSQL-Befehl:\n") + sql);
		return false;
	}

	QSqlDatabase::database().commit();
	return true;
}


#endif // !CONNECTION_H
