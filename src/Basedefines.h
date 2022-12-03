#ifndef BASE_DEFINES_H
#define BASE_DEFINES_H

/// <summary>
/// This file holds definitions and typedef's that are used through out the project
/// </summary>

namespace BA_Engine
{
	/// <summary>
	/// Used to identify unique Components
	/// </summary>
	typedef std::uint64_t ComponentId;

	/// <summary>
	/// Every entity is just a unsigned __int64
	/// why:
	/// 	- No entity will have an id of negative or zero
	/// 	- Every entity is just a "collection" of components
	/// 		- Don't let the Entity Class fool you.
	/// 	- This allows us to track a lot of unique entities. (Your mad if you let it get into the 1000)
	/// </summary>
	typedef std::uint64_t EntityId;

	/// <summary>
	/// 
	/// </summary>
	typedef std::uint8_t SystemLayer;

	/// <summary>
	/// Component Data
	/// </summary>
	typedef unsigned char* CompData;

	/// <summary>
	// A Entity will never have an id of zero
	/// </summary>
	#define kInvlaid_Entity 0;
	
	/// <summary>
	// 
	/// </summary>
	#define kInvlaid_Component 0;
}

#endif //BASE_DEFINES_H