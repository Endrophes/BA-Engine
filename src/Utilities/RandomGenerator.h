#ifndef RANDOM_GENERATOR_H
#define RANDOM_GENERATOR_H

#include <random>

namespace BA_Engine
{

	typedef unsigned __int64 uint64_t;

	/// <summary>
	/// Use for random number generation for the UUID
	/// </summary>
	static std::random_device s_RandomDevice;
	static std::mt19937_64 s_Engine(s_RandomDevice());
	static std::uniform_int_distribution<uint64_t> s_UniformDistribution;

	//Define
	class RandomGenerator
	{

	public:

		/// <summary>
		/// A simple version of generating a UUID.
		/// </summary>
		/// <returns>uint64_t</returns>
		static uint64_t generateUUID_V1()
		{
			return s_UniformDistribution(s_Engine);
		}

	};

}

#endif //RANDOM_GENERATOR_H