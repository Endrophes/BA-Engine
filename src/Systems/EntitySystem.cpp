#include "EntitySystem.h"

namespace BA_Engine
{

    EntityId EntitySystem::createEntity()
    {
        //KISS for now. just hold one number, send it's current value out, then increment the number
        return (EntityId)RandomGenerator::generateUUID_V1();
    }

}
