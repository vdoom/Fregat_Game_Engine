#include "Entity.h"
#include "Component.h"

using namespace Fregat;

//Entity::Entity(void):
//	m_transform(*this),
//	m_enabled(true)
//{
//}
//
//Entity::Entity(std::string t_name):
//	m_transform(*this),
//	m_enabled(true),
//	m_name(t_name)
//{
//}
//
//Entity::~Entity(void)
//{
//}

void Entity::Update(float t_tick)
{
	if(m_enabled)
	{
		for(size_t i = 0; i < m_componentsUpdatableByEntity.size(); ++i)
		{
			m_componentsUpdatableByEntity[i]->Update(t_tick);
		}
	}
}

void Entity::AddOwnComponent(std::unique_ptr<Component>& t_component)
{
	m_componentsUpdatableByEntity.push_back(std::move(t_component));
}

void Entity::AddComponent(Component* t_component)
{
	m_components.push_back(t_component);
}
