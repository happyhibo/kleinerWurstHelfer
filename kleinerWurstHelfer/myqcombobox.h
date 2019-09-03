#ifndef MYQCOMPOBOX_H
#define MYQCOMPOBOX_H

#include <qcombobox.h>
#include <qevent.h>

class MyQComboBox : public QComboBox
{
	Q_OBJECT

public:
	explicit MyQComboBox(QWidget * parent = 0);
	~MyQComboBox();

private:
	void wheelEvent(QWheelEvent * event);
};

#endif // !MYQCOMPOBOX_H