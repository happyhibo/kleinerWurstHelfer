#include "mynewdialog.h"
//#include <QtWidgets>

myNewDialog::myNewDialog(QString txtTitel, QString txtZeile1, QString txtZeile2, QString txtZeile3, QString txtZeile4, QString txtZeile5, QWidget *parent) : QDialog(parent)
{
	QStringList txtListe = { txtZeile1, txtZeile2, txtZeile3, txtZeile4, txtZeile5 };

	setupUi(this);
	this->setWindowModality(Qt::ApplicationModal);
	this->resize(50, 50);
	QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	sizePolicy.setHorizontalStretch(0);
	sizePolicy.setVerticalStretch(0);
	sizePolicy.setHeightForWidth(this->sizePolicy().hasHeightForWidth());
	this->setSizePolicy(sizePolicy);
	
	font.setPointSize(10);
	this->setFont(font);
	
	mainLayout = new QVBoxLayout;
	mainLayout->setSpacing(6);
	mainLayout->setContentsMargins(10, 10, 10, 10);
	//mainLayout->setObjectName(QString::fromUtf8("mainLayout"));

	for (int i = 0; i < txtListe.size(); i++)
	{
		if (txtListe[i] != "")
		{
			if (txtListe[i] == "Einheit :")
			{
				NewComboLine(i, txtListe[i]);
			}
			else
			{
				NewInputLine(i, txtListe[i]);
			}
		}
	}

	QSpacerItem *verticalSpacer = new QSpacerItem(10, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

	mainLayout->addItem(verticalSpacer);

	QHBoxLayout *horizontalLayout_buttom = new QHBoxLayout;
	horizontalLayout_buttom->setSpacing(6);
	//horizontalLayout_buttom->setObjectName(QString::fromUtf8("horizontalLayout_buttom"));
	QSpacerItem *horizontalSpacer_buttom = new QSpacerItem(1, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

	horizontalLayout_buttom->addItem(horizontalSpacer_buttom);

	pushButton_New_Ok = new QPushButton("OK");
	//pushButton_New_Ok->setObjectName(QString::fromUtf8("pushButton_New_Ok"));
	pushButton_New_Ok->setEnabled(false);
	pushButton_New_Ok->setFont(font);

	horizontalLayout_buttom->addWidget(pushButton_New_Ok);

	pushButton_New_Cnl = new QPushButton("Cancel");
	//pushButton_New_Cnl->setObjectName(QString::fromUtf8("pushButton_New_cnl"));
	pushButton_New_Cnl->setFont(font);
	pushButton_New_Cnl->setDefault(true);

	horizontalLayout_buttom->addWidget(pushButton_New_Cnl);


	mainLayout->addLayout(horizontalLayout_buttom);


	setLayout(mainLayout);

	setWindowTitle(txtTitel);
	//setWindowTitle(_titel);

	connect(lineEdit[0], &QLineEdit::textChanged, this, &myNewDialog::btnOKEnable);
	connect(pushButton_New_Ok, &QPushButton::clicked, this, &myNewDialog::accept);
	connect(pushButton_New_Cnl, &QPushButton::clicked, this, &myNewDialog::reject);
}

//myNewDialog::~myNewDialog()
//{
//}

void myNewDialog::NewInputLine(int index, QString Label) {

	horizontalLayout[index] = new QHBoxLayout;
	horizontalLayout[index]->setSpacing(6);
	//horizontalLayout[0]->setObjectName(QString::fromUtf8("horizontalLayout1"));

	label[index] = new QLabel(Label);
	//label[index]->setObjectName(QString::fromUtf8("Label_" + index));
	label[index]->setFont(font);

	horizontalLayout[index]->addWidget(label[index]);

	horizontalSpacer[index] = new QSpacerItem(5, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

	horizontalLayout[index]->addItem(horizontalSpacer[index]);

	lineEdit[index] = new QLineEdit;
	//lineEdit[index]->setObjectName(QString::fromUtf8("lineEdit_New_" + index));
	QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
	sizePolicy1.setHorizontalStretch(0);
	sizePolicy1.setVerticalStretch(0);
	sizePolicy1.setHeightForWidth(lineEdit[index]->sizePolicy().hasHeightForWidth());
	lineEdit[index]->setSizePolicy(sizePolicy1);
	lineEdit[index]->setMinimumSize(QSize(150, 22));
	lineEdit[index]->setFont(font);

	if (Label == "Preis per Einh. :")
	{
		//lineEdit[index]->setInputMethodHints(Qt::ImhFormattedNumbersOnly);
		QRegExp rx("[0-9\.\,]*");
		lineEdit[index]->setValidator(new QRegExpValidator(rx, lineEdit[index]));
	}


	horizontalLayout[index]->addWidget(lineEdit[index]);

	mainLayout->addLayout(horizontalLayout[index]);
	
	//auto sigMap = new QSignalMapper(this);
	//connect(lineEdit[index], SIGNAL(textChanged()),	sigMap, SLOT(map()));
	//sigMap->setMapping(lineEdit[index], index);
	//connect(sigMap, SIGNAL(mapped(int)),this, SLOT(btnOKEnable()));

}

void myNewDialog::NewComboLine(int index, QString Label) {

	horizontalLayout[index] = new QHBoxLayout;
	horizontalLayout[index]->setSpacing(6);
	//horizontalLayout[0]->setObjectName(QString::fromUtf8("horizontalLayout1"));

	label[index] = new QLabel(Label);
	//label[index]->setObjectName(QString::fromUtf8("Label_" + index));
	label[index]->setFont(font);

	horizontalLayout[index]->addWidget(label[index]);

	horizontalSpacer[index] = new QSpacerItem(5, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

	horizontalLayout[index]->addItem(horizontalSpacer[index]);

	label_einh_id = new QLabel("E_ID");
	//label_einh_id->setObjectName(QString::fromUtf8("label_einh_id"));
	label_einh_id->setEnabled(false);
	label_einh_id->setHidden(true);
	QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
	sizePolicy2.setHorizontalStretch(0);
	sizePolicy2.setVerticalStretch(0);
	sizePolicy2.setHeightForWidth(label_einh_id->sizePolicy().hasHeightForWidth());
	label_einh_id->setSizePolicy(sizePolicy2);
	label_einh_id->setMinimumSize(QSize(1, 22));

	horizontalLayout[index]->addWidget(label_einh_id);
	
	comboBox_Einh = new QComboBox();
	//comboBox_Einh->setObjectName(QString::fromUtf8("comboBox_Einh"));
	comboBox_Einh->setEnabled(true);
	QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
	sizePolicy3.setHorizontalStretch(0);
	sizePolicy3.setVerticalStretch(0);
	sizePolicy3.setHeightForWidth(comboBox_Einh->sizePolicy().hasHeightForWidth());
	comboBox_Einh->setSizePolicy(sizePolicy3);
	comboBox_Einh->setMinimumSize(QSize(150, 22));
	comboBox_Einh->setFocusPolicy(Qt::StrongFocus);
	comboBox_Einh->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
	comboBox_Einh->setEditable(false);
	comboBox_Einh->setFrame(true);
	comboBox_Einh->setFont(font);

	horizontalLayout[index]->addWidget(comboBox_Einh);

	mainLayout->addLayout(horizontalLayout[index]);

	db_query_einheiten();
}

void myNewDialog::db_query_einheiten() {

	// Combobox mit EInheiten füllen
	QSqlQuery dbquery_einh("SELECT * FROM einheiten ORDER BY e_name;");
	if (!dbquery_einh.isActive())
	{
		// Fehlermeldung Datenbankabfrage
		ErrorMessage* errorMessage = new ErrorMessage();
		errorMessage->showMessage(ERR_SQL_DB_ABFRAGE, TYPE_WARNUNG, CANCEL_NO,
			QString::fromLatin1("Rückgabe:\n") +
			dbquery_einh.lastError().databaseText() + QString::fromLatin1("\nSQL-Befehl:\n") + dbquery_einh.lastError().text());
	}
	QSqlQueryModel* model_einheiten = new QSqlQueryModel;
	model_einheiten->setQuery(dbquery_einh);
	model_einheiten->setHeaderData(0, Qt::Horizontal, "ID");
	model_einheiten->setHeaderData(1, Qt::Horizontal, "e_name");
	model_einheiten->setHeaderData(2, Qt::Horizontal, "e_kurzzzeichen");
	comboBox_Einh->clear();
	comboBox_Einh->setModel(model_einheiten);
	comboBox_Einh->setModelColumn(1);
	comboBox_Einh_currentIndexChanged(comboBox_Einh->currentIndex());

	connect(comboBox_Einh, static_cast<void (QComboBox::*)(int index)>
		(&QComboBox::currentIndexChanged), this, &myNewDialog::comboBox_Einh_currentIndexChanged);

}

void myNewDialog::comboBox_Einh_currentIndexChanged(int index)
{
	//int row = comboBox_Einh->currentIndex();

	QModelIndex mindex = comboBox_Einh->model()->index(index, 0, comboBox_Einh->rootModelIndex());
	int dbID = comboBox_Einh->model()->data(mindex, 0).toInt();
	label_einh_id->setText(QString::number(dbID));
}


void myNewDialog::btnOKEnable()
{
	pushButton_New_Ok->setEnabled(lineEdit[0]->hasAcceptableInput());
	pushButton_New_Ok->setDefault(true);
	pushButton_New_Cnl->setDefault(false);
}
