#ifndef TYPEINFOUTILS_H
#define TYPEINFOUTILS_H

class TypeInfoUtils
{
private:
    static int m_nextTypeID;

public:
    template <typename T>
    static int getTypeID()
    {
        static const int id = getNextTypeID();
        return id;
    }

private:
    static int getNextTypeID();
};

#endif
