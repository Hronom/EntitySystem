#ifndef COMHEALTH_H
#define COMHEALTH_H

#include "Component.h"

struct ComHealth: public Component
{
public:
    int healthMax;
    int healthCurrent;
};

#endif
