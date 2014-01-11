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
#include "BurnDownChart.h"
#include "ui_editSBI.h"
#include "editItemDialog.h"
#include "FileList.h"
#include <sstream>
#include "aUser.h"

QPushButton *btn_nextSprint, *btn_prevSprint;
QFrame *frm;
QListWidget* listViewTodo;
QListWidget* listViewVerify;
QListWidget* listViewDoing;
QListWidget* listViewDone;

BurnDownChart* bdc;
std::vector<Sprint*> sprintVector;
std::vector<WorkItem *> wiVector;
std::vector<Status *> statusVector;
int index;

AvanScrum::AvanScrum(QWidget *parent) : QMainWindow(parent)
{
	ui.setupUi(this);
	FileList* fl = new FileList();
	
	// Onderstaande 3 regels is om een project lokaal of op de tfs server te zetten
	ProjectBL* pb = new ProjectBL();
	//pb->makeRemoteDemoProject();
	pb->makeLocalDemoProject();


    std::list<std::string> saFilenameList;
    std::list<std::string>::iterator iList;
	QStringList *sl = new QStringList();
	QString sFilename;
    int y = 0;

    try
    {
		TFSTransaction::localListProjects(saFilenameList);
		//TFSTransaction::remoteListProjects(saFilenameList);
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
	//bdc->test();
	//SprintSelectionChanged(index);
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
	AvanScrum::Detail* detailer = new AvanScrum::Detail();
	QStringList itemText = item->text().split(' ');
	QString id = itemText[0].replace('#',' ').trimmed();

	for (int i = 0; i < wiVector.size(); i++)
	{
		if(wiVector.at(i) != NULL)
		{
			if(wiVector.at(i)->getTitle() == itemText[1])
			{
				wiVector.at(i)->accept(*detailer);
			}
		}
	}

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
	Project *p2 = TFSTransaction::localReadProject(sProject.toStdString().c_str());
	//Project *p2 = TFSTransaction::remoteReadProject(sProject.toStdString().c_str());
	Sprint *sprint = p2->getSprint(0);
	sprintVector = p2->getSprintArray();
	index = 0;
	ui.lbl_SprintName_3->setText(sprint->getName());
	
	fillUsers();
	
	refresh();
	//SprintSelectionChanged(index);
}

void AvanScrum::refresh()
{
	listViewDoing->clear();
	listViewVerify->clear();
	listViewDone->clear();
	listViewTodo->clear();
	
	getWorkItem();
}

AvanScrum::func AvanScrum::refreshWorkItems()
{
	return &AvanScrum::refresh;
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
	QVector<double> estimatedDate, estimatedHours, realDate, realHours;
	Sprint* sp = sprintVector.at(index);

	//startdate
	QDate beginDate = QDate(sp->getBeginYear(), sp->getBeginMonth(), sp->getBeginDay());
	QDateTime beginDateTime = QDateTime(beginDate);
	double sprintStartDate = beginDateTime.toTime_t();
	estimatedDate.push_back(sprintStartDate);
	realDate.push_back(sprintStartDate);

	//enddate
	QDate endDate = QDate(sp->getEndYear(), sp->getEndMonth(), sp->getEndDay()+1);
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
	AvanScrum::Sort::ProcessWorkItem(sbi, sbi.getStatus(0));
}

void AvanScrum::Sort::visit(ProductBacklogItem& pbi)
{
	AvanScrum::Sort::ProcessWorkItem(pbi, pbi.getStatus(0));
}

void AvanScrum::Sort::visit(Defect& def)
{
	//TODO: Defect heeft geen status bij het laden. ProjectBL.cpp error?
	AvanScrum::Sort::ProcessWorkItem(def, def.getStatus(0));
}

void AvanScrum::Sort::ProcessWorkItem(WorkItem wi, Status* status)
{
	QString gegevens;
	int workItemNumber = wi.getWorkItemNumber();
	QListWidgetItem* item = new QListWidgetItem();
	item->setBackgroundColor(QColor(255,0,0,255));
	item->setSizeHint(QSize(1,50));
	item->setTextColor(QColor(255,255,255,255));
	gegevens.append("#");
	gegevens.append(QString::number(workItemNumber));
	gegevens.append(" ");
	gegevens.append(wi.getTitle());
	gegevens.append(" \n");

	if(wi.getUser() != NULL)
		gegevens.append(wi.getUser()->getName());

	item->setText(gegevens);

	//statusVector = sbi.getStatusArray();

	if(status != NULL)
	{
		if(status->getStatusType() != NULL)
		{
			if(status->getStatusType() == StatusType::withName("ToDo"))
			{
				listViewTodo->addItem(item);
			}
			else if(status->getStatusType() == StatusType::withName("Doing"))
			{
				listViewDoing->addItem(item);
			}
			else if(status->getStatusType() == StatusType::withName("ToVerify"))
			{
				listViewVerify->addItem(item);
			}
			else if(status->getStatusType() == StatusType::withName("Done"))
			{
				listViewDone->addItem(item);
			}
		}
	}
}

void AvanScrum::Detail::visit(SprintBacklogItem& sbi)
{
	//TODO: Uitzoeken wat voor effect de parent op NULL heeft ipv AvanScrumClass (impossibru vanwege subclass?)
	AvanScrum::func f;
	editSBI* dlg = new editSBI(f, NULL);
	dlg->setTitle(sbi.getTitle());
	dlg->setID(sbi.getWorkItemNumber());

	//dlg->setPBI(wiVector.at(currentRow)->get

	dlg->setHour(sbi.getRemainingWork());
	
	QString prio = sbi.getAdditionalInfo();
	int iPrio = prio.toInt();
	dlg->setPrio(iPrio);

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