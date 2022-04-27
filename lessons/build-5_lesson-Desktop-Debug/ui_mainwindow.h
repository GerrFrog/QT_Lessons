/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionCreate_new;
    QAction *actionOpen_project;
    QAction *actionClose_project;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        actionCreate_new = new QAction(MainWindow);
        actionCreate_new->setObjectName(QString::fromUtf8("actionCreate_new"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/rec/img/img.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCreate_new->setIcon(icon);
        actionOpen_project = new QAction(MainWindow);
        actionOpen_project->setObjectName(QString::fromUtf8("actionOpen_project"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/rec/img/img2.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen_project->setIcon(icon1);
        actionClose_project = new QAction(MainWindow);
        actionClose_project->setObjectName(QString::fromUtf8("actionClose_project"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/rec/img/img3.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClose_project->setIcon(icon2);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout->addWidget(listWidget);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionCreate_new);
        menuFile->addAction(actionOpen_project);
        menuFile->addAction(actionClose_project);
        toolBar->addAction(actionCreate_new);
        toolBar->addAction(actionOpen_project);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionCreate_new->setText(QApplication::translate("MainWindow", "Create new", nullptr));
        actionOpen_project->setText(QApplication::translate("MainWindow", "Open project", nullptr));
        actionClose_project->setText(QApplication::translate("MainWindow", "Close project", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Choose element", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
