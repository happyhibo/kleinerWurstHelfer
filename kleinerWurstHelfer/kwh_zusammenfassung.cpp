#include "kwh.h"
#include "ui_kwh.h"
#include <qdatetime.h>


void KWH::erstelleRezeptVorschau2()
{
	double menge_braetgewicht = double(spinBox_Verwurstung->value());

	QString seite, kopf, body, ende, style;
	double gesamtpreis, fleischpreis, gewuerzpreis, darmpreis;
	gesamtpreis = 0;
	fleischpreis = 0;
	gewuerzpreis = 0;
	darmpreis = 0;
	
	kopf = "<!DOCTYPE html PUBLIC ' -//W3C//DTD HTML 4.01//EN' 'http://www.w3.org/TR/html4/strict.dtd'>";
	style = "<style type='text/css'>";
	//Style für Div Box mit Rahmen
	style += "div.rm{border:2px solid #990000; border-radius: 10px; padding:5px; background-color:#ffffff;}";
	style += "</style>";
	kopf += "<html><head>";
	kopf += "<meta content = 'text/html; charset=ISO-8859-1' http - equiv = 'content-type'>";
	kopf += "<title>Rezeptvorschau</title>";
	kopf += style;
	kopf += "</head>";
	seite = kopf;

	body = "<body>";
	body += "<div class='rm' style='margin:10px 10px 10px 30px; width:90%;' align='left'>";
	body += "<h1 style = 'margin-left: 80px;'>Rezept: " + lineEdit_Name->text() + "<br></h1>";
	body += "</div>";
	//++++++++++++++++++++++++++++++++++++++Kopfdaten
	body += "<div class='rm' style='margin:10px 10px 10px 30px; width:90%;' align='center'>";
	body += "<table style = 'text-align: left; width: 80%; margin-left: auto; margin-right: auto;' border = '0' cellpadding = '0' cellspacing = '0'>";
	body += "<tbody>";
	body += "<tr>";
	body += "<td style = 'vertical-align: top; text-align: right;'><big>Art :</big><br></td>";
	body += "<td style = 'vertical-align: top; text-align: right;'><big>" + comboBox_Art->currentText() + "</big><br></td>";	
	body += "<td style = 'vertical-align: top;'><br></td>";
	body += "<td style = 'vertical-align: top;'><br></td>";
	body += "<td style = 'vertical-align: top;'><br></td>";
	body += "<td style = 'vertical-align: top; width: 90px;'><big>Datum :</big><br></td>";
	body += "<td style = 'vertical-align: top; width: 200px;'><big>" + QDateTime::currentDateTime().toString("dd.MM.yy"); //+ "</big><br></td>";
	body += "</tr>";
	body += "<tr>";
	body += "<td style = 'vertical-align: top; text-align: right; width: 100px;'><big>Gewicht:</big><br></td>";
	body += "<td style = 'vertical-align: top; width: 100px; text-align: right;'><big>" + QString::number(spinBox_Verwurstung->value()) + " g</big><br></td>";
	body += "<td style = 'vertical-align: top;'><br></td>";
	body += "<td style = 'vertical-align: top;'><br></td>";
	body += "<td style = 'vertical-align: top;'><br></td>";
	body += "<td style = 'vertical-align: top; width: 90px;'><big>Darm :</big><br></td>";
	body += "<td style = 'vertical-align: top; width: 200px;'><big>" + comboBox_Darm->currentText() + "</big><br></td>";
	body += "</tr>";
	body += "<tr>";
	body += "<td style = 'vertical-align: top;'><br></td>";
	body += "<td style = 'vertical-align: top;'><br></td>";
	body += "<td style = 'vertical-align: top;'><br></td>";
	body += "<td style = 'vertical-align: top;'><br></td>";
	body += "<td style = 'vertical-align: top;'><br></td>";
	body += "<td style = 'vertical-align: top;'><br></td>";
	body += "<td style = 'vertical-align: top;'><br></td>";
	body += "</tr>";
	body += "</tbody>";
	body += "</table>";

	body += "<br>";

	//++++++++++++++++++++++++++++++++++++++Verarbeitung
	body += "<h1 style = 'text-align: left; margin-left: 80px;'>Verarbeitung:<br></h1>";
	body += "<span style = 'font-family: &quot;Open Sans&quot;,Arial,sans-serif;'><span style = 'font-weight: bold;'></span></span>";
	body += "<table style = 'text-align: left; width: 80%; margin-left: auto; margin-right: auto;' border = '0' cellpadding = '0' cellspacing = '0'>";

	body += "<tbody>";
	body += "<tr>";
	body += "<td style = 'vertical-align: top;'>";
	body += "<h3 style = 'margin: 15px 0px 15px 25px; padding: 0px; font-weight: 700; text-align: left; font-size: 14px; color: rgb(0, 0, 0); font-family: &quot;Open Sans&quot;,Arial,sans-serif; font-style: normal; letter-spacing: normal; orphans: 2; text-indent: 0px; text-transform: none; white-space: normal; widows: 2; word-spacing: 0px; background-color: rgb(255, 255, 255);'>";

	//body += "<big>Überschrift Verarbeitung</big>";

	body += "</h3>";
	body += "<div style = 'margin-left: 25px;'>";

	body += "<big>";
	if (textEdit_Zubereitung->toPlainText() != "") {
		body += textEdit_Zubereitung->toHtml();
	}
	body += "</big></div>";

	//++++++++++++++++++++++++++++++++++++++Fleischanteile
	body += "<p style = 'margin: 0px 0px 15px 80px; padding: 0px; text-align: justify; color: rgb(0, 0, 0); font-family: &quot;Open Sans&quot;,Arial,sans-serif; font-size: 14px; font-style: normal; font-weight: 400; letter-spacing: normal; orphans: 2; text-indent: 0px; text-transform: none; white-space: normal; widows: 2; word-spacing: 0px; background-color: rgb(255, 255, 255);'><br></p>";
	body += "</td>";
	body += "</tr>";
	body += "</tbody>";
	body += "</table>";

	body += "<h1 style = 'text-align: left; margin-left: 80px;'>Zutaten :</h1>";
	body += "<table style = 'text-align: left; width: 80%; margin-left: auto; margin-right: auto;' border = '0' cellpadding = '0' cellspacing = '0'>";
	body += "<thead>";
	body += "<tr>";
	body += "<th style = 'vertical-align: top; text-align: right; width: 100px;'><big>g/Masse</big><br></th>";
	body += "<th style = 'vertical-align: top; width: 250px;'>";
	body += "<div style = 'margin-left: 40px;'><big>Zutat</big><br></div></th>";
	body += "<th style = 'vertical-align: top;'><big>Verarbeitung</big><br></div></th>";
	body += "</tr>";
	body += "</thead>";

	body += "<tbody>";

	//Fleischwidget auslesen
	int row = tableWidget_Fleisch->rowCount();
	//erforderliche Arrays anlegen
	QString *zutat = new QString[row];
	QString *verarb = new QString[row];

	double *menge_prozent = new double[row];
	double *menge_gewicht = new double[row];
	double *preis_pe = new double[row];

	//QString zutat[99], verarb[99];
	//double menge_prozent[99], menge_gewicht[99], preis_pe[99];

	for (int i = 0; i < row; i++)
	{
		QComboBox *comboBox_Zutat = (QComboBox *)tableWidget_Fleisch->cellWidget(i, 1);
		QDoubleSpinBox *spinBox_Menge = (QDoubleSpinBox *)tableWidget_Fleisch->cellWidget(i, 2);
		QComboBox *comboBox_Verarb = (QComboBox *)tableWidget_Fleisch->cellWidget(i, 3);
		QTableWidgetItem *PreisPE = tableWidget_Fleisch->item(i, 7);
		zutat[i] = comboBox_Zutat->currentText();
		menge_prozent[i] = spinBox_Menge->value();
		verarb[i] = comboBox_Verarb->currentText();
		preis_pe[i] = PreisPE->text().toDouble();
		menge_gewicht[i] = Berechnung.ber_Fleischanteil(menge_braetgewicht, menge_prozent[i]);
		fleischpreis += Berechnung.ber_Kostenanteil(menge_gewicht[i]/1000, preis_pe[i]);
		
		if (i % 2 == 0)   // gerade
		{
			body += "<tr>";
			body += "<td style = 'vertical-align: top; background-color: rgb(204, 204, 255); text-align: right; width: 100px;'><big>" + QString::number(menge_gewicht[i]) + " g</big><br></td>";
			body += "<td style = 'vertical-align: top; background-color: rgb(204, 204, 255); width: 250px;'>";
			body += "<div style = 'margin-left: 40px; background-color: rgb(204, 204, 255);'><big>" + zutat[i] + "</big><br></div></td>";
			body += "<td style = 'vertical-align: top; background-color: rgb(204, 204, 255);'><big>" + verarb[i] + "</big><br></td>";
			body += "</tr>";
		}
		else
		{
			body += "<tr>";
			body += "<td style = 'vertical-align: top; text-align: right; width: 100px;'><big>" + QString::number(menge_gewicht[i]) + " g</big><br></td>";
			body += "<td style = 'vertical-align: top; width: 250px;'>";
			body += "<div style = 'margin-left: 40px;'><big>" + zutat[i] + "</big><br></div></td>";
			body += "<td style = 'vertical-align: top;'><big>" + verarb[i] + "</big><br></td>";
			body += "</tr>";
		}
	}
	if (row % 2 == 0)
	{
		body += "<tr>";
		body += "<td style = 'vertical-align: top; background-color: rgb(204, 204, 255); width: 100px; text-align: right;'><big> </big><br></td>";
		body += "<td style = 'vertical-align: top; background-color: rgb(204, 204, 255); width: 250px;'>";
		body += "<div style = 'margin-left: 40px; background-color: rgb(204, 204, 255); '><big> </big><br></div>";
		body += "</td>";
		body += "<td style = 'vertical-align: top; background-color: rgb(204, 204, 255);'><big> </big><br></td>";
		body += "</tr>";
	}
	//Array wieder freigeben
	delete[](zutat);
	delete[](verarb);
	delete[](menge_prozent);
	delete[](menge_gewicht);
	delete[](preis_pe);
	
	body += "</tbody>";
	body += "</table>";

	body += "<br><br>";

	//++++++++++++++++++++++++++++++++++++++Gewürzbereich
	body += "<h1 style = 'text-align: left; margin-left: 80px;'>Gew&uumlrze :</h1>";

	body += "<table style = 'text-align: left; width: 80%; margin-left: auto; margin-right: auto;' border = '0' cellpadding = '0' cellspacing = '0'>";
	body += "<thead>";
	body += "<tr>";
	body += "<th style = 'vertical-align: top; width: 100px; text-align: right;'><big>g/Masse</big><br></th>";
	body += "<th style = 'vertical-align: top; width: 200px;'>";
	body += "<div style = 'margin-left: 40px;'><big>Gew&uumlrz</big><br></div></th>";
	body += "<th style = 'vertical-align: top; width: 200px;'>";
	body += "<div style = 'margin-left: 40px;'><big>Verarbeitung</big><br></div></th>";
	body += "<th style = 'vertical-align: top; text-align: right;'>";
	body += "<div style = 'margin-right: 5px;'><big>Ursprungsmenge g/kg</big><br></th>";
	body += "</tr>";
	body += "</thead>";

	body += "<tbody>";

	//Gewürzwidget auslesen
	row = tableWidget_Gewuerze->rowCount();
	//erforderliche Arrays anlegen
	QString *gewuerz = new QString[row];
	QString *verarb_gew = new QString[row];
	QString *einh = new QString[row];

	double *menge_g_p_kg = new double[row];
	double *menge_g = new double[row];
	double *preis_peGw = new double[row];

	//QString gewuerz[99], verarb_gew[99], einh[99];
	//double menge_g_p_kg[99], menge_g[99], preis_peGw[99];
	for (int j = 0; j < row; j++)
	{
		QComboBox *comboBox_Gew_Zutat = (QComboBox *)tableWidget_Gewuerze->cellWidget(j, 1);
		QDoubleSpinBox *spinBox_Gew_Menge = (QDoubleSpinBox *)tableWidget_Gewuerze->cellWidget(j, 2);
		QTableWidgetItem *Gew_Einh = tableWidget_Gewuerze->item(j, 3);
		QComboBox *comboBox_Gew_Verarb = (QComboBox *)tableWidget_Gewuerze->cellWidget(j, 4);
		QTableWidgetItem *PreisPEGew = tableWidget_Gewuerze->item(j, 8);
		gewuerz[j] = comboBox_Gew_Zutat->currentText();
		menge_g_p_kg[j] = spinBox_Gew_Menge->value();
		verarb_gew[j] = comboBox_Gew_Verarb->currentText();
		menge_g[j] = Berechnung.ber_Gewuerzanteil(menge_braetgewicht, menge_g_p_kg[j]);
		einh[j] = Gew_Einh->text();
		preis_peGw[j] = PreisPEGew->text().toDouble();
		gewuerzpreis += Berechnung.ber_Kostenanteil(menge_g[j], preis_peGw[j]);

		if (j % 2 == 0)
		{
			body += "<tr>";
			body += "<td style = 'vertical-align: top; background-color: rgb(204, 204, 255); width: 100px; text-align: right;'><big>" + QString::number(menge_g[j]) + " " + einh[j] + "</big><br></td>";
			body += "<td style = 'vertical-align: top; background-color: rgb(204, 204, 255); width: 200px;'>";
			body += "<div style = 'margin-left: 40px; background-color: rgb(204, 204, 255); '><big>" + gewuerz[j] + "</big><br></div>";
			body += "</td>";
			body += "<td style = 'vertical-align: top; background-color: rgb(204, 204, 255); width: 200px;'>";
			body += "<div style = 'margin-left: 40px; background-color: rgb(204, 204, 255);'><big>" + verarb_gew[j] + "</big><br></div></td>";
			body += "<td style = 'vertical-align: top; text-align: right; background-color: rgb(204, 204, 255);'>";
			body += "<div style = 'margin-right: 20px; background-color: rgb(204, 204, 255);'><big>" + QString::number(menge_g_p_kg[j]) + " " + einh[j] + "</big><br></td>";
			body += "</tr>";
		}
		else
		{
			body += "<tr>";
			body += "<td style = 'vertical-align: top; width: 100px; text-align: right;'><big>" + QString::number(menge_g[j]) + " " + einh[j] + "</big><br></td>";
			body += "<td style = 'vertical-align: top; width: 200px;'>";
			body += "<div style = 'margin-left: 40px;'><big>" + gewuerz[j] + "</big><br></div>";
			body += "</td>";
			body += "<td style = 'vertical-align: top; width: 200px;'>";
			body += "<div style = 'margin-left: 40px;'><big>" + verarb_gew[j] + "</big><br></div></td>";
			body += "<td style = 'vertical-align: top; text-align: right;'>";
			body += "<div style = 'margin-right: 20px;'><big>" + QString::number(menge_g_p_kg[j]) + " " + einh[j] + "</big><br></td>";
			body += "</tr>";
		}
	}
	//leere Zeile am schluß einfügen
	if (row % 2 == 0)
	{
		body += "<tr>";
		body += "<td style = 'vertical-align: top; background-color: rgb(204, 204, 255); width: 100px; text-align: right;'><big> </big><br></td>";
		body += "<td style = 'vertical-align: top; background-color: rgb(204, 204, 255); width: 250px;'>";
		body += "<div style = 'margin-left: 40px; background-color: rgb(204, 204, 255); '><big> </big><br></div>";
		body += "</td>";
		body += "<td style = 'margin-left: 40px; background-color: rgb(204, 204, 255);'><big> </big><br></td>";
		body += "<td style = 'vertical-align: top; background-color: rgb(204, 204, 255);'><big> </big><br></td>";
		body += "</tr>";
	}
	//Array wieder freigeben
	delete[](gewuerz);
	delete[](verarb_gew);
	delete[](einh);
	delete[](menge_g_p_kg);
	delete[](menge_g);
	delete[](preis_peGw);

	body += "</tbody>";
	body += "</table>";

	body += "<br><br>";
	//++++++++++++++++++++++++++++++++++++++Kostenbereich
	body += "<h1 style = 'text-align: left; margin-left: 80px;'>Kosten :</h1>";

	body += "<table style = 'text-align: left; width: 80%; margin-left: auto; margin-right: auto;' border = '0' cellpadding = '0' cellspacing = '0'>";
	body += "<tbody>";

	QString numStrFleisch;
	numStrFleisch.setNum(fleischpreis, 'f', 2);
	body += "<tr>";
	body += "<td style = 'vertical-align: top; background-color: rgb(204, 204, 255); width: 100px; text-align: right;'><big>" + numStrFleisch + " &euro;</big><br></td>";
	body += "<td style = 'vertical-align: top; background-color: rgb(204, 204, 255); width: 250px;'>";
	body += "<div style = 'margin-left: 40px; background-color: rgb(204, 204, 255); '><big>Zutaten</big><br></div>";
	body += "</td>";
	body += "<td style = 'vertical-align: top; background-color: rgb(204, 204, 255);'><big> </big><br></td>";
	body += "</tr>";

	//body += "<tr>";
	//body += "<td style = 'vertical-align: top; background-color: rgb(204, 204, 255); width: 250px;'>";
	//QString numStrFleisch;
	//numStrFleisch.setNum(fleischpreis, 'f', 2);
	//body += "<div style = 'margin-left: 40px; background-color: rgb(204, 204, 255);'><big>" + numStrFleisch + " &euro;</big><br></div></td>";
	//body += "<td style = 'vertical-align: top; background-color: rgb(204, 204, 255); text-align: left; width: 100px;'><big>Fleischanteil</big><br></td>";
	//body += "</tr>";

	QString numStrGewuerz;
	numStrGewuerz.setNum(gewuerzpreis, 'f', 2);
	body += "<tr>";
	body += "<td style = 'vertical-align: top; width: 100px; text-align: right;'><big>" + numStrGewuerz + " &euro;</big><br></td>";
	body += "<td style = 'vertical-align: top; width: 250px;'>";
	body += "<div style = 'margin-left: 40px;'><big>Gew&uumlrze</big><br></div>";
	body += "</td>";
	body += "<td style = 'vertical-align: top;'><big> </big><br></td>";
	body += "</tr>";

	//body += "<tr>";
	//body += "<td style = 'vertical-align: top; text-align: right; width: 100px;'><big>Gewürzanteil</big><br></td>";
	//body += "<td style = 'vertical-align: top; width: 250px;'>";
	//QString numStrGewuerz;
	//numStrGewuerz.setNum(gewuerzpreis, 'f', 2);
	//body += "<div style = 'margin-left: 40px; '><big>" + numStrGewuerz + " &euro;</big><br></div></td>";
	//body += "</tr>";

	QString numStrDarm;
	numStrDarm.setNum(darmpreis, 'f', 2);
	if (numStrDarm != "0.00")
	{
		body += "<tr>";
		body += "<td style = 'vertical-align: top; background-color: rgb(204, 204, 255); width: 100px; text-align: right;'><big>" + numStrDarm + " &euro;</big><br></td>";
		body += "<td style = 'vertical-align: top; background-color: rgb(204, 204, 255); width: 250px;'>";
		body += "<div style = 'margin-left: 40px; background-color: rgb(204, 204, 255); '><big>Darm</big><br></div>";
		body += "</td>";
		body += "<td style = 'vertical-align: top; background-color: rgb(204, 204, 255);'><big> </big><br></td>";
		body += "</tr>";
	}
	
	body += "</tbody>";
	body += "</table>";

	body += "<br><br>";

	body += "</div>";
	body += "<div class='rm' style='margin:10px 10px 10px 30px; width:90%;' align='center'>";
	body += "erstellt mit " + QString(APP_KURZNAME) + " Version " + QString(APP_VERSION);
	body += "</div>";
	seite += body;

	//Seitenende
	ende = "</body></html>";
	seite += ende;

	gesamtpreis = fleischpreis + gewuerzpreis + darmpreis;

	webEngineView->setHtml(seite);
}
