#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "DeathKnightMultipliers.h"
#include "GenericDeathKnightNonCombatStrategy.h"

using namespace ai;

void GenericDeathKnightNonCombatStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    NonCombatStrategy::InitTriggers(triggers);

    triggers.push_back(new TriggerNode(
        "horn of winter",
        NextAction::array(0, new NextAction("horn of winter", 11.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "bone shield",
        NextAction::array(0, new NextAction("bone shield", 21.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "almost dead",
        NextAction::array(0, new NextAction("bandage", 22.0f), NULL)));

}
