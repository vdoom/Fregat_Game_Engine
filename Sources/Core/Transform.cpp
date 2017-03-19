#include "Transform.h"

using namespace Fregat;
//Transform::Transform(void)
//{
//}


Transform::~Transform(void)
{
}

Transform::Transform(Entity& t_entity) :
	m_entity(t_entity)
{
    SetDefault();
}

//Transform::Transform(ctObject * t_entity)
//{
//    SetDefault();
//    m_object = t_entity;
//}

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
    //m_localTransform.RotateX(t_angle);
}

void Transform::RotateByY(float t_angle)
{
	m_localTransform *= Mat4::RotationY(t_angle);
    //m_localTransform.RotateY(t_angle);
}

void Transform::RotateByZ(float t_angle)
{
	m_localTransform *= Mat4::RotationZ(t_angle);
    //m_localTransform.RotateZ(t_angle);
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
	m_localTransform = m_localTransform * t_mat;
}

Mat4 Transform::GetGlobalTransformMatrix()// const
{
    if(!m_parent)
    {
        m_globalTransform.operator=(m_localTransform);
        //m_globalTransform = m_localTransform;
        return m_globalTransform;
    }
    else
    {
//        ctMatrix4 tmpMat(m_parent->GetGlobalTransformMatrix());
//        //tmpMat
//        //QMatrix4x4 tmp1 = m_parent->GetGlobalTransformMatrix().GetMatrix();
//        //QMatrix4x4 tmp2 = m_localTransform.GetMatrix();
//        //tmp1 *= tmp2;
//        //tmpMat.SetMatrix(tmp1);
//        ctMatrix4 tmpMat1(m_localTransform);
//        //tmpMat1.Multiply(tmpMat);
//        m_globalTransform = tmpMat;//tmpMat1; //= tmpMat;
//        return m_globalTransform;
        Mat4 tmpMat(m_parent->GetGlobalTransformMatrix());
        Mat4 tmpMat1(m_localTransform);
        tmpMat = tmpMat * tmpMat1;
        m_globalTransform = tmpMat;
        return tmpMat;
    }
}

//ctMatrix4 operator * (ctMatrix4 & t_mat1, ctMatrix4 & t_mat2)
//{
//    ctMatrix4 tmp(t_mat1);
//    tmp.Multiply(t_mat2);
//    return tmp;
//}

//ctObject * Transform::GetGameObject() const
//{
//    return m_object;
//}
//TODO: NEED TEST !!!
//bool Transform::GetParentsVisibility() const
//{
//    if(!m_parent)
//    {
//        return m_object->IsVisible();
//    }
//    else
//    {
//        ctTransform * parent = m_parent;
//        while(parent)
//        {
//            parent = parent->GetParent();
//            if(!parent->GetGameObject()->IsVisible())
//            {return false;}
//            if(!parent->GetParent()) return parent->GetGameObject()->IsVisible();
//        }
//        return parent->GetGameObject()->IsVisible();
//    }
//}

Transform * Transform::GetParent() const
{
    return m_parent;
}

//bool Transform::IsVisible() const
//{
//    if(!m_object) return false;
//    return m_object->IsVisible();
//}
//
//void Transform::SetVisible(bool t_visible)
//{
//    if(!m_object) return;
//    if(t_visible) m_object->Show();
//    else m_object->Hide();
//}

void Transform::SetLocalMatrix(const Mat4& t_matrix)
{
    m_localTransform = t_matrix;
}

void Transform::SetParent(const Transform * t_parent)
{
    m_parent = const_cast<Transform*>(t_parent);

    //ctMatrix4 tmp(m_parent->GetGlobalTransformMatrix().GetMatrix()); //= m_parent->GetGlobalTransformMatrix().Inverted();
    //ctMatrix4 tmp2(m_localTransform.GetMatrix());
    //tmp = tmp.Inverted();
    //tmp2.Multiply(tmp);
    //m_localTransform.Multiply(tmp2);
    //tmp2 = tmp2.Inverted();
    //tmp.Multiply(tmp2);
    //m_localTransform.Multiply(tmp);
}

void Transform::UpdateGlobalTransformMatrix()
{
    //TODO: NEED REFINE!!!
}

Vec3 Transform::GetLocalPos()
{
	//TODO: move to mat operations
	//TODO: need to test
    //QVector4D tmp = GetLocalTransformMatrix().GetMatrix().column(3);
    //return QVector3D(tmp.x(), tmp.y(), tmp.z());
	return GetPosFromMat4(m_localTransform);//Vec3(m_localTransform.m03, m_localTransform.m13, m_localTransform.m23);
}

Vec3 Transform::GetGlobalPos()
{
	//TODO: move to mat operations
	//TODO: need to test
    //QVector4D tmp = GetGlobalTransformMatrix().GetMatrix().column(3);
    //return QVector3D(tmp.x(), tmp.y(), tmp.z());
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
