//---------------------------------------------
// Base interface for textures
// Created by Volodymyr KUKSYNOK 
// 2017
//---------------------------------------------
#pragma once

#include <GL/glew.h>// TODO: need to remove frome here
#include "../../AssetsManagement/AssetBase.h"

namespace Fregat
{
	namespace Render
	{
		class TextureBase : public System::AssetBase
		{
		protected:
			GLuint m_textureID;
		public:
			TextureBase(){}
			~TextureBase() override {}
			inline GLuint GetTexturePointer() const
			{
				return m_textureID;
			}
		};
	}
}