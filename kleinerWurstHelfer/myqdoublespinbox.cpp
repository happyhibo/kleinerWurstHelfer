#include "myqdoublespinbox.h"

MyQDoubleSpinBox::MyQDoubleSpinBox(QWidget * parent) : QDoubleSpinBox(parent)
{
}

MyQDoubleSpinBox::~MyQDoubleSpinBox()
{
}

void MyQDoubleSpinBox::keyPressEvent(QKeyEvent * event) {

	if (event->key() == Qt::Key_Return) {
		editingFinished();
	}
	else {
		QDoubleSpinBox::keyPressEvent(event);
	}
}

void MyQDoubleSpinBox::wheelEvent(QWheelEvent * event)
{

}

