//---------------------------------------------
// Interface for App Main Window
// Created by Volodymyr KUKSYNOK 
// 2017
//---------------------------------------------
#pragma once

namespace Fregat
{
	namespace System
	{
		struct GLWindowParams
		{
			int gl_major_version; // 3
			int gl_minor_version; // 3
			int gl_doublebuffer; // 1
			int gl_depth_size; // 24

			GLWindowParams(int t_gl_major_ver, int t_gl_minor_version, int t_gl_db, int t_gl_depth_size)
			{
				gl_major_version = t_gl_major_ver;
				gl_minor_version = t_gl_minor_version;
				gl_doublebuffer = t_gl_db;
				gl_depth_size = t_gl_depth_size;
			}
		};

		struct WindowParam
		{
			char* caption;
			int w;
			int h;

			WindowParam(char* t_caption, int t_w, int t_h)
			{
				caption = t_caption;
				w = t_w;
				h = t_h;
			}
		};

		class IWindow
		{
		public:
			virtual bool CreateWindow(GLWindowParams t_gl_params, WindowParam t_param) = 0;
			virtual void DestroyWindow() = 0;
			virtual void SwapBuffers() = 0;

			virtual ~IWindow()
			{}
		};
	}
}