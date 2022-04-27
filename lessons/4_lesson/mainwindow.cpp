#include "mainwindow.h"
#include "ui_mainwindow.h"

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


void MainWindow::on_checkBox_clicked()
{
    if (ui->checkBox->isChecked()) {
        ui->statusbar->showMessage("Checked");
    } else {
        ui->statusbar->showMessage("Unchecked");
    }
}

void MainWindow::on_checkBox_stateChanged(int arg1)
{
    if (ui->checkBox->isChecked()) {
        ui->statusbar->showMessage("Checked");
    } else {
        ui->statusbar->showMessage("Unchecked");
    }
}

void MainWindow::on_pushButton_clicked()
{
    if (ui->radioButton->isChecked()) {
        ui->statusbar->showMessage("First");
    }
    if (ui->radioButton_2->isChecked()) {
        ui->statusbar->showMessage("Second");
    }
}
