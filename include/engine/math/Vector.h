#pragma once

#include <concepts>

#include "raylib/raylib.h"

template<typename T>
requires std::integral<T> || std::floating_point<T>
class Vec3
{
public:
    Vec3() = default;
    
    Vec3(const T X, const T Y, const T Z) : m_X {X}, m_Y {Y}, m_Z {Z}
    {
    }
    
    Vec3 operator+(const Vec3& Rhs) const
    {
        return {m_X + Rhs.m_X, m_Y + Rhs.m_Y, m_Z + Rhs.m_Z};
    }
    
    explicit operator Vector3() const 
    {
        return {m_X, m_Y, m_Z};
    }
    
    T GetX() const
    {
        return m_X;
    }
    
    void SetX(const T X)
    {
        m_X = X;
    }
    
    T GetY() const
    {
        return m_Y;
    }
    
    void SetY(const T Y)
    {
        m_Y = Y;
    }
    
    T GetZ() const
    {
        return m_Z;
    }
    
    void SetZ(const T Z)
    {
        m_Z = Z;
    }
    
    String ToString() const
    {
        return "(" + std::to_string(m_X) + ", " + std::to_string(m_Y) + ", " + std::to_string(m_Z) + ")";
    }
private:
    T m_X;
    T m_Y;
    T m_Z;
};
