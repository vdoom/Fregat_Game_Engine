//---------------------------------------------
// AssetSys is a base class for all engine system assets
// (e.g. Texture2D, StaticMesh and other processing by engine)
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
		class AssetBin;
		
		class AssetSys
		{
		private:
			inline void _InternalCreate(AssetBin* t_assetBinData);
		protected:
			std::string m_name;
			std::string m_path;
			AssetState m_state;
			AssetsManager* m_manager;
		public:
			explicit AssetSys(AssetsManager* t_manager):
				m_manager(t_manager),
				m_state(AssetState::Created)
			{}

			virtual ~AssetSys() {}

			virtual bool CreateAsset(AssetBin* t_assetBinData) = 0;

			inline std::string GetName() { return m_name; }
			inline std::string GetPath() { return m_path; }
			inline AssetState GetState() { return m_state; }
		};

		void AssetSys::_InternalCreate(AssetBin* t_assetBinData)
		{
			m_state = AssetState::Processing;
			
			if (CreateAsset(t_assetBinData))
				m_state = AssetState::Loaded;
			else
				m_state = AssetState::BreakedByError;
		}
	}
}