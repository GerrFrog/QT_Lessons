#ifndef SETTINGSINFO_H
#define SETTINGSINFO_H

#include <QWidget>

namespace Ui {
class SettingsInfo;
}

class SettingsInfo : public QWidget
{
    Q_OBJECT

public:
    explicit SettingsInfo(QWidget *parent = nullptr);
    ~SettingsInfo();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::SettingsInfo *ui;

signals:
    void homeClicked();
};

#endif // SETTINGSINFO_H
