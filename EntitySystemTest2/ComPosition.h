#ifndef COMPOSITION_H
#define COMPOSITION_H

#include "Component.h"

struct ComPosition: public Component
{
public:
    bool changed;
    int x;
    int y;
};

#endif
