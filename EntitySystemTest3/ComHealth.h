#ifndef HEALTHCOM_H
#define HEALTHCOM_H

#include "Component.h"

struct ComHealth: public Component
{
public:
    int healthMax;
    int healthCurrent;
};

#endif
