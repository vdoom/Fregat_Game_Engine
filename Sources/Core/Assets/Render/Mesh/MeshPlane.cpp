#include "MeshPlane.h"

namespace Fregat
{
	namespace Render
	{
		MeshPlane::MeshPlane() : MeshBase()
		{
			m_mode = FRGGLMESH_USE_VAO;
		}

		MeshPlane::~MeshPlane()
		{
			//TODO: need to unbind and remove all buffers
		}

		void MeshPlane::InitPlane(Math::Rect t_size)
		{
			m_rect = t_size;
			m_texCord[0][0] = 1.0; m_texCord[0][1] = 0.0;
			m_texCord[1][0] = 0.0; m_texCord[1][1] = 0.0;
			m_texCord[2][0] = 0.0; m_texCord[2][1] = 1.0;
			m_texCord[3][0] = 1.0; m_texCord[3][1] = 1.0;

			m_verts[0][0] = m_rect.GetMinX(); m_verts[0][1] = m_rect.GetMaxY(); m_verts[0][2] = 0.0;
			m_verts[1][0] = m_rect.GetMaxX(); m_verts[1][1] = m_rect.GetMaxY(); m_verts[1][2] = 0.0;
			m_verts[2][0] = m_rect.GetMaxX(); m_verts[2][1] = m_rect.GetMinY(); m_verts[2][2] = 0.0;
			m_verts[3][0] = m_rect.GetMinX(); m_verts[3][1] = m_rect.GetMinY(); m_verts[3][2] = 0.0;

			m_indicesCount = 6;
			m_indices.resize(m_indicesCount);
			m_indices[0] = 0;
			m_indices[1] = 1;
			m_indices[2] = 2;
			m_indices[3] = 3;
			m_indices[4] = 0;
			m_indices[5] = 2;
			BakeMesh();
		}

		void MeshPlane::BakeMesh()
		{
			//TODO: need to make to modes with VAO or one VBO

			/* Allocate and assign a Vertex Array Object to our handle */
			glGenVertexArrays(1, &vao);

			/* Bind our Vertex Array Object as the current used object */
			glBindVertexArray(vao);

			/* Allocate and assign two Vertex Buffer Objects to our handle */
			glGenBuffers(3, vbo);

			/* Bind our first VBO as being the active buffer and storing vertex attributes (coordinates) */
			glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);

			/* Copy the vertex data from diamond to our buffer */
			/* 8 * sizeof(GLfloat) is the size of the diamond array, since it contains 8 GLfloat values */
			glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(GLfloat), m_verts, GL_STATIC_DRAW);

			/* Specify that our coordinate data is going into attribute index 0, and contains two floats per vertex */
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

			/* Enable attribute index 0 as being used */
			glEnableVertexAttribArray(0);

			/* Bind our second VBO as being the active buffer and storing vertex attributes (colors) */
			glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);

			/* Copy the color data from colors to our buffer */
			/* 12 * sizeof(GLfloat) is the size of the colors array, since it contains 12 GLfloat values */
			glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(GLfloat), m_texCord, GL_STATIC_DRAW);

			/* Specify that our color data is going into attribute index 1, and contains three floats per vertex */
			glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

			/* Enable attribute index 1 as being used */
			glEnableVertexAttribArray(1);

//--		------------------------------------------------------
			// Binde buffer for indeces
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo[2]);
			// Place indeces into index buffer
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indicesCount * sizeof(unsigned int),
				m_indices.data(), GL_STATIC_DRAW);

			m_isInitBuff = true;
		}
		
		MeshPlane MeshPlane::CratePlane(Math::Rect t_rect)
		{
			MeshPlane tmp;
			tmp.InitPlane(t_rect);
			tmp.BakeMesh();
			return tmp;
		}
	}
}