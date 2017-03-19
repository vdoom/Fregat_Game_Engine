#pragma once

#include <vector>

#include "Component.h"
#include "Entity.h"

namespace Fregat
{
	class ObjectManager
	{
	private:
		std::vector<Component*> m_inputComponents;
		std::vector<Component*> m_movementComponents;
		std::vector<Component*> m_physicksComponents;
		//std::vector<Component*> m_customComponents;
		std::vector<Component*> m_renderers;

		std::vector<Entity*> m_objects;
	public:
		ObjectManager(void);
		~ObjectManager(void);

		void Update(float t_tick);
	};
}

