/*******************************************************
 * Copyright (C) 2022 Bastien A. Auxer <auxerbastien@gmail.com>
 *
 * This file is part of BA-Engine project.
 *
 * BA-Engine project can not be copied and/or distributed without the express
 * permission of Bastien A. Auxer
 *******************************************************/

#ifndef COMPONENT_H
#define COMPONENT_H

#include "../PrecompiledHeader.h"
#include "../BaseClass/IComponent.h"

// Started getting really lazy and now I'm storing all my components in here

// TODO: make into structs?

namespace BA_Engine
{

    /// <summary>
    /// Life value of the Entity
    /// </summary>
    class Health : public IComponent
    {
    public:

        float mHealth;

        //Hit by
        std::vector< std::pair< std::string, float > > mHitBy;

        Health() = default;
        Health(const Health&) = default;
        Health(float pHealth)
            : mHealth(pHealth)
        {}

    };

    // ## Weapons ##

    /// <summary>
    /// A Romulan heavy weapon
    /// </summary>
    class Disruptor : public virtual IComponent
    {
    public:

        float mMaxRange;
        float mDamage;

        Disruptor() = default;
        Disruptor(const Disruptor&) = default;
        Disruptor(float pMaxRange, float pDamage)
            : mMaxRange(pMaxRange)
            , mDamage(pDamage)
        {}
    };

    /// <summary>
    /// Federation long range energy weapon
    /// </summary>
    class Phaser : public virtual IComponent
    {
    public:

        float mMaxRange;
        float mDamage;
        bool mOnline;

        Phaser() = default;
        Phaser(const Phaser&) = default;
        Phaser(float pMaxRange, float pDamage, bool pOnline)
            : mMaxRange(pMaxRange)
            , mDamage(pDamage)
            , mOnline(pOnline)
        {}
    };

    /// <summary>
    /// Federation short range heavy weapon
    /// </summary>
    class PhotonTorpedo : public virtual IComponent
    {
    public:

        float mMaxRange;
        float mDamage;
        bool mOnline;

        PhotonTorpedo() = default;
        PhotonTorpedo(const PhotonTorpedo&) = default;
        PhotonTorpedo(float pMaxRange, float pDamage, bool pOnline)
            : mMaxRange(pMaxRange)
            , mDamage(pDamage)
            , mOnline(pOnline)
        {}
    };

    // ## Sub-light thrusters ##

    /// <summary>
    /// A Standard drive engine for starship's
    /// </summary>
    class ImpulseEngines : public virtual IComponent
    {
    public:

        float mMaxSpeed;
        float mSpeed;
        bool mOnline;

        ImpulseEngines() = default;
        ImpulseEngines(const ImpulseEngines&) = default;
        ImpulseEngines(float pMaxSpeed, float pSpeed, bool pOnline)
            : mMaxSpeed(pMaxSpeed)
            , mSpeed(pSpeed)
            , mOnline(pOnline)
        {}
    };

}

#endif //COMPONENT_H