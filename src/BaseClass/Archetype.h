#ifndef ARCHETYPE_H
#define ARCHETYPE_H

#include "../PrecompiledHeader.h"
#include "../Basedefines.h"

namespace BA_Engine
{
    /// <summary>
    /// Collections of Components and Entities
    /// </summary>
    struct Archetype
    {
        /// <summary>
        /// 
        /// </summary>
        std::vector<ComponentId> mType;

        /// <summary>
        /// 
        /// </summary>
        std::vector<CompData> mComponentData;

        /// <summary>
        /// Hold all id's for the given Entity
        /// </summary>
        std::vector<EntityId> mEntityIds;

        /// <summary>
        /// Holds the size of each Component data values
        /// </summary>
        std::vector<std::size_t> mComponentDataSize;
    };

}

#endif //ARCHETYPE_H
