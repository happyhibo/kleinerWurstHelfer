#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_kwh.h"

class kwh : public QMainWindow
{
	Q_OBJECT

public:
	kwh(QWidget *parent = Q_NULLPTR);

private:
	Ui::kwhClass ui;
};
