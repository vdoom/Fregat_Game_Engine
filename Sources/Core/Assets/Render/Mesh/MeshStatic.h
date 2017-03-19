//---------------------------------------------
// Static mesh (loading from file)
// Created by Volodymyr KUKSYNOK 
// 2017
//---------------------------------------------
#pragma once

#include "MeshBase.h"
#include <vector>
//#include "../../../MathLib/Rect.h"
//#include "../../../MathLib/Mat4.h"
//TODO: need implement and refine
namespace Fregat
{
	namespace System
	{
		namespace IO
		{
			class mesh;
		}
	}

	namespace Render
	{
		class MeshStatic : public MeshBase
		{
		private:
			//TODO: Need to change to standart types
			//--------------------------------------
			/*std::vector<GLfloat[3]> m_verts;
			std::vector<GLfloat[2]> m_texCord;
			std::vector<GLfloat[3]> m_normals;*/
			std::vector<GLfloat> m_verts;
			std::vector<GLfloat> m_texCord;
			std::vector<GLfloat> m_normals;
			//--------------------------------------
			void BakeMesh();
		public:
			MeshStatic();
			virtual ~MeshStatic();
			void InitPlane(System::IO::mesh&);
			//inline const Math::Rect GetRect() const
			//{return m_rect;}
			static MeshStatic CratePlane(std::string);
		};
	}
}