#include "MeshStatic.h"
#include "Geometry3D.h"
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

		void MeshStatic::InitPlane(System::IO::MeshData* t_data)
		{
			//m_name = t_data->meshName;
			for (size_t i = 0; i < t_data->altIndex.size(); ++i)
			{
				m_indices.push_back(t_data->altIndex[i]);
			}
			//m_indices.swap(t_data.altIndex);
			for (size_t i = 0; i < t_data->RealVerteces.size(); ++i)//(auto vert : t_data->RealVerteces)
			{
				m_verts.push_back(t_data->RealVerteces[i]->position.x);
				m_verts.push_back(t_data->RealVerteces[i]->position.y);
				m_verts.push_back(t_data->RealVerteces[i]->position.z);
				m_texCord.push_back(t_data->RealVerteces[i]->texcoord.x);
				m_texCord.push_back(t_data->RealVerteces[i]->texcoord.y);
				m_normals.push_back(t_data->RealVerteces[i]->normal.x);
				m_normals.push_back(t_data->RealVerteces[i]->normal.y);
				m_normals.push_back(t_data->RealVerteces[i]->normal.z);
			}
			m_indicesCount = m_indices.size();
		}
		//inline const Math::Rect GetRect() const
		//{return m_rect;}
		//MeshStatic MeshStatic::CratePlane(std::string t_path)
		//{
		//	MeshStatic tmp;
		//	System::IO::MeshData* msh = System::IO::ParsOBJ(t_path);
		//	tmp.InitPlane(msh);
		//	tmp.BakeMesh();
		//	return tmp;
		//}

		bool MeshStatic::CreateAsset(System::AssetBin* t_assetBinData)
		{
			System::Geometry3D* geometry = (System::Geometry3D*) t_assetBinData;
			m_name = geometry->GetName();
			InitPlane(geometry->GetData());
			BakeMesh();
			return true; //TODO: need refine
		}

		void MeshStatic::BakeMesh()
		{
			//TODO: need to make to modes with VAO or one VBO

			/* Allocate and assign a Vertex Array Object to our handle */
			glGenVertexArrays(1, &vao);

			/* Bind our Vertex Array Object as the current used object */
			glBindVertexArray(vao);

			/* Allocate and assign two Vertex Buffer Objects to our handle */
			glGenBuffers(4, vbo);

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
			//----------------------------------------------------------------------------
			// Binde buffer for indeces and placing indeces there 
			glBindBuffer(GL_ARRAY_BUFFER, vbo[2]);
			glBufferData(GL_ARRAY_BUFFER, m_normals.size() * sizeof(GLfloat), m_normals.data(), GL_STATIC_DRAW);
			glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, 0);
			glEnableVertexAttribArray(2);
			//----------------------------------------------------------------------------

//--		------------------------------------------------------
			// Binde buffer for indeces
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo[3]);
			// Place indeces into index buffer
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indicesCount * sizeof(unsigned int),
				m_indices.data(), GL_STATIC_DRAW);

			m_isInitBuff = true;
		}
	}
}