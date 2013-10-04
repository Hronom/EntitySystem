#include <QCoreApplication>

#include "MainApp.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    MainApp mainApp;

    return app.exec();
}
