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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ListWidget.h"
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_AvanScrumClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QFrame *frame_ItemLists;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_2;
    QLabel *label_5;
    ListWidget *list_stories;
    ListWidget *list_todo;
    ListWidget *list_verify;
    ListWidget *list_done;
    ListWidget *list_doing;
    QFrame *frame_users;
    QHBoxLayout *horizontalLayout;
    QFrame *frame_user1;
    QLabel *name_user1;
    QLabel *title_user1;
    QFrame *frame_Head;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *cb_Projects_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_PreviousSprint_3;
    QSpacerItem *horizontalSpacer_2;
    QLabel *lbl_SprintName_3;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *btn_NextSprint_3;
    QFrame *frame_Log;
    QVBoxLayout *verticalLayout;
    QLabel *label_7;
    QListView *HistoryLogList;
    QPushButton *btn_Undo_3;
    QFrame *frame;
    QGridLayout *gridLayout_3;
    QCustomPlot *widget_Graph;

    void setupUi(QMainWindow *AvanScrumClass)
    {
        if (AvanScrumClass->objectName().isEmpty())
            AvanScrumClass->setObjectName(QStringLiteral("AvanScrumClass"));
        AvanScrumClass->resize(1600, 1100);
        AvanScrumClass->setMouseTracking(false);
        centralWidget = new QWidget(AvanScrumClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        frame_ItemLists = new QFrame(centralWidget);
        frame_ItemLists->setObjectName(QStringLiteral("frame_ItemLists"));
        frame_ItemLists->setMouseTracking(true);
        frame_ItemLists->setFrameShape(QFrame::StyledPanel);
        frame_ItemLists->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_ItemLists);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(frame_ItemLists);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(frame_ItemLists);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 2, 1, 1);

        label_4 = new QLabel(frame_ItemLists);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 0, 3, 1, 1);

        label_2 = new QLabel(frame_ItemLists);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        label_5 = new QLabel(frame_ItemLists);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 0, 4, 1, 1);

        list_stories = new ListWidget(frame_ItemLists);
        list_stories->setObjectName(QStringLiteral("list_stories"));

        gridLayout->addWidget(list_stories, 1, 0, 1, 1);

        list_todo = new ListWidget(frame_ItemLists);
        list_todo->setObjectName(QStringLiteral("list_todo"));
        list_todo->setMouseTracking(false);
        list_todo->setDragEnabled(true);
        list_todo->setDragDropMode(QAbstractItemView::DragDrop);
        list_todo->setDefaultDropAction(Qt::MoveAction);

        gridLayout->addWidget(list_todo, 1, 1, 1, 1);

        list_verify = new ListWidget(frame_ItemLists);
        list_verify->setObjectName(QStringLiteral("list_verify"));
        list_verify->setMouseTracking(true);

        gridLayout->addWidget(list_verify, 1, 3, 1, 1);

        list_done = new ListWidget(frame_ItemLists);
        list_done->setObjectName(QStringLiteral("list_done"));
        list_done->setMouseTracking(true);

        gridLayout->addWidget(list_done, 1, 4, 1, 1);

        list_doing = new ListWidget(frame_ItemLists);
        list_doing->setObjectName(QStringLiteral("list_doing"));
        list_doing->setMouseTracking(true);

        gridLayout->addWidget(list_doing, 1, 2, 1, 1);


        gridLayout_2->addWidget(frame_ItemLists, 1, 0, 1, 1);

        frame_users = new QFrame(centralWidget);
        frame_users->setObjectName(QStringLiteral("frame_users"));
        frame_users->setMinimumSize(QSize(0, 150));
        frame_users->setBaseSize(QSize(0, 150));
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


        gridLayout_2->addWidget(frame_users, 2, 0, 1, 1);

        frame_Head = new QFrame(centralWidget);
        frame_Head->setObjectName(QStringLiteral("frame_Head"));
        frame_Head->setMinimumSize(QSize(0, 50));
        frame_Head->setBaseSize(QSize(0, 50));
        frame_Head->setFrameShape(QFrame::StyledPanel);
        frame_Head->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_Head);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        cb_Projects_3 = new QComboBox(frame_Head);
        cb_Projects_3->setObjectName(QStringLiteral("cb_Projects_3"));
        cb_Projects_3->setMinimumSize(QSize(350, 45));
        cb_Projects_3->setMaximumSize(QSize(250, 16777215));
        QFont font;
        font.setPointSize(12);
        cb_Projects_3->setFont(font);

        horizontalLayout_2->addWidget(cb_Projects_3);

        horizontalSpacer = new QSpacerItem(60, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btn_PreviousSprint_3 = new QPushButton(frame_Head);
        btn_PreviousSprint_3->setObjectName(QStringLiteral("btn_PreviousSprint_3"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btn_PreviousSprint_3->sizePolicy().hasHeightForWidth());
        btn_PreviousSprint_3->setSizePolicy(sizePolicy);
        btn_PreviousSprint_3->setMinimumSize(QSize(45, 45));
        btn_PreviousSprint_3->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_2->addWidget(btn_PreviousSprint_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        lbl_SprintName_3 = new QLabel(frame_Head);
        lbl_SprintName_3->setObjectName(QStringLiteral("lbl_SprintName_3"));
        QFont font1;
        font1.setPointSize(18);
        lbl_SprintName_3->setFont(font1);
        lbl_SprintName_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(lbl_SprintName_3);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_7);

        btn_NextSprint_3 = new QPushButton(frame_Head);
        btn_NextSprint_3->setObjectName(QStringLiteral("btn_NextSprint_3"));
        sizePolicy.setHeightForWidth(btn_NextSprint_3->sizePolicy().hasHeightForWidth());
        btn_NextSprint_3->setSizePolicy(sizePolicy);
        btn_NextSprint_3->setMinimumSize(QSize(45, 45));
        btn_NextSprint_3->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_2->addWidget(btn_NextSprint_3);


        gridLayout_2->addWidget(frame_Head, 0, 0, 1, 1);

        frame_Log = new QFrame(centralWidget);
        frame_Log->setObjectName(QStringLiteral("frame_Log"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame_Log->sizePolicy().hasHeightForWidth());
        frame_Log->setSizePolicy(sizePolicy1);
        frame_Log->setMaximumSize(QSize(450, 16777215));
        frame_Log->setSizeIncrement(QSize(0, 0));
        frame_Log->setBaseSize(QSize(0, 0));
        frame_Log->setFrameShape(QFrame::StyledPanel);
        frame_Log->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame_Log);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        label_7 = new QLabel(frame_Log);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);
        label_7->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_7);

        HistoryLogList = new QListView(frame_Log);
        HistoryLogList->setObjectName(QStringLiteral("HistoryLogList"));
        HistoryLogList->setMinimumSize(QSize(250, 250));
        HistoryLogList->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout->addWidget(HistoryLogList);

        btn_Undo_3 = new QPushButton(frame_Log);
        btn_Undo_3->setObjectName(QStringLiteral("btn_Undo_3"));

        verticalLayout->addWidget(btn_Undo_3);

        frame = new QFrame(frame_Log);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        widget_Graph = new QCustomPlot(frame);
        widget_Graph->setObjectName(QStringLiteral("widget_Graph"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(widget_Graph->sizePolicy().hasHeightForWidth());
        widget_Graph->setSizePolicy(sizePolicy2);
        widget_Graph->setMinimumSize(QSize(250, 250));
        widget_Graph->setMaximumSize(QSize(400, 400));
        widget_Graph->setBaseSize(QSize(0, 0));
        frame->raise();
        btn_Undo_3->raise();
        HistoryLogList->raise();
        label_7->raise();

        gridLayout_3->addWidget(widget_Graph, 0, 0, 1, 1);


        verticalLayout->addWidget(frame);


        gridLayout_2->addWidget(frame_Log, 1, 2, 1, 1);

        AvanScrumClass->setCentralWidget(centralWidget);
        QWidget::setTabOrder(cb_Projects_3, btn_PreviousSprint_3);
        QWidget::setTabOrder(btn_PreviousSprint_3, btn_NextSprint_3);
        QWidget::setTabOrder(btn_NextSprint_3, list_stories);
        QWidget::setTabOrder(list_stories, list_todo);
        QWidget::setTabOrder(list_todo, list_doing);
        QWidget::setTabOrder(list_doing, list_verify);
        QWidget::setTabOrder(list_verify, list_done);
        QWidget::setTabOrder(list_done, HistoryLogList);
        QWidget::setTabOrder(HistoryLogList, btn_Undo_3);

        retranslateUi(AvanScrumClass);

        QMetaObject::connectSlotsByName(AvanScrumClass);
    } // setupUi

    void retranslateUi(QMainWindow *AvanScrumClass)
    {
        AvanScrumClass->setWindowTitle(QApplication::translate("AvanScrumClass", "AvanScrum", 0));
        label->setText(QApplication::translate("AvanScrumClass", "Stories", 0));
        label_3->setText(QApplication::translate("AvanScrumClass", "Doing", 0));
        label_4->setText(QApplication::translate("AvanScrumClass", "To verify", 0));
        label_2->setText(QApplication::translate("AvanScrumClass", "Todo", 0));
        label_5->setText(QApplication::translate("AvanScrumClass", "Done", 0));
        name_user1->setText(QApplication::translate("AvanScrumClass", "F. Wammes", 0));
        title_user1->setText(QApplication::translate("AvanScrumClass", "Lead Developer", 0));
        btn_PreviousSprint_3->setText(QApplication::translate("AvanScrumClass", "<", 0));
        lbl_SprintName_3->setText(QApplication::translate("AvanScrumClass", "Sprint 4", 0));
        btn_NextSprint_3->setText(QApplication::translate("AvanScrumClass", ">", 0));
        label_7->setText(QApplication::translate("AvanScrumClass", "History log", 0));
        btn_Undo_3->setText(QApplication::translate("AvanScrumClass", "Undo", 0));
    } // retranslateUi

};

namespace Ui {
    class AvanScrumClass: public Ui_AvanScrumClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AVANSCRUM_H
