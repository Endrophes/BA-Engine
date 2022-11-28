
#ifndef ComponentSystem
#define ComponentSystem

#include "EntitySystem.h"
#include "../BaseClass/IComponent.h"
#include <map>
#include <vector>

namespace BA_Engine
{

	#define kInvalid_Comp 00000

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

#endif //ComponentSystem