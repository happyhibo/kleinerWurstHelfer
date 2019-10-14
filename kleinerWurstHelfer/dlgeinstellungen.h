#ifndef DLGEINSTELLUNGEN_H
#define DLGEINSTELLUNGEN_H


#include <qdialog.h>
#include "ui_dlgeinstellungen.h"
#include "definitionen.h"
#include "errormessage.h"
#include <qfiledialog.h>
#include "settings.h"
#include <qmessagebox.h>
#include <qdir.h>

class dlgEinstellungen : public QDialog, public Ui::dlgEinstellungen
{
	Q_OBJECT

public:
	dlgEinstellungen(QWidget *parent = Q_NULLPTR);
	~dlgEinstellungen();

	Settings settings;
	

private:
	//Ui::dlgEinstellungen ui;
	void leseSettingDB();
	void schreibeSettingDB();

	QString DBPfadAlt;
	bool CopyDB;


private slots:
	void Seitenwechsel(QListWidgetItem * current, QListWidgetItem * previous);
	void on_pushButton_getPath_clicked();
	void accepted();

};

#endif // !DLGEINSTELLUNGEN_H
