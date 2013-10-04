#ifndef BITMASK_H
#define BITMASK_H

#include "TypeInfoUtils.h"

class BitMask
{
private:
    bool m_initialized;
    int m_mask;

public:
    explicit BitMask();
    ~BitMask();

    void add(const int &par_componentType);
    void remove(const int &par_componentType);

    int getMask() const;

    static bool contains(const int &par_nodeMask, const int &par_entityMask);
};

#endif
