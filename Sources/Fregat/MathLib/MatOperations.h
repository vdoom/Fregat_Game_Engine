#pragma once
#include "Mat4.h"
#include "Mat3.h"
#include "Vec4.h"
#include "Vec3.h"
#include "Vec2.h"
#include <iostream>

namespace Fregat 
{
	namespace Math
	{	
		//-----------------------------------------------------------------------------------
		// TODO: need test
		inline const Vec3 ToEulerMat4(const Mat4& t_mat)
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
		// TODO: need test
		inline const Vec3 GetPosFromMat4(const Mat4& t_mat)
		{
			return Vec3(t_mat.m03, t_mat.m13, t_mat.m23);
		}
		// TODO: need test
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
		// TODO: need test
		inline const Vec3 ToEulerMat3(const Mat3& t_mat)
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
		// TODO: need test
		inline const Mat3 FromEulerMat3(const Vec3& t_vec)
		{
			return Mat3::FromEuler(t_vec.x, t_vec.y, t_vec.z);
		}
		// TODO: need test
		inline const Mat3 ScaleMat3(const Vec3& t_vec)
		{
			return Mat3::Scale(t_vec.x, t_vec.y, t_vec.z);
		}
		// TODO: need test
		inline const Mat3 TranslationMat3(const Vec3& t_vec)
		{
			return Mat3::Translation(t_vec.x, t_vec.y, t_vec.z);
		}
		// TODO: need test
		inline Quat Mat3ToQuat(const Mat3& t_mat)
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
		// TODO: need test
		inline Quat Mat4ToQuat(const Mat4 &t_mat)
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
		// TODO: need test
		inline float DeterminantMat4(const Mat4& t_mat)
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
		// TODO: need test
		inline const Mat4 InverseMat4(const Mat4& t_mat)
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
		// TODO: need test
		inline float DeterminantMat3(const Mat3& t_mat)
		{
			return t_mat[0] * (t_mat[4] * t_mat[8] - t_mat[5] * t_mat[7])
			     - t_mat[1] * (t_mat[3] * t_mat[8] - t_mat[5] * t_mat[6])
			     + t_mat[2] * (t_mat[3] * t_mat[7] - t_mat[4] * t_mat[6]);
		}
		// TODO: need test
		inline const Mat3 InverseMat3(const Mat3& t_mat)
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
		// TODO: need test
		inline const Mat3 TransposeMat3(const Mat3& t_mat)
		{
			return Mat3(t_mat[0], t_mat[3], t_mat[6],
			            t_mat[1], t_mat[4], t_mat[7],
			            t_mat[2], t_mat[5], t_mat[8]);
		}
		// TODO: need test
		inline const Mat4 Orthographic(float t_left, float t_right, float t_bottom, 
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


		
		inline const Mat4 LHPerspective(float t_fov, float t_aspect, float t_zNear, float t_zFar)
		{
			const float tanHalfFovy = tanf((t_fov*math_radians)/2);
			//const float f = 1 / tanf(t_fov * math_radians / 2),
			//	        A = (t_zFar + t_zNear) / (t_zNear - t_zFar),
			//		    B = (2 * t_zFar * t_zNear) / (t_zNear - t_zFar);

			//return Mat4(f / t_aspect, 0, 0, 0,
			//	        0, f, 0, 0,
			//		    0, 0, A, B,
			//			0, 0, -1, 0);
			Mat4 res;
			res.m1[0][0] = 1.0f / (t_aspect * tanHalfFovy);
			res.m1[1][1] = 1.0f / (tanHalfFovy);
			res.m1[2][3] = 1.0f;

			res.m1[2][2] = (t_zFar + t_zNear) / (t_zFar - t_zNear);
			res.m1[3][2] = - (2.0f * t_zFar * t_zNear) / (t_zFar - t_zNear);

			res.m1[3][3] = 0;

			return res;
		}

		//TODO: need refine
		inline const Mat4 RHPerspective(float t_fov, float t_aspect, float t_zNear, float t_zFar)
		{
			const float f = 1 / tanf(t_fov * math_radians / 2),
				        A = (t_zFar + t_zNear) / (t_zNear - t_zFar),
					    B = (2 * t_zFar * t_zNear) / (t_zNear - t_zFar);

			return Mat4(f / t_aspect, 0, 0, 0,
				        0, f, 0, 0,
					    0, 0, A, B,
						0, 0, -1, 0);

	//		assert(abs(aspect - std::numeric_limits<T>::epsilon()) > static_cast<T>(0));

	//		T const tanHalfFovy = tan(fovy / static_cast<T>(2));

	//		tmat4x4<T, defaultp> Result(static_cast<T>(0));
	//		Result[0][0] = static_cast<T>(1) / (aspect * tanHalfFovy);
	//		Result[1][1] = static_cast<T>(1) / (tanHalfFovy);
	//		Result[2][3] = - static_cast<T>(1);

	//#		if GLM_DEPTH_CLIP_SPACE == GLM_DEPTH_ZERO_TO_ONE
	//			Result[2][2] = zFar / (zNear - zFar);
	//			Result[3][2] = -(zFar * zNear) / (zFar - zNear);
	//#		else
	//			Result[2][2] = - (zFar + zNear) / (zFar - zNear);
	//			Result[3][2] = - (static_cast<T>(2) * zFar * zNear) / (zFar - zNear);
	//#		endif

	//		return Result;
		}

		inline const Mat4 _OLDPerspective(float t_fov, float t_aspect, float t_zNear, float t_zFar)
		{
			const float f = 1 / tanf(t_fov * math_radians / 2),
				        A = (t_zFar + t_zNear) / (t_zNear - t_zFar),
					    B = (2 * t_zFar * t_zNear) / (t_zNear - t_zFar);

			return Mat4(f / t_aspect, 0, 0, 0,
				        0, f, 0, 0,
					    0, 0, A, B,
						0, 0, -1, 0);
		}

		inline const Mat4 Perspective(float t_fov, float t_aspect, float t_zNear, float t_zFar)
		{
			return RHPerspective(t_fov, t_aspect, t_zNear, t_zFar);
		}

		// TODO: need test
		inline const Mat4 Frustum(float t_left, float t_right, float t_bottom, 
									float t_top, float t_zNear, float t_zFar)
		{
			return Mat4((2 * t_zNear) / (t_right - t_left), 0, (t_right + t_left) / (t_right - t_left), 0,
				        0, (2 * t_zNear) / (t_top - t_bottom), (t_top + t_bottom) / (t_top - t_bottom), 0,
					    0, 0, -(t_zFar + t_zNear) / (t_zFar - t_zNear), -(2 * t_zFar * t_zNear) / (t_zFar - t_zNear),
						0, 0, -1, 0);
		}
		// TODO: need test
		const Mat4 Mat4::Translation(const Vec3& t_vec)
		{
			return Mat4(1, 0, 0, t_vec.x,
						0, 1, 0, t_vec.y,
						0, 0, 1, t_vec.z,
						0, 0, 0, 1);
		}
		// TODO: need test
		const Mat4 Mat4::Scale(const Vec3& t_vec)
		{
			return Mat4(t_vec.x, 0, 0, 0,
						0, t_vec.y, 0, 0,
						0, 0, t_vec.z, 0,
						0, 0, 0, 1);
		}
		// TODO: need test
		const Mat4 Mat4::FromEuler(const Vec3& t_vec)
		{
			const float cx = cosf(t_vec.x * math_radians), sx = sinf(t_vec.x * math_radians),
					cy = cosf(t_vec.y * math_radians), sy = sinf(t_vec.y * math_radians),
					cz = cosf(t_vec.x * math_radians), sz = sinf(t_vec.z * math_radians);
		
			// rotationX * rotationY * rotationZ
			return Mat4(cy * cz, -cy * sz, sy, 0,
						cx * sz + sx * cz * sy, cx * cz - sx * sy * sz, -cy * sx, 0,
						sx * sz - cx * cz * sy, cz * sx + cx * sy * sz, cx * cy, 0,
						0, 0, 0, 1);
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

		inline Vec2 Normalize(const Vec2& t_vec)
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

		inline Vec3 Normalize(const Vec3 t_vec)
		{
			return Vec3(t_vec / Length(t_vec));
		}

		inline const Mat4 RHLookAt(const Vec3 &t_position, const Vec3 &t_center, const Vec3 &t_up)//RH
		{
			const Vec3 f = Normalize(t_center - t_position);
			const Vec3 s = Normalize(Cross(f, t_up));
			const Vec3 u = Normalize(Cross(s, f));
		
			//return Mat4(s.x, s.y, s.z, 0,
			//            u.x, u.y, u.z, 0,
			//            -f.x, -f.y, -f.z, 0,
			//            -Dot(s, t_position), -Dot(u, t_position),  Dot(f, t_position), 1);
			return Mat4(s.x, u.x, -f.x, 0,
			            s.y, u.y, -f.y, 0,
			            s.z, u.z, -f.z, 0,
			            -Dot(s, t_position), -Dot(u, t_position), Dot(f, t_position),   1);
		}

		inline const Mat4 LHLookAt(const Vec3& t_position, const Vec3& t_center, const Vec3& t_up)//LH
		{
			const Vec3 f = Normalize(t_center - t_position);
			const Vec3 s = Normalize(Cross(t_up, f));
			const Vec3 u = Normalize(Cross(f, s));
		
			//return Mat4(s.x, u.x, f.x, -Dot(s, t_position),
			//            s.y, u.y, f.y, -Dot(u, t_position),
			//            s.z, u.z, f.z, -Dot(f, t_position),
			//            0,	 0,	  0,   1);
			return Mat4(s.x, u.x, f.x, 0,
			            s.y, u.y, f.y, 0,
			            s.z, u.z, f.z, 0,
			            -Dot(s, t_position), -Dot(u, t_position), -Dot(f, t_position),   1);
		}

		inline const Mat4 LookAt(const Vec3 &t_position, const Vec3 &t_center, const Vec3 &t_up)
		{
			return RHLookAt(t_position, t_center, t_up);
		}
		// TODO: need test
		// random point on sphere
		inline const Vec3 SphRand()
		{
			float u = UniRand(2.0f * math_pi);
			float h = UniRand(2.0f)  - 1.0f;
			float r = sqrtf(1.0f - h * h);
			return Vec3(cosf(u) * r, sinf(u) * r, h);
		}
		// TODO: need test
		inline const Vec3 GetScaleFromMa4(const Mat4& t_mat)
		{
			return Vec3(Length(Vec3(t_mat.m00, t_mat.m01, t_mat.m02)),
						Length(Vec3(t_mat.m10, t_mat.m11, t_mat.m12)),
						Length(Vec3(t_mat.m20, t_mat.m21, t_mat.m22)));
		}
		//TODO: need implement
		//inline float Dot(const Vec4& v1, const Vec4 &v2);
		//inline float Length(const Vec4 &v);
		//inline float Distance(const Vec4 &v1, const Vec4 &v2);
		//inline Vec4 Normalize(Vec4);
		//--------------------------------------------------------------

		inline void ShowMat(const Mat4& t_mat)
		{
			std::cout << "-----------------------------\n";
			std::cout << t_mat.m00 << " " << t_mat.m01 << " " << t_mat.m02 << " " << t_mat.m03 << std::endl;
			std::cout << t_mat.m10 << " " << t_mat.m11 << " " << t_mat.m12 << " " << t_mat.m13 << std::endl;
			std::cout << t_mat.m20 << " " << t_mat.m21 << " " << t_mat.m22 << " " << t_mat.m23 << std::endl;
			std::cout << t_mat.m30 << " " << t_mat.m31 << " " << t_mat.m32 << " " << t_mat.m33 << std::endl;
		}

		/*inline Vec3 operator* (const Mat4& t_mat, const Vec3& t_vec)
		{
			return Vec3(t_mat.m00 * t_vec.x + t_mat.m01 * t_vec.y + t_mat.m02 * t_vec.z + t_mat.m03,
						t_mat.m10 * t_vec.x + t_mat.m11 * t_vec.y + t_mat.m12 * t_vec.z + t_mat.m13,
						t_mat.m20 * t_vec.x + t_mat.m21 * t_vec.y + t_mat.m22 * t_vec.z + t_mat.m23);
		}*/
		inline Vec3 operator* (const Mat4& t_mat, const Vec3& t_vec)
		{
			return Vec3(t_mat.m00 * t_vec.x + t_mat.m10 * t_vec.y + t_mat.m20 * t_vec.z,
						t_mat.m01 * t_vec.x + t_mat.m11 * t_vec.y + t_mat.m21 * t_vec.z,
						t_mat.m02 * t_vec.x + t_mat.m12 * t_vec.y + t_mat.m22 * t_vec.z);
		}
		// TODO: need test
		inline Vec3 RotDotY(Vec3 t_dot, Vec3 t_cntRot, float t_angle)
		{
			Vec3 tmp;
			tmp.x = t_cntRot.x + (t_dot.x - t_cntRot.x)*cos(t_angle) - (t_dot.z - t_cntRot.z)*sin(t_angle);
			tmp.z = t_cntRot.z + (t_dot.x - t_cntRot.x)*sin(t_angle) + (t_dot.z - t_cntRot.z)*cos(t_angle);
			tmp.y = t_dot.y;
			return tmp;
		}
		// TODO: need test
		inline Vec3 RotDotX(Vec3 t_dot, Vec3 t_cntRot, float t_angle)
		{
			Vec3 tmp;
			tmp.y = t_cntRot.y + (t_dot.y - t_cntRot.y)*cos(t_angle) - (t_dot.z - t_cntRot.z)*sin(t_angle);
			tmp.z = t_cntRot.z + (t_dot.y - t_cntRot.y)*sin(t_angle) + (t_dot.z - t_cntRot.z)*cos(t_angle);
			tmp.x = t_dot.x;
			return tmp;
		}

		inline Mat4 Rotate(Mat4 const& m, float angle, Vec3 const& v)
		{
			float const a = angle;
			float const c = cosf(a);
			float const s = sinf(a);

			Vec3 axis(Normalize(v));
			Vec3 tmp(axis*(1-c));
			
			Mat4 rot;
			rot.m1[0][0] = c + tmp[0] * axis[0];
			rot.m1[0][1] = tmp[0] * axis[1] + s * axis[2];
			rot.m1[0][2] = tmp[0] * axis[2] - s * axis[1];

			rot.m1[1][0] = tmp[1] * axis[0] - s * axis[2];
			rot.m1[1][1] = c + tmp[1] * axis[1];
			rot.m1[1][2] = tmp[1] * axis[2] + s * axis[0];

			rot.m1[2][0] = tmp[2] * axis[0] + s * axis[1];
			rot.m1[2][1] = tmp[2] * axis[1] - s * axis[0];
			rot.m1[2][2] = c + tmp[2] * axis[2];

			Mat4 result;
			Vec4 v0(m.m00, m.m01, m.m02, m.m03);
			Vec4 v1(m.m10, m.m11, m.m12, m.m13);
			Vec4 v2(m.m20, m.m21, m.m22, m.m23);
			Vec4 v3(m.m30, m.m31, m.m32, m.m33);

			Vec4 r0 = v0 * rot.m1[0][0] + v1 * rot.m1[0][1] + v2 * rot.m1[0][2];
			Vec4 r1 = v0 * rot.m1[1][0] + v1 * rot.m1[1][1] + v2 * rot.m1[1][2];
			Vec4 r2 = v0 * rot.m1[2][0] + v1 * rot.m1[2][1] + v2 * rot.m1[2][2];
			Vec4 r3(rot.m1[3][0], rot.m1[3][1], rot.m1[3][2], rot.m1[3][3]);

			result.m1[0][0] = r0.x; result.m1[0][1] = r0.y; result.m1[0][2] = r0.z; result.m1[0][3] = r0.w;
			result.m1[1][0] = r1.x; result.m1[1][1] = r1.y; result.m1[1][2] = r1.z; result.m1[1][3] = r1.w;
			result.m1[2][0] = r2.x; result.m1[2][1] = r2.y; result.m1[2][2] = r2.z; result.m1[2][3] = r2.w;
			result.m1[3][0] = r3.x; result.m1[3][1] = r3.y; result.m1[3][2] = r3.z; result.m1[3][3] = r3.w;
			return result;
		}

		inline Vec3 Rotate(Vec3 vec, float angl, Vec3 axis)
		{
			return Rotate(Mat4(), angl, axis) * vec;
		}
	}
}