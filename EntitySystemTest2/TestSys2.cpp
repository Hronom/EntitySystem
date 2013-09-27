#include "TestSys2.h"

#include "EntitysIterator.h"
#include "BitMask.h"

#include "HealthCom.h"
#include "PositionCom.h"

#include <QDebug>

#include <QElapsedTimer>

TestSys2::TestSys2()
{
}

void TestSys2::initialize()
{
    BitMask bitMask;
    bitMask.add<HealthCom>();
    bitMask.add<PositionCom>();

    m_node = getEntitySystem()->createEntitysGroup(bitMask);
}

void TestSys2::injectUpdate(const qint64 &par_timeSinceLastUpdate)
{
    Q_UNUSED(par_timeSinceLastUpdate);

    EntitysIterator iter;
    iter.setContainer(m_node);
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
