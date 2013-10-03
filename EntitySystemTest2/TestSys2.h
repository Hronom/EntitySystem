#ifndef TESTSYS2_H
#define TESTSYS2_H

#include "EntitySystem.h"
#include "BagIterator.h"

class TestSys2: public EntitySystem
{
public:
    TestSys2();

    BitMask getInterest();

    void initialize();
    void injectUpdate(const qint64 &par_timeSinceLastUpdate);
};

#endif
