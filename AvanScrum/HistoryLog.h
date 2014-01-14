#pragma once
#include <QtWidgets/QMainWindow>
#include <QtGui>
 #include <QListWidget>
#include "ui_avanscrum.h"
#include "moveServerItems.h"

class HistoryLog
{
public:
	HistoryLog(void);
	~HistoryLog(void);
	QString listDraggedFrom;
	HistoryLog(Ui::AvanScrumClass* UI);
	ListWidget* findWidgetByName(QString name);
	void undo();
	void addToHistory(QListWidgetItem* item, WorkItem* wi);
	std::vector<QString> historyLog;
	void moveItem(WorkItem*, bool forward);
private :
	Ui::AvanScrumClass* ui;
};

