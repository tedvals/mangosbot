#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "PaladinMultipliers.h"
#include "HealPaladinStrategy.h"

using namespace ai;

class HealPaladinStrategyActionNodeFactory : public NamedObjectFactory<ActionNode>
{
public:
    HealPaladinStrategyActionNodeFactory()
    {
        creators["seal of wisdom"] = &seal_of_wisdom;
        creators["seal of light"] = &seal_of_light;
    }

private:
    static ActionNode* seal_of_wisdom(PlayerbotAI* ai)
    {
        return new ActionNode ("seal of wisdom",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("seal of light"), NULL),
            /*C*/ NULL);
    }
     static ActionNode* seal_of_light(PlayerbotAI* ai)
    {
        return new ActionNode ("seal of light",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("seal of righteousness"), NULL),
            /*C*/ NULL);
    }
};

HealPaladinStrategy::HealPaladinStrategy(PlayerbotAI* ai) : GenericPaladinStrategy(ai)
{
    actionNodeFactories.Add(new HealPaladinStrategyActionNodeFactory());
}

NextAction** HealPaladinStrategy::getDefaultActions()
{
    return NextAction::array(0, new NextAction("judgement of wisdom", ACTION_NORMAL + 1), NULL);
}

void HealPaladinStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    GenericPaladinStrategy::InitTriggers(triggers);

    triggers.push_back(new TriggerNode(
        "beacon of light on master",
        NextAction::array(0, new NextAction("beacon of light on master", 11.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "party member medium health",
        NextAction::array(0, new NextAction("holy light on party", ACTION_CRITICAL_HEAL + 1), NULL)));

    triggers.push_back(new TriggerNode(
        "low health",
        NextAction::array(0, new NextAction("flash of light", ACTION_MEDIUM_HEAL + 2), NULL)));

    triggers.push_back(new TriggerNode(
        "party member low health",
        NextAction::array(0, new NextAction("flash of light on party", ACTION_MEDIUM_HEAL + 1), NULL)));

    triggers.push_back(new TriggerNode(
		"party member critical health",
		NextAction::array(0, new NextAction("holy shock on party", ACTION_EMERGENCY), NULL)));

    triggers.push_back(new TriggerNode(
        "critical health",
        NextAction::array(0, new NextAction("divine shield", ACTION_CRITICAL_HEAL + 2), new NextAction("holy light", ACTION_CRITICAL_HEAL + 2), NULL)));

    triggers.push_back(new TriggerNode(
        "judgement of wisdom",
        NextAction::array(0, new NextAction("judgement of wisdom", ACTION_NORMAL + 2), NULL)));

    triggers.push_back(new TriggerNode(
        "blessing",
        NextAction::array(0, new NextAction("blessing of wisdom", ACTION_HIGH + 8), NULL)));

     triggers.push_back(new TriggerNode(
        "not facing target",
        NextAction::array(0, new NextAction("set facing", ACTION_NORMAL + 7), NULL)));

     triggers.push_back(new TriggerNode(
        "low mana",
        NextAction::array(0, new NextAction("divine illumination", ACTION_HIGH + 5), NULL)));
}
