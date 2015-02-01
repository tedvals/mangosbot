#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "MageMultipliers.h"
#include "FireMageStrategy.h"

using namespace ai;

class FireMageStrategyActionNodeFactory : public NamedObjectFactory<ActionNode>
{
public:
    FireMageStrategyActionNodeFactory()
    {
        creators["fireball"] = &fire_blast;
        creators["fire blast"] = &fire_blast;
        creators["scorch"] = &scorch;
        creators["combustion"] = &combustion;
        creators["burst"] = &combustion;
        creators["dragon's breath"] = dragons_breath;
        creators["blast wave"] = blast_wave;
    }
private:
    static ActionNode* fireball(PlayerbotAI* ai)
    {
        return new ActionNode ("fireball",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("fire blast"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* fire_blast(PlayerbotAI* ai)
    {
        return new ActionNode ("fire blast",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("shoot"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* scorch(PlayerbotAI* ai)
    {
        return new ActionNode ("scorch",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("fireball"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* combustion(PlayerbotAI* ai)
    {
        return new ActionNode ("combustion",
            /*P*/ NULL,
            /*A*/ NULL,
            /*C*/ NULL);
    }
    static ActionNode* dragons_breath(PlayerbotAI* ai)
    {
        return new ActionNode ("dragon's breath",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("blast wave"), NULL),
            /*C*/ NextAction::array(0, new NextAction("flamestrike", 50.0f), NULL));
    }
    static ActionNode* blast_wave(PlayerbotAI* ai)
    {
        return new ActionNode ("blast wave",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("cone of cold"), NULL),
            /*C*/ NextAction::array(0, new NextAction("flamestrike", 50.0f), NULL));
    }
};

FireMageStrategy::FireMageStrategy(PlayerbotAI* ai) : GenericMageStrategy(ai)
{
    actionNodeFactories.Add(new FireMageStrategyActionNodeFactory());
}

NextAction** FireMageStrategy::getDefaultActions()
{
    return NextAction::array(0, new NextAction("fireball", ACTION_NORMAL), NULL);
}

void FireMageStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    GenericMageStrategy::InitTriggers(triggers);

   // triggers.push_back(new TriggerNode(
   //     "pyroblast",
   //     NextAction::array(0, new NextAction("pyroblast", 10.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "improved scorch",
        NextAction::array(0, new NextAction("scorch", 30.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "target stunned",
        NextAction::array(0, new NextAction("fire blast", 30.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "target almost dead",
        NextAction::array(0, new NextAction("fire blast", 30.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "hot streak",
        NextAction::array(0, new NextAction("pyroblast", 25.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "fiery payback",
        NextAction::array(0, new NextAction("pyroblast", 25.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "combustion",
        NextAction::array(0, new NextAction("combustion", 40.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "burst",
        NextAction::array(0, new NextAction("combustion", 40.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "living bomb on attacker",
        NextAction::array(0, new NextAction("living bomb", 25.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "blazing speed",
        NextAction::array(0, new NextAction("flee", 60.0f), NULL)));
}

void FireMageAoeStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    triggers.push_back(new TriggerNode(
        "enemy too close for spell",
        NextAction::array(0, new NextAction("dragon's breath", 70.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "living bomb",
        NextAction::array(0, new NextAction("living bomb", 25.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "high aoe",
        NextAction::array(0, new NextAction("flamestrike", 20.0f), NULL)));
}

