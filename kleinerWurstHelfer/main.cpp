
#include "kwh.h"
#include <QtWidgets/QApplication>
#include "dbconnect.h"
#include "definitionen.h"
#include <resource.h>
#include "settings.h"


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	a.setOrganizationName(QString(APP_KURZNAME));
	a.setApplicationName(QString(APP_NAME));
	a.setApplicationVersion(QString(APP_VERSION));

	// Mit Datenbank verbinden
		if (!DB_verbindung()) {
			return 1;
		}

	KWH w;
	w.show();
	return a.exec();
}
