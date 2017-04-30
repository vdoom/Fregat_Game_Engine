#include "Transform.h"

using namespace Fregat;

Transform::~Transform(void)
{
}

Transform::Transform(Entity& t_entity) :
	m_entity(t_entity)
{
    SetDefault();
}

void Transform::SetDefault()
{
    //todo: need check for all var is init
    m_parent = 0;
    //m_object = 0;
    m_childrens = new std::vector<Transform * >();
}

void Transform::Move(const Vec3& t_pos)
{
	//m_localTransform .Translation(t_pos.x, t_pos.y, t_pos.z);
}

void Transform::MoveBy(const Vec3& t_pos)
{
	m_localTransform *= Mat4::Translation(t_pos);//(t_pos.x, t_pos.y, t_pos.z);;
}

void Transform::Scale(const Vec3& t_scl)
{
	//m_localTransform.Scale(t_scl.x, t_scl.y, t_scl.z);
    //m_localTransform.Scale(t_scl);
}

void Transform::ScaleBy(const Vec3& t_scl)
{
	m_localTransform *= Mat4::Scale(t_scl);
}

void Transform::RotateByX(float t_angle)
{
	m_localTransform *= Mat4::RotationX(t_angle);
}

void Transform::RotateByY(float t_angle)
{
	m_localTransform *= Mat4::RotationY(t_angle);
}

void Transform::RotateByZ(float t_angle)
{
	m_localTransform *= Mat4::RotationZ(t_angle);
}

void Transform::RotateToZ(float t_angle)
{
    //m_localTransform.RotateToZ(t_angle);
}

Mat4 Transform::GetLocalTransformMatrix() const
{
    return m_localTransform;
}

void Transform::ApplyTransform(const Mat4& t_mat)
{
	m_localTransform = t_mat*m_localTransform;
}

Mat4 Transform::GetGlobalTransformMatrix()// const
{
    if(!m_parent)
    {
        m_globalTransform.operator=(m_localTransform);
        //m_globalTransform = m_localTransform;
        
    }
    else
    {
        Mat4 tmpMat(m_parent->GetGlobalTransformMatrix());
        Mat4 tmpMat1(m_localTransform);
		tmpMat = tmpMat*tmpMat1;//tmpMat * tmpMat1;
        m_globalTransform = tmpMat;
        //return tmpMat;
    }
	return m_globalTransform;
}

Mat4 Transform::GetGlobalTransformMatrixAlt()// const
{
	if (!m_parent)
	{
		m_globalTransform.operator=(m_localTransform);
		//m_globalTransform = m_localTransform;
		return m_globalTransform;
	}
	else
	{
		Mat4 tmpMat(m_parent->GetGlobalTransformMatrix());
		Mat4 tmpMat1(m_localTransform);
		tmpMat = tmpMat * tmpMat1;
		m_globalTransform = tmpMat;
		return tmpMat;
	}
}


Transform * Transform::GetParent() const
{
    return m_parent;
}


void Transform::SetLocalMatrix(const Mat4& t_matrix)
{
    m_localTransform = t_matrix;
}

void Transform::SetParent(const Transform * t_parent)
{
    m_parent = const_cast<Transform*>(t_parent);
}

void Transform::UpdateGlobalTransformMatrix()
{
    //TODO: NEED REFINE!!!
}

Vec3 Transform::GetLocalPos()
{
	return GetPosFromMat4(m_localTransform);//Vec3(m_localTransform.m03, m_localTransform.m13, m_localTransform.m23);
}

Vec3 Transform::GetGlobalPos()
{
	return GetPosFromMat4(GetGlobalTransformMatrix());//Vec3(GetGlobalTransformMatrix().m03, GetGlobalTransformMatrix().m13, GetGlobalTransformMatrix().m23);
}

Vec3 Transform::GetLocalEulerAngles()
{
	//TODO: need to test
	return ToEulerMat4(m_localTransform);	
}

Vec3 Transform::GetGlobalEulerAngles()
{
	//TODO: need to test
	return ToEulerMat4(GetGlobalTransformMatrix());
}

Vec3 Transform::GetLocalScale()
{
	//TODO: move to mat operations
	//TODO: need TEST 
	return GetScaleFromMa4(m_localTransform);
	/*return Vec3(Length(Vec3(m_localTransform.m00, m_localTransform.m01, m_localTransform.m02)),
				Length(Vec3(m_localTransform.m10, m_localTransform.m11, m_localTransform.m12)),
				Length(Vec3(m_localTransform.m20, m_localTransform.m21, m_localTransform.m22)));*/
}

Vec3 Transform::GetGlobalScale()
{
	//TODO: move to mat operations
	//TODO: need to test
	return GetScaleFromMa4(GetGlobalTransformMatrix());
	//return Vec3(Length(Vec3(GetGlobalTransformMatrix().m00, GetGlobalTransformMatrix().m01, GetGlobalTransformMatrix().m02)),
	//			Length(Vec3(GetGlobalTransformMatrix().m10, GetGlobalTransformMatrix().m11, GetGlobalTransformMatrix().m12)),
	//			Length(Vec3(GetGlobalTransformMatrix().m20, GetGlobalTransformMatrix().m21, GetGlobalTransformMatrix().m22)));
}
