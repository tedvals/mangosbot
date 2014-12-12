#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "RogueMultipliers.h"
#include "DpsRogueStrategy.h"

using namespace ai;

class DpsRogueStrategyActionNodeFactory : public NamedObjectFactory<ActionNode>
{
public:
    DpsRogueStrategyActionNodeFactory()
    {
        creators["backstab"] = &backstab;
        creators["kick"] = &kick;
        creators["kidney shot"] = &kidney_shot;
        creators["evasion"] = &evasion;
        creators["vanish"] = &vanish;
        creators["eviscerate"] = &eviscerate;
    }
private:

    static ActionNode* backstab(PlayerbotAI* ai)
    {
        return new ActionNode ("backstab",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("hemorrhage"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* kick(PlayerbotAI* ai)
    {
        return new ActionNode ("kick",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("kidney shot"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* kidney_shot(PlayerbotAI* ai)
    {
        return new ActionNode ("kidney shot",
            /*P*/ NULL,
            /*A*/ NULL,
            /*C*/ NULL);
    }
    static ActionNode* vanish(PlayerbotAI* ai)
    {
        return new ActionNode ("vanish",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("preparation"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* evasion(PlayerbotAI* ai)
    {
        return new ActionNode ("evasion",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("vanish"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* eviscerate(PlayerbotAI* ai)
    {
        return new ActionNode ("eviscerate",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("deadly throw"), NULL),
            /*C*/ NULL);
    }
};

DpsRogueStrategy::DpsRogueStrategy(PlayerbotAI* ai) : MeleeCombatStrategy(ai)
{
    actionNodeFactories.Add(new DpsRogueStrategyActionNodeFactory());
}

NextAction** DpsRogueStrategy::getDefaultActions()
{
    return NextAction::array(0, new NextAction("backstab", ACTION_NORMAL), NULL);
}

void DpsRogueStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    MeleeCombatStrategy::InitTriggers(triggers);


    triggers.push_back(new TriggerNode(
        "stealth",
        NextAction::array(0, new NextAction("stealth", 21.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "combo points available",
        NextAction::array(0, new NextAction("rupture", ACTION_HIGH + 4), NULL)));

    triggers.push_back(new TriggerNode(
        "combo point available",
        NextAction::array(0, new NextAction("slice and dice", ACTION_HIGH + 5), NULL)));

    triggers.push_back(new TriggerNode(
        "riposte",
        NextAction::array(0, new NextAction("riposte", ACTION_HIGH + 3), NULL)));

    triggers.push_back(new TriggerNode(
        "rupture",
        NextAction::array(0, new NextAction("rupture", ACTION_HIGH + 2), NULL)));

    triggers.push_back(new TriggerNode(
        "slice and dice",
        NextAction::array(0, new NextAction("slice and dice", ACTION_HIGH + 5), NULL)));

    triggers.push_back(new TriggerNode(
        "rooted",
        NextAction::array(0, new NextAction("vanish", ACTION_HIGH + 5), NULL)));

    triggers.push_back(new TriggerNode(
        "snared",
        NextAction::array(0, new NextAction("sprint", ACTION_HIGH + 5), NULL)));

	triggers.push_back(new TriggerNode(
		"medium threat",
		NextAction::array(0, new NextAction("feint", ACTION_HIGH), NULL)));

	triggers.push_back(new TriggerNode(
		"critical health",
		NextAction::array(0, new NextAction("vanish", ACTION_EMERGENCY), NULL)));

	triggers.push_back(new TriggerNode(
		"kick",
		NextAction::array(0, new NextAction("kick", ACTION_INTERRUPT + 2), NULL)));

	triggers.push_back(new TriggerNode(
		"kick on enemy healer",
		NextAction::array(0, new NextAction("kick on enemy healer", ACTION_INTERRUPT + 1), NULL)));

    triggers.push_back(new TriggerNode(
        "not facing target",
        NextAction::array(0, new NextAction("set facing", ACTION_NORMAL + 7), NULL)));

     triggers.push_back(new TriggerNode(
        "have aggro",
        NextAction::array(0, new NextAction("evasion", 70.0f), NULL)));
}

class DpsSwordRogueStrategyActionNodeFactory : public NamedObjectFactory<ActionNode>
{
public:
    DpsSwordRogueStrategyActionNodeFactory()
    {
        creators["garrote"] = &garrote;
        creators["riposte"] = &riposte;
        creators["sinister strike"] = &sinister_strike;
        creators["kick"] = &kick;
        creators["rupture"] = &rupture;
        creators["kidney shot"] = &kidney_shot;
        creators["adrenaline rush"] = &adrenaline_rush;
        creators["boost"] = &adrenaline_rush;
    }
private:
    static ActionNode* garrote(PlayerbotAI* ai)
    {
        return new ActionNode ("garrote",
            /*P*/ NextAction::array(0, new NextAction("stealth"), NULL),
            /*A*/ NextAction::array(0, new NextAction("reach melee"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* riposte(PlayerbotAI* ai)
    {
        return new ActionNode ("riposte",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("sinister strike"), NULL),
            /*C*/ NULL);
    }

    static ActionNode* sinister_strike(PlayerbotAI* ai)
    {
        return new ActionNode ("sinister strike",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("melee"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* kick(PlayerbotAI* ai)
    {
        return new ActionNode ("kick",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("kidney shot"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* kidney_shot(PlayerbotAI* ai)
    {
        return new ActionNode ("kidney shot",
            /*P*/ NULL,
            /*A*/ NULL,
            /*C*/ NULL);
    }
    static ActionNode* adrenaline_rush(PlayerbotAI* ai)
    {
        return new ActionNode ("adrenaline rush",
            /*P*/ NULL,
            /*A*/ NULL,
            /*C*/ NULL);
    }
    static ActionNode* rupture(PlayerbotAI* ai)
    {
        return new ActionNode ("rupture",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("eviscerate"), NULL),
            /*C*/ NULL);
    }
};

DpsSwordRogueStrategy::DpsSwordRogueStrategy(PlayerbotAI* ai) : DpsRogueStrategy(ai)
{
    actionNodeFactories.Add(new DpsSwordRogueStrategyActionNodeFactory());
}

NextAction** DpsSwordRogueStrategy::getDefaultActions()
{
    return NextAction::array(0, new NextAction("Sinister Strike", ACTION_NORMAL), NULL);
}

void DpsSwordRogueStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    DpsRogueStrategy::InitTriggers(triggers);

    triggers.push_back(new TriggerNode(
        "enemy out of melee",
        NextAction::array(0, new NextAction("reach melee", ACTION_HIGH + 5), NULL)));

    triggers.push_back(new TriggerNode(
        "combo points available",
        NextAction::array(0, new NextAction("eviscerate", ACTION_HIGH + 2), NULL)));

    triggers.push_back(new TriggerNode(
        "riposte",
        NextAction::array(0, new NextAction("riposte", ACTION_HIGH + 3), NULL)));

    triggers.push_back(new TriggerNode(
        "rupture",
        NextAction::array(0, new NextAction("rupture", ACTION_HIGH + 2), NULL)));

    triggers.push_back(new TriggerNode(
        "garrote",
        NextAction::array(0, new NextAction("garrote", ACTION_HIGH + 4), NULL)));

    triggers.push_back(new TriggerNode(
        "behind target",
        NextAction::array(0, new NextAction("sinister strike", ACTION_NORMAL), NULL)));

    triggers.push_back(new TriggerNode(
        "not facing target",
        NextAction::array(0, new NextAction("set facing", ACTION_NORMAL + 7), NULL)));

    triggers.push_back(new TriggerNode(
        "enemy too close for melee",
        NextAction::array(0, new NextAction("move out of enemy contact", ACTION_NORMAL + 8), NULL)));

     triggers.push_back(new TriggerNode(
        "light aoe",
        NextAction::array(0, new NextAction("blade furry", ACTION_HIGH + 1), NULL)));

    triggers.push_back(new TriggerNode(
        "high aoe",
        NextAction::array(0, new NextAction("fan of knives", ACTION_HIGH + 1), NULL)));

     triggers.push_back(new TriggerNode(
        "boost",
        NextAction::array(0, new NextAction("adrenaline rush", ACTION_NORMAL + 2), NULL)));

     triggers.push_back(new TriggerNode(
        "has nearest adds",
        NextAction::array(0, new NextAction("blade flurry", ACTION_NORMAL + 2), NULL)));

    triggers.push_back(new TriggerNode(
		"target almost dead",
		NextAction::array(0, new NextAction("eviscerate", ACTION_EMERGENCY), NULL)));

    triggers.push_back(new TriggerNode(
		"execute",
		NextAction::array(0, new NextAction("eviscerate", ACTION_EMERGENCY + 2), NULL)));
}

class DpsDaggerRogueStrategyActionNodeFactory : public NamedObjectFactory<ActionNode>
{
public:
    DpsDaggerRogueStrategyActionNodeFactory()
    {
        creators["garrote"] = &garrote;
        creators["ambush"] = &ambush;
        creators["melee"] = &melee;
        creators["shadowstep"] = &shadowstep;
        creators["mutilate"] = &mutilate;
        creators["vanish"] = &vanish;
        creators["rupture"] = &rupture;
        creators["backstab"] = &backstab;
        creators["cold blood"] = &cold_blood;
        creators["envenom"] = &envenom;
        creators["boost"] = &shadow_dance;
        creators["hemorrhage"] = &hemorrhage;
    }
private:
    static ActionNode* garrote(PlayerbotAI* ai)
    {
        return new ActionNode ("garrote",
            /*P*/ NextAction::array(0, new NextAction("stealth"), NULL),
            /*A*/ NextAction::array(0, new NextAction("ambush"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* rupture(PlayerbotAI* ai)
    {
        return new ActionNode ("rupture",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("envenom"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* ambush(PlayerbotAI* ai)
    {
        return new ActionNode ("ambush",
            /*P*/ NextAction::array(0, new NextAction("stealth"), NULL),
            /*A*/ NextAction::array(0, new NextAction("reach melee"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* melee(PlayerbotAI* ai)
    {
        return new ActionNode ("melee",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("shadowstep"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* shadowstep(PlayerbotAI* ai)
    {
        return new ActionNode ("shadowstep",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("reach melee"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* mutilate(PlayerbotAI* ai)
    {
        return new ActionNode ("mutilate",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("backstab"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* vanish(PlayerbotAI* ai)
    {
        return new ActionNode ("vanish",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("preparation"), NULL),
            /*C*/  NextAction::array(0, new NextAction("vanish"), NULL));
    }
    static ActionNode* backstab(PlayerbotAI* ai)
    {
        return new ActionNode ("backstab",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("hemorrhage"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* hemorrhage(PlayerbotAI* ai)
    {
        return new ActionNode ("hemorrhage",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("melee"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* envenom(PlayerbotAI* ai)
    {
        return new ActionNode ("envenom",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("eviscerate"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* shadow_dance(PlayerbotAI* ai)
    {
        return new ActionNode ("shadow dance",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("cold blood"), NULL),
            /*C*/ NextAction::array(0, new NextAction("ambush"), NULL));
    }

    static ActionNode* cold_blood(PlayerbotAI* ai)
    {
        return new ActionNode ("cold blood",
            /*P*/ NULL,
            /*A*/ NULL,
            /*C*/ NextAction::array(0, new NextAction("vanish"), new NextAction("ambush"),NULL));
    }
};

DpsDaggerRogueStrategy::DpsDaggerRogueStrategy(PlayerbotAI* ai) : DpsRogueStrategy(ai)
{
    actionNodeFactories.Add(new DpsDaggerRogueStrategyActionNodeFactory());
}

NextAction** DpsDaggerRogueStrategy::getDefaultActions()
{
    return NextAction::array(0, new NextAction("mutilate", ACTION_NORMAL + 5), new NextAction("backstab", ACTION_NORMAL), NULL);
}

void DpsDaggerRogueStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    DpsRogueStrategy::InitTriggers(triggers);

    triggers.push_back(new TriggerNode(
        "enemy out of melee",
        NextAction::array(0, new NextAction("shadowstep", ACTION_HIGH + 5), NULL)));

    triggers.push_back(new TriggerNode(
        "combo points available",
        NextAction::array(0, new NextAction("envenom", ACTION_HIGH + 2), NULL)));

    triggers.push_back(new TriggerNode(
		"high energy available",
		NextAction::array(0, new NextAction("backstab", ACTION_HIGH), NULL)));

     triggers.push_back(new TriggerNode(
        "rupture",
        NextAction::array(0, new NextAction("rupture", ACTION_HIGH + 2), NULL)));

    triggers.push_back(new TriggerNode(
        "garrote",
        NextAction::array(0, new NextAction("garrote", ACTION_HIGH + 5), NULL)));

    triggers.push_back(new TriggerNode(
        "medium health",
        NextAction::array(0, new NextAction("ghostly strike", ACTION_HIGH + 4), NULL)));

	triggers.push_back(new TriggerNode(
		"medium threat",
		NextAction::array(0, new NextAction("feint", ACTION_HIGH), NULL)));

     triggers.push_back(new TriggerNode(
        "have aggro",
        NextAction::array(0, new NextAction("evasion", 70.0f), NULL)));

    triggers.push_back(new TriggerNode(
		"low health",
		NextAction::array(0, new NextAction("evasion", ACTION_EMERGENCY), NULL)));

	triggers.push_back(new TriggerNode(
		"critical health",
		NextAction::array(0, new NextAction("vanish", ACTION_EMERGENCY), NULL)));

    triggers.push_back(new TriggerNode(
		"target almost dead",
		NextAction::array(0, new NextAction("envenom", ACTION_EMERGENCY), NULL)));

	triggers.push_back(new TriggerNode(
		"kick",
		NextAction::array(0, new NextAction("kick", ACTION_INTERRUPT + 2), NULL)));

	triggers.push_back(new TriggerNode(
		"kick on enemy healer",
		NextAction::array(0, new NextAction("kick on enemy healer", ACTION_INTERRUPT + 1), NULL)));

    triggers.push_back(new TriggerNode(
        "behind target",
        NextAction::array(0, new NextAction("backstab", ACTION_NORMAL), NULL)));

     triggers.push_back(new TriggerNode(
        "boost",
        NextAction::array(0, new NextAction("shadow dance", ACTION_NORMAL + 5), new NextAction("garrote", ACTION_NORMAL + 5), new NextAction("ambush", ACTION_NORMAL + 5), new NextAction("ambush", ACTION_NORMAL + 5),NULL)));

     triggers.push_back(new TriggerNode(
        "high aoe",
        NextAction::array(0, new NextAction("fan of knives", ACTION_HIGH + 1), NULL)));

    triggers.push_back(new TriggerNode(
		"target almost dead",
		NextAction::array(0, new NextAction("envenom", ACTION_EMERGENCY + 2), NULL)));

    triggers.push_back(new TriggerNode(
		"execute",
		NextAction::array(0, new NextAction("envenom", ACTION_EMERGENCY + 2), NULL)));
}
