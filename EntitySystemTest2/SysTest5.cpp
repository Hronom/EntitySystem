#include "SysTest5.h"

#include "World.h"
#include "Entity.h"
#include "BagIterator.h"

#include "ComClientConnection.h"
#include "ComHealth.h"
#include "ComPosition.h"

#include <QDebug>

SysTest5::SysTest5()
{
}

void SysTest5::initialize()
{
}

void SysTest5::injectUpdate(const qint64 &par_timeSinceLastUpdate)
{
    Q_UNUSED(par_timeSinceLastUpdate);

    if(m_entitys.count() != 0)
        qCritical()<<"SysTest5"<<"Wrong count of entitys.";

    {
        Entity *entity;
        entity = m_world->createEntity();

        ComClientConnection *comConnection = new ComClientConnection();
        entity->addComponent(comConnection);

        ComHealth *comHealth = new ComHealth();
        entity->addComponent(comHealth);

        ComPosition *comPosition = new ComPosition();
        entity->addComponent(comPosition);

        entity->update();
    }
    {
        Entity *entity;
        entity = m_world->createEntity();

        ComClientConnection *comConnection = new ComClientConnection();
        entity->addComponent(comConnection);

        ComHealth *comHealth = new ComHealth();
        entity->addComponent(comHealth);

        ComPosition *comPosition = new ComPosition();
        entity->addComponent(comPosition);

        entity->update();
    }
}
