#ifndef REGISTRY_SYSTEM_H
#define REGISTRY_SYSTEM_H

#include "../PrecompiledHeader.h"
#include "../Basedefines.h"
#include "../BaseClass/IComponent.h"
#include "../BaseClass/ISystem.h"
#include "../BaseClass/Archetype.h"

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

        struct Record
        {
            /// <summary>
            /// 
            /// </summary>
            Archetype* arch = nullptr;

            /// <summary>
            /// 
            /// </summary>
            std::size_t index = 0;
        };

    public:

        //## Entities ##

        /// <summary>
        /// 
        /// </summary>
        void registerEntity(const EntityId pEntId);

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
        T* isComponentRegistered();

        /// <summary>
        /// 
        /// </summary>
        template<class T>
        void addComponent();
        
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
        void registerSystem(const std::uint8_t& pLayer, ISystem* pSys);
    
        /// <summary>
        /// 
        /// </summary>
        void runSystems(const std::uint8_t& pLayer, const float pElapsedTime);

        //## Other ##

        Archetype* getArchetype(const ArchetypeId& pArcId);

    private:

        /// <summary>
        /// 
        /// </summary>
        std::unordered_map < ComponentId, IComponent* > mComponentIdMap;

        /// <summary>
        /// 
        /// </summary>
        std::unordered_map < EntityId, Record > mEntityArchetypeMap;

        /// <summary>
        /// Holds all Archetype's
        /// </summary>
        std::vector< Archetype > mArchetypeStorage;

        /// <summary>
        /// Ties Entities (By Id) to a given record
        /// </summary>
        std::unordered_map < EntityId, Record > mEntityArchetypeMap;
    };

}

#endif //REGISTRY_SYSTEM_H