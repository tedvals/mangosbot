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
        creators["will of the forsaken"] = &will_of_the_forsaken;
        creators["escape artist"] = &escape_artist;
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
    static ActionNode* will_of_the_forsaken(PlayerbotAI* ai)
    {
        return new ActionNode ("will of the forsaken",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("every man for himself"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* escape_artist(PlayerbotAI* ai)
    {
        return new ActionNode ("escape artist",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("every man for himself"), NULL),
        /*C*/ NULL);
    }
};

void RacialsStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
	triggers.push_back(new TriggerNode(
		"low health",
		NextAction::array(0, new NextAction("stoneform", ACTION_EMERGENCY + 6), NULL)));

    triggers.push_back(new TriggerNode(
		"critical health",
		NextAction::array(0, new NextAction("lifeblood", ACTION_EMERGENCY + 6), NULL)));

    triggers.push_back(new TriggerNode(
		"party member almost dead",
		NextAction::array(0, new NextAction("gift of the naaru on party", ACTION_EMERGENCY + 6), NULL)));

    triggers.push_back(new TriggerNode(
		"almost dead",
		NextAction::array(0, new NextAction("shadowmeld", ACTION_EMERGENCY + 6), NULL)));

    triggers.push_back(new TriggerNode(
        "low mana",
        NextAction::array(0, new NextAction("arcane torrent", ACTION_EMERGENCY + 6), NULL)));

    triggers.push_back(new TriggerNode(
        "charmed",
        NextAction::array(0, new NextAction("will of the forsaken", ACTION_EMERGENCY + 6), NULL)));

    triggers.push_back(new TriggerNode(
        "racial boost",
        NextAction::array(0, new NextAction("berserking", ACTION_EMERGENCY + 6), NULL)));

     triggers.push_back(new TriggerNode(
        "bleeding",
        NextAction::array(0, new NextAction("stoneform", ACTION_EMERGENCY + 6), NULL)));

     triggers.push_back(new TriggerNode(
        "feared",
        NextAction::array(0, new NextAction("will of the forsaken", ACTION_EMERGENCY + 6), NULL)));

     triggers.push_back(new TriggerNode(
        "rooted",
        NextAction::array(0, new NextAction("escape artist", ACTION_EMERGENCY + 6), NULL)));
}

RacialsStrategy::RacialsStrategy(PlayerbotAI* ai) : Strategy(ai)
{
    actionNodeFactories.Add(new RacialsStrategyActionNodeFactory());
}
