#ifndef EDITITEM_H
#define EDITITEM_H

#include "ui_editSBI.h"
#include <QtWidgets\qdialog>

class editSBI : public QDialog
{
        Q_OBJECT
public:
                    editSBI(QWidget *parent = 0);
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
};

#endif