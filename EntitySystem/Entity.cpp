#include "Entity.h"

#include "ComponentManager.h"

Entity::Entity(World *par_world, int par_id): m_id(par_id)
{
    m_world = par_world;
    m_componentManager = m_world->getComponentManager();
}

Entity::~Entity()
{
}

int Entity::getID() const
{
    return m_id;
}
