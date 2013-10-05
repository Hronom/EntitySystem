#ifndef COMCLIENTCONNECTION_H
#define COMCLIENTCONNECTION_H

#include "Component.h"

struct ComClientConnection: public Component
{
public:
    bool connected;
};

#endif
