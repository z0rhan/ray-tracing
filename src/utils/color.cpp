#include "color.hh"

void writeColor(std::ostream& out, const color& pixelColor)
{
    auto r = pixelColor.x();
    auto g = pixelColor.y();
    auto b = pixelColor.z();

    // map the [0,1] components value to byte range [0, 255]
    int rByte = static_cast<int>(255 * r);
    int gByte = static_cast<int>(255 * g);
    int bByte = static_cast<int>(255 * b);

    out << rByte << ' ' << gByte << ' ' << bByte << '\n';
}
