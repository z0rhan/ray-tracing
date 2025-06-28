#ifndef RAY_HH
#define RAY_HH

#include "math/vec3.hpp"

class Ray
{
public:
    Ray() {};
    Ray(math::vec3& origin, math::vec3& direction) : m_origin(origin), m_direction(direction) {};
    ~Ray() {};

    inline const math::vec3& origin() const {return m_origin;}
    inline const math::vec3& direction() const {return m_direction;}
    inline math::vec3 at(float point) const {return m_origin + m_direction * point;}
private:
    math::vec3 m_origin;
    math::vec3 m_direction;
};

#endif // RAY_HH
