#include "SysTest1.h"

#include "World.h"
#include "Entity.h"
#include "BagIterator.h"

#include "ComClientConnection.h"
#include "ComHealth.h"
#include "ComPosition.h"

#include <QDebug>

SysTest1::SysTest1()
{
    EntitySystem::addComponentType<ComClientConnection>();
    EntitySystem::addComponentType<ComHealth>();
    EntitySystem::addComponentType<ComPosition>();
}

void SysTest1::initialize()
{
}

void SysTest1::injectUpdate(const qint64 &par_timeSinceLastUpdate)
{
    Q_UNUSED(par_timeSinceLastUpdate);

    if(m_entitys.count() != 2)
        qCritical()<<"TestSys1"<<"Wrong count of entitys.";

    BagIterator<Entity*> iter;
    iter.setContainer(&m_entitys);
    while(iter.hasNext())
    {
        Entity *entity;
        entity = iter.next();

        ComClientConnection *comConnection;
        comConnection = entity->getComponent<ComClientConnection>();
        if(comConnection == 0)
            qCritical()<<"TestSys1"<<"ComConnection is 0";

        ComHealth *comHealth;
        comHealth = entity->getComponent<ComHealth>();
        if(comHealth == 0)
            qCritical()<<"TestSys1"<<"HealthCom is 0";

        ComPosition *comPosition;
        comPosition = entity->getComponent<ComPosition>();
        if(comPosition == 0)
            qCritical()<<"TestSys1"<<"PositionCom is 0";

        entity->removeComponent<ComHealth>();

        entity->update();
    }
}
