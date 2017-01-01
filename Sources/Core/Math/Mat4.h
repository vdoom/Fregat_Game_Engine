#pragma once

#include "MathCommon.h"
namespace Fregat 
{
	namespace Math
	{
		class Mat4
		{
		public:
			union
			{
				struct { float r1[4], r2[4], r3[4], r4[4]; };
				float m[16];
				float m1[4][4];
				struct
				{
					float m00,m01,m02,m03;
					float m10,m11,m12,m13;
					float m20,m21,m22,m23;
					float m30,m31,m32,m33;
				};
				//vect mt[3];
			};
		
			//todo: need remove
			union
			{
				__m128 resSSE;
				float res[4];
			} pResultSSE1, pResultSSE2, pResultSSE3, pResultSSE4;
		
			Mat4() {set(1, 0, 0, 0,
				        0, 1, 0, 0,
				        0, 0, 1, 0,
						0, 0, 0, 1);}
		
			void set(const float *t_f)
			{
				m[ 0] = t_f[ 0]; m[ 1] = t_f[ 1]; m[ 2] = t_f[ 2]; m[ 3] = t_f[ 3];
				m[ 4] = t_f[ 4]; m[ 5] = t_f[ 5]; m[ 6] = t_f[ 6]; m[ 7] = t_f[ 7];
				m[ 8] = t_f[ 8]; m[ 9] = t_f[ 9]; m[10] = t_f[10]; m[11] = t_f[11];
				m[12] = t_f[12]; m[13] = t_f[13]; m[14] = t_f[14]; m[15] = t_f[15];
			}
			
			void set(float  t_m0, float  t_m1, float  t_m2, float  t_m3,
			         float  t_m4, float  t_m5, float  t_m6, float  t_m7,
			         float  t_m8, float  t_m9, float t_m10, float t_m11,
			         float t_m12, float t_m13, float t_m14, float t_m15)
			{
				m[ 0] =  t_m0; m[ 1] =  t_m1; m[ 2] =  t_m2; m[ 3] =  t_m3;
				m[ 4] =  t_m4; m[ 5] =  t_m5; m[ 6] =  t_m6; m[ 7] =  t_m7;
				m[ 8] =  t_m8; m[ 9] =  t_m9; m[10] = t_m10; m[11] = t_m11;
				m[12] = t_m12; m[13] = t_m13; m[14] = t_m14; m[15] = t_m15;
			}
			
			void set(const Mat4& t_mat)
			{
				m[ 0] = t_mat[ 0]; m[ 1] = t_mat[ 1]; m[ 2] = t_mat[ 2]; m[ 3] = t_mat[ 3];
				m[ 4] = t_mat[ 4]; m[ 5] = t_mat[ 5]; m[ 6] = t_mat[ 6]; m[ 7] = t_mat[ 7];
				m[ 8] = t_mat[ 8]; m[ 9] = t_mat[ 9]; m[10] = t_mat[10]; m[11] = t_mat[11];
				m[12] = t_mat[12]; m[13] = t_mat[13]; m[14] = t_mat[14]; m[15] = t_mat[15];
			}
		
			//void set(const Mat2 &M);
			//void set(const Mat3 &M);
			//void set(const quat &q);
		
			explicit Mat4(const float* t_f) { set(t_f); }
			Mat4(const Mat4& t_mat)  { set(t_mat); }
			//mat4(const mat2 &M)  { set(M); }
			//mat4(const mat3 &M)  { set(M); }
			//mat4(const quat &q)  { set(q); }
		
			Mat4(float  t_m0, float  t_m1, float  t_m2, float  t_m3,
			     float  t_m4, float  t_m5, float  t_m6, float  t_m7,
			     float  t_m8, float  t_m9, float t_m10, float t_m11,
			     float t_m12, float t_m13, float t_m14, float t_m15)
			{
				set( t_m0,  t_m1,  t_m2,  t_m3,
				     t_m4,  t_m5,  t_m6,  t_m7,
				     t_m8,  t_m9, t_m10, t_m11,
				    t_m12, t_m13, t_m14, t_m15);
			}
		
			Mat4& operator=(const Mat4& t_mat) { set(t_mat); return *this; }
			//Mat4& operator=(const mat2 &M) { set(M); return *this; }
			//Mat4& operator=(const mat3 &M) { set(M); return *this; }
			//Mat4& operator=(const quat &q) { set(q); return *this; }
		
			float operator[](int t_i)       { return m[t_i]; }
			float operator[](int t_i) const { return m[t_i]; }
		
			const Mat4 operator+(const Mat4& t_mat) const
			{
				return Mat4(m[ 0] + t_mat[ 0], m[ 1] + t_mat[ 1], m[ 2] + t_mat[ 2], m[ 3] + t_mat[ 3],
				            m[ 4] + t_mat[ 4], m[ 5] + t_mat[ 5], m[ 6] + t_mat[ 6], m[ 7] + t_mat[ 7],
				            m[ 8] + t_mat[ 8], m[ 9] + t_mat[ 9], m[10] + t_mat[10], m[11] + t_mat[11],
				            m[12] + t_mat[12], m[13] + t_mat[13], m[14] + t_mat[14], m[15] + t_mat[15]);
			}
			const Mat4 operator-(const Mat4& t_mat) const
			{
				return Mat4(m[ 0] - t_mat[ 0], m[ 1] - t_mat[ 1], m[ 2] - t_mat[ 2], m[ 3] - t_mat[ 3],
				            m[ 4] - t_mat[ 4], m[ 5] - t_mat[ 5], m[ 6] - t_mat[ 6], m[ 7] - t_mat[ 7],
				            m[ 8] - t_mat[ 8], m[ 9] - t_mat[ 9], m[10] - t_mat[10], m[11] - t_mat[11],
				            m[12] - t_mat[12], m[13] - t_mat[13], m[14] - t_mat[14], m[15] - t_mat[15]);
			}
			const Mat4 operator*(const Mat4& t_mat) const
			{
				return Mat4(m[ 0] * t_mat[ 0] + m[ 1] * t_mat[ 4] + m[ 2] * t_mat[ 8] + m[ 3] * t_mat[12],
				            m[ 0] * t_mat[ 1] + m[ 1] * t_mat[ 5] + m[ 2] * t_mat[ 9] + m[ 3] * t_mat[13],
				            m[ 0] * t_mat[ 2] + m[ 1] * t_mat[ 6] + m[ 2] * t_mat[10] + m[ 3] * t_mat[14],
				            m[ 0] * t_mat[ 3] + m[ 1] * t_mat[ 7] + m[ 2] * t_mat[11] + m[ 3] * t_mat[15],
				            m[ 4] * t_mat[ 0] + m[ 5] * t_mat[ 4] + m[ 6] * t_mat[ 8] + m[ 7] * t_mat[12],
				            m[ 4] * t_mat[ 1] + m[ 5] * t_mat[ 5] + m[ 6] * t_mat[ 9] + m[ 7] * t_mat[13],
				            m[ 4] * t_mat[ 2] + m[ 5] * t_mat[ 6] + m[ 6] * t_mat[10] + m[ 7] * t_mat[14],
				            m[ 4] * t_mat[ 3] + m[ 5] * t_mat[ 7] + m[ 6] * t_mat[11] + m[ 7] * t_mat[15],
				            m[ 8] * t_mat[ 0] + m[ 9] * t_mat[ 4] + m[10] * t_mat[ 8] + m[11] * t_mat[12],
				            m[ 8] * t_mat[ 1] + m[ 9] * t_mat[ 5] + m[10] * t_mat[ 9] + m[11] * t_mat[13],
				            m[ 8] * t_mat[ 2] + m[ 9] * t_mat[ 6] + m[10] * t_mat[10] + m[11] * t_mat[14],
				            m[ 8] * t_mat[ 3] + m[ 9] * t_mat[ 7] + m[10] * t_mat[11] + m[11] * t_mat[15],
				            m[12] * t_mat[ 0] + m[13] * t_mat[ 4] + m[14] * t_mat[ 8] + m[15] * t_mat[12],
				            m[12] * t_mat[ 1] + m[13] * t_mat[ 5] + m[14] * t_mat[ 9] + m[15] * t_mat[13],
				            m[12] * t_mat[ 2] + m[13] * t_mat[ 6] + m[14] * t_mat[10] + m[15] * t_mat[14],
				            m[12] * t_mat[ 3] + m[13] * t_mat[ 7] + m[14] * t_mat[11] + m[15] * t_mat[15]);
			}
			const Mat4 operator*(float t_f) const
			{
				return Mat4(m[ 0] * t_f, m[ 1] * t_f, m[ 2] * t_f, m[ 3] * t_f,
				            m[ 4] * t_f, m[ 5] * t_f, m[ 6] * t_f, m[ 7] * t_f,
				            m[ 8] * t_f, m[ 9] * t_f, m[10] * t_f, m[11] * t_f,
				            m[12] * t_f, m[13] * t_f, m[14] * t_f, m[15] * t_f);
			}
			//todo: need remove
			const Mat4 Mult(float f) 
			{
				__m128 ValB1 = _mm_set_ps(f, f, f, f);
				
				pResultSSE1.resSSE = _mm_mul_ps(_mm_set_ps(m[ 3], m[ 2], m[ 1], m[ 0]), ValB1);
				pResultSSE2.resSSE = _mm_mul_ps(_mm_set_ps(m[ 7], m[ 6], m[ 5], m[ 4]), ValB1);
				pResultSSE3.resSSE = _mm_mul_ps(_mm_set_ps(m[11], m[10], m[ 9], m[ 8]), ValB1);
				pResultSSE4.resSSE = _mm_mul_ps(_mm_set_ps(m[15], m[14], m[13], m[12]), ValB1);
		
				return Mat4(pResultSSE1.res[0], pResultSSE1.res[1], pResultSSE1.res[2], pResultSSE1.res[3],
							pResultSSE2.res[0], pResultSSE2.res[1], pResultSSE2.res[2], pResultSSE2.res[3],
							pResultSSE3.res[0], pResultSSE3.res[1], pResultSSE3.res[2], pResultSSE3.res[3],
							pResultSSE4.res[0], pResultSSE4.res[1], pResultSSE4.res[2], pResultSSE4.res[3]);
			}
		
			const Mat4 operator/(float t_f) const
			{
				return Mat4(m[ 0] / t_f, m[ 1] / t_f, m[ 2] / t_f, m[ 3] / t_f,
				            m[ 4] / t_f, m[ 5] / t_f, m[ 6] / t_f, m[ 7] / t_f,
				            m[ 8] / t_f, m[ 9] / t_f, m[10] / t_f, m[11] / t_f,
				            m[12] / t_f, m[13] / t_f, m[14] / t_f, m[15] / t_f);
			}
		
			Mat4& operator+=(const Mat4& t_mat)
			{
				m[ 0] += t_mat[ 0]; m[ 1] += t_mat[ 1]; m[ 2] += t_mat[ 2]; m[ 3] += t_mat[ 3];
				m[ 4] += t_mat[ 4]; m[ 5] += t_mat[ 5]; m[ 6] += t_mat[ 6]; m[ 7] += t_mat[ 7];
				m[ 8] += t_mat[ 8]; m[ 9] += t_mat[ 9]; m[10] += t_mat[10]; m[11] += t_mat[11];
				m[12] += t_mat[12]; m[13] += t_mat[13]; m[14] += t_mat[14]; m[15] += t_mat[15];
				return *this;
			}
			Mat4& operator-=(const Mat4& t_mat)
			{
				m[ 0] -= t_mat[ 0]; m[ 1] -= t_mat[ 1]; m[ 2] -= t_mat[ 2]; m[ 3] -= t_mat[ 3];
				m[ 4] -= t_mat[ 4]; m[ 5] -= t_mat[ 5]; m[ 6] -= t_mat[ 6]; m[ 7] -= t_mat[ 7];
				m[ 8] -= t_mat[ 8]; m[ 9] -= t_mat[ 9]; m[10] -= t_mat[10]; m[11] -= t_mat[11];
				m[12] -= t_mat[12]; m[13] -= t_mat[13]; m[14] -= t_mat[14]; m[15] -= t_mat[15];
				return *this;
			}
			Mat4& operator*=(const Mat4& t_mat)
			{
				set(m[ 0] * t_mat[ 0] + m[ 1] * t_mat[ 4] + m[ 2] * t_mat[ 8] + m[ 3] * t_mat[12],
				    m[ 0] * t_mat[ 1] + m[ 1] * t_mat[ 5] + m[ 2] * t_mat[ 9] + m[ 3] * t_mat[13],
				    m[ 0] * t_mat[ 2] + m[ 1] * t_mat[ 6] + m[ 2] * t_mat[10] + m[ 3] * t_mat[14],
				    m[ 0] * t_mat[ 3] + m[ 1] * t_mat[ 7] + m[ 2] * t_mat[11] + m[ 3] * t_mat[15],
				    m[ 4] * t_mat[ 0] + m[ 5] * t_mat[ 4] + m[ 6] * t_mat[ 8] + m[ 7] * t_mat[12],
				    m[ 4] * t_mat[ 1] + m[ 5] * t_mat[ 5] + m[ 6] * t_mat[ 9] + m[ 7] * t_mat[13],
				    m[ 4] * t_mat[ 2] + m[ 5] * t_mat[ 6] + m[ 6] * t_mat[10] + m[ 7] * t_mat[14],
				    m[ 4] * t_mat[ 3] + m[ 5] * t_mat[ 7] + m[ 6] * t_mat[11] + m[ 7] * t_mat[15],
				    m[ 8] * t_mat[ 0] + m[ 9] * t_mat[ 4] + m[10] * t_mat[ 8] + m[11] * t_mat[12],
				    m[ 8] * t_mat[ 1] + m[ 9] * t_mat[ 5] + m[10] * t_mat[ 9] + m[11] * t_mat[13],
				    m[ 8] * t_mat[ 2] + m[ 9] * t_mat[ 6] + m[10] * t_mat[10] + m[11] * t_mat[14],
				    m[ 8] * t_mat[ 3] + m[ 9] * t_mat[ 7] + m[10] * t_mat[11] + m[11] * t_mat[15],
				    m[12] * t_mat[ 0] + m[13] * t_mat[ 4] + m[14] * t_mat[ 8] + m[15] * t_mat[12],
				    m[12] * t_mat[ 1] + m[13] * t_mat[ 5] + m[14] * t_mat[ 9] + m[15] * t_mat[13],
				    m[12] * t_mat[ 2] + m[13] * t_mat[ 6] + m[14] * t_mat[10] + m[15] * t_mat[14],
				    m[12] * t_mat[ 3] + m[13] * t_mat[ 7] + m[14] * t_mat[11] + m[15] * t_mat[15]);
				return *this;
			}
		
			Mat4& operator*=(float t_f)
			{
				m[ 0] *= t_f; m[ 1] *= t_f; m[ 2] *= t_f; m[ 3] *= t_f;
				m[ 4] *= t_f; m[ 5] *= t_f; m[ 6] *= t_f; m[ 7] *= t_f;
				m[ 8] *= t_f; m[ 9] *= t_f; m[10] *= t_f; m[11] *= t_f;
				m[12] *= t_f; m[13] *= t_f; m[14] *= t_f; m[15] *= t_f;
				return *this;
			}
		
			Mat4& operator/=(float t_f)
			{
				m[ 0] /= t_f; m[ 1] /= t_f; m[ 2] /= t_f; m[ 3] /= t_f;
				m[ 4] /= t_f; m[ 5] /= t_f; m[ 6] /= t_f; m[ 7] /= t_f;
				m[ 8] /= t_f; m[ 9] /= t_f; m[10] /= t_f; m[11] /= t_f;
				m[12] /= t_f; m[13] /= t_f; m[14] /= t_f; m[15] /= t_f;
				return *this;
			}
		
			static const Mat4 RotationX(float t_angle)
			{
				const float c = cosf(t_angle * math_radians), s = sinf(t_angle * math_radians);
		
				return Mat4(1, 0, 0, 0,
							0, c,-s, 0,
							0, s, c, 0,
							0, 0, 0, 1);
			}
		
			static const Mat4 RotationY(float t_angle)
			{
				const float c = cosf(t_angle * math_radians), s = sinf(t_angle * math_radians);
		
				return Mat4(c, 0, s, 0,
							0, 1, 0, 0,
							-s, 0, c, 0,
							0, 0, 0, 1);
			}
		
			static const Mat4 RotationZ(float t_angle)
			{
				const float c = cosf(t_angle * math_radians), s = sinf(t_angle * math_radians);
		
				return Mat4(c,-s, 0, 0,
							s, c, 0, 0,
							0, 0, 1, 0,
							0, 0, 0, 1);
			}
		
			static const Mat4 FromEuler(float t_x, float t_y, float t_z)
			{
				const float cx = cosf(t_x * math_radians), sx = sinf(t_x * math_radians),
							cy = cosf(t_y * math_radians), sy = sinf(t_y * math_radians),
							cz = cosf(t_z * math_radians), sz = sinf(t_z * math_radians);
		
				// rotationX * rotationY * rotationZ
				return Mat4(cy * cz, -cy * sz, sy, 0,
							cx * sz + sx * cz * sy, cx * cz - sx * sy * sz, -cy * sx, 0,
							sx * sz - cx * cz * sy, cz * sx + cx * sy * sz, cx * cy, 0,
							0, 0, 0, 1);
			}
		
			static const Mat4 Scale(float t_x, float t_y, float t_z)
			{
				return Mat4(t_x, 0, 0, 0,
							0, t_y, 0, 0,
							0, 0, t_z, 0,
							0, 0, 0, 1);
			}
		
			static const Mat4 Translation(float t_x, float t_y, float t_z)
			{
				return Mat4(1, 0, 0, t_x,
							0, 1, 0, t_y,
							0, 0, 1, t_z,
							0, 0, 0, 1);
			}
		};

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