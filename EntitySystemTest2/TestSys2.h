#ifndef TESTSYS2_H
#define TESTSYS2_H

#include "LogicSystem.h"
#include "EntitysIterator.h"

class TestSys2: public LogicSystem
{
private:
    Entitys m_node;

public:
    TestSys2();

    void initialize();
    void injectUpdate(const qint64 &par_timeSinceLastUpdate);
};

Q_DECLARE_METATYPE(TestSys2)

#endif
