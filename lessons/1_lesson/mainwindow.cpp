#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QMessageBox>
#include <QDebug>

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

void MainWindow::on_pushButton_clicked()
{
//    QMessageBox::about(this, "Header", "Header text");
//    QMessageBox::critical(this, "Header", "Header critical");
    // information, warning, question

    QMessageBox::StandardButton reply = QMessageBox::question(
        this,
        "Header",
        "Exit?",
        QMessageBox::Yes | QMessageBox::No
    );

    if (reply == QMessageBox::Yes) {
        QApplication::quit();
    } else {
        qDebug() << "Button pressed\b";
    }

}
