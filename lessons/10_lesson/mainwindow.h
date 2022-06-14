#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "machineinfo.h"
#include "settingsinfo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void moveHome();

private:
    Ui::MainWindow *ui;

    MachineInfo machInfo;

    SettingsInfo setInfo;
};
#endif // MAINWINDOW_H
