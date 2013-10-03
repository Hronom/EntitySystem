#include <QCoreApplication>

#include "MainApp.h"

#include <QList>
#include <QElapsedTimer>
#include <QDebug>
#include <climits>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MainApp mainApp;

    return a.exec();
}
