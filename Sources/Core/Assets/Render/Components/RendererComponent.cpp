#include "RendererComponent.h"
#include "../Mesh/MeshBase.h"
#include "../Material/SimpleMaterial.h"
#include "../../../Math/Mat4.h"

namespace Fregat
{
	namespace Render
	{

		RenderComponent::RenderComponent(Entity& t_tt) : Component(t_tt)
		{}

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