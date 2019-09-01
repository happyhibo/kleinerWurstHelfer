#include "kwh.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	kwh w;
	w.show();
	return a.exec();
}
