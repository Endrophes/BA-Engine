#ifndef I_SYSTEM_H
#define I_SYSTEM_H

#include "../Basedefines.h"
#include "Archetype.h"

namespace BA_Engine
{

    /// <summary>
    /// Operates on a given Layer of Components
    /// </summary>
    class ISystem
    {

        virtual ~ISystem() {}

        virtual ArchetypeId getArchId() const = 0;

        virtual void run(const float elapsedTime, Archetype* arType) = 0;

    };

}

#endif //I_SYSTEM_H