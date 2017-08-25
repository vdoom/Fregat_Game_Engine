//---------------------------------------------
// Collection of Easing Methods
// http://gizma.com/easing/
// t - current time(frame)
// b - start value
// c - change in value
// d - duration
// Created by Volodymyr KUKSYNOK 
// 2014
//---------------------------------------------

#pragma once

#include <Fregat/MathLib/MathCommon.h>

namespace Fregat 
{
	namespace Math
	{
		namespace EasingLib
		{
		    static float LinearTween(float t, float b, float c, float d)
		    {
		        return c*t/d + b;
		    }
		
		    static float EaseInQuad(float t, float b, float c, float d)
		    {
		        t /= d;
		        return c*t*t + b;
		    }
		
		    static float EaseOutQuad(float t, float b, float c, float d)
		    {
		        t /= d;
		        return -c * t*(t-2) + b;
		    }
		
		    static float EaseInOutQuad(float t, float b, float c, float d)
		    {
		        t /= d/2;
		        if (t < 1) return c/2*t*t + b;
		        t--;
		        return -c/2 * (t*(t-2) - 1) + b;
		    }
		
		    static float EaseInCubic(float t, float b, float c, float d)
		    {
		        t /= d;
		        return c*t*t*t + b;
		    }
		
		    static float EaseOutCubic(float t, float b, float c, float d)
		    {
		        t /= d;
		        t--;
		        return c*(t*t*t + 1) + b;
		    }
		
		    static float EaseInOutCubic(float t, float b, float c, float d)
		    {
		        t /= d/2;
		        if (t < 1) return c/2*t*t*t + b;
		        t -= 2;
		        return c/2*(t*t*t + 2) + b;
		    }
		
		    static float EaseInQuart(float t, float b, float c, float d)
		    {
		        t /= d;
		        return c*t*t*t*t + b;
		    }
		
		    static float EaseOutQuart(float t, float b, float c, float d)
		    {
		        t /= d;
		        t--;
		        return -c * (t*t*t*t - 1) + b;
		    }
		
		    static float EaseInOutQuart(float t, float b, float c, float d)
		    {
		        t /= d/2;
		        if (t < 1) return c/2*t*t*t*t + b;
		        t -= 2;
		        return -c/2 * (t*t*t*t - 2) + b;
		    }
		
		    static float EaseInQuint(float t, float b, float c, float d)
		    {
		        t /= d;
		        return c*t*t*t*t*t + b;
		    }
		
		    static float EaseOutQuint(float t, float b, float c, float d)
		    {
		        t /= d;
		        t--;
		        return c*(t*t*t*t*t + 1) + b;
		    }
		
		    static float EaseInOutQuint(float t, float b, float c, float d)
		    {
		        t /= d/2;
		        if (t < 1) return c/2*t*t*t*t*t + b;
		        t -= 2;
		        return c/2*(t*t*t*t*t + 2) + b;
		    }
		
		    static float EaseInSine(float t, float b, float c, float d)
		    {
		        return -c * cos(t/d * (mcf_PI)) + c + b;
		    }
		
		    static float EaseOutSine(float t, float b, float c, float d)
		    {
		        return c * sin(t/d * (mcf_PI)) + b;
		    }
		
		    static float EaseInOutSine(float t, float b, float c, float d)
		    {
		        return -c/2 * (cos(mcf_PI*t/d) - 1) + b;
		    }
		
		    static float EaseInExpo(float t, float b, float c, float d)
		    {
		        return c * pow( 2, 10 * (t/d - 1) ) + b;
		    }
		
		    static float EaseOutExpo(float t, float b, float c, float d)
		    {
		        return c * ( -pow( 2, -10 * t/d ) + 1 ) + b;
		    }
		
		    static float EaseInOutExpo(float t, float b, float c, float d)
		    {
		        t /= d/2;
		        if (t < 1) return c/2 * pow( 2, 10 * (t - 1) ) + b;
		        t--;
		        return c/2 * ( -pow( 2, -10 * t) + 2 ) + b;
		    }
		
		    static float EaseInCirc(float t, float b, float c, float d)
		    {
		        t /= d;
		        return -c * (sqrt(1 - t*t) - 1) + b;
		    }
		
		    static float EaseOutCirc(float t, float b, float c, float d)
		    {
		        t /= d;
		        t--;
		        return c * sqrt(1 - t*t) + b;
		    }
		
		    static float EaseInOutCirc(float t, float b, float c, float d)
		    {
		        t /= d/2;
		        if (t < 1) return -c/2 * (sqrt(1 - t*t) - 1) + b;
		        t -= 2;
		        return c/2 * (sqrt(1 - t*t) + 1) + b;
		    }
		}
	}
}