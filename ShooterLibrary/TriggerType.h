#pragma once

namespace ShooterLibrary
{
	enum TriggerType : uint32_t
	{
		TRIGGERTYPE_NONE = 0,

		TRIGGERTYPE_PRIMARY = 1,
		TRIGGERTYPE_SECONDARY = 2,

		TRIGGERTYPE_SPECIAL = 4,

		TRIGGERTYPE_ALL = ((uint32_t)-1)
	};
}
