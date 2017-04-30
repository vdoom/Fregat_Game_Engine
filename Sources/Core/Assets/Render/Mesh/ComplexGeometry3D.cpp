#include "ComplexGeometry3D.h"
#include "Geometry3D.h"
#include "../../../System/IO/FileFormats/OBJimporter.h"
#include "../../../System/IO/FileFormats/ParsersDataStructures.h"

namespace Fregat
{
	namespace System
	{

		ComplexGeometry3D::ComplexGeometry3D(AssetsManager* t_manager, const std::string& t_path, const std::string& t_name) :
			AssetBin(t_manager, t_path, t_name)
		{}

		ComplexGeometry3D::~ComplexGeometry3D()
		{}

		bool ComplexGeometry3D::Load()
		{
			auto&& objects = System::IO::ParsOBJall(m_path);

			for (size_t i = 0; i < objects.size(); ++i)
			{
				Geometry3D* tmp = new Geometry3D(m_manager, m_path, objects[i]->meshName);
				tmp->GenerateFromMeshData(objects[i].get());
				m_meshData.push_back(std::move(std::unique_ptr<Geometry3D>(tmp)));
			}
			return true;
			//return false;
		}

	}
}