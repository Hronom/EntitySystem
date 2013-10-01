#ifndef ENTITY_H
#define ENTITY_H

#include "BitMask.h"
#include "TypeInfoUtils.h"

#include <QHash>
#include <QList>
#include <QString>

class Entity
{
private:
    QString m_name;
    // node mask - entitys in node
    QHash<int, QList<Entity*>*> *m_nodes;
    BitMask m_bitMask;

    // component type - component
    QHash<quint32, void*> m_components;

public:
    Entity(QString par_name, QHash<int, QList<Entity*>*> *par_nodes);
    // Remove entity from all nodes. Components must be deleted manually
    ~Entity();

    QString getName() const;
    int getMask() const;

    template<typename T>
    void addComponent(T *par_component)
    {
        int entityMaskOld;
        entityMaskOld = m_bitMask.getMask();

        int componentType = TypeInfoUtils::getTypeID<T>();
        m_bitMask.add(componentType);
        m_components.insert(componentType, par_component);

        int entityMaskNew;
        entityMaskNew = m_bitMask.getMask();

        addEntityToNodes(entityMaskOld, entityMaskNew);
    }

    template<typename T>
    bool hasComponent() const
    {
        int componentType = TypeInfoUtils::getTypeID<T>();
        if(m_components.contains(componentType))
            return true;
        else
            return false;
    }

    template<typename T>
    T* getComponent() const
    {
        int xComponentType = TypeInfoUtils::getTypeID<T>();
        if(m_components.contains(xComponentType))
            return static_cast<T*>(m_components.value(xComponentType));
            //return ((T*)mComponents.value(xComponentType));
        else
            return 0;
    }

    template<typename T>
    void removeComponent()
    {
        int entityMaskOld;
        entityMaskOld = m_bitMask.getMask();

        int componentType = TypeInfoUtils::getTypeID<T>();
        m_bitMask.remove(componentType);
        m_components.remove(componentType);

        int entityMaskNew;
        entityMaskNew = m_bitMask.getMask();

        removeEntityFromNodes(entityMaskOld, entityMaskNew);
    }

    template<typename T>
    T* takeComponent()
    {
        int entityMaskOld;
        entityMaskOld = m_bitMask.getMask();

        int componentType = TypeInfoUtils::getTypeID<T>();
        m_bitMask.remove(componentType);

        T* component;
        component = static_cast<T*>(m_components.take(componentType));

        int entityMaskNew;
        entityMaskNew = m_bitMask.getMask();

        removeEntityFromNodes(entityMaskOld, entityMaskNew);

        return component;
    }

private:
    void addEntityToNodes(const int &par_entityMaskOld, const int &par_entityMaskNew);
    void removeEntityFromNodes(const int &par_entityMaskOld, const int &par_entityMaskNew);
};

#endif
