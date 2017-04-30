#include "OBJimporter.h"
#include "ParsersDataStructures.h"

namespace Fregat
{
	namespace System
	{
		namespace IO
		{
			Vertex* ParsFace(const std::string& t_value,
							 const MeshData& t_mesh,
							 size_t t_prevMeshVertCount,
							 size_t t_prevMeshTexCount,
							 size_t t_prevMeshNormCount)
			{
				// Face
				Vertex* vertex = new Vertex();

				string vertInd = "";
				string txInd = "";
				string normInd = "";
				int counter = 0;
				for (size_t i = 0; i < t_value.size(); ++i)
				{
					if ((t_value[i] >= '0' && t_value[i] <= '9') || t_value[i] == '-')
					{
						if (counter == 0)
							vertInd += t_value[i];
						else if (counter == 1)
							txInd += t_value[i];
						else if (counter == 2)
							normInd += t_value[i];
					}
					else if (t_value[i] == '/')
						++counter;
				}

				if (vertInd != "")
				{
					size_t iPosition = 0;
					iPosition = stoi(vertInd);
					vertex->index = iPosition;
					vertex->position = t_mesh.vertices[iPosition - (1 + t_prevMeshVertCount)];
				}

				if (txInd != "")
				{
					size_t iTexCoord = 0;
					iTexCoord = stoi(txInd);
					vertex->texcoord = t_mesh.texCoord[iTexCoord - (1 + t_prevMeshTexCount)];
					vertex->texcoord = Vec2(vertex->texcoord.x, 1 - vertex->texcoord.y);
				}

				if (normInd != "")
				{
					size_t iNormal = 0;
					iNormal = stoi(normInd);
					vertex->normal = t_mesh.normals[iNormal - (1 + t_prevMeshNormCount)];
				}
				return vertex;
			}

			MeshData* ParsOBJ(const string& t_path)
			{
				ifstream infile(t_path);
				string line;
				MeshData* msh = new MeshData;
				while (!infile.eof())
				{
					getline(infile, line);
					if (line.size() == 0 || (line.size() > 0 && line[0] == '#'))
						continue;
					istringstream iss(line);
					string symb;
					iss >> symb;

					if (symb == "mtllib")
						continue;//cout<<"Material File"<<iss;
					else if (symb == "o")
						iss >> msh->meshName;
					else if (symb == "v")
					{
						Vec3 vc;
						iss >> vc.x >> vc.y >> vc.z;
						msh->vertices.push_back(vc);
					}
					else if (symb == "vt")
					{
						Vec2 vc;
						iss >> vc.x >> vc.y;
						//vc.x=1-vc.x;
						//vc.y=1-vc.y;
						msh->texCoord.push_back(vc);
					}
					else if (symb == "vn")
					{
						Vec3 vc;
						iss >> vc.x >> vc.y >> vc.z;
						msh->normals.push_back(vc);
					}
					else if (symb == "usemtl")
						continue;//cout<<"Material Used"<<iss;
					else if (symb == "s")
						continue;//cout<<"S: "<<iss;
					else if (symb == "f")
					{
						while (!iss.eof())
							//for(size_t i = 0; i < 3; ++i)//while(!iss.eof())//for(size_t i = 0; i < 4; ++i)
						{
							string face;
							iss >> face;
							std::shared_ptr<Vertex> vert(ParsFace(face, *msh));
							msh->RealVerteces.push_back(std::move(vert));
							msh->altIndex.push_back(msh->RealVerteces.size() - 1);
						}
						//break;
					}
				}

				Vec3 AA, BB;
				for (auto pos : msh->vertices)
				{
					if (pos.x > AA.x)
						AA.x = pos.x;

					if (pos.x < BB.x)
						BB.x = pos.x;

					if (pos.y > AA.y)
						AA.y = pos.y;

					if (pos.y < BB.y)
						BB.y = pos.y;

					if (pos.z > AA.z)
						AA.z = pos.z;

					if (pos.z < BB.z)
						BB.z = pos.z;
				}
				msh->AA = AA;
				msh->BB = BB;
				msh->centr = (AA + BB) / 2;
				return msh;
			}

			std::vector<std::unique_ptr<MeshData>> ParsOBJall(const std::string& t_path)
			{
				ifstream infile(t_path);
				string line;
				std::vector<std::unique_ptr<MeshData>> objects;
				MeshData* msh = nullptr;// = new MeshData;
				size_t prevVertCount = 0;
				size_t prevTexCount = 0;
				size_t prevNormCount = 0;

				while (!infile.eof())
				{
					getline(infile, line);
					if (line.size() == 0 || (line.size() > 0 && line[0] == '#'))
						continue;
					istringstream iss(line);
					string symb;
					iss >> symb;

					if (symb == "mtllib")
						continue;//cout<<"Material File"<<iss;
					else if (symb == "o")
					{
						if (msh != nullptr)
						{
							prevVertCount += msh->vertices.size();
							prevTexCount += msh->texCoord.size();
							prevNormCount += msh->normals.size();
						}
						msh = new MeshData;
						objects.push_back(std::move(std::unique_ptr<MeshData>(msh)));
						iss >> msh->meshName;
					}
					else if (symb == "v")
					{
						Vec3 vc;
						iss >> vc.x >> vc.y >> vc.z;
						msh->vertices.push_back(vc);
					}
					else if (symb == "vt")
					{
						Vec2 vc;
						iss >> vc.x >> vc.y;
						msh->texCoord.push_back(vc);
					}
					else if (symb == "vn")
					{
						Vec3 vc;
						iss >> vc.x >> vc.y >> vc.z;
						msh->normals.push_back(vc);
					}
					else if (symb == "usemtl")
						continue;//cout<<"Material Used"<<iss;
					else if (symb == "s")
						continue;//cout<<"S: "<<iss;
					else if (symb == "f")
					{
						while (!iss.eof())
						{
							string face;
							iss >> face;
							std::shared_ptr<Vertex> vert(ParsFace(face, *msh, prevVertCount, prevTexCount, prevNormCount));
							msh->RealVerteces.push_back(std::move(vert));
							msh->altIndex.push_back(msh->RealVerteces.size() - 1);
						}
					}
				}

				for (size_t i = 0; i < objects.size(); ++i)
				{
					Vec3 AA, BB;
					for (auto pos : objects[i]->vertices)
					{
						if (pos.x > AA.x)
							AA.x = pos.x;

						if (pos.x < BB.x)
							BB.x = pos.x;

						if (pos.y > AA.y)
							AA.y = pos.y;

						if (pos.y < BB.y)
							BB.y = pos.y;

						if (pos.z > AA.z)
							AA.z = pos.z;

						if (pos.z < BB.z)
							BB.z = pos.z;
					}
					objects[i]->AA = AA;
					objects[i]->BB = BB;
					objects[i]->centr = (AA + BB) / 2;
				}

				return objects;
			}
		}
	}
}