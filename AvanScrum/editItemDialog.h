#ifndef EDITITEM_H
#define EDITITEM_H

#include <QtWidgets\qdialog>
#include "ui_editWorkItem.h"

class editItemDialog : public QDialog
{
	Q_OBJECT
public:
				editItemDialog(QWidget *parent = 0);
	virtual		~editItemDialog(void);

private:
	Ui::Dialog ui;

public:
	void		setTitle(const char*);
	void		setPrio(int);
	void		setHour(int);
	void		setPBI(QString*);
	void		setID(int);
	void		setUser(const char*);
	void		setContent(const char*);
	void		fillInItems();

private slots:
    void addHour();
    void reduceHour();
    void addPrio();
    void reducePrio();
};

#endif
