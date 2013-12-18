#include <ListWidget.h>


ListWidget::ListWidget(QFrame* fParent)
: QListWidget(fParent), 
wiVector()
{
	
}

void ListWidget::addItem(WorkItem* wi)
{
	QString gegevens;
	int workItemNumber = wi->getWorkItemNumber();
	QListWidgetItem* item = new QListWidgetItem();
	item->setBackgroundColor(QColor(255,0,0,255));
	item->setSizeHint(QSize(1,50));
	item->setTextColor(QColor(255,255,255,255));
	gegevens.append("#");
	gegevens.append(QString::number(workItemNumber));
	gegevens.append(" ");
	gegevens.append(wi->getTitle());
	gegevens.append("\n");

	if(wi->getUser() != NULL)
	{
		gegevens.append(wi->getUser()->getName());
	}

	item->setText(gegevens);

	//TODO: Bijhouden in wiVector welke WorkItems er toegevoegd zijn zodat ze 
	//later via een signal gereturned kunnen worden naar avanscrum (bij drag&drop)

	QListWidget::addItem(item);
}