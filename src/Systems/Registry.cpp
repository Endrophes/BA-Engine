#include "PrecompiledHeader.h"
#include "../Utilities/RandomGenerator.h"
#include "Registry.h"
#include <algorithm>

namespace BA_Engine
{

	const EntityId Registry::createEntity()
	{
		const EntityId entId = RandomGenerator::generateUUID_V1();
		
		//TODO: Check if ID has been used
		
		std::unordered_map< ComponentId, IComponent > newMap;
		mEntityCompMap.emplace(
			std::pair<
				EntityId,
				std::unordered_map< ComponentId, IComponent >
			>(entId, newMap)
		);

		return entId;
	}

	void Registry::removeEntity(const EntityId pEntId)
	{
		if (mEntityCompMap.find(pEntId) == mEntityCompMap.cend())
		{
			log_d("Entity was already removed or does not exist")
			return;
		}

		std::unordered_map< ComponentId, IComponent > mCompMap = mEntityCompMap[pEntId];

		//Remove Entity from lists of each Component
		for (auto& comp : mCompMap)
		{
			auto entityVec = mComponentStorageMap[comp.first];
			entityVec.erase(
				std::remove(entityVec.begin(), entityVec.end(), pEntId),
				entityVec.end()
			);
		}

		//Clear the components
		mCompMap.clear();

		//Remove the Entity
		mEntityCompMap.erase(pEntId);
	}

	template<class T>
	void Registry::registerComponent()
	{
		auto compName = typeid(T).name();

		if (isComponentRegistered<T>())
		{
			log_d("Component has already been registered")
			return;
		}

		//TODO: Replace with counter
		ComponentId newCompId = RandomGenerator::generateUUID_V1();

		mComponentRegMap.emplace(
			std::pair<
				compName,
				newCompId
			>
		);
	}

	template<class T>
	ComponentId Registry::getComponentId()
	{
		auto compName = typeid(T).name();
		if (!isComponentRegistered(compName))
		{
			return kInvlaid_Component;
		}

		return mComponentRegMap[compName];
	}

	template<class T>
	bool Registry::isComponentRegistered()
	{
		auto compName = typeid(T).name();
		return (mComponentRegMap.find(compName) != mComponentRegMap.end());
	}

	bool Registry::isComponentRegistered(unsigned char* pCompName)
	{
		return (mComponentRegMap.find(pCompName) != mComponentRegMap.end());
	}

	template<class T>
	T* Registry::addComponent(const EntityId& pEntId)
	{
		auto compName = typeid(T).name();

		if (!isComponentRegistered(compName))
		{
			log_d("Component has not been register")
			return;
		}

		if (mEntityCompMap.find(pEntId) != mEntityCompMap.end())
		{
			log_d("Entity has not been register")
			return;
		}

		if (hasComponent<T>(pEntId))
		{
			log_d("Entity already has the component")
			return;
		}

		ComponentId& compId = mComponentRegMap[compName];

		T* newComp = new T;

		//Add the new component
		mEntityCompMap[pEntId][compId] = newComp;

		//Record who is now using the component
		mComponentStorageMap[compId].push_back(pEntId);

		return newComp;
	}

	template<class T>
	bool Registry::hasComponent(const EntityId& pEntId)
	{
		ComponentId compId = getComponentId<T>();
		
		if (mEntityCompMap.find(pEntId) == mEntityCompMap.end())
		{
			log_d("Entity has not been register")
			return false;
		}

		if (mEntityCompMap[pEntId].find(compId) != mEntityCompMap[pEntId].end())
		{
			return true;
		}
		else
		{
			return false;
		}
	}


	template<class T>
	T* Registry::getComponent(const EntityId& pEntId)
	{
		ComponentId compId = getComponentId<T>();

		if (mEntityCompMap.find(pEntId) == mEntityCompMap.end())
		{
			log_d("Entity has not been register")
			return;
		}

		if (mEntityCompMap[pEntId].find(compId) != mEntityCompMap[pEntId].end())
		{
			return &mEntityCompMap[pEntId][compId];
		}
		else
		{
			return nullptr;
		}
	}

	template<class T>
	void Registry::removeComponent(const EntityId& pEntId)
	{
		auto compName = typeid(T).name();
		ComponentId compId = getComponentId<T>();

		if (!isComponentRegistered(compName))
		{
			log_d("Component has not been register")
			return;
		}

		if (mEntityCompMap.find(pEntId) != mEntityCompMap.end())
		{
			log_d("Entity has not been register")
			return;
		}

		if (!hasComponent<T>(pEntId))
		{
			log_d("Component was removed from the entity")
			return;
		}

		// Remove entity from the list
		mComponentStorageMap[compId].erase(pEntId);

		// Remove the component from the Entity list
		mEntityCompMap[pEntId].erase(compId);
	}

}