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

bool SoulstoneOnMasterTrigger::IsActive()
{
    Unit* target = GetTarget();
    return (!ai->HasAura("soulstone", target) && AI_VALUE2(uint8, "item count", getName()) > 0);
}

/*
bool SpellstoneTrigger::IsActive()
{
    Unit* target = GetTarget();
    return (!ai->HasAura("spellstone", target) &&
		!ai->HasAura("firestone", target) && AI_VALUE2(uint8, "item count", getName()) > 0);
}

bool FirestoneTrigger::IsActive()
{
    Unit* target = GetTarget();
    return (!ai->HasAura("spellstone", target) &&
		!ai->HasAura("firestone", target) && AI_VALUE2(uint8, "item count", getName()) > 0);
}
*/

bool CurseOnAttackerTrigger::IsActive()
{
    return DebuffOnAttackerTrigger::IsActive() &&
            !ai->HasOwnAura("curse of the elements", GetTarget()) &&
            !ai->HasOwnAura("curse of weakness", GetTarget()) &&
            !ai->HasOwnAura("curse of exhaustion", GetTarget()) &&
            !ai->HasOwnAura("curse of agony", GetTarget()) &&
            !ai->HasOwnAura("curse of doom", GetTarget());
}

bool CorruptionOnAttackerTrigger::IsActive()
{
    return DebuffOnAttackerTrigger::IsActive() &&
            !ai->HasOwnAura("corruption", GetTarget()) &&
            !ai->HasOwnAura("seed of corruption", GetTarget());
}

bool NoCurseTrigger::IsActive()
{
    return DebuffTrigger::IsActive() &&
            !ai->HasOwnAura("curse of the elements", GetTarget()) &&
            !ai->HasOwnAura("curse of weakness", GetTarget()) &&
            !ai->HasOwnAura("curse of exhaustion", GetTarget()) &&
            !ai->HasOwnAura("curse of agony", GetTarget()) &&
            !ai->HasOwnAura("curse of doom", GetTarget());
}

bool NoCorruptionTrigger::IsActive()
{
    return DebuffTrigger::IsActive() &&
            !ai->HasOwnAura("corruption", GetTarget()) &&
            !ai->HasOwnAura("seed of corruption", GetTarget());
}

bool DemonDeadTrigger::IsActive()
{
    Unit* pet = AI_VALUE(Unit*, "pet target");
    return pet && AI_VALUE2(bool, "dead", "pet target") && !AI_VALUE2(bool, "mounted", "self target");
}


bool DemonLowHealthTrigger::IsActive()
{
    Unit* pet = AI_VALUE(Unit*, "pet target");
    return pet && AI_VALUE2(uint8, "health", "pet target") < 20 &&
        !AI_VALUE2(bool, "dead", "pet target") && !AI_VALUE2(bool, "mounted", "self target");
}
