//---------------------------------------------
// Service Locator (using for accesing to core services via context instead of singletones)
// Created by Volodymyr KUKSYNOK 
// 2017
//---------------------------------------------
#pragma once

#include <map>
#include <memory>
#include "IService.h"
#include <string>

namespace Fregat
{
	namespace System
	{
		class IService; 
		
		struct cmpByStringLength 
		{
		    bool operator()(const std::string& first, const std::string& second) const
			{
				return first.compare(second)<0;
				//if(first.size() != second.size())
				//	return first.size() < second.size();
				//else
				//{
				//	for(size_t i = 0; i < first.size(); ++i)
				//	{
				//		if(first[i] >= second[i])
				//			return false;
				//	}
				//	return true;
				//}
			}
		};

		class ServiceLocator
		{
		private:
			//std::map<std::string, std::shared_ptr<IService>> m_services;
			std::map<std::string, std::shared_ptr<IService>, cmpByStringLength> m_services;
		public:
			ServiceLocator();

			void AddService(std::string t_serviceName, IService* t_service);

			void InitServices();
			void UpdateServices();

			IService* GetService(std::string t_name);
			
			template <class T>
			T* GetService()
			{
				for(auto itr : m_services)
				{
					T* val = dynamic_cast<T*>(itr.second.get());
					if(val != nullptr)
						return val;
				}

				return nullptr;
			}

			template <class T>
			void UpdateService()
			{
				for(auto itr : m_services)
				{
					T* val = static_cast<T*>(itr.second.get());
					if(val != nullptr)
						val->Update();
				}
			}

			template <class T>
			T* GetServiceT(std::string t_name)
			{
				auto item = m_services.find(t_name);
				if(item != m_services.end())
				{
					return static_cast<T*>(item->second.get());
				}
				else
				{
					return nullptr;
				}
			}
		};
	}
}