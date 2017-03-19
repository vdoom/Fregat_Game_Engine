#pragma once

//#include <vector>
#include "ObjectManager.h"

namespace Fregat
{
	class BaseScene
	{
	private:
		ObjectManager m_objectManager;
	public:
		BaseScene(void);
		~BaseScene(void);

		virtual void Update(float t_tick);
	};
}
