#include "BaseScene.h"

using namespace Fregat;

BaseScene::BaseScene(void)
{
}


BaseScene::~BaseScene(void)
{
}

void BaseScene::Update(float t_tick)
{
	m_objectManager.Update(t_tick);
}