//---------------------------------------------
// Base interface for all assets
// Created by Volodymyr KUKSYNOK 
// 2017
//---------------------------------------------
#pragma once

#include <string>

namespace Fregat
{
	namespace System
	{
		class AssetsManager;

		class AssetBase
		{
			friend class AssetsManager;
		private:
			bool m_isLoaded;
		private:
			std::string m_name;
			std::string m_pathOnDisc;
			std::string m_typeName;
		public:
			AssetBase(){}
			virtual ~AssetBase(){}

			inline const bool IsLoaded() const
			{return m_isLoaded;}

			inline const std::string GetName() const
			{return m_name;}

			inline const std::string GetPathOnDisk() const
			{return m_pathOnDisc;}

			inline const std::string GetTypeName() const
			{return m_typeName;}
		};
	}
}