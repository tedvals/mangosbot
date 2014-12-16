#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "WarriorMultipliers.h"
#include "DpsWarriorStrategy.h"

using namespace ai;

class DpsWarriorStrategyActionNodeFactory : public NamedObjectFactory<ActionNode>
{
public:
    DpsWarriorStrategyActionNodeFactory()
    {
        creators["overpower"] = &overpower;
        creators["melee"] = &melee;
        creators["charge"] = &charge;
        creators["intercept"] = &intercept;
        creators["rend"] = &rend;
        creators["mocking blow"] = &mocking_blow;
        creators["execute"] = &execute;
        creators["slam"] = &slam;
    }
private:
    static ActionNode* overpower(PlayerbotAI* ai)
    {
        return new ActionNode ("overpower",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("melee"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* slam(PlayerbotAI* ai)
    {
        return new ActionNode ("slam",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("heroic strike"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* melee(PlayerbotAI* ai)
    {
        return new ActionNode ("melee",
            /*P*/ NextAction::array(0, new NextAction("charge"), NULL),
            /*A*/ NULL,
            /*C*/ NULL);
    }
    static ActionNode* charge(PlayerbotAI* ai)
    {
        return new ActionNode ("charge",
            /*P*/ NextAction::array(0, new NextAction("battle stance"), NULL),
            /*A*/ NextAction::array(0, new NextAction("reach melee"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* intercept(PlayerbotAI* ai)
    {
        return new ActionNode ("intercept",
            /*P*/ NextAction::array(0, new NextAction("berserker stance"), NULL),
            /*A*/ NextAction::array(0, new NextAction("reach melee"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* rend(PlayerbotAI* ai)
    {
        return new ActionNode ("rend",
            /*P*/ NextAction::array(0, new NextAction("battle stance"), NULL),
            /*A*/ NULL,
            /*C*/ NULL);
    }
    static ActionNode* mocking_blow(PlayerbotAI* ai)
    {
        return new ActionNode ("mocking blow",
            /*P*/ NextAction::array(0, new NextAction("battle stance"), NULL),
            /*A*/ NextAction::array(0, NULL),
            /*C*/ NULL);
    }
    static ActionNode* execute(PlayerbotAI* ai)
    {
        return new ActionNode ("execute",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("heroic strike"), NULL),
            /*C*/ NULL);
    }
};

DpsWarriorStrategy::DpsWarriorStrategy(PlayerbotAI* ai) : GenericWarriorStrategy(ai)
{
    actionNodeFactories.Add(new DpsWarriorStrategyActionNodeFactory());
}

NextAction** DpsWarriorStrategy::getDefaultActions()
{
    return NextAction::array(0, new NextAction("heroic strike", ACTION_NORMAL + 1), NULL);
}

void DpsWarriorStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    GenericWarriorStrategy::InitTriggers(triggers);

    triggers.push_back(new TriggerNode(
        "rend",
        NextAction::array(0, new NextAction("rend", ACTION_NORMAL + 1), NULL)));

    triggers.push_back(new TriggerNode(
        "enemy out of melee",
        NextAction::array(0, new NextAction("charge", ACTION_NORMAL + 9), NULL)));

    triggers.push_back(new TriggerNode(
        "target critical health",
        NextAction::array(0, new NextAction("execute", ACTION_HIGH + 4), NULL)));

	triggers.push_back(new TriggerNode(
		"hamstring",
		NextAction::array(0, new NextAction("hamstring", ACTION_INTERRUPT), NULL)));

	triggers.push_back(new TriggerNode(
		"victory rush",
		NextAction::array(0, new NextAction("victory rush", ACTION_HIGH + 3), NULL)));

    triggers.push_back(new TriggerNode(
        "rooted",
        NextAction::array(0, new NextAction("heroic throw", ACTION_MOVE + 10), NULL)));


    triggers.push_back(new TriggerNode(
        "target fleeing",
        NextAction::array(0, new NextAction("hamstring", ACTION_HIGH + 2), NULL)));
}


class DpsArmsWarriorStrategyActionNodeFactory : public NamedObjectFactory<ActionNode>
{
public:
    DpsArmsWarriorStrategyActionNodeFactory()
    {
        creators["overpower"] = &overpower;
        creators["mortal strike"]= &mortal_strike;
        creators["sweeping strikes"]= &sweeping_strikes;
        creators["bladestorm"]= &bladestorm;
        creators["overpower"] = &overpower;
        creators["rend"] = &rend;
        creators["melee"] = &melee;
        creators["charge"] = &charge;
        creators["rend"] = &rend;
        creators["mocking blow"] = &mocking_blow;
        creators["execute"] = &execute;
        creators["slam"] = &slam;

    }
private:
    static ActionNode* overpower(PlayerbotAI* ai)
    {
        return new ActionNode ("overpower",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("melee"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* mortal_strike(PlayerbotAI* ai)
    {
        return new ActionNode ("mortal strike",
            /*P*/ NextAction::array(0, new NextAction("battle stance"), NULL),
            /*A*/ NextAction::array(0, new NextAction("slam"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* sweeping_strikes(PlayerbotAI* ai)
    {
        return new ActionNode ("sweeping strikes",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("whirlwind"), NULL),
            /*C*/ NULL);
    }
     static ActionNode* bladestorm(PlayerbotAI* ai)
    {
        return new ActionNode ("bladestorm",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("whirlwind"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* slam(PlayerbotAI* ai)
    {
        return new ActionNode ("slam",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("heroic strike"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* melee(PlayerbotAI* ai)
    {
        return new ActionNode ("melee",
            /*P*/ NextAction::array(0, new NextAction("charge"), NULL),
            /*A*/ NULL,
            /*C*/ NULL);
    }
    static ActionNode* charge(PlayerbotAI* ai)
    {
        return new ActionNode ("charge",
            /*P*/ NextAction::array(0, new NextAction("battle stance"), NULL),
            /*A*/ NextAction::array(0, new NextAction("reach melee"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* rend(PlayerbotAI* ai)
    {
        return new ActionNode ("rend",
            /*P*/ NextAction::array(0, new NextAction("battle stance"), NULL),
            /*A*/ NULL,
            /*C*/ NULL);
    }
    static ActionNode* mocking_blow(PlayerbotAI* ai)
    {
        return new ActionNode ("mocking blow",
            /*P*/ NextAction::array(0, new NextAction("battle stance"), NULL),
            /*A*/ NextAction::array(0, NULL),
            /*C*/ NULL);
    }
    static ActionNode* execute(PlayerbotAI* ai)
    {
        return new ActionNode ("execute",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("heroic strike"), NULL),
            /*C*/ NULL);
    }

};

DpsArmsWarriorStrategy::DpsArmsWarriorStrategy(PlayerbotAI* ai) : GenericWarriorStrategy(ai)
{
    actionNodeFactories.Add(new DpsArmsWarriorStrategyActionNodeFactory());
}

NextAction** DpsArmsWarriorStrategy::getDefaultActions()
{
    return NextAction::array(0, new NextAction("overpower", ACTION_NORMAL + 5), new NextAction("mortal strike", ACTION_NORMAL + 4), new NextAction("slam", ACTION_NORMAL), NULL);
}

void DpsArmsWarriorStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    GenericWarriorStrategy::InitTriggers(triggers);

    triggers.push_back(new TriggerNode(
        "rend",
        NextAction::array(0, new NextAction("rend", ACTION_NORMAL + 1), NULL)));

    triggers.push_back(new TriggerNode(
        "rend on attacker",
        NextAction::array(0, new NextAction("rend on attacker", ACTION_HIGH + 1), NULL)));

	triggers.push_back(new TriggerNode(
		"hamstring",
		NextAction::array(0, new NextAction("hamstring", ACTION_INTERRUPT), NULL)));

    triggers.push_back(new TriggerNode(
        "rooted",
        NextAction::array(0, new NextAction("heroic throw", ACTION_MOVE + 10), NULL)));

    triggers.push_back(new TriggerNode(
        "target fleeing",
        NextAction::array(0, new NextAction("hamstring", ACTION_HIGH + 2), NULL)));

     triggers.push_back(new TriggerNode(
        "medium rage available",
        NextAction::array(0, new NextAction("heroic strike", ACTION_NORMAL + 2), NULL)));

    triggers.push_back(new TriggerNode(
        "battle stance",
        NextAction::array(0, new NextAction("battle stance", ACTION_MOVE + 10), NULL)));

    triggers.push_back(new TriggerNode(
        "enemy out of melee",
        NextAction::array(0, new NextAction("charge", ACTION_NORMAL + 9), NULL)));

    triggers.push_back(new TriggerNode(
        "target critical health",
        NextAction::array(0, new NextAction("execute", ACTION_HIGH + 4), NULL)));

	triggers.push_back(new TriggerNode(
		"victory rush",
		NextAction::array(0, new NextAction("victory rush", ACTION_HIGH + 3), NULL)));

	triggers.push_back(new TriggerNode(
		"sudden death",
		NextAction::array(0, new NextAction("execute", ACTION_HIGH + 8), NULL)));

    triggers.push_back(new TriggerNode(
        "taste for blood",
        NextAction::array(0, new NextAction("overpower", ACTION_HIGH + 6), NULL)));

    triggers.push_back(new TriggerNode(
        "boost",
        NextAction::array(0, new NextAction("recklessness", ACTION_HIGH + 2), new NextAction("bladestorm", ACTION_HIGH + 2), NULL)));

}

class DpsFuryWarriorStrategyActionNodeFactory : public NamedObjectFactory<ActionNode>
{
public:
    DpsFuryWarriorStrategyActionNodeFactory()
    {
        creators["intercept"] = &intercept;
        creators["death wish"] = &death_wish;
        creators["boost"] = &death_wish;
        creators["whirlwind"]= &whirlwind;
        creators["melee"] = &melee;
        creators["execute"] = &execute;
        creators["slam"] = &slam;
    }
private:
    static ActionNode* intercept(PlayerbotAI* ai)
    {
        return new ActionNode ("intercept",
            /*P*/ NextAction::array(0, new NextAction("berserker stance"), NULL),
            /*A*/ NextAction::array(0, new NextAction("reach melee"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* whirlwind(PlayerbotAI* ai)
    {
        return new ActionNode ("whirlwind",
            /*P*/ NextAction::array(0, new NextAction("berserker stance"), NULL),
            /*A*/ NextAction::array(0, new NextAction("cleave"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* death_wish(PlayerbotAI* ai)
    {
        return new ActionNode ("death wish",
        /*P*/ NULL,
        /*A*/ NextAction::array(0, new NextAction("berserker rage"), NULL),
        /*C*/ NULL);
    }
    static ActionNode* execute(PlayerbotAI* ai)
    {
        return new ActionNode ("execute",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("heroic strike"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* melee(PlayerbotAI* ai)
    {
        return new ActionNode ("melee",
            /*P*/ NextAction::array(0, new NextAction("intercept"), NULL),
            /*A*/ NULL,
            /*C*/ NULL);
    }
    static ActionNode* slam(PlayerbotAI* ai)
    {
        return new ActionNode ("slam",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("heroic strike"), NULL),
            /*C*/ NULL);
    }
};

DpsFuryWarriorStrategy::DpsFuryWarriorStrategy(PlayerbotAI* ai) : GenericWarriorStrategy(ai)
{
    actionNodeFactories.Add(new DpsWarriorStrategyActionNodeFactory());
}

NextAction** DpsFuryWarriorStrategy::getDefaultActions()
{
    return NextAction::array(0, new NextAction("bloodthirst", ACTION_NORMAL + 5), new NextAction("whirlwind", ACTION_NORMAL + 2), NULL);
}

void DpsFuryWarriorStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    GenericWarriorStrategy::InitTriggers(triggers);


    triggers.push_back(new TriggerNode(
        "target critical health",
        NextAction::array(0, new NextAction("execute", ACTION_HIGH + 4), NULL)));

	triggers.push_back(new TriggerNode(
		"hamstring",
		NextAction::array(0, new NextAction("hamstring", ACTION_INTERRUPT), NULL)));

	triggers.push_back(new TriggerNode(
		"victory rush",
		NextAction::array(0, new NextAction("victory rush", ACTION_HIGH + 3), NULL)));

    triggers.push_back(new TriggerNode(
        "enemy out of melee",
        NextAction::array(0, new NextAction("intercept", ACTION_NORMAL + 9), NULL)));

    triggers.push_back(new TriggerNode(
        "target fleeing",
        NextAction::array(0, new NextAction("hamstring", ACTION_HIGH + 2), NULL)));

      triggers.push_back(new TriggerNode(
        "medium rage available",
        NextAction::array(0, new NextAction("heroic strike", ACTION_NORMAL + 2), NULL)));

    triggers.push_back(new TriggerNode(
        "berserker stance",
        NextAction::array(0, new NextAction("berserker stance", ACTION_MOVE + 10), NULL)));

    triggers.push_back(new TriggerNode(
        "reach melee",
        NextAction::array(0, new NextAction("intercept", ACTION_NORMAL + 9), NULL)));

     triggers.push_back(new TriggerNode(
        "rooted",
        NextAction::array(0, new NextAction("heroic fury", ACTION_NORMAL + 9), NULL)));

	triggers.push_back(new TriggerNode(
		"bloodsurge",
		NextAction::array(0, new NextAction("slam", ACTION_HIGH + 3), NULL)));

    triggers.push_back(new TriggerNode(
        "death wish",
        NextAction::array(0, new NextAction("death wish", ACTION_HIGH + 2), NULL)));

    triggers.push_back(new TriggerNode(
        "burst",
        NextAction::array(0, new NextAction("recklessness", ACTION_HIGH + 2), NULL)));

    triggers.push_back(new TriggerNode(
        "boost",
        NextAction::array(0, new NextAction("death wish", ACTION_HIGH + 2), NULL)));

    triggers.push_back(new TriggerNode(
        "light rage available",
        NextAction::array(0, new NextAction("berserker rage", ACTION_HIGH + 1), NULL)));


   //   triggers.push_back(new TriggerNode(
   //     "target fleeing",
   //     NextAction::array(0, new NextAction("hamstring", ACTION_HIGH + 2), NULL)));
}

void DpsWarriorAoeStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    triggers.push_back(new TriggerNode(
        "light aoe",
        NextAction::array(0, new NextAction("thunder clap", ACTION_HIGH + 2), new NextAction("demoralizing shout", ACTION_HIGH + 2), NULL)));

    triggers.push_back(new TriggerNode(
        "medium aoe",
        NextAction::array(0, new NextAction("sweeping strikes", ACTION_HIGH + 5), new NextAction("cleave", ACTION_HIGH + 3), NULL)));

    triggers.push_back(new TriggerNode(
        "high aoe",
        NextAction::array(0, new NextAction("bladestorm", ACTION_HIGH + 5), new NextAction("cleave", ACTION_HIGH + 3), NULL)));
}
