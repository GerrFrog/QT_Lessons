#include "settingsinfo.h"
#include "ui_settingsinfo.h"

SettingsInfo::SettingsInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingsInfo)
{
    ui->setupUi(this);
}

SettingsInfo::~SettingsInfo()
{
    delete ui;
}

void SettingsInfo::on_pushButton_2_clicked()
{
    emit homeClicked();
}
