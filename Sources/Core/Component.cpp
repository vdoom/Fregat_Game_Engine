#include "Component.h"
#include "Entity.h"

using namespace Fregat;

Component::Component(Entity& t_entity):
	m_parent(t_entity),
	m_enabled(true)
{
}


Component::~Component(void)
{
}

bool Component::IsCanBeUpdated()
{return m_enabled && m_parent.IsEnabled();}
