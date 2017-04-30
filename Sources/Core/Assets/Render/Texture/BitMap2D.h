//---------------------------------------------
// BitMap2D is a container for bimap loaded in paralell thread
// Can be used for loading Texture2D data
// Created by Volodymyr KUKSYNOK 
// 2017
//---------------------------------------------
#pragma once
#include "../../AssetsManagement/AssetBin.h"

struct SDL_Surface;

namespace Fregat
{
	namespace System
	{
		class BitMap2D : public AssetBin
		{
		protected:
			SDL_Surface* m_loadedSurface;

			
		public:
			explicit BitMap2D(AssetsManager* t_manager, const std::string& t_path = std::string(""), const std::string& t_name = std::string(""));

			virtual ~BitMap2D() override;
			virtual bool Load() override;
			inline SDL_Surface* GetData() { return m_loadedSurface; }
		};
	}
}

