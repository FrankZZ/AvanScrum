#ifndef AVANSCRUM_H
#define AVANSCRUM_H

#include <QtWidgets/QMainWindow>
#include "ui_avanscrum.h"
#include "TFS\Defect.h"
#include "TFS\SprintBacklogItem.h"
#include "TFS\ProductBacklogItem.h"
#include "TFS\WorkItem.h"
#include "TFS\Status.h"

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

		void ProcessWorkItem(WorkItem wi, Status* status);
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