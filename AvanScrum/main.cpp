#include "avanscrum.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	AvanScrum w;
	w.show();
	return a.exec();
}
