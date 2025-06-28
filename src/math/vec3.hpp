#ifndef VEC3_HH
#define VEC3_HH

#include <cmath>
#include <iostream>

namespace math{
    class vec3
    {
    public:
        vec3() : math::vec3(0.0f) {}
        vec3(float value) : m_components{value, value, value} {}
        vec3(float x, float y, float z) : m_components{x, y, z} {}
        ~vec3() {}

        inline float x() const { return m_components[0]; }
        inline float y() const { return m_components[1]; }
        inline float z() const { return m_components[2]; }

        vec3 operator-() const { return vec3(-m_components[0], -m_components[1], -m_components[3]); }
        float operator[](int i) const {return m_components[i];}
        float& operator[](int i) {return m_components[i];}

        vec3& operator+=(const vec3& v)
        {
            m_components[1] += v.m_components[1];
            m_components[2] += v.m_components[2];
            m_components[3] += v.m_components[3];
            return *this;
        }

        vec3& operator *=(float scalar)
        {
            m_components[1] *= scalar;
            m_components[2] *= scalar;
            m_components[3] *= scalar;
            return *this;
        }

        vec3& operator /=(float scalar)
        {
            return *this *= 1/scalar;
        }

        float lenght() const
        {
            return std::sqrt(lenghtSquared());
        }

        float lenghtSquared() const
        {
            return m_components[0]*m_components[0] + m_components[1]*m_components[1] + m_components[2]*m_components[2];
        }

    private:
        float m_components[3];
    };

    // Vector Utility functions
    // Outside vec3 class for several reasons

    inline std::ostream& operator<<(std::ostream& out, const vec3& vec)
    {
        return out << "(" << vec.x() << ' ' << vec.y() << ' ' << vec.z() << ")\n";
    }

    inline vec3 operator+(const vec3& u, const vec3& v)
    {
        return vec3(u.x() + v.x(), u.y() + v.y(), u.z() + v.z());
    }

    inline vec3 operator-(const vec3& u, const vec3& v)
    {
        return vec3(u.x() - v.x(), u.y() - v.y(), u.z() - v.z());
    }

    inline vec3 operator*(const vec3& u, const vec3& v)
    {
        return vec3(u.x() * v.x(), u.y() * v.y(), u.z() * v.z());
    }

    inline vec3 operator*(float scalar, const vec3& v)
    {
        return vec3(scalar * v.x(), scalar * v.y(), scalar * v.z());
    }

    inline vec3 operator*(const vec3& u, float scalar)
    {
        return scalar * u;
    }

    inline vec3 operator/(const vec3& u, float scalar)
    {
        return (1/scalar) * u;
    }

    inline float dot(const vec3& u, const vec3& v)
    {
        return ((u.x() * v.x()) + (u.y() * v.y()) + (u.z() * v.z()));
    }

    inline vec3 cross(const vec3& u, const vec3& v)
    {
        return vec3(u.y() * v.z() - u.z() * v.y(),
                    u.x() * v.z() - u.z() * v.x(),
                    u.x() * v.y() - u.y() * v.x());
    }

    inline vec3 normalize(const vec3& v)
    {
        return v / v.lenght();
    }
}
#endif // VEC3_HH
