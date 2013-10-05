#ifndef TYPEINFOUTILS_H
#define TYPEINFOUTILS_H

#include <QtGlobal>

class TypeInfoUtils
{
private:
    static int m_nextManagerTypeID;
    static int m_nextSystemTypeID;
    static int m_nextComponentTypeID;
    static int m_nextOtherTypeID;

public:
    template <typename T>
    static int getManagerTypeID()
    {
        static const int id = m_nextManagerTypeID++;
        return id;
    }

    template <typename T>
    static int getSystemTypeID()
    {
        static const int id = m_nextSystemTypeID++;
        return id;
    }

    template <typename T>
    static int getComponentTypeID()
    {
        static const int id = m_nextComponentTypeID++;
        return id;
    }

    template <typename T>
    static int getOtherTypeID()
    {
        static const int id = m_nextOtherTypeID++;
        return id;
    }
};

#endif
