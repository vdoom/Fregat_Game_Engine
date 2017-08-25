//---------------------------------------------
// Static mesh (loading from file)
// Created by Volodymyr KUKSYNOK 
// 2017
//---------------------------------------------
#pragma once

#include "MeshBase.h"
#include <vector>
//#include "Geometry3D.h"
//#include "../../../MathLib/Rect.h"
//#include "../../../MathLib/Mat4.h"
//TODO: need implement and refine
namespace Fregat
{
	namespace System
	{
		namespace IO
		{
			struct MeshData;
		}
	}

	namespace Render
	{
		class MeshStatic : public MeshBase
		{
		private:
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
			void InitMesh(System::IO::MeshData*);//TODO: need to rename
			//inline const Math::Rect GetRect() const
			//{return m_rect;}
			virtual bool CreateAsset(System::AssetBin* t_assetBinData) override;
			//static MeshStatic CratePlane(std::string);
		};
	}
}