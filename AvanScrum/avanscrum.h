#ifndef AVANSCRUM_H
#define AVANSCRUM_H

#include <QtWidgets/QMainWindow>
#include "ui_avanscrum.h"
#include "HistoryLog.h"

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
	void SprintSelectionChanged(int index); //temporary demo code
	void fillUsers();
	void dropEvent(QDropEvent*);
	void onListItemClicked(QListWidgetItem*, QListWidget*);

private slots:
    void nextSprint();
    void prevSprint();
	void switchCombo();
	void listToDoClicked(QListWidgetItem*);
	void listDoingClicked(QListWidgetItem*);
	void listVerifyClicked(QListWidgetItem*);
	void listChangedToDo(QListWidgetItem* item);
	void listChangedDoing(QListWidgetItem* item);
	void listChangedVerify(QListWidgetItem* item);
	void listChangedDone(QListWidgetItem* item);
	void SetNodeDefect();
	void SetNodePB();
	void SetNodeSB();
};
#endif // AVANSCRUM_H