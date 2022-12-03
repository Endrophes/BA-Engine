#include "PrecompiledHeader.h"
#include "Entity.h"

namespace BA_Engine
{

	Entity::Entity(EntityId pEntId, Scene* pScene)
	{

	}

	Entity::~Entity()
	{

	}

	template<class T, std::enable_if<std::is_base_of<IComponent, T>::value>>
	void Entity::addComponent()
	{

	}

	template<class T, std::enable_if<std::is_base_of<IComponent, T>::value>>
	bool Entity::hasComponent()
	{
		return false;
	}

	template<class T, std::enable_if<std::is_base_of<IComponent, T>::value>>
	void Entity::removeComponent()
	{

	}

}
