#include <TestingTools.h>
//---------------------------------------
//TMP SOLUTION
#include <EntityComponent_tests.h>
//---------------------------------------
#define GLM_COORDINATE_SYSTEM GLM_LEFT_HANDED
using namespace std;
using namespace Fregat::Math;

//void ShowMat(const Fregat::Math::Mat4 &a)
//{
//	cout<<a.m1[0][0]<<" "<<a.m1[0][1]<<" "<<a.m1[0][2]<<" "<<a.m1[0][3]<<endl;
//	cout<<a.m1[1][0]<<" "<<a.m1[1][1]<<" "<<a.m1[1][2]<<" "<<a.m1[1][3]<<endl;
//	cout<<a.m1[2][0]<<" "<<a.m1[2][1]<<" "<<a.m1[2][2]<<" "<<a.m1[2][3]<<endl;
//	cout<<a.m1[3][0]<<" "<<a.m1[3][1]<<" "<<a.m1[3][2]<<" "<<a.m1[3][3]<<endl;
//}


void TestVec3()
{
	cout<<"Test Vec3"<<endl;
	Vec3 vec1(2, 5, 6);
	Vec3 vec2(4, 3, 7);
	float dist = Distance(vec1, vec2);
	float length = Length(vec1);
	float dot = Dot(vec1, vec2);
	Vec3 cross = Cross(vec1, vec2);
	Vec3 normalize = Normalize(vec2);

	glm::vec3 gvec1(2.0f, 5.0f, 6.0f);
	glm::vec3 gvec2(4.0f, 3.0f, 7.0f);
	float gdist = glm::distance(gvec1, gvec2);
	float glength = glm::length(gvec1);
	float gdot = glm::dot(gvec1, gvec2);
	glm::vec3 gcross = glm::cross(gvec1, gvec2);
	glm::vec3 gnormalize = glm::normalize(gvec2);
	
	cout<<"true : ";
	assert(Compare(vec1, vec1));
	cout<<"true : ";
	assert(Compare(gvec1, gvec1));
	cout<<"false : ";
	assert(!Compare(vec1, vec2));
	cout<<"false : ";
	assert(!Compare(gvec1, gvec2));
	cout<<"true : ";
	assert(Compare(vec1, gvec1));
	cout<<"true : ";
	assert(Compare(vec2, gvec2));
	cout<<"true : ";
	assert(Compare(dist, gdist));
	cout<<"true : ";
	assert(Compare(length, glength));
	cout<<"true : ";
	assert(Compare(dot, gdot));
	cout<<"true : ";
	assert(Compare(cross, gcross));
	cout<<"true : ";
	assert(Compare(normalize, gnormalize));

	//------------------------------------

	glm::vec3 grotated = glm::rotate(glm::vec3(0,0,20), glm::radians(45.0f), glm::vec3(0,1,0));
	Vec3 rotated = Rotate(Vec3(0,0,20), glm::radians(45.0f), Vec3::Up());
	cout<<"true : ";
	assert(Compare(rotated, grotated));

	AABB aabb1(Vec3(-3,-3,-3), Vec3(3,3,3));
	cout<<"true : ";
	assert(Compare(aabb1.GetCenter(), Vec3()));

	AABB aabb2(Vec3(2,2,2), Vec3(6,6,6));
	cout<<"true : ";
	assert(Compare(aabb2.GetCenter(), Vec3(4,4,4)));
}

void TestMat4()
{
	cout<<"Test Mat4"<<endl;
	Mat4 mat1;
	glm::mat4 gmat1;
	cout<<"true : ";
	assert(Compare(mat1, mat1));
	cout<<"true : ";
	assert(Compare(mat1, gmat1));
	Mat4 matTr = Mat4::RotationZ(90);
	cout<<"false : ";
	assert(!Compare(mat1, matTr));
	cout<<"false : ";
	assert(!Compare(gmat1, matTr));

	Mat4 mat2(1,  2,  3,  4,
			  5,  6,  7,  8,
			  9,  10, 11, 12,
			  13, 14, 15, 16);

	glm::mat4 gmat2(1,  2,  3,  4,
					5,  6,  7,  8,
					9,  10, 11, 12,
					13, 14, 15, 16);

	cout<<"true : ";
	assert(Compare(mat1, gmat1));

	Vec3 tPos(1,2,3);
	glm::vec3 gtPos(1,2,3);
	glm::mat4 gtransMat1 = glm::translate(gmat1, gtPos);
	Mat4 transMat1 = TranslationMat4(tPos);
	cout<<"true : ";
	assert(Compare(gtransMat1, transMat1));
	
	Vec3 scaleVal(4,5,6);
	glm::vec3 gscaleVal(4,5,6);
	Mat4 scaleMat = ScaleMat4(scaleVal);
	glm::mat4 gscaleMat = glm::scale(glm::mat4(), gscaleVal);
	cout<<"true : ";
	assert(Compare(gscaleMat, scaleMat));

	Mat4 rotX = Mat4::RotationX(90.0f); 
	glm::mat4 grotX = glm::rotate(glm::mat4(), 90.0f*math_radians, glm::vec3(1,0,0));
	cout<<"true : ";
	assert(Compare(rotX, grotX));

	Mat4 rotY = Mat4::RotationY(90.0f); 
	glm::mat4 grotY = glm::rotate(glm::mat4(), 90.0f*math_radians, glm::vec3(0,1,0));
	cout<<"true : ";
	assert(Compare(rotY, grotY));
	
	Mat4 rotZ = Mat4::RotationZ(90.0f); 
	glm::mat4 grotZ = glm::rotate(glm::mat4(), 90.0f*math_radians, glm::vec3(0,0,1));
	cout<<"true : ";
	assert(Compare(rotZ, grotZ));

	glm::mat4 glookAtMat = glm::lookAt(glm::vec3(0,-10,20), glm::vec3(0,0,0), glm::vec3(0,1,0));
	Mat4 lookAtMat = LookAt(Vec3(0,-10,20), Vec3(0,0,0), Vec3::Up());
	cout<<"true : ";
	assert(Compare(glookAtMat, lookAtMat));

	Mat4 pers = Perspective(50.,3./4.,1.,1000.);
	glm::mat4 gpers = glm::perspective(50.*math_radians,3./4.,1.,1000.);
	cout<<"true : ";
	assert(Compare(pers, glm::transpose(gpers)));

	glm::mat4 gtrasposed = gpers;
	Mat4 trasposed = TransposeMat4(pers);
	cout<<"true : ";
	assert(Compare(trasposed, gtrasposed));

	glm::mat4 grotMat = glm::rotate(glm::mat4(), glm::radians(45.0f), glm::vec3(0,1,0));
	Mat4 rotMat = Rotate(Mat4(), glm::radians(45.0f), Vec3(0,1,0));
	cout<<"true : ";
	assert(Compare(rotMat, grotMat));
}

void main()
{
	TestVec3();	
	TestMat4();

	EntityComponent_Tests::TestEntity teters;
	teters.TestEC();
	//EntityComponent_Tests::TestEC();
	//EXPECT_EQ(Distance(vec1, vec2), 3.0f);
	//EXPECT_NEAR(Length(vec1), 8.06225774829855f, 0.001);
	//EXPECT_EQ(Dot(vec1, vec2), 65);
	//EXPECT_EQ(Cross(vec1, vec2), Vec3(17,10,-14));
	//EXPECT_EQ(Normalize(vec2), Vec3(0.464990554975f, 0.348742916231f, 0.813733471207f));
}