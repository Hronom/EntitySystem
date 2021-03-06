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

    void inline reserve(int par_reserve)
    {
        m_elements.reserve(par_reserve);
        for(int i = m_elements.size(); i < par_reserve; ++i)
            m_elements.append(0);
    }

    int count()
    {
        return m_count;
    }

    bool isEmpty()
    {
        if(m_count > 0)
            return false;
        else
            return true;
    }

    int elementsCount()
    {
        return m_elements.size();
    }

    void set(const int &par_index, T par_elem)
    {
        reserve(par_index + 1);

        m_elements.replace(par_index, par_elem);
        m_count++;
    }

    T first() const
    {
        for(int i = 0; i<m_elements.size(); ++i)
        {
            T elem;
            elem = m_elements.at(i);

            if(elem != 0)
                return elem;
        }

        return 0;
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
        if(par_index < m_elements.size())
        {
            T elem;
            elem = m_elements.at(par_index);

            if(elem != 0)
            {
                m_elements.replace(par_index, 0);
                m_count--;
            }

            return elem;
        }
        else
            return 0;
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
