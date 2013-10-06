#include "SysTest3.h"

#include "World.h"
#include "Entity.h"
#include "BagIterator.h"

#include "ComHealth.h"
#include "ComPosition.h"

#include <QElapsedTimer>

SysTest3::SysTest3()
{
    EntitySystem::addComponentType<ComPosition>();
}

void SysTest3::initialize()
{
}

void SysTest3::injectUpdate(const qint64 &par_timeSinceLastUpdate)
{
    Q_UNUSED(par_timeSinceLastUpdate);

    BagIterator<Entity*> iter;
    iter.setContainer(&m_entitys);
    while(iter.hasNext())
    {
        Entity *entity;
        entity = iter.next();

        ComHealth *comHealth;
        comHealth = new ComHealth();

        entity->addComponent(comHealth);

        entity->update();
    }
}
