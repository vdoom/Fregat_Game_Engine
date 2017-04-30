//---------------------------------------------
// Representing 2D textures for OpenGL
// Created by Volodymyr KUKSYNOK 
// 2017
//---------------------------------------------
#pragma once

#include "TextureBase.h"
#include <string>

namespace Fregat
{
	namespace Render
	{
		class Texture2D : public TextureBase 
		{
		public:
			Texture2D();
			~Texture2D() override;
			//TEmporary solution!!! It will be moved to asset manager loaders
			//void InitTexture(std::string); //TODO: perhaps need create fabrica and move this code there.
			
			virtual bool CreateAsset(System::AssetBin* t_assetBinData) override;

			//static Texture2D CreateTexture(std::string);//TEST METHODS, REMOVE IN FUTURE
		private:
		};
	}
}