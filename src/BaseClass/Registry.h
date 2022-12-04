#ifndef REGISTRY_SYSTEM_H
#define REGISTRY_SYSTEM_H

#include "../PrecompiledHeader.h"
#include "../Basedefines.h"
#include "../BaseClass/IComponent.h"
#include "../BaseClass/ISystem.h"

#include <type_traits>

namespace BA_Engine
{

    /// <summary>
    /// Here is where the black magic happens to tie
    /// all the Components and Entities/EntId's together.
    /// Also the heart of the ECS system
    /// </summary>
    class Registry
    {
        /*
            Things to keep in mind:
                - An Entity is just uint64_t (Used like a key in a map)
                - AND an Entity is built up of Components
                - For optimal performance, things need to be in straight line in memory
        */
    private:



    public:

        //## Entities ##

        /// <summary>
        /// Creates and registers an Entity Id
        /// </summary>
        const EntityId createEntity()
        {
            const EntityId entId = RandomGenerator::generateUUID_V1();

            //TODO: Check if ID has been used

            std::unordered_map< ComponentId, IComponent* > newMap;
            mEntityCompMap.emplace(
                std::pair<
                EntityId,
                std::unordered_map< ComponentId, IComponent* >
                >(entId, newMap)
            );

            return entId;
        }

        /// <summary>
        /// With a given EntityId, go through all it's components and shutdown/clean-up
        /// and remove the entry.
        /// </summary>
        void removeEntity(const EntityId pEntId)
        {
            if (mEntityCompMap.find(pEntId) == mEntityCompMap.cend())
            {
                log_d("Entity was already removed or does not exist");
                return;
            }

            std::unordered_map< ComponentId, IComponent* > mCompMap = mEntityCompMap[pEntId];

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

        //## Components ##

        /// <summary>
        /// Used when you first want to use the component as we need to track it by a key value
        /// other than it's string name
        /// </summary>
        template<class T>
        void registerComponent()
        {
            auto compName = typeid(T).name();

            if (isComponentRegistered<T>())
            {
                log_d("Component has already been registered");
                return;
            }

            //TODO: Replace with counter
            ComponentId newCompId = RandomGenerator::generateUUID_V1();

            mComponentRegMap.emplace(
                std::pair<
                const char*, ComponentId
                >
                (compName, newCompId)
            );
        }

        /// <summary>
        /// Returned the ID for the given registered component
        /// </summary>
        template<class T>
        ComponentId getComponentId()
        {
            auto compName = typeid(T).name();
            if (!isComponentRegistered(compName))
            {
                return kInvlaid_Component;
            }

            return mComponentRegMap[compName];
        }

        /// <summary>
        /// Confirms that the component has a ID associated with it.
        /// </summary>
        template<class T>
        bool isComponentRegistered()
        {
            auto compName = typeid(T).name();
            return (mComponentRegMap.find(compName) != mComponentRegMap.end());
        }

        /// <summary>
        /// Confirms that the component has a ID associated with it.
        /// Internal function that is used to reduce redundancy
        /// </summary>
        bool isComponentRegistered(const char* pCompName)
        {
            return (mComponentRegMap.find(pCompName) != mComponentRegMap.end());
        }


        //TODO: I need to return a reference and not a pointer
        /// <summary>
        /// Creates a new instance of the given component and pass in
        /// the arguments
        /// </summary>
        template<class T, typename... Args>
        T* addComponent(const EntityId& pEntId, Args&&... args)
        {
            auto compName = typeid(T).name();
            
            //TODO: Figure out who should register the components
            if (!isComponentRegistered(compName))
            {
                registerComponent<T>(); // If not then register it! - says 11 pm me
                //log_d("Component has not been register");
                //_ASSERT(false);
            }

            if (mEntityCompMap.find(pEntId) == mEntityCompMap.end())
            {
                log_d("Entity has not been register");
                _ASSERT(false);
            }

            if (hasComponent<T>(pEntId))
            {
                log_d("Entity already has the component");
                _ASSERT(false);
            }

            ComponentId& compId = mComponentRegMap[compName];

            auto newComp = new T((args)...);

            //Add the new component
            mEntityCompMap[pEntId][compId] = dynamic_cast<IComponent *>(newComp);

            //Record who is now using the component
            mComponentStorageMap[compId].push_back(pEntId);

            return newComp;
        }
        
        /// <summary>
        /// Confirms that the component has been attached to the
        /// the given Entity
        /// </summary>
        template<class T>
        bool hasComponent(const EntityId& pEntId)
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

        /// <summary>
        /// Gets an instance of a component that is attached to the Entity
        /// </summary>
        template<class T>
        T* getComponent(const EntityId& pEntId)
        {
            ComponentId compId = getComponentId<T>();

            if (mEntityCompMap.find(pEntId) == mEntityCompMap.end())
            {
                log_d("Entity has not been register");
                _ASSERT(false);
            }

            if (mEntityCompMap[pEntId].find(compId) != mEntityCompMap[pEntId].end())
            {
                //Gives a warning, but I will take it.
                return dynamic_cast<T*>(mEntityCompMap[pEntId][compId]);
            }
            else
            {
                log_d("Component is not part of the entity");
                _ASSERT(false);
            }
        }

        /// <summary>
        /// Removes an instance of the component that is attached to the Entity
        /// </summary>
        template<class T>
        void removeComponent(const EntityId& pEntId)
        {
            auto compName = typeid(T).name();
            ComponentId compId = getComponentId<T>();

            if (!isComponentRegistered(compName))
            {
                log_d("Component has not been register");
                return;
            }

            if (mEntityCompMap.find(pEntId) != mEntityCompMap.end())
            {
                log_d("Entity has not been register");
                return;
            }

            if (!hasComponent<T>(pEntId))
            {
                log_d("Component was removed from the entity");
                return;
            }

            // Remove entity from the list
            mComponentStorageMap[compId].erase(pEntId);

            // Remove the component from the Entity list
            mEntityCompMap[pEntId].erase(compId);
        }

        /// <summary>
        /// Gets a vector of entities that have a specific component
        /// </summary>
        template<class T>
        std::vector<EntityId> getEntitiesWith()
        {
            if (!isComponentRegistered<T>())
            {
                log_d("Component has not been register");

                std::vector<EntityId> entIds;
                return entIds;
            }

            ComponentId compId = getComponentId<T>();

            return mComponentStorageMap[compId];

        }

        //## Systems ##

        /// <summary>
        /// Adds a given system to a specific layer
        /// </summary>
        void registerSystem(const SystemLayer& pLayer, ISystem* pSys)
        {
            if (mSystemRegMap.find(pLayer) == mSystemRegMap.end())
            {
                std::vector<ISystem*> sys;
                sys.push_back(pSys);
                mSystemRegMap.emplace(
                    std::pair<SystemLayer, std::vector<ISystem*>>(
                        pLayer,
                        sys
                        ));
            }
            else
            {
                mSystemRegMap[pLayer].push_back(pSys);
            }
        }
    
        /// <summary>
        /// Runs all systems on a given layer
        /// </summary>
        void runSystems(const SystemLayer& pLayer, const float pElapsedTime)
        {
            if (mSystemRegMap.find(pLayer) != mSystemRegMap.end())
            {
                log_d("Layer has not been set");
                return;
            }

            for (auto sys : mSystemRegMap[pLayer])
            {
                sys->run(pElapsedTime);
            }
        }

    private:

        /// <summary>
        /// A map that set's up the components ID and matches it to the components name
        /// </summary>
        std::unordered_map< const char *, ComponentId > mComponentRegMap;

        /// <summary>
        /// A map that ties the Entity Id to its components
        /// </summary>
        std::unordered_map<
            EntityId,
            std::unordered_map< ComponentId, IComponent* >
        > mEntityCompMap;

        /// <summary>
        /// Holds each instance of a component by it's ID
        /// </summary>
        std::unordered_map< ComponentId, std::vector<EntityId> > mComponentStorageMap;

        /// <summary>
        /// Holds all systems and keyed by their Id
        /// </summary>
        std::unordered_map< SystemLayer, std::vector<ISystem*> > mSystemRegMap;

    };

}

#endif //REGISTRY_SYSTEM_H