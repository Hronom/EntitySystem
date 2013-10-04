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

void EntitySystem::reserveEntitysBag(int par_size)
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

void EntitySystem::added(Entity *par_entity)
{
    check(par_entity);
}

void EntitySystem::changed(Entity *par_entity)
{
    check(par_entity);
}

void EntitySystem::deleted(Entity *par_entity)
{
    if(m_entitys.contains(par_entity->getID()))
        removeFromSystem(par_entity);
}

void EntitySystem::disabled(Entity *par_entity)
{
    if(m_entitys.contains(par_entity->getID()))
        removeFromSystem(par_entity);
}

void EntitySystem::enabled(Entity *par_entity)
{
    check(par_entity);
}

void EntitySystem::check(Entity *par_entity)
{
    int entityMask;
    entityMask = par_entity->getComponentsMask();

    if(m_entitys.contains(par_entity->getID()))
    {
        // Delete if needed
        if(BitMask::contains(m_entitysMask.getMask(), entityMask) == false)
            removeFromSystem(par_entity);
    }
    else
    {
        // Insert if needed
        if(BitMask::contains(m_entitysMask.getMask(), entityMask))
            insertToSystem(par_entity);
    }
}

void EntitySystem::insertToSystem(Entity *par_entity)
{
    m_entitys.set(par_entity->getID(), par_entity);
    inserted(par_entity);
}

void EntitySystem::removeFromSystem(Entity *par_entity)
{
    m_entitys.remove(par_entity->getID());
    removed(par_entity);
}

