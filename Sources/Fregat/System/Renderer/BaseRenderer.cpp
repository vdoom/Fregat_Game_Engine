#include "BaseRenderer.h"
#include <Fregat/System/Core/Entity.h>

namespace Fregat
{
	namespace Render
	{

		BaseRenderer::BaseRenderer(void) : m_currentCamera(nullptr)
		{
			m_currentCamera = nullptr;
		}
		
		BaseRenderer::~BaseRenderer(void)
		{
		}

		RenderComponent* BaseRenderer::AddRendererComponent(Entity* t_entity)
		{
			auto rndr = std::shared_ptr<RenderComponent>(new RenderComponent(*t_entity));
			t_entity->AddComponent(rndr.get());
			m_renderers.push_back(rndr);
			return rndr.get();
		}

		void BaseRenderer::RemoveRenderComponent(RenderComponent*)
		{
			//TODO: need implement;
		}

		void BaseRenderer::SetCamera(ICamera* t_camera)
		{
			m_currentCamera = t_camera;
		}

		void BaseRenderer::Render()
		{}
	}
}
