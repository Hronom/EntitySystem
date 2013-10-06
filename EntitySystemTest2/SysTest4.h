#ifndef SYSTEST4_H
#define SYSTEST4_H

#include "EntitySystem.h"
#include "BagIterator.h"

class SysTest4: public EntitySystem
{
public:
    SysTest4();

    void initialize();
    void injectUpdate(const qint64 &par_timeSinceLastUpdate);
};

#endif
