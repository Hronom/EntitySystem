#ifndef POSITIONCOM_H
#define POSITIONCOM_H

#include "Component.h"

class ComPosition: public Component
{
public:
    bool changed;
    int x;
    int y;
};

#endif
