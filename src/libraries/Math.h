/*******************************************************
 * Copyright (C) 2022 Bastien A. Auxer <auxerbastien@gmail.com>
 *
 * This file is part of BA-Engine project.
 *
 * BA-Engine project can not be copied and/or distributed without the express
 * permission of Bastien A. Auxer
 *******************************************************/


#ifndef MATH_H
#define MATH_H

namespace BA_Engine
{
	namespace Math
	{
		/// <summary>
		/// Object made of three floats 
		/// </summary>
		class Vector3
		{
		public:

			float mX;
			float mY;
			float mZ;

			Vector3(const float& pX, const float& pY, const float& pZ = 0)
				: mX(pX)
				, mY(pY)
				, mZ(pZ)
			{}
		};

		/// <summary>
		/// Object made of three integers 
		/// </summary>
		class Vector3I
		{
		public:

			int mX;
			int mY;
			int mZ;

			Vector3I(const int& pX, const int& pY, const int& pZ = 0)
				: mX(pX)
				, mY(pY)
				, mZ(pZ)
			{}

			Vector3I(Vector3 vec3)
				: mX((int) vec3.mX)
				, mY((int) vec3.mY)
				, mZ((int) vec3.mZ)
			{}
		};
	}
}

#endif //MATH_H