/*******************************************************
 * Copyright (C) 2022 Bastien A. Auxer <auxerbastien@gmail.com>
 *
 * This file is part of BA-Engine project.
 *
 * BA-Engine project can not be copied and/or distributed without the express
 * permission of Bastien A. Auxer
 *******************************************************/

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