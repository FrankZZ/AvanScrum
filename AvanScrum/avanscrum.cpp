#include "avanscrum.h"
#include "qmessagebox.h"
#include <QTextFrameFormat>
#include "TFS\sprint.h"
#include "TFS\TFSTransaction.h"
#include "TFS\Project.h"
#include "TFS\Sprint.h"
#include "TFS\Defect.h"
#include "TFS\SprintBacklogItem.h"
#include "TFS\User.h"
#include "TFS\Status.h"
#include "TFS\StatusType.h"
#include <iostream>
#include "ProjectBL.h"
#include "BurnDownChart.h"
#include "ui_editSBI.h"
#include "editItemDialog.h"
#include "FileList.h"

QPushButton *btn_nextSprint, *btn_prevSprint;
QFrame *frm;
QListWidget* listView;
BurnDownChart* bdc;
std::vector<Sprint*> sprintVector;
std::vector<WorkItem *> wiVector;
std::vector<Status *> statusVector;
WorkItem* selectedWorkItem;
int index;

AvanScrum::AvanScrum(QWidget *parent) : QMainWindow(parent)
{
	ui.setupUi(this);
	FileList* fl = new FileList();
	// Onderstaande 3 regels is om een project lokaal of op de tfs server te zetten
	//ProjectBL* pb = new ProjectBL();
	//pb->makeRemoteDemoProject();
	//pb->makeLocalDemoProject();

	ui.frame_ItemLists;
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
	connect(ui.list_todo, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(listToDoClicked(QListWidgetItem*)));
	connect(ui.list_doing, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(listDoingClicked(QListWidgetItem*)));
	connect(ui.list_verify, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(listVerifyClicked(QListWidgetItem*)));

	connect(ui.list_todo, SIGNAL(itemChanged(QListWidgetItem*)), this, SLOT(listChangedToDo(QListWidgetItem*)));	
	connect(ui.list_done, SIGNAL(itemChanged(QListWidgetItem*)), this, SLOT(listChangedDone(QListWidgetItem*)));
	connect(ui.list_verify, SIGNAL(itemChanged(QListWidgetItem*)), this, SLOT(listChangedVerify(QListWidgetItem*)));
	connect(ui.list_doing, SIGNAL(itemChanged(QListWidgetItem*)), this, SLOT(listChangedDoing(QListWidgetItem*)));
	connect(ui.setNoteDefect, SIGNAL(clicked()), this, SLOT(SetNodeDefect()));
	connect(ui.setNotePB, SIGNAL(clicked()), this, SLOT(SetNodePB()));
	connect(ui.setNoteSB, SIGNAL(clicked()), this, SLOT(SetNodeSB()));

	bdc = new BurnDownChart(ui.widget_Graph);
	//bdc->test();
	SprintSelectionChanged(index);
	
	fillUsers();
}

AvanScrum::~AvanScrum()
{

}
void ShowMessage(QString s)
{
		QMessageBox msgBox;
		msgBox.setText(s);
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.show();
}
void AvanScrum::listChangedToDo(QListWidgetItem* item)
{
	ShowMessage("ToDo");
}
void AvanScrum::listChangedDoing(QListWidgetItem* item)
{
	ShowMessage("Doing");
}
void AvanScrum::listChangedVerify(QListWidgetItem* item)
{
	ShowMessage("Verify");
}
void AvanScrum::listChangedDone(QListWidgetItem* item)
{
	ShowMessage("Done");
}
void AvanScrum::SetNodeDefect()
{

}
void AvanScrum::SetNodePB()
{

}
void AvanScrum::SetNodeSB()
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
	
	selectedWorkItem = wiVector.at(currentRow);
	SprintBacklogItem* sbi = dynamic_cast<SprintBacklogItem *>(wiVector.at(currentRow));
	editSBI* dlg = new editSBI(this);
	dlg->setTitle(wiVector.at(currentRow)->getTitle());
	dlg->setID(wiVector.at(currentRow)->getWorkItemNumber());
	//dlg->setPBI(wiVector.at(currentRow)->get
	dlg->setHour(sbi->getRemainingWork());
	//dlg->setPrio(wiVector.at(currentRow)->get
	dlg->setContent(wiVector.at(currentRow)->getDescription());
	dlg->setUser(wiVector.at(currentRow)->getUser()->getName());
	dlg->fillInItems();
	dlg->setWindowTitle(wiVector.at(currentRow)->getTitle());
	
	dlg->show();
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
	//Project *p2 = TFSTransaction::localReadProject(sProject.toStdString().c_str());
	Project *p2 = TFSTransaction::remoteReadProject(sProject.toStdString().c_str());
	Sprint *sprint = p2->getSprint(0);
	sprintVector = p2->getSprintArray();
	index = 0;
	ui.lbl_SprintName_3->setText(sprint->getName());
	refreshWorkItems();
	//SprintSelectionChanged(index);
}

void AvanScrum::refreshWorkItems()
{
	ui.list_doing->clear();
	ui.list_verify->clear();
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
				Status *s = sbi->getStatus(0);
				statusVector = sbi->getStatusArray();
				item->setText(gegevens);
				item->setSelected(true);

				if(s != NULL)
				{
					if(s->getStatusType() != NULL)
					{
						if(s->getStatusType() == StatusType::withName("ToDo"))
							listView->addItem(item);
						if(s->getStatusType() == StatusType::withName("Doing"))
							ui.list_doing->addItem(item);
						if(s->getStatusType() == StatusType::withName("ToVerify"))
							ui.list_verify->addItem(item);
					}
				}
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

	//NOTE: for loop geeft geen users terug, voor nu even met de hand Maurits erin gezet...

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