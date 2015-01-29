#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "GenericDruidStrategy.h"
#include "DruidAiObjectContext.h"

using namespace ai;

class GenericDruidStrategyActionNodeFactory : public NamedObjectFactory<ActionNode>
{
public:
    GenericDruidStrategyActionNodeFactory()
    {
        creators["melee"] = &melee;
        creators["caster form"] = &caster_form;
        creators["cure poison"] = &cure_poison;
        creators["cure poison on party"] = &cure_poison_on_party;
        creators["abolish poison"] = &abolish_poison;
        creators["abolish poison on party"] = &abolish_poison_on_party;
        creators["instant regrowth"] = &instant_regrowth;
        creators["instant regrowth on party"] = &instant_regrowth_on_party;
        creators["instant regrowth on master"] = &instant_regrowth_on_master;
        creators["instant healing touch"] = &instant_healing_touch;
        creators["instant healing touch on party"] = &instant_healing_touch_on_party;
        creators["instant healing touch on master"] = &instant_healing_touch_on_master;
        creators["rebirth"] = &rebirth;
        creators["entangling roots on cc"] = &entangling_roots_on_cc;
        creators["hibernate"] = &hibernate;
        creators["hibernate on cc"] = &hibernate_on_cc;
        creators["innervate"] = &innervate;
        creators["dash"] = &dash;
    }

private:
    static ActionNode* melee(PlayerbotAI* ai)
    {
        return new ActionNode ("melee",
            /*P*/ NextAction::array(0, new NextAction("reach melee"), NULL),
            /*A*/ NULL,
            /*C*/ NULL);
    }
    static ActionNode* caster_form(PlayerbotAI* ai)
    {
        return new ActionNode ("caster form",
            /*P*/ NULL,
            /*A*/ NULL,
            /*C*/ NULL);
    }
    static ActionNode* cure_poison(PlayerbotAI* ai)
    {
        return new ActionNode ("cure poison",
            /*P*/ NULL,
            /*A*/ NULL,
            /*C*/ NULL);
    }
    static ActionNode* cure_poison_on_party(PlayerbotAI* ai)
    {
        return new ActionNode ("cure poison on party",
            /*P*/ NULL,
            /*A*/ NULL,
            /*C*/ NULL);
    }
    static ActionNode* abolish_poison(PlayerbotAI* ai)
    {
        return new ActionNode ("abolish poison",
            /*P*/ NULL,
            /*A*/ NULL,
            /*C*/ NULL);
    }
    static ActionNode* abolish_poison_on_party(PlayerbotAI* ai)
    {
        return new ActionNode ("abolish poison on party",
            /*P*/ NULL,
            /*A*/ NULL,
            /*C*/ NULL);
    }
    static ActionNode* instant_regrowth(PlayerbotAI* ai)
    {
        return new ActionNode ("instant regrowth",
            /*P*/ NextAction::array(0, new NextAction("caster form"), NULL),
            /*A*/ NextAction::array(0, new NextAction("rejuvenation"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* instant_regrowth_on_party(PlayerbotAI* ai)
    {
        return new ActionNode ("instant regrowth on party",
            /*P*/ NextAction::array(0, new NextAction("caster form"), NULL),
            /*A*/ NextAction::array(0, new NextAction("rejuvenation on party"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* instant_regrowth_on_master(PlayerbotAI* ai)
    {
        return new ActionNode ("instant regrowth on master",
            /*P*/ NextAction::array(0, new NextAction("caster form"), NULL),
            /*A*/ NextAction::array(0, new NextAction("rejuvenation on master"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* instant_healing_touch(PlayerbotAI* ai)
    {
        return new ActionNode ("instant healing touch",
            /*P*/ NextAction::array(0, new NextAction("caster form"), NULL),
            /*A*/ NextAction::array(0, new NextAction("healing touch"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* instant_healing_touch_on_party(PlayerbotAI* ai)
    {
        return new ActionNode ("instant healing touch on party",
            /*P*/ NextAction::array(0, new NextAction("caster form"), NULL),
            /*A*/ NextAction::array(0, new NextAction("healing touch on party"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* instant_healing_touch_on_master(PlayerbotAI* ai)
    {
        return new ActionNode ("instant healing touch on master",
            /*P*/ NextAction::array(0, new NextAction("caster form"), NULL),
            /*A*/ NextAction::array(0, new NextAction("healing touch on master"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* rebirth(PlayerbotAI* ai)
    {
        return new ActionNode ("rebirth",
            /*P*/ NextAction::array(0, new NextAction("caster form"), NULL),
            /*A*/ NULL,
            /*C*/ NULL);
    }
    static ActionNode* entangling_roots_on_cc(PlayerbotAI* ai)
    {
        return new ActionNode ("entangling roots on cc",
            /*P*/ NextAction::array(0, new NextAction("caster form"), NULL),
            /*A*/ NULL,
            /*C*/ NULL);
    }
    static ActionNode* hibernate(PlayerbotAI* ai)
    {
        return new ActionNode ("hibernate",
            /*P*/ NextAction::array(0, new NextAction("caster form"), NULL),
            /*A*/ NULL,
            /*C*/ NULL);
    }
    static ActionNode* hibernate_on_cc(PlayerbotAI* ai)
    {
        return new ActionNode ("hibernate on cc",
            /*P*/ NextAction::array(0, new NextAction("caster form"), NULL),
            /*A*/ NULL,
            /*C*/ NULL);
    }
    static ActionNode* innervate(PlayerbotAI* ai)
    {
        return new ActionNode ("innervate",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("mana potion"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* dash(PlayerbotAI* ai)
    {
        return new ActionNode ("dash",
            /*P*/ NextAction::array(0, new NextAction("cat form")),
            /*A*/ NULL,
            /*C*/ NULL);
    }
};

GenericDruidStrategy::GenericDruidStrategy(PlayerbotAI* ai) : CombatStrategy(ai)
{
    actionNodeFactories.Add(new GenericDruidStrategyActionNodeFactory());
}

void GenericDruidStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    CombatStrategy::InitTriggers(triggers);

    triggers.push_back(new TriggerNode(
        "low health",
        NextAction::array(0, new NextAction("instant regrowth", ACTION_MEDIUM_HEAL + 2), NULL)));

    triggers.push_back(new TriggerNode(
        "party member low health",
        NextAction::array(0, new NextAction("instant regrowth on party", ACTION_MEDIUM_HEAL + 1), NULL)));

    triggers.push_back(new TriggerNode(
        "master low health",
        NextAction::array(0, new NextAction("instant regrowth on master", ACTION_MEDIUM_HEAL + 7), NULL)));

    triggers.push_back(new TriggerNode(
        "critical health",
        NextAction::array(0, new NextAction("regrowth", ACTION_CRITICAL_HEAL + 3), NULL)));

    triggers.push_back(new TriggerNode(
        "party member critical health",
        NextAction::array(0,  new NextAction("regrowth on party", ACTION_CRITICAL_HEAL + 4), new NextAction("rejuvenation on party", ACTION_CRITICAL_HEAL + 3), NULL)));

    triggers.push_back(new TriggerNode(
        "master critical health",
        NextAction::array(0,  new NextAction("regrowth on master", ACTION_CRITICAL_HEAL + 4), new NextAction("rejuvenation on master", ACTION_CRITICAL_HEAL + 3), NULL)));

    triggers.push_back(new TriggerNode(
        "cure poison",
        NextAction::array(0, new NextAction("abolish poison", ACTION_DISPEL + 2), NULL)));

    triggers.push_back(new TriggerNode(
        "party member cure poison",
        NextAction::array(0, new NextAction("abolish poison on party", ACTION_DISPEL + 1), NULL)));

	triggers.push_back(new TriggerNode(
		"party member dead",
		NextAction::array(0, new NextAction("rebirth", ACTION_HIGH + 1), NULL)));

    triggers.push_back(new TriggerNode(
        "low mana",
        NextAction::array(0, new NextAction("innervate", ACTION_EMERGENCY + 5), NULL)));

    triggers.push_back(new TriggerNode(
        "critical aoe heal",
        NextAction::array(0, new NextAction("barkskin", ACTION_EMERGENCY + 5), new NextAction("tranquility", ACTION_EMERGENCY + 4), NULL)));

    triggers.push_back(new TriggerNode(
        "hibernate",
        NextAction::array(0, new NextAction("hibernate on cc", ACTION_HIGH + 2), NULL)));

    triggers.push_back(new TriggerNode(
        "runaway",
        NextAction::array(0, new NextAction("cat form", ACTION_EMERGENCY + 7), new NextAction("dash", ACTION_EMERGENCY + 8), NULL)));
}
