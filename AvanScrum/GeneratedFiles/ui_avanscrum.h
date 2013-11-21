/********************************************************************************
** Form generated from reading UI file 'avanscrum.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AVANSCRUM_H
#define UI_AVANSCRUM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AvanScrumClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *AvanScrumClass)
    {
        if (AvanScrumClass->objectName().isEmpty())
            AvanScrumClass->setObjectName(QStringLiteral("AvanScrumClass"));
        AvanScrumClass->resize(600, 400);
        menuBar = new QMenuBar(AvanScrumClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        AvanScrumClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(AvanScrumClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        AvanScrumClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(AvanScrumClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        AvanScrumClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(AvanScrumClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        AvanScrumClass->setStatusBar(statusBar);

        retranslateUi(AvanScrumClass);

        QMetaObject::connectSlotsByName(AvanScrumClass);
    } // setupUi

    void retranslateUi(QMainWindow *AvanScrumClass)
    {
        AvanScrumClass->setWindowTitle(QApplication::translate("AvanScrumClass", "AvanScrum", 0));
    } // retranslateUi

};

namespace Ui {
    class AvanScrumClass: public Ui_AvanScrumClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AVANSCRUM_H
