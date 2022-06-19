#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QVector>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->custom_plot->addGraph();

    ui->custom_plot->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
    ui->custom_plot->graph()->setLineStyle(QCPGraph::lsLine);
    ui->custom_plot->xAxis->setLabel("X");
    ui->custom_plot->yAxis->setLabel("Y");
    ui->custom_plot->xAxis->setRange(600, 1000);
    ui->custom_plot->yAxis->setRange(600, 1000);

    ui->custom_plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

    QVector<double> x = {1, 2, 3, 4}, y = {4, 5, 6, 7};

    ui->custom_plot->graph(0)->setData(x, y);
    ui->custom_plot->rescaleAxes();
    ui->custom_plot->replot();
    ui->custom_plot->update();
}

MainWindow::~MainWindow()
{
    delete ui;
}

