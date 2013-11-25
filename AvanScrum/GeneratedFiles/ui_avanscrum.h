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
#include <QtWidgets/QColumnView>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AvanScrumClass
{
public:
    QWidget *centralWidget;
    QFrame *frame_Log;
    QListView *list_LogItems_3;
    QPushButton *btn_Undo_3;
    QLabel *label_7;
    QFrame *frame_items;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QFrame *frame_Graph;
    QFrame *frame_users;
    QWidget *widget_3;
    QLabel *label_8;
    QLabel *label_9;
    QFrame *frame_Head;
    QPushButton *btn_PreviousSprint_3;
    QPushButton *btn_NextSprint_3;
    QLabel *lbl_SprintName_3;
    QComboBox *cb_Projects_3;
    QFrame *frame_ItemLists;
    QColumnView *column_SprintStatus_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *AvanScrumClass)
    {
        if (AvanScrumClass->objectName().isEmpty())
            AvanScrumClass->setObjectName(QStringLiteral("AvanScrumClass"));
        AvanScrumClass->resize(1102, 642);
        centralWidget = new QWidget(AvanScrumClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        frame_Log = new QFrame(centralWidget);
        frame_Log->setObjectName(QStringLiteral("frame_Log"));
        frame_Log->setGeometry(QRect(820, 50, 281, 291));
        frame_Log->setFrameShape(QFrame::StyledPanel);
        frame_Log->setFrameShadow(QFrame::Raised);
        list_LogItems_3 = new QListView(frame_Log);
        list_LogItems_3->setObjectName(QStringLiteral("list_LogItems_3"));
        list_LogItems_3->setGeometry(QRect(0, 30, 281, 211));
        btn_Undo_3 = new QPushButton(frame_Log);
        btn_Undo_3->setObjectName(QStringLiteral("btn_Undo_3"));
        btn_Undo_3->setGeometry(QRect(10, 250, 261, 31));
        label_7 = new QLabel(frame_Log);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(0, -1, 281, 31));
        QFont font;
        font.setPointSize(12);
        label_7->setFont(font);
        label_7->setAlignment(Qt::AlignCenter);
        frame_items = new QFrame(centralWidget);
        frame_items->setObjectName(QStringLiteral("frame_items"));
        frame_items->setGeometry(QRect(0, 430, 120, 161));
        frame_items->setFrameShape(QFrame::StyledPanel);
        frame_items->setFrameShadow(QFrame::Raised);
        pushButton_7 = new QPushButton(frame_items);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(0, 30, 111, 28));
        pushButton_8 = new QPushButton(frame_items);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(0, 70, 111, 28));
        pushButton_9 = new QPushButton(frame_items);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(0, 110, 111, 28));
        frame_Graph = new QFrame(centralWidget);
        frame_Graph->setObjectName(QStringLiteral("frame_Graph"));
        frame_Graph->setGeometry(QRect(820, 340, 281, 251));
        frame_Graph->setFrameShape(QFrame::StyledPanel);
        frame_Graph->setFrameShadow(QFrame::Raised);
        frame_users = new QFrame(centralWidget);
        frame_users->setObjectName(QStringLiteral("frame_users"));
        frame_users->setGeometry(QRect(120, 430, 701, 161));
        frame_users->setFrameShape(QFrame::StyledPanel);
        frame_users->setFrameShadow(QFrame::Raised);
        widget_3 = new QWidget(frame_users);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setGeometry(QRect(20, 80, 120, 80));
        label_8 = new QLabel(widget_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(0, 0, 121, 21));
        label_9 = new QLabel(widget_3);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(0, 20, 121, 21));
        frame_Head = new QFrame(centralWidget);
        frame_Head->setObjectName(QStringLiteral("frame_Head"));
        frame_Head->setGeometry(QRect(0, 0, 1101, 51));
        frame_Head->setFrameShape(QFrame::StyledPanel);
        frame_Head->setFrameShadow(QFrame::Raised);
        btn_PreviousSprint_3 = new QPushButton(frame_Head);
        btn_PreviousSprint_3->setObjectName(QStringLiteral("btn_PreviousSprint_3"));
        btn_PreviousSprint_3->setGeometry(QRect(400, 10, 31, 31));
        btn_NextSprint_3 = new QPushButton(frame_Head);
        btn_NextSprint_3->setObjectName(QStringLiteral("btn_NextSprint_3"));
        btn_NextSprint_3->setGeometry(QRect(900, 10, 31, 31));
        lbl_SprintName_3 = new QLabel(frame_Head);
        lbl_SprintName_3->setObjectName(QStringLiteral("lbl_SprintName_3"));
        lbl_SprintName_3->setGeometry(QRect(430, 1, 471, 41));
        QFont font1;
        font1.setPointSize(18);
        lbl_SprintName_3->setFont(font1);
        lbl_SprintName_3->setAlignment(Qt::AlignCenter);
        cb_Projects_3 = new QComboBox(frame_Head);
        cb_Projects_3->setObjectName(QStringLiteral("cb_Projects_3"));
        cb_Projects_3->setGeometry(QRect(10, 10, 251, 31));
        cb_Projects_3->setFont(font);
        frame_ItemLists = new QFrame(centralWidget);
        frame_ItemLists->setObjectName(QStringLiteral("frame_ItemLists"));
        frame_ItemLists->setGeometry(QRect(0, 50, 821, 381));
        frame_ItemLists->setFrameShape(QFrame::StyledPanel);
        frame_ItemLists->setFrameShadow(QFrame::Raised);
        column_SprintStatus_3 = new QColumnView(frame_ItemLists);
        column_SprintStatus_3->setObjectName(QStringLiteral("column_SprintStatus_3"));
        column_SprintStatus_3->setGeometry(QRect(0, 0, 821, 381));
        AvanScrumClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(AvanScrumClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1102, 26));
        AvanScrumClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(AvanScrumClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        AvanScrumClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(AvanScrumClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        AvanScrumClass->setStatusBar(statusBar);

        retranslateUi(AvanScrumClass);

        QMetaObject::connectSlotsByName(AvanScrumClass);
    } // setupUi

    void retranslateUi(QMainWindow *AvanScrumClass)
    {
        AvanScrumClass->setWindowTitle(QApplication::translate("AvanScrumClass", "AvanScrum", 0));
        btn_Undo_3->setText(QApplication::translate("AvanScrumClass", "undo", 0));
        label_7->setText(QApplication::translate("AvanScrumClass", "history log", 0));
        pushButton_7->setText(QApplication::translate("AvanScrumClass", "defect", 0));
        pushButton_8->setText(QApplication::translate("AvanScrumClass", "product backlog", 0));
        pushButton_9->setText(QApplication::translate("AvanScrumClass", "sprint backlog", 0));
        label_8->setText(QApplication::translate("AvanScrumClass", "F. Wammes", 0));
        label_9->setText(QApplication::translate("AvanScrumClass", "Lead Programer", 0));
        btn_PreviousSprint_3->setText(QApplication::translate("AvanScrumClass", "<", 0));
        btn_NextSprint_3->setText(QApplication::translate("AvanScrumClass", ">", 0));
        lbl_SprintName_3->setText(QApplication::translate("AvanScrumClass", "sprint 4", 0));
    } // retranslateUi

};

namespace Ui {
    class AvanScrumClass: public Ui_AvanScrumClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AVANSCRUM_H
