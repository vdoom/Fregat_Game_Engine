#include "Texture2D.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_pixels.h>
#include <memory>

namespace Fregat
{
	namespace Render
	{
		Texture2D::Texture2D()
		{}

		Texture2D::~Texture2D()
		{
			//TODO: should free resources and delete dats
		}

		void Texture2D::InitTexture(std::string t_path)
		{
			SDL_Surface* loadedSurface = nullptr;//std::unique_ptr<SDL_Surface> loadedSurface(nullptr);
			bool success = true; 
			if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) 
			{ 
				printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() ); 
				success = false; 
			} 
			else 
			{
				 //Initialize PNG loading 
				int imgFlags = IMG_INIT_JPG; 
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{ 
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() ); 
					success = false; 
				} 
				else 
				{ 
					loadedSurface = IMG_Load(t_path.c_str());
					//Get window surface 
					//auto tmpFormat = loadedSurface->format;
					//tmpFormat->format = SDL_PIXELFORMAT_RGB888;
					//optimSurf = SDL_ConvertSurface( loadedSurface, tmpFormat, NULL );
			
					//SDL_FreeSurface( loadedSurface );//SDL_PIXELFORMAT_RGB888
				}
			}
			int Mode = GL_RGB;
			
			if(loadedSurface->format->BytesPerPixel == 4) 
			{
			    Mode = GL_RGBA;
			}
			//---------------------------------------------------
			// запросим у OpenGL свободный индекс текстуры
			glGenTextures(1, &m_textureID);
			
			// сделаем текстуру активной
			glBindTexture(GL_TEXTURE_2D, m_textureID);
			
			// установим параметры фильтрации текстуры - линейная фильтрация
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			
			// установим параметры "оборачивания" текстуры - отсутствие оборачивания
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			
			// загрузим данные о цвете в текущую автивную текстуру
			glTexImage2D(GL_TEXTURE_2D, 0, Mode/*GL_RGB*/, loadedSurface->w, loadedSurface->h, 0, Mode/*GL_RGB8*/,
				GL_UNSIGNED_BYTE, (const GLvoid*)(loadedSurface->pixels));
			//------------------------------------------------------------
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, m_textureID);
		
			if(loadedSurface!= nullptr)
				SDL_FreeSurface(loadedSurface);
		}

		Texture2D Texture2D::CreateTexture(std::string t_path)
		{
			Texture2D tmp;
			tmp.InitTexture(t_path);
			return tmp;
		}
	}
}