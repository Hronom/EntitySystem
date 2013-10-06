#include "SysTest2.h"

#include "World.h"
#include "Entity.h"
#include "BagIterator.h"

#include "ComClientConnection.h"
#include "ComHealth.h"
#include "ComPosition.h"

#include <QDebug>

#include <QElapsedTimer>

SysTest2::SysTest2()
{
    EntitySystem::addComponentType<ComClientConnection>();
    EntitySystem::addComponentType<ComPosition>();
}

void SysTest2::initialize()
{
}

void SysTest2::injectUpdate(const qint64 &par_timeSinceLastUpdate)
{
    Q_UNUSED(par_timeSinceLastUpdate);

    if(m_entitys.count() != 2)
        qCritical()<<"TestSys2"<<"Wrong count of entitys.";

    BagIterator<Entity*> iter;
    iter.setContainer(&m_entitys);
    while(iter.hasNext())
    {
        Entity *entity;
        entity = iter.next();

        ComClientConnection *comConnection;
        comConnection = entity->getComponent<ComClientConnection>();
        if(comConnection == 0)
            qCritical()<<"TestSys2"<<"ComConnection is 0";

        ComHealth *comHealth;
        comHealth = entity->getComponent<ComHealth>();
        if(comHealth != 0)
            qCritical()<<"TestSys2"<<"ComHealth not 0";

        ComPosition *comPosition;
        comPosition = entity->getComponent<ComPosition>();
        if(comPosition == 0)
            qCritical()<<"TestSys2"<<"ComPosition is 0";

        ComHealth *newComHealth = new ComHealth();
        entity->addComponent(newComHealth);

        entity->update();
    }    
}
