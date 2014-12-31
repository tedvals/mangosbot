#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "DruidActions.h"

using namespace ai;

bool CastCasterFormAction::Execute(Event event)
{
    ai->RemoveShapeshift();
    return true;
}

NextAction** CastAbolishPoisonAction::getAlternatives()
{
    return NextAction::merge( NextAction::array(0, new NextAction("cure poison"), NULL), CastSpellAction::getPrerequisites());
}

NextAction** CastBoostAction::getAlternatives()
{
    return NextAction::merge( NextAction::array(0, new NextAction("force of nature"), NULL), CastSpellAction::getPrerequisites());
}

NextAction** CastAbolishPoisonOnPartyAction::getAlternatives()
{
    return NextAction::merge( NextAction::array(0, new NextAction("cure poison on party"), NULL), CastSpellAction::getPrerequisites());
}

Value<Unit*>* CastEntanglingRootsCcAction::GetTargetValue()
{
    return context->GetValue<Unit*>("cc target2", "entangling roots");
}

bool CastEntanglingRootsCcAction::Execute(Event event)
{
    return ai->CastSpell("entangling roots", GetTarget());
}

Value<Unit*>* CastHibernateCcAction::GetTargetValue()
{
    return context->GetValue<Unit*>("cc target3", "hibernate");
}

bool CastHibernateCcAction::Execute(Event event)
{
    return ai->CastSpell("hibernate", GetTarget());
}

bool CastThornsOnPartyAction::isUseful()
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
                return ai->HasAnyAuraOf(player, "blessing of sanctuary", "devotion aura", NULL);
            case CLASS_DRUID:
                return ai->HasAnyAuraOf(player, "bear form", "dire bear form", "moonkin form", NULL);
        }
            return false;
    }
    else return false;
}

