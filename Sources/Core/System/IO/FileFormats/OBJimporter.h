//---------------------------------------------
// Wavefront .obj file importer to Static mesh
// Created by Volodymyr KUKSYNOK 
// 2017
//---------------------------------------------
#pragma once

#include <fstream>
#include <sstream>
#include <vector>
#include <memory>
//#include "ParsersDataStructures.h"

namespace Fregat
{
	namespace System
	{
		namespace IO
		{
			struct Vertex;
			struct MeshData;
			Vertex* ParsFace(const std::string& t_value, 
							 const MeshData& t_mesh, 
							 size_t t_prevMeshVertCount = 0,
							 size_t t_prevMeshTexCount = 0,
							 size_t t_prevMeshNormCount = 0);
			MeshData* ParsOBJ(const std::string& t_path);
			std::vector<std::unique_ptr<MeshData>> ParsOBJall(const std::string&);
		}
	}
}