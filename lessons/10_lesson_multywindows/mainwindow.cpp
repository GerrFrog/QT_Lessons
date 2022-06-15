#include "mainwindow.h"
#include "ui_mainwindow.h"

// https://www.youtube.com/watch?v=27PvtxWlV-o

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    ui->stackedWidget->addWidget(&machInfo);
//    ui->stackedWidget->addWidget(&setInfo);

    ui->stackedWidget->insertWidget(1, &machInfo);
    ui->stackedWidget->insertWidget(2, &setInfo);

    connect(&machInfo, SIGNAL(homeClicked()), this, SLOT(moveHome()));
    connect(&setInfo, SIGNAL(homeClicked()), this, SLOT(moveHome()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_3_clicked()
{
    this->close();
}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::moveHome()
{
    ui->stackedWidget->setCurrentIndex(0);
}
