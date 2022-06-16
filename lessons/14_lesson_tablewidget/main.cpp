#include "mainwindow.h"

#include <QApplication>

/* https://www.youtube.com/watch?v=68_PHjBohAs */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
