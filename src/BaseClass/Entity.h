#ifndef ENTITY_SYSTEM_H
#define ENTITY_SYSTEM_H

#include "../Utilities/RandomGenerator.h"
#include "../Basedefines.h"
#include "Registry.h"
#include "Scene.h"

namespace BA_Engine
{

	/// <summary>
	/// At it's core, this is just a nice a wrapper to keep my OO-Brain happy.
	/// </summary>
	class Entity
	{
	public:
		Entity(EntityId pEntId, Scene* pScene);
		~Entity();
	
		/// <summary>
		/// Return the Entities ID number
		/// </summary>
		EntityId getId();

		/// <summary>
		/// Added a component to the entity via the scene
		/// </summary>
		template<class T, typename... Args>
		void addComponent(Args&&... args);

		/// <summary>
		/// Checks to see if the component has been added to the entity
		/// </summary>
		template<class T>
		bool hasComponent();

		/// <summary>
		/// Removes a component from the entity
		/// </summary>
		template<class T>
		void removeComponent();

	private:

		/// <summary>
		/// Stores the number of the entity
		/// </summary>
		EntityId mEntId;
		
		/// <summary>
		/// Manages and controls all the entity's, scenes, and systems
		/// </summary>
		Scene* mScene;
	};

}

#endif //ENTITY_SYSTEM_H