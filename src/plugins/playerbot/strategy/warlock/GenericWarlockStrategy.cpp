#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "WarlockMultipliers.h"
#include "GenericWarlockStrategy.h"

using namespace ai;

class GenericWarlockStrategyActionNodeFactory : public NamedObjectFactory<ActionNode>
{
public:
    GenericWarlockStrategyActionNodeFactory()
    {
        creators["banish"] = &banish;
        creators["death coil"] = &death_coil;
    }
private:
    static ActionNode* banish(PlayerbotAI* ai)
    {
        return new ActionNode ("banish",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("fear"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* death_coil(PlayerbotAI* ai)
    {
        return new ActionNode ("death coil",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("howl of terror"), NULL),
            /*C*/ NextAction::array(0, new NextAction("fear"), NULL));
    }
};

GenericWarlockStrategy::GenericWarlockStrategy(PlayerbotAI* ai) : RangedCombatStrategy(ai)
{
    actionNodeFactories.Add(new GenericWarlockStrategyActionNodeFactory());
}

NextAction** GenericWarlockStrategy::getDefaultActions()
{
    return NextAction::array(0, new NextAction("shadow bolt", 10.0f), NULL);
}

void GenericWarlockStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    RangedCombatStrategy::InitTriggers(triggers);

    //triggers.push_back(new TriggerNode(
    //    "curse of agony",
    //    NextAction::array(0, new NextAction("curse of agony", 11.0f), NULL)));

     triggers.push_back(new TriggerNode(
        "enemy out of spell",
        NextAction::array(0, new NextAction("reach spell", ACTION_NORMAL + 9), NULL)));

     triggers.push_back(new TriggerNode(
        "enemy too close for spell",
        NextAction::array(0, new NextAction("flee",49.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "almost dead",
        NextAction::array(0, new NextAction("death coil", 40.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "medium mana",
        NextAction::array(0, new NextAction("life tap", ACTION_EMERGENCY + 5), NULL)));

	triggers.push_back(new TriggerNode(
		"target almost dead",
		NextAction::array(0, new NextAction("drain soul", 30.0f), NULL)));

     triggers.push_back(new TriggerNode(
        "target fleeing",
        NextAction::array(0, new NextAction("curse of exhaustion", 30.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "banish",
        NextAction::array(0, new NextAction("banish", 21.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "fear",
        NextAction::array(0, new NextAction("fear on cc", 20.0f), NULL)));

}
