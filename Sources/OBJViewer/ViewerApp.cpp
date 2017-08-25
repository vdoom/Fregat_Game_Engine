#include "ViewerApp.h"
#include <Fregat/System/Core/SDLWindow.h>
#include <Fregat/System/IO/Inputs/SDLInputController.h>
#include <Fregat/System/Assets/AssetsManagement/AssetsManager.h>
#include <Fregat/System/Renderer/OpenGL33Renderer.h>
#include "ViewerObjectManager.h"

using namespace Fregat::System::Inputs;
using namespace Fregat::Render;

void ViewerApp::InitApp()
{
	m_window = std::move(std::unique_ptr<IWindow>(new SDLWindow()));
	m_window->CreateWindow(GLWindowParams(3,3,1,24), WindowParam("OBJviewer", 512, 512));
}

void ViewerApp::StartApp()
{
	m_isQute = true; 

	std::string modelPath = "";
	std::string texturePath = "";

	if(m_cmdArguments.size() > 1)
		modelPath = m_cmdArguments[1];
	if(m_cmdArguments.size() > 2)
		texturePath = m_cmdArguments[2];

	m_services.AddService("InputController", new SDLInputController());
	m_services.AddService("AssetsManager", new AssetsManager());
	m_services.AddService("Renderer", new OpenGL33Renderer());
	m_services.AddService("ObjectManager", new ViewerObjectManager(&m_services, modelPath, texturePath));

	m_services.GetService<SDLInputController>()->Init();
	m_services.GetService<AssetsManager>()->Init();
	m_services.GetService<OpenGL33Renderer>()->Init();
	m_services.GetService<ViewerObjectManager>()->Init();

	m_services.GetService<SDLInputController>()->actionQuit = [&]() {QuitApp(); };

	//-----------------------------------------------------------
	while (m_isQute)
	{
		m_services.UpdateServices();
		m_window->SwapBuffers();
	}
	//-----------------------------------------------------------

	m_window->DestroyWindow();
}

void ViewerApp::QuitApp()
{
	m_isQute = false;
}