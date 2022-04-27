#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap pix(":/resources/img/img.png");
    int w = ui->img->width();
    int h = ui->img->height();
    ui->img->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_authButton_clicked()
{
    QString login = ui->login->text();
    QString pass = ui->password->text();

    if (login == "test" && pass == "test") {
        QMessageBox::information(this, "Authorized", "You are authorized");
        ui->statusbar->showMessage("Authorized");
    } else {
        QMessageBox::warning(this, "Unauthorized", "You are not authorized");
        ui->statusbar->showMessage("Unauthorized");
    }
}
