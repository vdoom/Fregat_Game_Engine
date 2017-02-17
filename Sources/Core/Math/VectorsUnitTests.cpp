#include <gtest/gtest.h>
#include "MatOperations.h"
#include <iostream>

using namespace std;
using namespace Fregat::Math;

//	Vec2
//-----------------------------------
TEST(Vec2Test, InitializationTests)
{
	Vec2 vec1;
	EXPECT_EQ(vec1.x, .0);
	EXPECT_EQ(vec1.y, .0);
	
	Vec2 vec2(.2f, .3f);
	EXPECT_EQ(vec2.x, .2f);
	EXPECT_EQ(vec2.y, .3f);
	EXPECT_EQ(vec2.v[0], .2f);
	EXPECT_EQ(vec2.v[1], .3f);

	vec1 = vec2;
	EXPECT_EQ(vec1.x, .2f);
	EXPECT_EQ(vec1.y, .3f);

	vec1.Set(-1.0, -2.0);
	EXPECT_EQ(vec1.v[0], -1.0f);
	EXPECT_EQ(vec1.v[1], -2.0f);
	EXPECT_EQ(vec1[0], -1.0f);
	EXPECT_EQ(vec1[1], -2.0f);

	EXPECT_NE(vec1, vec2);
	EXPECT_EQ(vec1, vec1);
	vec2.Set(vec1.x, vec1.y);
	EXPECT_EQ(vec1, vec2);
}

TEST(Vec2Test, ArithmeticTest)
{
	Vec2 vec1(2,5);
	Vec2 vec2(4,3);

	Vec2 result = vec1 + vec2;
	EXPECT_EQ(result, Vec2(6, 8));

	result = vec1 - vec2;
	EXPECT_EQ(result, Vec2(-2, 2));

	result = vec1 * vec2;
	EXPECT_EQ(result, Vec2(8, 15));

	result = vec1 * 3;
	EXPECT_EQ(result, Vec2(6, 15));

	result = vec1 / 2;
	EXPECT_EQ(result, Vec2(1, 2.5f));

	Vec2 vec3(2,5);
	vec3 += vec1;
	EXPECT_EQ(vec3, Vec2(4, 10));

	vec3 -= vec1;
	EXPECT_EQ(vec3, Vec2(2, 5));

	vec3 *= 5;
	EXPECT_EQ(vec3, Vec2(10, 25));
	
	vec3 /= 5;
	EXPECT_EQ(vec3, Vec2(2, 5));
}

TEST(Vec2Test, VectorOperations)
{
	Vec2 vec1(2,5);
	Vec2 vec2(4,3);
	EXPECT_EQ(Distance(vec1, vec2), 2.8284271247461903f);
	EXPECT_EQ(Length(vec1), 5.385164807134504f);
	EXPECT_EQ(Dot(vec1, vec2), 23);
	EXPECT_EQ(Normalize(vec2), Vec2(0.8f, 0.6f));
}

//	Vec3
//----------------------------------------------------------
TEST(Vec3Test, InitializationTests)
{
	Vec3 vec1;
	EXPECT_EQ(vec1.x, .0);
	EXPECT_EQ(vec1.y, .0);
	EXPECT_EQ(vec1.z, .0);
	
	Vec3 vec2(.2f, .3f, .6f);
	EXPECT_EQ(vec2.x, .2f);
	EXPECT_EQ(vec2.y, .3f);
	EXPECT_EQ(vec2.z, .6f);
	EXPECT_EQ(vec2.v[0], .2f);
	EXPECT_EQ(vec2.v[1], .3f);
	EXPECT_EQ(vec2.v[2], .6f);

	vec1 = vec2;
	EXPECT_EQ(vec1.x, .2f);
	EXPECT_EQ(vec1.y, .3f);
	EXPECT_EQ(vec1.z, .6f);

	vec1.Set(-1.0, -2.0, -26.0);
	EXPECT_EQ(vec1.v[0], -1.0f);
	EXPECT_EQ(vec1.v[1], -2.0f);
	EXPECT_EQ(vec1.v[2], -26.0f);
	EXPECT_EQ(vec1[0], -1.0f);
	EXPECT_EQ(vec1[1], -2.0f);
	EXPECT_EQ(vec1[2], -26.0f);

	EXPECT_NE(vec1, vec2);
	EXPECT_EQ(vec1, vec1);
	vec2.Set(vec1.x, vec1.y, vec1.z);
	EXPECT_EQ(vec1, vec2);
}

TEST(Vec3Test, ArithmeticTest)
{
	Vec3 vec1(2,5,7);
	Vec3 vec2(4,3,9);

	Vec3 result = vec1 + vec2;
	EXPECT_EQ(result, Vec3(6, 8, 16));

	result = vec1 - vec2;
	EXPECT_EQ(result, Vec3(-2, 2, -2));

	result = vec1 * vec2;
	EXPECT_EQ(result, Vec3(8, 15, 63));

	result = vec1 * 3;
	EXPECT_EQ(result, Vec3(6, 15, 21));

	result = vec1 / 2;
	EXPECT_EQ(result, Vec3(1, 2.5f, 3.5f));

	Vec3 vec3(2,5,6);
	vec3 += vec1;
	EXPECT_EQ(vec3, Vec3(4, 10, 13));
	vec3 -= vec1;
	EXPECT_EQ(vec3, Vec3(2, 5, 6));

	vec3 *= 5;
	EXPECT_EQ(vec3, Vec3(10, 25, 30));
	
	vec3 /= 5;
	EXPECT_EQ(vec3, Vec3(2, 5, 6));
}

TEST(Vec3Test, VectorOperations)
{
	Vec3 vec1(2, 5, 6);
	Vec3 vec2(4, 3, 7);
	EXPECT_EQ(Distance(vec1, vec2), 3.0f);
	EXPECT_NEAR(Length(vec1), 8.06225774829855f, 0.001);
	EXPECT_EQ(Dot(vec1, vec2), 65);
	EXPECT_EQ(Cross(vec1, vec2), Vec3(17,10,-14));
	EXPECT_EQ(Normalize(vec2), Vec3(0.464990554975f, 0.348742916231f, 0.813733471207f));
}

//	Vec4
//----------------------------------------------------------
TEST(Vec4Test, InitializationTests)
{
	Vec4 vec1;
	EXPECT_EQ(vec1.x, .0);
	EXPECT_EQ(vec1.y, .0);
	EXPECT_EQ(vec1.z, .0);
	EXPECT_EQ(vec1.w, .0);
	
	Vec4 vec2(.2f, .3f, .6f, .4f);
	EXPECT_EQ(vec2.x, .2f);
	EXPECT_EQ(vec2.y, .3f);
	EXPECT_EQ(vec2.z, .6f);
	EXPECT_EQ(vec2.w, .4f);
	EXPECT_EQ(vec2.v[0], .2f);
	EXPECT_EQ(vec2.v[1], .3f);
	EXPECT_EQ(vec2.v[2], .6f);
	EXPECT_EQ(vec2.v[3], .4f);

	vec1 = vec2;
	EXPECT_EQ(vec1.x, .2f);
	EXPECT_EQ(vec1.y, .3f);
	EXPECT_EQ(vec1.z, .6f);
	EXPECT_EQ(vec1.w, .4f);

	vec1.Set(-1.0, -2.0, -26.0, 3.0f);
	EXPECT_EQ(vec1.v[0], -1.0f);
	EXPECT_EQ(vec1.v[1], -2.0f);
	EXPECT_EQ(vec1.v[2], -26.0f);
	EXPECT_EQ(vec1.v[3], 3.0f);
	EXPECT_EQ(vec1[0], -1.0f);
	EXPECT_EQ(vec1[1], -2.0f);
	EXPECT_EQ(vec1[2], -26.0f);
	EXPECT_EQ(vec1[3], 3.0f);

	EXPECT_NE(vec1, vec2);
	EXPECT_EQ(vec1, vec1);
	vec2.Set(vec1.x, vec1.y, vec1.z, vec1.w);
	EXPECT_EQ(vec1, vec2);
}

TEST(Vec4Test, ArithmeticTest)
{
	Vec4 vec1(2, 5, 7, 4);
	Vec4 vec2(4, 3, 9, 8);

	Vec4 result = vec1 + vec2;
	EXPECT_EQ(result, Vec4(6, 8, 16, 12));

	result = vec1 - vec2;
	EXPECT_EQ(result, Vec4(-2, 2, -2, -4));

	result = vec1 * vec2;
	EXPECT_EQ(result, Vec4(8, 15, 63, 32));

	result = vec1 * 3;
	EXPECT_EQ(result, Vec4(6, 15, 21, 12));

	result = vec1 / 2;
	EXPECT_EQ(result, Vec4(1, 2.5f, 3.5f, 2));

	Vec4 vec3(2, 5, 6, 4);
	vec3 += vec1;
	EXPECT_EQ(vec3, Vec4(4, 10, 13, 8));
	vec3 -= vec1;
	EXPECT_EQ(vec3, Vec4(2, 5, 6, 4));

	vec3 *= 5;
	EXPECT_EQ(vec3, Vec4(10, 25, 30, 20));
	
	vec3 /= 5;
	EXPECT_EQ(vec3, Vec4(2, 5, 6, 4));
}