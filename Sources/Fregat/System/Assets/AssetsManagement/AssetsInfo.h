#pragma once

namespace Fregat
{
	namespace System
	{
		enum class AssetState
		{
			None,
			Created,
			Processing,
			BreakedByError,
			Loaded,
			Removed
		};
	}
}