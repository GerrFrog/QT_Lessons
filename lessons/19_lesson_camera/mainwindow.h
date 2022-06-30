#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QCamera;
class QCameraViewfinder;
class QCameraImageCapture;
class QVBoxLayout;
class QMenu;
class QAction;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QCamera* m_camera;
    QCameraViewfinder* m_camera_viewfinder;
    QCameraImageCapture* m_camera_image_capture;
    QVBoxLayout* m_layout;
    QMenu* m_option_menu;
    QAction* m_light_action;
    QAction* m_turn_off_action;
    QAction* m_capture_action;
};
#endif // MAINWINDOW_H
