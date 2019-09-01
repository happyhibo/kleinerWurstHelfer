#ifndef MYQSPINBOX_H
#define MYQSPINBOX_H

#include <qspinbox.h>
#include <qevent.h>


class MyQSpinbox : public QSpinBox {
	Q_OBJECT

public:
	explicit MyQSpinbox(QWidget * parent = 0);
	~MyQSpinbox();

private:
	void wheelEvent(QWheelEvent * event);

protected:
	void keyPressEvent(QKeyEvent * event);

signals:
	void ReturnPressed();

};

#endif // MYQSPINBOX_H