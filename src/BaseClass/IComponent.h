#ifndef I_COMPONENT_H
#define I_COMPONENT_H

#include "../Basedefines.h"

namespace BA_Engine
{

	//Define
	class IComponent
	{


	public:

		/// <summary>
		/// Grab or initialize parts of the component before start up
		/// </summary>
		/// <param name="entId">Id of the parent entity</param>
		virtual void setup(EntityId entId) = 0;

		/// <summary>
		/// Ran every frame to make changes to logic
		/// </summary>
		/// <param name="entId">Id of the parent entity</param>
		virtual void update(EntityId entId) = 0;

		/// <summary>
		/// Close out and clear data when removing the component
		/// </summary>
		/// <param name="entId">Id of the parent entity</param>
		virtual void shutdown(EntityId entId) = 0;
	};

}

#endif //I_COMPONENT_H