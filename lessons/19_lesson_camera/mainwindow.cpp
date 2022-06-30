#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QVBoxLayout>
#include <QMenu>
#include <QAction>
#include <QFileDialog>
#include <QCameraImageProcessingControl>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_camera = new QCamera(this);
    m_camera_viewfinder = new QCameraViewfinder(this);
    m_camera_image_capture = new QCameraImageCapture(m_camera, this);

    m_layout = new QVBoxLayout;

    m_option_menu = new QMenu("Options", this);
    m_light_action = new QAction("Light", this);
    m_turn_off_action = new QAction("Turn off", this);
    m_capture_action = new QAction("Capture", this);

    m_option_menu->addActions({
        m_light_action,
        m_turn_off_action,
        m_capture_action
    });

    ui->options_pushButton->setMenu(m_option_menu);

    m_camera->setViewfinder(m_camera_viewfinder);
    m_layout->addWidget(m_camera_viewfinder);
    m_layout->setMargin(0);
    ui->scrollArea->setLayout(m_layout);

    connect(m_light_action, &QAction::triggered, [&]() {
        m_camera->start();
    });
    connect(m_turn_off_action, &QAction::triggered, [&]() {
        m_camera->stop();
    });
    connect(m_capture_action, &QAction::triggered, [&]() {
        auto filename = QFileDialog::getSaveFileName(this, "Captured", "/home/falls/Pictures", "Image (*.jpg;*.jpeg)");
        if (filename.isEmpty())
            return;
        m_camera_image_capture->setCaptureDestination(
            QCameraImageCapture::CaptureToFile
        );
        QImageEncoderSettings imageEncoderSettings;
        imageEncoderSettings.setCodec("image/jpeg");
        imageEncoderSettings.setResolution(640, 480);

        m_camera_image_capture->setEncodingSettings(imageEncoderSettings);
        m_camera->setCaptureMode(QCamera::CaptureStillImage);
        m_camera->start();
        m_camera->searchAndLock();
        m_camera_image_capture->capture(filename);
        m_camera->unlock();
    });



}

MainWindow::~MainWindow()
{
    delete ui;
}

