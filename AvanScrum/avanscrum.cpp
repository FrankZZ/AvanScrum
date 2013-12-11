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
#include <QStringBuilder>
#include <string>

QPushButton *btn_nextSprint, *btn_prevSprint;
QFrame *frm;
QListWidget* listView;
std::vector<Sprint*> sprintVector;
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

	BurnDownChart* bdc = new BurnDownChart(ui.widget_Graph);
	bdc->test();

	fillUsers();
}

AvanScrum::~AvanScrum()
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
	std::vector<WorkItem *> wiVector = sprint->getWorkItemArray();
	for (int i = 0; i < wiVector.size(); i++)
	{
		if(wiVector.at(i) != NULL)
		{
			QString string;
			QListWidgetItem* item = new QListWidgetItem();
			item->setBackgroundColor(QColor(255,0,0,255));
			item->setSizeHint(QSize(1,50));
			item->setTextColor(QColor(255,255,255,255));
			string.append(wiVector.at(i)->getTitle());
			string.append("\n");
			if(wiVector.at(i)->getUser() != NULL)
				string.append(wiVector.at(i)->getUser()->getName());
			item->setText(string);
			listView->addItem(item);
		}
	}

	/*int size = sizeof(wiVector);
	if(wiVector.at(0) != NULL)
	{

		QString wiName = wiVector.at(0)->getTitle();
		QString wiDescription = wiVector.at(0)->getDescription();
		QString wiNumber = wiVector.at(0)->getWorkItemNumber();
		QString wiUser = wiVector.at(0)->getUser()->getName();
	}*/
}

void AvanScrum::fillUsers()
{
	User::ItemStorage::iterator iUser;

	//NOTE: for loop geeft geen users terug, voor nu even met de hand Maurits erin gezet...

	//for ( iUser = User::begin(); iUser != User::end(); ++iUser )
	//{
		
		int counter = 2;
		
		//std::string sName = iUser->first; // iUser->second is het User object, first is string name
		// TODO: for loop terugzetten en static data eruit
		std::string sName = "Maurits Buijs";


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
	//}
}