#ifndef TESTSYS3_H
#define TESTSYS3_H

#include "EntitySystem.h"
#include "BagIterator.h"

class TestSys3: public EntitySystem
{
public:
    TestSys3();

    BitMask getInterest();

    void initialize();
    void injectUpdate(const qint64 &par_timeSinceLastUpdate);
};

#endif
