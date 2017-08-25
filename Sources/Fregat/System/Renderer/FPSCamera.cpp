#include "FPSCamera.h"

namespace Fregat
{
	namespace Render
	{
		FPSCamera::FPSCamera() :
			m_changed(false),
			m_rotX(0),
			m_rotY(0)
		{
			m_cachedUp = Vec3::Up();
		}


		FPSCamera::~FPSCamera()
		{
		}

		void FPSCamera::SetPosition(const Vec3& t_vec)
		{
			m_pos = t_vec;
			m_changed = true;
		}

		Vec3 FPSCamera::GetPosition()
		{
			return m_pos;//Vec3(m_pos.x, m_pos.y, m_pos.z);//m_pos;
		}

		void FPSCamera::SetTarget(const Vec3& t_vec)
		{
			m_target = t_vec;
			m_changed = true;
		}

		Vec3 FPSCamera::GetTarget()
		{
			return m_target;
		}

		void FPSCamera::MoveForward(float t_val) //TODO: need refine
		{}

		void FPSCamera::MoveRight(float t_val) //TODO: need refine
		{
			/*m_pos += GetRight() * t_val;
			m_target += GetRight() * t_val;
			m_changed = true;*/
		}

		void FPSCamera::MoveUp(float t_val) //TODO: need refine
		{
			/*m_pos += m_cachedUp * t_val;
			m_target += m_cachedUp * t_val;
			m_changed = true;*/
		}

		void FPSCamera::MoveDirection(float t_dist, const Vec3& t_dir) //TODO: need refine
		{}

		void FPSCamera::RotateX(float t_ang) //TODO: need refine
		{
		}

		float FPSCamera::GetRotationX() const
		{
			return m_rotX;
		}

		void FPSCamera::RotateY(float t_ang) //TODO: need refine
		{
			
		}

		float FPSCamera::GetRotationY() const
		{
			return m_rotY;
		}

		//***
		Mat4 FPSCamera::GetMatrix() //TODO: need refine
		{
			if (m_changed)
			{
				m_changed = false;
				//glm::vec3 cameraDirection = glm::normalize(cameraPos - cameraTarget);
				Vec3 cameraDirection = GetDirection();//Normalize(m_pos-m_target);
				
				//Vec3 cameraRight = Normalize(Cross(Vec3::Up(), cameraDirection));
				//Vec3 cameraUp = Cross(cameraDirection, cameraRight);
				//glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
				//glm::vec3 cameraRight = glm::normalize(glm::cross(up, cameraDirection));
				//Vec3 cameraRight = Vec3::Right();//Normalize(Cross(Vec3::Up(), cameraDirection));
				//glm::vec3 cameraUp = glm::cross(cameraDirection, cameraRight);
				//Vec3 cameraUp;
				//if(m_pos.z > 0)
				//cameraUp = Cross(cameraDirection, cameraRight);//Cross(cameraDirection, cameraRight);
				//else
				//cameraUp = Cross(cameraRight,cameraDirection);
				m_cachedTransforms = LookAt(m_pos, cameraDirection, m_cachedUp);
			}
			return TransposeMat4(m_cachedTransforms);
		}

		//***
		Mat4 FPSCamera::GetProjMatrix() //TODO: need refine
		{
			//TODO: perhapse maybe maked same as GetMatrix()
			return m_projMat;
		}

		void FPSCamera::SetUpOrthogonal(float t_left, float t_right, float t_bottom,
										float t_top, float t_zNear, float t_zFar)
		{
			m_projMat = Orthographic(t_left, t_right, t_bottom,
								     t_top, t_zNear, t_zFar);
		}

		void FPSCamera::SetUpPerspective(float t_fov, float t_aspect, float t_zNear, float t_zFar)
		{
			m_projMat = Perspective(t_fov, t_aspect, t_zNear, t_zFar);
		}
	}
}