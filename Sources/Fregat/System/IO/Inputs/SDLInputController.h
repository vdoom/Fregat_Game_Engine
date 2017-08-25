//---------------------------------------------
// Input Controller working on SDL Input Events
// Created by Volodymyr KUKSYNOK 
// 2017
//---------------------------------------------

#pragma once

#include "SDL.h"
#include <Fregat/System/IO/Inputs/BaseInputController.h>

namespace Fregat
{
	namespace System
	{
		namespace Inputs
		{
			using namespace Fregat::Math;
			
			class SDLInputController : public BaseInputController
			{
			public:
				SDLInputController()
				{
				}

				void Update() override
				{
					SDL_Event event;
					/* Poll for events. SDL_PollEvent() returns 0 when there are no  */
					/* more events on the event queue, our while loop will exit when */
					/* that occurs.                                                  */
					while( SDL_PollEvent( &event ) )
					{
						//--------------------------------------------------------------------------------------------------
						static float angle = 0;
						if (event.key.type == SDL_QUIT)
						{
							actionQuit();
						}
						if( event.key.type == SDL_KEYDOWN )
						{
							if(event.key.keysym.scancode == SDL_SCANCODE_RIGHT)
							{
								actionRight(true);
								//inoutController->actionRight();
								//mat = Mat4::RotationY(1.0f) * mat;//Translation(0.05f,0,0);
								//---------------------------------------
								//auto pos = camera.GetPosition();
								//pos.z = pos.z;
								//camera.SetPosition(RotDotY(pos, camera.GetTarget(), ToRadian(1)));//(++angle)));
							}
							if(event.key.keysym.scancode == SDL_SCANCODE_LEFT)
							{
								actionLeft(true);
								//inoutController->actionLeft();
								//mat = Mat4::RotationY(-1.0f) * mat;//Mat4::Translation(-0.05f,0,0);
								//----------------------------------------------------------
								//auto pos = camera.GetPosition();
								//pos.z = pos.z;
								//camera.SetPosition(RotDotY(pos, camera.GetTarget(), ToRadian(-1)));

							}
							if(event.key.keysym.scancode == SDL_SCANCODE_UP)
							{
								actionForward(true);
								//mat = Mat4::RotationX(-1.0f) * mat;
							}
							if(event.key.keysym.scancode == SDL_SCANCODE_DOWN)
							{
								actionBack(true);
								//mat = Mat4::RotationX(1.0f) * mat;
							}
							if(event.key.keysym.scancode == SDL_SCANCODE_W)
							{
								actionWkey(true);
								//mat = mat * Mat4::Translation(0,-0.15f,0);//Translation(0.05f,0,0);
							}
							if(event.key.keysym.scancode == SDL_SCANCODE_S)
							{
								actionSkey(true);
								//mat = mat * Mat4::Translation(0,0.15f,0);//Mat4::Translation(-0.05f,0,0);
							}
							if(event.key.keysym.scancode == SDL_SCANCODE_A)
							{
								actionAkey(true);
								//mat = mat * Mat4::Translation(0.15f,0,0);
							}
							if(event.key.keysym.scancode == SDL_SCANCODE_D)
							{
								actionDkey(true);
								//mat = mat * Mat4::Translation(-0.15f,0,0);
							} 	
							if(event.key.keysym.scancode == SDL_SCANCODE_Q)
							{
								actionQkey(true);
								//mat = mat * Mat4::Translation(0,0,0.15);
							}
							if(event.key.keysym.scancode == SDL_SCANCODE_E)
							{
								actionEkey(true);
								//mat = mat * Mat4::Translation(0,0,-0.15);
							} 	
						}
						//--------------------------------------------------------------------------------------------------
						//PrintKeyInfo(&event.key, mat, camera, inoutController);
						if (event.type == SDL_MOUSEMOTION)
						{
							actionMouseMove(Vec2(event.motion.xrel, event.motion.yrel));
						}
						if (event.type == SDL_MOUSEWHEEL)
						{
							actionMouseWheel(Vec2(event.wheel.x, event.wheel.y));
						}
						if (event.type == SDL_MOUSEBUTTONDOWN)
						{
							/* If the left button was pressed. */
							if (event.button.button == SDL_BUTTON_LEFT)
							{
								actionLeftMButton(true);
							}

							if (event.button.button == SDL_BUTTON_RIGHT)
							{
								actionRightMButton(true);
							}
						}
						if(event.type == SDL_MOUSEBUTTONUP)
						{
							/* If the left button was relesed. */
							if (event.button.button == SDL_BUTTON_LEFT)
							{
								actionLeftMButton(false);
							}

							if (event.button.button == SDL_BUTTON_RIGHT)
							{
								actionRightMButton(false);
							}
						}
					}
				}
			};
		}
	}
}