#ifndef I_COMPONENT_H
#define I_COMPONENT_H

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
		virtual void setup(EntityId entId);

		/// <summary>
		/// Ran every frame to make changes to logic
		/// </summary>
		/// <param name="entId">Id of the parent entity</param>
		virtual void update(EntityId entId);

		/// <summary>
		/// Close out and clear data when removing the component
		/// </summary>
		/// <param name="entId">Id of the parent entity</param>
		virtual void shutdown(EntityId entId);
	};

}

#endif //I_COMPONENT_H