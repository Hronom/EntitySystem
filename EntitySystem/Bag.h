#ifndef BAG_H
#define BAG_H

#include <QList>

template<class T>
class Bag
{
private:
    QList<T> m_elements;
    int m_count;

public:
    Bag()
    {
        m_count = 0;
    }

    ~Bag()
    {
        m_elements.clear();
        m_count = 0;
    }

    void reserve(int par_reserve)
    {
        m_elements.reserve(par_reserve);
        for(int i = m_elements.size(); i < par_reserve; ++i)
            m_elements.append(0);
    }

    int count()
    {
        return m_count;
    }

    void set(const int &par_index, T par_elem)
    {
        for(int i = m_elements.size(); i <= par_index; ++i)
            m_elements.append(0);

        m_elements.replace(par_index, par_elem);
        m_count++;
    }

    T get(const int &par_index) const
    {
        if(par_index < m_elements.size())
        {
            T elem;
            elem = m_elements.at(par_index);
            if(elem != 0)
                return elem;
            else
                return 0;
        }
        else
            return 0;
    }

    T take(const int &par_index)
    {
        T elem;
        elem = m_elements.at(par_index);
        m_elements.replace(par_index, 0);
        return elem;
    }

    void remove(const int &par_index)
    {
        if(par_index < m_elements.size())
        {
            if(m_elements.at(par_index) != 0)
            {
                m_elements.replace(par_index, 0);
                m_count--;
            }
        }
    }

    bool contains(const int &par_index) const
    {
        if(par_index < m_elements.size())
        {
            if(m_elements.at(par_index) != 0)
                return true;
            else
                return false;
        }
        else
            return false;
    }
};

#endif
