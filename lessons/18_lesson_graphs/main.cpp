#include "mainwindow.h"

#include <QApplication>

/* https://www.qcustomplot.com/index.php/download */
/* https://www.youtube.com/watch?v=VCx8i2W52TY */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
