#ifndef TESTSYS1_H
#define TESTSYS1_H

#include "EntitySystem.h"

class SysTest1: public EntitySystem
{
public:
    SysTest1();

    void initialize();
    void injectUpdate(const qint64 &par_timeSinceLastUpdate);
};

#endif
