#include "SysTest1.h"

#include "World.h"
#include "BagIterator.h"

#include "ComHealth.h"
#include "ComPosition.h"

#include <QDebug>

SysTest1::SysTest1()
{
}

void SysTest1::initialize()
{
}

void SysTest1::injectUpdate(const qint64 &par_timeSinceLastUpdate)
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
