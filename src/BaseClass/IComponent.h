#ifndef I_COMPONENT_H
#define I_COMPONENT_H

#include "../Basedefines.h"

namespace BA_Engine
{

	/// <summary>
	/// A simple class that holds only data values
	/// this is used to help the Registry store the components
	/// </summary>
	class IComponent
	{
	public:

		virtual ~IComponent() {}

	};

}

#endif //I_COMPONENT_H