/*******************************************************
 * Copyright (C) 2022 Bastien A. Auxer <auxerbastien@gmail.com>
 *
 * This file is part of BA-Engine project.
 *
 * BA-Engine project can not be copied and/or distributed without the express
 * permission of Bastien A. Auxer
 *******************************************************/

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