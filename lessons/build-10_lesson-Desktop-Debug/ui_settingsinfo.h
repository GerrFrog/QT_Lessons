/********************************************************************************
** Form generated from reading UI file 'settingsinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSINFO_H
#define UI_SETTINGSINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsInfo
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QDateEdit *dateEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *page_2;
    QPushButton *pushButton_3;
    QDialogButtonBox *buttonBox;

    void setupUi(QWidget *SettingsInfo)
    {
        if (SettingsInfo->objectName().isEmpty())
            SettingsInfo->setObjectName(QString::fromUtf8("SettingsInfo"));
        SettingsInfo->resize(800, 600);
        verticalLayout = new QVBoxLayout(SettingsInfo);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(SettingsInfo);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        stackedWidget = new QStackedWidget(SettingsInfo);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        dateEdit = new QDateEdit(page);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(100, 110, 110, 26));
        pushButton = new QPushButton(page);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(520, 90, 111, 51));
        pushButton_2 = new QPushButton(page);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(520, 180, 111, 51));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        pushButton_3 = new QPushButton(page_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(420, 140, 111, 51));
        buttonBox = new QDialogButtonBox(page_2);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(100, 270, 166, 25));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        stackedWidget->addWidget(page_2);

        verticalLayout->addWidget(stackedWidget);


        retranslateUi(SettingsInfo);

        QMetaObject::connectSlotsByName(SettingsInfo);
    } // setupUi

    void retranslateUi(QWidget *SettingsInfo)
    {
        SettingsInfo->setWindowTitle(QApplication::translate("SettingsInfo", "Form", nullptr));
        label->setText(QApplication::translate("SettingsInfo", "Settings information", nullptr));
        pushButton->setText(QApplication::translate("SettingsInfo", "Screen 2", nullptr));
        pushButton_2->setText(QApplication::translate("SettingsInfo", "Home", nullptr));
        pushButton_3->setText(QApplication::translate("SettingsInfo", "Screen 1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingsInfo: public Ui_SettingsInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSINFO_H
