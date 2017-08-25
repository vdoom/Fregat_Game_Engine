#pragma once
#include <math.h>
#include <mmintrin.h>
#include <xmmintrin.h>
#include <float.h>
#include <cmath>
#include "stdlib.h"
namespace Fregat 
{
	namespace Math
	{
		#define	FLOAT_IS_NAN(x)			(((*(const unsigned long *)&x) & 0x7f800000) == 0x7f800000)
		#define FLOAT_IS_INF(x)			(((*(const unsigned long *)&x) & 0x7fffffff) == 0x7f800000)
		#define FLOAT_IS_IND(x)			((*(const unsigned long *)&x) == 0xffc00000)
		#define	FLOAT_IS_DENORMAL(x)	(((*(const unsigned long *)&x) & 0x7f800000) == 0x00000000 && \
										 ((*(const unsigned long *)&x) & 0x007fffff) != 0x00000000 )
		typedef unsigned long int dword;
		// Definitions
		const float  mcf_PI = float(3.14159265358979323846264338327950288419716939937510);
		const double mc_PI  = 3.14159265358979323846264338327950288419716939937510;        //!< pi
		
		const float  mcf_PI2 = float(3.14159265358979323846264338327950288419716939937510 * 2.0);
		const double mc_PI2  = 3.14159265358979323846264338327950288419716939937510 * 2.0; //!< 2*pi
		
		const double sqrt2 = 1.4142135623730950488016887242097;
		const double sqrt3 = 1.7320508075688772935274463415059;
		
		// math constants
		const float math_epsilon = 1e-5f;
		const float math_pi      = 3.1415926536f;
		const float math_radians = math_pi / 180.0f;
		const float math_degrees = 180.0f / math_pi;
		
		//#if defined _M_IX86_FP && _M_IX86_FP == 2
		inline float mcsqrt(float op)	{ __m128 s = _mm_sqrt_ss(_mm_set_ss(op));  float r; _mm_store_ss(&r, s);   return r; }
		inline float mcisqrt(float op) { __m128 s = _mm_rsqrt_ss(_mm_set_ss(op));  float r; _mm_store_ss(&r, s);   return r * (1.5f - op * r * r * 0.5f); }
		//#else
		inline float mcsqrt2(float op)	
		{
			return sqrtf(op);
		}
		inline float mcisqrt2(float op) 
		{
			return 1.0f / sqrt(op); 
		}
		//#endif
		
		inline double sqrt_tpl(double op) { return sqrt(op); }
		
		inline double isqrt_tpl(double op) { return 1.0 / sqrt(op); }
		
		#ifndef min
		inline float Min(float a, float b)
		{
			return (a < b ? a : b);
		}
		#endif
		
		#ifndef max
		inline float Max(float a, float b)
		{
			return (a < b ? b : a);
		}
		#endif
		
		// clamp x to [a,b]
		inline float Clamp(float x, float a, float b)
		{
			return (x < a ? a : ( x > b ? b : x ));
		}
		
		// linear interpolation
		inline float Lerp(float a, float b, float t)
		{
			return a + (b - a) * t;
		}
		
		// random number in [0,1]
		inline float UniRand()
		{
		    return (float)rand() / (float)RAND_MAX;
		}
		
		// random number in [0,a]
		inline float UniRand(float a)
		{
			return a * UniRand();
		}
		
		// random number in [a,b]
		inline float UniRand(float a, float b)
		{
			return Lerp(a, b, UniRand());
		}

		inline float  ToDegree(float radian)
		{
			return radian*(180.0f / mcf_PI);
		}

		inline float  ToRadian(float degree)
		{
			return degree*(mcf_PI / 180.0f);
		}

		inline bool AreEqualRel(float a, float b, float epsilon) 
		{
			return (fabs(a - b) <= epsilon * Max(fabs(a), fabs(b)));
		}
		//-------------------------------------------------------------------
	} 
}