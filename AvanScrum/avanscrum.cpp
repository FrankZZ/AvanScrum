#include "avanscrum.h"
#include "qmessagebox.h";
#include "TFS\sprint.h";
#include <iostream>
#include "TFS\TFSTransaction.h"
#include "TFS\Project.h"
#include "TFS\Sprint.h"
#include "TFS\Defect.h"
#include "TFS\SprintBacklogItem.h"
#include "TFS\User.h"

QPushButton *btn_nextSprint, *btn_prevSprint;
std::vector<Sprint*> sprintVector;
int index;

AvanScrum::AvanScrum(QWidget *parent) : QMainWindow(parent)
{
	ui.setupUi(this);
	
    std::list<std::string> saFilenameList;
	std::vector<std::string> sprintList;
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
	switchCombo();

	btn_nextSprint = ui.btn_NextSprint_3;
	btn_prevSprint = ui.btn_PreviousSprint_3;

	connect(btn_nextSprint, SIGNAL(clicked()), this, SLOT(nextSprint()));
	connect(btn_prevSprint, SIGNAL(clicked()), this, SLOT(prevSprint()));
	connect(ui.cb_Projects_3,SIGNAL(currentIndexChanged(const QString&)), this,SLOT(switchCombo()));
}

AvanScrum::~AvanScrum()
{
	
}

void AvanScrum::nextSprint()
{
	int sprintCount = sprintVector.size();
	if(sprintCount >= index)
		index++;
	Sprint *sp = sprintVector.at(index);
	ui.lbl_SprintName_3->setText(sp->getName());
}

void AvanScrum::prevSprint()
{
	if(index > 0)
		index--;
	Sprint *sp = sprintVector.at(index);
	ui.lbl_SprintName_3->setText(sp->getName());
}
	
void AvanScrum::switchCombo()
{
	QString sProject = ui.cb_Projects_3->currentText();
	Project *p2 = TFSTransaction::remoteReadProject(sProject.toStdString().c_str());
	Sprint *sprint = p2->getSprint(0);
	sprintVector = p2->getSprintArray();
	index = 0;
	ui.lbl_SprintName_3->setText(sprint->getName());
}