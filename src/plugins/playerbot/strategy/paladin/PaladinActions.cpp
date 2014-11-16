#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "PaladinActions.h"

using namespace ai;

bool CastBlessingOfWisdomOnPartyAction::isUseful()
{
    Unit* player = GetTarget();

    switch (player->getClass())
    {
        case CLASS_DEATH_KNIGHT:
        case CLASS_WARRIOR:
        case CLASS_ROGUE:
            return false;
        case CLASS_DRUID:
            return !ai->HasAnyAuraOf(player, "bear form", "dire bear form", "cat form", NULL);
    }
    return true;
}

bool CastBlessingOfMightOnPartyAction::isUseful()
{
    Unit* player = GetTarget();

    if (ai->HasAura("blessing of might", player))
        return false;

    switch (player->getClass())
    {
        case CLASS_DEATH_KNIGHT:
        case CLASS_WARRIOR:
        case CLASS_ROGUE:
            return true;
        case CLASS_DRUID:
            return ai->HasAnyAuraOf(player, "bear form", "dire bear form", "cat form", NULL);
    }
    return true;
}

bool CastBlessingOfSanctuaryOnPartyAction::isUseful()
{
    Unit* player = GetTarget();
     return !ai->HasAura("blessing of kings", player);
}

bool  CastSealOfCommandAction::isUseful()
{
     return (AI_VALUE(uint8, "attacker count") > 2);
}

bool  CastSealOfWisdomAction::isUseful()
{
      return ai->IsHeal(ai->GetBot());
}

bool  CastSealOfVengeanceAction::isUseful()
{
     return (AI_VALUE(uint8, "attacker count") == 1);
}


bool CastInstantFlashOfLightAction::isPossible()
{
    Unit* player = ai->GetUnitBot();
    return ai->HasAura("art of war",player);
}

bool CastInstantFlashOfLightAction::Execute(Event event)
{
    return ai->CastSpell("flash of light", GetTarget());
}

bool CastInstantFlashOfLightOnPartyAction::isPossible()
{
    Unit* player = ai->GetUnitBot();
    return ai->HasAura("art of war",player);
}

bool CastInstantFlashOfLightOnPartyAction::Execute(Event event)
{
    Unit* player = ai->GetUnitBot();
    return ai->CastSpell("flash of light", player);
}
