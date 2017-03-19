//---------------------------------------------
// Assets Manager
// Created by Volodymyr KUKSYNOK 
// 2017
//---------------------------------------------
#pragma once

#include <map>
#include <memory>

namespace Fregat
{
	namespace Render
	{
		class TextureBase;
		class Shader;
		class MeshBase;
	}

	namespace System
	{
		using namespace Fregat::Render;

		class ServiceLocator;

		class AssetsManager
		{
			friend ServiceLocator;
			
		private:

			std::map<std::string, std::unique_ptr<TextureBase>> m_textures;
			std::map<std::string, std::unique_ptr<MeshBase>> m_meshes;
			std::map<std::string, std::unique_ptr<Shader>> m_shaders;

			AssetsManager();

			TextureBase* LoadTexture(const std::string&);
		public:
			TextureBase* GetTexture(const std::string&);
		};
	}
}