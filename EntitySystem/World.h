#ifndef WORLD_H
#define WORLD_H

#include "EntitySystem.h"
#include "TypeInfoUtils.h"
#include "EntityManager.h"

#include <QString>
#include <QHash>
#include <QDebug>

class Entity;

class World
{
private:
    bool m_stopUpdate;

    EntityManager *m_entityManager;

    ////////////////////////////////////////////////////////////////////////////
    // World properties
    int m_managersStartBagSize;
    int m_systemsStartBagSize;
    ////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////
    // Managers type id - manager
    QHash<int, Manager*> m_managers; // For fast lookup by type
    QList<Manager*> m_managersOrdered; // To iterate in insert order
    ////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////
    // Entity Systems type id - logic system
    QHash<int, EntitySystem*> m_systems; // For fast lookup by type
    QList<EntitySystem*> m_systemsOrdered; // To iterate in insert order
    ////////////////////////////////////////////////////////////////////////////

public:
    World();
    virtual ~World();
    ////////////////////////////////////////////////////////////////////////////
    // World properties methods
    void setManagersStartBagSize(int par_size);
    void setSystemsStartBagSize(int par_size);
    ////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////
    // Entitys methods
    Entity* createEntity();
    void updateEntity(Entity *par_entity, const int &par_entityMaskOld, const int &par_entityMaskNew);
    void removeEntity(Entity *par_entity);
    ////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////
    // EntitySystem methods
    void initializeAll();

    template<typename T>
    void setSystem(T *par_system, bool par_passive = false)
    {
        int systemType;
        systemType = TypeInfoUtils::getTypeID<T>();

        par_system->setWorld(this);
        par_system->setStartBagSize(m_systemsStartBagSize);
        par_system->setPassive(par_passive);

        m_systems.insert(systemType, par_system);
        m_systemsOrdered.append(par_system);

        stopUpdate();
    }

    template<typename T>
    T* getSystem()
    {
        int systemType;
        systemType = TypeInfoUtils::getTypeID<T>();

        T* system;
        system = static_cast<T*>(m_systems.value(systemType));

        return system;
    }

    QList<EntitySystem*> getAllSystems();

    template<typename T>
    void removeSystem()
    {
        int systemType;
        systemType = TypeInfoUtils::getTypeID<T>();

        EntitySystem *system;
        system = m_systems.take(systemType);
        m_systemsOrdered.removeOne(system);

        stopUpdate();
    }

    template<typename T>
    T* takeSystem()
    {
        int systemType;
        systemType = TypeInfoUtils::getTypeID<T>();

        EntitySystem *system;
        system = m_systems.take(systemType);
        m_systemsOrdered.removeAll(system);

        T *systemConverted;
        systemConverted = static_cast<T*>(system);

        stopUpdate();

        return systemConverted;
    }
    ////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////
    // Update methods
    void injectUpdate(const float& par_timeSinceLastUpdate);
    void stopUpdate();
    ////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////
    // Debug methods
    // TODO
    ////////////////////////////////////////////////////////////////////////////
};

#endif
