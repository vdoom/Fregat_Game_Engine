#include "AssetsManager.h"
#include "../Render/Texture/Texture2D.h"
#include "../Render/Mesh/MeshPlane.h"
#include "../Render/Shader/Shader.h"
#include "../Render/Mesh/MeshStatic.h"
#include "../Render/Material/SimpleMaterial.h"
#include "../Render/Texture/BitMap2D.h"
#include "../Render/Mesh/Geometry3D.h"
#include "../Render/Mesh/ComplexGeometry3D.h"
#include <memory>
//#include "../../System/IO/FileFormats/ParsersDataStructures.h"
//#include "../../System/IO/FileFormats/OBJimporter.h"

namespace Fregat
{
	namespace System
	{
		using namespace Fregat::Render;

		AssetsManager::AssetsManager()
		{}

		TextureBase* AssetsManager::LoadTexture(const std::string& t_texturePath)
		{
			//if(m_textures.find(t_texturePath) != m_textures.end())
			{
				auto texture = new Texture2D();
				BitMap2D bm2d(this, t_texturePath);
				bm2d.Load();
				texture->CreateAsset(&bm2d);
				//texture->InitTexture(t_texturePath);
				m_textures[t_texturePath] = std::move(std::unique_ptr<TextureBase>(texture));
				return texture;
			}

			return nullptr;
		}

		TextureBase* AssetsManager::GetTexture(const std::string& t_texturePath)
		{
			auto texture = m_textures.find(t_texturePath);
			if(texture != m_textures.end())
			{
				return texture->second.get();
			}
			else
			{
				return LoadTexture(t_texturePath);
			}
			return nullptr;
		}

		MeshBase* AssetsManager::LoadMesh(const std::string& t_path)
		{
			//if (m_meshes.find(t_path) != m_meshes.end())
			{
				//Loading In single thread
				MeshStatic* tmp = new MeshStatic();
				Geometry3D geom(this, t_path);
				geom.Load();
				tmp->CreateAsset(&geom);
				m_meshes[t_path] = std::move(std::unique_ptr<MeshBase>(tmp));
				return tmp;
			}
			return nullptr;
		}

		MeshBase* AssetsManager::GetMesh(const std::string& t_path)
		{
			auto mesh = m_meshes.find(t_path);
			if (mesh != m_meshes.end())
			{
				return mesh->second.get();
			}
			else
			{
				return LoadMesh(t_path);
			}
			return nullptr;
		}

		std::vector<MeshBase*> AssetsManager::GetMeshes(const std::string& t_path)
		{
			std::vector<MeshBase*> meshes;// = new std::vector<MeshBase*>();
			ComplexGeometry3D geom(this, t_path);
			geom.Load();
			std::vector<std::unique_ptr<Geometry3D>>* tmp = geom.GetData();
			for (size_t i = 0; i < tmp->size(); ++i)
			{
				MeshStatic* tmpMesh = new MeshStatic();
				tmpMesh->CreateAsset((*tmp)[i].get());
				meshes.push_back(tmpMesh);
				m_meshes[t_path+"_"+ tmpMesh->GetName()] = std::move(std::unique_ptr<MeshBase>(tmpMesh));
			}
			return meshes;
		}


		Shader* AssetsManager::GetShader(const std::string& t_shaderName)
		{
			auto shader = m_shaders.find(t_shaderName);
			if (shader != m_shaders.end())
			{
				return shader->second.get();
			}
			return nullptr;
		}

		MaterialBase* AssetsManager::GetMaterial(const std::string& t_name, Shader* t_shader, TextureBase* t_texture)
		{
			auto mat = m_materials.find(t_name);
			if (mat != m_materials.end())
			{
				return mat->second.get();
			}
			else
			{
				SimpleMaterial* materialTest = new SimpleMaterial();
				materialTest->InitMaterial(std::shared_ptr<Fregat::Render::Shader>(t_shader),
					std::shared_ptr<Fregat::Render::TextureBase>(t_texture));
				m_materials[t_name] = std::move(std::unique_ptr<MaterialBase>(materialTest));
				return materialTest;
			}
			return nullptr;
		}

		void AssetsManager::Update()
		{
			//validating assets loaded in separate thread
		}

		void AssetsManager::Init()
		{
			IService::Init();

			std::unique_ptr<Fregat::Render::Shader> shaderTest = std::move(Fregat::Render::Shader::CreateShader("simple_without_light.vert", "simple_without_light.frag"));
			m_shaders["default"] = std::move(shaderTest);
			auto shaderTestLight = std::move(Fregat::Render::Shader::CreateShader("simple_with_light.vert", "simple_with_light.frag"));
			m_shaders["withLight"] = std::move(shaderTestLight);
			//init internal states
			//Load base shaders
		}
	}
}