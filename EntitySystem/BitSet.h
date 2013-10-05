//////////////////////////////////////////////////////////////////
///
/// Beware max 62 masked elements !!!
/// qint64 => 8 bytes => 64 bits
/// so qint64(1) << 64 == 0
/// bits[64] it's sign
///
//////////////////////////////////////////////////////////////////

#ifndef BITSET_H
#define BITSET_H

#include "TypeInfoUtils.h"
#include <QtGlobal>

class BitSet
{
private:
    const qint64 m_value;
    qint64 m_mask;

public:
    explicit BitSet();
    ~BitSet();

    int nextSet(const int &par_fromIndex);

    void set(const int &par_bitIndex);
    void clear(const int &par_bitIndex);
    void clear();
    bool test(const int &par_bitIndex);

    static inline bool contains(const BitSet &par_nodeMask, const BitSet &par_entityMask);
};

#include "BitSet.inl"

#endif
