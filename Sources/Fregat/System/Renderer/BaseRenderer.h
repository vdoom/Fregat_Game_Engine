//---------------------------------------------
// Base Rendering Subsystem
// Created by Volodymyr KUKSYNOK 
// 2017
//---------------------------------------------
#pragma once

#include <vector>
#include <memory>
#include <Fregat/System/Assets/Render/Components/RendererComponent.h> //"../../Assets/Render/Components/RendererComponent.h"
#include <Fregat/System/Core/IService.h>

namespace Fregat
{
	class Entity;
	namespace Render
	{
		//class RenderComponent;
		class ICamera;
		class BaseRenderer : public System::IService
		{
		protected:
			std::vector<std::shared_ptr<RenderComponent>> m_renderers; //TODO: Perhaps need different quaues of rendere
			ICamera* m_currentCamera;
		public:
			BaseRenderer(void);
			virtual ~BaseRenderer(void);

			RenderComponent* AddRendererComponent(Entity*);
			void RemoveRenderComponent(RenderComponent*);

			void SetCamera(ICamera*);

			virtual void Render();

			void Update() override
			{
				Render();
			}
		};
	}
}

