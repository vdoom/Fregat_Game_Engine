//---------------------------------------------
// Base Rendering Subsystem
// Created by Volodymyr KUKSYNOK 
// 2017
//---------------------------------------------
#pragma once

#include <vector>
#include <memory>
#include "../../Assets/Render/Components/RendererComponent.h"

namespace Fregat
{
	class Entity;
	namespace Render
	{
		//class RenderComponent;
		class Camera;
		class BaseRenderer
		{
		protected:
			std::vector<std::shared_ptr<RenderComponent>> m_renderers; //TODO: Perhaps need different quaues of rendere
			Camera* m_currentCamera;
		public:
			BaseRenderer(void);
			virtual ~BaseRenderer(void);

			RenderComponent* AddRendererComponent(Entity*);
			void RemoveRenderComponent(RenderComponent*);

			void SetCamera(Camera*);

			virtual void Render();
		};
	}
}

