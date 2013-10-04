#include "Manager.h"

#include "World.h"

Manager::Manager()
{
    m_world = 0;
}

void Manager::setWorld(World *par_world)
{
    m_world = par_world;
}
