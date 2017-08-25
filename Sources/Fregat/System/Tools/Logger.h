//---------------------------------------------
// Logger for internall use
// used for Rendering System
// Created by Volodymyr KUKSYNOK 
// 2017
//---------------------------------------------
#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <ctime>

namespace Fregat
{
	namespace System
	{
		namespace Tools
		{
			using namespace std::chrono;

			class Logger
			{
			private:
				std::ostream& m_outStream;
				std::ofstream m_logFile;
				void WriteCaptionTimeToLogFile()
				{
					auto time = system_clock::to_time_t(system_clock::now());
					m_logFile << "Log created: " << std::ctime(&time) << "\n";
				}
			public:
				static const char endl = '\n';

				Logger() :
					m_outStream(std::cout),
					m_logFile("log.txt")
				{
					WriteCaptionTimeToLogFile();
				};

				Logger(std::string t_logFilePath) :
					m_outStream(std::cout),
					m_logFile("t_logFilePath")
				{
					WriteCaptionTimeToLogFile();
				};

				virtual ~Logger()
				{};

				//Templated operator>> that uses the std::ostream: Everything that has defined 
				//an operator<< for the std::ostream (Everithing "printable" with std::cout 
				//and its colleages) can use this function.    
				template<typename T>
				Logger& operator<< (const T& data)
				{
					// Todo: need to add 
					// <<"["<< system_clock::now().time_since_epoch() <<"]"
					m_outStream << data;
					m_logFile << data;

					return *this;
				}
			};
		}
	}
}