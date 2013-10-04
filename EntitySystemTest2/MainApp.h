#ifndef MAINAPP_H
#define MAINAPP_H

#include <QObject>

class MainApp: public QObject
{
    Q_OBJECT

public:
    explicit MainApp(QObject *par_parent = 0);
    ~MainApp();

    void timerEvent(QTimerEvent *par_event);

};

#endif
