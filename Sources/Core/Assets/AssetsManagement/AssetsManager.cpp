#include "AssetsManager.h"
#include "../Render/Texture/Texture2D.h"
#include "../Render/Mesh/MeshPlane.h"
#include "../Render/Shader/Shader.h"

namespace Fregat
{
	namespace System
	{
		using namespace Fregat::Render;

		AssetsManager::AssetsManager()
		{}

		TextureBase* AssetsManager::LoadTexture(const std::string& t_texturePath)
		{
			if(m_textures.find(t_texturePath) != m_textures.end())
			{
				auto texture = new Texture2D();
				texture->InitTexture(t_texturePath);
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
	}
}