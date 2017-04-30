//---------------------------------------------
// Base interface for textures
// Created by Volodymyr KUKSYNOK 
// 2017
//---------------------------------------------
#pragma once

#include <GL/glew.h>// TODO: need to remove frome here
#include "../../AssetsManagement/AssetSys.h"

namespace Fregat
{
	namespace Render
	{
		class TextureBase : public System::AssetSys
		{
		protected:
			GLuint m_textureID;
		public:
			TextureBase():AssetSys(nullptr)
			{}
			~TextureBase() override {}
			inline GLuint GetTexturePointer() const
			{
				return m_textureID;
			}
		};
	}
}