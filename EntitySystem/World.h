#ifndef WORLD_H
#define WORLD_H

#include "TypeInfoUtils.h"
#include "Manager.h"
#include "EntitySystem.h"

#include <QList>
#include <QHash>

class EntityManager;
class ComponentManager;
class Entity;

class World
{
private:
    bool m_stopUpdate;

    ////////////////////////////////////////////////////////////////////////////
    // World properties
    int m_managersStartBagSize;
    int m_systemsStartBagSize;
    ////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////
    // Managers
    EntityManager *m_entityManager;
    ComponentManager *m_componentManager;

    // Managers type id - manager
    Bag<Manager*> m_managers; // For fast lookup by type
    QList<Manager*> m_managersOrdered; // To iterate in insert order
    ////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////
    // Entity Systems type id - logic system
    Bag<EntitySystem*> m_systems; // For fast lookup by type
    QList<EntitySystem*> m_systemsOrdered; // To iterate in insert order
    ////////////////////////////////////////////////////////////////////////////

public:
    explicit World();
    virtual ~World();
    ////////////////////////////////////////////////////////////////////////////
    // World properties methods
    void setManagersStartBagSize(int par_size);
    void setSystemsStartBagSize(int par_size);
    ////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////
    // Entitys methods
    Entity* createEntity();
    void updateEntity(Entity *par_entity);
    void removeEntity(Entity *par_entity);
    ////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////
    // Manager methods
    EntityManager* getEntityManager();
    ComponentManager* getComponentManager();

    template<typename T>
    void setManager(T *par_manager)
    {
        int managerType;
        managerType = TypeInfoUtils::getManagerTypeID<T>();

        par_manager->setWorld(this);

        m_managers.set(managerType, par_manager);
        m_managersOrdered.append(par_manager);

        stopUpdate();
    }

    template<typename T>
    T* getManager()
    {
        int managerType;
        managerType = TypeInfoUtils::getManagerTypeID<T>();

        T* manager;
        manager = static_cast<T*>(m_managers.get(managerType));

        return manager;
    }

    template<typename T>
    void removeManager()
    {
        int managerType;
        managerType = TypeInfoUtils::getManagerTypeID<T>();

        Manager *manager;
        manager = m_managers.take(managerType);
        m_managersOrdered.removeOne(manager);

        stopUpdate();
    }

    template<typename T>
    T* takeManager()
    {
        int managerType;
        managerType = TypeInfoUtils::getManagerTypeID<T>();

        Manager *manager;
        manager = m_managers.take(managerType);
        m_managersOrdered.removeOne(manager);

        T *managerConverted;
        managerConverted = static_cast<T*>(manager);

        stopUpdate();

        return managerConverted;
    }
    ////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////
    // EntitySystem methods
    void initializeAll();

    template<typename T>
    void setSystem(T *par_system, bool par_passive = false)
    {
        int systemType;
        systemType = TypeInfoUtils::getSystemTypeID<T>();

        par_system->setWorld(this);
        par_system->reserveEntitysBag(m_systemsStartBagSize);
        par_system->setPassive(par_passive);

        m_systems.set(systemType, par_system);
        m_systemsOrdered.append(par_system);

        stopUpdate();
    }

    template<typename T>
    T* getSystem()
    {
        int systemType;
        systemType = TypeInfoUtils::getSystemTypeID<T>();

        T* system;
        system = static_cast<T*>(m_systems.get(systemType));

        return system;
    }

    QList<EntitySystem*> getAllSystems();

    template<typename T>
    void removeSystem()
    {
        int systemType;
        systemType = TypeInfoUtils::getSystemTypeID<T>();

        EntitySystem *system;
        system = m_systems.take(systemType);
        m_systemsOrdered.removeOne(system);

        stopUpdate();
    }

    template<typename T>
    T* takeSystem()
    {
        int systemType;
        systemType = TypeInfoUtils::getSystemTypeID<T>();

        EntitySystem *system;
        system = m_systems.take(systemType);
        m_systemsOrdered.removeOne(system);

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
