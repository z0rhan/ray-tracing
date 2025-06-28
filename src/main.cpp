#include "math/vec3.hpp"
#include "utils/color.hh"
#include "ray.hpp"

#include <iostream>
#include <ostream>

color rayColor(Ray& ray);

int main(int argc, char *argv[]) {
    // Image dimensions
    const auto aspectRatio = 16.0 / 9.0;
    int imageWidth = 800;
    int imageHeight = static_cast<int>(imageWidth / aspectRatio);
    imageHeight = (imageHeight < 1) ? 1 : imageHeight;

    // Viewport dimensions for camera
    auto focalLength = 1.0;
    auto viewportHeight = 2.0;
    auto viewportWidht = viewportHeight * (static_cast<double>(imageWidth) / imageHeight);
    auto cameraCenter = math::vec3(0,0,0);

    // Vectors
    auto viewportU = math::vec3(viewportWidht, 0, 0);
    auto viewportV = math::vec3(0, -viewportHeight, 0);

    // Distance between each pixels
    auto pixelDeltaU = viewportWidht / imageWidth;
    auto pixelDeltaV = viewportHeight / imageHeight;

    // Top left pixel
    auto viewportTopLeft = cameraCenter - math::vec3(0, 0, focalLength) - viewportU/2 - viewportV/2;
    auto pixel00Pos = viewportTopLeft + 0.5 * (pixelDeltaU + pixelDeltaV);
    
    std::cout << "P3\n"
              << imageWidth << ' ' << imageHeight << "\n"
              << "255\n";

    for (unsigned int row = 0; row < imageHeight; ++row) {
        std::clog << "\rScanlines remaining " << imageHeight - row << std::flush;

        for (unsigned int col = 0; col < imageWidth; ++col) {
            auto pixelCenter = pixel00Pos + (row * pixelDeltaV) + (col * pixelDeltaU);
            auto rayDirection = pixelCenter - cameraCenter;
            Ray ray(cameraCenter, rayDirection);

            auto pixelColor = rayColor(ray);

            writeColor(std::cout, pixelColor);
        }
    }

    std::clog << "\rDone                                \n";

    return 0;
}

color rayColor(Ray& ray)
{
    auto unitVector = math::normalize(ray.direction());
    auto a = 0.5 * (unitVector.y() + 1); // Map [-1, 1] to [0, 1]
    return (1 - a) * math::vec3(1.0, 1.0, 1.0) + a * math::vec3(0.5, 0.7, 1.0);
}
