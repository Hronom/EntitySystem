#include "TypeInfoUtils.h"

int TypeInfoUtils::m_nextTypeID = 0;

int TypeInfoUtils::getNextTypeID()
{
    return m_nextTypeID++;
}

