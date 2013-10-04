#ifndef SYSTEST1_H
#define SYSTEST1_H

#include "EntitySystem.h"
#include "BagIterator.h"

class SysTest1: public EntitySystem
{
public:
    SysTest1();

    void initialize();
    void injectUpdate(const qint64 &par_timeSinceLastUpdate);
};

#endif
