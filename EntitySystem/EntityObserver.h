#ifndef ENTITYOBSERVER_H
#define ENTITYOBSERVER_H

#include <QtGlobal>

class Entity;

class EntityObserver
{
public:
    EntityObserver() {}
    virtual ~EntityObserver() {}

    virtual void added(Entity *par_entity) { Q_UNUSED(par_entity) }
    virtual void changed(Entity *par_entity) { Q_UNUSED(par_entity) }
    virtual void deleted(Entity *par_entity) { Q_UNUSED(par_entity) }
    virtual void disabled(Entity *par_entity) { Q_UNUSED(par_entity) }
    virtual void enabled(Entity *par_entity) { Q_UNUSED(par_entity) }
};

#endif
