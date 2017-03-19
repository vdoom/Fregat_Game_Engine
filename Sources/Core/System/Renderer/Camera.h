//---------------------------------------------
// Simple Camera for Rendering System
// Created by Volodymyr KUKSYNOK 
// 2017
//---------------------------------------------
#pragma once
//#include "MathLib/MatOperations.h"
#include "../../Math/MatOperations.h"
#include "../../Math/Vec3.h"
#include "../../Component.h"

namespace Fregat
{
	class Transform;
	namespace Render
	{
		class Camera : public Component
		{
		private:
			float m_left, m_right, m_bottom, m_top, t_zNear, t_zFar;
			float m_fov, m_aspect;
			Math::Vec3 m_position, m_center, m_up;
			Math::Mat4 m_projection;
			Math::Mat4 m_cachedProjMat;
			//void UpdateCachedMat();
		public:
			void UpdateCachedMat();
			//Math::Mat4 m_transform;
			Camera(Entity&);
			~Camera(void);
		
			//void SetUp(const Math::Mat4&);
			void SetUpOrthogonal(float t_left, float t_right, float t_bottom, 
									   float t_top, float t_zNear, float t_zFar);
			void SetUpPerspective(float t_fov, float t_aspect, float t_zNear, float t_zFar);
			void LookAt(const Math::Vec3 &position, const Math::Vec3 &center, const Math::Vec3 &up);

			inline Math::Mat4& GetProjMatrix() {return m_cachedProjMat;}
			inline const Math::Mat4& GetProjMatrix() const {return m_cachedProjMat;}
		};
	}
}
