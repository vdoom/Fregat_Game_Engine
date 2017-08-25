#include "ViewerObjectManager.h"
#include <Fregat/System/IO/Inputs/SDLInputController.h>
#include <Fregat/MathLib/MatOperations.h>
#include <Fregat/System/Static3DObjectFabriacator.h>
#include <Fregat/MathLib/AABB.h>
#include <Fregat/System/Core/ServiceLocator.h>

//------
#include <Fregat/System/Assets/AssetsManagement/AssetsManager.h>
#include <Fregat/System/Assets/Render/Texture/Texture2D.h>//TODO: move to asset root folder
#include <Fregat/System/Assets/Render/Shader/Shader.h>//TODO: move to asset root folder
#include <Fregat/System/Assets/Render/Mesh/MeshPlane.h>//TODO: move to asset root folder
#include <Fregat/System/Assets/Render/Mesh/MeshStatic.h>
#include <Fregat/System/Assets/Render/Material/SimpleMaterial.h>//TODO: move to asset root folder
#include <Fregat/System/Renderer/OpenGL33Renderer.h>
//#include <System/Renderer/Camera.h>


using namespace Fregat;
using namespace Fregat::Math;
using namespace Fregat::System;
using namespace Fregat::System::IO;
using namespace Fregat::System::Inputs;
using namespace Fregat::Render;

ViewerObjectManager::ViewerObjectManager(Fregat::System::ServiceLocator* t_locator, std::string t_modelPath, std::string t_texturePath)
{
	modelPath = t_modelPath;
	texturePath = t_texturePath;
	m_locator = t_locator;
	rotateByMouse = false;
	moveByMouse = false;
}


ViewerObjectManager::~ViewerObjectManager(void)
{
}

void ViewerObjectManager::Init()
{
	Fregat::Render::BaseRenderer* renderer = m_locator->GetServiceT<BaseRenderer>("Renderer");

	//Fregat::Entity camObject;
	
	cam2.SetUpPerspective(50., 1. / 1., 1, 100000.);
	cam2.SetPosition(Vec3(0, 0, 5));
	cam2.SetTarget(Vec3(0, 0, 0));
	//----------------------------------------------------------------
	//Fregat::Render::Camera cam(camObject);
	//camObject.AddComponent(&cam);
	//Perspective(50.,3./4.,1.,1000.);
	//cam.SetUpPerspective(50.,3./4.,1.,10000.);
	
	//rootObject.GetTransform().MoveBy(Vec3(0,0,0));
	
	//camObject.GetTransform().SetParent(&rootObject.GetTransform());

	//camObject.GetTransform().MoveBy(Vec3(0,-5,-20));
	//cam.LookAt(Vec3(0,-10,20), Vec3(0,0,0), Vec3::Up());
	//cam.UpdateCachedMat();
	renderer->SetCamera(&cam2);//(&cam);

	//TestObject tstObj;
	//Logger tmpLoger;
	
	BaseInputController* inputController = m_locator->GetService<BaseInputController>();//new SDLInputController();
	Mat4 mt2;
	inputController->actionRight = [&](bool) {mt2 = Mat4::RotationY(1.0f) * mt2; };
	inputController->actionForward = [&](bool) {mt2 = Mat4::RotationX(-1.0f) * mt2; };
	inputController->actionLeft = [&](bool) {mt2 = Mat4::RotationY(-1.0f) * mt2; };
	inputController->actionBack = [&](bool) {mt2 = Mat4::RotationX(1.0f) * mt2; };
	inputController->actionWkey = [&](bool) {mt2 = mt2 * Mat4::Translation(0, -0.15f, 0); };
	inputController->actionSkey = [&](bool) {mt2 = mt2 * Mat4::Translation(0, 0.15f, 0); };
	inputController->actionAkey = [&](bool) {mt2 = mt2 * Mat4::Translation(0.15f, 0, 0); };
	inputController->actionDkey = [&](bool) {mt2 = mt2 * Mat4::Translation(-0.15f, 0, 0); };
	inputController->actionQkey = [&](bool) {mt2 = mt2 * Mat4::Translation(0, 0, 0.15f); };
	inputController->actionEkey = [&](bool) {mt2 = mt2 * Mat4::Translation(0, 0, -0.15f); };
	
	inputController->actionLeftMButton = [&](bool isPressed)
	{
		rotateByMouse = isPressed;
	};
	inputController->actionRightMButton = [&](bool isPressed)
	{
		moveByMouse = isPressed;
	};
	inputController->actionMouseMove = [&](Vec2 vec) 
	{
		if(rotateByMouse)
		{
			//Rot Around Dest by UP
			float length = Length(cam2.GetPosition());
			Vec3 newPos = Rotate(Normalize(cam2.GetPosition()), ToRadian(-vec.x), cam2.GetUp());
			cam2.SetPosition(newPos*length);

			//Rot Around Dest by Right
			Vec3 rightVec = cam2.GetRight();//Cross(cam2.GetDirection(), cam2.GetUp());
			length = Length(cam2.GetPosition());
			newPos = Rotate(Normalize(cam2.GetPosition()), ToRadian(-vec.y), rightVec);
			Vec3 newUp = Rotate(cam2.GetUp(), ToRadian(-vec.y), rightVec);
			cam2.SetPosition(newPos*length);
			cam2.SetUp(newUp);
		}
		if(moveByMouse)
		{
			/*cam2.MoveUp(vec.y);
			cam2.MoveRight(vec.x);*/
		}
	};

	inputController->actionMouseWheel = [&](Vec2 vec)
	{
		//cout<<"wheel X: "<<vec.x<<", Y: "<<vec.y<<endl;
		cam2.GetTarget();
		cam2.GetPosition();
		Vec3 dir = Normalize(cam2.GetTarget() - cam2.GetPosition()); 
		dir*=vec.y;
		if(vec.y < 0 || Distance(cam2.GetTarget(), cam2.GetPosition()) + 1 > Length(dir))
			cam2.SetPosition(cam2.GetPosition()+dir);
	};
	//auto* rdrCmp = renderer.AddRendererComponent(&tstObj);
	//rdrCmp->InitRenderer(cude, (SimpleMaterial*)materialTest);
	Fregat::Static3DObjectFabriacator fabricator(m_locator->GetServiceT<AssetsManager>("AssetsManager"), renderer);
	
	//Entity* tstObj = fabricator.FabricateStatic3DObject(t_modelPath, t_texturePath, "default");
	ObjectManager::m_objects = fabricator.FabricateComplexStatic3DObject(modelPath, texturePath, "withLight");//"default");
	Entity* tmpEnt = m_objects[0].get();
	auto rnderWithMesh = tmpEnt->GetComponent<RenderComponent>();
	AABB tmpAABB = rnderWithMesh->GetMesh()->GetAABB();
	//Vec3 aa = rnderWithMesh->GetMesh()->GetAA();
	//Vec3 bb = rnderWithMesh->GetMesh()->GetBB();
	Vec3 maxBound = Vec3(Max(fabs(tmpAABB.GetAA().x), fabs(tmpAABB.GetBB().x)), 
						 Max(fabs(tmpAABB.GetAA().y), fabs(tmpAABB.GetBB().y)), 
						 Max(fabs(tmpAABB.GetAA().z), fabs(tmpAABB.GetBB().z)));
	float maxLength = Max(maxBound.x, Max(maxBound.y, maxBound.z));
	maxLength+=1+maxLength;
	cam2.SetPosition(Vec3(0, 0, maxLength));
	//tmpEnt->GetTransform().MoveBy(Vec3(5,0,0));
	tmpEnt->GetTransform().SetParent(&rootObject.GetTransform());
}