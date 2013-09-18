#ifndef HEALTHCOM_H
#define HEALTHCOM_H

#include "IComponent.h"

class HealthCom: public IComponent
{
public:
    int healthMax;
    int healthCurrent;
};

Q_DECLARE_METATYPE(HealthCom)

#endif // HEALTHCOM_H
