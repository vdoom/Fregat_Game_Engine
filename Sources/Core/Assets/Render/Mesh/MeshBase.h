//---------------------------------------------
// Base interface for mesh
// Created by Volodymyr KUKSYNOK 
// 2017
//---------------------------------------------
#pragma once
#include <GL/glew.h>// TODO: need to remove frome here
#include <vector>
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
		public:
			MeshBase() : AssetSys(nullptr)
			{
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
		};
	}
}
