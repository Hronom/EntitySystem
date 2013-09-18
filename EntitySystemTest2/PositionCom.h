#ifndef POSITIONCOM_H
#define POSITIONCOM_H

#include "IComponent.h"

class PositionCom: public IComponent
{
public:
    bool changed;
    int x;
    int y;
};

Q_DECLARE_METATYPE(PositionCom)

#endif // POSITIONCOM_H
