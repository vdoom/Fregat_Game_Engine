#pragma once

#include <iostream>
#include <algorithm>
#include <glm/glm.hpp> // glm::vec3
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <Fregat/MathLib/MatOperations.h>
#include <Fregat/MathLib/AABB.h>

using namespace std;
using namespace Fregat::Math;

void ShowMat(const glm::mat4 &a)
{
	cout<<a[0][0]<<" "<<a[0][1]<<" "<<a[0][2]<<" "<<a[0][3]<<endl;
	cout<<a[1][0]<<" "<<a[1][1]<<" "<<a[1][2]<<" "<<a[1][3]<<endl;
	cout<<a[2][0]<<" "<<a[2][1]<<" "<<a[2][2]<<" "<<a[2][3]<<endl;
	cout<<a[3][0]<<" "<<a[3][1]<<" "<<a[3][2]<<" "<<a[3][3]<<endl;
}

void ShowVec(const glm::vec3& vec)
{
	cout<<"X: "<<vec.x<<", Y: "<<vec.y<<", Z: "<<vec.z<<endl;
}

void ShowVec(const Vec3& vec)
{
	cout<<"X: "<<vec.x<<", Y: "<<vec.y<<", Z: "<<vec.z<<endl;
}

bool operator ==(const Fregat::Math::Vec3 &a, const glm::vec3 &b)
{
	return a.x == b.x && a.y == b.y && a.z == b.z;
}

bool operator ==(const glm::vec3 &a, const Fregat::Math::Vec3 &b)
{
	return (b == a);
}

bool operator ==(const Fregat::Math::Mat4 &a, const glm::mat4 &b)
{
	return (AreEqualRel(a.m1[0][0], b[0][0], 0.001) && AreEqualRel(a.m1[0][1], b[0][1], 0.001) && AreEqualRel(a.m1[0][2], b[0][2], 0.001) && AreEqualRel(a.m1[0][3], b[0][3], 0.001) && 
			AreEqualRel(a.m1[1][0], b[1][0], 0.001) && AreEqualRel(a.m1[1][1], b[1][1], 0.001) && AreEqualRel(a.m1[1][2], b[1][2], 0.001) && AreEqualRel(a.m1[1][3], b[1][3], 0.001) && 
			AreEqualRel(a.m1[2][0], b[2][0], 0.001) && AreEqualRel(a.m1[2][1], b[2][1], 0.001) && AreEqualRel(a.m1[2][2], b[2][2], 0.001) && AreEqualRel(a.m1[2][3], b[2][3], 0.001) &&
			AreEqualRel(a.m1[3][0], b[3][0], 0.001) && AreEqualRel(a.m1[3][1], b[3][1], 0.001) && AreEqualRel(a.m1[3][2], b[3][2], 0.001) && AreEqualRel(a.m1[3][3], b[3][3], 0.001));
}

bool operator ==(const glm::mat4 &a, const Fregat::Math::Mat4 &b)
{
	return (b == a);
}

template <class A, class B>
bool Compare(const A& val1, const B& val2)
{
	bool res = val1 == val2;
	cout << (res ? "true" : "false")<<endl; 
	return res;
}
