#include "SysTest4.h"

#include "World.h"
#include "Entity.h"
#include "BagIterator.h"

#include "ComClientConnection.h"
#include "ComPosition.h"

#include <QDebug>

SysTest4::SysTest4()
{
    EntitySystem::addComponentType<ComClientConnection>();
    EntitySystem::addComponentType<ComPosition>();
}

void SysTest4::initialize()
{
}

void SysTest4::injectUpdate(const qint64 &par_timeSinceLastUpdate)
{
    Q_UNUSED(par_timeSinceLastUpdate);

    if(m_entitys.count() != 2)
        qCritical()<<"TestSys4"<<"Wrong count of entitys.";

    BagIterator<Entity*> iter;
    iter.setContainer(&m_entitys);
    while(iter.hasNext())
    {
        Entity *entity;
        entity = iter.next();

        m_world->removeEntity(entity);
    }
}
