#ifndef TESTSYS3_H
#define TESTSYS3_H

#include "LogicSystem.h"
#include "EntitysIterator.h"

class TestSys3: public LogicSystem
{
private:
    Entitys m_node;

public:
    TestSys3();

    void initialize();
    void injectUpdate(const qint64 &par_timeSinceLastUpdate);
};

#endif
