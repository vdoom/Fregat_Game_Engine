#pragma once
#include <Fregat/System/Core/App.h>
//namespace Fregat
//{
//	namespace System
using namespace Fregat::System;

class ViewerApp :
	public App
{
private:
	bool m_isQute;
public:
	ViewerApp(void)
	{}

	ViewerApp(int argc, char *argv[]) :
		App(argc, argv)
	{}
	
	virtual ~ViewerApp(void)
	{}

	void InitApp() override;
	void StartApp() override;
	void QuitApp() override;
};

