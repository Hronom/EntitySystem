#include "SysTest2.h"

#include "World.h"
#include "Entity.h"
#include "BagIterator.h"

#include "ComHealth.h"
#include "ComPosition.h"

#include <QDebug>

#include <QElapsedTimer>

SysTest2::SysTest2()
{
    EntitySystem::addComponentType<ComHealth>();
    EntitySystem::addComponentType<ComPosition>();
}

void SysTest2::initialize()
{
}

void SysTest2::injectUpdate(const qint64 &par_timeSinceLastUpdate)
{
    Q_UNUSED(par_timeSinceLastUpdate);

    BagIterator<Entity*> iter;
    iter.setContainer(&m_entitys);
    while(iter.hasNext())
    {
        Entity *entity;
        entity = iter.next();

        ComHealth *comHealth;
        comHealth = entity->getComponent<ComHealth>();

        delete comHealth;

        entity->removeComponent<ComHealth>();
    }
}
