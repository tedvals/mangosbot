#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "RacialsStrategy.h"

using namespace ai;


class RacialsStrategyActionNodeFactory : public NamedObjectFactory<ActionNode>
{
public:
    RacialsStrategyActionNodeFactory()
    {
        creators["lifeblood"] = &lifeblood;
        creators["racial boost"] = &berserking;
        creators["berserking"] = &berserking;
        creators["blood fury"] = &blood_fury;
        creators["stoneform"] = &stoneform;
    }
private:
    static ActionNode* stoneform(PlayerbotAI* ai)
    {
        return new ActionNode ("stoneform",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("lifeblood"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* lifeblood(PlayerbotAI* ai)
    {
        return new ActionNode ("lifeblood",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("gift of the naaru"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* berserking(PlayerbotAI* ai)
    {
        return new ActionNode ("berserking",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("blood fury"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* blood_fury(PlayerbotAI* ai)
    {
        return new ActionNode ("blood fury",
            /*P*/ NULL,
            /*A*/ NULL,
            /*C*/ NULL);
    }
};

void RacialsStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
	triggers.push_back(new TriggerNode(
		"low health",
		NextAction::array(0, new NextAction("stoneform", ACTION_EMERGENCY + 6), NULL)));

    triggers.push_back(new TriggerNode(
		"almost dead",
		NextAction::array(0, new NextAction("shadowmelt", ACTION_EMERGENCY + 6), NULL)));

    triggers.push_back(new TriggerNode(
        "low mana",
        NextAction::array(0, new NextAction("arcane torrent", ACTION_EMERGENCY + 6), NULL)));

    triggers.push_back(new TriggerNode(
        "racial boost",
        NextAction::array(0, new NextAction("berserking", ACTION_EMERGENCY + 6), NULL)));
}

RacialsStrategy::RacialsStrategy(PlayerbotAI* ai) : Strategy(ai)
{
    actionNodeFactories.Add(new RacialsStrategyActionNodeFactory());
}
