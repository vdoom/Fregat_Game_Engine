#include <gtest/gtest.h>
#include "MatOperations.h"
#include <iostream>

using namespace std;
using namespace Fregat::Math;

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
