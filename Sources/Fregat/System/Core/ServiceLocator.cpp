#include "ServiceLocator.h"

namespace Fregat
{
	namespace System
	{
		ServiceLocator::ServiceLocator()
		{}

		void ServiceLocator::AddService(std::string t_serviceName, IService* t_service)
		{
			m_services[t_serviceName] = std::move( std::shared_ptr<IService>(t_service));
		}

		void ServiceLocator::InitServices()
		{
			for(auto itr : m_services)
			{
				itr.second->Init();
			}
		}

		void ServiceLocator::UpdateServices()
		{
			for(auto itr : m_services)
			{
				itr.second->Update();
			}
		}

		IService* ServiceLocator::GetService(std::string t_name)
		{
			auto item = m_services.find(t_name);
			if(item != m_services.end())
			{
				return item->second.get();
			}
			else
			{
				return nullptr;
			}
		}
	}
}