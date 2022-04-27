#include "mainwindow.h"
#include "ui_mainwindow.h"

double num_first;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_sign, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_perc, SIGNAL(clicked()), this, SLOT(operations()));

    connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_mult, SIGNAL(clicked()), this, SLOT(math_operations()));

    ui->pushButton_div->setCheckable(true);
    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_mult->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers()
{
    QPushButton *button = (QPushButton*)sender();

    double all_numbers;
    QString new_label;

    if (ui->result_show->text().contains(".") && button->text() == "0") {
        new_label = ui->result_show->text() + button->text();
    } else {
        all_numbers = (ui->result_show->text() + button->text()).toDouble();

        new_label = QString::number(all_numbers, 'g', 15);
    }
    ui->result_show->setText(new_label);
}

void MainWindow::operations()
{
    QPushButton *button = (QPushButton*)sender();
    double all_numbers;
    QString new_label;

    if (button->text() == "+/-") {
        all_numbers = (ui->result_show->text()).toDouble();
        all_numbers *= -1;
        new_label = QString::number(all_numbers, 'g', 15);
        ui->result_show->setText(new_label);
    } else if (button->text() == "%") {
        all_numbers = (ui->result_show->text()).toDouble();
        all_numbers /= 100;
        new_label = QString::number(all_numbers, 'g', 15);
        ui->result_show->setText(new_label);
    }
}

void MainWindow::math_operations()
{
    QPushButton *button = (QPushButton*)sender();

    num_first = ui->result_show->text().toDouble();

    ui->result_show->setText("");

    button->setChecked(true);
}

void MainWindow::on_pushButton_dot_clicked()
{
    if (!ui->result_show->text().contains('.'))
        ui->result_show->setText(ui->result_show->text() + '.');
}

void MainWindow::on_pushButton_eq_clicked()
{
    double labelNumber, num_second;

    QString new_label;

    num_second = ui->result_show->text().toDouble();

    if (ui->pushButton_plus->isChecked()) {
        labelNumber = num_first + num_second;
        new_label = QString::number(labelNumber, 'g', 15);
        ui->result_show->setText(new_label);
        ui->pushButton_plus->setChecked(false);
    } else if (ui->pushButton_minus->isChecked()) {
        labelNumber = num_first - num_second;
        new_label = QString::number(labelNumber, 'g', 15);
        ui->result_show->setText(new_label);
        ui->pushButton_minus->setChecked(false);
    } else if (ui->pushButton_div->isChecked()) {
        labelNumber = num_first / num_second;
        new_label = QString::number(labelNumber, 'g', 15);
        ui->result_show->setText(new_label);
        ui->pushButton_div->setChecked(false);
    } else if (ui->pushButton_mult->isChecked()) {
        labelNumber = num_first * num_second;
        new_label = QString::number(labelNumber, 'g', 15);
        ui->result_show->setText(new_label);
        ui->pushButton_mult->setChecked(false);
    }
}

void MainWindow::on_pushButton_clear_clicked()
{
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_mult->setChecked(false);
    ui->pushButton_div->setChecked(false);
    ui->pushButton_minus->setChecked(false);

    num_first = 0;

    ui->result_show->setText("0");
}

