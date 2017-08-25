#pragma once

#include "MathCommon.h"

namespace Fregat 
{
	namespace Math
	{

		struct Vec2
		{
			union
			{
				struct { float x, y; };
				float v[2];
			};
		public:
			inline Vec2():
				x(0.0f),
				y(0.0f)
			{
			}
			
			inline Vec2(float t_x, float t_y):
				x(t_x),
				y(t_y)
			{
			}
		
			inline Vec2(const Vec2& t_vec):
				x(t_vec.x),
				y(t_vec.y)
			{
			}
		
			inline float GetX()const {return x;}
			inline float GetY()const {return y;}
		
			inline void Set(float t_x, float t_y)
			{//TODO: need think about caching vector length
				x = t_x; 
				y = t_y;
			}

			inline void Set(const Vec2& t_vec)
			{//TODO: need think about caching vector length
				x = t_vec.x;
				y = t_vec.y;
			}
		
			inline void SetX(float t_x)
			{
				x = t_x;
			}
		
			inline void SetY(float t_y)
			{
				y = t_y;
			}
		
			inline float operator[](size_t t_i)       
			{ return v[t_i]; }
			
			inline float operator[](size_t t_i)const 
			{ return v[t_i]; }

			inline Vec2& operator=(const Vec2& t_vec) { Set(t_vec); return *this; }
		
			inline const Vec2 operator+(const Vec2& t_v) const { return Vec2(x + t_v.x, y + t_v.y); }
			inline const Vec2 operator-(const Vec2& t_v) const { return Vec2(x - t_v.x, y - t_v.y); }
			inline const Vec2 operator*(const Vec2& t_v) const { return Vec2(x * t_v.x, y * t_v.y); }
			inline const Vec2 operator*(float t_f)       const { return Vec2(x * t_f,   y * t_f);   }
			inline const Vec2 operator/(float t_f)       const { return Vec2(x / t_f,   y / t_f);   }
		
			inline Vec2& operator+=(const Vec2& t_v) { x += t_v.x; y += t_v.y; return *this; }
			inline Vec2& operator-=(const Vec2& t_v) { x -= t_v.x; y -= t_v.y; return *this; }
			inline Vec2& operator*=(float t_f)       { x *= t_f;   y *= t_f;   return *this; }
			inline Vec2& operator/=(float t_f)       { x /= t_f;   y /= t_f;   return *this; }
		};
		
		inline bool operator==(const Vec2& t_vec1, const Vec2& t_vec2)
		{
			return (t_vec1.x == t_vec2.x) && (t_vec1.y == t_vec2.y);
		}

		inline bool operator!=(const Vec2& t_vec1, const Vec2& t_vec2)
		{
			return (t_vec1.x != t_vec2.x) || (t_vec1.y != t_vec2.y);
		}
	}
}