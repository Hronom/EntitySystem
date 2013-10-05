#include "EntityObserver.h"

#include <QtGlobal>

void EntityObserver::added(Entity *par_entity)
{
    Q_UNUSED(par_entity)
}

void EntityObserver::changed(Entity *par_entity)
{
    Q_UNUSED(par_entity)
}

void EntityObserver::deleted(Entity *par_entity)
{
    Q_UNUSED(par_entity)
}

void EntityObserver::disabled(Entity *par_entity)
{
    Q_UNUSED(par_entity)
}

void EntityObserver::enabled(Entity *par_entity)
{
    Q_UNUSED(par_entity)
}
