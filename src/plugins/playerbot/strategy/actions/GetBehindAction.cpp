#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "FollowActions.h"
#include "../../PlayerbotAIConfig.h"
#include "../values/Formations.h"

using namespace ai;

bool GetBehindAction::Execute(Event event)
{
     Unit* target = GetTarget();

    if (!target)
        return false;
    else
        return GetBehind(target);
}

bool FollowAction::isUseful()
{
     Unit* target = GetTarget();

    if (!target)
        return false;
    else
        return AI_VALUE2(bool, "behind", "current target");
}

