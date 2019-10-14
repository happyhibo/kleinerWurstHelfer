#include "settings.h"


Settings::Settings(QObject *parent)
	: QSettings(QSettings::IniFormat, QSettings::UserScope, QCoreApplication::organizationName(), QCoreApplication::applicationName(), parent)
{

}


Settings::~Settings()
{
	
}

QString Settings::getDatabasePath()
{
#if DEBUG
	beginGroup("DEBUG_DB");
	QString path = QSettings::value("DEBUG_DB_Pfad").toString();
	endGroup();
#else
	beginGroup("DB");
	QString path = QSettings::value("DB_Pfad").toString();
	endGroup();
#endif // DEBUG
	return path;
}

void Settings::setDatabasePath(const QString &path)
{	
	QString _pfad = path;
#ifdef DEBUG
	beginGroup("DEBUG_DB");
	setValue("DEBUG_DB_Pfad", _pfad);
	endGroup();
#else
	beginGroup("DB");
	setValue("DB_Pfad", _pfad);
	endGroup();
#endif // DEBUG


	
	
}

void Settings::setWindowSize(const QSize &size)
{
	beginGroup("MainWindow");
	setValue("WinSize", size);
	endGroup();
}

QSize Settings::getWindowSize()
{
	beginGroup("MainWindow");
	QSize size = value("WinSize", QSize(1280, 768)).toSize();
	endGroup();
	return size;
}

void Settings::setWindowPos(const QPoint &pos)
{
	beginGroup("MainWindow");
	setValue("WinPos", pos);
	endGroup();
}

QPoint Settings::getWindowPos()
{
	beginGroup("MainWindow");
	QPoint pos = value("WinPos", QPoint(140, 40)).toPoint();
	endGroup();
	return pos;
}