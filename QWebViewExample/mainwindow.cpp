#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Устанавливаем ручную обработку клика по ссылке
    ui->webView->page()->setLinkDelegationPolicy(QWebPage::DelegateAllLinks);

    // Подключаем сигнал нажатия "Enter" в поле lineEdit
    connect(ui->lineEdit, &QLineEdit::returnPressed, this, &MainWindow::slotEnter);
    // Подключиаем сигнала клика по ссылке к обработчику
    connect(ui->webView, &QWebView::linkClicked, this, &MainWindow::slotLinkClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotEnter()
{
    // Загружаем страницу по заданном URL в поле lineEdit
    ui->webView->load(QUrl(ui->lineEdit->text()));
}

void MainWindow::slotLinkClicked(QUrl url)
{
    // При клике по ссылке помещаем адрес в поле lineEdit
    ui->lineEdit->setText(url.toString());
    ui->webView->load(url);     // Загружаем страницу по этой ссылке
}


