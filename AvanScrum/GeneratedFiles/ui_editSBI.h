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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QTextBrowser *textBrowser_2;
    QLabel *lbl_WijzigTitle_4;
    QTextBrowser *txt_Description;
    QLabel *lbl_WijzigTitle_3;
    QPushButton *btn_EditTitle;
    QLabel *lbl_Title;
    QLabel *lbl_WijzigTitle_2;
    QPushButton *btn_ReduceHour;
    QLabel *lbl_Number;
    QLineEdit *txt_Prio;
    QPushButton *btn_AddPrio;
    QComboBox *cb_users;
    QPushButton *btn_AddHour;
    QLabel *lbl_WijzigTitle_5;
    QPushButton *btn_Save;
    QPushButton *btn_ReducePrio;
    QLineEdit *txt_Hour;
    QPushButton *btn_EditDescription;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(915, 553);
        textBrowser_2 = new QTextBrowser(Dialog);
        textBrowser_2->setObjectName(QStringLiteral("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(640, 220, 191, 91));
        QFont font;
        font.setPointSize(14);
        textBrowser_2->setFont(font);
        lbl_WijzigTitle_4 = new QLabel(Dialog);
        lbl_WijzigTitle_4->setObjectName(QStringLiteral("lbl_WijzigTitle_4"));
        lbl_WijzigTitle_4->setGeometry(QRect(640, 190, 161, 21));
        lbl_WijzigTitle_4->setFont(font);
        txt_Description = new QTextBrowser(Dialog);
        txt_Description->setObjectName(QStringLiteral("txt_Description"));
        txt_Description->setGeometry(QRect(10, 50, 611, 411));
        txt_Description->setFont(font);
        lbl_WijzigTitle_3 = new QLabel(Dialog);
        lbl_WijzigTitle_3->setObjectName(QStringLiteral("lbl_WijzigTitle_3"));
        lbl_WijzigTitle_3->setGeometry(QRect(640, 100, 161, 21));
        lbl_WijzigTitle_3->setFont(font);
        btn_EditTitle = new QPushButton(Dialog);
        btn_EditTitle->setObjectName(QStringLiteral("btn_EditTitle"));
        btn_EditTitle->setGeometry(QRect(530, 7, 93, 41));
        btn_EditTitle->setFont(font);
        lbl_Title = new QLabel(Dialog);
        lbl_Title->setObjectName(QStringLiteral("lbl_Title"));
        lbl_Title->setGeometry(QRect(130, 10, 441, 31));
        QFont font1;
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setWeight(75);
        lbl_Title->setFont(font1);
        lbl_WijzigTitle_2 = new QLabel(Dialog);
        lbl_WijzigTitle_2->setObjectName(QStringLiteral("lbl_WijzigTitle_2"));
        lbl_WijzigTitle_2->setGeometry(QRect(640, 10, 161, 21));
        lbl_WijzigTitle_2->setFont(font);
        btn_ReduceHour = new QPushButton(Dialog);
        btn_ReduceHour->setObjectName(QStringLiteral("btn_ReduceHour"));
        btn_ReduceHour->setGeometry(QRect(640, 140, 41, 41));
        btn_ReduceHour->setFont(font);
        lbl_Number = new QLabel(Dialog);
        lbl_Number->setObjectName(QStringLiteral("lbl_Number"));
        lbl_Number->setGeometry(QRect(10, 10, 101, 31));
        lbl_Number->setFont(font1);
        txt_Prio = new QLineEdit(Dialog);
        txt_Prio->setObjectName(QStringLiteral("txt_Prio"));
        txt_Prio->setGeometry(QRect(690, 50, 41, 41));
        txt_Prio->setFont(font);
        btn_AddPrio = new QPushButton(Dialog);
        btn_AddPrio->setObjectName(QStringLiteral("btn_AddPrio"));
        btn_AddPrio->setGeometry(QRect(740, 50, 41, 41));
        btn_AddPrio->setFont(font);
        cb_users = new QComboBox(Dialog);
        cb_users->setObjectName(QStringLiteral("cb_users"));
        cb_users->setGeometry(QRect(640, 360, 191, 41));
        cb_users->setFont(font);
        btn_AddHour = new QPushButton(Dialog);
        btn_AddHour->setObjectName(QStringLiteral("btn_AddHour"));
        btn_AddHour->setGeometry(QRect(740, 140, 41, 41));
        btn_AddHour->setFont(font);
        lbl_WijzigTitle_5 = new QLabel(Dialog);
        lbl_WijzigTitle_5->setObjectName(QStringLiteral("lbl_WijzigTitle_5"));
        lbl_WijzigTitle_5->setGeometry(QRect(640, 320, 191, 31));
        lbl_WijzigTitle_5->setFont(font);
        btn_Save = new QPushButton(Dialog);
        btn_Save->setObjectName(QStringLiteral("btn_Save"));
        btn_Save->setGeometry(QRect(780, 460, 101, 41));
        btn_Save->setFont(font);
        btn_ReducePrio = new QPushButton(Dialog);
        btn_ReducePrio->setObjectName(QStringLiteral("btn_ReducePrio"));
        btn_ReducePrio->setGeometry(QRect(640, 50, 41, 41));
        btn_ReducePrio->setFont(font);
        txt_Hour = new QLineEdit(Dialog);
        txt_Hour->setObjectName(QStringLiteral("txt_Hour"));
        txt_Hour->setGeometry(QRect(690, 140, 41, 41));
        txt_Hour->setFont(font);
        btn_EditDescription = new QPushButton(Dialog);
        btn_EditDescription->setObjectName(QStringLiteral("btn_EditDescription"));
        btn_EditDescription->setGeometry(QRect(530, 467, 93, 41));
        btn_EditDescription->setFont(font);

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0));
        lbl_WijzigTitle_4->setText(QApplication::translate("Dialog", "PBI", 0));
        lbl_WijzigTitle_3->setText(QApplication::translate("Dialog", "Uren", 0));
        btn_EditTitle->setText(QApplication::translate("Dialog", "wijzig", 0));
        lbl_Title->setText(QApplication::translate("Dialog", "Titel", 0));
        lbl_WijzigTitle_2->setText(QApplication::translate("Dialog", "Prioriteit", 0));
        btn_ReduceHour->setText(QApplication::translate("Dialog", "-", 0));
        lbl_Number->setText(QApplication::translate("Dialog", "#1001", 0));
        txt_Prio->setText(QString());
        btn_AddPrio->setText(QApplication::translate("Dialog", "+", 0));
        btn_AddHour->setText(QApplication::translate("Dialog", "+", 0));
        lbl_WijzigTitle_5->setText(QApplication::translate("Dialog", "Huidig project lid", 0));
        btn_Save->setText(QApplication::translate("Dialog", "Opslaan", 0));
        btn_ReducePrio->setText(QApplication::translate("Dialog", "-", 0));
        txt_Hour->setText(QString());
        btn_EditDescription->setText(QApplication::translate("Dialog", "wijzig", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITSBI_H
