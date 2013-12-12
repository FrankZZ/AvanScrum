#include "editItemDialog.h"

const char* _title, *_content, *_user;
QString *_PBI;
int _ID, _prio, _hour;

editItemDialog::editItemDialog(QWidget *parent) : QDialog(parent)
{
        ui.setupUi(this);

        setHour(0);
        setPrio(0);
        connect(ui.btn_AddHour, SIGNAL(clicked()), this, SLOT(addHour()));
        connect(ui.btn_ReduceHour, SIGNAL(clicked()), this, SLOT(reduceHour()));
        connect(ui.btn_AddPrio, SIGNAL(clicked()), this, SLOT(addPrio()));
        connect(ui.btn_ReducePrio, SIGNAL(clicked()), this, SLOT(reducePrio()));
}


editItemDialog::~editItemDialog(void)
{
}

void editItemDialog::setTitle(const char* title)
{
        _title = title;
}

void editItemDialog::setPBI(QString* PBI)
{
        _PBI = PBI;
}

void editItemDialog::setContent(const char* content)
{
        _content = content;
}

void editItemDialog::setUser(const char* user)
{
        _user = user;
}

void editItemDialog::setID(int ID)
{
        _ID = ID;
}

void editItemDialog::setPrio(int prio)
{
        _prio = prio;
}

void editItemDialog::setHour(int hour)
{
        _hour = hour;
}

void editItemDialog::fillInItems()
{
        ui.lbl_Title->setText(_title);
        ui.lbl_Number->setText("#" + QString::number(_ID));
        ui.txt_Description->setText(_content);
        ui.txt_Prio->setText(QString::number(_prio));
		ui.txt_Hour->setText(QString::number(_hour));
}

void editItemDialog::addHour()
{
        _hour++;
        fillInItems();
}

void editItemDialog::reduceHour()
{
        if(_hour > 0)
			_hour--;
        fillInItems();
}

void editItemDialog::addPrio()
{
        _prio++;
        fillInItems();
}

void editItemDialog::reducePrio()
{
        if(_prio > 0)
            _prio--;
        fillInItems();
}