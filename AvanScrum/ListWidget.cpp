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
	this->setSpacing(2);
}

void ListWidget::addItem(int workItemId, WorkItem* wi, int wiType)
{
	QString gegevens;
	int workItemNumber = wi->getWorkItemNumber();
	QListWidgetItem* item = new QListWidgetItem();
	
	if (wiType == 2)
		gegevens.append("D ");
	else if (wiType == 0)
		gegevens.append("SBI ");
	else
		gegevens.append("PBI ");
	item->setTextColor(QColor("white"));
	item->setSizeHint(QSize(1,50));
	
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

	if (wi->getUser() != NULL)
	{
		User::ItemStorage::iterator iUser;
	
		int counter = 0;
		QString aColors[] = {"brown", "green", "blue", "yellow", "pink", "purple", "orange", "gold"};
	
		for ( iUser = User::begin(); iUser != User::end(); ++iUser )
		{
			if (iUser->first == wi->getUser()->getName())
			{
				item->setBackgroundColor(QColor(aColors[counter]));
				break;
			}
			counter++;
		}
	} else
		item->setBackgroundColor(QColor("grey"));

	QListWidget::addItem(item);
}
