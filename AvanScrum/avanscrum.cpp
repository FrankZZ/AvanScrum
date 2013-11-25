#include "avanscrum.h"
#include "qmessagebox.h";
#include "TFS\sprint.h";
#include <iostream>

QPushButton *button;

AvanScrum::AvanScrum(QWidget *parent) : QMainWindow(parent)
{
	ui.setupUi(this);

	QStringList *s = new QStringList();
	s->insert(0,"project 1");
	s->insert(1,"project 2");
	s->insert(2,"project 3");
	ui.cb_Projects_3->addItems(*s);

	button = ui.btn_NextSprint_3;

	connect(button, SIGNAL(clicked()), this, SLOT(handleButton()));
}

AvanScrum::~AvanScrum()
{
	
}

void AvanScrum::handleButton()
{
	Sprint* sprint = new Sprint();

	//sprint->setName("xxx");

	QMessageBox msgBox;
	msgBox.setText(sprint->getName());
	msgBox.setStandardButtons(QMessageBox::Ok);

	msgBox.exec();
}