//#include <GL/glew.h>
#include "ViewerApp.h"

int main(int argc, char *argv[])
{
	Fregat::System::App* app = new ViewerApp(argc, argv);
	app->InitApp();
	app->StartApp();
	//Should be moved to mesh or Shaders
	//------------------------------------------------
	//glDisableVertexAttribArray(0);
    //glDisableVertexAttribArray(1);
	//------------------------------------------------
	return 0;
}