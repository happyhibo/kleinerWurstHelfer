
#ifndef MYQDOUBLESPINBOX_H
#define MYQDOUBLESPINBOX_H

#include <qspinbox.h>
#include <qevent.h>


class MyQDoubleSpinBox : public QDoubleSpinBox {

	Q_OBJECT

public:
	explicit MyQDoubleSpinBox(QWidget * parent = 0);
	~MyQDoubleSpinBox();

private:
	void wheelEvent(QWheelEvent * event);

protected:
	void keyPressEvent(QKeyEvent * event);

//signals:
//	void sigD_ReturnPressed();
	
};

#endif // MYQDOUBLESPINBOX_H