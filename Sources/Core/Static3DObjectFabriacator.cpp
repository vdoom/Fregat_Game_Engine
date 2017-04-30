#include "Static3DObjectFabriacator.h"
#include "Assets/AssetsManagement/AssetsManager.h"
#include "Assets/Render/Texture/Texture2D.h"//TODO: move to asset root folder
#include "Assets/Render/Shader/Shader.h"//TODO: move to asset root folder
#include "Assets/Render/Mesh/MeshPlane.h"//TODO: move to asset root folder
#include "Assets/Render/Mesh/MeshStatic.h"
#include "Assets/Render/Material/SimpleMaterial.h"//TODO: move to asset root folder
#include "System/Renderer/OpenGL33Renderer.h"
#include "System/Renderer/Camera.h"
#include "Entity.h"

namespace Fregat
{
	Static3DObjectFabriacator::Static3DObjectFabriacator(System::AssetsManager* t_assetsManager, Render::BaseRenderer* t_baseRenderer)
	{
		m_assetsManager = t_assetsManager;
		m_baseRenderer = t_baseRenderer;
	}


	Static3DObjectFabriacator::~Static3DObjectFabriacator()
	{
	}

	Entity* Static3DObjectFabriacator::FabricateStatic3DObject(const std::string& t_modelPath, const std::string& t_texturePath, const std::string& t_shaderName)
	{
		Render::TextureBase* texture2D = m_assetsManager->GetTexture(t_texturePath.c_str());
		Render::Shader* shaderTest = m_assetsManager->GetShader("default");
		Render::MeshBase* cude = m_assetsManager->GetMesh(t_modelPath.c_str());
		Render::MaterialBase* materialTest = m_assetsManager->GetMaterial("tmpMat", shaderTest, texture2D);
		Entity* tstObj = new Entity();

		auto* rdrCmp = m_baseRenderer->AddRendererComponent(tstObj);
		rdrCmp->InitRenderer(cude, (Render::SimpleMaterial*)materialTest);

		return tstObj;
	}

	std::vector<Entity*> Static3DObjectFabriacator::FabricateComplexStatic3DObject(const std::string& t_modelPath, const std::string& t_texturePath, const std::string& t_shaderName)
	{
		Render::TextureBase* texture2D = m_assetsManager->GetTexture(t_texturePath.c_str());
		Render::Shader* shaderTest = m_assetsManager->GetShader("default");
		Render::MaterialBase* materialTest = m_assetsManager->GetMaterial("tmpMat", shaderTest, texture2D);
		
		std::vector<Entity*> objects;
		auto&& tmp = m_assetsManager->GetMeshes(t_modelPath.c_str());

		for (size_t i = 0; i < tmp.size(); ++i)
		{
			Entity* tstObj = new Entity();
			//Render::MeshBase* cude = m_assetsManager->GetMesh(t_modelPath.c_str());

			auto* rdrCmp = m_baseRenderer->AddRendererComponent(tstObj);
			rdrCmp->InitRenderer(tmp.at(i), (Render::SimpleMaterial*)materialTest);
			objects.push_back(tstObj);
		}
		return objects;
	}

}