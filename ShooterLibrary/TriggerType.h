#pragma once

namespace ShooterLibrary
{
	enum TriggerType : uint32_t
	{
		TRIGGERTYPE_NONE		= 0,

		TRIGGERTYPE_PRIMARY		= 1 << 0,
		TRIGGERTYPE_SECONDARY	= 1 << 1,

		TRIGGERTYPE_SPECIAL		= 1 << 2,

		TRIGGERTYPE_ALL			= ((uint32_t)-1)
	};
}
