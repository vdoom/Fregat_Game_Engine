//---------------------------------------------
// Interface for Services
// Created by Volodymyr KUKSYNOK 
// 2017
//---------------------------------------------
#pragma once

namespace Fregat
{
	namespace System
	{
		class IService
		{
		protected:
			bool m_isInited;
		public:
			IService() :
				m_isInited(false)
			{}

			virtual ~IService()
			{}
			
			virtual void Init(){m_isInited = true;}

			inline bool IsInited() const {return m_isInited;}

			virtual void Update() = 0;
		};
	}
}