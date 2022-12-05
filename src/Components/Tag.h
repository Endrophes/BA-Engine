/*******************************************************
 * Copyright (C) 2022 Bastien A. Auxer <auxerbastien@gmail.com>
 *
 * This file is part of BA-Engine project.
 *
 * BA-Engine project can not be copied and/or distributed without the express
 * permission of Bastien A. Auxer
 *******************************************************/

#ifndef TAG_COMPONENT_H
#define TAG_COMPONENT_H

#include "../PrecompiledHeader.h"
#include "../BaseClass/IComponent.h"

namespace BA_Engine
{

    /// <summary>
    /// Simple Identifier on an Entity
    /// </summary>
    class Tag : public IComponent
    {
    public:

        std::string mTag;

        Tag() = default;
        Tag(const Tag&) = default;
        Tag(std::string pTag)
            : mTag(pTag) {}
    };

}

#endif //TAG_COMPONENT_H