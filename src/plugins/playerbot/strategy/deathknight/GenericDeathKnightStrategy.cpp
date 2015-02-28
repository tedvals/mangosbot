#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "GenericDeathKnightStrategy.h"
#include "DeathKnightAiObjectContext.h"

using namespace ai;

class GenericDeathKnightStrategyActionNodeFactory : public NamedObjectFactory<ActionNode>
{
public:
    GenericDeathKnightStrategyActionNodeFactory()
    {
	creators["heart strike"] = &heart_strike;
	creators["chains of ice"] = &chains_of_ice;
    creators["mind freeze"] = &mind_freeze;
	creators["rune strike"] = &rune_strike;
	creators["frost strike"] = &frost_strike;
	creators["hysteria on master"] = &hysteria_on_master;
    }
private:
    static ActionNode* heart_strike(PlayerbotAI* ai)
    {
        return new ActionNode ("heart strike",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("blood strike"), NULL),
            /*C*/ NULL);
    }
   static ActionNode* chains_of_ice(PlayerbotAI* ai)
    {
        return new ActionNode ("chains of ice",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("death grip"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* mind_freeze(PlayerbotAI* ai)
    {
        return new ActionNode ("mind freeze",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("strangulate"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* rune_strike(PlayerbotAI* ai)
    {
        return new ActionNode ("rune strike",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("frost strike"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* frost_strike(PlayerbotAI* ai)
    {
        return new ActionNode ("frost strike",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("death coil"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* hysteria_on_master(PlayerbotAI* ai)
    {
        return new ActionNode ("hysteria on master",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("hysteria"), NULL),
            /*C*/ NULL);
    }

};

GenericDeathKnightStrategy::GenericDeathKnightStrategy(PlayerbotAI* ai) : MeleeCombatStrategy(ai)
{
    actionNodeFactories.Add(new GenericDeathKnightStrategyActionNodeFactory());
}

void GenericDeathKnightStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    MeleeCombatStrategy::InitTriggers(triggers);

    triggers.push_back(new TriggerNode(
        "horn of winter",
        NextAction::array(0, new NextAction("horn of winter", ACTION_HIGH + 1), NULL)));

    triggers.push_back(new TriggerNode(
        "blood plague",
        NextAction::array(0, new NextAction("plague strike", ACTION_HIGH + 1), NULL)));

    triggers.push_back(new TriggerNode(
        "high runic power available",
        NextAction::array(0, new NextAction("rune strike", ACTION_HIGH + 1), NULL)));

    triggers.push_back(new TriggerNode(
        "no pet",
        NextAction::array(0, new NextAction("raise ghoul", ACTION_HIGH + 9), NULL)));

    triggers.push_back(new TriggerNode(
        "target fleeing",
        NextAction::array(0, new NextAction("chains of ice", ACTION_MOVE + 5), NULL)));

    triggers.push_back(new TriggerNode(
        "mind freeze",
        NextAction::array(0, new NextAction("mind freeze", ACTION_INTERRUPT + 4), NULL)));

    triggers.push_back(new TriggerNode(
        "mind freeze on enemy healer",
        NextAction::array(0, new NextAction("mind freeze on enemy healer", ACTION_INTERRUPT + 3), NULL)));

  triggers.push_back(new TriggerNode(
        "boost",
        NextAction::array(0, new NextAction("hysteria on master", ACTION_HIGH + 6), NULL)));

    triggers.push_back(new TriggerNode(
		"critical health",
		NextAction::array(0, new NextAction("icebound fortitude", ACTION_EMERGENCY), NULL)));

    triggers.push_back(new TriggerNode(
		"almost dead",
		NextAction::array(0, new NextAction("rune tap", ACTION_EMERGENCY), NULL)));

    triggers.push_back(new TriggerNode(
        "not facing target",
        NextAction::array(0, new NextAction("set facing", ACTION_MOVE + 7), NULL)));

 	triggers.push_back(new TriggerNode(
        "enemy too close for melee",
        NextAction::array(0, new NextAction("move out of enemy contact", ACTION_MOVE + 8), NULL)));

     triggers.push_back(new TriggerNode(
        "runaway",
        NextAction::array(0, new NextAction("hungering cold", ACTION_EMERGENCY + 7), new NextAction("bandage", ACTION_EMERGENCY + 6), NULL)));
}


void DeathKnightBuffHealthStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    triggers.push_back(new TriggerNode(
        "frost presence",
        NextAction::array(0, new NextAction("frost presence", ACTION_EMERGENCY), NULL)));
}

void DeathKnightBuffSpeedStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    triggers.push_back(new TriggerNode(
        "unholy presence",
        NextAction::array(0, new NextAction("unholy presence", ACTION_EMERGENCY), NULL)));
}

void DeathKnightBuffDpsStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    triggers.push_back(new TriggerNode(
        "blood presence",
        NextAction::array(0, new NextAction("blood presence", ACTION_EMERGENCY), NULL)));
}

