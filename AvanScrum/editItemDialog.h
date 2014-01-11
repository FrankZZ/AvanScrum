#ifndef EDITITEM_H
#define EDITITEM_H

#include <QtWidgets\qdialog>
#include "ui_editSBI.h"
#include "avanscrum.h"

class editSBI : public QDialog
{
        Q_OBJECT
public:
                    editSBI(AvanScrum::func, QWidget *parent = 0);
    virtual         ~editSBI(void);

private:
        Ui::Dialog ui;

public:
    void            setTitle(const char*);
    void            setPrio(int);
    void            setHour(int);
    void            setPBI(QString*);
    void            setID(int);
    void            setUser(const char*);
    void            setContent(const char*);
    void            fillInItems();

private slots:
    void			addHour();
    void			reduceHour();
    void			addPrio();
    void			reducePrio();
	void			save();
	void			editTitle();
	void			switchUserCombo();
};

#endif