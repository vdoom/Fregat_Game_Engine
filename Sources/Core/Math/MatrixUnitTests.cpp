#include <gtest/gtest.h>
#include "MatOperations.h"
#include <iostream>

using namespace std;
using namespace Fregat::Math;

TEST(Mat3Test, InitializationTests)
{
	Mat3 mat;
	EXPECT_EQ(mat.m00, 1); EXPECT_EQ(mat.m01, 0); EXPECT_EQ(mat.m02, 0);
	EXPECT_EQ(mat.m10, 0); EXPECT_EQ(mat.m11, 1); EXPECT_EQ(mat.m12, 0);
	EXPECT_EQ(mat.m20, 0); EXPECT_EQ(mat.m21, 0); EXPECT_EQ(mat.m22, 1);

	EXPECT_EQ(mat.m[0], 1); EXPECT_EQ(mat.m[1], 0); EXPECT_EQ(mat.m[2], 0);
	EXPECT_EQ(mat.m[3], 0); EXPECT_EQ(mat.m[4], 1); EXPECT_EQ(mat.m[5], 0);
	EXPECT_EQ(mat.m[6], 0); EXPECT_EQ(mat.m[7], 0); EXPECT_EQ(mat.m[8], 1);

	EXPECT_EQ(mat.m1[0][0], 1); EXPECT_EQ(mat.m1[0][1], 0); EXPECT_EQ(mat.m1[0][2], 0);
	EXPECT_EQ(mat.m1[1][0], 0); EXPECT_EQ(mat.m1[1][1], 1); EXPECT_EQ(mat.m1[1][2], 0);
	EXPECT_EQ(mat.m1[2][0], 0); EXPECT_EQ(mat.m1[2][1], 0); EXPECT_EQ(mat.m1[2][2], 1);
	
	EXPECT_EQ(mat[0], 1); EXPECT_EQ(mat[1], 0); EXPECT_EQ(mat[2], 0);
	EXPECT_EQ(mat[3], 0); EXPECT_EQ(mat[4], 1); EXPECT_EQ(mat[5], 0);
	EXPECT_EQ(mat[6], 0); EXPECT_EQ(mat[7], 0); EXPECT_EQ(mat[8], 1);	

	Mat3 mat2(1, 2, 3,
			  4, 5, 6,
			  7, 8, 9);
	
	EXPECT_EQ(mat2.m00, 1); EXPECT_EQ(mat2.m01, 2); EXPECT_EQ(mat2.m02, 3);
	EXPECT_EQ(mat2.m10, 4); EXPECT_EQ(mat2.m11, 5); EXPECT_EQ(mat2.m12, 6);
	EXPECT_EQ(mat2.m20, 7); EXPECT_EQ(mat2.m21, 8); EXPECT_EQ(mat2.m22, 9);

	EXPECT_EQ(mat2.m[0], 1); EXPECT_EQ(mat2.m[1], 2); EXPECT_EQ(mat2.m[2], 3);
	EXPECT_EQ(mat2.m[3], 4); EXPECT_EQ(mat2.m[4], 5); EXPECT_EQ(mat2.m[5], 6);
	EXPECT_EQ(mat2.m[6], 7); EXPECT_EQ(mat2.m[7], 8); EXPECT_EQ(mat2.m[8], 9);

	EXPECT_EQ(mat2.m1[0][0], 1); EXPECT_EQ(mat2.m1[0][1], 2); EXPECT_EQ(mat2.m1[0][2], 3);
	EXPECT_EQ(mat2.m1[1][0], 4); EXPECT_EQ(mat2.m1[1][1], 5); EXPECT_EQ(mat2.m1[1][2], 6);
	EXPECT_EQ(mat2.m1[2][0], 7); EXPECT_EQ(mat2.m1[2][1], 8); EXPECT_EQ(mat2.m1[2][2], 9);
	
	EXPECT_EQ(mat2[0], 1); EXPECT_EQ(mat2[1], 2); EXPECT_EQ(mat2[2], 3);
	EXPECT_EQ(mat2[3], 4); EXPECT_EQ(mat2[4], 5); EXPECT_EQ(mat2[5], 6);
	EXPECT_EQ(mat2[6], 7); EXPECT_EQ(mat2[7], 8); EXPECT_EQ(mat2[8], 9);

	mat = mat2;
	EXPECT_EQ(mat.m00, 1); EXPECT_EQ(mat.m01, 2); EXPECT_EQ(mat.m02, 3);
	EXPECT_EQ(mat.m10, 4); EXPECT_EQ(mat.m11, 5); EXPECT_EQ(mat.m12, 6);
	EXPECT_EQ(mat.m20, 7); EXPECT_EQ(mat.m21, 8); EXPECT_EQ(mat.m22, 9);
}

TEST(Mat3Test, ArithmeticTest)
{
	Mat3 mat;
	
	Mat3 mat2(1, 2, 3,
			  4, 5, 6,
			  7, 8, 9);

	mat = mat2;

	Mat3 res = mat + mat2;
	EXPECT_EQ(res.m00, 2); EXPECT_EQ(res.m01, 4); EXPECT_EQ(res.m02, 6);
	EXPECT_EQ(res.m10, 8); EXPECT_EQ(res.m11, 10); EXPECT_EQ(res.m12, 12);
	EXPECT_EQ(res.m20, 14); EXPECT_EQ(res.m21, 16); EXPECT_EQ(res.m22, 18);

	res = res - mat2;
	EXPECT_EQ(res.m00, 1); EXPECT_EQ(res.m01, 2); EXPECT_EQ(res.m02, 3);
	EXPECT_EQ(res.m10, 4); EXPECT_EQ(res.m11, 5); EXPECT_EQ(res.m12, 6);
	EXPECT_EQ(res.m20, 7); EXPECT_EQ(res.m21, 8); EXPECT_EQ(res.m22, 9);

	res = mat;
	res += mat2;
	EXPECT_EQ(res.m00, 2); EXPECT_EQ(res.m01, 4); EXPECT_EQ(res.m02, 6);
	EXPECT_EQ(res.m10, 8); EXPECT_EQ(res.m11, 10); EXPECT_EQ(res.m12, 12);
	EXPECT_EQ(res.m20, 14); EXPECT_EQ(res.m21, 16); EXPECT_EQ(res.m22, 18);

	res -= mat2;
	EXPECT_EQ(res.m00, 1); EXPECT_EQ(res.m01, 2); EXPECT_EQ(res.m02, 3);
	EXPECT_EQ(res.m10, 4); EXPECT_EQ(res.m11, 5); EXPECT_EQ(res.m12, 6);
	EXPECT_EQ(res.m20, 7); EXPECT_EQ(res.m21, 8); EXPECT_EQ(res.m22, 9);

	res = mat * 3;
	EXPECT_EQ(res.m00, 3);  EXPECT_EQ(res.m01, 6);  EXPECT_EQ(res.m02, 9);
	EXPECT_EQ(res.m10, 12); EXPECT_EQ(res.m11, 15); EXPECT_EQ(res.m12, 18);
	EXPECT_EQ(res.m20, 21); EXPECT_EQ(res.m21, 24); EXPECT_EQ(res.m22, 27);

	res = mat * res;
	EXPECT_EQ(res.m00, 90);  EXPECT_EQ(res.m01, 108);  EXPECT_EQ(res.m02, 126);
	EXPECT_EQ(res.m10, 198); EXPECT_EQ(res.m11, 243);  EXPECT_EQ(res.m12, 288);
	EXPECT_EQ(res.m20, 306); EXPECT_EQ(res.m21, 378);  EXPECT_EQ(res.m22, 450);

	res = mat * 3;
	EXPECT_EQ(res.m00, 3);  EXPECT_EQ(res.m01, 6);  EXPECT_EQ(res.m02, 9);
	res *= mat;
	EXPECT_EQ(res.m00, 90);  EXPECT_EQ(res.m01, 108);  EXPECT_EQ(res.m02, 126);
	EXPECT_EQ(res.m10, 198); EXPECT_EQ(res.m11, 243);  EXPECT_EQ(res.m12, 288);
	EXPECT_EQ(res.m20, 306); EXPECT_EQ(res.m21, 378);  EXPECT_EQ(res.m22, 450);

	res = mat * 3;
	EXPECT_EQ(res.m00, 3);  EXPECT_EQ(res.m01, 6);  EXPECT_EQ(res.m02, 9);
	EXPECT_EQ(res.m10, 12); EXPECT_EQ(res.m11, 15); EXPECT_EQ(res.m12, 18);
	EXPECT_EQ(res.m20, 21); EXPECT_EQ(res.m21, 24); EXPECT_EQ(res.m22, 27);

	res = res / 3;
	EXPECT_EQ(res.m00, 1); EXPECT_EQ(res.m01, 2); EXPECT_EQ(res.m02, 3);
	EXPECT_EQ(res.m10, 4); EXPECT_EQ(res.m11, 5); EXPECT_EQ(res.m12, 6);
	EXPECT_EQ(res.m20, 7); EXPECT_EQ(res.m21, 8); EXPECT_EQ(res.m22, 9);

	res *= 3;
	EXPECT_EQ(res.m00, 3);  EXPECT_EQ(res.m01, 6);  EXPECT_EQ(res.m02, 9);
	EXPECT_EQ(res.m10, 12); EXPECT_EQ(res.m11, 15); EXPECT_EQ(res.m12, 18);
	EXPECT_EQ(res.m20, 21); EXPECT_EQ(res.m21, 24); EXPECT_EQ(res.m22, 27);

	res /= 3;
	EXPECT_EQ(res.m00, 1); EXPECT_EQ(res.m01, 2); EXPECT_EQ(res.m02, 3);
	EXPECT_EQ(res.m10, 4); EXPECT_EQ(res.m11, 5); EXPECT_EQ(res.m12, 6);
	EXPECT_EQ(res.m20, 7); EXPECT_EQ(res.m21, 8); EXPECT_EQ(res.m22, 9);
}

TEST(Mat3Test, MatOperationsTest)
{
	//RotationX
	//RotationY
	//RotationZ
	//FromEuler
	//Scale
	//Translation
	//Mat3ToQuat
	//InverseMat3
	//TransposeMat3
	//DeterminantMat3
}

TEST(Mat4Test, InitializationTests)
{
	Mat4 mat;
	EXPECT_EQ(mat.m00, 1); EXPECT_EQ(mat.m01, 0); EXPECT_EQ(mat.m02, 0); EXPECT_EQ(mat.m03, 0);
	EXPECT_EQ(mat.m10, 0); EXPECT_EQ(mat.m11, 1); EXPECT_EQ(mat.m12, 0); EXPECT_EQ(mat.m13, 0);
	EXPECT_EQ(mat.m20, 0); EXPECT_EQ(mat.m21, 0); EXPECT_EQ(mat.m22, 1); EXPECT_EQ(mat.m23, 0);
	EXPECT_EQ(mat.m30, 0); EXPECT_EQ(mat.m31, 0); EXPECT_EQ(mat.m32, 0); EXPECT_EQ(mat.m33, 1);

	EXPECT_EQ(mat.m[0], 1);  EXPECT_EQ(mat.m[1], 0);  EXPECT_EQ(mat.m[2], 0);  EXPECT_EQ(mat.m[3], 0);
	EXPECT_EQ(mat.m[4], 0);  EXPECT_EQ(mat.m[5], 1);  EXPECT_EQ(mat.m[6], 0);  EXPECT_EQ(mat.m[7], 0);
	EXPECT_EQ(mat.m[8], 0);  EXPECT_EQ(mat.m[9], 0);  EXPECT_EQ(mat.m[10], 1); EXPECT_EQ(mat.m[11], 0);
	EXPECT_EQ(mat.m[12], 0); EXPECT_EQ(mat.m[13], 0); EXPECT_EQ(mat.m[14], 0); EXPECT_EQ(mat.m[15], 1);

	EXPECT_EQ(mat.m1[0][0], 1); EXPECT_EQ(mat.m1[0][1], 0); EXPECT_EQ(mat.m1[0][2], 0); EXPECT_EQ(mat.m1[0][3], 0);
	EXPECT_EQ(mat.m1[1][0], 0); EXPECT_EQ(mat.m1[1][1], 1); EXPECT_EQ(mat.m1[1][2], 0); EXPECT_EQ(mat.m1[1][3], 0);
	EXPECT_EQ(mat.m1[2][0], 0); EXPECT_EQ(mat.m1[2][1], 0); EXPECT_EQ(mat.m1[2][2], 1); EXPECT_EQ(mat.m1[2][3], 0);
	EXPECT_EQ(mat.m1[3][0], 0); EXPECT_EQ(mat.m1[3][1], 0); EXPECT_EQ(mat.m1[3][2], 0); EXPECT_EQ(mat.m1[3][3], 1);
	
	EXPECT_EQ(mat[0], 1);  EXPECT_EQ(mat[1], 0);  EXPECT_EQ(mat[2], 0);  EXPECT_EQ(mat[3], 0);
	EXPECT_EQ(mat[4], 0);  EXPECT_EQ(mat[5], 1);  EXPECT_EQ(mat[6], 0);  EXPECT_EQ(mat[7], 0);
	EXPECT_EQ(mat[8], 0);  EXPECT_EQ(mat[9], 0);  EXPECT_EQ(mat[10], 1); EXPECT_EQ(mat[11], 0);
	EXPECT_EQ(mat[12], 0); EXPECT_EQ(mat[13], 0); EXPECT_EQ(mat[14], 0); EXPECT_EQ(mat[15], 1);	

	Mat4 mat2(1,  2,  3,  4,
			  5,  6,  7,  8,
			  9,  10, 11, 12,
			  13, 14, 15, 16);
	
	EXPECT_EQ(mat2.m00,  1); EXPECT_EQ(mat2.m01,  2); EXPECT_EQ(mat2.m02,  3); EXPECT_EQ(mat2.m03, 4);
	EXPECT_EQ(mat2.m10,  5); EXPECT_EQ(mat2.m11,  6); EXPECT_EQ(mat2.m12,  7); EXPECT_EQ(mat2.m13, 8);
	EXPECT_EQ(mat2.m20,  9); EXPECT_EQ(mat2.m21, 10); EXPECT_EQ(mat2.m22, 11); EXPECT_EQ(mat2.m23, 12);
	EXPECT_EQ(mat2.m30, 13); EXPECT_EQ(mat2.m31, 14); EXPECT_EQ(mat2.m32, 15); EXPECT_EQ(mat2.m33, 16);

	EXPECT_EQ(mat2.m[0],  1);  EXPECT_EQ(mat2.m[1],  2);  EXPECT_EQ(mat2.m[2],  3);  EXPECT_EQ(mat2.m[3],  4);
	EXPECT_EQ(mat2.m[4],  5);  EXPECT_EQ(mat2.m[5],  6);  EXPECT_EQ(mat2.m[6],  7);  EXPECT_EQ(mat2.m[7],  8);
	EXPECT_EQ(mat2.m[8],  9);  EXPECT_EQ(mat2.m[9],  10); EXPECT_EQ(mat2.m[10], 11); EXPECT_EQ(mat2.m[11], 12);
	EXPECT_EQ(mat2.m[12], 13); EXPECT_EQ(mat2.m[13], 14); EXPECT_EQ(mat2.m[14], 15); EXPECT_EQ(mat2.m[15], 16);

	EXPECT_EQ(mat2.m1[0][0],  1); EXPECT_EQ(mat2.m1[0][1],  2); EXPECT_EQ(mat2.m1[0][2],  3); EXPECT_EQ(mat2.m1[0][3], 4);
	EXPECT_EQ(mat2.m1[1][0],  5); EXPECT_EQ(mat2.m1[1][1],  6); EXPECT_EQ(mat2.m1[1][2],  7); EXPECT_EQ(mat2.m1[1][3], 8);
	EXPECT_EQ(mat2.m1[2][0],  9); EXPECT_EQ(mat2.m1[2][1], 10); EXPECT_EQ(mat2.m1[2][2], 11); EXPECT_EQ(mat2.m1[2][3], 12);
	EXPECT_EQ(mat2.m1[3][0], 13); EXPECT_EQ(mat2.m1[3][1], 14); EXPECT_EQ(mat2.m1[3][2], 15); EXPECT_EQ(mat2.m1[3][3], 16);
	
	EXPECT_EQ(mat2[0],  1);  EXPECT_EQ(mat2[1],  2);  EXPECT_EQ(mat2[2],  3);  EXPECT_EQ(mat2[3], 4);
	EXPECT_EQ(mat2[4],  5);  EXPECT_EQ(mat2[5],  6);  EXPECT_EQ(mat2[6],  7);  EXPECT_EQ(mat2[7], 8);
	EXPECT_EQ(mat2[8],  9);  EXPECT_EQ(mat2[9],  10); EXPECT_EQ(mat2[10], 11); EXPECT_EQ(mat2[11], 12);
	EXPECT_EQ(mat2[12], 13); EXPECT_EQ(mat2[13], 14); EXPECT_EQ(mat2[14], 15); EXPECT_EQ(mat2[15], 16);	

	mat = mat2;
	EXPECT_EQ(mat.m00,  1); EXPECT_EQ(mat.m01,  2); EXPECT_EQ(mat.m02,  3); EXPECT_EQ(mat.m03, 4);
	EXPECT_EQ(mat.m10,  5); EXPECT_EQ(mat.m11,  6); EXPECT_EQ(mat.m12,  7); EXPECT_EQ(mat.m13, 8);
	EXPECT_EQ(mat.m20,  9); EXPECT_EQ(mat.m21, 10); EXPECT_EQ(mat.m22, 11); EXPECT_EQ(mat.m23, 12);
	EXPECT_EQ(mat.m30, 13); EXPECT_EQ(mat.m31, 14); EXPECT_EQ(mat.m32, 15); EXPECT_EQ(mat.m33, 16);
}

TEST(Mat4Test, ArithmeticTest)
{
	Mat4 mat;
	
	Mat4 mat2(1,  2,  3,  4,
			  5,  6,  7,  8,
			  9,  10, 11, 12,
			  13, 14, 15, 16);

	mat = mat2;

	Mat4 res = mat + mat2;
	EXPECT_EQ(res.m00, 2);  EXPECT_EQ(res.m01, 4);  EXPECT_EQ(res.m02, 6);  EXPECT_EQ(res.m03, 8); 
	EXPECT_EQ(res.m10, 10); EXPECT_EQ(res.m11, 12); EXPECT_EQ(res.m12, 14); EXPECT_EQ(res.m13, 16);
	EXPECT_EQ(res.m20, 18); EXPECT_EQ(res.m21, 20); EXPECT_EQ(res.m22, 22); EXPECT_EQ(res.m23, 24);
	EXPECT_EQ(res.m30, 26); EXPECT_EQ(res.m31, 28); EXPECT_EQ(res.m32, 30); EXPECT_EQ(res.m33, 32);

	res = res - mat2;
	EXPECT_EQ(res.m00,  1); EXPECT_EQ(res.m01,  2); EXPECT_EQ(res.m02,  3); EXPECT_EQ(res.m03, 4);
	EXPECT_EQ(res.m10,  5); EXPECT_EQ(res.m11,  6); EXPECT_EQ(res.m12,  7); EXPECT_EQ(res.m13, 8);
	EXPECT_EQ(res.m20,  9); EXPECT_EQ(res.m21, 10); EXPECT_EQ(res.m22, 11); EXPECT_EQ(res.m23, 12);
	EXPECT_EQ(res.m30, 13); EXPECT_EQ(res.m31, 14); EXPECT_EQ(res.m32, 15); EXPECT_EQ(res.m33, 16);

	res = mat;
	res += mat2;
	EXPECT_EQ(res.m00,  2); EXPECT_EQ(res.m01,  4); EXPECT_EQ(res.m02,  6); EXPECT_EQ(res.m03, 8);
	EXPECT_EQ(res.m10, 10); EXPECT_EQ(res.m11, 12); EXPECT_EQ(res.m12, 14); EXPECT_EQ(res.m13, 16);
	EXPECT_EQ(res.m20, 18); EXPECT_EQ(res.m21, 20); EXPECT_EQ(res.m22, 22); EXPECT_EQ(res.m23, 24);
	EXPECT_EQ(res.m30, 26); EXPECT_EQ(res.m31, 28); EXPECT_EQ(res.m32, 30); EXPECT_EQ(res.m33, 32);

	res -= mat2;
	EXPECT_EQ(res.m00,  1); EXPECT_EQ(res.m01,  2); EXPECT_EQ(res.m02,  3); EXPECT_EQ(res.m03, 4);
	EXPECT_EQ(res.m10,  5); EXPECT_EQ(res.m11,  6); EXPECT_EQ(res.m12,  7); EXPECT_EQ(res.m13, 8);
	EXPECT_EQ(res.m20,  9); EXPECT_EQ(res.m21, 10); EXPECT_EQ(res.m22, 11); EXPECT_EQ(res.m23, 12);
	EXPECT_EQ(res.m30, 13); EXPECT_EQ(res.m31, 14); EXPECT_EQ(res.m32, 15); EXPECT_EQ(res.m33, 16);

	res = mat * 3;
	EXPECT_EQ(res.m00,  3); EXPECT_EQ(res.m01,  6); EXPECT_EQ(res.m02,  9); EXPECT_EQ(res.m03, 12);
	EXPECT_EQ(res.m10, 15); EXPECT_EQ(res.m11, 18); EXPECT_EQ(res.m12, 21); EXPECT_EQ(res.m13, 24);
	EXPECT_EQ(res.m20, 27); EXPECT_EQ(res.m21, 30); EXPECT_EQ(res.m22, 33); EXPECT_EQ(res.m23, 36);
	EXPECT_EQ(res.m30, 39); EXPECT_EQ(res.m31, 42); EXPECT_EQ(res.m32, 45); EXPECT_EQ(res.m33, 48);

	res = mat * res;
	EXPECT_EQ(res.m00,  270); EXPECT_EQ(res.m01,  300); EXPECT_EQ(res.m02,  330); EXPECT_EQ(res.m03, 360);
	EXPECT_EQ(res.m10,  606); EXPECT_EQ(res.m11,  684); EXPECT_EQ(res.m12,  762); EXPECT_EQ(res.m13, 840);
	EXPECT_EQ(res.m20,  942); EXPECT_EQ(res.m21, 1068); EXPECT_EQ(res.m22, 1194); EXPECT_EQ(res.m23, 1320);
	EXPECT_EQ(res.m30, 1278); EXPECT_EQ(res.m31, 1452); EXPECT_EQ(res.m32, 1626); EXPECT_EQ(res.m33, 1800);

	res = mat * 3;
	EXPECT_EQ(res.m00, 3);  EXPECT_EQ(res.m01, 6);  EXPECT_EQ(res.m02, 9);
	res *= mat;
	EXPECT_EQ(res.m00,  270); EXPECT_EQ(res.m01,  300); EXPECT_EQ(res.m02,  330); EXPECT_EQ(res.m03, 360);
	EXPECT_EQ(res.m10,  606); EXPECT_EQ(res.m11,  684); EXPECT_EQ(res.m12,  762); EXPECT_EQ(res.m13, 840);
	EXPECT_EQ(res.m20,  942); EXPECT_EQ(res.m21, 1068); EXPECT_EQ(res.m22, 1194); EXPECT_EQ(res.m23, 1320);
	EXPECT_EQ(res.m30, 1278); EXPECT_EQ(res.m31, 1452); EXPECT_EQ(res.m32, 1626); EXPECT_EQ(res.m33, 1800);

	res = mat * 3;
	EXPECT_EQ(res.m00,  3); EXPECT_EQ(res.m01,  6); EXPECT_EQ(res.m02,  9); EXPECT_EQ(res.m03, 12);
	EXPECT_EQ(res.m10, 15); EXPECT_EQ(res.m11, 18); EXPECT_EQ(res.m12, 21); EXPECT_EQ(res.m13, 24);
	EXPECT_EQ(res.m20, 27); EXPECT_EQ(res.m21, 30); EXPECT_EQ(res.m22, 33); EXPECT_EQ(res.m23, 36);
	EXPECT_EQ(res.m30, 39); EXPECT_EQ(res.m31, 42); EXPECT_EQ(res.m32, 45); EXPECT_EQ(res.m33, 48);

	res = res / 3;
	EXPECT_EQ(res.m00,  1); EXPECT_EQ(res.m01,  2); EXPECT_EQ(res.m02,  3); EXPECT_EQ(res.m03, 4);
	EXPECT_EQ(res.m10,  5); EXPECT_EQ(res.m11,  6); EXPECT_EQ(res.m12,  7); EXPECT_EQ(res.m13, 8);
	EXPECT_EQ(res.m20,  9); EXPECT_EQ(res.m21, 10); EXPECT_EQ(res.m22, 11); EXPECT_EQ(res.m23, 12);
	EXPECT_EQ(res.m30, 13); EXPECT_EQ(res.m31, 14); EXPECT_EQ(res.m32, 15); EXPECT_EQ(res.m33, 16);

	res *= 3;
	EXPECT_EQ(res.m00,  3); EXPECT_EQ(res.m01,  6); EXPECT_EQ(res.m02,  9); EXPECT_EQ(res.m03, 12);
	EXPECT_EQ(res.m10, 15); EXPECT_EQ(res.m11, 18); EXPECT_EQ(res.m12, 21); EXPECT_EQ(res.m13, 24);
	EXPECT_EQ(res.m20, 27); EXPECT_EQ(res.m21, 30); EXPECT_EQ(res.m22, 33); EXPECT_EQ(res.m23, 36);
	EXPECT_EQ(res.m30, 39); EXPECT_EQ(res.m31, 42); EXPECT_EQ(res.m32, 45); EXPECT_EQ(res.m33, 48);

	res /= 3;
	EXPECT_EQ(res.m00,  1); EXPECT_EQ(res.m01,  2); EXPECT_EQ(res.m02,  3); EXPECT_EQ(res.m03, 4);
	EXPECT_EQ(res.m10,  5); EXPECT_EQ(res.m11,  6); EXPECT_EQ(res.m12,  7); EXPECT_EQ(res.m13, 8);
	EXPECT_EQ(res.m20,  9); EXPECT_EQ(res.m21, 10); EXPECT_EQ(res.m22, 11); EXPECT_EQ(res.m23, 12);
	EXPECT_EQ(res.m30, 13); EXPECT_EQ(res.m31, 14); EXPECT_EQ(res.m32, 15); EXPECT_EQ(res.m33, 16);
}

TEST(Mat4Test, MatOperationsTest)
{
	//RotationX
	//RotationY
	//RotationZ
	//FromEuler
	//Scale
	//Translation
	//Mat3ToQuat
	//InverseMat4
	//TransposeMat4
	//DeterminantMat4
	//Orthographic
	//Perspective
	//Frustum
}

TEST(Mat4Test, TransfomUntransform)
{
	Mat4 tmp;
	Vec3 gtPos(1,2,3);
	Vec3 gtScale(4,5,6);
	tmp *= Mat4::Translation(gtPos);
	Vec3 pos = GetPosFromMat4(tmp);
	EXPECT_EQ(pos, gtPos);
	tmp *= Mat4::Scale(gtScale);
	Vec3 scale = GetScaleFromMa4(tmp);
	pos = GetPosFromMat4(tmp);
	EXPECT_EQ(pos, gtPos);
	EXPECT_EQ(scale, gtScale);
	//Vec3 gtRot(30, 45, 90);
	//Mat4 tmp2;
	//tmp = Mat4::FromEuler(gtRot)*tmp;
	//tmp = Mat4::RotationX(gtRot.x) * tmp;
	//tmp *= Mat4::RotationY(gtRot.y);//Mat4::RotationY(gtRot.y) * tmp;
	//tmp = Mat4::RotationZ(gtRot.z) * tmp;
	
	//Vec3 rot = ToEulerMat4(TransposeMat4(tmp));
	//std::cout<<"GT x:"<<gtRot.x<<"; y:"<<gtRot.y<<"; z:"<<gtRot.z<<std::endl;
	//std::cout<<"res x:"<<rot.x<<"; y:"<<rot.y<<"; z:"<<rot.z<<std::endl;
	//EXPECT_EQ(gtRot, rot);
}

//TEST(Mat4Test, LookAtTest)
//{
//	Mat4 tmp;
//	Vec3 gtPos(0, -5, -20);
//	Vec3 gtCenter = Vec3::Zero();
//	tmp = LookAt(gtPos, gtCenter, Vec3::Up());
//	Vec3 pos = GetPosFromMat4(tmp);
//	EXPECT_EQ(gtPos, pos);
//}