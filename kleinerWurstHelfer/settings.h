#ifndef SETTINGS_H
#define SETTINGS_H

#include <qsettings.h>
#include <qcoreapplication.h>
#include <qfileinfo.h>
//#include <qwidget.h>
//#include <qmainwindow.h>
#include <qsize.h>

class Settings : public QSettings
{
	Q_OBJECT

public:
	explicit Settings(QObject *parent = nullptr);
	~Settings();

	QString getDatabasePath();
	void setDatabasePath(const QString & path);
	void setWindowSize(const QSize & size);
	QSize getWindowSize();
	void setWindowPos(const QPoint & pos);
	QPoint getWindowPos();

};


#endif // !SETTINGS_H
