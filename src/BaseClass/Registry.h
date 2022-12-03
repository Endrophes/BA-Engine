#ifndef REGISTRY_SYSTEM_H
#define REGISTRY_SYSTEM_H

#include "../PrecompiledHeader.h"
#include "../Basedefines.h"
#include "../BaseClass/IComponent.h"
#include "../BaseClass/ISystem.h"

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
        const EntityId createEntity();

        /// <summary>
        /// With a given EntityId, go through all it's components and shutdown/clean-up
        /// and remove the entry.
        /// </summary>
        void removeEntity(const EntityId pEntId);

        //## Components ##

        /// <summary>
        /// Used when you first want to use the component as we need to track it by a key value
        /// other than it's string name
        /// </summary>
        template<class T>
        void registerComponent();

        /// <summary>
        /// Returned the ID for the given registered component
        /// </summary>
        template<class T>
        ComponentId getComponentId();

        /// <summary>
        /// Confirms that the component has a ID associated with it.
        /// </summary>
        template<class T>
        bool isComponentRegistered();

        /// <summary>
        /// Confirms that the component has a ID associated with it.
        /// Internal function that is used to reduce redundancy
        /// </summary>
        bool isComponentRegistered(unsigned char* pCompName);

        /// <summary>
        /// Creates a new instance of the given component and pass in
        /// the arguments
        /// </summary>
        template<class T, typename... Args>
        T* addComponent(const EntityId& pEntid, Args&&... args);
        
        /// <summary>
        /// Confirms that the component has been attached to the
        /// the given Entity
        /// </summary>
        template<class T>
        bool hasComponent(const EntityId& pEntId);

        /// <summary>
        /// Gets an instance of a component that is attached to the Entity
        /// </summary>
        template<class T>
        T* getComponent(const EntityId& pEntId);

        /// <summary>
        /// Removes an instance of the component that is attached to the Entity
        /// </summary>
        template<class T>
        void removeComponent(const EntityId& pEntId);

        /// <summary>
        /// Gets a vector of entities that have a specific component
        /// </summary>
        template<class T>
        std::vector<EntityId> getEntitiesWith();

        //## Systems ##

        /// <summary>
        /// Adds a given system to a specific layer
        /// </summary>
        void registerSystem(const SystemLayer& pLayer, ISystem* pSys);
    
        /// <summary>
        /// Runs all systems on a given layer
        /// </summary>
        void runSystems(const SystemLayer& pLayer, const float pElapsedTime);

    private:

        /// <summary>
        /// A map that set's up the components ID and matches it to the components name
        /// </summary>
        std::unordered_map< unsigned char *, ComponentId > mComponentRegMap;

        /// <summary>
        /// A map that ties the Entity Id to its components
        /// </summary>
        std::unordered_map<
            EntityId,
            std::unordered_map< ComponentId, IComponent >
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