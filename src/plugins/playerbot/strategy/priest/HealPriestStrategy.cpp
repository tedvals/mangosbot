#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "PriestMultipliers.h"
#include "HealPriestStrategy.h"

using namespace ai;

NextAction** HealPriestStrategy::getDefaultActions()
{
    return NextAction::array(0, new NextAction("shoot", 10.0f), NULL);
}

void HealPriestStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    GenericPriestStrategy::InitTriggers(triggers);

    triggers.push_back(new TriggerNode(
        "enemy out of spell",
        NextAction::array(0, new NextAction("reach spell", ACTION_NORMAL + 9), NULL)));

	triggers.push_back(new TriggerNode(
		"medium aoe heal",
		NextAction::array(0, new NextAction("inner focus", 30.0f), new NextAction("prayer of healing", 27.0f), NULL)));

    triggers.push_back(new TriggerNode(
		"critical aoe heal",
		NextAction::array(0, new NextAction("holy nova", ACTION_LIGHT_HEAL), NULL)));

    triggers.push_back(new TriggerNode(
        "almost full health",
        NextAction::array(0, new NextAction("prayer of mending", ACTION_LIGHT_HEAL + 1), new NextAction("power word: shield", ACTION_LIGHT_HEAL), NULL)));

    triggers.push_back(new TriggerNode(
        "party member almost full health",
        NextAction::array(0, new NextAction("prayer of mending on party", ACTION_LIGHT_HEAL + 8), new NextAction("power word: shield on party", ACTION_LIGHT_HEAL + 7), NULL)));

    triggers.push_back(new TriggerNode(
        "party member high health",
        NextAction::array(0, new NextAction("renew on party", ACTION_LIGHT_HEAL + 1), NULL)));

    triggers.push_back(new TriggerNode(
        "medium health",
        NextAction::array(0, new NextAction("penance", ACTION_MEDIUM_HEAL + 2), NULL)));

    triggers.push_back(new TriggerNode(
        "party member medium health",
        NextAction::array(0, new NextAction("penance on party", ACTION_LIGHT_HEAL + 1), NULL)));

    triggers.push_back(new TriggerNode(
        "low health",
        NextAction::array(0, new NextAction("renew", 60.0f), new NextAction("greater heal", 60.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "party member low health",
        NextAction::array(0, new NextAction("power word: shield on party", ACTION_CRITICAL_HEAL + 2), new NextAction("greater heal on party", ACTION_CRITICAL_HEAL + 1), NULL)));

    triggers.push_back(new TriggerNode(
        "have aggro",
        NextAction::array(0, new NextAction("fade", 50.0f), new NextAction("psychic scream", 49.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "enemy too close for spell",
        NextAction::array(0, new NextAction("flee", 49.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "almost dead",
        NextAction::array(0, new NextAction("pain suppression", ACTION_EMERGENCY + 8), NULL)));

    triggers.push_back(new TriggerNode(
        "party member almost dead",
        NextAction::array(0, new NextAction("pain suppression on party", ACTION_EMERGENCY + 7), NULL)));
}
