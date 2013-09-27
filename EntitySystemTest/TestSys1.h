#ifndef TESTSYS1_H
#define TESTSYS1_H

#include "LogicSystem.h"
#include "EntitysIterator.h"

class TestSys1: public LogicSystem
{
private:
    Entitys m_node;

public:
    TestSys1();

    void initialize();
    void injectUpdate(const qint64 &par_timeSinceLastUpdate);
};

Q_DECLARE_METATYPE(TestSys1)

#endif
