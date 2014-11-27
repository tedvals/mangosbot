#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "RogueTriggers.h"
#include "RogueMultipliers.h"
#include "GenericRogueNonCombatStrategy.h"
#include "RogueActions.h"

using namespace ai;


class GenericRogueNonCombatStrategyActionNodeFactory : public NamedObjectFactory<ActionNode>
{
public:
    GenericRogueNonCombatStrategyActionNodeFactory()
    {
        creators["sprint"] = &sprint;
    }
private:
    static ActionNode* sprint(PlayerbotAI* ai)
    {
        return new ActionNode ("sprint",
            /*P*/ NULL,
            /*A*/ NULL,
            /*C*/ NULL);
    }
};

GenericRogueNonCombatStrategy::GenericRogueNonCombatStrategy(PlayerbotAI* ai) : NonCombatStrategy(ai)
{
    actionNodeFactories.Add(new GenericRogueNonCombatStrategyActionNodeFactory());
}

void GenericRogueNonCombatStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    NonCombatStrategy::InitTriggers(triggers);

        triggers.push_back(new TriggerNode(
        "runaway",
        NextAction::array(0, new NextAction("sprint", 60.0f), NULL)));
}

class GenericRogueNonCombatStealthStrategyActionNodeFactory : public NamedObjectFactory<ActionNode>
{
public:
    GenericRogueNonCombatStealthStrategyActionNodeFactory()
    {
        creators["stealth"] = &stealth;
    }
private:
    static ActionNode* stealth(PlayerbotAI* ai)
    {
        return new ActionNode ("stealth",
            /*P*/ NULL,
            /*A*/ NULL,
            /*C*/ NULL);
    }
};

GenericRogueNonCombatStealthStrategy::GenericRogueNonCombatStealthStrategy(PlayerbotAI* ai) : NonCombatStrategy(ai)
{
    actionNodeFactories.Add(new GenericRogueNonCombatStealthStrategyActionNodeFactory());
}

void GenericRogueNonCombatStealthStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    NonCombatStrategy::InitTriggers(triggers);

    triggers.push_back(new TriggerNode(
        "stealth",
        NextAction::array(0, new NextAction("stealth", 21.0f), NULL)));
}

