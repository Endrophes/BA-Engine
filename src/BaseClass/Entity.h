#ifndef ENTITY_SYSTEM_H
#define ENTITY_SYSTEM_H

#include "../Utilities/RandomGenerator.h"
#include "../Basedefines.h"
#include "Scene.h"

#include <WeakReference.h>


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
		/// 
		/// </summary>
		/// <returns>The id of the given entity</returns>
		EntityId getId();

		/// <summary>
		/// 
		/// </summary>
		template<typename T>
		void addComponent();


		template<typename T>
		bool hasComponent();

		/// <summary>
		/// 
		/// </summary>
		template<typename T>
		void removeComponent();

	private:

		/// <summary>
		/// Stores the number of the entity
		/// </summary>
		EntityId mEntId;
		
		/// <summary>
		/// 
		/// </summary>
		Scene* mScene;
	};

}

#endif //ENTITY_SYSTEM_H