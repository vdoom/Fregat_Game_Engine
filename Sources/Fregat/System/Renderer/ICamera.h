//---------------------------------------------
// Camera Interface 
// used for Rendering System
// Created by Volodymyr KUKSYNOK 
// 2017
//---------------------------------------------
#pragma once

#include "../../MathLib/MatOperations.h"
#include "../../MathLib/Vec3.h"

namespace Fregat
{
	using namespace Math;
	//class Transform;
	namespace Render
	{
		class ICamera
		{
		public:
			virtual Mat4 GetProjMatrix() = 0;
			virtual Mat4 GetMatrix() = 0;
			virtual Vec3 GetPosition() = 0;
		};
	}
}
