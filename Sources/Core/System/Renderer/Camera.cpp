#include "Camera.h"
#include "../../Entity.h"

namespace Fregat
{
	namespace Render
	{
		Camera::Camera(Entity& t_entity) : Component(t_entity)
		{
		}

		Camera::~Camera(void)
		{
		}

		void Camera::SetUpOrthogonal(float t_left, float t_right, float t_bottom, 
						   float t_top, float t_zNear, float t_zFar)
		{
			m_projection = Math::Orthographic(t_left, t_right, t_bottom,
												t_top, t_zNear, t_zFar);
			UpdateCachedMat();
		}

		void Camera::SetUpPerspective(float t_fov, float t_aspect, float t_zNear, float t_zFar)
		{
			m_projection = Math::Perspective(t_fov, t_aspect, t_zNear, t_zFar);
			UpdateCachedMat();
		}

		void Camera::LookAt(const Math::Vec3 &t_position, const Math::Vec3 &t_center, const Math::Vec3 &t_up)
		{
			m_position = t_position;
			m_center = t_center;
			m_up = t_up;
			
			m_parent.GetTransform().SetLocalMatrix(Math::LookAt(t_position, t_center, t_up));
			UpdateCachedMat();
		}

		void Camera::UpdateCachedMat()
		{
			m_cachedProjMat = m_projection * m_parent.GetTransform().GetGlobalTransformMatrix();//m_transform * m_projection;//m_projection * m_transform;
		}
	}
}