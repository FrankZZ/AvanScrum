#define FILELIST_H
 
#include <QtGui>
#include <QtCore>
#include <qlistwidget>
 
 
class FileList : public QListWidget
{
	Q_OBJECT
 
public:
	FileList();
 
protected:
	void dragEnterEvent(QDragEnterEvent *event);
	void dragMoveEvent(QDragMoveEvent *event);
	void dragLeaveEvent(QDragLeaveEvent *event);
	void dropEvent(QDropEvent *event);
};
 