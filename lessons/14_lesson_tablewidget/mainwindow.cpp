#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QWidget>
#include "form.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    ui->tabWidget->removeTab(index);
}

void MainWindow::on_pushButton_clicked()
{
//    ui->tabWidget->addTab(new QWidget(), QString("Tab %0").arg(ui->tabWidget->count() + 1));

    Form* form = new Form();

    ui->tabWidget->addTab(
        form,
        QString("Tab %0").arg(ui->tabWidget->count() + 1)
    );
    ui->tabWidget->setCurrentIndex(ui->tabWidget->count() - 1);
}
