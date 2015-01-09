#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "PriestMultipliers.h"
#include "HolyPriestStrategy.h"

namespace ai
{
    class HolyPriestStrategyActionNodeFactory : public NamedObjectFactory<ActionNode>
    {
    public:
        HolyPriestStrategyActionNodeFactory()
        {
            creators["smite"] = &smite;
            creators["circle of healing"] = &circle_of_healing;
        }
    private:
        static ActionNode* smite(PlayerbotAI* ai)
        {
            return new ActionNode ("smite",
                /*P*/ NULL,
                /*A*/ NextAction::array(0, new NextAction("shoot"), NULL),
                /*C*/ NULL);
        }
        static ActionNode* circle_of_healing(PlayerbotAI* ai)
        {
            return new ActionNode ("circle of healing",
                /*P*/ NULL,
                /*A*/ NextAction::array(0, new NextAction("holy nova"), NULL),
                /*C*/ NULL);
        }
    };
};

using namespace ai;

HolyPriestStrategy::HolyPriestStrategy(PlayerbotAI* ai) : GenericPriestStrategy(ai)
{
    actionNodeFactories.Add(new HolyPriestStrategyActionNodeFactory());
}

NextAction** HolyPriestStrategy::getDefaultActions()
{
    return NextAction::array(0, new NextAction("holy fire", 11.0f), new NextAction("smite", 10.0f), NULL);
}

void HolyPriestStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    GenericPriestStrategy::InitTriggers(triggers);

    triggers.push_back(new TriggerNode(
        "enemy out of spell",
        NextAction::array(0, new NextAction("reach spell", ACTION_MOVE + 9), NULL)));

    triggers.push_back(new TriggerNode(
        "surge of light",
        NextAction::array(0, new NextAction("smite", ACTION_NORMAL + 10), NULL)));

    triggers.push_back(new TriggerNode(
        "almost full health",
        NextAction::array(0, new NextAction("prayer of mending", ACTION_LIGHT_HEAL + 5), new NextAction("renew", ACTION_LIGHT_HEAL + 3), NULL)));

    triggers.push_back(new TriggerNode(
        "party member almost full health",
        NextAction::array(0, new NextAction("prayer of mending on party", ACTION_LIGHT_HEAL + 2), new NextAction("renew on party", ACTION_LIGHT_HEAL + 1), NULL)));

    triggers.push_back(new TriggerNode(
        "master almost full health",
        NextAction::array(0, new NextAction("prayer of mending on master", ACTION_LIGHT_HEAL + 5), new NextAction("renew on master", ACTION_LIGHT_HEAL + 4), NULL)));

    triggers.push_back(new TriggerNode(
		"critical aoe heal",
		NextAction::array(0, new NextAction("holy nova", ACTION_LIGHT_HEAL), NULL)));

    triggers.push_back(new TriggerNode(
		"medium aoe heal",
		NextAction::array(0, new NextAction("circle of healing", ACTION_MEDIUM_HEAL + 2), NULL)));

     triggers.push_back(new TriggerNode(
        "medium health",
        NextAction::array(0, new NextAction("greater heal", ACTION_MEDIUM_HEAL + 6), NULL)));

    triggers.push_back(new TriggerNode(
        "party member medium health",
        NextAction::array(0, new NextAction("binding heal on party", ACTION_MEDIUM_HEAL + 1), NULL)));

    triggers.push_back(new TriggerNode(
        "master medium health",
        NextAction::array(0, new NextAction("binding heal on master", ACTION_MEDIUM_HEAL + 8), NULL)));

    triggers.push_back(new TriggerNode(
        "party member critical health",
        NextAction::array(0, new NextAction("flash heal on party", ACTION_CRITICAL_HEAL + 5), NULL)));

    triggers.push_back(new TriggerNode(
        "master critical health",
        NextAction::array(0, new NextAction("flash heal on master", ACTION_CRITICAL_HEAL + 8), NULL)));

    triggers.push_back(new TriggerNode(
        "low health",
        NextAction::array(0, new NextAction("renew", ACTION_CRITICAL_HEAL + 4), new NextAction("greater heal", ACTION_CRITICAL_HEAL + 3), NULL)));

    triggers.push_back(new TriggerNode(
        "party member low health",
        NextAction::array(0, new NextAction("renew on party", ACTION_CRITICAL_HEAL + 2), new NextAction("greater heal on party", ACTION_CRITICAL_HEAL + 1), NULL)));

    triggers.push_back(new TriggerNode(
        "master low health",
        NextAction::array(0, new NextAction("renew on master", ACTION_CRITICAL_HEAL + 6), new NextAction("greater heal on party", ACTION_CRITICAL_HEAL + 5), NULL)));

    triggers.push_back(new TriggerNode(
        "almost dead",
        NextAction::array(0, new NextAction("guardian spirit", ACTION_EMERGENCY + 6), NULL)));

    triggers.push_back(new TriggerNode(
        "party member almost dead",
        NextAction::array(0, new NextAction("guardian spirit on party", ACTION_EMERGENCY + 5), NULL)));

    triggers.push_back(new TriggerNode(
        "master almost dead",
        NextAction::array(0, new NextAction("guardian spirit on master", ACTION_EMERGENCY + 9), NULL)));
}
