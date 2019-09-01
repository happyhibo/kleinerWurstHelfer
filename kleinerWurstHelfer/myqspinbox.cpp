#include "myqspinbox.h"


MyQSpinbox::MyQSpinbox(QWidget * parent) : QSpinBox(parent) 
{
}

MyQSpinbox::~MyQSpinbox() 
{
}

void MyQSpinbox::keyPressEvent(QKeyEvent * event) 
{

	if (event->key() == Qt::Key_Enter) {
		emit ReturnPressed();
	}
	else {
		QSpinBox::keyPressEvent(event);
	}
}

void MyQSpinbox::wheelEvent(QWheelEvent * event)
{

}
