#include "PrecompiledHeader.h"
#include "Entity.h"

namespace BA_Engine
{

	Entity::Entity(EntityId pEntId, Scene* pScene)
		: mEntId(pEntId)
		, mScene(pScene)
	{

	}

	Entity::~Entity()
	{

	}

	EntityId Entity::getId()
	{
		return mEntId;
	}

	template<class T, typename... Args>
	void Entity::addComponent(Args&&... args)
	{
		mScene->mRegistor.addComponent<T>(mEntId, std::forward<Args>(args)...);
	}

	template<class T>
	bool Entity::hasComponent()
	{
		return mScene->mRegistor.hasComponent<T>(mEntId);
	}

	template<class T>
	void Entity::removeComponent()
	{
		mScene->mRegistor.removeComponent<T>(mEntId);
	}

}
