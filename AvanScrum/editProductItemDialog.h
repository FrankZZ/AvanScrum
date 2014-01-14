#ifndef EDITPRODUCTITEM_H
#define EDITPRODUCTITEM_H

#include "ui_editPBI.h"
#include <QtWidgets\qdialog>

class editProductItemDialog : public QDialog
{
	Q_OBJECT
public:
	editProductItemDialog(QWidget *parent = 0);
	~editProductItemDialog(void);
	
private:
        Ui::PbiDialog ui;
};

#endif

