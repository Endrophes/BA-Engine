#ifndef SCENE_H
#define SCENE_H

#include "../PrecompiledHeader.h"
#include "IComponent.h"
#include "../Utilities/RandomGenerator.h"

#include <unordered_set>

namespace BA_Engine
{

	/// <summary>
	/// Stores a collections of entities for a world and ties Entities to it's components
	/// </summary>
	class Scene
	{

		/// <summary>
		/// Pair's components to entities
		/// </summary>
		std::map<EntityId, std::unordered_set<IComponent*>> EntitesComponentTree;


		/// <summary>
		/// Added a new entity to the map
		/// </summary>
		/// <returns>The Id of the new entity</returns>
		EntityId addEntity(EntityId entId = RandomGenerator::generateUUID_V1());

		/// <summary>
		/// Goes through a shutdown procedure and removes the Entity from the Scene
		/// </summary>
		/// <param name="entId">The Entity you want to remove</param>
		/// <returns>Boolean value on if it passed or failed</returns>
		bool removeEntity(EntityId entId);


		/// <summary>
		/// Iterate over the Scene and update the entities via their Components
		/// </summary>
		void onUpdate();
	};

}

#endif //SCENE_H