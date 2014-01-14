#include <qlistwidget.h>
#include <qstring.h>
#include <map>
#include <TFS/WorkItem.h>
#include <TFS/User.h>
#include <QDragMoveEvent>
#include <qvariant.h>
#include <qwidget.h>
#include <qlabel.h>

class ListWidget : public QListWidget
{
	public:
		ListWidget(QFrame*);
		void addItem(int, WorkItem*, int);
};