#pragma once
#include <vector>
#include "Math/MatOperations.h"

using namespace Fregat::Math;

namespace Fregat
{
	class Entity;

	class Transform
	{
	private:
		std::vector<Transform*> *m_childrens;
	    Transform *m_parent;
	    Mat4 m_localTransform;
	    Mat4 m_globalTransform; //Cached value //TODO: steel need refine!!!
	    Entity& m_entity; 
	public:
		Transform(Entity&);
		~Transform(void);
	
		void UpdateGlobalTransformMatrix();
	    //ctTransform(ctObject * t_entity);
	
	    void SetDefault();
	
	    Transform * GetChild(int);
	    //Transform * GetChild(QUuid);
	    //Transform * GetChild(QString);
	    Transform * GetParent() const;
	    void AddChild(Transform *);
	    void DeleteChild(int);
	    //void DeleteChild(QUuid);
	    //void DeleteChild(QString);
	
	    Mat4 GetLocalTransformMatrix() const;
	    Mat4 GetGlobalTransformMatrix();// const;
	
	    void SetLocalMatrix(const Mat4 & t_matrix);
	    //void SetLocalMatrix(const QMatrix4x4 & t_matrix);
	
	    void Move(const Vec3&);
	    void MoveBy(const Vec3&);
	    void Scale(const Vec3&);
		void ScaleBy(const Vec3&);
	    void RotateByX(float);
	    void RotateByY(float);
	    void RotateByZ(float);
	    void RotateToZ(float);
		void ApplyTransform(const Mat4&);
	    //ctObject * GetGameObject() const;
	
	    //bool GetParentsVisibility() const;
	
	    //bool IsVisible() const;
	    //void SetVisible(bool t_visible);
	
	    void SetParent(const Transform * t_transform);
	
	    Vec3 GetLocalPos();
	    Vec3 GetGlobalPos();
		Vec3 GetLocalEulerAngles();
		Vec3 GetGlobalEulerAngles();
		Vec3 GetLocalScale();
		Vec3 GetGlobalScale();
	};
}
