#include <QtGui>
#include "FileList.h"


FileList::FileList()
{
}

FileList::FileList(QListWidget* qlw)
{

}
     
void FileList::dragEnterEvent(QDragEnterEvent *event)
{
	event->acceptProposedAction();
}
     
void FileList::dragMoveEvent(QDragMoveEvent *event)
{
	event->acceptProposedAction();
}
     
void FileList::dropEvent(QDropEvent *event) {
const QMimeData *mimeData = event->mimeData();
if (mimeData->hasUrls()) {
//Insert the URLs and set flags to Qt::ItemIsDragEnabled | Qt::ItemIsDropEnabled | defaultFlags;
}
	event->acceptProposedAction();
}
     
void FileList::dragLeaveEvent(QDragLeaveEvent *event)
{
	event->accept();
}