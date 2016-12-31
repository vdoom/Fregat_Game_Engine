#include "Mat4.h"
#include "Mat3.h"
#include "Vec4.h"
#include "Vec3.h"
#include "Vec2.h"

namespace Fregat 
{
	namespace Math
	{
		static const Vec3 ToEulerMat4(const Mat4& t_mat)
		{
			Vec3 angle;
			float x, y, C;
		
			angle.y = asinf(t_mat[2]);
			C       = cosf(angle.y);
			angle.y *= math_degrees;
		
			if (fabsf(C) > math_epsilon)
			{
				x       =  t_mat[10] / C;
				y       = -t_mat[ 6] / C;
				angle.x = atan2f(y, x) * math_degrees;
				x       =  t_mat[ 0] / C;
				y       = -t_mat[ 1] / C;
				angle.z = atan2f(y, x) * math_degrees;
			} else
			{
				angle.x = 0.0f;
				x       =  t_mat[ 5];
				y       =  t_mat[ 4];
				angle.z = atan2f(y, x) * math_degrees;
			}
		
			if (angle.x < 0) angle.x += 360;
			if (angle.y < 0) angle.y += 360;
			if (angle.z < 0) angle.z += 360;
		
			return angle;
		}

		inline const Mat4 FromEulerMat4(const Vec3& t_vec)
		{
			return Mat4::FromEuler(t_vec.x, t_vec.y, t_vec.z);
		}

		inline const Mat4 ScaleMat4(const Vec3& t_vec)
		{
			return Mat4::Scale(t_vec.x, t_vec.y, t_vec.z);
		}

		inline const Mat4 TranslationMat4(const Vec3& t_vec)
		{
			return Mat4::Translation(t_vec.x, t_vec.y, t_vec.z);
		}

		static const Mat4 LookAt(const Vec3 &position, const Vec3 &center, const Vec3 &up)
		{
			const Vec3 f = Vec3::Normileze(position - center);
			const Vec3 s = Vec3::Normileze(Cross(up, f));
			const Vec3 u = Vec3::Normileze(Cross(f, s));
		
			return Mat4(s.x, s.y, s.z, 0,
			            u.x, u.y, u.z, 0,
			            f.x, f.y, f.z, 0,
			            -Dot(s, position), -Dot(u, position),  -Dot(f, position), 1);
		}
		
		static const Vec3 ToEulerMat3(const Mat3& t_mat)
		{
			Vec3 angle;
			float x, y, C;
		
			angle.y = asinf(t_mat[2]);
			C       = cosf(angle.y);
			angle.y *= math_degrees;
		
			if (fabsf(C) > math_epsilon)
			{
				x       =  t_mat[8] / C;
				y       = -t_mat[ 5] / C;
				angle.x = atan2f(y, x) * math_degrees;
				x       =  t_mat[ 0] / C;
				y       = -t_mat[ 1] / C;
				angle.z = atan2f(y, x) * math_degrees;
			} else
			{
				angle.x = 0.0f;
				x       =  t_mat[ 4];
				y       =  t_mat[ 3];
				angle.z = atan2f(y, x) * math_degrees;
			}
		
			if (angle.x < 0) angle.x += 360;
			if (angle.y < 0) angle.y += 360;
			if (angle.z < 0) angle.z += 360;
		
			return angle;
		}
		
		inline const Mat3 FromEulerMat3(const Vec3& t_vec)
		{
			return Mat3::FromEuler(t_vec.x, t_vec.y, t_vec.z);
		}
		
		inline const Mat3 ScaleMat3(const Vec3& t_vec)
		{
			return Mat3::Scale(t_vec.x, t_vec.y, t_vec.z);
		}
		
		inline const Mat3 TranslationMat3(const Vec3& t_vec)
		{
			return Mat3::Translation(t_vec.x, t_vec.y, t_vec.z);
		}

		static Quat Mat3ToQuat(const Mat3& t_mat)
		{
			Quat tmp;
			const float t = t_mat[0] + t_mat[4] + t_mat[8];
			float       s;
		
			if (t > 0.0f)
			{
				s = 0.5f / sqrtf(t + 1.0f);
				tmp.x = (t_mat[7] - t_mat[5]) * s;
				tmp.y = (t_mat[2] - t_mat[6]) * s;
				tmp.z = (t_mat[3] - t_mat[1]) * s;
				tmp.w = 0.25f / s;
			} else if (t_mat[0] > t_mat[4] && t_mat[0] > t_mat[8])
			{
				s = 2.0f * sqrtf(1.0f + t_mat[0] - t_mat[4] - t_mat[8]);
				tmp.x = 0.25f * s;
				tmp.y = (t_mat[3] + t_mat[1]) / s;
				tmp.z = (t_mat[2] + t_mat[6]) / s;
				tmp.w = (t_mat[7] - t_mat[5]) / s;
			} else if (t_mat[4] > t_mat[8])
			{
				s = 2.0f * sqrtf(1.0f + t_mat[4] - t_mat[0] - t_mat[8]);
				tmp.x = (t_mat[3] + t_mat[1]) / s;
				tmp.y = 0.25f * s;
				tmp.z = (t_mat[7] + t_mat[5]) / s;
				tmp.w = (t_mat[2] - t_mat[6]) / s;
			} else
			{
				s = 2.0f * sqrtf(1.0f + t_mat[8] - t_mat[0] - t_mat[4]);
				tmp.x = (t_mat[2] + t_mat[6]) / s;
				tmp.y = (t_mat[7] + t_mat[5]) / s;
				tmp.z = 0.25f * s;
				tmp.w = (t_mat[3] - t_mat[1]) / s;
			}

			return tmp;
		}
		
		static Quat Mat4ToQuat(const Mat4 &t_mat)
		{
			Quat tmp;
			const float t = t_mat[0] + t_mat[5] + t_mat[10];
			float       s;
		
			if (t > 0.0f)
			{
				s = 0.5f / sqrtf(t + 1.0f);
				tmp.x = (t_mat[8] - t_mat[6]) * s;
				tmp.y = (t_mat[2] - t_mat[7]) * s;
				tmp.z = (t_mat[3] - t_mat[1]) * s;
				tmp.w = 0.25f / s;
			} else if (t_mat[0] > t_mat[5] && t_mat[0] > t_mat[10])
			{
				s = 2.0f * sqrtf(1.0f + t_mat[0] - t_mat[5] - t_mat[10]);
				tmp.x = 0.25f * s;
				tmp.y = (t_mat[3] + t_mat[1]) / s;
				tmp.z = (t_mat[2] + t_mat[7]) / s;
				tmp.w = (t_mat[8] - t_mat[6]) / s;
			} else if (t_mat[5] > t_mat[10])
			{
				s = 2.0f * sqrtf(1.0f + t_mat[5] - t_mat[0] - t_mat[10]);
				tmp.x = (t_mat[3] + t_mat[1]) / s;
				tmp.y = 0.25f * s;
				tmp.z = (t_mat[8] + t_mat[6]) / s;
				tmp.w = (t_mat[2] - t_mat[7]) / s;
			} else
			{
				s = 2.0f * sqrtf(1.0f + t_mat[10] - t_mat[0] - t_mat[5]);
				tmp.x = (t_mat[2] + t_mat[7]) / s;
				tmp.y = (t_mat[8] + t_mat[6]) / s;
				tmp.z = 0.25f * s;
				tmp.w = (t_mat[3] - t_mat[1]) / s;
			}

			return tmp;
		}

		
		static float DeterminantMat4(const Mat4& t_mat)
		{
			float A, B, C, D, E, F;
		
			A = t_mat[10] * t_mat[15] - t_mat[11] * t_mat[14];
			B = t_mat[ 9] * t_mat[15] - t_mat[11] * t_mat[13];
			C = t_mat[ 9] * t_mat[14] - t_mat[10] * t_mat[13];
			D = t_mat[ 8] * t_mat[15] - t_mat[11] * t_mat[12];
			E = t_mat[ 8] * t_mat[14] - t_mat[10] * t_mat[12];
			F = t_mat[ 8] * t_mat[13] - t_mat[ 9] * t_mat[12];
		
			return t_mat[0] * (A * t_mat[5] - B * t_mat[6] + C * t_mat[7])
			     - t_mat[1] * (A * t_mat[4] - D * t_mat[6] + E * t_mat[7])
			     + t_mat[2] * (B * t_mat[4] - D * t_mat[5] + F * t_mat[7])
			     - t_mat[3] * (C * t_mat[4] - E * t_mat[5] + F * t_mat[6]);
		}
		
		static const Mat4 InverseMat4(const Mat4& t_mat)
		{
			const float det = 1.0f / DeterminantMat4(t_mat);
		
			#define MDET3(a0,a1,a2,a3,a4,a5,a6,a7,a8) \
			            ( a0 * (a4 * a8 - a5 * a7) \
			            - a1 * (a3 * a8 - a5 * a6) \
			            + a2 * (a3 * a7 - a4 * a6) )
		
			// ~ 160 mul & 80 add
			return Mat4(
				 MDET3(t_mat[5], t_mat[6], t_mat[7], t_mat[9], t_mat[10], t_mat[11], t_mat[13], t_mat[14], t_mat[15]) * det,
				-MDET3(t_mat[1], t_mat[2], t_mat[3], t_mat[9], t_mat[10], t_mat[11], t_mat[13], t_mat[14], t_mat[15]) * det,
				 MDET3(t_mat[1], t_mat[2], t_mat[3], t_mat[5], t_mat[ 6], t_mat[ 7], t_mat[13], t_mat[14], t_mat[15]) * det,
				-MDET3(t_mat[1], t_mat[2], t_mat[3], t_mat[5], t_mat[ 6], t_mat[ 7], t_mat[ 9], t_mat[10], t_mat[11]) * det,
				-MDET3(t_mat[4], t_mat[6], t_mat[7], t_mat[8], t_mat[10], t_mat[11], t_mat[12], t_mat[14], t_mat[15]) * det,
				 MDET3(t_mat[0], t_mat[2], t_mat[3], t_mat[8], t_mat[10], t_mat[11], t_mat[12], t_mat[14], t_mat[15]) * det,
				-MDET3(t_mat[0], t_mat[2], t_mat[3], t_mat[4], t_mat[ 6], t_mat[ 7], t_mat[12], t_mat[14], t_mat[15]) * det,
				 MDET3(t_mat[0], t_mat[2], t_mat[3], t_mat[4], t_mat[ 6], t_mat[ 7], t_mat[ 8], t_mat[10], t_mat[11]) * det,
				 MDET3(t_mat[4], t_mat[5], t_mat[7], t_mat[8], t_mat[ 9], t_mat[11], t_mat[12], t_mat[13], t_mat[15]) * det,
				-MDET3(t_mat[0], t_mat[1], t_mat[3], t_mat[8], t_mat[ 9], t_mat[11], t_mat[12], t_mat[13], t_mat[15]) * det,
				 MDET3(t_mat[0], t_mat[1], t_mat[3], t_mat[4], t_mat[ 5], t_mat[ 7], t_mat[12], t_mat[13], t_mat[15]) * det,
				-MDET3(t_mat[0], t_mat[1], t_mat[3], t_mat[4], t_mat[ 5], t_mat[ 7], t_mat[ 8], t_mat[ 9], t_mat[11]) * det,
				-MDET3(t_mat[4], t_mat[5], t_mat[6], t_mat[8], t_mat[ 9], t_mat[10], t_mat[12], t_mat[13], t_mat[14]) * det,
				 MDET3(t_mat[0], t_mat[1], t_mat[2], t_mat[8], t_mat[ 9], t_mat[10], t_mat[12], t_mat[13], t_mat[14]) * det,
				-MDET3(t_mat[0], t_mat[1], t_mat[2], t_mat[4], t_mat[ 5], t_mat[ 6], t_mat[12], t_mat[13], t_mat[14]) * det,
				 MDET3(t_mat[0], t_mat[1], t_mat[2], t_mat[4], t_mat[ 5], t_mat[ 6], t_mat[ 8], t_mat[ 9], t_mat[10]) * det);
		
			#undef MDET3
		}
		
		inline const Mat4 TransposeMat4(const Mat4& t_mat)
		{
			return Mat4(t_mat[ 0], t_mat[ 4], t_mat[ 8], t_mat[12],
			            t_mat[ 1], t_mat[ 5], t_mat[ 9], t_mat[13],
			            t_mat[ 2], t_mat[ 6], t_mat[10], t_mat[14],
			            t_mat[ 3], t_mat[ 7], t_mat[11], t_mat[15]);
		}

		inline float DeterminantMat3(const Mat3& t_mat)
		{
			return t_mat[0] * (t_mat[4] * t_mat[8] - t_mat[5] * t_mat[7])
			     - t_mat[1] * (t_mat[3] * t_mat[8] - t_mat[5] * t_mat[6])
			     + t_mat[2] * (t_mat[3] * t_mat[7] - t_mat[4] * t_mat[6]);
		}
		
		inline const Mat3 inverseMat3(const Mat3& t_mat)
		{
			const float det = 1.0f / DeterminantMat3(t_mat);
		
			return Mat3((t_mat[4] * t_mat[8] - t_mat[5] * t_mat[7]) * det,
			            (t_mat[2] * t_mat[7] - t_mat[1] * t_mat[8]) * det,
			            (t_mat[1] * t_mat[5] - t_mat[2] * t_mat[4]) * det,
			            (t_mat[5] * t_mat[6] - t_mat[3] * t_mat[8]) * det,
			            (t_mat[0] * t_mat[8] - t_mat[2] * t_mat[6]) * det,
			            (t_mat[2] * t_mat[3] - t_mat[0] * t_mat[5]) * det,
			            (t_mat[3] * t_mat[7] - t_mat[4] * t_mat[6]) * det,
			            (t_mat[1] * t_mat[6] - t_mat[0] * t_mat[7]) * det,
			            (t_mat[0] * t_mat[4] - t_mat[1] * t_mat[3]) * det);
		}
		
		inline const Mat3 transposeMat3(const Mat3& t_mat)
		{
			return Mat3(t_mat[0], t_mat[3], t_mat[6],
			            t_mat[1], t_mat[4], t_mat[7],
			            t_mat[2], t_mat[5], t_mat[8]);
		}

		static const Mat4 Orthographic(float t_left, float t_right, float t_bottom, 
									   float t_top, float t_zNear, float t_zFar)
		{
			const float tx = - (t_right + t_left) / (t_right - t_left),
			            ty = - (t_top + t_bottom) / (t_top - t_bottom),
			            tz = - (t_zFar + t_zNear) / (t_zFar - t_zNear);
		
			return Mat4(2 / (t_right - t_left), 0, 0, tx,
			            0, 2 / (t_top - t_bottom), 0, ty,
			            0, 0, -2 / (t_zFar - t_zNear), tz,
			            0, 0, 0, 1);
		}

		static const Mat4 Perspective(float t_fov, float t_aspect, float t_zNear, float t_zFar)
		{
			const float f = 1 / tanf(t_fov * math_radians / 2),
				        A = (t_zFar + t_zNear) / (t_zNear - t_zFar),
					    B = (2 * t_zFar * t_zNear) / (t_zNear - t_zFar);

			return Mat4(f / t_aspect, 0, 0, 0,
				        0, f, 0, 0,
					    0, 0, A, B,
						0, 0, -1, 0);
		}

		static const Mat4 Frustum(float t_left, float t_right, float t_bottom, 
									float t_top, float t_zNear, float t_zFar)
		{
			return Mat4((2 * t_zNear) / (t_right - t_left), 0, (t_right + t_left) / (t_right - t_left), 0,
				        0, (2 * t_zNear) / (t_top - t_bottom), (t_top + t_bottom) / (t_top - t_bottom), 0,
					    0, 0, -(t_zFar + t_zNear) / (t_zFar - t_zNear), -(2 * t_zFar * t_zNear) / (t_zFar - t_zNear),
						0, 0, -1, 0);
		}

		inline float Dot(const Vec2& t_v1, const Vec2& t_v2)
		{
			return t_v1.x * t_v2.x + t_v1.y * t_v2.y;
		}

		inline float Length(const Vec2& t_vec)
		{ 
			return sqrtf(Dot(t_vec, t_vec));
		}

		inline float Distance(const Vec2& t_v1, const Vec2& t_v2)
		{
			return Length(t_v1 - t_v2);
		}

		Vec2& Normalize(const Vec2& t_vec)
		{
			return Vec2(t_vec / Length(t_vec));
		}

		inline Vec3 Cross(const Vec3& t_vec1, const Vec3& t_vec2)
		{
			return Vec3(t_vec1.y * t_vec2.z - t_vec1.z * t_vec2.y, 
						t_vec1.z * t_vec2.x - t_vec1.x * t_vec2.z, 
						t_vec1.x * t_vec2.y - t_vec1.y * t_vec2.x);
		}

		inline float Dot(const Vec3& t_vec1, const Vec3& t_vec2)
		{
			return t_vec1.x * t_vec2.x + t_vec1.y * t_vec2.y + t_vec1.z * t_vec2.z;
		}

		inline float Length(const Vec3& t_vec)
		{
			return sqrtf(Dot(t_vec, t_vec));
		}

		inline float Distance(const Vec3& t_vec1, const Vec3& t_vec2)
		{
			return Length(t_vec1 - t_vec2);
		}

		Vec3& Normalize(const Vec3 t_vec)
		{
			return Vec3(t_vec / Length(t_vec));
		}

		// random point on sphere
		static const Vec3 SphRand()
		{
			float u = unirand(2.0f * math_pi);
			float h = unirand(2.0f)  - 1.0f;
			float r = sqrtf(1.0f - h * h);
			return Vec3(cosf(u) * r, sinf(u) * r, h);
		}

		//TODO: need implement
		//inline float Dot(const Vec4& v1, const Vec4 &v2);
		//inline float Length(const Vec4 &v);
		//inline float Distance(const Vec4 &v1, const Vec4 &v2);
		//inline Vec4 Normalize(Vec4);

		inline bool operator==(const Vec2& t_vec1, const Vec2& t_vec2)
		{
			return (t_vec1.x == t_vec2.x) && (t_vec1.y == t_vec2.y);
		}
		
		inline bool operator==(const Vec3& t_vec1, const Vec3& t_vec2)
		{
			return (t_vec1.x == t_vec2.x) && (t_vec1.y == t_vec2.y) && (t_vec1.z == t_vec2.z);
		}

		inline bool operator==(const Vec4& t_vec1, const Vec4& t_vec2)
		{
			return (t_vec1.x == t_vec2.x) && (t_vec1.y == t_vec2.y) 
				&& (t_vec1.z == t_vec2.z) && (t_vec1.w == t_vec2.w);
		}

		bool operator==(const Mat3& t_mat1, const Mat3& t_mat2)
		{
			const int matSize = 9;
			for(size_t i = 0; i < matSize; ++i)
			{
				if(t_mat1[i] != t_mat2[i]) return false;
			}

			return true;
		}

		bool operator==(const Mat4& t_mat1, const Mat4& t_mat2)
		{
			const int matSize = 16;
			for(size_t i = 0; i < matSize; ++i)
			{
				if(t_mat1[i] != t_mat2[i]) return false;
			}

			return true;
		}
	}
}