#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "WarlockTriggers.h"
#include "WarlockActions.h"

using namespace ai;

bool DemonArmorTrigger::IsActive()
{
	Unit* target = GetTarget();
	return !ai->HasAura("demon skin", target) &&
		!ai->HasAura("demon armor", target) &&
		!ai->HasAura("fel armor", target);
}

bool SpellstoneTrigger::IsActive()
{
    return BuffTrigger::IsActive() && AI_VALUE2(uint8, "item count", getName()) > 0;
}

bool WarlockNoCurseTrigger::IsActive()
{
	Unit* target = AI_VALUE(Unit*, "current target");
    return target && AI_VALUE2(uint8, "health", "current target") > 10 &&
            !ai->HasAura("curse of the elements", target) &&
            !ai->HasAura("curse of weakness", target) &&
            !ai->HasAura("curse of exhaustion", target) &&
            !ai->HasAura("curse of agony", target) &&
            !ai->HasAura("curse of doom", target);
}

bool WarlockNoCorruptionTrigger::IsActive()
{
	Unit* target = AI_VALUE(Unit*, "current target");
    return target && AI_VALUE2(uint8, "health", "current target") > 10 &&
            !ai->HasAura("corruption", target) &&
            !ai->HasAura("seed of corruption", target);
}

bool CurseOfAgonyOnAttackerTrigger::IsActive()
{
	Unit* target = AI_VALUE(Unit*, "current target");
    return target && AI_VALUE2(uint8, "health", "current target") > 10 &&
            !ai->HasAura("curse of the elements", target) &&
            !ai->HasAura("curse of weakness", target) &&
            !ai->HasAura("curse of exhaustion", target) &&
            !ai->HasAura("curse of agony", target) &&
            !ai->HasAura("curse of doom", target);
}

bool CorruptionOnAttackerTrigger::IsActive()
{
	Unit* target = AI_VALUE(Unit*, "current target");
    return target && AI_VALUE2(uint8, "health", "current target") > 10 &&
            !ai->HasAura("corruption", target) &&
            !ai->HasAura("seed of corruption", target);
}

//bool DemonDeadTrigger::IsActive()
//{
//    Unit* pet = AI_VALUE(Unit*, "pet target");
//    return pet && AI_VALUE2(bool, "dead", "pet target") && !AI_VALUE2(bool, "mounted", "self target");
//}


//bool DemonLowHealthTrigger::IsActive()
//{
//    Unit* pet = AI_VALUE(Unit*, "pet target");
//    return pet && AI_VALUE2(uint8, "health", "pet target") < 40 &&
//        !AI_VALUE2(bool, "dead", "pet target") && !AI_VALUE2(bool, "mounted", "self target");
//}
