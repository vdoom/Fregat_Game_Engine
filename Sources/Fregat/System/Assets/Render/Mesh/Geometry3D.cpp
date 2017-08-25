#include "Geometry3D.h"
#include "MeshStatic.h"
#include <Fregat/System/IO/FileFormats/OBJimporter.h>
#include <Fregat/System/IO/FileFormats/ParsersDataStructures.h>

namespace Fregat
{
	namespace System
	{

		Geometry3D::Geometry3D(AssetsManager* t_manager, 
							   const std::string& t_path, 
							   const std::string& t_name) : 
			AssetBin(t_manager, t_path, t_name),
			m_meshData(nullptr)
		{
		}

		Geometry3D::Geometry3D(Geometry3D&& t_other)
			: AssetBin(std::move(t_other))
		{
			m_meshData = std::move(t_other.m_meshData);
		}

		Geometry3D::~Geometry3D()
		{
		}

		bool Geometry3D::Load()
		{
			//MeshStatic tmp;
			GenerateFromMeshData(System::IO::ParsOBJ(m_path));
			//m_meshData.reset(System::IO::ParsOBJ(m_path));
			return true; //TODO:need refine
		}

		void Geometry3D::GenerateFromMeshData(IO::MeshData* t_data)
		{
			m_meshData.reset(new IO::MeshData(*t_data));//.reset(t_data);
		}
	}
}