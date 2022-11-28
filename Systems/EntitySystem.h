#ifndef ENTITY_SYSTEM_H
#define ENTITY_SYSTEM_H

namespace BA_Engine
{

	#define kInvlaid_Entity 00000

	// Every entity is just a unsigned __int32
	/*
		why:
			- No entity will have an id of negative or zero
			- Every entity is a "collection" of components
			- This allows us to track 4,294,967,295 unique entities. (Your mad if you let it get that high)
	*/

	typedef unsigned __int32 EntityId;

	//Controller for Entity Id's
	class EntitySystem
	{

	private:


		EntityId currentId;

	public:

		/// <summary>
		/// Generate and return the next unique EntityId
		/// </summary>
		/// <returns> The ID of the new Entity </returns>
		EntityId createEntity();

	};

}

#endif //ENTITY_SYSTEM_H