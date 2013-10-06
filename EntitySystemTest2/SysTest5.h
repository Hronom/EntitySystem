#ifndef SYSTEST5_H
#define SYSTEST5_H

#include "EntitySystem.h"
#include "BagIterator.h"

class SysTest5: public EntitySystem
{
public:
    SysTest5();

    void initialize();
    void injectUpdate(const qint64 &par_timeSinceLastUpdate);
};

#endif
