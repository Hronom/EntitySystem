#include "Entity.h"

Entity::Entity(World *par_world, int par_id)
{
    m_world = par_world;
    m_id = par_id;
}

Entity::~Entity()
{
}

int Entity::getID()
{
    return m_id;
}

BitSet Entity::getComponentsMask()
{
    return m_componentsMask;
}
