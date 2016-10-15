#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "DeathKnightMultipliers.h"
#include "TankDeathKnightStrategy.h"

using namespace ai;

class TankDeathKnightStrategyActionNodeFactory : public NamedObjectFactory<ActionNode>
{
public:
    TankDeathKnightStrategyActionNodeFactory()
    {
        creators["melee"] = &melee;
        creators["death grip"] = &death_grip;
        creators["death strike"] = &death_strike;
        creators["scourge strike"] = &scourge_strike;
        creators["obliterate"] = &obliterate;
        creators["dark command"] = &dark_command;
    }
private:
    static ActionNode* melee(PlayerbotAI* ai)
    {
        return new ActionNode ("melee",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("death grip"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* death_grip(PlayerbotAI* ai)
    {
        return new ActionNode ("death grip",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("reach target"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* death_strike(PlayerbotAI* ai)
    {
        return new ActionNode ("death strike",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("scourge strike"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* scourge_strike(PlayerbotAI* ai)
    {
        return new ActionNode ("scourge strike",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("obliterate"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* obliterate(PlayerbotAI* ai)
    {
        return new ActionNode ("obliterate",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("plague strike"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* dark_command(PlayerbotAI* ai)
    {
        return new ActionNode ("dark command",
            /*P*/ NULL,
            /*A*/ NULL,
            /*C*/ NULL);
    }
};

TankDeathKnightStrategy::TankDeathKnightStrategy(PlayerbotAI* ai) : GenericDeathKnightStrategy(ai)
{
    actionNodeFactories.Add(new TankDeathKnightStrategyActionNodeFactory());
}

NextAction** TankDeathKnightStrategy::getDefaultActions()
{
    return NextAction::array(0, new NextAction("heart strike", ACTION_NORMAL + 1), new NextAction("plague strike", ACTION_NORMAL + 2), NULL);
}

void TankDeathKnightStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    GenericDeathKnightStrategy::InitTriggers(triggers);

    triggers.push_back(new TriggerNode(
        "medium runic power available",
        NextAction::array(0, new NextAction("rune strike", ACTION_NORMAL + 2), NULL)));

    triggers.push_back(new TriggerNode(
        "lose aggro",
        NextAction::array(0, new NextAction("dark command", ACTION_HIGH + 9), NULL)));

    triggers.push_back(new TriggerNode(
        "critical health",
        NextAction::array(0, new NextAction("icebound fortitude", ACTION_MEDIUM_HEAL), NULL)));

     triggers.push_back(new TriggerNode(
        "enemy out of melee",
        NextAction::array(0, new NextAction("death grip", ACTION_NORMAL + 9), NULL)));

	triggers.push_back(new TriggerNode(
		"almost dead",
		NextAction::array(0, new NextAction("dark pact", ACTION_EMERGENCY + 3), NULL)));

	triggers.push_back(new TriggerNode(
		"melee light aoe",
		NextAction::array(0, new NextAction("howling blast", ACTION_HIGH + 3), new NextAction("pestilence", ACTION_HIGH + 2),  new NextAction("blood boil", ACTION_HIGH + 2), NULL)));

    triggers.push_back(new TriggerNode(
        "high aoe",
        NextAction::array(0, new NextAction("death and decay", ACTION_HIGH + 3),NULL)));
}
