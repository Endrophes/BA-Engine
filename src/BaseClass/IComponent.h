#ifndef I_COMPONENT_H
#define I_COMPONENT_H

#include "../Basedefines.h"

namespace BA_Engine
{

	/// <summary>
	/// 
	/// </summary>
	class IComponent
	{


	public:

		virtual ~IComponent() {}

		/// <summary>
		/// Grab or initialize parts of the component before start up
		/// </summary>
		virtual void setup(CompData data) const = 0;

		/// <summary>
		/// Ran every frame to make changes to logic
		/// </summary>
		virtual void update(CompData data) const = 0;

		/// <summary>
		/// 
		/// </summary>
		virtual void moveData(CompData source, CompData destination) const = 0;

		/// <summary>
		/// Close out and clear data when removing the component
		/// </summary>
		virtual void shutdown(CompData data) const = 0;

		/// <summary>
		/// Get the size of data for the given component
		/// </summary>
		virtual std::size_t getSize() const = 0;
	};

}

#endif //I_COMPONENT_H