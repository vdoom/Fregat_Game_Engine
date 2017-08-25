//---------------------------------------------
// FPS variant Camera for Rendering System
// Camera has a vector params from witch 
// generate transformation matrix
// Created by Volodymyr KUKSYNOK 
// 2017
//---------------------------------------------

#pragma once

//#include "MathLib/MatOperations.h"
#include "../../MathLib/MatOperations.h"
#include "../../MathLib/Vec3.h"
#include <Fregat/System/Core/Component.h>
#include "ICamera.h"

namespace Fregat
{
	using namespace Math;
	class Transform;
	namespace Render
	{
		class FPSCamera : public ICamera
		{
		private:
			Vec3 m_pos;
			Vec3 m_target;
			//Vec3 m_cachedViewVec;
			Vec3 m_cachedUp;
			//Vec3 m_cachedRight;

			Mat4 m_cachedTransforms;
			Mat4 m_projMat;

			bool m_changed;

			float m_rotX;
			float m_rotY;
			//float m_rotZ;
		public:
			FPSCamera();
			~FPSCamera(); //TODO: need refine

			void SetUpOrthogonal(float t_left, float t_right, float t_bottom,
								 float t_top, float t_zNear, float t_zFar);
			void SetUpPerspective(float t_fov, float t_aspect, float t_zNear, float t_zFar);

			void SetPosition(const Vec3& t_vec);
			virtual Vec3 GetPosition() override;
			void SetTarget(const Vec3& t_vec);
			Vec3 GetTarget();
			void MoveForward(float t_val); //TODO: need refine
			void MoveRight(float t_val); //TODO: need refine
			void MoveUp(float t_val); //TODO: need refine
			void MoveDirection(float t_dist, const Vec3& t_dir); //TODO: need refine

			void RotateX(float t_ang); //TODO: need refine
			float GetRotationX() const;

			void RotateY(float t_ang); //TODO: need refine
			float GetRotationY() const;

			virtual Mat4 GetMatrix() override; //TODO: need refine
			virtual Mat4 GetProjMatrix() override; //TODO: need refine

			inline Vec3 GetUp() const {return m_cachedUp;}
			inline void SetUp(const Vec3& t_vec) {m_cachedUp = t_vec; m_changed = true;}

			inline Vec3 GetDirection() const {return Normalize(m_target-m_pos);}
			inline Vec3 GetRight() const {return Cross(GetDirection(), GetUp());}
		};
	}
}

