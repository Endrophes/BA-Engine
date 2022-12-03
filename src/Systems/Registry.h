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
        template<class T, std::enable_if<std::is_base_of<IComponent, T>::value>>
        void registerComponent();

        /// <summary>
        /// 
        /// </summary>
        template<class T, std::enable_if<std::is_base_of<IComponent, T>::value>>
        bool isComponentRegistered();

        /// <summary>
        /// 
        /// </summary>
        template<class T, std::enable_if<std::is_base_of<IComponent, T>::value>>
        void addComponent(const EntityId& pEntid);
        
        /// <summary>
        /// 
        /// </summary>
        template<class T, std::enable_if<std::is_base_of<IComponent, T>::value>>
        T* hasComponent(const EntityId& pEntId);

        /// <summary>
        /// 
        /// </summary>
        template<class T, std::enable_if<std::is_base_of<IComponent, T>::value>>
        T* getComponent(const EntityId& pEntId);


        /// <summary>
        /// 
        /// </summary>
        template<class T, std::enable_if<std::is_base_of<IComponent, T>::value>>
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

    private:

        /// <summary>
        /// 
        /// </summary>
        std::unordered_map < const char* , IComponent* > mComponentIdMap;

    };

}

#endif //REGISTRY_SYSTEM_H