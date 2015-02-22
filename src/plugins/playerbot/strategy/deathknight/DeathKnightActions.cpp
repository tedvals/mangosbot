#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "WarriorActions.h"

using namespace ai;

NextAction** CastRendAction::getPrerequisites()
{
    return NextAction::merge( NextAction::array(0, new NextAction("reach melee"), NULL), CastDebuffSpellAction::getPrerequisites());
}

NextAction** CastRendOnAttackerAction::getPrerequisites()
{
    return NextAction::merge( NextAction::array(0, new NextAction("reach melee"), NULL), CastDebuffSpellOnAttackerAction::getPrerequisites());
}

NextAction** CastDisarmAction::getPrerequisites()
{
    return NextAction::merge( NextAction::array(0, new NextAction("reach melee"), new NextAction("defensive stance"), NULL), CastDebuffSpellAction::getPrerequisites());
}

NextAction** CastSunderArmorAction::getPrerequisites()
{
    return NextAction::merge( NextAction::array(0, new NextAction("reach melee"), NULL), CastDebuffSpellAction::getPrerequisites());
}

NextAction** CastRevengeAction::getPrerequisites()
{
    return NextAction::merge( NextAction::array(0, new NextAction("defensive stance"), NULL), CastMeleeSpellAction::getPrerequisites());
}

NextAction** CastBloodthirstAction::getAlternatives()
{
    return NextAction::merge( NextAction::array(0, new NextAction("heroic strike"), NULL), CastMeleeSpellAction::getAlternatives());
}

NextAction** CastMortalStrikeAction::getAlternatives()
{
    return NextAction::merge( NextAction::array(0, new NextAction("heroic strike"), NULL), CastMeleeSpellAction::getAlternatives());
}

NextAction** CastBattleShoutAction::getAlternatives()
{
    return NextAction::merge( NextAction::array(0, new NextAction("commanding shout"), NULL), CastBuffSpellAction::getAlternatives());
}

NextAction** CastCommandingShoutAction::getAlternatives()
{
    return NextAction::merge( NextAction::array(0, new NextAction("battle shout"), NULL), CastBuffSpellAction::getAlternatives());
}
