/********************************************************************************
** Form generated from reading UI file 'editPBI.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITPBI_H
#define UI_EDITPBI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLabel *lbl_Title;
    QLabel *lbl_Number;
    QPushButton *btn_Save;
    QListWidget *listWidget;
    QLabel *lbl_IncludedSbisTitel;
    QTextBrowser *txt_Description;
    QLabel *lbl_PbiDescription;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(915, 553);
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
        btn_Save = new QPushButton(Dialog);
        btn_Save->setObjectName(QStringLiteral("btn_Save"));
        btn_Save->setGeometry(QRect(780, 460, 101, 41));
        QFont font1;
        font1.setPointSize(14);
        btn_Save->setFont(font1);
        listWidget = new QListWidget(Dialog);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(10, 100, 300, 411));
        lbl_IncludedSbisTitel = new QLabel(Dialog);
        lbl_IncludedSbisTitel->setObjectName(QStringLiteral("lbl_IncludedSbisTitel"));
        lbl_IncludedSbisTitel->setGeometry(QRect(10, 70, 151, 21));
        lbl_IncludedSbisTitel->setFont(font1);
        txt_Description = new QTextBrowser(Dialog);
        txt_Description->setObjectName(QStringLiteral("txt_Description"));
        txt_Description->setGeometry(QRect(350, 100, 531, 341));
        lbl_PbiDescription = new QLabel(Dialog);
        lbl_PbiDescription->setObjectName(QStringLiteral("lbl_PbiDescription"));
        lbl_PbiDescription->setGeometry(QRect(350, 70, 531, 21));
        lbl_PbiDescription->setFont(font1);

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0));
        lbl_Title->setText(QApplication::translate("Dialog", "Titel", 0));
        lbl_Number->setText(QApplication::translate("Dialog", "#1001", 0));
        btn_Save->setText(QApplication::translate("Dialog", "Opslaan", 0));
        lbl_IncludedSbisTitel->setText(QApplication::translate("Dialog", "SBI's voor PBI", 0));
        lbl_PbiDescription->setText(QApplication::translate("Dialog", "Beschrijving", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITPBI_H
