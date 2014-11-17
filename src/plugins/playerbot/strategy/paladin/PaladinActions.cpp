#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "PaladinActions.h"

using namespace ai;

bool CastBlessingOfWisdomOnPartyAction::isUseful()
{
    Unit* player = GetTarget();
    if (player)
    {
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
    return false;
}

bool CastBlessingOfMightOnPartyAction::isUseful()
{
    Unit* player = GetTarget();
    if (player)
    {
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
    else return false;
}

bool CastBlessingOfSanctuaryOnPartyAction::isUseful()
{
    Unit* player = GetTarget();
    if (player)
     return !ai->HasAura("blessing of kings", player);
    else return false;
}

bool  CastSealOfCommandAction::isUseful()
{
     return (AI_VALUE(uint8, "attacker count") > 2);
}

bool  CastSealOfWisdomAction::isUseful()
{
      Player* player = ai->GetBot();
      if (player)
        return ai->IsHeal(player);
      else return false;
}

bool  CastSealOfVengeanceAction::isUseful()
{
     return (AI_VALUE(uint8, "attacker count") == 1);
}


bool CastInstantFlashOfLightAction::isPossible()
{
    return ai->HasAura("art of war",GetTarget());
}

bool CastInstantFlashOfLightAction::Execute(Event event)
{
    return ai->CastSpell("flash of light", GetTarget());
}

bool CastInstantFlashOfLightOnPartyAction::isPossible()
{
    Player* player = ai->GetBot();
    return player->HasAura(53488);
}

bool CastInstantFlashOfLightOnPartyAction::Execute(Event event)
{
    return ai->CastSpell("flash of light", GetTarget());
}
