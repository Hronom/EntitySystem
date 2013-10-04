#ifndef MANAGER_H
#define MANAGER_H

#include "EntityObserver.h"

class World;

class Manager: public EntityObserver
{
protected:
    World *m_world;

public:
    Manager();
    virtual ~Manager() {}

    void setWorld(World *par_world);

    virtual void initialize() {}
};

#endif
