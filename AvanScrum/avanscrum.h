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
	void refreshWorkItems();
	void getWorkItem();
	void ListViewSettings(QListView*);
	void fillUsers();

private slots:
    void nextSprint();
    void prevSprint();
	void switchCombo();
	void onListToDoItemClicked(QListWidgetItem*);
};

#endif // AVANSCRUM_H