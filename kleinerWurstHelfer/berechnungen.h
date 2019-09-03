#ifndef BERECHNUNGEN_H
#define BERECHNUNGEN_H

class Qberechnungen {

public:
	double ber_Fleischanteil(double Menge_braet, double Anteil_Prozent);
	double ber_Gewuerzanteil(double Menge_braet, double Gewuerz_g_p_kg);

	double ber_Kostenanteil(double Menge, double Preis_p_Einheit);

	Qberechnungen();

private:
	

};

#endif // BERECHNUNGEN_H