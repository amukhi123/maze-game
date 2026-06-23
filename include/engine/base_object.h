#pragma once

#include "engine/types.h"

class BaseObject
{
public:
    BaseObject(const String& Name) : m_Name {Name}
    {
    }

    String GetName() const
    {
        return m_Name;
    }
private:
    String m_Name;
};
