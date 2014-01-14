#include <ListWidget.h>


ListWidget::ListWidget(QFrame* fParent)
: QListWidget(fParent)
{
	this->setSelectionMode(QAbstractItemView::SingleSelection);
	this->setDragEnabled(true);
	this->setDragDropMode(QAbstractItemView::DragDrop);
	this->viewport()->setAcceptDrops(true);
	this->setDropIndicatorShown(true);
	this->setDefaultDropAction(Qt::DropAction::MoveAction);
	this->setSpacing(4);
}

void ListWidget::addItem(int workItemId, WorkItem* wi)
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
	
	QVariant variant(workItemId);

	item->setData(Qt::UserRole, variant);

	item->setText(gegevens);

	QListWidget::addItem(item);
}
