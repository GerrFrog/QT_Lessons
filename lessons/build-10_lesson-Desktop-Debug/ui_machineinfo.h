/********************************************************************************
** Form generated from reading UI file 'machineinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MACHINEINFO_H
#define UI_MACHINEINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDial>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MachineInfo
{
public:
    QLabel *label;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QTimeEdit *timeEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QWidget *page_2;
    QDial *dial;
    QPushButton *pushButton_2;
    QWidget *page_3;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;
    QPushButton *pushButton_3;

    void setupUi(QWidget *MachineInfo)
    {
        if (MachineInfo->objectName().isEmpty())
            MachineInfo->setObjectName(QString::fromUtf8("MachineInfo"));
        MachineInfo->resize(800, 600);
        label = new QLabel(MachineInfo);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(260, 0, 231, 71));
        stackedWidget = new QStackedWidget(MachineInfo);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 60, 791, 531));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        timeEdit = new QTimeEdit(page);
        timeEdit->setObjectName(QString::fromUtf8("timeEdit"));
        timeEdit->setGeometry(QRect(110, 160, 118, 26));
        pushButton = new QPushButton(page);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(570, 70, 121, 41));
        pushButton_4 = new QPushButton(page);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(570, 180, 121, 41));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        dial = new QDial(page_2);
        dial->setObjectName(QString::fromUtf8("dial"));
        dial->setGeometry(QRect(150, 200, 50, 64));
        pushButton_2 = new QPushButton(page_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(500, 100, 141, 71));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        tabWidget = new QTabWidget(page_3);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(150, 150, 231, 161));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());
        pushButton_3 = new QPushButton(page_3);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(520, 100, 141, 71));
        stackedWidget->addWidget(page_3);

        retranslateUi(MachineInfo);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MachineInfo);
    } // setupUi

    void retranslateUi(QWidget *MachineInfo)
    {
        MachineInfo->setWindowTitle(QApplication::translate("MachineInfo", "Form", nullptr));
        label->setText(QApplication::translate("MachineInfo", "Machine info", nullptr));
        pushButton->setText(QApplication::translate("MachineInfo", "Screen 2", nullptr));
        pushButton_4->setText(QApplication::translate("MachineInfo", "Home", nullptr));
        pushButton_2->setText(QApplication::translate("MachineInfo", "Screen 3", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MachineInfo", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MachineInfo", "Tab 2", nullptr));
        pushButton_3->setText(QApplication::translate("MachineInfo", "Screen 1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MachineInfo: public Ui_MachineInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MACHINEINFO_H
