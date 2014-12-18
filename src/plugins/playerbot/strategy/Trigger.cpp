#include "../../pchdef.h"
#include "../playerbot.h"
#include "Trigger.h"
#include "Action.h"

using namespace ai;

Event Trigger::Check()
{
	if (IsActive())
	{
	    Player* master = GetMaster();
        if (!master)
            ai->TellMaster(getName());

		Event event(getName());
		return event;
	}
	Event event;
	return event;
}

Value<Unit*>* Trigger::GetTargetValue()
{
    return context->GetValue<Unit*>(GetTargetName());
}

Unit* Trigger::GetTarget()
{
    return GetTargetValue()->Get();
}
