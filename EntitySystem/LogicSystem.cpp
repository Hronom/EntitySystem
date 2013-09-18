#include "LogicSystem.h"

void LogicSystem::setEntitySystem(EntitySystem *par_entitySystem)
{
    m_entitySystem = par_entitySystem;
}

EntitySystem *LogicSystem::getEntitySystem()
{
    return m_entitySystem;
}
