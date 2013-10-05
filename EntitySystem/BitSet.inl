#ifndef BITSET_INL
#define BITSET_INL

inline bool BitSet::contains(const BitSet &par_nodeMask, const BitSet &par_entityMask)
{
    if((par_entityMask.m_mask & par_nodeMask.m_mask) == par_nodeMask.m_mask)
        return true;
    else
        return false;
}

#endif
