//---------------------------------------------
// Base interface for mesh
// Created by Volodymyr KUKSYNOK 
// 2017
//---------------------------------------------
#pragma once

#include "MeshBase.h"
#include <Fregat/MathLib/Rect.h>
#include <Fregat/MathLib/Mat4.h>

namespace Fregat
{
	namespace Render
	{
		class MeshPlane : public MeshBase
		{
		private:
			Math::Rect m_rect;
			//TODO: Need to change to standart types
			//--------------------------------------
			GLfloat m_verts[4][3];
			GLfloat m_texCord[4][2];
			
			//--------------------------------------
			void BakeMesh();
		public:
			MeshPlane();
			virtual ~MeshPlane();
			void InitMesh(Math::Rect);
			inline const Math::Rect GetRect() const
			{return m_rect;}
			virtual bool CreateAsset(System::AssetBin* t_assetBinData) override
			{
				return true;
			}
			static MeshPlane CratePlane(Math::Rect);
		};
	}
}