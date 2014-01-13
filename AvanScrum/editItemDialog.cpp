#include "editItemDialog.h"
#include "TFS/User.h"
#include "aUser.h"

const char* _title, *_content, *_user;
QString *_PBI;
int _ID, _prio, _hour;
User::ItemStorage::iterator iUser;
aUser* u;

editSBI::editSBI(QWidget *parent) : QDialog(parent)
{
    ui.setupUi(this);

	setWindowFlags(Qt::Dialog | Qt::Desktop);
    int y = 0;
	QStringList *sl = new QStringList();

	u = new aUser();
    setHour(-1);
    setPrio(0);
    connect(ui.btn_AddHour, SIGNAL(clicked()), this, SLOT(addHour()));
    connect(ui.btn_ReduceHour, SIGNAL(clicked()), this, SLOT(reduceHour()));
    connect(ui.btn_AddPrio, SIGNAL(clicked()), this, SLOT(addPrio()));
    connect(ui.btn_ReducePrio, SIGNAL(clicked()), this, SLOT(reducePrio()));
	connect(ui.btn_Save, SIGNAL(clicked()), this, SLOT(save()));

	/*iUser = u->getAllUsers();
	for ( iUser = User::begin(); iUser != User::end(); ++iUser )
	{
		QString	userName = iUser->first.c_str();
		sl->insert(y, userName);
		y++;
	}
	ui.cb_users->addItems(*sl);*/
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
    ui.lbl_Title->setText(_title);
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
	//ui.cb_users->setCurrentText(_user);
}

void editSBI::addHour()
{
    setHour(_hour += 1);
    fillInItems();
}

void editSBI::reduceHour()
{
    if(_hour > 0)
		setHour(_hour -= 1);
	fillInItems();
}

void editSBI::addPrio()
{
	setPrio(_prio += 1);
    fillInItems();
}

void editSBI::reducePrio()
{
    if(_prio > 0)
		setPrio(_prio -= 1);
    fillInItems();
}

void editSBI::save()
{
	this->close();
}