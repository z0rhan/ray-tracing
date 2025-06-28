#ifndef COLOR_HH
#define COLOR_HH

#include "math/vec3.hpp"

#include <iostream>

using color = math::vec3;

void writeColor(std::ostream& out, const color& pixelColor);

#endif // COLOR_HH
