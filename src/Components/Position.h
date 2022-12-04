#ifndef POSITION_H
#define POSITION_H

#include "../PrecompiledHeader.h"
#include "../BaseClass/IComponent.h"

namespace BA_Engine
{

    /// <summary>
    /// 2D coordinates on a map. 
    /// </summary>
    class Position : public virtual IComponent
    {
    public:

        float mX;
        float mY;

        Position() = default;
        Position(const Position&) = default;
        Position(const float& pX, const float& pY)
            : mX(pX)
            , mY(pY)
        {}
    };

}

#endif //POSITION_H