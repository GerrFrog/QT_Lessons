#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QListWidgetItem *item_1 = new QListWidgetItem(QIcon(":/rec/img/img.png"), "Audi");
    QListWidgetItem *item_2 = new QListWidgetItem(QIcon(":/rec/img/img2.png"), "BMW");
    QListWidgetItem *item_3 = new QListWidgetItem(QIcon(":/rec/img/img3.png"), "Volvo");
    ui->listWidget->addItem(item_1);
    ui->listWidget->addItem(item_2);
    ui->listWidget->addItem(item_3);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionCreate_new_triggered()
{
    ui->statusbar->showMessage("Created new file");
}

void MainWindow::on_actionOpen_project_triggered()
{
    ui->statusbar->showMessage("Created new project");
}

void MainWindow::on_pushButton_clicked()
{
    ui->statusbar->showMessage(ui->listWidget->currentItem()->text());
    ui->listWidget->currentItem()->setBackgroundColor(Qt::blue);
    ui->listWidget->currentItem()->setForeground(Qt::white);
}
