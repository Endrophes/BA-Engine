#include "PrecompiledHeader.h"
#include "Scene.h"
#include "Entity.h"
#include "../Utilities/RandomGenerator.h"

namespace BA_Engine
{
	Scene::Scene()
	{
		mRegistor = Registry();
	}

	Scene::~Scene()
	{
		//TODO: Shutdown mRegistor
	}

	Entity Scene::createEntity()
	{
		auto entId = mRegistor.createEntity();
		Entity newEnt = Entity(entId, this);
		return newEnt;
	}

	void Scene::removeEntity(Entity pEnt)
	{
		mRegistor.removeEntity(pEnt.getId());
	}

	void Scene::addSystem(const SystemLayer& pLayer, ISystem* pSys)
	{
		mRegistor.registerSystem(pLayer, pSys);
	}

	void Scene::onUpdate(const SystemLayer& pLayerToRun, const float pElapsedTime)
	{
		mRegistor.runSystems(pLayerToRun, pElapsedTime);
	}
}