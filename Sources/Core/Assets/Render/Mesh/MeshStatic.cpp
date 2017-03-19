#include "MeshStatic.h"
#include "../../../System/IO/FileFormats/ParsersDataStructures.h"
#include "../../../System/IO/FileFormats/OBJimporter.h"

namespace Fregat
{
	namespace Render
	{
		MeshStatic::MeshStatic()
		{}

		MeshStatic::~MeshStatic()
		{}

		
		//void MeshStatic::InitPlane(System::IO::mesh& t_data)
		//{
		//	m_indices.swap(t_data.indeces);
		//	for(auto vert : t_data.vertices)
		//	{
		//		m_verts.push_back(vert.x);
		//		m_verts.push_back(vert.y);
		//		m_verts.push_back(vert.z);
		//	}
		//	for(auto vert : t_data.texCoord)
		//	{
		//		m_texCord.push_back(vert.x);
		//		m_texCord.push_back(vert.y);
		//	}
		//	m_indicesCount = m_indices.size();
		//}

		void MeshStatic::InitPlane(System::IO::mesh& t_data)
		{
			m_indices.swap(t_data.altIndex);
			for(auto vert : t_data.RealVerteces)
			{
				m_verts.push_back(vert.position.x);
				m_verts.push_back(vert.position.y);
				m_verts.push_back(vert.position.z);
				m_texCord.push_back(vert.texcoord.x);
				m_texCord.push_back(vert.texcoord.y);
				m_normals.push_back(vert.normal.x);
				m_normals.push_back(vert.normal.y);
				m_normals.push_back(vert.normal.z);
			}
			m_indicesCount = m_indices.size();
		}
		//inline const Math::Rect GetRect() const
		//{return m_rect;}
		MeshStatic MeshStatic::CratePlane(std::string t_path)
		{
			MeshStatic tmp;
			auto&& msh = System::IO::ParsOBJ(t_path);
			tmp.InitPlane(msh);
			tmp.BakeMesh();
			return tmp;
		}

		void MeshStatic::BakeMesh()
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
			glBufferData(GL_ARRAY_BUFFER, m_verts.size() * sizeof(GLfloat), m_verts.data(), GL_STATIC_DRAW);

			/* Specify that our coordinate data is going into attribute index 0, and contains two floats per vertex */
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

			/* Enable attribute index 0 as being used */
			glEnableVertexAttribArray(0);

			/* Bind our second VBO as being the active buffer and storing vertex attributes (colors) */
			glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);

			/* Copy the color data from colors to our buffer */
			/* 12 * sizeof(GLfloat) is the size of the colors array, since it contains 12 GLfloat values */
			glBufferData(GL_ARRAY_BUFFER, m_texCord.size() * sizeof(GLfloat), m_texCord.data(), GL_STATIC_DRAW);

			/* Specify that our color data is going into attribute index 1, and contains three floats per vertex */
			glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

			/* Enable attribute index 1 as being used */
			glEnableVertexAttribArray(1);

//--		------------------------------------------------------
			// начинаем работу с индексным буфером
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo[2]);
			// поместим в буфер индексы вершин куба
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indicesCount * sizeof(unsigned int),
				m_indices.data(), GL_STATIC_DRAW);

			m_isInitBuff = true;
		}
	}
}