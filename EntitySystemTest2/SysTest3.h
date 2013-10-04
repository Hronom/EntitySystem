#ifndef SYSTEST3_H
#define SYSTEST3_H

#include "EntitySystem.h"
#include "BagIterator.h"

class SysTest3: public EntitySystem
{
public:
    SysTest3();

    void initialize();
    void injectUpdate(const qint64 &par_timeSinceLastUpdate);
};

#endif
