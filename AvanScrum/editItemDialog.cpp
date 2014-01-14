#include "editItemDialog.h"
#include "TFS/User.h"
#include "aUser.h"
#include "ProjectBL.h"

const char* _title, *_content;
std::string _user;
QString *_PBI;
int _ID, _prio, _hour;
User::ItemStorage::iterator iUser;
aUser* u;
void* _refresh;
SprintBacklogItem* _sbi;
Project* _pro;

editSBI::editSBI(AvanScrum::func refresh, QWidget *parent) : QDialog(parent)
{

    ui.setupUi(this);

	_refresh = &refresh;

	setWindowFlags(Qt::Dialog | Qt::Desktop);
    int y = 0;
	QStringList *sl = new QStringList();

    setHour(-1);
    setPrio(0);
    connect(ui.btn_AddHour, SIGNAL(clicked()), this, SLOT(addHour()));
    connect(ui.btn_ReduceHour, SIGNAL(clicked()), this, SLOT(reduceHour()));
    connect(ui.btn_AddPrio, SIGNAL(clicked()), this, SLOT(addPrio()));
    connect(ui.btn_ReducePrio, SIGNAL(clicked()), this, SLOT(reducePrio()));
	connect(ui.btn_Save, SIGNAL(clicked()), this, SLOT(save()));
	connect(ui.btn_EditTitle, SIGNAL(clicked()), this, SLOT(editTitle()));
	connect(ui.cb_users,SIGNAL(currentIndexChanged(const QString&)), this,SLOT(switchUserCombo()));

	iUser = u->getAllUsers();
	for ( iUser = User::begin(); iUser != User::end(); ++iUser )
	{
		QString	userName = iUser->first.c_str();
		sl->insert(y, userName);
		y++;
	}
	ui.cb_users->addItems(*sl);
}


editSBI::~editSBI(void)
{
}

void editSBI::setTitle(const char* title)
{
	_title = title;
}

void editSBI::setPBI(QString* PBI)
{
    _PBI = PBI;
}

void editSBI::setContent(const char* content)
{
    _content = content;
}

void editSBI::setUser(const char* user)
{
    _user = user;
}

void editSBI::setID(int ID)
{
    _ID = ID;
}

void editSBI::setPrio(int prio)
{
    _prio = prio;
}

void editSBI::setHour(int hour)
{
	_hour = hour;
}

void editSBI::fillInItems()
{
	ui.lbl_Title->setText(_sbi->getTitle());
	//number.append();
    ui.lbl_Number->setText("#" + QString::number(_ID));
    ui.txt_Description->setText(_content);
    ui.txt_Prio->setText(QString::number(_prio));
	
	if (_hour == -1)
	{
		ui.txt_Hour->setDisabled(true);
		ui.btn_AddHour->setDisabled(true);
		ui.btn_ReduceHour->setDisabled(true);
	}
	else
	{
		ui.txt_Hour->setText(QString::number(_hour));
	}

	ui.cb_users->setCurrentIndex(ui.cb_users->findText(_user));
}

void editSBI::addHour()
{
    setHour(_hour += 1);
    fillInItems();
	_sbi->setRemainingWork(_hour);
}

void editSBI::reduceHour()
{
    if(_hour > 0)
		setHour(_hour -= 1);
	fillInItems();
	_sbi->setRemainingWork(_hour);
}

void editSBI::addPrio()
{
	setPrio(_prio += 1);
    fillInItems();
	//_sbi->setAdditionalInfo(_prio);
}

void editSBI::reducePrio()
{
    if(_prio > 0)
		setPrio(_prio -= 1);
    fillInItems();
	//_sbi->setAdditionalInfo(_prio);
}

void editSBI::save()
{
	_sbi->setRemainingWork(_hour);
	ProjectBL* pbl = new ProjectBL();
	//pbl->saveLocalSBI(_sbi);
	//pbl->saveLocalSBI("Project Groep E", 0 , 0,_title,_content,_user.c_str(),_ID,_prio,_hour);
	AvanScrum::func f;
	AvanScrum *c;

	f = c->refreshWorkItems();
	(c->*f)();

	this->close();
}

void editSBI::switchUserCombo()
{
	QString user = ui.cb_users->currentText();
	std::string userstd = user.toStdString();
	const char *userchar = userstd.c_str();
	//_sbi->setUser(User::withName(userchar));
	setUser(userchar);
}

void editSBI::editTitle()
{
	setTitle("TestTitle");
	_sbi->setTitle("TestTitle");
	fillInItems();
}

void editSBI::setSBI(SprintBacklogItem* sbi)
{
	_sbi = sbi;
	setHour(sbi->getRemainingWork());
	setUser(sbi->getUser()->getName());
	setContent(sbi->getDescription());
	setID(sbi->getWorkItemNumber());
	setTitle(sbi->getTitle());
	
	QString prio = sbi->getAdditionalInfo();
	int iPrio = prio.toInt();
	setPrio(iPrio);

}

void editSBI::setProject(Project* pro)
{
	_pro = pro;
}