//---------------------------------------------
// SDL variant of App Main Window
// Created by Volodymyr KUKSYNOK 
// 2017
//---------------------------------------------
#pragma once

#include <Fregat/System/Core/IWindow.h>
#include <SDL.h>
#include <GL/glew.h>

namespace Fregat
{
	namespace System
	{
		

		class SDLWindow : public IWindow
		{
		private:
			SDL_Window *mainwindow; /* Our window handle */
			SDL_GLContext maincontext;
		public:
			SDLWindow()
			{
				maincontext = 0;
				mainwindow = 0;
			}

			~SDLWindow() override
			{
				DestroyWindow();
			}

			bool CreateWindow(GLWindowParams t_gl_params, WindowParam t_param) override
			{
				if (SDL_Init(SDL_INIT_VIDEO) < 0) /* Initialize SDL's Video subsystem */
				{
					//sdldie("Unable to initialize SDL"); /* Or die on error */
					//printf("%s: %s\n", msg, SDL_GetError());
					SDL_Quit();
					return false;
				}
				SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, t_gl_params.gl_major_version);//3);
				SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, t_gl_params.gl_minor_version);//3);

				/* Turn on double buffering with a 24bit Z buffer.
				 * You may need to change this to 16 or 32 for your system */
				SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, t_gl_params.gl_doublebuffer);//1);
				SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, t_gl_params.gl_depth_size);//24);

				/* Create our window centered at 512x512 resolution */
				mainwindow = SDL_CreateWindow(t_param.caption, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
					t_param.w, t_param.h, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

				/* Create our opengl context and attach it to our window */
				maincontext = SDL_GL_CreateContext(mainwindow);

				/* This makes our buffer swap syncronized with the monitor's vertical refresh */
				SDL_GL_SetSwapInterval(1);
				//-----------------------------------------------------------
				//INIT GLEW
				//------------------------------------------------------------
				glewInit();
				//------------------------------------------------------------
				return true;
			}

			void DestroyWindow() override
			{
			    SDL_GL_DeleteContext(maincontext);
			    SDL_DestroyWindow(mainwindow);
			    SDL_Quit();
			}

			void SwapBuffers() override
			{
				SDL_GL_SwapWindow(mainwindow);
			}
		};
	}
}