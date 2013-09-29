#ifndef BITMASK_H
#define BITMASK_H

#include "TypeInfoUtils.h"

class BitMask
{
private:
    bool m_initialized;
    int m_mask;

public:
    BitMask();
    ~BitMask();

    template<typename T>
    void add()
    {
        int componentType = TypeInfoUtils::getTypeID<T>();
        add(componentType);
    }
    void add(const int &par_componentType);

    template<typename T>
    void remove()
    {
        int componentType = TypeInfoUtils::getTypeID<T>();
        remove(componentType);
    }
    void remove(const int &par_componentType);

    int getMask() const;

    static bool contains(const int &par_nodeMask, const int &par_entityMask);
};

#endif
