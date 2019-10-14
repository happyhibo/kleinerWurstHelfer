
#ifndef KWH_H
#define KWH_H

#include <qwidget.h>
#include <qmainwindow.h>
#include "ui_kwh.h"
#include "definitionen.h"
#include "errormessage.h"
#include <qsqltablemodel.h>
#include "berechnungen.h"
#include "myqspinbox.h"
#include "myqdoublespinbox.h"
#include <qicon.h>
#include "mynewdialog.h"
#include "ui_mynewdialog.h"
#include "ui_kwh.h"
#include <qsqlquery.h>
#include <qsqlerror.h>
#include <qsqlrecord.h>
#include <qmessagebox.h>
#include <qdatetime.h>
#include <qmetaobject.h>
#include <qspinbox.h>
#include <qsqlquerymodel.h>
#include "myqcombobox.h"
#include <qtabwidget.h>
#include <qtablewidget.h>
#include <qfiledialog.h>
#include <qdiriterator.h>
#include <qurl.h>
#include <qdesktopservices.h>
#include <qprinter.h>
#include <qmenu.h>
#include <qmenubar.h>
#include <qaction.h>
#include "dlgeinstellungen.h"
#include "settings.h"

class KWH : public QMainWindow, public Ui::KWHClass
{
	Q_OBJECT

public:
	KWH(QWidget* parent = 0);
	~KWH();
	Settings settings;
	


private:
	Ui::KWHClass ui;
	void leseSettings();
	void schreibeSettings();
	void initUi();
	void fuelleRezeptauswahl();
	void NeueZeileFleisch(int id, int menge_prozent, int verarbeitung);
	void NeueZeileGewuerze(int id, double menge_einh, int verarbeitung);
	void ladeRezeptDetails();
	void clearRezeptDetails();
	void ladeRezeptberechnet();
	void ladeZutatenlisten();
	void schreibeRezeptPosFleisch(QString aktID);
	void schreibeRezeptPosGewuerze(QString aktID);
	void schreibeRezeptPosZubereitung(QString aktID);
	void erstelleRezeptVorschau2();
	void erstelleAktionen();
	void erstelleMenue();
	Qberechnungen Berechnung;
	QIcon kwh_icon;
	//QMenu *MenueDatei;
	//QMenu *MenueExtras;
	//QAction *ActExit;
	//QAction *ActEinstellungen;


private slots:
	
	void on_tableWidget_Rezeptauswahl_itemSelectionChanged();
	void on_tableWidget_Rezeptauswahl_cellDoubleClicked(int, int);
	void on_tableWidget_Fleisch_cellClicked(int row, int col);
	void on_tableWidget_Gewuerze_cellClicked(int row, int col);

	void on_pushButton_Rezept_speichern_clicked();
	void on_pushButton_Rezept_PDF_clicked();
	void on_pushButton_Clear_clicked();
	void on_pushButton_EintragNeu_Einheiten_clicked();
	void on_pushButton_EintragDel_Einheiten_clicked();
	void on_pushButton_EintragNeu_Verarbeitung_clicked();
	void on_pushButton_EintragDel_Verarbeitung_clicked();
	void on_pushButton_EintragNeu_Wurstart_clicked();
	void on_pushButton_EintragDel_Wurstart_clicked();
	void on_pushButton_EintragNeu_Darm_clicked();
	void on_pushButton_EintragDel_Darm_clicked();
	void on_pushButton_EintragNeu_Gewuerze_clicked();
	void on_pushButton_EintragDel_Gewuerze_clicked();
	void on_pushButton_EintragNeu_Fleisch_clicked();
	void on_pushButton_EintragDel_Fleisch_clicked();
	void on_pushButton_EintragKopie_Fleisch_clicked();

	void changeEintragFleisch(int row, int col);
	void changeEintragGewuerz(int row, int col);
	void changeEintragDarm(int row, int col);

	void oeffneEinstellungen();

	void slot_itemchanged();
	void slot_pushButton_Rezept_anlegen_clicked();
	void slot_pushButton_Rezept_kopieren_clicked();
	void slot_pushButton_Rezept_loeschen_clicked();
	void slot_FleischMengeValueChanged(double val);
	void slot_GewuerzMengeValueChanged(double val);
	void slot_FleischZutatChanged(int index);
	void slot_GewuerzZutatChanged(int index);
	void slot_FleischVerarbeitungChanged(int index);
	void slot_GewuerzVerarbeitungChanged(int index);
	void slot_WurstartChanged(int index);
	void slot_HuelleChanged(int index);
	


};
#endif // !KWH_H