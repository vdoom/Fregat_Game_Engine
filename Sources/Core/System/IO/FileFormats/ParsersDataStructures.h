//---------------------------------------------
// Parser Data Structures (internal data presentation of parsed meshes for rendering meshes construction)
// Created by Volodymyr KUKSYNOK 
// 2017
//---------------------------------------------
#pragma once

#include <vector>
#include <string>
#include "../../../Math/Vec2.h"
#include "../../../Math/Vec3.h"

namespace Fregat
{
	namespace System
	{
		namespace IO
		{
			using namespace Fregat::Math;
			using namespace std;

			struct Vertex
			{
				Vec3 position;
				Vec3 normal;
				Vec2 texcoord;
				unsigned index;
				Vertex():
					 position()
					,normal()
					,texcoord()
					,index(0)
				{}
			};
			
			struct mesh
			{
				string meshName;
				vector<Vec3> vertices;
				//vector<Point3> indeces;
				vector<unsigned> indeces;
				vector<Vec2> texCoord;
				vector<Vec3> normals;
				vector<Vertex> RealVerteces;
				vector<unsigned> altIndex; // !!! USE THIS !!!
				Vec3 AA;
				Vec3 BB;
				Vec3 centr;
				//material
				//TODO: need implement parser for material
			};
		}
	}
}