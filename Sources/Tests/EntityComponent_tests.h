#pragma once

#include <Fregat/System/Core/Component.h>
#include <Fregat/System/Core/Entity.h>

using namespace std;
using namespace Fregat;

namespace EntityComponent_Tests
{
	class MockComponent : public Component
	{
	public:
		float prevTick;
		bool isUpdated;
		bool &isDeleted;
		explicit MockComponent(Entity& t_entity, bool& deletedFlag):
				Component(t_entity),
				prevTick(0),
				isUpdated(false),
				isDeleted(deletedFlag)
		{}

		~MockComponent()
		{
			isDeleted = true;
		}

		void Update(float t_tick) override 
		{
			isUpdated = true;
			prevTick = t_tick;
		}

		static MockComponent* AddComponentAsOwn(Entity& t_entity, bool& deletedFlag)
		{
			auto* tmp = new MockComponent(t_entity, deletedFlag);
			t_entity.AddOwnComponent(std::unique_ptr<Component>(tmp));
			return tmp;
		}
	};

	class MockComponent2 : public Component
	{
	public:
		float prevTick;
		bool isUpdated;
		bool &isDeleted;
		explicit MockComponent2(Entity& t_entity, bool& deletedFlag):
				Component(t_entity),
				prevTick(0),
				isUpdated(false),
				isDeleted(deletedFlag)
		{}

		~MockComponent2()
		{
			isDeleted = true;
		}
		void Update(float t_tick) override 
		{
			isUpdated = true;
			prevTick = t_tick;
		}

		static MockComponent2* AddComponentAsOwn(Entity& t_entity, bool& deletedFlag)
		{
			auto* tmp = new MockComponent2(t_entity, deletedFlag);
			t_entity.AddComponent(tmp);
			return tmp;
		}
	};
	
	class TestEntity
	{
	public:
	void TestEC()
	{
		bool isDeletedfirst = false; 
		bool isDeletedSecond = false;
		std::shared_ptr<Component> secondEntity;
		if(true)
		{
		Entity tmpEntity("dddd");
		secondEntity.reset(MockComponent2::AddComponentAsOwn(tmpEntity, isDeletedSecond));
		assert(&tmpEntity == secondEntity->GetEntity());

		auto* tmpComp = MockComponent::AddComponentAsOwn(tmpEntity, isDeletedfirst);
		assert(&tmpEntity == tmpComp->GetEntity());

		auto* tmpCmp12 = tmpEntity.GetOwnComponent<MockComponent>();
		assert(tmpCmp12 == tmpComp);

		auto* tmpCmp22 = tmpEntity.GetComponent<MockComponent2>();
		assert(tmpCmp22 == secondEntity.get());
		
		assert(!tmpComp->isUpdated);
		assert(tmpComp->prevTick == 0);
		const float currentTick = 0.34f;
		tmpEntity.Update(currentTick);
		assert(tmpComp->isUpdated);
		assert(tmpComp->prevTick == currentTick);
		
		assert(!isDeletedSecond);
		assert(!isDeletedfirst);
		}
		assert(isDeletedfirst);
		assert(!isDeletedSecond);
	}
	};
}