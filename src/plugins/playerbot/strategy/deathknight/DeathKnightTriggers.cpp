#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "DeathKnightTriggers.h"
#include "DeathKnightActions.h"

using namespace ai;

bool GhoulPetDeadTrigger::IsActive()
{
    Unit* pet = AI_VALUE(Unit*, "pet target");
    return pet && AI_VALUE2(bool, "dead", "pet target") && !AI_VALUE2(bool, "mounted", "self target");
}

