#include "ObjectManager.h"

using namespace Fregat;

ObjectManager::ObjectManager(void)
{
}


ObjectManager::~ObjectManager(void)
{
}

void ObjectManager::Update(float t_tick)
{
	//TODO: need sort this all for enabling components and objects and than iteration to disabled once
	//Update Inputs
	for(auto component : m_inputComponents)
	{
		if(component->IsCanBeUpdated())
			component->Update(t_tick);
	}

	//Update Objects states and custom actions
	for(auto obj : m_objects)
	{
		if(obj->IsEnabled())
			obj->Update(t_tick);
	}

	//Update All movers and twinners
	for(auto twn : m_movementComponents)
	{
		if(twn->IsCanBeUpdated())
			twn->Update(t_tick);
	}

	//Update Physicks
	for(auto phz : m_physicksComponents) //TODO: Perhaps need flag to disable it or completely remove from here.
	{
		if(phz->IsCanBeUpdated())
			phz->Update(t_tick);
	}

	//Render updated Objects
	for(auto rndr : m_renderers) //TODO: need sorting for Z and frustrum test ALSO need more rendering leyers
	{
		if(rndr->IsCanBeUpdated())
			rndr->Update(t_tick);
	}
}