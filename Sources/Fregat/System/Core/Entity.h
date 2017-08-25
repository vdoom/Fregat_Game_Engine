//---------------------------------------------
// Base Entity class
// Can be used as agregator of connected 
// between each other components
// Created by Volodymyr KUKSYNOK 
// 2017
//---------------------------------------------
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
		std::vector<std::unique_ptr<Component>> m_componentsUpdatableByEntity;
		Transform m_transform;
		std::string m_name;
		bool m_enabled;
	public:
		Entity(void):
	m_transform(*this),
	m_enabled(true)
{
}

Entity(std::string t_name):
	m_transform(*this),
	m_enabled(true),
	m_name(t_name)
{
}

virtual ~Entity(void)
{
}
		/*Entity(void);
		explicit Entity(std::string t_name);
		virtual ~Entity(void);*/
		
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
		void AddOwnComponent(std::unique_ptr<Component>&);

		template <class T>
		T* GetComponent()
		{
			for(auto comp : m_components)
			{
				T* result = dynamic_cast<T*>(comp);
				if(result != nullptr)
				{
					return result;
				}
			}
			return nullptr;
		}

		template <class T>
		T* GetOwnComponent()
		{
			for(size_t i = 0; i < m_componentsUpdatableByEntity.size(); ++i)//for(auto comp : m_components)
			{
				T* result = static_cast<T*>(m_componentsUpdatableByEntity[i].get());
				if(result != nullptr)
				{
					return result;
				}
			}
			return nullptr;
		}
		/*virtual void Start();
		virtual void Awake();*/
	};
}

