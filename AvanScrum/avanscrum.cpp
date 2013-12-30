#include "avanscrum.h"
#include "qmessagebox.h"
#include <QTextFrameFormat>
#include "TFS\sprint.h"
#include "TFS\TFSTransaction.h"
#include "TFS\Project.h"
#include "TFS\Sprint.h"
#include "TFS\Defect.h"
#include "TFS\SprintBacklogItem.h"
#include "TFS\ProductBacklogItem.h"
#include "TFS\User.h"
#include "TFS\Status.h"
#include "TFS\StatusType.h"
#include <iostream>
#include "ProjectBL.h"
#include "WorkItemSorter.h"
#include "BurnDownChart.h"
#include "ui_editSBI.h"
#include "editItemDialog.h"
#include "FileList.h"
#include <sstream>
#include "aUser.h"

QPushButton *btn_nextSprint, *btn_prevSprint;
QFrame *frm;
ListWidget* listViewTodo;
ListWidget* listViewVerify;
ListWidget* listViewDoing;
ListWidget* listViewDone;
BurnDownChart* bdc;
WorkItemSorter* wis;
std::vector<Sprint*> sprintVector;
std::vector<WorkItem *> wiVector;
std::vector<Status *> statuwisector;
int index;
Project* p;

AvanScrum::AvanScrum(QWidget *parent) : QMainWindow(parent)
{
	ui.setupUi(this);
	FileList* fl = new FileList();
	
	// Onderstaande 3 regels is om een project lokaal of op de tfs server te zetten
	//ProjectBL* pb = new ProjectBL();
	//pb->makeRemoteDemoProject();
	//pb->makeLocalDemoProject();

    std::list<std::string> saFilenameList;
    std::list<std::string>::iterator iList;
	QStringList *sl = new QStringList();
	QString sFilename;
    int y = 0;

    try
    {
		//TFSTransaction::localListProjects(saFilenameList);
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
	listViewTodo = ui.list_todo; 
	listViewDoing = ui.list_doing;
	listViewVerify = ui.list_verify;
	listViewDone = ui.list_done;

	ListViewSettings(ui.list_todo);
	ListViewSettings(ui.list_doing);
	ListViewSettings(ui.list_verify);
	ListViewSettings(ui.list_done);
	frm = ui.frame_user1;
	frm->setObjectName("frm");
	frm->setStyleSheet("#frm { border: 3px solid red; }");

	switchCombo();

	btn_nextSprint = ui.btn_NextSprint_3;
	btn_prevSprint = ui.btn_PreviousSprint_3;

	connect(btn_nextSprint, SIGNAL(clicked()), this, SLOT(nextSprint()));
	connect(btn_prevSprint, SIGNAL(clicked()), this, SLOT(prevSprint()));
	connect(ui.cb_Projects_3,SIGNAL(currentIndexChanged(const QString&)), this,SLOT(switchCombo()));
	connect(ui.list_todo, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(listToDoClicked(QListWidgetItem*)));
	connect(ui.list_doing, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(listDoingClicked(QListWidgetItem*)));
	connect(ui.list_verify, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(listVerifyClicked(QListWidgetItem*)));

	bdc = new BurnDownChart(ui.widget_Graph);
	wis = new WorkItemSorter();
	//bdc->test();
	SprintSelectionChanged(index);
}

AvanScrum::~AvanScrum()
{

}

void AvanScrum::listToDoClicked(QListWidgetItem* item)
{
	onListItemClicked(item,ui.list_todo);
}

void AvanScrum::listDoingClicked(QListWidgetItem* item)
{
	onListItemClicked(item,ui.list_doing);
}

void AvanScrum::listVerifyClicked(QListWidgetItem* item)
{
	onListItemClicked(item,ui.list_verify);
}

void AvanScrum::onListItemClicked(QListWidgetItem* item, QListWidget* list)
{
	int currentRow = list->QListWidget::currentRow();

	AvanScrum::Detail* detailer = new AvanScrum::Detail();

	wiVector.at(currentRow)->accept(*detailer);

	delete detailer;
}

void AvanScrum::dropEvent(QDropEvent* e)
{

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
	//p = TFSTransaction::localReadProject(sProject.toStdString().c_str());
	p = TFSTransaction::remoteReadProject(sProject.toStdString().c_str());
	Sprint *sprint = p->getSprint(0);
	sprintVector = p->getSprintArray();
	index = 0;
	ui.lbl_SprintName_3->setText(sprint->getName());
	
	fillUsers();
	
	refreshWorkItems();
	//SprintSelectionChanged(index);
}

void AvanScrum::refreshWorkItems()
{
	listViewDoing->clear();
	listViewVerify->clear();
	listViewDone->clear();
	listViewTodo->clear();
	
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
			AvanScrum::Sort* sorter = new AvanScrum::Sort();

			wiVector.at(i)->accept(*sorter);

			delete sorter;
		}
	}
}

void AvanScrum::SprintSelectionChanged(int index)
{
	//haal de huidige sprint op
	QVector<double> estimatedDate, estimatedHours, realDate, realHours;
	Sprint* sp = sprintVector.at(index);

	//haal de huidige sbi's op
	std::vector<WorkItem*> workItems = sp->getWorkItemArray();
	wis->sort(workItems);
	std::vector<SprintBacklogItem*> sprintBacklogItems = wis->getSprintBacklogItems();

	//startdate project (estimated) OLD
	/*QDate beginDate = QDate(p->getBeginYear(), p->getBeginMonth(), p->getBeginDay());
	QDateTime beginDateTime = QDateTime(beginDate);
	double projectStartDate = beginDateTime.toTime_t();
	estimatedDate.push_back(projectStartDate);*/

	//startdate sprint (estimated)
	/*QDate beginDate = QDate(sp->getBeginYear(), sp->getBeginMonth(), sp->getBeginDay());
	QDateTime beginDateTime = QDateTime(beginDate);
	double sprintStartDate = beginDateTime.toTime_t();
	realDate.push_back(sprintStartDate);

	//startdate sprint (real) OLD
	/*beginDate = QDate(sp->getBeginYear(), sp->getBeginMonth(), sp->getBeginDay());
	beginDateTime = QDateTime(beginDate);
	double sprintStartDate = beginDateTime.toTime_t();
	realDate.push_back(sprintStartDate);*/

	//startdate sbi (real)
	/*beginDate = QDate(sp->getBeginYear(), sp->getBeginMonth(), sp->getBeginDay());
	beginDateTime = QDateTime(beginDate);
	sprintStartDate = beginDateTime.toTime_t();
	realDate.push_back(sprintStartDate);

	//enddate project (estimated)
	QDate endDate = QDate(p->getEndYear(), p->getEndMonth(), p->getEndDay()+1);
	QDateTime endDateTime = QDateTime(endDate);
	double projectEndDate = endDateTime.toTime_t();
	realDate.push_back(projectEndDate);

	//enddate sprint (real)
	endDate = QDate(sp->getEndYear(), sp->getEndMonth(), sp->getEndDay()+1);
	endDateTime = QDateTime(endDate);
	double sprintEndDate = endDateTime.toTime_t();
	realDate.push_back(sprintEndDate);

	//estimatedHours
	int daysBetweenFirstAndLast1 = (sprintEndDate - sprintStartDate) / (60*60*24) + 1;
	double estimatedHours1 = 0;
	QDate tempDate = beginDate;
	for (int i = 0; i < daysBetweenFirstAndLast1; i++)
	{
		int test = tempDate.dayOfWeek();
		if (tempDate.dayOfWeek() < 6)
		{
			estimatedHours1 += 8.0;
		}
		tempDate = tempDate.addDays(1);
	}

	//realHours
	int daysBetweenFirstAndLast2 = (projectEndDate - projectStartDate) / (60*60*24) + 1;
	double estimatedHours2 = 0;
	tempDate = beginDate;
	for (int i = 0; i < daysBetweenFirstAndLast2; i++)
	{
		int test = tempDate.dayOfWeek();
		if (tempDate.dayOfWeek() < 6)
		{
			estimatedHours2 += 8.0;
		}
		tempDate = tempDate.addDays(1);
	}

	estimatedHours.push_back(estimatedHours1);
	estimatedHours.push_back(estimatedHours2);
	realHours.push_back(estimatedHours1);
	realHours.push_back(estimatedHours2);

	bdc->updateGraphView(estimatedDate, estimatedHours, realDate, realHours);*/
}

void AvanScrum::fillUsers()
{
	User::ItemStorage::iterator iUser;
	
	if (ui.horizontalLayout != NULL)
	{
		QLayoutItem* item;

		while ((item = ui.horizontalLayout->takeAt(0)) != NULL )
		{
			delete item->widget();
			delete item;
		}
	}
	
	for ( iUser = User::begin(); iUser != User::end(); ++iUser )
	{
		
		int counter = 2;
		
		std::string sName = iUser->first; // iUser->second is het User object, first is string name
		// TODO: for loop terugzetten en static data eruit
		//std::string sName = "Maurits Buijs";

		QFrame* frame_user;

		frame_user = new QFrame(ui.frame_users);
        QString sFrameName = "frame_user";
		
		sFrameName.append(QString::fromStdString(std::to_string(counter)));
		
		frame_user->setObjectName(sFrameName);
        
		frame_user->setMaximumSize(QSize(120, 80));
        frame_user->setFrameShape(QFrame::StyledPanel);
        frame_user->setFrameShadow(QFrame::Raised);
		
		//TODO: Kleuren automatisch kiezen en koppelen aan user object
		frame_user->setStyleSheet("#" + sFrameName + " { border: 3px solid blue; }");
        
		QLabel* name_user;
		name_user = new QLabel(frame_user);
		name_user->setText(QString::fromStdString(sName));
        //name_user->setObjectName(QStringLiteral("name_user1"));
        name_user->setGeometry(QRect(0, 0, 121, 21));
        name_user->setLayoutDirection(Qt::LeftToRight);
        name_user->setAlignment(Qt::AlignCenter);
        
		QLabel* title_user;
		title_user = new QLabel(frame_user);
        //title_user->setObjectName(QStringLiteral("title_user1"));
		title_user->setText(QString("Developer"));
        title_user->setGeometry(QRect(0, 20, 121, 21));
        title_user->setAlignment(Qt::AlignCenter);

        ui.horizontalLayout->addWidget(frame_user);
		

	
		// TODO: Per cycle moet de user worden toegevoegd aan de Qt GUI
	}
}

void AvanScrum::Sort::visit(SprintBacklogItem& sbi)
{
	AvanScrum::Sort::ProcessWorkItem(&sbi, sbi.getStatus(0));
}

void AvanScrum::Sort::visit(ProductBacklogItem& pbi)
{
	AvanScrum::Sort::ProcessWorkItem(&pbi, pbi.getStatus(0));
}

void AvanScrum::Sort::visit(Defect& def)
{
	//TODO: Defect heeft geen status bij het laden. ProjectBL.cpp error?
	AvanScrum::Sort::ProcessWorkItem(&def, def.getStatus(0));
}

void AvanScrum::Sort::ProcessWorkItem(WorkItem* wi, Status* status)
{
	//statuwisector = sbi.getStatusArray();

	if(status != NULL)
	{
		if(status->getStatusType() != NULL)
		{
			if(status->getStatusType() == StatusType::withName("ToDo"))
			{
				listViewTodo->addItem(wi);
			}
			else if(status->getStatusType() == StatusType::withName("Doing"))
			{
				listViewDoing->addItem(wi);
			}
			else if(status->getStatusType() == StatusType::withName("ToVerify"))
			{
				listViewVerify->addItem(wi);
			}
			else if(status->getStatusType() == StatusType::withName("Done"))
			{
				listViewDone->addItem(wi);
			}
		}
	}
}

void AvanScrum::Detail::visit(SprintBacklogItem& sbi)
{
	//TODO: Uitzoeken wat voor effect de parent op NULL heeft ipv AvanScrumClass (impossibru vanwege subclass?)
	editSBI* dlg = new editSBI(NULL);
	dlg->setTitle(sbi.getTitle());
	dlg->setID(sbi.getWorkItemNumber());

	//dlg->setPBI(wiVector.at(currentRow)->get

	dlg->setHour(sbi.getRemainingWork());

	//dlg->setPrio(wiVector.at(currentRow)->get

	dlg->setContent(sbi.getDescription());
	dlg->setUser(sbi.getUser()->getName());
	dlg->fillInItems();
	dlg->setWindowTitle(sbi.getTitle());
	
	dlg->show();
}

void AvanScrum::Detail::visit(ProductBacklogItem& pbi)
{

}

void AvanScrum::Detail::visit(Defect& def)
{

}