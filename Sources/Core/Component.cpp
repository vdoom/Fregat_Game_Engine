#include "Component.h"
#include "Entity.h"

using namespace Fregat;

Component::Component(Entity& t_entity):
	m_entity(t_entity),
	m_enabled(true)
{
}


Component::~Component(void)
{
}

bool Component::IsCanBeUpdated()
{return m_enabled && m_entity.IsEnabled();}
