#ifndef BASE_DEFINES_H
#define BASE_DEFINES_H

/// <summary>
/// This file holds definitions and typedef's that are used through out the project
/// </summary>

namespace BA_Engine
{
	/// I don't need all of cstdint. (Yet)
	
	typedef unsigned __int8  uint8_t;
	typedef unsigned __int64 uint64_t;

	typedef uint64_t ComponentId;
	typedef uint64_t EntityId;
	// Every entity is just a unsigned __int64
	/*
		why:
			- No entity will have an id of negative or zero
			- Every entity is just a "collection" of components
				- Don't let the Entity Class fool you.
			- This allows us to track a lot of unique entities. (Your mad if you let it get into the 1000)
	*/

	// A Entity will never have an id of zero
	#define kInvlaid_Entity 0;
	
	// A 
	#define kInvlaid_Component 0;
}

#endif //BASE_DEFINES_H