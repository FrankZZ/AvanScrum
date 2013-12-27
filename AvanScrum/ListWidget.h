#include <qlistwidget.h>
#include <qstring.h>
#include <vector>
#include <TFS/WorkItem.h>
#include <TFS/User.h>

class ListWidget : public QListWidget
{
	public:
		ListWidget(QFrame*);
		void addItem(WorkItem*);

	private:
		std::vector<WorkItem*> wiVector;

	signals:
		void itemDrag(WorkItem*);
		void itemDrop(WorkItem*);
};