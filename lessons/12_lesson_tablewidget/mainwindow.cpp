#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tableWidget->setColumnCount(2); // Указываем число колонок
    ui->tableWidget->setShowGrid(true); // Включаем сетку
    // Разрешаем выделение только одного элемента
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    // Разрешаем выделение построчно
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    // Устанавливаем заголовки колонок
    QStringList headers;
    headers.append("Название");
    headers.append("Количество");
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    // Растягиваем последнюю колонку на всё доступное пространство
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    // Скрываем колонку под номером 0
    //ui->tableWidget->hideColumn(0);
    // делаем таблицу readonly
    ui->tableWidget->setEditTriggers(QTableWidget::NoEditTriggers);
    // добавим в ячейки данные
    ui->tableWidget->insertRow(0);
    ui->tableWidget->setItem(0,0, new QTableWidgetItem("Ваши новые тикеты"));
    ui->tableWidget->setItem(0,1, new QTableWidgetItem("0"));
    ui->tableWidget->insertRow(1);
    ui->tableWidget->setItem(1,0, new QTableWidgetItem("-- не завершенные (Менеджер)"));
    ui->tableWidget->setItem(1,1, new QTableWidgetItem("0"));
    ui->tableWidget->insertRow(2);
    ui->tableWidget->setItem(2,0, new QTableWidgetItem("-- не завершенные (Клиент)"));
    ui->tableWidget->setItem(2,1, new QTableWidgetItem("0"));
    ui->tableWidget->insertRow(3);
    ui->tableWidget->setItem(3,0, new QTableWidgetItem("Новых в подразделении"));
    ui->tableWidget->setItem(3,1, new QTableWidgetItem("0"));
    ui->tableWidget->insertRow(4);
    ui->tableWidget->setItem(4,0, new QTableWidgetItem("-- не закрытых"));
    ui->tableWidget->setItem(4,1, new QTableWidgetItem("0"));
    ui->tableWidget->insertRow(5);
    ui->tableWidget->setItem(5,0, new QTableWidgetItem("Заявок на подключения"));
    ui->tableWidget->setItem(5,1, new QTableWidgetItem("0"));
    // растянем все колонки
    ui->tableWidget->resizeColumnsToContents();

    connect(ui->tableWidget, SIGNAL(cellClicked(int, int)), this, SLOT(myCellClicked(int, int)));
    connect(ui->tableWidget, SIGNAL(cellDoubleClicked(int,int)), this, SLOT(tableItemClicked(int,int)));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::tableItemClicked(int row, int column)
{
    QTableWidgetItem *item = new QTableWidgetItem;
    item = ui->tableWidget->item(row,column);

    item->setBackgroundColor(Qt::red);
    /* do some stuff with item */
}

