#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QDomDocument>
#include <QDomElement>
#include <QDomNodeList>
#include <QDomAttr>
#include <QtWebKitWidgets/QWebView>
#include <QtWebKit/QWebElementCollection>
#include <QTextBrowser>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    // create custom temporary event loop on stack
    QEventLoop eventLoop;

    // "quit()" the event-loop, when the network request "finished()"
    QNetworkAccessManager mgr;
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

//    QUrl url("https://api.parse.com/1/login");
//    QUrlQuery query;
//    query.addQueryItem("password", "test");
//    url.setQuery(query.query());
//    QNetworkRequest request(url);
//    request.setRawHeader("X-Parse-Application-Id", "myappid");
//    request.setRawHeader("X-Parse-REST-API-Key", "myapikey");
//    nam->get(request);

    // the HTTP request
    QNetworkRequest req( QUrl( QString("https://status.prismacloud.com/history?page=1") ) ); // "http://ip.jsontest.com/"
    QNetworkReply *reply = mgr.get(req);
    eventLoop.exec(); // blocks stack until "finished()" has been called

    if (reply->error() == QNetworkReply::NoError) {
        //success
//        qDebug() << "Success" <<reply->readAll();
        QString reply_string = QString(reply->readAll());
        qDebug() << reply_string;

        delete reply;
    }
    else {
        //failure
        qDebug() << "Failure" <<reply->errorString();
        delete reply;
    }
}
