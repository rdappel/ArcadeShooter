
#include "TriggerType.h"

const TriggerType TriggerType::NONE			= TriggerType(0);
const TriggerType TriggerType::PRIMARY		= TriggerType(1 << 0);
const TriggerType TriggerType::SECONDARY	= TriggerType(1 << 1);
const TriggerType TriggerType::SPECIAL		= TriggerType(1 << 2);
const TriggerType TriggerType::ALL			= TriggerType((unsigned short)(-1));