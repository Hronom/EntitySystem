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
    World* getWorld();

    virtual void setStartBagSize(int par_size) {}

    virtual void initialize() {}
};

#endif
