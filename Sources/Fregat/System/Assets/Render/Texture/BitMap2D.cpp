#include "BitMap2D.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_pixels.h>

namespace Fregat
{
	namespace System
	{

		BitMap2D::BitMap2D(AssetsManager* t_manager, const std::string& t_path, const std::string& t_name) :
			AssetBin(t_manager, t_path, t_name),
			m_loadedSurface(nullptr)
		{
		}

		BitMap2D::~BitMap2D()
		{
			if (m_loadedSurface != nullptr)
				SDL_FreeSurface(m_loadedSurface);
		}

		bool BitMap2D::Load()
		{
			m_loadedSurface = nullptr;//std::unique_ptr<SDL_Surface> loadedSurface(nullptr);
			bool success = true;
			if (SDL_Init(SDL_INIT_VIDEO) < 0)
			{
				printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Initialize PNG loading 
				int imgFlags = IMG_INIT_JPG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
				else
				{
					m_loadedSurface = IMG_Load(m_path.c_str());
				}
			}
			return success;
		}
	}
}