#include "EntitySystem.h"

EntityId EntitySystem::createEntity()
{
    //KISS for now. just hold one number, send it's current value out, then increment the number
    return currentId++;
}
