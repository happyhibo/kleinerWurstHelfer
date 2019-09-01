
#include "kwh.h"
#include <QtWidgets/QApplication>
#include "connect.h"
#include "definitionen.h"
#include <resource.h>



int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	// Mit Datenbank verbinden
		if (!DB_verbindung()) {
			return 1;
		}

	KWH w;
	w.show();
	return a.exec();
}
