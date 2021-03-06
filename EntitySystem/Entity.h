#ifndef ENTITY_H
#define ENTITY_H

#include "World.h"
#include "TypeInfoUtils.h"
#include "BitSet.h"
#include "Bag.h"

#include <QString>

class ComponentManager;
class NameManager;

class Entity
{
    friend class World;
    friend class EntitySystem;
    friend class EntityManager;
    friend class ComponentManager;
private:
    World *m_world;
    ComponentManager *m_componentManager;
    NameManager *m_nameManager;

    QString m_name;

    const int m_id;

    BitSet m_componentsMask;

public:
    explicit Entity(World *par_world, int par_id);
    ~Entity();

    int getID() const;
    void setName(const QString &par_name);
    QString getName() const;

    void reset();

    ////////////////////////////////////////////////////////////////////////////
    // Components methods
    template<typename T>
    void addComponent(T *par_component);

    template<typename T>
    bool hasComponent() const;

    template<typename T>
    T* getComponent() const;

    template<typename T>
    void removeComponent();

    template<typename T>
    T* takeComponent();

    // This entity has changed, a component added or deleted. So update in world.
    void update();
    ////////////////////////////////////////////////////////////////////////////
};

#include "Entity.inl"

#endif
