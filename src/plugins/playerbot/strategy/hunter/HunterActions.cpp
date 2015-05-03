#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "../actions/GenericActions.h"
#include "HunterActions.h"

using namespace ai;

bool CastSerpentStingAction::isUseful()
{
    return AI_VALUE2(uint8, "health", "current target") > 10;
}

bool CastViperStingAction::isUseful()
{
    return AI_VALUE2(uint8, "mana", "self target") < 30 && AI_VALUE2(uint8, "mana", "current target") >= 30;
}

bool CastAspectOfTheCheetahAction::isUseful()
{
    return !ai->HasAnyAuraOf(GetTarget(), "aspect of the cheetah", "aspect of the pack", NULL);
}

Value<Unit*>* CastFreezingTrapCcAction::GetTargetValue()
{
    return context->GetValue<Unit*>("cc target", "freezing trap");
}

bool CastFreezingTrapAction::Execute(Event event)
{
	return ai->CastSpell(1499 , GetTarget());
}

bool CastDisengageAction::Execute(Event event)
{
	return ai->CastSpell(781, GetTarget());
}

bool CastFrostTrapAction::Execute(Event event)
{
	return ai->CastSpell(13809, GetTarget());
}

bool CastImmolationTrapAction::Execute(Event event)
{
	return ai->CastSpell(14302, GetTarget());
}

bool CastExplosiveTrapAction::Execute(Event event)
{
	return ai->CastSpell(13813, GetTarget());
}

Value<Unit*>* CastWyvernStingCcAction::GetTargetValue()
{
    return context->GetValue<Unit*>("cc target4", getName());
}

bool CastMisdirectionOnPartyAction::isUseful()
{
    Unit* player = GetTarget();

    if (player)
    {
        switch (player->getClass())
        {
            case CLASS_DEATH_KNIGHT:
                return ai->HasAura("frost presence", player);
            case CLASS_WARRIOR:
                return ai->HasAura("defensive stance", player);
            case CLASS_PALADIN:
                return ai->HasAura("blessing of sanctuary", player);
            case CLASS_DRUID:
                return ai->HasAnyAuraOf(player, "bear form", "dire bear form",  NULL);
        }
            return false;
    }
    else return false;
}
