/*******************************************************
 * Copyright (C) 2022 Bastien A. Auxer <auxerbastien@gmail.com>
 *
 * This file is part of BA-Engine project.
 *
 * BA-Engine project can not be copied and/or distributed without the express
 * permission of Bastien A. Auxer
 *******************************************************/

#ifndef SCENE_H
#define SCENE_H

#include "../PrecompiledHeader.h"
#include "IComponent.h"
#include "../Utilities/RandomGenerator.h"
#include "Registry.h"

#include <unordered_set>

namespace BA_Engine
{

	class Entity; // Forward declaration

	/// <summary>
	/// Stores a collections of entities for a world and ties Entities to it's components
	/// </summary>
	class Scene
	{

	private:

		/// <summary>
		/// Pair's components to entities
		/// </summary>
		Registry mRegistor;

		friend class Entity;

	public:
		Scene();
		~Scene();

		/// <summary>
		/// Added a new entity to the map
		/// </summary>
		Entity createEntity();

		/// <summary>
		/// Goes through a shutdown procedure and removes the Entity from the Scene
		/// </summary>
		void removeEntity(Entity pEnt);

		
		/// <summary>
		/// Get a vector of entities that have this component
		/// </summary>
		template<class T>
		std::vector<Entity> getEntitiesWith()
		{
			std::vector<EntityId> entityIds = mRegistor.getEntitiesWith<T>();
			std::vector<Entity> entites;
			for (EntityId entId : entityIds)
			{
				entites.push_back(Entity(entId, this));
			}

			return entites;
 		}

		/// <summary>
		/// 
		/// </summary>
		void addSystem(const SystemLayer& pLayer, ISystem* pSys);

		/// <summary>
		/// Iterate over the Systems and update the Scene
		/// </summary>
		void onUpdate(const SystemLayer& pLayerToRun, const float pElapsedTime);
	};

}

#endif //SCENE_H