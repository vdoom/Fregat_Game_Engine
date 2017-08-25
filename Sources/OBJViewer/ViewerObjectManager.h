#pragma once
#include <Fregat/System/Core/ObjectManager.h>
#include <Fregat/System/Renderer/FPSCamera.h>
//
namespace Fregat
{
	namespace System
	{
		class ServiceLocator;
	}
}

class ViewerObjectManager :
	public Fregat::System::ObjectManager
{
private:
	Fregat::System::ServiceLocator* m_locator;
	std::string modelPath, texturePath; 
	//------
	Fregat::Entity rootObject;
	bool rotateByMouse;
	bool moveByMouse;
	//----------------------------------------------------------------
	Fregat::Render::FPSCamera cam2; 
public:
	ViewerObjectManager(Fregat::System::ServiceLocator* t_locator, std::string t_modelPath, std::string t_texturePath);
	virtual ~ViewerObjectManager(void);

	void Update() override{}
	void Init() override;
};

