#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "DruidMultipliers.h"
#include "HealDruidStrategy.h"

using namespace ai;

class HealDruidStrategyActionNodeFactory : public NamedObjectFactory<ActionNode>
{
public:
    HealDruidStrategyActionNodeFactory()
    {
        creators["swiftmend"] = &swiftmend;
        creators["swiftmend on party"] = &swiftmend_on_party;
        creators["swiftmend on master"] = &swiftmend_on_master;
        creators["wild growth on master"] = &wild_growth_on_master;
        creators["nature's swiftness"] = &nature_swiftness;
    }
private:
    static ActionNode* swiftmend(PlayerbotAI* ai)
    {
        return new ActionNode ("swiftmend",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("nature's swiftness"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* swiftmend_on_party(PlayerbotAI* ai)
    {
        return new ActionNode ("swiftmend on party",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("nature's swiftness"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* swiftmend_on_master(PlayerbotAI* ai)
    {
        return new ActionNode ("swiftmend on master",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("nature's swiftness"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* wild_growth_on_master(PlayerbotAI* ai)
    {
        return new ActionNode ("wild growth on master",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("lifebloom on master"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* nature_swiftness(PlayerbotAI* ai)
    {
        return new ActionNode ("nature's swiftness",
            /*P*/ NULL,
            /*A*/ NULL,
            /*C*/ NextAction::array(0, new NextAction("healing touch"), NULL));
    }
};

HealDruidStrategy::HealDruidStrategy(PlayerbotAI* ai) : GenericDruidStrategy(ai)
{
    actionNodeFactories.Add(new HealDruidStrategyActionNodeFactory());
}

void HealDruidStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    GenericDruidStrategy::InitTriggers(triggers);

    triggers.push_back(new TriggerNode(
        "enemy out of spell",
        NextAction::array(0, new NextAction("reach spell", ACTION_MOVE + 9), NULL)));

    triggers.push_back(new TriggerNode(
        "tree form",
        NextAction::array(0, new NextAction("tree form", ACTION_HIGH + 1), NULL)));

    triggers.push_back(new TriggerNode(
        "medium health",
        NextAction::array(0, new NextAction("regrowth", ACTION_MEDIUM_HEAL + 2),NULL)));

    triggers.push_back(new TriggerNode(
        "critical health",
        NextAction::array(0, new NextAction("swiftmend", ACTION_CRITICAL_HEAL + 2), NULL)));

    triggers.push_back(new TriggerNode(
        "party member medium health",
        NextAction::array(0, new NextAction("regrowth on party", ACTION_MEDIUM_HEAL + 1), NULL)));

    triggers.push_back(new TriggerNode(
        "master medium health",
        NextAction::array(0, new NextAction("regrowth on master", ACTION_CRITICAL_HEAL), NULL)));

    triggers.push_back(new TriggerNode(
        "party member critical health",
        NextAction::array(0, new NextAction("swiftmend on party", ACTION_CRITICAL_HEAL + 1), NULL)));

    triggers.push_back(new TriggerNode(
        "master critical health",
        NextAction::array(0, new NextAction("swiftmend on master", ACTION_EMERGENCY + 1), NULL)));

    triggers.push_back(new TriggerNode(
        "almost full health",
        NextAction::array(0, new NextAction("rejuvenation", ACTION_LIGHT_HEAL + 3), NULL)));

    triggers.push_back(new TriggerNode(
        "master almost full health",
        NextAction::array(0, new NextAction("wild growth on master", ACTION_LIGHT_HEAL + 6), new NextAction("rejuvenation on master", ACTION_LIGHT_HEAL + 5), NULL)));

    triggers.push_back(new TriggerNode(
        "party member almost full health",
        NextAction::array(0, new NextAction("rejuvenation on party", ACTION_LIGHT_HEAL + 1), NULL)));

    triggers.push_back(new TriggerNode(
        "almost full aoe heal",
        NextAction::array(0, new NextAction("wild growth on master", ACTION_MEDIUM_HEAL + 3), NULL)));

    triggers.push_back(new TriggerNode(
        "entangling roots",
        NextAction::array(0, new NextAction("entangling roots on cc", ACTION_HIGH + 1), NULL)));
}
