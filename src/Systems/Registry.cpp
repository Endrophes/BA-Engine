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
}