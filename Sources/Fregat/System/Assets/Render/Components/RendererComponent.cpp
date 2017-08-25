#include "RendererComponent.h"
#include "../Mesh/MeshBase.h"
#include "../Material/SimpleMaterial.h"
#include <Fregat/MathLib/Mat4.h>

namespace Fregat
{
	namespace Render
	{

		RenderComponent::RenderComponent(Entity& t_tt) : 
			Component(t_tt),
			m_material(nullptr),
			m_mesh(nullptr)
		{
			//m_typeName = std::string("RenderComponent");
		}

		RenderComponent::~RenderComponent()
		{}
		
		void RenderComponent::InitRenderer(MeshBase* t_mesh, SimpleMaterial* t_material)
		{
			m_mesh = t_mesh;
			m_material = t_material;
		}//, Mat4* t_transform){}
		
		void RenderComponent::Update(float t_tick)
		{
		}

	}
}