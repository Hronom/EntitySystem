#include "SysTest3.h"

#include "World.h"
#include "Entity.h"
#include "BagIterator.h"

#include "ComClientConnection.h"
#include "ComHealth.h"
#include "ComPosition.h"

#include <QDebug>

SysTest3::SysTest3()
{
    EntitySystem::addComponentType<ComClientConnection>();
    EntitySystem::addComponentType<ComHealth>();
    EntitySystem::addComponentType<ComPosition>();
}

void SysTest3::initialize()
{
}

void SysTest3::injectUpdate(const qint64 &par_timeSinceLastUpdate)
{
    Q_UNUSED(par_timeSinceLastUpdate);

    if(m_entitys.count() != 2)
        qDebug()<<"TestSys3"<<"Wrong count of entitys.";

    BagIterator<Entity*> iter;
    iter.setContainer(&m_entitys);
    while(iter.hasNext())
    {
        Entity *entity;
        entity = iter.next();

        ComClientConnection *comConnection;
        comConnection = entity->getComponent<ComClientConnection>();
        if(comConnection == 0)
            qDebug()<<"TestSys3"<<"ComConnection is 0";

        ComHealth *comHealth;
        comHealth = entity->getComponent<ComHealth>();
        if(comHealth == 0)
            qDebug()<<"TestSys3"<<"ComHealth is 0";

        ComPosition *comPosition;
        comPosition = entity->getComponent<ComPosition>();
        if(comPosition == 0)
            qDebug()<<"TestSys3"<<"ComPosition is 0";

        entity->removeComponent<ComHealth>();
    }
}
