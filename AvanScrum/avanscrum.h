#ifndef AVANSCRUM_H
#define AVANSCRUM_H

#include <QtWidgets/QMainWindow>
#include "ui_avanscrum.h"

class AvanScrum : public QMainWindow
{
	Q_OBJECT

public:
	AvanScrum(QWidget *parent = 0);
	~AvanScrum();

private:
	Ui::AvanScrumClass ui;
	QPushButton *button;

private slots:
    void nextSprint();
    void prevSprint();
	void switchCombo();
};

#endif // AVANSCRUM_H