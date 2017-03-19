#include "Entity.h"
#include "Component.h"

using namespace Fregat;

Entity::Entity(void):
	m_transform(*this)
{
}

Entity::~Entity(void)
{
}

void Entity::Update(float t_tick)
{
	for(auto custom : m_componentsUpdatableByEntity)
		custom->Update(t_tick);
}

void Entity::AddComponent(Component* t_component)
{
	m_components.push_back(t_component);
}
