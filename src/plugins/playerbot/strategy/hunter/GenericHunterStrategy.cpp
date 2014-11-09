#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "GenericHunterStrategy.h"
#include "HunterAiObjectContext.h"

using namespace ai;

class GenericHunterStrategyActionNodeFactory : public NamedObjectFactory<ActionNode>
{
public:
    GenericHunterStrategyActionNodeFactory()
    {
        creators["rapid fire"] = &rapid_fire;
        creators["boost"] = &rapid_fire;
        creators["aspect of the pack"] = &aspect_of_the_pack;
        creators["aspect of the dragonhawk"] = &aspect_of_the_dragonhawk;
        creators["feign death"] = &feign_death;
        creators["silencing shot"] = &silencing_shot;
        creators["intimidation"] = &intimidation;
        creators["wing clip"] = &wing_clip;
        creators["misdirection"] = &wing_clip;
    }
private:
    static ActionNode* rapid_fire(PlayerbotAI* ai)
    {
        return new ActionNode ("rapid fire",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("readiness"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* aspect_of_the_dragonhawk(PlayerbotAI* ai)
    {
        return new ActionNode ("aspect of the dragonhawk",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("aspect of the hawk"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* aspect_of_the_pack(PlayerbotAI* ai)
    {
        return new ActionNode ("aspect of the pack",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("aspect of the cheetah"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* feign_death(PlayerbotAI* ai)
    {
        return new ActionNode ("feign death",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("flee"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* silencing_shot(PlayerbotAI* ai)
    {
        return new ActionNode ("silencing shot",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("intimidation"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* intimidation(PlayerbotAI* ai)
    {
        return new ActionNode ("intimidation",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("scatter shot"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* wing_clip(PlayerbotAI* ai)
    {
        return new ActionNode ("wing clip",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("intimidation"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* scatter_shot(PlayerbotAI* ai)
    {
        return new ActionNode ("shatter shot",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("disengage"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* misdirection(PlayerbotAI* ai)
    {
        return new ActionNode ("misdirection",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("feign death"), NULL),
            /*C*/ NULL);
    }
};

GenericHunterStrategy::GenericHunterStrategy(PlayerbotAI* ai) : RangedCombatStrategy(ai)
{
    actionNodeFactories.Add(new GenericHunterStrategyActionNodeFactory());
}

void GenericHunterStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    RangedCombatStrategy::InitTriggers(triggers);

    triggers.push_back(new TriggerNode(
        "enemy too close for spell",
        NextAction::array(0, new NextAction("wing clip", 50.0f), new NextAction("flee",49.0f), new NextAction("concussive shot", 48.0f), NULL)));

     triggers.push_back(new TriggerNode(
        "almost full health",
        NextAction::array(0, new NextAction("freezing trap", 50), NULL)));

    triggers.push_back(new TriggerNode(
        "boost",
        NextAction::array(0, new NextAction("rapid fire", 50), new NextAction("bestial wrath", 50), NULL)));

    triggers.push_back(new TriggerNode(
        "critical health",
        NextAction::array(0, new NextAction("deterrence", 70), NULL)));

    triggers.push_back(new TriggerNode(
        "medium threat",
        NextAction::array(0, new NextAction("misdirection", 52.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "have aggro",
        NextAction::array(0, new NextAction("feign death", 70.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "hunters pet low health",
        NextAction::array(0, new NextAction("mend pet", 60.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "rapid fire",
        NextAction::array(0, new NextAction("rapid fire", 55.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "silencing shot on enemy healer",
        NextAction::array(0, new NextAction("silencing shot on enemy healer", 40.0f), NULL)));

     triggers.push_back(new TriggerNode(
        "wyvern sting",
        NextAction::array(0, new NextAction("wyvern sting", 30.0f), NULL)));
}
