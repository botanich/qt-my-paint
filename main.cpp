#include "mainwindow.h"

#include <QApplication>
#include <QLabel>
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow window;
    window.show();
    window.update();
    return a.exec();
}
