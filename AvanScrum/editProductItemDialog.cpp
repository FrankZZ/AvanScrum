#include "editProductItemDialog.h"


editProductItemDialog::editProductItemDialog(QWidget *parent) : QDialog(parent)
{
	ui.setupUi(this);

	setWindowFlags(Qt::Dialog | Qt::Desktop);
}


editProductItemDialog::~editProductItemDialog(void)
{
}
