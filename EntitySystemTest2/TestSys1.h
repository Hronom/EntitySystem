#ifndef TESTSYS1_H
#define TESTSYS1_H

#include "EntitySystem.h"

class TestSys1: public EntitySystem
{
public:
    TestSys1();

    BitMask getInterest();

    void initialize();
    void injectUpdate(const qint64 &par_timeSinceLastUpdate);
};

#endif
