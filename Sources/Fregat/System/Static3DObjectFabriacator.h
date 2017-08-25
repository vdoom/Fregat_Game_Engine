//TEMPORAL EXPERIMENTAL CLASS 
//GENERATE 3D Object from file via fector + asset manager
#pragma once

#include <string>
#include <vector>
#include <memory>
//#include "Entity.h"

namespace Fregat
{
	namespace System
	{
		class AssetsManager;
	}
	namespace Render
	{
		class BaseRenderer;
	}

	class Entity;

	class Static3DObjectFabriacator
	{
	private:
		System::AssetsManager* m_assetsManager;
		Render::BaseRenderer* m_baseRenderer;
	public:
		Static3DObjectFabriacator(System::AssetsManager* t_assetsManager, Render::BaseRenderer* t_baseRenderer);
		~Static3DObjectFabriacator();

		Entity* FabricateStatic3DObject(const std::string& t_modelPath, const std::string& t_texturePath, const std::string& t_shaderName);
		std::vector<std::unique_ptr<Entity>> FabricateComplexStatic3DObject(const std::string& t_modelPath, const std::string& t_texturePath, const std::string& t_shaderName);
	};
}
