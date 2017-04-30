#pragma once

#include "Vec2.h"

namespace Fregat 
{
	namespace Math
	{
		class Rect
		{
		private:
			Vec2 m_bottomLeft;
			Vec2 m_topRight;
		public:
			inline Rect(void)
			{}
			inline Rect(Vec2 t_bottomLeft, Vec2 t_topRight)
			{
				Set(t_bottomLeft, t_topRight);
			}
			inline Rect(float t_minX, float t_minY, float t_maxX, float t_maxY)
			{
				Set(t_minX, t_minY, t_maxX, t_maxY);
			}
			//TODO: need override copy constructor and operator=
			inline Rect::~Rect(void)
			{}
			inline void Rect::Set(Vec2 t_bottomLeft, Vec2 t_topRight)
			{
				m_bottomLeft = t_bottomLeft;
				m_topRight = t_topRight;
			}
			inline void Rect::Set(float t_minX, float t_minY, float t_maxX, float t_maxY)
			{
				m_bottomLeft.Set(t_minX, t_minY);
				m_topRight.Set(t_maxX, t_maxY);
			}
			inline Vec2 GetTopRight() const {return m_topRight;}
			inline Vec2 GetBottomLeft() const {return m_bottomLeft;}
			inline float GetMinX() const {return m_bottomLeft.GetX();}
			inline float GetMaxX() const {return m_topRight.GetX();}
			inline float GetMinY() const {return m_bottomLeft.GetY();}
			inline float GetMaxY() const {return m_topRight.GetY();}
		};

		inline bool operator==(const Rect& t_rect1, const Rect& t_rect2)
		{
			return (t_rect1.GetTopRight() == t_rect2.GetTopRight()) && 
				(t_rect1.GetBottomLeft() == t_rect2.GetBottomLeft());
		}
	}
}