#include "berechnungen.h"
#include <QtGlobal>

Qberechnungen::Qberechnungen() {

}


double Qberechnungen::ber_Fleischanteil(double Menge_braet, double Anteil_Prozent)
{
	double _menge = Menge_braet;
	double _anteil = Anteil_Prozent;

	return (_menge / 100 * _anteil);
}

double Qberechnungen::ber_Gewuerzanteil(double Menge_braet, double Gewuerz_g_p_kg)
{
	double _menge = Menge_braet /1000;
	double _anteil = Gewuerz_g_p_kg;

	return (_menge  * _anteil);
}

double Qberechnungen::ber_Kostenanteil(double Menge, double Preis_p_Einheit)
{
	return Menge * Preis_p_Einheit;
}



