#include "LogicSystem.h"

LogicSystem::LogicSystem()
{
    m_enabled = false;
}

void LogicSystem::enable()
{
    m_enabled = true;
    enabled();
}

void LogicSystem::disable()
{
    m_enabled = false;
    disabled();
}

bool LogicSystem::isEnabled()
{
    return m_enabled;
}

void LogicSystem::setEntitySystem(EntitySystem *par_entitySystem)
{
    m_entitySystem = par_entitySystem;
}

EntitySystem *LogicSystem::getEntitySystem()
{
    return m_entitySystem;
}
