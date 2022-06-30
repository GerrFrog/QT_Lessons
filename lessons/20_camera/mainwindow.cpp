#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QCameraInfo>
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QVBoxLayout>
#include <QMenu>
#include <QAction>
#include <QFileDialog>
#include <QList>
#include <QGuiApplication>
#include <QtGui>
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
////////////////////////
    if (QCameraInfo::availableCameras().count() > 0)
        qDebug() << "Have";
    else
        qDebug() << "Camera is not here";
///////////////////
    const QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
    for (const QCameraInfo& cameraInfo : cameras)
        qDebug() << cameraInfo.deviceName();
/////////////////////


}

MainWindow::~MainWindow()
{
    delete ui;
}

