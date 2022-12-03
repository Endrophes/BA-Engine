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
        /// 
        /// </summary>
        const EntityId createEntity();

        /// <summary>
        /// With a given EntityId, go through all it's components and shutdown/clean-up
        /// and remove the entry.
        /// </summary>
        void removeEntity(const EntityId pEntId);

        //## Components ##

        /// <summary>
        /// 
        /// </summary>
        template<class T>
        void registerComponent();

        /// <summary>
        /// 
        /// </summary>
        template<class T>
        bool isComponentRegistered();

        /// <summary>
        /// 
        /// </summary>
        template<class T>
        void addComponent(const EntityId& pEntid);
        
        /// <summary>
        /// 
        /// </summary>
        template<class T>
        T* hasComponent(const EntityId& pEntId);

        /// <summary>
        /// 
        /// </summary>
        template<class T>
        T* getComponent(const EntityId& pEntId);

        /// <summary>
        /// 
        /// </summary>
        template<class T>
        void removeComponent();

        /// <summary>
        /// 
        /// </summary>
        template<class... Ts>
        std::vector<EntityId> getEntitiesWith();

        //## Systems ##

        /// <summary>
        /// 
        /// </summary>
        void registerSystem(const SystemId& pLayer, ISystem* pSys);
    
        /// <summary>
        /// 
        /// </summary>
        void runSystems(const SystemId& pLayer, const float pElapsedTime);

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
        std::unordered_map< SystemId, ISystem* > mSystemRegMap;

    };

}

#endif //REGISTRY_SYSTEM_H