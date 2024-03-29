#ifndef AVANSCRUM_H
#define AVANSCRUM_H

#include <QtWidgets/QMainWindow>
#include "ui_avanscrum.h"
#include "TFS\Defect.h"
#include "TFS\SprintBacklogItem.h"
#include "TFS\ProductBacklogItem.h"
#include "TFS\WorkItem.h"
#include "TFS\Status.h"
#include "HistoryLog.h"

class AvanScrum : public QMainWindow
{
	Q_OBJECT

public:
	AvanScrum(QWidget *parent = 0);
	~AvanScrum();
	typedef void (AvanScrum::*func)();
	func refreshWorkItems();
	QString getProjectName();

private:
	QPushButton *button;
	Ui::AvanScrumClass ui;

private:
	//void refreshWorkItems1();
	void getWorkItem();
	void refresh();
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

		void ProcessWorkItem(WorkItem*, Status*, int);
	};
	class Detail : public TFSVisitor
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
	
	void ListChangedToDo(QListWidgetItem*);
	void ListChangedDoing(QListWidgetItem*);
	void ListChangedVerify(QListWidgetItem*);
	void ListChangedDone(QListWidgetItem*);
	
	void ListcrChangedtodo(int);
	void ListcrChangedverify(int);
	void ListcrChangeddoing(int);
	void ListcrChangeddone(int);
	
	void undoClicked();
};

#endif // AVANSCRUM_H