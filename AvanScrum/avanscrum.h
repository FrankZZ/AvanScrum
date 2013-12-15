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
	void SprintSelectionChanged(int index); //temporary demo code
	void fillUsers();
	void dropEvent(QDropEvent*);
	void onListItemClicked(QListWidgetItem*, QListWidget*);

private:
	class Sort : public TFSVisitor
	{
		virtual void visit(SprintBacklogItem& sbi);
		virtual void visit(ProductBacklogItem& pbi);
		virtual void visit(Defect& def);
	};

private slots:
    void nextSprint();
    void prevSprint();
	void switchCombo();
	void listToDoClicked(QListWidgetItem*);
	void listDoingClicked(QListWidgetItem*);
	void listVerifyClicked(QListWidgetItem*);
};

#endif // AVANSCRUM_H