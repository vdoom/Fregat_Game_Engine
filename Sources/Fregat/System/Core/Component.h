//---------------------------------------------
// Base Component class
// Created by Volodymyr KUKSYNOK 
// 2017
//---------------------------------------------
#include <string>

#pragma once

namespace Fregat
{
	class Entity;
	//class UUID;

	class Component
	{
	protected:
		Entity& m_entity;
		//UUID& m_uuid;
		bool m_enabled;
		//std::string m_typeName;
	public:
		explicit Component(Entity&);
		virtual ~Component(void);
		virtual void Update(float t_tick){}

		inline bool IsEnabled()
		{return m_enabled;}
		inline void SetEnabled(bool t_enabled)
		{m_enabled = true;} //TODO: set event of enabling
		inline Entity* GetEntity() {return &m_entity;}
		//inline std::string GetTypeName() const {return m_typeName;}
		bool IsCanBeUpdated();
	};
}

