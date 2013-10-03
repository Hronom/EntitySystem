#ifndef BAGITERATOR_H
#define BAGITERATOR_H

#include "Bag.h"

template<class T>
class BagIterator
{
private:
    Bag<T> *m_bag;
    int m_currentIndex;
    int m_size;

public:
    BagIterator()
    {
        m_currentIndex = 0;
    }

    ~BagIterator()
    {

    }

    void setContainer(Bag<T> *par_bag)
    {
        m_bag = par_bag;
        m_currentIndex = 0;
        m_size = par_bag->count();
    }

    bool hasNext()
    {
        if(m_currentIndex < m_size)
            return true;
        else
            return false;
    }

    T next()
    {
        T elem;
        elem = m_bag->get(m_currentIndex);

        m_currentIndex++;

        return elem;
    }
};

#endif
