//---------------------------------------------
// Base Component class
// Created by Volodymyr KUKSYNOK 
// 2017
//---------------------------------------------
#pragma once

namespace Fregat
{
	class Entity;
	//class UUID;

	class Component
	{
	protected:
		Entity& m_parent;
		//UUID& m_uuid;
		bool m_enabled;
	public:
		Component(Entity&);
		virtual ~Component(void);
		virtual void Update(float t_tick){}

		inline bool IsEnabled()
		{return m_enabled;}
		inline void SetEnabled(bool t_enabled)
		{m_enabled = true;} //TODO: set event of enabling
		inline Entity* GetParent() {return &m_parent;}

		bool IsCanBeUpdated();
	};
}

