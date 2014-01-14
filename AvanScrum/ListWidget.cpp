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
	//this->setStyleSheet("QListWidget::item { border: 4px solid black; }");
}

void ListWidget::addItem(int workItemId, WorkItem* wi, int wiType)
{
	QString gegevens;
	int workItemNumber = wi->getWorkItemNumber();
	QListWidgetItem* item = new QListWidgetItem();
	
	QWidget* widget = new QWidget(NULL);

	
	
	if (wiType == 2)
		widget->setStyleSheet("border: 4px solid red;");
	else
		widget->setStyleSheet("border: 4px solid black;");
	
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

	QLabel* label = new QLabel(widget);
	
	label->setStyleSheet("border: none; margin: auto; margin-top: 4px;");

	label->setText(gegevens);

	if (wi->getUser() != NULL)
	{
		User::ItemStorage::iterator iUser;
	
		int counter = 0;
		QString aColors[] = {"brown", "green", "blue", "yellow", "pink", "purple", "orange", "gold"};
	
		for ( iUser = User::begin(); iUser != User::end(); ++iUser )
		{
			if (iUser->first == wi->getUser()->getName())
			{
				widget->setStyleSheet(widget->styleSheet() + "\nbackground-color: " + aColors[counter] + ";");
				break;
			}
			counter++;
		}
	} else
		widget->setStyleSheet(widget->styleSheet() + "\nbackground-color: grey;");
	QListWidget::addItem(item);
	QListWidget::setItemWidget(item, widget);
}
