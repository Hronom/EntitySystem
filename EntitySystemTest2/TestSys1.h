#ifndef TESTSYS1_H
#define TESTSYS1_H

#include "LogicSystem.h"
#include <QMetaType>

class TestSys1: public LogicSystem
{
public:
    TestSys1();

    void addedToEntitySystem();
    void injectUpdate(const qint64 &par_timeSinceLastUpdate);
};

Q_DECLARE_METATYPE(TestSys1)

#endif
