#include "BitSet.h"

#include <QDebug>

BitSet::BitSet(): m_value(Q_INT64_C(1))
{
    clear();
}

BitSet::~BitSet()
{
}

int BitSet::nextSet(const int &par_fromIndex)
{
    for(int i = par_fromIndex; i < 63; ++i)
    {
        if(test(i) == true)
            return i;
    }

    return -1;
}

void BitSet::set(const int &par_index)
{
    if(par_index > -1 && par_index < 63)
        m_mask |= m_value << par_index;
    else
        qDebug()<<"bitIndex is longer than max";
}

void BitSet::clear(const int &par_bitIndex)
{
    if(par_bitIndex > -1 && par_bitIndex < 63)
        m_mask &= ~(m_value << par_bitIndex);
    else
        qDebug()<<"bitIndex is longer than max";
}

void BitSet::clear()
{
    m_mask = Q_INT64_C(0);
}

bool BitSet::test(const int &par_bitIndex) const
{
    if(par_bitIndex > -1 && par_bitIndex < 63)
    {
        qint64 temp = m_value << par_bitIndex;
        if((m_mask & temp) == temp)
            return true;
        else
            return false;
    }

    qDebug()<<"bitIndex is longer than max";

    return false;
}

bool BitSet::isNull() const
{
    if(m_mask == 0)
        return true;
    else
        return false;
}
