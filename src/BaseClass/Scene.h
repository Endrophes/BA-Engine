#ifndef SCENE_H
#define SCENE_H

#include "IComponent.h"
#include "../Systems/EntitySystem.h"

#include <map>
#include <vector>

namespace BA_Engine
{

	/// <summary>
	/// Stores a collections of entities for a world.
	/// </summary>
	class Scene
	{

		/// <summary>
		/// Pair's components to entities
		/// </summary>
		std::map<EntityId, std::vector<IComponent>> EntitesComponentTree;

	};

}

#endif //SCENE_H