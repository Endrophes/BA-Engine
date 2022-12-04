#ifndef MATH_UTILS_H
#define MATH_UTILS_H

#include <cmath>

namespace BA_Engine
{

    /// <summary>
    /// Collection of math functions
    /// </summary>
    class MathUtils
    {

    public:

        static float lerp(float a, float b, float t)
        {
            return a + t * (b - a);
        }

        /// <summary>
        /// Gets the distance between two points in space
        /// </summary>
        static float getDistance(float x1, float y1, float x2, float y2)
        {
            return (float) std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2) * 1.0);
        }

    };

}

#endif //MATH_UTILS_H