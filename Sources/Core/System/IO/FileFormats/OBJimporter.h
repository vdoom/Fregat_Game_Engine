//---------------------------------------------
// Wavefront .obj file importer to Static mesh
// Created by Volodymyr KUKSYNOK 
// 2017
//---------------------------------------------
#pragma once

#include <fstream>
#include <sstream>
#include "ParsersDataStructures.h"

namespace Fregat
{
	namespace System
	{
		namespace IO
		{	 
			Vertex ParsFace(string t_value, mesh t_mesh)
			{	
				// Face
				unsigned iPosition, iTexCoord, iNormal;
				Vertex vertex;
				
				string vertInd = "";
				string txInd = "";
				string normInd = "";
				int counter = 0;
				for(size_t i = 0; i < t_value.size(); ++i)
				{
					if((t_value[i]>='0' && t_value[i]<='9')||t_value[i]=='-')
					{
						if(counter == 0)
							vertInd += t_value[i];
						else if(counter == 1)
							txInd += t_value[i];
						else if(counter ==2)
							normInd += t_value[i];
					}
					else if(t_value[i] == '/')
						++counter;	
				}
			
				if(vertInd != "")
				{ 
					iPosition = stoi(vertInd);
					vertex.index = iPosition;
					vertex.position = t_mesh.vertices[iPosition - 1];
				}
			
				if(txInd != "")
				{ 
					iTexCoord = stoi(txInd);
					vertex.texcoord = t_mesh.texCoord[iTexCoord - 1];
					vertex.texcoord = Vec2(vertex.texcoord.x, 1-vertex.texcoord.y);
				}
			
				if(normInd != "")
				{
					iNormal = stoi(normInd);
					vertex.normal = t_mesh.normals[iNormal - 1];
				}
				return vertex;
			}
			
			mesh ParsOBJ(string t_path)
			{
				ifstream infile(t_path);
				string line;
				mesh msh;
				while(!infile.eof())
				{
					getline(infile, line);
					if(line.size() == 0 || (line.size() > 0 && line[0] == '#'))
						continue;
					istringstream iss(line);
					string symb;
					iss >> symb;
			
					if(symb == "mtllib")
						continue;//cout<<"Material File"<<iss;
					else if(symb == "o")
						iss >> msh.meshName;
					else if(symb == "v")
					{
						Vec3 vc;
						iss >> vc.x >> vc.y >> vc.z;
						msh.vertices.push_back(vc);
					}
					else if(symb == "vt")
					{
						Vec2 vc;
						iss >> vc.x >> vc.y;
						//vc.x=1-vc.x;
						//vc.y=1-vc.y;
						msh.texCoord.push_back(vc);
					}
					else if(symb == "vn")
					{
						Vec3 vc;
						iss >> vc.x >> vc.y >> vc.z;
						msh.normals.push_back(vc);
					}
					else if(symb == "usemtl")
						continue;//cout<<"Material Used"<<iss;
					else if(symb == "s")
						continue;//cout<<"S: "<<iss;
					else if(symb == "f")
					{
						while(!iss.eof())
						//for(size_t i = 0; i < 3; ++i)//while(!iss.eof())//for(size_t i = 0; i < 4; ++i)
						{
							string face;
							iss >> face;
							Vertex vert = ParsFace(face, msh);
							msh.RealVerteces.push_back(vert);
							msh.altIndex.push_back(msh.RealVerteces.size()-1);
						}
						//break;
					}
				}

				Vec3 AA, BB;
				for(auto pos : msh.vertices)
				{
					if(pos.x > AA.x)
						AA.x = pos.x;

					if(pos.x < BB.x)
						BB.x = pos.x;
					
					if(pos.y > AA.y)
						AA.y = pos.y;
					
					if(pos.y < BB.y)
						BB.y = pos.y;

					if(pos.z > AA.z)
						AA.z = pos.z;

					if(pos.z < BB.z)
						BB.z = pos.z;
				}
				msh.AA = AA;
				msh.BB = BB;
				msh.centr = (AA + BB) / 2;
				return msh;
			}
		}
	}
}