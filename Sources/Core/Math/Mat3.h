#pragma once
#include "MathCommon.h"

namespace Fregat 
{
	namespace Math
	{
		class Mat3
		{
		public:
			union
			{
				struct { float r1[3], r2[3], r3[3]; };
				float m[9];
				float m1[3][3];
				struct
				{
					float m00,m01,m02;
					float m10,m11,m12;
					float m20,m21,m22;
				};
				//vect mt[3];
			};
		
			Mat3() {}
		
			void set(const float* t_f)
			{
				m[0] = t_f[0]; m[1] = t_f[1]; m[2] = t_f[2];
				m[3] = t_f[3]; m[4] = t_f[4]; m[5] = t_f[5];
				m[6] = t_f[6]; m[7] = t_f[7]; m[8] = t_f[8];
			}

			void set(float t_m0, float t_m1, float t_m2,
			         float t_m3, float t_m4, float t_m5,
			         float t_m6, float t_m7, float t_m8)
			{
				m[0] = t_m0; m[1] = t_m1; m[2] = t_m2;
				m[3] = t_m3; m[4] = t_m4; m[5] = t_m5;
				m[6] = t_m6; m[7] = t_m7; m[8] = t_m8;
			}

			void set(const Mat3& t_mat)
			{
				m[0] = t_mat[0]; m[1] = t_mat[1]; m[2] = t_mat[2];
				m[3] = t_mat[3]; m[4] = t_mat[4]; m[5] = t_mat[5];
				m[6] = t_mat[6]; m[7] = t_mat[7]; m[8] = t_mat[8];
			}
			
			//CONSTRUCTORS MUST BE OPTIMISED
			explicit Mat3(const float* t_f) { set(t_f); }
			Mat3(const Mat3& t_mat)  { set(t_mat); }
			//Mat3(const mat2 &M)  { set(M); }
			//Mat3(const mat4 &M)  { set(M); }
			//Mat3(const quat &q)  { set(q); }
		
			Mat3(float t_m0, float t_m1, float t_m2,
			     float t_m3, float t_m4, float t_m5,
			     float t_m6, float t_m7, float t_m8)
			{
				set(t_m0, t_m1, t_m2,
				    t_m3, t_m4, t_m5,
				    t_m6, t_m7, t_m8);
			}
		
			Mat3& operator=(const Mat3& t_mat) { set(t_mat); return *this; }
			//Mat3& operator=(const mat2 &M) { set(M); return *this; }
			//Mat3& operator=(const mat4 &M) { set(M); return *this; }
			//Mat3& operator=(const quat &q) { set(q); return *this; }
		
			float operator[](int t_i)       { return m[t_i]; }
			float operator[](int t_i) const { return m[t_i]; }
		
			//float operator[][](int i, int j) { return m1[i][j];}
		
			const Mat3 operator+(const Mat3& t_mat) const
			{
				return Mat3(m[0] + t_mat[0], m[1] + t_mat[1], m[2] + t_mat[2],
				            m[3] + t_mat[3], m[4] + t_mat[4], m[5] + t_mat[5],
				            m[6] + t_mat[6], m[7] + t_mat[7], m[8] + t_mat[8]);
			}

			const Mat3 operator-(const Mat3& t_mat) const
			{
				return Mat3(m[0] - t_mat[0], m[1] - t_mat[1], m[2] - t_mat[2],
				            m[3] - t_mat[3], m[4] - t_mat[4], m[5] - t_mat[5],
				            m[6] - t_mat[6], m[7] - t_mat[7], m[8] - t_mat[8]);
			}

			const Mat3 operator*(const Mat3& t_mat) const
			{
				return Mat3(m[0] * t_mat[0] + m[1] * t_mat[3] + m[2] * t_mat[6],
				            m[0] * t_mat[1] + m[1] * t_mat[4] + m[2] * t_mat[7],
				            m[0] * t_mat[2] + m[1] * t_mat[5] + m[2] * t_mat[8],
				            m[3] * t_mat[0] + m[4] * t_mat[3] + m[5] * t_mat[6],
				            m[3] * t_mat[1] + m[4] * t_mat[4] + m[5] * t_mat[7],
				            m[3] * t_mat[2] + m[4] * t_mat[5] + m[5] * t_mat[8],
				            m[6] * t_mat[0] + m[7] * t_mat[3] + m[8] * t_mat[6],
				            m[6] * t_mat[1] + m[7] * t_mat[4] + m[8] * t_mat[7],
				            m[6] * t_mat[2] + m[7] * t_mat[5] + m[8] * t_mat[8]);
			}

			const Mat3 operator*(float t_f) const
			{
				return Mat3(m[0] * t_f, m[1] * t_f, m[2] * t_f,
				            m[3] * t_f, m[4] * t_f, m[5] * t_f,
				            m[6] * t_f, m[7] * t_f, m[8] * t_f);
			}

			const Mat3 operator/(float t_f) const
			{
				return Mat3(m[0] / t_f, m[1] / t_f, m[2] / t_f,
				            m[3] / t_f, m[4] / t_f, m[5] / t_f,
				            m[6] / t_f, m[7] / t_f, m[8] / t_f);
			}
		
			Mat3& operator+=(const Mat3& t_mat)
			{
				m[0] += t_mat[0]; m[1] += t_mat[1]; m[2] += t_mat[2];
				m[3] += t_mat[3]; m[4] += t_mat[4]; m[5] += t_mat[5];
				m[6] += t_mat[6]; m[7] += t_mat[7]; m[8] += t_mat[8];
				return *this;
			}

			Mat3& operator-=(const Mat3& t_mat)
			{
				m[0] -= t_mat[0]; m[1] -= t_mat[1]; m[2] -= t_mat[2];
				m[3] -= t_mat[3]; m[4] -= t_mat[4]; m[5] -= t_mat[5];
				m[6] -= t_mat[6]; m[7] -= t_mat[7]; m[8] -= t_mat[8];
				return *this;
			}

			Mat3& operator*=(const Mat3& t_mat)
			{
				set(m[0] * t_mat[0] + m[1] * t_mat[3] + m[2] * t_mat[6],
				    m[0] * t_mat[1] + m[1] * t_mat[4] + m[2] * t_mat[7],
				    m[0] * t_mat[2] + m[1] * t_mat[5] + m[2] * t_mat[8],
				    m[3] * t_mat[0] + m[4] * t_mat[3] + m[5] * t_mat[6],
				    m[3] * t_mat[1] + m[4] * t_mat[4] + m[5] * t_mat[7],
				    m[3] * t_mat[2] + m[4] * t_mat[5] + m[5] * t_mat[8],
				    m[6] * t_mat[0] + m[7] * t_mat[3] + m[8] * t_mat[6],
				    m[6] * t_mat[1] + m[7] * t_mat[4] + m[8] * t_mat[7],
				    m[6] * t_mat[2] + m[7] * t_mat[5] + m[8] * t_mat[8]);
				return *this;
			}

			Mat3& operator*=(float t_f)
			{
				m[0] *= t_f; m[1] *= t_f; m[2] *= t_f;
				m[3] *= t_f; m[4] *= t_f; m[5] *= t_f;
				m[6] *= t_f; m[7] *= t_f; m[8] *= t_f;
				return *this;
			}

			Mat3& operator/=(float t_f)
			{
				m[0] /= t_f; m[1] /= t_f; m[2] /= t_f;
				m[3] /= t_f; m[4] /= t_f; m[5] /= t_f;
				m[6] /= t_f; m[7] /= t_f; m[8] /= t_f;
				return *this;
			}
		
			static const Mat3 RotationX(float t_angle)
			{
				const float c = cosf(t_angle * math_radians), s = sinf(t_angle * math_radians);

				return Mat3(1, 0, 0,
							0, c,-s,
							0, s, c);
			}
		
			static const Mat3 RotationY(float t_angle)
			{
				const float c = cosf(t_angle * math_radians), s = sinf(t_angle * math_radians);

				return Mat3(c, 0, s,
					        0, 1, 0,
						   -s, 0, c);
			}
		
			static const Mat3 RotationZ(float t_angle)
			{
				const float c = cosf(t_angle * math_radians), s = sinf(t_angle * math_radians);

				return Mat3(c,-s, 0,
							s, c, 0,
							0, 0, 1);
			}
		
			static const Mat3 FromEuler(float t_x, float t_y, float t_z)
			{
				const float cx = cosf(t_x * math_radians), sx = sinf(t_x * math_radians),
							cy = cosf(t_y * math_radians), sy = sinf(t_y * math_radians),
							cz = cosf(t_z * math_radians), sz = sinf(t_z * math_radians);
			
				// rotationX * rotationY * rotationZ
				return Mat3(cy * cz, -cy * sz, sy,
							cx * sz + sx * cz * sy, cx * cz - sx * sy * sz, -cy * sx,
							sx * sz - cx * cz * sy, cz * sx + cx * sy * sz, cx * cy);
			}
		
			static const Mat3 Scale(float t_x, float t_y, float t_z)
			{
				return Mat3(t_x, 0, 0,
							0, t_y, 0,
							0, 0, t_z);
			}
		
			static const Mat3 Translation(float t_x, float t_y, float t_z)
			{
				return Mat3(1, 0, t_x,
							0, 1, t_y,
							0, 0, t_z);
			}
		};

		bool operator==(const Mat3& t_mat1, const Mat3& t_mat2)
		{
			const int matSize = 9;
			for(size_t i = 0; i < matSize; ++i)
			{
				if(t_mat1[i] != t_mat2[i]) return false;
			}

			return true;
		}
	}
}