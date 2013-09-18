#include "BitMask.h"

BitMask::BitMask()
{
    m_initialized = false;
}

BitMask::~BitMask()
{
}

void BitMask::add(const int &par_componentType)
{
    int componentMask = 1 << par_componentType;

    if(m_initialized == false)
    {
        m_initialized = true;
        m_mask = componentMask;
    }
    else
        m_mask |= componentMask;
}

void BitMask::remove(const int &par_componentType)
{
    int componentMask = 1 << par_componentType;

    if(m_initialized == true)
        m_mask &= ~componentMask;
}

int BitMask::getMask() const
{
    return m_mask;
}

bool BitMask::contains(const int &par_nodeMask, const int &par_entityMask)
{
    if((par_entityMask & par_nodeMask) == par_nodeMask)
        return true;
    else
        return false;
}
