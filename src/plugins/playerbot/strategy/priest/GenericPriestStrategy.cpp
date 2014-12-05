#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "PriestMultipliers.h"
#include "HealPriestStrategy.h"
#include "GenericPriestStrategyActionNodeFactory.h"

using namespace ai;

GenericPriestStrategy::GenericPriestStrategy(PlayerbotAI* ai) : CombatStrategy(ai)
{
    actionNodeFactories.Add(new GenericPriestStrategyActionNodeFactory());
}

void GenericPriestStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    CombatStrategy::InitTriggers(triggers);

    triggers.push_back(new TriggerNode(
        "shadow word: pain on attacker",
        NextAction::array(0, new NextAction("shadow word: pain on attacker", 11.0f), NULL)));

       triggers.push_back(new TriggerNode(
        "enemy out of spell",
        NextAction::array(0, new NextAction("reach spell", ACTION_NORMAL + 9), NULL)));

     triggers.push_back(new TriggerNode(
        "enemy too close for spell",
        NextAction::array(0, new NextAction("flee",49.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "critical health",
        NextAction::array(0, new NextAction("power word: shield", 50.0f), new NextAction("renew", 50.0f), new NextAction("flash heal", 50.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "party member critical health",
        NextAction::array(0, new NextAction("power word: shield on party", 50.0f),  new NextAction("renew on party", 50.0f), new NextAction("flash heal on party", 50.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "low health",
        NextAction::array(0, new NextAction("power word: shield", 60.0f) , NULL)));

    triggers.push_back(new TriggerNode(
        "party member low health",
        NextAction::array(0, new NextAction("power word: shield on party", 50.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "dispel magic",
        NextAction::array(0, new NextAction("dispel magic", 41.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "dispel magic on party",
        NextAction::array(0, new NextAction("dispel magic on party", 40.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "low mana",
        NextAction::array(0, new NextAction("shadowfiend", ACTION_EMERGENCY + 5), NULL)));

    triggers.push_back(new TriggerNode(
        "cure disease",
        NextAction::array(0, new NextAction("abolish disease", 31.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "party member cure disease",
        NextAction::array(0, new NextAction("abolish disease on party", 30.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "almost dead",
        NextAction::array(0, new NextAction("desperate prayer", 50.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "critical aoe heal",
        NextAction::array(0,  new NextAction("divine hymn", ACTION_EMERGENCY + 10), NULL)));
}
