//---------------------------------------------
// Assets Manager
// Created by Volodymyr KUKSYNOK 
// 2017
//---------------------------------------------
#pragma once

#include <map>
#include <memory>
#include <vector>

namespace Fregat
{
	namespace Render
	{
		class TextureBase;
		class Shader;
		class MeshBase;
		class MaterialBase;
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
			//std::map<std::string, std::unique_ptr<MaterialBase>> m_materials;
			std::map<std::string, MaterialBase*> m_materials; //TMP solution

			//AssetsManager();

			TextureBase* LoadTexture(const std::string&);
			MeshBase* LoadMesh(const std::string&);
			
		public:
			AssetsManager();
			TextureBase* GetTexture(const std::string&);
			MeshBase* GetMesh(const std::string&);
			Shader* GetShader(const std::string&);
			MaterialBase* GetMaterial(const std::string&, Shader*, TextureBase*);
			void Update();
			void Init();

			std::vector<MeshBase*> GetMeshes(const std::string&);
		};
	}
}