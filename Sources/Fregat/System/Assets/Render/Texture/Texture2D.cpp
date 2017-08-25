#include "Texture2D.h"
#include "BitMap2D.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_pixels.h>
#include <memory>

namespace Fregat
{
	namespace Render
	{
		using namespace Fregat::System;

		Texture2D::Texture2D()
		{}

		Texture2D::~Texture2D()
		{
			//TODO: should free resources and delete dats
		}


		bool Texture2D::CreateAsset(System::AssetBin* t_assetBinData)
		{

			BitMap2D* bitmap = (BitMap2D*)t_assetBinData;
			
			int mode = GL_RGB;

			if (bitmap->GetData()->format->BytesPerPixel == 4)
			{
				mode = GL_RGBA;
			}
			//---------------------------------------------------
			// Reauest fom OpenGL free texure index
			glGenTextures(1, &m_textureID);

			// Binde Texture index
			glBindTexture(GL_TEXTURE_2D, m_textureID);

			// Setup linear filtration for texture
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

			// Setup wrap mode for texture
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

			// placing raw texture data into texture buffer
			glTexImage2D(GL_TEXTURE_2D, 0, mode/*GL_RGB*/, bitmap->GetData()->w, bitmap->GetData()->h, 0, mode/*GL_RGB8*/,
				GL_UNSIGNED_BYTE, (const GLvoid*)(bitmap->GetData()->pixels));
			//------------------------------------------------------------
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, m_textureID);

			return true;//TODO: need refine
		}
	}
}