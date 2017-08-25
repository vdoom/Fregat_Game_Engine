//---------------------------------------------
// ComplexGeometry3D is a container for several Geometry3D loaded in paralell thread
// Can be used for loading object with several StaticMesh data
// Created by Volodymyr KUKSYNOK 
// 2017
//---------------------------------------------
#pragma once
#include "../../AssetsManagement/AssetBin.h"
#include <memory>
#include <vector>

namespace Fregat
{
	namespace System
	{
		//namespace IO
		//{
		//	struct MeshData;
		//}
		class Geometry3D;

		class ComplexGeometry3D : public AssetBin
		{
		protected:
			std::vector<std::unique_ptr<Geometry3D>> m_meshData;
		public:
			explicit ComplexGeometry3D(AssetsManager* t_manager, const std::string& t_path = std::string(""), const std::string& t_name = std::string(""));
			virtual ~ComplexGeometry3D() override;
			virtual bool Load() override;
			inline std::vector<std::unique_ptr<Geometry3D>>* GetData() { return &m_meshData; }
		};
	}
}
