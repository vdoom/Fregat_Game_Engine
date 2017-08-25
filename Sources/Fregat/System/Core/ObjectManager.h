#pragma once

#include <vector>

#include "Component.h"
#include "Entity.h"
#include <Fregat/System/Core/IService.h>
#include <memory>

namespace Fregat
{
	namespace System
	{
		class ObjectManager : public IService
		{
		protected:
			//std::vector<Component*> m_inputComponents;
			//std::vector<Component*> m_movementComponents;
			//std::vector<Component*> m_physicksComponents;
			//std::vector<Component*> m_customComponents;
			//std::vector<Component*> m_renderers;

			std::vector<std::unique_ptr<Entity>> m_objects;
		public:
			ObjectManager(void);
			virtual ~ObjectManager(void);

			void Update() override {}
			void Init() override 
			{
				IService::Init();
			}

			//void Update(float t_tick);
		};
	}
}

