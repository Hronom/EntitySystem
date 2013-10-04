#include "World.h"

#include "Entity.h"

World::World()
{
    m_stopUpdate = false;

    m_entityManager = new EntityManager();
    m_entityManager->setWorld(this);

    m_managersStartBagSize = 0;
    m_systemsStartBagSize = 0;
}

World::~World()
{
    qDebug()<<"Destroying World";
}

void World::setManagersStartBagSize(int par_size)
{
    m_managersStartBagSize = par_size;
    m_entityManager->setStartBagSize(par_size);
}

void World::setSystemsStartBagSize(int par_size)
{
    m_systemsStartBagSize = par_size;
}

Entity* World::createEntity()
{
    return m_entityManager->createEntity();
}

void World::updateEntity(Entity *par_entity)
{
    QList<EntitySystem*>::Iterator iter;
    iter = m_systemsOrdered.begin();
    while(iter != m_systemsOrdered.end())
    {
        EntitySystem *entitySystem;
        entitySystem = (*iter);

        entitySystem->check(par_entity);

        ++iter;
    }
}

void World::removeEntity(Entity *par_entity)
{
    m_entityManager->deleted(par_entity);
}

void World::initializeAll()
{
    QList<EntitySystem*>::Iterator iter;
    iter = m_systemsOrdered.begin();
    while(iter != m_systemsOrdered.end())
    {
        (*iter)->initialize();
        ++iter;
    }
}

QList<EntitySystem*> World::getAllSystems()
{
    return m_systemsOrdered;
}

void World::injectUpdate(const float &par_timeSinceLastUpdate)
{
    m_stopUpdate = false;

    QList<EntitySystem*>::Iterator iter;
    iter = m_systemsOrdered.begin();
    while(iter != m_systemsOrdered.end())
    {
        if(!m_stopUpdate)
        {
            EntitySystem *system;
            system = (*iter);
            if(system->checkProcessing())
                system->injectUpdate(par_timeSinceLastUpdate);

            ++iter;
        }
        else
        {
            break;
        }
    }
}

void World::stopUpdate()
{
    m_stopUpdate = true;
}
