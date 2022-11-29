
#ifndef COMPONENT_SYSTEM_H
#define COMPONENT_SYSTEM_H

#include <map>
#include <vector>

#include "EntitySystem.h"
#include "../BaseClass/IComponent.h"

namespace BA_Engine
{

	#define kInvalid_Comp 0;

	//Controller and holder for all components and their entities
	class ComponentSystem
	{
		/// <summary>
		/// Pair's components to entities
		/// </summary>
		std::map<EntityId, std::vector<IComponent>> EntitesComponentTree;

	public:

		/// <summary>
		/// Create a new instance of a Component 
		/// </summary>
		/// <param name="entId">Parent Entity</param>
		static void addComponent(EntityId entId);

		/// <summary>
		/// Shutdown an instance of a Component
		/// </summary>
		/// <param name="entId">Parent Entity</param>
		static void removeComponent(EntityId entId);
	};

}

#endif //COMPONENT_SYSTEM_H