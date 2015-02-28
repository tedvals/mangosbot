#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "DeathKnightActions.h"

using namespace ai;

NextAction** CastBloodStrikeAction::getPrerequisites()
{
    return NextAction::merge( NextAction::array(0, new NextAction("reach melee"), NULL), CastMeleeSpellAction::getPrerequisites());
}

NextAction** CastDeathStrikeAction::getPrerequisites()
{
    return NextAction::merge( NextAction::array(0, new NextAction("reach melee"), NULL), CastMeleeSpellAction::getPrerequisites());
}

NextAction** CastPlagueStrikeAction::getPrerequisites()
{
    return NextAction::merge( NextAction::array(0, new NextAction("reach melee"), NULL), CastSpellAction::getPrerequisites());
}

NextAction** CastScourgeStrikeAction::getPrerequisites()
{
    return NextAction::merge( NextAction::array(0, new NextAction("reach melee"), NULL), CastSpellAction::getPrerequisites());
}

NextAction** CastObliterateAction::getPrerequisites()
{
    return NextAction::merge( NextAction::array(0, new NextAction("reach melee"), NULL), CastMeleeSpellAction::getPrerequisites());
}

NextAction** CastScourgeStrikeAction::getAlternatives()
{
    return NextAction::merge( NextAction::array(0, new NextAction("plague strike"), NULL), CastMeleeSpellAction::getAlternatives());
}

NextAction** CastFrostStrikeAction::getAlternatives()
{
    return NextAction::merge( NextAction::array(0, new NextAction("runic strike"), NULL), CastMeleeSpellAction::getAlternatives());
}

NextAction** CastHowlingBlastAction::getAlternatives()
{
    return NextAction::merge( NextAction::array(0, new NextAction("icy touch"), NULL), CastMeleeSpellAction::getAlternatives());
}

NextAction** CastMindFreezeAction::getAlternatives()
{
    return NextAction::merge( NextAction::array(0, new NextAction("strangulate"), NULL), CastSpellAction::getAlternatives());
}

NextAction** CastRuneStrikeAction::getAlternatives()
{
    return NextAction::merge( NextAction::array(0, new NextAction("death coil"), NULL), CastSpellAction::getAlternatives());
}

NextAction** CastVampiricBloodAction::getAlternatives()
{
    return NextAction::merge( NextAction::array(0, new NextAction("unbreakable armor"), NULL), CastBuffSpellAction::getAlternatives());
}

bool CastHysteriaOnPartyAction::isUseful()
{
    Unit* player = GetTarget();

    if (player)
    {
        switch (player->getClass())
        {
            case CLASS_DEATH_KNIGHT:
            case CLASS_WARRIOR:
            case CLASS_ROGUE:
            case CLASS_DRUID:
                return ai->HasAnyAuraOf(player, "bear form", "dire bear form", "cat form", NULL);
        }
            return false;
    }
    else return false;
}

bool CastHysteriaOnMasterAction::isUseful()
{
    Unit* player = GetTarget();

    if (player)
    {
        switch (player->getClass())
        {
            case CLASS_DEATH_KNIGHT:
            case CLASS_WARRIOR:
            case CLASS_ROGUE:
            case CLASS_DRUID:
                return ai->HasAnyAuraOf(player, "bear form", "dire bear form", "cat form", NULL);
        }
            return false;
    }
    else return false;
}
