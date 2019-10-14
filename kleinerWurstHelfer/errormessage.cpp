
#include <QMessageBox>

#include "errormessage.h"
#include "definitionen.h"

ErrorMessage::ErrorMessage(QWidget *parent) : QWidget(parent) {
}

void ErrorMessage::showMessage(int errorNo, int errorType, int cancelProcedure,
	QString addon) {
	QString message;
	// Fehlertext
	message = getErrorText(errorNo);
	// wenn Text noch angehängt werden soll
	if (addon != "") {
		message.append("\n" + addon);
	}

	// Abbruchtext
	message.append("\n\n" + getCancelText(cancelProcedure));

	// Style
	switch (errorType) {
		case TYPE_INFO:
			QMessageBox::information(0, APP_NAME, message);
			break;
		case TYPE_WARNUNG:
			QMessageBox::warning(0, APP_NAME, message);
			break;
		case TYPE_KRITISCH:
		default:
			QMessageBox::critical(0, APP_NAME, message);
			break;
	}
}

QString ErrorMessage::getCancelText(int number) {
	QString cancelText = "";
	switch (number) {
		case CANCEL_NO:
			cancelText = "";
			break;
		case CANCEL_AKTION:
			cancelText = QString::fromLatin1("Der Vorgang wird abgebrochen.");
			break;
		case CANCEL_PROGRAM:
		default:
			cancelText = QString::fromLatin1("Die Anwendung wird beendet.");
			break;
	}
	return cancelText;
}

QString ErrorMessage::getErrorText(int number) {
	QString errorText = "";
	switch (number) {
		case ERR_SQL_DB_USER_KOPIE:
			errorText = QString::fromLatin1("Vorlagendatenbank konnte nicht kopiert werden");
			break;
		case ERR_SQL_DB_VORLAGE:
			errorText = QString::fromLatin1("Vorlagendatenbank ist nicht vorhanden");
			break;
		case ERR_SQL_DB_PFAD:
			errorText = QString::fromLatin1("Es Konnte kein Pfad für die Datenbankdatei ermittelt werden");
			break;
		case ERR_SQL_DB_OPEN:
			errorText = QString::fromLatin1("Kann Datenbank nicht öffnen");
			break;
		case ERR_SQL_DB_VERSION:
			errorText = QString::fromLatin1("Kann Version der Datenbank nicht abfragen");
			break;
		case ERR_SQL_DB_ABFRAGE:
			errorText = QString::fromLatin1("Fehler bei SQL-Abfrage");
			break;
		case ERR_SQL_DB_CREATE:
			errorText = QString::fromLatin1("Konnte Tabelle nicht erstellen");
			break;
		case ERR_DEBUG_INFO:
			errorText = QString::fromLatin1("INFO");
			break;
		case ERR_DB_PFAD_NIO:
			errorText = QString::fromLatin1("Kann Datenbankpfad nicht finden! Der Pfad wird auf den Standardpfad umgestellt und die Vorlagendatenbank angelegt.\nBitte den Pfad zur Datenbankdatei in den Einstellungen korrigieren.");
			break;
		case ERR_DB_KOPIE_NEU_ORT:
			errorText = QString::fromLatin1("Kann Datenbank nicht an neuen Ort kopieren. Datenbankdatei schon vorhanden?.\nDer Pfad wird nicht geändert");
			break;

		default:
			errorText = QString::fromLatin1("Ein Fehler ist aufgetreten.");
			break;
	}
	// Fehlernummer Anhängen
	errorText.append(QString::fromLatin1("\n(Fehlernummer: ") + QString::number(number) + QString::fromLatin1(")\n"));
	return errorText;
}
