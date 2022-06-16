#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(100);

    ui->progressBar->setValue(0);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateProgress);
    timer->start(1000);

    setWindowTitle(tr("Timer"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateProgress()
{
    ui->progressBar->setValue(ui->progressBar->value()+1);
}
