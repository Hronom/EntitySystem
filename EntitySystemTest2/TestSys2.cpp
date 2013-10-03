#include "TestSys2.h"

#include "World.h"
#include "Entity.h"
#include "BagIterator.h"
#include "BitMask.h"

#include "HealthCom.h"
#include "PositionCom.h"

#include <QDebug>

#include <QElapsedTimer>

TestSys2::TestSys2()
{
}

BitMask TestSys2::getInterest()
{
    BitMask bitMask;
    bitMask.add<HealthCom>();
    bitMask.add<PositionCom>();
    return bitMask;
}

void TestSys2::initialize()
{
}

void TestSys2::injectUpdate(const qint64 &par_timeSinceLastUpdate)
{
    Q_UNUSED(par_timeSinceLastUpdate);

    BagIterator<Entity*> iter;
    iter.setContainer(&m_entitys);
    while(iter.hasNext())
    {
        Entity *entity;
        entity = iter.next();

        HealthCom *healthCom;
        healthCom = entity->getComponent<HealthCom>();

        delete healthCom;

        entity->removeComponent<HealthCom>();
    }
}
