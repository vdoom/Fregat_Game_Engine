//---------------------------------------------
// Simple Rendere component
// Created by Volodymyr KUKSYNOK 
// 2017
//---------------------------------------------
#pragma once

//#include "../Mesh/MeshBase.h"
//#include "../Material/MaterialBase.h"
//#include "../../MathLib/Mat4.h"
#include <Fregat/System/Core/Component.h>  // <Component.h>
//#include "../../Entity.h"

//class Mat4;

namespace Fregat
{
	namespace Render
	{
		class MeshBase;
		class SimpleMaterial;
		class BaseRenderer;

		class RenderComponent : public Component
		{
		private:
			//TODO: need to refactor to shared_ptr
			SimpleMaterial* m_material;
			MeshBase* m_mesh;
		public:
			explicit RenderComponent(Entity& t_tt);// : Component(t_tt){}
			virtual ~RenderComponent();//{}
			void InitRenderer(MeshBase* t_mesh, SimpleMaterial* t_material);//{}//, Mat4* t_transform){}
			virtual void Update(float t_tick);//{}

			inline SimpleMaterial* GetMaterial() {return m_material;}
			inline MeshBase* GetMesh(){return m_mesh;}
		};
	}
}
