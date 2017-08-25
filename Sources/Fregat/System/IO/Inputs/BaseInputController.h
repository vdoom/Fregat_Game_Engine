//---------------------------------------------
// Base class for custom Input Controllers
// Created by Volodymyr KUKSYNOK 
// 2017
//---------------------------------------------

#pragma once

//#include <SDL.h>
#include <functional>
#include <Fregat/MathLib/Vec2.h>
#include <Fregat/System/Core/IService.h>

namespace Fregat
{
	namespace System
	{
		namespace Inputs
		{
			using namespace Fregat::Math;

			class BaseInputController : public IService
			{
			public:
				//TODO: need to refactor this
				std::function<void(bool)> actionForward;
				std::function<void(bool)> actionBack;
				std::function<void(bool)> actionLeft;
				std::function<void(bool)> actionRight;
				std::function<void(bool)> actionJump;
				std::function<void(bool)> actionWkey;
				std::function<void(bool)> actionSkey;
				std::function<void(bool)> actionAkey;
				std::function<void(bool)> actionDkey;
				std::function<void(bool)> actionQkey;
				std::function<void(bool)> actionEkey;
				std::function<void()> actionQuit;
				std::function<void(bool)> actionLeftMButton;
				std::function<void(bool)> actionRightMButton;
				std::function<void(Vec2)> actionMouseMove;
				std::function<void(Vec2)> actionMouseWheel;

				BaseInputController()
				{
					//reactionOnInput = [](SDL_KeyboardEvent*) {};
					//---------------------------------------
					actionForward = [](bool){};
					actionBack = [](bool){};
					actionLeft = [](bool){};
					actionRight = [](bool){};
					actionJump = [](bool){};
					actionWkey = [](bool){};
					actionSkey = [](bool){};
					actionAkey = [](bool){};
					actionDkey = [](bool){};
					actionQuit = [](){};

					actionMouseMove = [](Vec2) {};
					actionMouseWheel = [](Vec2) {};
					actionLeftMButton = [](bool) {};
					actionRightMButton = [](bool) {};
				}

				//void Update() override
				//{
				//	//Empty
				//}
				//
			};
		}
	}
}