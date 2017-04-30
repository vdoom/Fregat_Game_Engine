//---------------------------------------------
// Geometry3D is a container for 3D geometry loaded in paralell thread
// Can be used for loading StaticMesh data
// Created by Volodymyr KUKSYNOK 
// 2017
//---------------------------------------------
#pragma once
#include "../../AssetsManagement/AssetBin.h"
#include <memory>

namespace Fregat
{
	namespace System
	{
		namespace IO
		{
			struct MeshData;
		}

		class ComplexGeometry3D;

		class Geometry3D : public AssetBin
		{
			friend ComplexGeometry3D;
		private:
			void GenerateFromMeshData(IO::MeshData*);
		protected:
			std::unique_ptr<IO::MeshData> m_meshData;
			
		public:
			explicit Geometry3D(AssetsManager* t_manager, const std::string& t_path = std::string(""), const std::string& t_name = std::string(""));
			Geometry3D(Geometry3D&&);
			virtual ~Geometry3D() override;
			virtual bool Load() override;
			inline IO::MeshData* GetData() { return m_meshData.get(); }
		};
	}
}

