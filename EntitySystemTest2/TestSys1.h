#ifndef TESTSYS1_H
#define TESTSYS1_H

#include "LogicSystem.h"
#include <QMetaType>

class TestSys1: public LogicSystem
{
public:
    TestSys1();

    void initialize();
    void injectUpdate(const qint64 &par_timeSinceLastUpdate);
};

#endif
