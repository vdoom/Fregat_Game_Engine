//#ifndef VEC4_H
//#define VEC4_H
#pragma once

#include "MathCommon.h"
#include "Mat3.h"
#include "Mat4.h"

namespace Fregat 
{
	namespace Math
	{

		struct Vec4
		{
			union
			{
				struct { float x, y, z, w; };
				float v[4];
			};
			public:
			inline Vec4():
					x(0.0f),
					y(0.0f),
					z(0.0f),
					w(0.0f)
			{
			}
				
			inline Vec4(float t_x, float t_y, float t_z, float t_w):
					x(t_x),
					y(t_y),
					z(t_z),
					w(t_w)
			{
			}
			
			inline Vec4(const Vec4& t_vec):
					x(t_vec.x),
					y(t_vec.y),
					z(t_vec.z),
					w(t_vec.w)
			{
			}
		
			inline float GetX()const {return x;}
			inline float GetY()const {return y;}
			inline float GetZ()const {return z;}
			inline float GetW()const {return w;}
			
			inline void Set(float t_x, float t_y, float t_z, float t_w)
			{//TODO: need think about caching vector length
				x = t_x; 
				y = t_y;
				z = t_z;
				w = t_w;
			}

			inline void Set(const Vec4& t_vec)
			{//TODO: need think about caching vector length
				x = t_vec.x;
				y = t_vec.y;
				z = t_vec.z;
				w = t_vec.w;
			}
			
			//void Set(const Mat3 &M);
			
			//void Set(const Mat4 &M);
			
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
			
			inline void SetW(float t_w)
			{
				w = t_w;
			}
		
			inline float operator[](size_t t_i)       
			{ return v[t_i]; }
			
			inline float operator[](size_t t_i)const 
			{ return v[t_i]; }

			inline Vec4& operator=(const Vec4& t_vec) { Set(t_vec); return *this; }
		
			//todo: Perhaps can be speeduped via SSE
			inline const Vec4 operator+(const Vec4& t_v) const { return Vec4(x + t_v.x, y + t_v.y, z + t_v.z, w + t_v.w); }
			inline const Vec4 operator-(const Vec4& t_v) const { return Vec4(x - t_v.x, y - t_v.y, z - t_v.z, w - t_v.w); }
			inline const Vec4 operator*(const Vec4& t_v) const { return Vec4(x * t_v.x, y * t_v.y, z * t_v.z, w * t_v.w); }
			inline const Vec4 operator*(float t_f)       const { return Vec4(x * t_f, y * t_f, z * t_f, w * t_f);   }
			inline const Vec4 operator/(float t_f)       const { return Vec4(x / t_f, y / t_f, z / t_f, w / t_f);   }
		
			inline Vec4& operator+=(const Vec4& t_v) { x += t_v.x; y += t_v.y; z += t_v.z; w += t_v.w; return *this; }
			inline Vec4& operator-=(const Vec4& t_v) { x -= t_v.x; y -= t_v.y; z -= t_v.z; w -= t_v.w; return *this; }
			inline Vec4& operator*=(float t_f)       { x *= t_f; y *= t_f; z *= t_f; w *= t_f; return *this; }
			inline Vec4& operator/=(float t_f)       { x /= t_f; y /= t_f; z /= t_f; w /= t_f;return *this; }
		
			static inline Vec4 Left(){return Vec4(-1, 0, 0, 0);}
			static inline Vec4 Right(){return Vec4(1, 0, 0, 0);}
			static inline Vec4 Up(){return Vec4(0, 1, 0, 0);}
			static inline Vec4 Down(){return Vec4(0, -1, 0, 0);}
			static inline Vec4 Forward(){return Vec4(0, 0, -1, 0);}
			static inline Vec4 Back(){return Vec4(0, 0, 1, 0);}
		private:
		
		};
		
		inline bool operator==(const Vec4& t_vec1, const Vec4& t_vec2)
		{
			return (t_vec1.x == t_vec2.x) && (t_vec1.y == t_vec2.y) 
				&& (t_vec1.z == t_vec2.z) && (t_vec1.w == t_vec2.w);
		}

		inline bool operator!=(const Vec4& t_vec1, const Vec4& t_vec2)
		{
			return (t_vec1.x != t_vec2.x) || (t_vec1.y != t_vec2.y) 
				|| (t_vec1.z != t_vec2.z) || (t_vec1.w != t_vec2.w);
		}

		typedef Vec4 Quat; // Vector4 => Quaternion
	}
}
