#include "TestSys3.h"

#include "EntitysIterator.h"

#include "HealthCom.h"
#include "PositionCom.h"

#include <QElapsedTimer>

TestSys3::TestSys3()
{
}

void TestSys3::addedToEntitySystem()
{
    BitMask bitMask;
    bitMask.add<PositionCom>();

    m_node = getEntitySystem()->createEntitysGroup(bitMask);
}

void TestSys3::injectUpdate(const qint64 &par_timeSinceLastUpdate)
{
    Q_UNUSED(par_timeSinceLastUpdate);

    EntitysIterator iter;
    iter.setContainer(m_node);
    while(iter.hasNext())
    {
        Entity *entity;
        entity = iter.next();

        HealthCom *healthCom;
        healthCom = new HealthCom();

        entity->addComponent(healthCom);
    }
}
