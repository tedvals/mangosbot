#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "DruidMultipliers.h"
#include "CatDpsDruidStrategy.h"

using namespace ai;

class CatDpsDruidStrategyActionNodeFactory : public NamedObjectFactory<ActionNode>
{
public:
    CatDpsDruidStrategyActionNodeFactory()
    {
        creators["dire bear form"] = &dire_bear_form;
        creators["melee"] = &melee;
        creators["feral charge - cat"] = &feral_charge_cat;
        creators["pounce"] = &pounce;
        creators["cat form"] = &cat_form;
        creators["faerie fire (feral)"] = &faerie_fire_feral;
        creators["shred"] = &shred;
        creators["mangle (cat)"] = &mangle_cat;
        creators["shred"] = &shred;
        creators["claw"] = &claw;
        creators["rake"] = &rake;
        creators["savage roar"] = &savageroar;
        creators["ferocious bite"] = &ferocious_bite;
        creators["rip"] = &rip;
        creators["boost"] = &berserk;
        creators["berserk"] = &berserk;
    }
private:
    static ActionNode* dire_bear_form(PlayerbotAI* ai)
    {
        return new ActionNode ("dire bear form",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("bear form"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* pounce(PlayerbotAI* ai)
    {
        return new ActionNode ("pounce",
            /*P*/ NextAction::array(0, new NextAction("prowl"), NULL),
            /*A*/ NULL,
            /*C*/ NULL);
    }
    static ActionNode* melee(PlayerbotAI* ai)
    {
        return new ActionNode ("melee",
            /*P*/ NextAction::array(0, new NextAction("cat form")),
            /*A*/ NextAction::array(0, new NextAction("feral charge - cat"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* hibernate(PlayerbotAI* ai)
    {
        return new ActionNode ("hibernate",
            /*P*/ NextAction::array(0, new NextAction("moonkin form"), NULL),
            /*A*/ NULL,
            /*C*/ NULL);
    }
    static ActionNode* hibernate_on_cc(PlayerbotAI* ai)
    {
        return new ActionNode ("hibernate on cc",
            /*P*/ NextAction::array(0, new NextAction("moonkin form"), NULL),
            /*A*/ NULL,
            /*C*/ NULL);
    }
    static ActionNode* feral_charge_cat(PlayerbotAI* ai)
    {
        return new ActionNode ("feral charge - cat",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("reach melee"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* faerie_fire_feral(PlayerbotAI* ai)
    {
        return new ActionNode ("faerie fire (feral)",
            /*P*/ NULL,
            /*A*/ NULL,
            /*C*/ NULL);
    }
    static ActionNode* cat_form(PlayerbotAI* ai)
    {
        return new ActionNode ("cat form",
            /*P*/ NULL,
            /*A*/ NULL,
            /*C*/ NextAction::array(0, new NextAction("prowl"), NULL));
    }
    static ActionNode* shred(PlayerbotAI* ai)
    {
        return new ActionNode ("shred",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("mangle (cat)"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* mangle_cat(PlayerbotAI* ai)
    {
        return new ActionNode ("mangle (cat)",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("claw"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* claw(PlayerbotAI* ai)
    {
        return new ActionNode ("claw",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("melee"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* rake(PlayerbotAI* ai)
    {
        return new ActionNode ("rake",
            /*P*/ NULL,
            /*A*/ NULL,
            /*C*/ NextAction::array(0, new NextAction("mangle (cat)"), NULL));
    }
    static ActionNode* savageroar(PlayerbotAI* ai)
    {
        return new ActionNode ("savage roar",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("rip"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* ferocious_bite(PlayerbotAI* ai)
    {
        return new ActionNode ("ferocious bite",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("rip"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* rip(PlayerbotAI* ai)
    {
        return new ActionNode ("rip",
            /*P*/ NULL,
            /*A*/ NULL,
            /*C*/ NULL);
    }
    static ActionNode* berserk(PlayerbotAI* ai)
    {
        return new ActionNode ("berserk",
            /*P*/ NULL,
            /*A*/ NULL,
            /*C*/ NULL);
    }
};

CatDpsDruidStrategy::CatDpsDruidStrategy(PlayerbotAI* ai) : FeralDruidStrategy(ai)
{
    actionNodeFactories.Add(new CatDpsDruidStrategyActionNodeFactory());
}

NextAction** CatDpsDruidStrategy::getDefaultActions()
{
    return NextAction::array(0, new NextAction("shred", ACTION_NORMAL), NULL);
}

void CatDpsDruidStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    FeralDruidStrategy::InitTriggers(triggers);

    triggers.push_back(new TriggerNode(
        "enemy out of melee",
        NextAction::array(0, new NextAction("feral charge - cat", ACTION_NORMAL + 9), NULL)));

     triggers.push_back(new TriggerNode(
        "enemy too close for melee",
        NextAction::array(0, new NextAction("move out of enemy contact", ACTION_NORMAL + 8), NULL)));

    triggers.push_back(new TriggerNode(
        "not facing target",
        NextAction::array(0, new NextAction("set facing",  ACTION_EMERGENCY + 2), NULL)));

    triggers.push_back(new TriggerNode(
        "cat form",
        NextAction::array(0, new NextAction("cat form", ACTION_MOVE + 10), NULL)));

     triggers.push_back(new TriggerNode(
        "rooted",
        NextAction::array(0, new NextAction("cat form", ACTION_MOVE + 10), NULL)));

    triggers.push_back(new TriggerNode(
        "prowl",
        NextAction::array(0, new NextAction("prowl", ACTION_EMERGENCY + 2), NULL)));

    triggers.push_back(new TriggerNode(
        "pounce",
        NextAction::array(0, new NextAction("pounce",  ACTION_EMERGENCY + 1), NULL)));

    triggers.push_back(new TriggerNode(
        "mangle(cat)",
        NextAction::array(0, new NextAction("mangle(cat)", ACTION_NORMAL + 6), NULL)));

    triggers.push_back(new TriggerNode(
        "rake",
        NextAction::array(0, new NextAction("rake", ACTION_NORMAL + 5), NULL)));

    triggers.push_back(new TriggerNode(
        "combo point available",
        NextAction::array(0, new NextAction("savage roar", ACTION_NORMAL + 9), NULL)));

    triggers.push_back(new TriggerNode(
        "combo points available",
        NextAction::array(0, new NextAction("rip", ACTION_NORMAL + 7), NULL)));

    triggers.push_back(new TriggerNode(
        "medium threat",
        NextAction::array(0, new NextAction("cower", ACTION_EMERGENCY + 1), NULL)));

    triggers.push_back(new TriggerNode(
        "has aggro",
        NextAction::array(0, new NextAction("dire bear form", ACTION_EMERGENCY + 1), new NextAction("barkskin", ACTION_EMERGENCY + 1), NULL)));

    triggers.push_back(new TriggerNode(
        "faerie fire (feral)",
        NextAction::array(0, new NextAction("faerie fire (feral)", ACTION_HIGH + 1), NULL)));

    triggers.push_back(new TriggerNode(
        "behind target",
        NextAction::array(0, new NextAction("shred", ACTION_NORMAL), NULL)));

	triggers.push_back(new TriggerNode(
		"tiger's fury",
		NextAction::array(0, new NextAction("tiger's fury", ACTION_EMERGENCY + 1), NULL)));

    triggers.push_back(new TriggerNode(
        "entangling roots",
        NextAction::array(0, new NextAction("entangling roots on cc", ACTION_HIGH + 1), NULL)));

}

void CatAoeDruidStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    triggers.push_back(new TriggerNode(
        "medium aoe",
        NextAction::array(0, new NextAction("swipe (cat)", ACTION_HIGH + 2), NULL)));
}

