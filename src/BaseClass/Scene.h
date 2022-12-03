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