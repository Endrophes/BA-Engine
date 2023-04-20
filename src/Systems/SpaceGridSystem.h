/*******************************************************
 * Copyright (C) 2022 Bastien A. Auxer <auxerbastien@gmail.com>
 *
 * This file is part of BA-Engine project.
 *
 * BA-Engine project can not be copied and/or distributed without the express
 * permission of Bastien A. Auxer
 *******************************************************/

#ifndef SPACE_GRID_SYSTEM_H
#define SPACE_GRID_SYSTEM_H

#include "../PrecompiledHeader.h"
#include "../BaseClass/ISystem.h"
#include "../Components/Position.h"
#include "../libraries/Math.h"

/*
    Notes:
    * The lowest division SHOULD use EntityId for the objects in space.
    * Gridception - NOT super advised as it could get messy.
    * Think of a the battlefront 1 loading screen: https://youtu.be/wjVGjDoX3JQ
    * The T generic is provided to allow sub-grid division or Gridception.
    * typedef's are used to reduce code writes and copping.

*/

namespace BA_Engine
{
    /// <summary>
    /// Divides an area of space into a grid. Provides fast lookup when searching/Querying a system.
    /// </summary>
    template<class T>
    class SpaceGridSystem : public ISystem
    {

        /// <summary>
        /// 
        /// </summary>
        typedef GridBlockKey Math::Vector3I;

        /// <summary>
        /// 
        /// </summary>
        typedef GridBlock std::list<T>;

        /// <summary>
        /// Determines the size of each section of the grid.
        /// </summary>
        int gridScale;

        /// <summary>
        /// Holds a list of all Entities in a given Space
        /// </summary>
        std::map < GridBlockKey, GridBlock > grid;

    public:

        SpaceGridSystem(int pScale)
            :gridScale(pScale)
        {

        }

        ~SpaceGridSystem()
        {

        }

        /// <summary>
        /// Insert an object to track
        /// </summary>
        /// <param name="pT">Object to store</param>
        /// <param name="pos">Location of the Object</param>
        void add(T pT, Math::Vector3 pos)
        {
            GridBlockKey gbk = new Math::Vector3I(
                pos.mX / gridScale,
                pos.mY / gridScale,
                pos.mZ / gridScale
            );

            GridBlock gb = getGridBlock

            if (gb != grid.end())
            {
                gb.insert(pT);
            }
            else
            {
                grid.emplace(std::make_pair(gb, new GridBlock(pT)));
            }
        }

        /// <summary>
        /// Ejects an object from the tracking system.
        /// </summary>
        /// <param name="pT">Object to remove</param>
        void remove(T pT, Math::Vector3 pos)
        {
            
        }

    private:

        GridBlock& getGridBlock(Math::Vector3& pos)
        {
            GridBlockKey gbk = new Math::Vector3I(
                pos.mX / gridScale,
                pos.mY / gridScale,
                pos.mZ / gridScale
            );

            return &grid.find(gbk);
        }
    };
}

#endif //SPACE_GRID_SYSTEM_H