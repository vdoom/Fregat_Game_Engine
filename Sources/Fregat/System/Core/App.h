//---------------------------------------------
// Base Class for Main App
// Created by Volodymyr KUKSYNOK 
// 2017
//---------------------------------------------
#pragma once

#include <Fregat/_API.h>
#include "IWindow.h"
#include "ServiceLocator.h"
#include <vector>
#include <memory>

namespace Fregat
{
	namespace System
	{//FREGAT_API
		class App
		{
		protected:
			std::vector<std::string> m_cmdArguments;
			std::unique_ptr<IWindow> m_window; //TODO: Should be unique_ptr
			ServiceLocator m_services;
		public:
			App();
			App(int argc, char *argv[])
			{
				m_cmdArguments.reserve(argc);
				for(int i = 0; i < argc; ++i)
				{
					m_cmdArguments.push_back(std::string(argv[i]));
				}
			}
			virtual ~App(){}

			virtual void InitApp() = 0;
			virtual void StartApp() = 0;
			virtual void QuitApp() = 0;
		};
	}
}