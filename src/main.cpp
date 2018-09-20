#include "mainwindow.h"
#include <QApplication>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.resize(1000,1000);
    w.show();

    return a.exec();
}
