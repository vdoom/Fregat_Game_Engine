#include <string>
#include "AssetBin.h"

namespace Fregat
{
	namespace System
	{
		AssetBin::AssetBin(AssetBin&& t_other)
		{
			m_name = std::move(t_other.m_name);
			m_path = std::move(t_other.m_path);
			m_state = t_other.m_state;
			m_manager = t_other.m_manager;
			t_other.m_manager = nullptr;
		}
	}
}
