#include "EntitySystem.h"

#include "World.h"
#include "Entity.h"

EntitySystem::EntitySystem()
{
    m_passive = false;
}

void EntitySystem::setWorld(World *par_world)
{
    m_world = par_world;
}

void EntitySystem::setStartBagSize(int par_size)
{
    m_entitys.reserve(par_size);
}

void EntitySystem::setPassive(bool par_passive)
{
    m_passive = par_passive;
}

bool EntitySystem::isPassive()
{
    return m_passive;
}

bool EntitySystem::checkProcessing()
{
    return !m_passive;
}

void EntitySystem::added(Entity *par_entity)
{
    m_entitys.set(par_entity->getID(), par_entity);
}

void EntitySystem::changed(Entity *par_entity)
{
    Q_UNUSED(par_entity)
    // TODO ???
}

void EntitySystem::deleted(Entity *par_entity)
{
    m_entitys.remove(par_entity->getID());
}
