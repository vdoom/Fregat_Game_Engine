#pragma once

#include <vector> //TODO: Investigate performance difference between vector and unordered_set in this case
#include <memory>
#include <string>

#include "Transform.h"

namespace Fregat
{
	class Component;

	class Entity
	{
	protected:
		std::vector<Component*> m_components; //TODO: replace it with unique_ptr
		std::vector<Component*> m_componentsUpdatableByEntity;
		Transform m_transform;
		std::string m_name;
		bool m_enabled;
	public:
		Entity(void);
		virtual ~Entity(void);
		
		inline Transform& GetTransform() {return m_transform ;} //TODO: need test
		inline const Transform& GetTransform() const {return m_transform ;}
		
		inline void SetName(const std::string& t_newName)
		{m_name = t_newName;}
		inline std::string GetName()
		{return m_name;}
		
		inline bool IsEnabled()
		{return m_enabled;}
		inline void SetEnabled(bool t_enabled)
		{m_enabled = true;} //TODO: set event of enabling

		virtual void Update(float t_tick);

		void AddComponent(Component*);
		/*virtual void Start();
		virtual void Awake();*/
	};
}

