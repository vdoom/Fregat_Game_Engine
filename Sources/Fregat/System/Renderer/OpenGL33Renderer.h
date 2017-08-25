//---------------------------------------------
// OpenGL 3.3 Rendering Subsystem
// Created by Volodymyr KUKSYNOK 
// 2017
//---------------------------------------------
#pragma once

#include "BaseRenderer.h"

namespace Fregat
{
	namespace Render
	{
		class OpenGL33Renderer : public BaseRenderer
		{
		public:
			OpenGL33Renderer();
			virtual ~OpenGL33Renderer();

			virtual void Render();
		};
	}
}