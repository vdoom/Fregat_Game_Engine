#pragma once

#include "MathCommon.h"

namespace Fregat 
{
	namespace Math
	{

		struct Vec3
		{
			union
			{
				struct { float x, y, z; };
				float v[3];
			};
		public:
			inline Vec3():
				x(0.0f),
				y(0.0f),
				z(0.0f)
			{
			}
			
			inline Vec3(float t_x, float t_y, float t_z):
				x(t_x),
				y(t_y),
				z(t_z)
			{
			}
		
			inline Vec3(const Vec3& t_vec):
				x(t_vec.x),
				y(t_vec.y),
				z(t_vec.z)
			{
			}
		
			inline float GetX()const {return x;}
			inline float GetY()const {return y;}
			inline float GetZ()const {return z;}
		
			inline void Set(float t_x, float t_y, float t_z)
			{//TODO: need think about caching vector length
				x = t_x; 
				y = t_y;
				z = t_z;
			}
		
			inline void SetX(float t_x)
			{
				x = t_x;
			}
		
			inline void SetY(float t_y)
			{
				y = t_y;
			}
		
			inline void SetZ(float t_z)
			{
				z = t_z;
			}
		
			inline float operator[](int t_i)       
			{ return v[t_i]; }
			
			inline float operator[](int t_i)const 
			{ return v[t_i]; }
		
			inline const Vec3 operator+(const Vec3& t_v) const { return Vec3(x + t_v.x, y + t_v.y, z + t_v.z); }
			inline const Vec3 operator-(const Vec3& t_v) const { return Vec3(x - t_v.x, y - t_v.y, z - t_v.z); }
			inline const Vec3 operator*(const Vec3& t_v) const { return Vec3(x * t_v.x, y * t_v.y, z * t_v.z); }
			inline const Vec3 operator*(float t_f)       const { return Vec3(x * t_f, y * t_f, z * t_f);   }
			inline const Vec3 operator/(float t_f)       const { return Vec3(x / t_f, y / t_f, z / t_f);   }
		
			inline Vec3& operator+=(const Vec3& t_v) { x += t_v.x; y += t_v.y; z += t_v.z; return *this; }
			inline Vec3& operator-=(const Vec3& t_v) { x -= t_v.x; y -= t_v.y; z -= t_v.z; return *this; }
			inline Vec3& operator*=(float t_f)       { x *= t_f; y *= t_f; z *= t_f; return *this; }
			inline Vec3& operator/=(float t_f)       { x /= t_f; y /= t_f; z /= t_f; return *this; }
			
			static inline Vec3 Left(){return Vec3(-1, 0, 0);}
			static inline Vec3 Right(){return Vec3(1, 0, 0);}
			static inline Vec3 Up(){return Vec3(0, 1, 0);}
			static inline Vec3 Down(){return Vec3(0, -1, 0);}
			static inline Vec3 Forward(){return Vec3(0, 0, -1);}
			static inline Vec3 Back(){return Vec3(0, 0, 1);}
		
		};
		
		inline bool operator==(const Vec3& t_vec1, const Vec3& t_vec2)
		{
			return (t_vec1.x == t_vec2.x) && (t_vec1.y == t_vec2.y) && (t_vec1.z == t_vec2.z);
		}

		inline bool operator!=(const Vec3& t_vec1, const Vec3& t_vec2)
		{
			return (t_vec1.x != t_vec2.x) || (t_vec1.y != t_vec2.y) || (t_vec1.z != t_vec2.z);
		}

	}
}