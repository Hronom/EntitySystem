#ifndef SYSTEST2_H
#define SYSTEST2_H

#include "EntitySystem.h"
#include "BagIterator.h"

class SysTest2: public EntitySystem
{
public:
    SysTest2();

    void initialize();
    void injectUpdate(const qint64 &par_timeSinceLastUpdate);
};

#endif
