#include "machineinfo.h"
#include "ui_machineinfo.h"

MachineInfo::MachineInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MachineInfo)
{
    ui->setupUi(this);
}

MachineInfo::~MachineInfo()
{
    delete ui;
}

void MachineInfo::on_pushButton_4_clicked()
{
    emit homeClicked();
}

void MachineInfo::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MachineInfo::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MachineInfo::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
