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
        creators["nature's swiftness"] = &nature_swiftness;
    }
private:
    static ActionNode* swiftmend(PlayerbotAI* ai)
    {
        return new ActionNode ("nature's swiftness",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("nature's swiftness"), NULL),
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
        NextAction::array(0, new NextAction("reach spell", ACTION_NORMAL + 9), NULL)));

    triggers.push_back(new TriggerNode(
        "tree form",
        NextAction::array(0, new NextAction("tree form", ACTION_HIGH + 1), NULL)));

    triggers.push_back(new TriggerNode(
        "medium health",
        NextAction::array(0, new NextAction("regrowth", ACTION_MEDIUM_HEAL + 2),NULL)));

    triggers.push_back(new TriggerNode(
        "critical health",
        NextAction::array(0, new NextAction("swiftmend", ACTION_EMERGENCY + 2), NULL)));

    triggers.push_back(new TriggerNode(
        "party member medium health",
        NextAction::array(0, new NextAction("regrowth on party", ACTION_MEDIUM_HEAL + 1), NULL)));

    triggers.push_back(new TriggerNode(
        "party member critical health",
        NextAction::array(0, new NextAction("swiftmend on party", ACTION_EMERGENCY + 1), NULL)));

    triggers.push_back(new TriggerNode(
        "almost full health",
        NextAction::array(0, new NextAction("rejuvenation", ACTION_LIGHT_HEAL + 3), new NextAction("wild growth", ACTION_LIGHT_HEAL + 2), NULL)));

    triggers.push_back(new TriggerNode(
        "party member almost full health",
        NextAction::array(0, new NextAction("rejuvenation on party", ACTION_LIGHT_HEAL + 1), new NextAction("wild growth", ACTION_LIGHT_HEAL), NULL)));

    triggers.push_back(new TriggerNode(
        "medium aoe heal",
        NextAction::array(0, new NextAction("wild growth", ACTION_MEDIUM_HEAL + 3), NULL)));

    triggers.push_back(new TriggerNode(
        "entangling roots",
        NextAction::array(0, new NextAction("entangling roots on cc", ACTION_HIGH + 1), NULL)));
}
