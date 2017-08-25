#pragma once

#include "Vec3.h"

namespace Fregat 
{
	namespace Math
	{
		class AABB
		{
			Vec3 m_AA;
			Vec3 m_BB;
			Vec3 m_center;

		public: 
			AABB()
			{}

			AABB(Vec3 t_AA, Vec3 t_BB)
			{
				m_AA = t_AA;
				m_BB = t_BB;
				m_center = (m_BB + m_AA) / 2;
			}

			inline const Vec3 GetAA() const { return m_AA; }
			inline const Vec3 GetBB() const { return m_BB; }
			inline const Vec3 GetCenter() const { return m_center; }
		};
	}
}