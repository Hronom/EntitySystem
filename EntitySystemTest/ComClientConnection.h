#ifndef COMCLIENTCONNECTION_H
#define COMCLIENTCONNECTION_H

#include "IComponent.h"

class ComClientConnection: public IComponent
{
public:
    bool connected;
};

Q_DECLARE_METATYPE(ComClientConnection)

#endif
