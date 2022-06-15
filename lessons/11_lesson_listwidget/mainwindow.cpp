#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QStringListModel>
#include <QStringList>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for (int i = 0; i < 10; i++)
        ui->listWidget->addItem(QString::number(i) + " Hello world");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_listWidget_doubleClicked(const QModelIndex &index)
{
//    ui->listWidget->currentItem()->setText("Clicked");
    QListWidgetItem* item = ui->listWidget->currentItem();

    item->setText("Clicked");
    item->setTextColor(Qt::red);
}
