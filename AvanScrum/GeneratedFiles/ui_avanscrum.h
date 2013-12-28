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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "ListWidget.h"
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_AvanScrumClass
{
public:
    QWidget *centralWidget;
    QFrame *frame_Log;
    QListView *HistoryLogList;
    QPushButton *btn_Undo_3;
    QLabel *label_7;
    QFrame *frame_items;
    QPushButton *setNoteDefect;
    QPushButton *setNotePB;
    QPushButton *setNoteSB;
    QCustomPlot *widget_Graph;
    QFrame *frame_users;
    QHBoxLayout *horizontalLayout;
    QFrame *frame_user1;
    QLabel *name_user1;
    QLabel *title_user1;
    QFrame *frame_Head;
    QPushButton *btn_PreviousSprint_3;
    QPushButton *btn_NextSprint_3;
    QLabel *lbl_SprintName_3;
    QComboBox *cb_Projects_3;
    QFrame *frame_ItemLists;
    ListWidget *list_stories;
    ListWidget *list_todo;
    ListWidget *list_doing;
    ListWidget *list_verify;
    ListWidget *list_done;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *AvanScrumClass)
    {
        if (AvanScrumClass->objectName().isEmpty())
            AvanScrumClass->setObjectName(QStringLiteral("AvanScrumClass"));
        AvanScrumClass->resize(1102, 625);
        centralWidget = new QWidget(AvanScrumClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        frame_Log = new QFrame(centralWidget);
        frame_Log->setObjectName(QStringLiteral("frame_Log"));
        frame_Log->setGeometry(QRect(820, 50, 281, 291));
        frame_Log->setFrameShape(QFrame::StyledPanel);
        frame_Log->setFrameShadow(QFrame::Raised);
        HistoryLogList = new QListView(frame_Log);
        HistoryLogList->setObjectName(QStringLiteral("HistoryLogList"));
        HistoryLogList->setGeometry(QRect(0, 30, 281, 211));
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
        frame_items->setGeometry(QRect(0, 420, 120, 161));
        frame_items->setFrameShape(QFrame::StyledPanel);
        frame_items->setFrameShadow(QFrame::Raised);
        setNoteDefect = new QPushButton(frame_items);
        setNoteDefect->setObjectName(QStringLiteral("setNoteDefect"));
        setNoteDefect->setGeometry(QRect(10, 20, 111, 28));
        setNotePB = new QPushButton(frame_items);
        setNotePB->setObjectName(QStringLiteral("setNotePB"));
        setNotePB->setGeometry(QRect(10, 50, 111, 28));
        setNoteSB = new QPushButton(frame_items);
        setNoteSB->setObjectName(QStringLiteral("setNoteSB"));
        setNoteSB->setGeometry(QRect(10, 80, 111, 28));
        widget_Graph = new QCustomPlot(centralWidget);
        widget_Graph->setObjectName(QStringLiteral("widget_Graph"));
        widget_Graph->setGeometry(QRect(820, 340, 281, 251));
        frame_users = new QFrame(centralWidget);
        frame_users->setObjectName(QStringLiteral("frame_users"));
        frame_users->setGeometry(QRect(120, 430, 691, 141));
        frame_users->setLayoutDirection(Qt::LeftToRight);
        frame_users->setFrameShape(QFrame::StyledPanel);
        frame_users->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame_users);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        frame_user1 = new QFrame(frame_users);
        frame_user1->setObjectName(QStringLiteral("frame_user1"));
        frame_user1->setMaximumSize(QSize(120, 80));
        frame_user1->setFrameShape(QFrame::StyledPanel);
        frame_user1->setFrameShadow(QFrame::Raised);
        name_user1 = new QLabel(frame_user1);
        name_user1->setObjectName(QStringLiteral("name_user1"));
        name_user1->setGeometry(QRect(0, 0, 121, 21));
        name_user1->setLayoutDirection(Qt::LeftToRight);
        name_user1->setAlignment(Qt::AlignCenter);
        title_user1 = new QLabel(frame_user1);
        title_user1->setObjectName(QStringLiteral("title_user1"));
        title_user1->setGeometry(QRect(0, 20, 121, 21));
        title_user1->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(frame_user1);

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
        cb_Projects_3->setGeometry(QRect(10, 10, 301, 31));
        cb_Projects_3->setFont(font);
        frame_ItemLists = new QFrame(centralWidget);
        frame_ItemLists->setObjectName(QStringLiteral("frame_ItemLists"));
        frame_ItemLists->setGeometry(QRect(0, 50, 821, 381));
        frame_ItemLists->setFrameShape(QFrame::StyledPanel);
        frame_ItemLists->setFrameShadow(QFrame::Raised);
        list_stories = new ListWidget(frame_ItemLists);
        list_stories->setObjectName(QStringLiteral("list_stories"));
        list_stories->setGeometry(QRect(0, 20, 151, 361));
        list_todo = new ListWidget(frame_ItemLists);
        list_todo->setObjectName(QStringLiteral("list_todo"));
        list_todo->setGeometry(QRect(160, 20, 151, 361));
        list_doing = new ListWidget(frame_ItemLists);
        list_doing->setObjectName(QStringLiteral("list_doing"));
        list_doing->setGeometry(QRect(320, 20, 151, 361));
        list_verify = new ListWidget(frame_ItemLists);
        list_verify->setObjectName(QStringLiteral("list_verify"));
        list_verify->setGeometry(QRect(480, 20, 151, 361));
        list_done = new ListWidget(frame_ItemLists);
        list_done->setObjectName(QStringLiteral("list_done"));
        list_done->setGeometry(QRect(640, 20, 151, 361));
        label = new QLabel(frame_ItemLists);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 0, 151, 20));
        label_2 = new QLabel(frame_ItemLists);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(170, 0, 141, 16));
        label_3 = new QLabel(frame_ItemLists);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(340, 0, 141, 16));
        label_4 = new QLabel(frame_ItemLists);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(490, 0, 141, 16));
        label_5 = new QLabel(frame_ItemLists);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(650, 0, 141, 16));
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
        btn_Undo_3->setText(QApplication::translate("AvanScrumClass", "Undo", 0));
        label_7->setText(QApplication::translate("AvanScrumClass", "History log", 0));
        setNoteDefect->setText(QApplication::translate("AvanScrumClass", "Defect", 0));
        setNotePB->setText(QApplication::translate("AvanScrumClass", "Product Backlog", 0));
        setNoteSB->setText(QApplication::translate("AvanScrumClass", "Sprint Backlog", 0));
        name_user1->setText(QApplication::translate("AvanScrumClass", "F. Wammes", 0));
        title_user1->setText(QApplication::translate("AvanScrumClass", "Lead Developer", 0));
        btn_PreviousSprint_3->setText(QApplication::translate("AvanScrumClass", "<", 0));
        btn_NextSprint_3->setText(QApplication::translate("AvanScrumClass", ">", 0));
        lbl_SprintName_3->setText(QApplication::translate("AvanScrumClass", "Sprint 4", 0));
        label->setText(QApplication::translate("AvanScrumClass", "Stories", 0));
        label_2->setText(QApplication::translate("AvanScrumClass", "Todo", 0));
        label_3->setText(QApplication::translate("AvanScrumClass", "Doing", 0));
        label_4->setText(QApplication::translate("AvanScrumClass", "To verify", 0));
        label_5->setText(QApplication::translate("AvanScrumClass", "Done", 0));
    } // retranslateUi

};

namespace Ui {
    class AvanScrumClass: public Ui_AvanScrumClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AVANSCRUM_H
