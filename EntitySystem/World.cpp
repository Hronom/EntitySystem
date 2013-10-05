#include "World.h"

#include "EntitySystem.h"
#include "EntityManager.h"
#include "ComponentManager.h"
#include "Entity.h"

#include <QDebug>

World::World()
{
    m_stopUpdate = false;

    m_entityManager = new EntityManager();
    setManager(m_entityManager);

    m_componentManager = new ComponentManager();
    setManager(m_componentManager);

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
    // Update entity in managers
    {
        QList<Manager*>::Iterator iter;
        iter = m_managersOrdered.begin();
        while(iter != m_managersOrdered.end())
        {
            Manager *manager;
            manager = (*iter);

            manager->changed(par_entity);

            ++iter;
        }
    }

    // Update entity in systems
    {
        QList<EntitySystem*>::Iterator iter;
        iter = m_systemsOrdered.begin();
        while(iter != m_systemsOrdered.end())
        {
            EntitySystem *entitySystem;
            entitySystem = (*iter);

            entitySystem->changed(par_entity);

            ++iter;
        }
    }
}

void World::removeEntity(Entity *par_entity)
{
    // Delete entity in managers
    {
        QList<Manager*>::Iterator iter;
        iter = m_managersOrdered.begin();
        while(iter != m_managersOrdered.end())
        {
            Manager *manager;
            manager = (*iter);

            manager->deleted(par_entity);

            ++iter;
        }
    }

    // Delete entity in systems
    {
        QList<EntitySystem*>::Iterator iter;
        iter = m_systemsOrdered.begin();
        while(iter != m_systemsOrdered.end())
        {
            EntitySystem *entitySystem;
            entitySystem = (*iter);

            entitySystem->deleted(par_entity);

            ++iter;
        }
    }
}

EntityManager* World::getEntityManager()
{
    return m_entityManager;
}

ComponentManager* World::getComponentManager()
{
    return m_componentManager;
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
            if(!system->isPassive())
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
