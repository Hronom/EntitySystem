#include "TestSys3.h"

#include "World.h"
#include "Entity.h"
#include "BagIterator.h"

#include "HealthCom.h"
#include "PositionCom.h"

#include <QElapsedTimer>

TestSys3::TestSys3()
{
}

BitMask TestSys3::getInterest()
{
    BitMask bitMask;
    bitMask.add<PositionCom>();
    return bitMask;
}

void TestSys3::initialize()
{
}

void TestSys3::injectUpdate(const qint64 &par_timeSinceLastUpdate)
{
    Q_UNUSED(par_timeSinceLastUpdate);

    BagIterator<Entity*> iter;
    iter.setContainer(&m_entitys);
    while(iter.hasNext())
    {
        Entity *entity;
        entity = iter.next();

        HealthCom *healthCom;
        healthCom = new HealthCom();

        entity->addComponent(healthCom);
    }
}
