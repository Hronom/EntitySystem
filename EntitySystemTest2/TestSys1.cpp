#include "TestSys1.h"

#include "EntitysIterator.h"
#include "BitMask.h"

#include "HealthCom.h"
#include "PositionCom.h"

#include <QDebug>

TestSys1::TestSys1()
{
}

void TestSys1::addedToEntitySystem()
{

}

void TestSys1::injectUpdate(const qint64 &par_timeSinceLastUpdate)
{
    Q_UNUSED(par_timeSinceLastUpdate);

    for(int i=0; i<1000; i++)
    {
        Entity *entity;
        entity = getEntitySystem()->getEntity(QString::number(i));

        HealthCom *healthCom;
        healthCom = new HealthCom();
        entity->addComponent(healthCom);

        PositionCom *positionCom;
        positionCom = new PositionCom();
        entity->addComponent(positionCom);
    }
}
