#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <memory>

#define GL3_PROTOTYPES 1
#include <GL/glew.h>
#include <SDL.h>

#include "Assets/AssetsManagement/AssetsManager.h"
#include "Assets/Render/Texture/Texture2D.h"//TODO: move to asset root folder
#include "Assets/Render/Shader/Shader.h"//TODO: move to asset root folder
#include "Assets/Render/Mesh/MeshPlane.h"//TODO: move to asset root folder
#include "Assets/Render/Mesh/MeshStatic.h"
#include "Assets/Render/Material/SimpleMaterial.h"//TODO: move to asset root folder
#include "System/Renderer/OpenGL33Renderer.h"
#include "System/Renderer/Camera.h"
#include "System/Tools/UUID.h"
#include "Entity.h"
//#include "TestObject.h"
#include "MathLib/MatOperations.h"
#include "Static3DObjectFabriacator.h"

//--------------------------------------------------------------------------------------------------
#include "System/IO/FileFormats/ParsersDataStructures.h"
#include "System/IO/FileFormats/OBJimporter.h"
//--------------------------------------------------------------------------------------------------

using namespace Fregat;
using namespace Fregat::Math;
using namespace Fregat::System;
using namespace Fregat::System::IO;
using namespace Fregat::Render;

namespace{
/* A simple function that prints a message, the error code returned by SDL, and quits the application */
void sdldie(char *msg)
{
    printf("%s: %s\n", msg, SDL_GetError());
    SDL_Quit();
    exit(1);
}

void PrintKeyInfo( SDL_KeyboardEvent *key , Mat4& mat)
{	
    if( key->type == SDL_KEYDOWN ){
		if(key->keysym.scancode == 79)
		{
			mat = Mat4::RotationY(1.0f) * mat;//Translation(0.05f,0,0);
		}
		if(key->keysym.scancode == 80)
		{
			mat = Mat4::RotationY(-1.0f) * mat;//Mat4::Translation(-0.05f,0,0);
		}
		if(key->keysym.scancode == 82)
		{
			mat = Mat4::RotationX(-1.0f) * mat;
		}
		if(key->keysym.scancode == 81)
		{
			mat = Mat4::RotationX(1.0f) * mat;
		}
		if(key->keysym.scancode == SDL_SCANCODE_W)
		{
			mat = mat * Mat4::Translation(0,-0.15f,0);//Translation(0.05f,0,0);
		}
		if(key->keysym.scancode == SDL_SCANCODE_S)
		{
			mat = mat * Mat4::Translation(0,0.15f,0);//Mat4::Translation(-0.05f,0,0);
		}
		if(key->keysym.scancode == SDL_SCANCODE_A)
		{
			mat = mat * Mat4::Translation(0.15f,0,0);
		}
		if(key->keysym.scancode == SDL_SCANCODE_D)
		{
			mat = mat * Mat4::Translation(-0.15f,0,0);
		} 	
		if(key->keysym.scancode == SDL_SCANCODE_Q)
		{
			mat = mat * Mat4::Translation(0,0,0.15);
		}
		if(key->keysym.scancode == SDL_SCANCODE_E)
		{
			mat = mat * Mat4::Translation(0,0,-0.15);
		} 	
    }
}

void KeyUpdate(Mat4 &mat)
{
	SDL_Event event;
	/* Poll for events. SDL_PollEvent() returns 0 when there are no  */
	/* more events on the event queue, our while loop will exit when */
	/* that occurs.                                                  */
	while( SDL_PollEvent( &event ) )
	{
		PrintKeyInfo(&event.key, mat);
	}
}

void drawscene(SDL_Window* window, std::string t_modelPath, std::string t_texturePath)
{
	AssetsManager am;
	am.Init();

	//Fregat::Render::TextureBase* texture2D = am.GetTexture(t_texturePath.c_str());
	//Fregat::Render::Shader* shaderTest = am.GetShader("default");
	//Fregat::Render::MeshBase* cude = am.GetMesh(t_modelPath.c_str());

	//Fregat::Render::MaterialBase* materialTest = am.GetMaterial("tmpMat",shaderTest, texture2D);

	auto tmp = ParsOBJall("L:/assets/models/fromBlender/dumbster.obj");

	Fregat::Render::OpenGL33Renderer renderer;

	Fregat::Entity camObject;
	Fregat::Entity rootObject;
	Fregat::Render::Camera cam(camObject);
	camObject.AddComponent(&cam);
	//Perspective(50.,3./4.,1.,1000.);
	cam.SetUpPerspective(50.,3./4.,1.,10000.);
	rootObject.GetTransform().MoveBy(Vec3(0,0,0));
	//camObject.GetTransform().SetParent(&rootObject.GetTransform());

	//camObject.GetTransform().MoveBy(Vec3(0,-5,-20));
	cam.LookAt(Vec3(0,-10,20), Vec3(0,0,0), Vec3::Up());
	cam.UpdateCachedMat();
	renderer.SetCamera(&cam);

	//TestObject tstObj;

	//auto* rdrCmp = renderer.AddRendererComponent(&tstObj);
	//rdrCmp->InitRenderer(cude, (SimpleMaterial*)materialTest);
	Fregat::Static3DObjectFabriacator fabricator(&am, &renderer);
	//Entity* tstObj = fabricator.FabricateStatic3DObject(t_modelPath, t_texturePath, "default");
	auto&& tmpObjects = fabricator.FabricateComplexStatic3DObject(t_modelPath, t_texturePath, "default");
	Entity* tmpEnt = tmpObjects[0];
	tmpEnt->GetTransform().MoveBy(Vec3(5,0,0));
	tmpEnt->GetTransform().SetParent(&rootObject.GetTransform());
	glEnable(GL_DEPTH_TEST);
	while(true)
	{
		//-------------------------------------------------------------------
	    glClearColor(0.5, 0.5, 0.5, 1.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//-----------------------------------------------------------------------------------
		//Mat4 mat1;// = tstObj.GetTransform().GetLocalTransformMatrix();
		//mat1 *= Mat4::RotationX(.25f)*Mat4::RotationY(-0.45f);
		Mat4 mt2 ;//= camObject.GetTransform().GetLocalTransformMatrix();
		KeyUpdate(mt2);
		rootObject.GetTransform().ApplyTransform(mt2);//.//SetLocalMatrix(mt2);
		cam.UpdateCachedMat();
		renderer.Render();
		//-----------------------------------------------------------------------------------

        /* Swap our buffers to make our changes visible */
        SDL_GL_SwapWindow(window);
	//-------------------------------------------
	}
	//----------------------------------
	//TODO: need to refactor this
	glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
}

void destroywindow(SDL_Window* window, SDL_GLContext context)
{
    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
}

int main(int argc, char *argv[])
{
	std::string pathToModel;
	std::string pathToTexture;
	if(argc<2)
	{
		std::cout<<"need more params";
		return -1;
	}
	else if(argc >= 2)
	{
		pathToModel = argv[1];
		if(argc == 3)
			pathToTexture = argv[2];
		else
			pathToTexture = std::string("default.png");
	}

    SDL_Window *mainwindow=0; /* Our window handle */
    SDL_GLContext maincontext=0; /* Our opengl context handle */

        if (SDL_Init(SDL_INIT_VIDEO) < 0) /* Initialize SDL's Video subsystem */
        sdldie("Unable to initialize SDL"); /* Or die on error */

    /* Request an opengl 3.3 context.
     * SDL doesn't have the ability to choose which profile at this time of writing,
     * but it should default to the core profile */
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

    /* Turn on double buffering with a 24bit Z buffer.
     * You may need to change this to 16 or 32 for your system */
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    /* Create our window centered at 512x512 resolution */
    mainwindow = SDL_CreateWindow("OBJview", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        512, 512, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

    /* Create our opengl context and attach it to our window */
    maincontext = SDL_GL_CreateContext(mainwindow);

    /* This makes our buffer swap syncronized with the monitor's vertical refresh */
    SDL_GL_SetSwapInterval(1);
	glewInit();
    /* Call our function that performs opengl operations */
	drawscene(mainwindow, pathToModel, pathToTexture);

    /* Delete our opengl context, destroy our window, and shutdown SDL */
    destroywindow(mainwindow, maincontext);
	getch();
    return 0;
}