/*******************************************************
 * Copyright (C) 2022 Bastien A. Auxer <auxerbastien@gmail.com>
 *
 * This file is part of BA-Engine project.
 *
 * BA-Engine project can not be copied and/or distributed without the express
 * permission of Bastien A. Auxer
 *******************************************************/

#ifndef SHIP_REGISTRY_H
#define SHIP_REGISTRY_H

#include "../PrecompiledHeader.h"
#include "../BaseClass/IComponent.h"

namespace BA_Engine
{

    /// <summary>
    /// Details about the ships origin and Name
    /// </summary>
    class ShipRegistry : public IComponent
    {
    public:

        std::string mName;
        std::string mRace;
        uint8_t mNumber;

        ShipRegistry() = default;
        ShipRegistry(const ShipRegistry&) = default;
        ShipRegistry(std::string pName, std::string pRace, uint8_t pNumber)
            : mName(pName)
            , mRace(pRace)
            , mNumber(pNumber)
        {}
    };

}

#endif //SHIP_REGISTRY_H