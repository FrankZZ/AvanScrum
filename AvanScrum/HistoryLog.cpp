#include "HistoryLog.h"


HistoryLog::HistoryLog(void)
{
}


HistoryLog::~HistoryLog(void)
{
}

HistoryLog::HistoryLog(Ui::AvanScrumClass* UI)
{
	ui = UI;
}
ListWidget* HistoryLog::findWidgetByName(QString name)
{
	if(name == "todo") return ui->list_todo;
	else if(name == "doing") return ui->list_doing;
	else if(name == "done") return ui->list_done;
	else if(name == "verify") return ui->list_verify;
	else return NULL;
}
void HistoryLog::undo()
{
	int size = ui->HistoryLogList->count();
	if(size > 0)
	{
		QString last = historyLog.back();
		QListWidgetItem* it = ui->HistoryLogList->takeItem(size-1);
		delete it;
		QStringList pieces = last.split( ":" );
		QString itemPiece = pieces[0].mid(0,pieces[0].count()-4).trimmed();
		QString fromPiece = pieces[1].mid(0,pieces[1].count()-4).trimmed();
		QString toPiece = pieces[2].trimmed();
		QListWidget* from = findWidgetByName(fromPiece);
		QListWidget* to = findWidgetByName(toPiece);
		QListWidgetItem* item;
		for(int idx = 0; idx< to->count(); idx++)
		{
			if(to->item(idx)->text() == itemPiece)
			{
				item = to->takeItem(idx);
				from->addItem(item);
				break;
			}
		}
		historyLog.erase(historyLog.end()-1);
	}
}
void HistoryLog::addToHistory(QListWidgetItem* item, WorkItem* wi)
{	
	QString text(item->text()+" van: " +listDraggedFrom);
	QListWidget* ql = item->listWidget();
	if(ql == ui->list_doing) text += " naar: doing";
	else if(ql == ui->list_todo) text += " naar: todo";
	else if(ql == ui->list_verify) text += " naar: verify";
	else if(ql == ui->list_done) text += " naar: done";
	else text += " naar : fail";
	if(!(std::find(historyLog.begin(), historyLog.end(), text) != historyLog.end()))
	{
		historyLog.push_back(text);
		ui->HistoryLogList->addItem(text);
		moveItem(wi, true);
	}
}
void HistoryLog::moveItem(WorkItem* item, bool forward)
{
	moveServerItems msi = moveServerItems();
	if(forward) msi.moveWorkItemForward(item);
	else msi.moveWorkItemBack(item);
}
