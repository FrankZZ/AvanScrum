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

QPushButton *button;

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

	button = ui.btn_NextSprint_3;

	connect(button, SIGNAL(clicked()), this, SLOT(handleButton()));
}

AvanScrum::~AvanScrum()
{
	
}

void AvanScrum::handleButton()
{
	Sprint* sprint = new Sprint();

	//sprint->setName("xxx");

	QMessageBox msgBox;
	msgBox.setText(sprint->getName());
	msgBox.setStandardButtons(QMessageBox::Ok);
	
	msgBox.exec();
}