/********************************************************************************
** Form generated from reading UI file 'editWorkItem.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITWORKITEM_H
#define UI_EDITWORKITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLabel *lbl_Title;
    QLabel *lbl_Number;
    QTextBrowser *txt_Description;
    QLabel *lbl_WijzigContent;
    QLabel *lbl_WijzigTitle;
    QLabel *lbl_WijzigTitle_2;
    QLineEdit *txt_Prio;
    QPushButton *btn_ReducePrio;
    QPushButton *btn_AddPrio;
    QPushButton *btn_AddHour;
    QLineEdit *txt_Hour;
    QPushButton *btn_ReduceHour;
    QLabel *lbl_WijzigTitle_3;
    QLabel *lbl_WijzigTitle_4;
    QTextBrowser *textBrowser_2;
    QComboBox *comboBox;
    QLabel *lbl_WijzigTitle_5;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(876, 458);
        lbl_Title = new QLabel(Dialog);
        lbl_Title->setObjectName(QStringLiteral("lbl_Title"));
        lbl_Title->setGeometry(QRect(130, 10, 441, 31));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        lbl_Title->setFont(font);
        lbl_Number = new QLabel(Dialog);
        lbl_Number->setObjectName(QStringLiteral("lbl_Number"));
        lbl_Number->setGeometry(QRect(10, 10, 101, 31));
        lbl_Number->setFont(font);
        txt_Description = new QTextBrowser(Dialog);
        txt_Description->setObjectName(QStringLiteral("txt_Description"));
        txt_Description->setGeometry(QRect(10, 50, 611, 351));
        lbl_WijzigContent = new QLabel(Dialog);
        lbl_WijzigContent->setObjectName(QStringLiteral("lbl_WijzigContent"));
        lbl_WijzigContent->setGeometry(QRect(580, 410, 41, 16));
        lbl_WijzigTitle = new QLabel(Dialog);
        lbl_WijzigTitle->setObjectName(QStringLiteral("lbl_WijzigTitle"));
        lbl_WijzigTitle->setGeometry(QRect(570, 20, 53, 16));
        lbl_WijzigTitle_2 = new QLabel(Dialog);
        lbl_WijzigTitle_2->setObjectName(QStringLiteral("lbl_WijzigTitle_2"));
        lbl_WijzigTitle_2->setGeometry(QRect(640, 10, 161, 21));
        QFont font1;
        font1.setPointSize(14);
        lbl_WijzigTitle_2->setFont(font1);
        txt_Prio = new QLineEdit(Dialog);
        txt_Prio->setObjectName(QStringLiteral("txt_Prio"));
        txt_Prio->setGeometry(QRect(690, 50, 41, 41));
        txt_Prio->setFont(font1);
        btn_ReducePrio = new QPushButton(Dialog);
        btn_ReducePrio->setObjectName(QStringLiteral("btn_ReducePrio"));
        btn_ReducePrio->setGeometry(QRect(640, 50, 41, 41));
        btn_AddPrio = new QPushButton(Dialog);
        btn_AddPrio->setObjectName(QStringLiteral("btn_AddPrio"));
        btn_AddPrio->setGeometry(QRect(740, 50, 41, 41));
        btn_AddHour = new QPushButton(Dialog);
        btn_AddHour->setObjectName(QStringLiteral("btn_AddHour"));
        btn_AddHour->setGeometry(QRect(740, 140, 41, 41));
        txt_Hour = new QLineEdit(Dialog);
        txt_Hour->setObjectName(QStringLiteral("txt_Hour"));
        txt_Hour->setGeometry(QRect(690, 140, 41, 41));
        txt_Hour->setFont(font1);
        btn_ReduceHour = new QPushButton(Dialog);
        btn_ReduceHour->setObjectName(QStringLiteral("btn_ReduceHour"));
        btn_ReduceHour->setGeometry(QRect(640, 140, 41, 41));
        lbl_WijzigTitle_3 = new QLabel(Dialog);
        lbl_WijzigTitle_3->setObjectName(QStringLiteral("lbl_WijzigTitle_3"));
        lbl_WijzigTitle_3->setGeometry(QRect(640, 100, 161, 21));
        lbl_WijzigTitle_3->setFont(font1);
        lbl_WijzigTitle_4 = new QLabel(Dialog);
        lbl_WijzigTitle_4->setObjectName(QStringLiteral("lbl_WijzigTitle_4"));
        lbl_WijzigTitle_4->setGeometry(QRect(640, 190, 161, 21));
        lbl_WijzigTitle_4->setFont(font1);
        textBrowser_2 = new QTextBrowser(Dialog);
        textBrowser_2->setObjectName(QStringLiteral("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(640, 220, 191, 91));
        textBrowser_2->setFont(font1);
        comboBox = new QComboBox(Dialog);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(640, 360, 191, 41));
        comboBox->setFont(font1);
        lbl_WijzigTitle_5 = new QLabel(Dialog);
        lbl_WijzigTitle_5->setObjectName(QStringLiteral("lbl_WijzigTitle_5"));
        lbl_WijzigTitle_5->setGeometry(QRect(640, 320, 191, 31));
        lbl_WijzigTitle_5->setFont(font1);

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0));
        lbl_Title->setText(QApplication::translate("Dialog", "Titel", 0));
        lbl_Number->setText(QApplication::translate("Dialog", "#1001", 0));
        lbl_WijzigContent->setText(QApplication::translate("Dialog", "wijzig", 0));
        lbl_WijzigTitle->setText(QApplication::translate("Dialog", "wijzig", 0));
        lbl_WijzigTitle_2->setText(QApplication::translate("Dialog", "Prioriteit", 0));
        txt_Prio->setText(QApplication::translate("Dialog", "25", 0));
        btn_ReducePrio->setText(QApplication::translate("Dialog", "-", 0));
        btn_AddPrio->setText(QApplication::translate("Dialog", "+", 0));
        btn_AddHour->setText(QApplication::translate("Dialog", "+", 0));
        txt_Hour->setText(QApplication::translate("Dialog", "45", 0));
        btn_ReduceHour->setText(QApplication::translate("Dialog", "-", 0));
        lbl_WijzigTitle_3->setText(QApplication::translate("Dialog", "Uren", 0));
        lbl_WijzigTitle_4->setText(QApplication::translate("Dialog", "PBI", 0));
        lbl_WijzigTitle_5->setText(QApplication::translate("Dialog", "Huidig project lid", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITWORKITEM_H
