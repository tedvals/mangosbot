#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "DeathKnightMultipliers.h"
#include "DpsDeathKnightStrategy.h"

using namespace ai;

class DpsDeathKnightStrategyActionNodeFactory : public NamedObjectFactory<ActionNode>
{
public:
    DpsDeathKnightStrategyActionNodeFactory()
    {
        creators["melee"] = &melee;
        creators["death grip"] = &death_grip;
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
};

DpsDeathKnightStrategy::DpsDeathKnightStrategy(PlayerbotAI* ai) : GenericDeathKnightStrategy(ai)
{
    actionNodeFactories.Add(new DpsDeathKnightStrategyActionNodeFactory());
}

NextAction** DpsDeathKnightStrategy::getDefaultActions()
{
    return NextAction::array(0, new NextAction("blood strike", ACTION_NORMAL),  NULL);
}

void DpsDeathKnightStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    GenericDeathKnightStrategy::InitTriggers(triggers);

    	triggers.push_back(new TriggerNode(
        "frost fever",
        NextAction::array(0, new NextAction("icy touch", ACTION_HIGH + 2), NULL)));

    	triggers.push_back(new TriggerNode(
        "enemy out of melee",
        NextAction::array(0, new NextAction("move behind", ACTION_MOVE + 9), NULL)));

 	triggers.push_back(new TriggerNode(
        "enemy too close for melee",
        NextAction::array(0, new NextAction("move out of enemy contact", ACTION_MOVE + 8), NULL)));
	}


class DpsBloodDeathKnightStrategyActionNodeFactory : public NamedObjectFactory<ActionNode>
{
public:
    DpsBloodDeathKnightStrategyActionNodeFactory()
    {
	creators["melee"] = &melee;
    }
private:
    static ActionNode* melee(PlayerbotAI* ai)
    {
        return new ActionNode ("melee",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("move behind"), NULL),
            /*C*/ NULL);
    }
};

DpsBloodDeathKnightStrategy::DpsBloodDeathKnightStrategy(PlayerbotAI* ai) : GenericDeathKnightStrategy(ai)
{
    actionNodeFactories.Add(new DpsBloodDeathKnightStrategyActionNodeFactory());
}

NextAction** DpsBloodDeathKnightStrategy::getDefaultActions()
{
    return NextAction::array(0, new NextAction("heart strike", ACTION_NORMAL + 8), new NextAction("death strike", ACTION_NORMAL + 6), NULL);
}

void DpsBloodDeathKnightStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    GenericDeathKnightStrategy::InitTriggers(triggers);

 	triggers.push_back(new TriggerNode(
        "enemy too close for melee",
        NextAction::array(0, new NextAction("move out of enemy contact", ACTION_MOVE + 8), NULL)));

    triggers.push_back(new TriggerNode(
        "frost fever",
        NextAction::array(0, new NextAction("icy touch", ACTION_HIGH + 2), NULL)));

     triggers.push_back(new TriggerNode(
        "boost",
        NextAction::array(0, new NextAction("dancing rune weapon", ACTION_HIGH + 5), NULL)));

    triggers.push_back(new TriggerNode(
        "rooted",
        NextAction::array(0, new NextAction("death coil", ACTION_MOVE + 9), NULL)));

     triggers.push_back(new TriggerNode(
        "medium runic power available",
        NextAction::array(0, new NextAction("death coil", ACTION_NORMAL + 2), NULL)));

    triggers.push_back(new TriggerNode(
        "enemy out of melee",
        NextAction::array(0, new NextAction("move behind", ACTION_MOVE + 9), NULL)));

	triggers.push_back(new TriggerNode(
		"sudden doom",
		NextAction::array(0, new NextAction("death coil", ACTION_HIGH + 3), NULL)));

    triggers.push_back(new TriggerNode(
        "almost dead",
        NextAction::array(0, new NextAction("bandage", ACTION_EMERGENCY), NULL)));
 }

class DpsFrostDeathKnightStrategyActionNodeFactory : public NamedObjectFactory<ActionNode>
{
public:
    DpsFrostDeathKnightStrategyActionNodeFactory()
    {
        creators["melee"] = &melee;
	creators["howling blast"] = &howling_blast;
	creators["frost strike"] = &frost_strike;
    }
private:
   static ActionNode* melee(PlayerbotAI* ai)
    {
        return new ActionNode ("melee",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("move behind"), NULL),
            /*C*/ NULL);
    }
   static ActionNode* howling_blast(PlayerbotAI* ai)
    {
        return new ActionNode ("howling blast",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("icy touch"), NULL),
            /*C*/ NULL);
    }
   static ActionNode* frost_strike(PlayerbotAI* ai)
    {
        return new ActionNode ("frost strike",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("death coil"), NULL),
            /*C*/ NULL);
    }

};

DpsFrostDeathKnightStrategy::DpsFrostDeathKnightStrategy(PlayerbotAI* ai) : GenericDeathKnightStrategy(ai)
{
    actionNodeFactories.Add(new DpsDeathKnightStrategyActionNodeFactory());
}

NextAction** DpsFrostDeathKnightStrategy::getDefaultActions()
{
    return NextAction::array(0, new NextAction("howling blast", ACTION_NORMAL + 6),new NextAction("obliterate", ACTION_NORMAL + 5), new NextAction("blood strike", ACTION_NORMAL + 4), NULL);
}

void DpsFrostDeathKnightStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    GenericDeathKnightStrategy::InitTriggers(triggers);

    triggers.push_back(new TriggerNode(
        "frost fever",
        NextAction::array(0, new NextAction("howling blast", ACTION_HIGH + 2), NULL)));

     triggers.push_back(new TriggerNode(
        "medium runic power available",
        NextAction::array(0, new NextAction("frost strike", ACTION_NORMAL + 2), NULL)));

    triggers.push_back(new TriggerNode(
        "enemy out of melee",
        NextAction::array(0, new NextAction("move behind", ACTION_MOVE + 9), NULL)));

    triggers.push_back(new TriggerNode(
        "reach melee",
        NextAction::array(0, new NextAction("move behind", ACTION_MOVE + 9), NULL)));

    triggers.push_back(new TriggerNode(
        "burst",
        NextAction::array(0, new NextAction("deathchill", ACTION_HIGH + 2), new NextAction("empower rune weapon", ACTION_HIGH + 1), NULL)));

    triggers.push_back(new TriggerNode(
        "boost",
        NextAction::array(0, new NextAction("unbreakable armor", ACTION_HIGH + 2), NULL)));
 }

class DpsUnholyDeathKnightStrategyActionNodeFactory : public NamedObjectFactory<ActionNode>
{
public:
    DpsUnholyDeathKnightStrategyActionNodeFactory()
    {
        creators["melee"] = &melee;
    }
private:
   static ActionNode* melee(PlayerbotAI* ai)
    {
        return new ActionNode ("melee",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("move behind"), NULL),
            /*C*/ NULL);
    }
};

DpsUnholyDeathKnightStrategy::DpsUnholyDeathKnightStrategy(PlayerbotAI* ai) : GenericDeathKnightStrategy(ai)
{
    actionNodeFactories.Add(new DpsDeathKnightStrategyActionNodeFactory());
}

NextAction** DpsUnholyDeathKnightStrategy::getDefaultActions()
{
    return NextAction::array(0, new NextAction("scourge strike", ACTION_NORMAL + 6),new NextAction("blood strike", ACTION_NORMAL + 4), NULL);
}

void DpsUnholyDeathKnightStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    GenericDeathKnightStrategy::InitTriggers(triggers);

     triggers.push_back(new TriggerNode(
        "medium runic power available",
        NextAction::array(0, new NextAction("death coil", ACTION_NORMAL + 2), NULL)));

    triggers.push_back(new TriggerNode(
        "enemy out of melee",
        NextAction::array(0, new NextAction("move behind", ACTION_MOVE + 9), NULL)));

 	triggers.push_back(new TriggerNode(
        "enemy too close for melee",
        NextAction::array(0, new NextAction("move out of enemy contact", ACTION_MOVE + 8), NULL)));

    triggers.push_back(new TriggerNode(
        "target fleeing",
        NextAction::array(0, new NextAction("chains of ice", ACTION_HIGH + 2), NULL)));

    triggers.push_back(new TriggerNode(
        "reach melee",
        NextAction::array(0, new NextAction("move behind", ACTION_MOVE + 9), NULL)));

    triggers.push_back(new TriggerNode(
        "burst",
        NextAction::array(0, new NextAction("empower rune weapon", ACTION_HIGH + 2), NULL)));

    triggers.push_back(new TriggerNode(
        "boost",
        NextAction::array(0, new NextAction("summon gargoyle", ACTION_HIGH + 2), NULL)));
 }


NextAction** DpsDeathKnightAoeStrategy::getDefaultActions()
{
    return NextAction::array(0, new NextAction("blood boil", ACTION_NORMAL), NULL);
}

void DpsDeathKnightAoeStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{

    triggers.push_back(new TriggerNode(
        "melee medium aoe",
        NextAction::array(0, new NextAction("pestilence", ACTION_HIGH + 3), new NextAction("blood boil", ACTION_HIGH), new NextAction("blood boil", ACTION_HIGH), NULL)));

    triggers.push_back(new TriggerNode(
        "melee high aoe",
        NextAction::array(0, new NextAction("death and decay", ACTION_HIGH + 7), new NextAction("pestilence", ACTION_HIGH + 3), new NextAction("blood boil", ACTION_HIGH), new NextAction("blood boil", ACTION_HIGH), NULL)));
}
