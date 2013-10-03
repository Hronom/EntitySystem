#include "TestSys1.h"

#include "World.h"
#include "BagIterator.h"
#include "BitMask.h"

#include "HealthCom.h"
#include "PositionCom.h"

#include <QDebug>

TestSys1::TestSys1()
{
}

BitMask TestSys1::getInterest()
{
    BitMask bitMask;
    return bitMask;
}

void TestSys1::initialize()
{
}

void TestSys1::injectUpdate(const qint64 &par_timeSinceLastUpdate)
{
    Q_UNUSED(par_timeSinceLastUpdate);

    BagIterator<Entity*> iter;
    iter.setContainer(&m_entitys);
    while(iter.hasNext())
    {
        Entity *entity;
        entity = iter.next();

        Q_UNUSED(entity);
    }
}
