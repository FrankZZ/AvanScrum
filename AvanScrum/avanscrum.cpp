#include "avanscrum.h"
#include "qmessagebox.h";
#include <QTextFrameFormat>
#include "TFS\sprint.h";
#include "TFS\TFSTransaction.h"
#include "TFS\Project.h"
#include "TFS\Sprint.h"
#include "TFS\Defect.h"
#include "TFS\SprintBacklogItem.h"
#include "TFS\User.h"
#include <iostream>
#include "ProjectBL.h"
#include "BurnDownChart.h"
#include "ui_editSBI.h"
#include "editItemDialog.h"

QPushButton *btn_nextSprint, *btn_prevSprint;
QFrame *frm;
QListWidget* listView;
BurnDownChart* bdc;
std::vector<Sprint*> sprintVector;
std::vector<WorkItem *> wiVector;
int index;

AvanScrum::AvanScrum(QWidget *parent) : QMainWindow(parent)
{
	ui.setupUi(this);
	
    std::list<std::string> saFilenameList;
    std::list<std::string>::iterator iList;
	QStringList *sl = new QStringList();
	QString sFilename;
    int y = 0;

    try
    {
        TFSTransaction::remoteListProjects(saFilenameList);
        for (iList = saFilenameList.begin(); iList != saFilenameList.end(); ++iList)
        {
            sFilename = iList->c_str();
			sl->insert(y, sFilename);
            y++;
		}
    }
    catch ( ... )
    {
		QMessageBox msgBox;
		msgBox.setText("Geen verbinding met de server...");
		msgBox.setStandardButtons(QMessageBox::Ok);
    }

	ui.cb_Projects_3->addItems(*sl);
	index = 0;
	listView = ui.list_todo; 
	
	ListViewSettings(ui.list_todo);
	ListViewSettings(ui.list_doing);
	ListViewSettings(ui.list_verify);
	switchCombo();
	frm = ui.frame_user1;
	frm->setObjectName("frm");
	frm->setStyleSheet("#frm { border: 3px solid red; }");
	

	btn_nextSprint = ui.btn_NextSprint_3;
	btn_prevSprint = ui.btn_PreviousSprint_3;

	connect(btn_nextSprint, SIGNAL(clicked()), this, SLOT(nextSprint()));
	connect(btn_prevSprint, SIGNAL(clicked()), this, SLOT(prevSprint()));
	connect(ui.cb_Projects_3,SIGNAL(currentIndexChanged(const QString&)), this,SLOT(switchCombo()));
	connect(ui.list_todo, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(onListToDoItemClicked(QListWidgetItem*)));

	bdc = new BurnDownChart(ui.widget_Graph);
	//bdc->test();
	SprintSelectionChanged(index);
}

AvanScrum::~AvanScrum()
{
	
}

void AvanScrum::onListToDoItemClicked(QListWidgetItem* item)
{
	int currentRow = listView->QListWidget::currentRow();
	//QMessageBox* msg = new QMessageBox(this);
	//msg->setText(wiVector.at(currentRow)->getTitle());
	//msg->show();
	
	editItemDialog* dlg = new editItemDialog(this);
	dlg->setTitle(wiVector.at(currentRow)->getTitle());
	dlg->setID(wiVector.at(currentRow)->getWorkItemNumber());
	//dlg->setPBI(wiVector.at(currentRow)->get
	//dlg->setHour(wiVector.at(currentRow)->
	//dlg->setPrio(wiVector.at(currentRow)->get
	dlg->setContent(wiVector.at(currentRow)->getDescription());
	dlg->setUser(wiVector.at(currentRow)->getUser()->getName());
	dlg->fillInItems();
	dlg->setWindowTitle(wiVector.at(currentRow)->getTitle());
	
	dlg->show();

	/*Ui_Dialog* dlg = new Ui_Dialog();
	dlg->setupUi(new QDialog);
	dlg->lbl_Title->setText(wiVector.at(currentRow)->getTitle());*/


	/*
	if (ui.list_todo->item(0) == item) {
    }*/
}

void AvanScrum::ListViewSettings(QListView *l)
{
	l->setSelectionMode(QAbstractItemView::SingleSelection);
	l->setDragEnabled(true);
	l->setDragDropMode(QAbstractItemView::DragDrop);
	l->viewport()->setAcceptDrops(true);
	l->setDropIndicatorShown(true);
	l->setDefaultDropAction(Qt::DropAction::MoveAction);
	l->setSpacing(4);
	//l->dropEvent(drop());
	//l->addAction(action());
}

void AvanScrum::nextSprint()
{
	index++;
	Sprint *sp = sprintVector.at(index);
	if(sp != NULL)
	{
		ui.lbl_SprintName_3->setText(sp->getName());
		refreshWorkItems();
		SprintSelectionChanged(index);
	}
	else
		index--;

}

void AvanScrum::prevSprint()
{
	if(index > 0)
		index--;
	Sprint *sp = sprintVector.at(index);
	if(sp != NULL)
	{
		ui.lbl_SprintName_3->setText(sp->getName());
		refreshWorkItems();
		SprintSelectionChanged(index);
	}
}
	
void AvanScrum::switchCombo()
{
	QString sProject = ui.cb_Projects_3->currentText();
	Project *p2 = TFSTransaction::remoteReadProject(sProject.toStdString().c_str());
	Sprint *sprint = p2->getSprint(0);
	sprintVector = p2->getSprintArray();
	index = 0;
	ui.lbl_SprintName_3->setText(sprint->getName());
	refreshWorkItems();
}

void AvanScrum::refreshWorkItems()
{
	listView->clear();
	getWorkItem();
}

void AvanScrum::getWorkItem()
{
	Sprint *sprint = sprintVector.at(index);
	wiVector = sprint->getWorkItemArray();
	for (int i = 0; i < wiVector.size(); i++)
	{
		if(wiVector.at(i) != NULL)
		{
			SprintBacklogItem* sbi = dynamic_cast<SprintBacklogItem *>(wiVector.at(i));
			if(sbi != 0)
			{
				QString gegevens;
				int workItemNumber = sbi->getWorkItemNumber();
				QListWidgetItem* item = new QListWidgetItem();
				item->setBackgroundColor(QColor(255,0,0,255));
				item->setSizeHint(QSize(1,50));
				item->setTextColor(QColor(255,255,255,255));
				gegevens.append("#");
				gegevens.append(QString::number(workItemNumber));
				gegevens.append(" ");
				gegevens.append(sbi->getTitle());
				gegevens.append("\n");
				if(sbi->getUser() != NULL)
					gegevens.append(sbi->getUser()->getName());
				item->setText(gegevens);
				item->setSelected(true);
				listView->addItem(item);
			}
		}
	}
}

void AvanScrum::SprintSelectionChanged(int index)
{
	QVector<double> estimatedDate, estimatedHours, realDate, realHours;
	Sprint* sp = sprintVector.at(index);

	//startdate
	QDate beginDate = QDate(sp->getBeginYear(), sp->getBeginMonth(), sp->getBeginDay());
	QDateTime beginDateTime = QDateTime(beginDate);
	double sprintStartDate = beginDateTime.toTime_t();
	estimatedDate.push_back(sprintStartDate);
	realDate.push_back(sprintStartDate);

	//enddate
	QDate endDate = QDate(sp->getEndYear(), sp->getEndMonth(), sp->getEndDay());
	QDateTime endDateTime = QDateTime(endDate);
	double sprintEndDate = endDateTime.toTime_t();
	estimatedDate.push_back(sprintEndDate);
	realDate.push_back(sprintEndDate);

	//estimatedHours
	int daysBetweenFirstAndLast = (sprintEndDate - sprintStartDate) / (60*60*24) + 1;
	double estimatedHours1 = 0;
	QDate tempDate = beginDate;
	for (int i = 0; i < daysBetweenFirstAndLast; i++)
	{
		int test = tempDate.dayOfWeek();
		if (tempDate.dayOfWeek() < 6)
		{
			estimatedHours1 += 8.0;
		}
		tempDate = tempDate.addDays(1);
	}

	double estimatedHours2 = 0;

	estimatedHours.push_back(estimatedHours1);
	estimatedHours.push_back(estimatedHours2);
	realHours.push_back(estimatedHours1);
	realHours.push_back(estimatedHours2);

	bdc->updateGraphView(estimatedDate, estimatedHours, realDate, realHours);
}