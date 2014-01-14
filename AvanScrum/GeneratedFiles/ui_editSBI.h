/********************************************************************************
** Form generated from reading UI file 'editSBI.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITSBI_H
#define UI_EDITSBI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QHBoxLayout *horizontalLayout_5;
    QFrame *frame_5;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lbl_Number;
    QLabel *lbl_Title;
    QPushButton *btn_EditTitle;
    QTextBrowser *txt_Description;
    QFrame *frame_6;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_EditDescription;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout;
    QLabel *lbl_WijzigTitle_2;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_ReducePrio;
    QLineEdit *txt_Prio;
    QPushButton *btn_AddPrio;
    QLabel *lbl_WijzigTitle_3;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btn_ReduceHour;
    QLineEdit *txt_Hour;
    QPushButton *btn_AddHour;
    QLabel *lbl_WijzigTitle_4;
    QTextBrowser *textBrowser_2;
    QLabel *lbl_WijzigTitle_5;
    QComboBox *cb_users;
    QPushButton *btn_Save;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(1200, 800);
        horizontalLayout_5 = new QHBoxLayout(Dialog);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        frame_5 = new QFrame(Dialog);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_5);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        frame_4 = new QFrame(frame_5);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_4);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        lbl_Number = new QLabel(frame_4);
        lbl_Number->setObjectName(QStringLiteral("lbl_Number"));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        lbl_Number->setFont(font);

        horizontalLayout_3->addWidget(lbl_Number);

        lbl_Title = new QLabel(frame_4);
        lbl_Title->setObjectName(QStringLiteral("lbl_Title"));
        lbl_Title->setFont(font);

        horizontalLayout_3->addWidget(lbl_Title);

        btn_EditTitle = new QPushButton(frame_4);
        btn_EditTitle->setObjectName(QStringLiteral("btn_EditTitle"));

        horizontalLayout_3->addWidget(btn_EditTitle);


        verticalLayout_2->addWidget(frame_4);

        txt_Description = new QTextBrowser(frame_5);
        txt_Description->setObjectName(QStringLiteral("txt_Description"));

        verticalLayout_2->addWidget(txt_Description);

        frame_6 = new QFrame(frame_5);
        frame_6->setObjectName(QStringLiteral("frame_6"));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(frame_6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        btn_EditDescription = new QPushButton(frame_6);
        btn_EditDescription->setObjectName(QStringLiteral("btn_EditDescription"));

        horizontalLayout_4->addWidget(btn_EditDescription);


        verticalLayout_2->addWidget(frame_6);


        horizontalLayout_5->addWidget(frame_5);

        frame_3 = new QFrame(Dialog);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setMaximumSize(QSize(300, 16777215));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame_3);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lbl_WijzigTitle_2 = new QLabel(frame_3);
        lbl_WijzigTitle_2->setObjectName(QStringLiteral("lbl_WijzigTitle_2"));
        QFont font1;
        font1.setPointSize(14);
        lbl_WijzigTitle_2->setFont(font1);

        verticalLayout->addWidget(lbl_WijzigTitle_2);

        frame = new QFrame(frame_3);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btn_ReducePrio = new QPushButton(frame);
        btn_ReducePrio->setObjectName(QStringLiteral("btn_ReducePrio"));
        btn_ReducePrio->setFont(font1);

        horizontalLayout->addWidget(btn_ReducePrio);

        txt_Prio = new QLineEdit(frame);
        txt_Prio->setObjectName(QStringLiteral("txt_Prio"));
        txt_Prio->setFont(font1);

        horizontalLayout->addWidget(txt_Prio);

        btn_AddPrio = new QPushButton(frame);
        btn_AddPrio->setObjectName(QStringLiteral("btn_AddPrio"));
        btn_AddPrio->setFont(font1);

        horizontalLayout->addWidget(btn_AddPrio);


        verticalLayout->addWidget(frame);

        lbl_WijzigTitle_3 = new QLabel(frame_3);
        lbl_WijzigTitle_3->setObjectName(QStringLiteral("lbl_WijzigTitle_3"));
        lbl_WijzigTitle_3->setFont(font1);

        verticalLayout->addWidget(lbl_WijzigTitle_3);

        frame_2 = new QFrame(frame_3);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        btn_ReduceHour = new QPushButton(frame_2);
        btn_ReduceHour->setObjectName(QStringLiteral("btn_ReduceHour"));
        btn_ReduceHour->setFont(font1);

        horizontalLayout_2->addWidget(btn_ReduceHour);

        txt_Hour = new QLineEdit(frame_2);
        txt_Hour->setObjectName(QStringLiteral("txt_Hour"));
        txt_Hour->setFont(font1);

        horizontalLayout_2->addWidget(txt_Hour);

        btn_AddHour = new QPushButton(frame_2);
        btn_AddHour->setObjectName(QStringLiteral("btn_AddHour"));
        btn_AddHour->setFont(font1);

        horizontalLayout_2->addWidget(btn_AddHour);


        verticalLayout->addWidget(frame_2);

        lbl_WijzigTitle_4 = new QLabel(frame_3);
        lbl_WijzigTitle_4->setObjectName(QStringLiteral("lbl_WijzigTitle_4"));
        lbl_WijzigTitle_4->setFont(font1);

        verticalLayout->addWidget(lbl_WijzigTitle_4);

        textBrowser_2 = new QTextBrowser(frame_3);
        textBrowser_2->setObjectName(QStringLiteral("textBrowser_2"));
        textBrowser_2->setFont(font1);

        verticalLayout->addWidget(textBrowser_2);

        lbl_WijzigTitle_5 = new QLabel(frame_3);
        lbl_WijzigTitle_5->setObjectName(QStringLiteral("lbl_WijzigTitle_5"));
        lbl_WijzigTitle_5->setFont(font1);

        verticalLayout->addWidget(lbl_WijzigTitle_5);

        cb_users = new QComboBox(frame_3);
        cb_users->setObjectName(QStringLiteral("cb_users"));
        cb_users->setFont(font1);

        verticalLayout->addWidget(cb_users);

        btn_Save = new QPushButton(frame_3);
        btn_Save->setObjectName(QStringLiteral("btn_Save"));
        btn_Save->setFont(font1);

        verticalLayout->addWidget(btn_Save);


        horizontalLayout_5->addWidget(frame_3);

        QWidget::setTabOrder(txt_Description, btn_EditTitle);
        QWidget::setTabOrder(btn_EditTitle, btn_ReducePrio);
        QWidget::setTabOrder(btn_ReducePrio, txt_Prio);
        QWidget::setTabOrder(txt_Prio, btn_AddPrio);
        QWidget::setTabOrder(btn_AddPrio, btn_ReduceHour);
        QWidget::setTabOrder(btn_ReduceHour, txt_Hour);
        QWidget::setTabOrder(txt_Hour, btn_AddHour);
        QWidget::setTabOrder(btn_AddHour, textBrowser_2);
        QWidget::setTabOrder(textBrowser_2, cb_users);
        QWidget::setTabOrder(cb_users, btn_EditDescription);
        QWidget::setTabOrder(btn_EditDescription, btn_Save);

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0));
        lbl_Number->setText(QApplication::translate("Dialog", "#1001", 0));
        lbl_Title->setText(QApplication::translate("Dialog", "Titel", 0));
        btn_EditTitle->setText(QApplication::translate("Dialog", "wijzig", 0));
        btn_EditDescription->setText(QApplication::translate("Dialog", "wijzig", 0));
        lbl_WijzigTitle_2->setText(QApplication::translate("Dialog", "Prioriteit", 0));
        btn_ReducePrio->setText(QApplication::translate("Dialog", "-", 0));
        txt_Prio->setText(QString());
        btn_AddPrio->setText(QApplication::translate("Dialog", "+", 0));
        lbl_WijzigTitle_3->setText(QApplication::translate("Dialog", "Uren", 0));
        btn_ReduceHour->setText(QApplication::translate("Dialog", "-", 0));
        txt_Hour->setText(QString());
        btn_AddHour->setText(QApplication::translate("Dialog", "+", 0));
        lbl_WijzigTitle_4->setText(QApplication::translate("Dialog", "PBI", 0));
        lbl_WijzigTitle_5->setText(QApplication::translate("Dialog", "Huidig project lid", 0));
        btn_Save->setText(QApplication::translate("Dialog", "Opslaan", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITSBI_H
