//---------------------------------------------
// AssetBin is a base class for all non system assets
// (e.g. bitmaps loaded from disk or mesh data)
// Created by Volodymyr KUKSYNOK 
// 2017
//---------------------------------------------
#pragma once

#include <string>
#include "AssetsInfo.h"

namespace Fregat
{
	namespace System
	{
		class AssetsManager;
		
		class AssetBin
		{
		private:
			friend AssetsManager;
			inline void _InternalLoad();

		protected:
			std::string m_name;
			std::string m_path;
			AssetState m_state;
			AssetsManager* m_manager;
			//virtual void Load(const std::string& t_path = std::string(""), const std::string& t_name = std::string(""))// TODO: Perhaps should be Just virtual void Load();
			//{
			//	if (t_path != "")
			//		m_path = t_path;

			//	if (t_name != "")
			//		m_name = t_name;
			//}
			
		public:
			explicit AssetBin(AssetsManager* t_manager, const std::string& t_path = std::string(""), const std::string& t_name = std::string("")) :
				m_manager(t_manager),
				m_name(t_name),
				m_path(t_path),
				m_state(AssetState::Created)
			{}
			AssetBin(AssetBin&&);
			virtual ~AssetBin() {}
			virtual bool Load() = 0;
			inline std::string GetName() { return m_name; }
			inline std::string GetPath() { return m_path; }
			inline AssetState GetState() { return m_state; }
		};

		void AssetBin::_InternalLoad()
		{
			m_state = AssetState::Processing;

			if (Load())
				m_state = AssetState::Loaded;
			else
				m_state = AssetState::BreakedByError;
		}
		
	}
}
