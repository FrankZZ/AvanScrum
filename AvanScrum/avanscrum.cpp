#include <iostream>
#include <sstream>
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
#include "ProjectBL.h"
#include "WorkItemSorter.h"
#include "BurnDownChart.h"
#include "ui_editSBI.h"
#include "editItemDialog.h"
#include "FileList.h"
#include "aUser.h"

QPushButton *btn_nextSprint, *btn_prevSprint;
QFrame *frm;
ListWidget* listViewStories;
ListWidget* listViewTodo;
ListWidget* listViewVerify;
ListWidget* listViewDoing;
ListWidget* listViewDone;
BurnDownChart* bdc;
QString projectName;
std::vector<Sprint*> sprintVector;
std::vector<WorkItem *> wiVector;
std::vector<Status *> statusVector;
int index;
bool isStartUpCycle = true;
std::string sCurrentProject;

AvanScrum::AvanScrum(QWidget *parent) : QMainWindow(parent)
{
	ui.setupUi(this);
	FileList* fl = new FileList();
	
	// Onderstaande 3 regels is om een project lokaal of op de tfs server te zetten
	//ProjectBL* pb = new ProjectBL();
	//pb->makeRemoteDemoProject();
	//pb->makeLocalDemoProject();
	//pb->~ProjectBL();
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
	listViewStories = ui.list_stories;

	/*
	ListViewSettings(ui.list_todo);
	ListViewSettings(ui.list_doing);
	ListViewSettings(ui.list_verify);
	ListViewSettings(ui.list_done);
	*/
	frm = ui.frame_user1;
	frm->setObjectName("frm");
	frm->setStyleSheet("#frm { border: 3px solid red; }");
	
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
	switchCombo();
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
	int currentRow = list->QListWidget::currentRow();
	
	int workItemNumber = item->data(Qt::UserRole).toInt();

	AvanScrum::Detail detailer;

	wiVector.at(workItemNumber)->accept(detailer);
}

void AvanScrum::dropEvent(QDropEvent* e)
{

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
	sCurrentProject = ui.cb_Projects_3->currentText().toStdString();

	projectName = ui.cb_Projects_3->currentText();
	// Purge transaction before loading next project
	TFSTransaction::removeAllData();

	//Project *p2 = TFSTransaction::localReadProject(sProject.toStdString().c_str());
	Project *p2 = TFSTransaction::remoteReadProject(sProject.toStdString().c_str());
	Sprint *sprint = p2->getSprint(0);
	sprintVector = p2->getSprintArray();
	index = 0;
	ui.lbl_SprintName_3->setText(sprint->getName());
	
	fillUsers();
	
	refresh();
	//SprintSelectionChanged(index);
	
	SprintSelectionChanged(index);
}

void AvanScrum::refresh()
{
	listViewDoing->clear();
	listViewVerify->clear();
	listViewDone->clear();
	listViewTodo->clear();
	listViewStories->clear();
	
	getWorkItem();
}

QString AvanScrum::getProjectName()
{
	return projectName;
}

AvanScrum::func AvanScrum::refreshWorkItems()
{
	return &AvanScrum::refresh;
}

void AvanScrum::getWorkItem()
{
	Sprint *sprint = sprintVector.at(index);
	wiVector = sprint->getWorkItemArray();
	
	AvanScrum::Sort sorter;

	for (int i = 0; i < wiVector.size(); i++)
	{
		if(wiVector.at(i) != NULL)
		{
			wiVector.at(i)->accept(sorter);
		}
	}
}

void AvanScrum::SprintSelectionChanged(int index)
{
	bdc->updateGraphView(sprintVector.at(index));
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
	int counter = 0;
	QString aColors[] = {"brown", "green", "blue", "yellow", "pink", "purple", "orange", "gold"};
	for ( iUser = User::begin(); iUser != User::end(); ++iUser )
	{
		
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
		frame_user->setStyleSheet("#" + sFrameName + " { border: 3px solid " + aColors[counter] + "; }");
        
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
		
		counter++;
	
		// TODO: Per cycle moet de user worden toegevoegd aan de Qt GUI
	}
}

void AvanScrum::Sort::visit(SprintBacklogItem& sbi)
{
	AvanScrum::Sort::ProcessWorkItem(&sbi, sbi.getStatus(0), 0);
}

void AvanScrum::Sort::visit(ProductBacklogItem& pbi)
{
	AvanScrum::Sort::ProcessWorkItem(&pbi, pbi.getStatus(0), 1);
}

void AvanScrum::Sort::visit(Defect& def)
{
	AvanScrum::Sort::ProcessWorkItem(&def, def.getStatus(0), 2);
}

void AvanScrum::Sort::ProcessWorkItem(WorkItem* wi, Status* status, int wiType)
{
	int workItemId = -1;
	for (int i = 0; i < wiVector.size(); i++)
	{
		if (wiVector.at(i) == wi)
		{
			workItemId = i;
		}
	}

	if (wiType == 1)
	{
		listViewStories->addItem(workItemId, wi, wiType);
	}
	else if(status != NULL)
	{
		if(status->getStatusType() != NULL)
		{
			if(status->getStatusType() == StatusType::withName("ToDo"))
			{
				listViewTodo->addItem(workItemId, wi, wiType);
			}
			else if(status->getStatusType() == StatusType::withName("Doing"))
			{
				listViewDoing->addItem(workItemId, wi, wiType);
			}
			else if(status->getStatusType() == StatusType::withName("ToVerify"))
			{
				listViewVerify->addItem(workItemId, wi, wiType);
			}
			else if(status->getStatusType() == StatusType::withName("Done"))
			{
				listViewDone->addItem(workItemId, wi, wiType);
			}
		}
	}
}

void AvanScrum::Detail::visit(SprintBacklogItem& sbi)
{
	//TODO: Uitzoeken wat voor effect de parent op NULL heeft ipv AvanScrumClass (impossibru vanwege subclass?)
	AvanScrum::func f;
	editSBI* dlg = new editSBI(f, NULL);
	dlg->setSBI(&sbi);
	dlg->setProject(Project::withName(sCurrentProject.c_str()));
	/*dlg->setTitle(sbi.getTitle());
	dlg->setID(sbi.getWorkItemNumber());

	//dlg->setPBI(wiVector.at(currentRow)->get

	dlg->setHour(sbi.getRemainingWork());

	QString prio = sbi.getAdditionalInfo();
	int iPrio = prio.toInt();
	dlg->setPrio(iPrio);

	dlg->setContent(sbi.getDescription());
	dlg->setUser(sbi.getUser()->getName());*/
	dlg->fillInItems();
	dlg->setWindowTitle(sbi.getTitle());
	dlg->show();
}

void AvanScrum::Detail::visit(ProductBacklogItem& pbi)
{
	//TODO: Detailscherm pbi tonen
}

void AvanScrum::Detail::visit(Defect& def)
{
	editSBI* dlg = new editSBI(NULL);
	dlg->setTitle(def.getTitle());
	dlg->setID(def.getWorkItemNumber());

	//dlg->setPBI(wiVector.at(currentRow)->get

	//dlg->setHour(sbi.getRemainingWork());

	//dlg->setPrio(wiVector.at(currentRow)->get

	dlg->setContent(def.getDescription());
	dlg->setUser(def.getUser()->getName());
	dlg->fillInItems();
	dlg->setWindowTitle(def.getTitle());
	
	dlg->show();
}