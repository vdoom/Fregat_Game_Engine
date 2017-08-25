//---------------------------------------------
// Base interface for mesh
// Created by Volodymyr KUKSYNOK 
// 2017
//---------------------------------------------
#pragma once
#include <GL/glew.h>// TODO: need to remove frome here
#include <vector>
#include <Fregat/MathLib/Vec3.h>
#include <Fregat/MathLib/AABB.h>
#include "../../AssetsManagement/AssetSys.h"
//#include "../../AssetsManagement/AssetBase.h"

namespace Fregat
{
	namespace Render
	{
		enum FRGGL_MESH_MODE
		{
			FRGGLMESH_ONLY_VBO,
			FRGGLMESH_USE_VAO
		};

		class MeshBase : public System::AssetSys//: public System::AssetBase
		{
		protected:
			FRGGL_MESH_MODE m_mode;
			GLuint vao, vbo[4];
			GLuint m_indicesCount;
			std::vector<GLuint> m_indices; 
			bool m_isInitBuff;
			Math::AABB m_aabb;
			/*Math::Vec3 m_AA;
			Math::Vec3 m_BB;
			Math::Vec3 m_centr;*/
		public:
			MeshBase() : AssetSys(nullptr)
			{  
				vao = 0;
				m_mode = FRGGLMESH_USE_VAO;
				m_isInitBuff = false;
			}
			virtual ~MeshBase() override
			{
				glDeleteBuffers(2, vbo);
				glDeleteVertexArrays(1, &vao);
			}


			//virtual void Init() = 0;
			inline GLuint GetMeshPointer() const
			{
				if(m_mode == FRGGLMESH_USE_VAO)
					return vao;
				else if(m_mode == FRGGLMESH_ONLY_VBO)
					return vbo[0];
				return -1;
			}

			inline const GLuint* GetIndices() const
			{
				return m_indices.data();
			}

			inline const GLuint GetIndicesCount() const
			{
				return m_indicesCount;
			}

			inline const Math::AABB GetAABB() const
			{
				return m_aabb;
			}
			//inline const Math::Vec3 GetAA() const
			//{
			//	return m_AA;
			//}

			//inline const Math::Vec3 GetBB() const
			//{
			//	return m_BB;
			//}

			//inline const Math::Vec3 GetCeneter() const
			//{
			//	return m_centr;
			//}
		};
	}
}
