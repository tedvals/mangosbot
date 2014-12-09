#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "ShamanMultipliers.h"
#include "HealShamanStrategy.h"

using namespace ai;

class GenericShamanStrategyActionNodeFactory : public NamedObjectFactory<ActionNode>
{
public:
    GenericShamanStrategyActionNodeFactory()
    {
        creators["flametongue weapon"] = &flametongue_weapon;
        creators["frostbrand weapon"] = &frostbrand_weapon;
        creators["windfury weapon"] = &windfury_weapon;
        creators["lesser healing wave"] = &lesser_healing_wave;
        creators["lesser healing wave on party"] = &lesser_healing_wave_on_party;
        creators["earth shock"] = &earth_shock;
        creators["frost shock"] = &frost_shock;
        creators["strength of earth totem"] = &strength_earth_totem;
        creators["stoneskin totem"] = &stoneskin_totem;
        creators["totem of wrath totem"] = &wrath_totem;
        creators["flametongue totem"] = &flametongue_totem;
        creators["mana spring totem"] = &mana_spring_totem;
        creators["wrath of air totem"] = &wrath_air_totem;
        creators["grace of air totem"] = &grace_air_totem;
        creators["boost"] = &bloodlust;
        creators["bloodlust"] = &bloodlust;
        creators["heroism"] = &bloodlust;
        creators["stoneclaw totem"] = &stoneclaw_totem;
        creators["earth elemental totem"] = &earth_elemental_totem;
    }
private:

    static ActionNode* earth_shock(PlayerbotAI* ai)
    {
        return new ActionNode ("earth shock",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("flame shock"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* frost_shock(PlayerbotAI* ai)
    {
        return new ActionNode ("frost shock",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("earthbind totem"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* flametongue_weapon(PlayerbotAI* ai)
    {
        return new ActionNode ("flametongue weapon",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("frostbrand weapon"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* frostbrand_weapon(PlayerbotAI* ai)
    {
        return new ActionNode ("frostbrand weapon",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("rockbiter weapon"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* windfury_weapon(PlayerbotAI* ai)
    {
        return new ActionNode ("windfury weapon",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("rockbiter weapon"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* lesser_healing_wave(PlayerbotAI* ai)
    {
        return new ActionNode ("lesser healing wave",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("healing wave"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* lesser_healing_wave_on_party(PlayerbotAI* ai)
    {
        return new ActionNode ("lesser healing wave on party",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("healing wave on party"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* strength_earth_totem(PlayerbotAI* ai)
    {
        return new ActionNode ("strength of earth totem",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("stoneskin totem"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* stoneskin_totem(PlayerbotAI* ai)
    {
        return new ActionNode ("stoneskin totem",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("tremor totem"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* wrath_totem(PlayerbotAI* ai)
    {
        return new ActionNode ("totem of wrath",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("flametongue totem"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* flametongue_totem(PlayerbotAI* ai)
    {
        return new ActionNode ("flametongue totem",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("searing totem"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* mana_spring_totem(PlayerbotAI* ai)
    {
        return new ActionNode ("mana spring totem",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("healing stream totem"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* wrath_air_totem(PlayerbotAI* ai)
    {
        return new ActionNode ("wrath of air totem",
            /*P*/ NULL,
            /*A*/ NULL,
            /*C*/ NULL);
    }
    static ActionNode* grace_air_totem(PlayerbotAI* ai)
    {
        return new ActionNode ("grace of air totem",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("windfury totem"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* bloodlust(PlayerbotAI* ai)
    {
        return new ActionNode ("bloodlust",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("heroism"), NULL),
            /*C*/ NextAction::array(0, new NextAction("fire elemental"), NULL));
    }
    static ActionNode* heroism(PlayerbotAI* ai)
    {
        return new ActionNode ("heroism",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("bloodlust"), NULL),
            /*C*/ NextAction::array(0, new NextAction("fire elemental"), NULL));
    }
    static ActionNode* stoneclaw_totem(PlayerbotAI* ai)
    {
        return new ActionNode ("stoneclaw totem",
            /*P*/ NULL,
            /*A*/ NULL,
            /*C*/ NULL);
    }
    static ActionNode* earth_elemental_totem(PlayerbotAI* ai)
    {
        return new ActionNode ("earth elemental totem",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("stoneclaw totem"), NULL),
            /*C*/ NULL);
    }
};

GenericShamanStrategy::GenericShamanStrategy(PlayerbotAI* ai) : CombatStrategy(ai)
{
    actionNodeFactories.Add(new GenericShamanStrategyActionNodeFactory());
}

void GenericShamanStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    CombatStrategy::InitTriggers(triggers);

    triggers.push_back(new TriggerNode(
        "wind shear",
        NextAction::array(0, new NextAction("wind shear", 23.0f), NULL)));

     triggers.push_back(new TriggerNode(
        "target fleeing",
        NextAction::array(0, new NextAction("frost shock", 30.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "wind shear on enemy healer",
        NextAction::array(0, new NextAction("wind shear on enemy healer", 23.0f), NULL)));

	triggers.push_back(new TriggerNode(
        "purge",
		NextAction::array(0, new NextAction("purge", 10.0f), NULL)));

    triggers.push_back(new TriggerNode(
		"critical health",
		NextAction::array(0, new NextAction("stoneclaw totem", 80.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "party member charmed",
        NextAction::array(0, new NextAction("tremor totem", 60.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "party member feared",
        NextAction::array(0, new NextAction("tremor totem", 60.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "party member possessed",
        NextAction::array(0, new NextAction("tremor totem", 55.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "hex",
        NextAction::array(0, new NextAction("hex", 30.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "has aggro",
        NextAction::array(0, new NextAction("earth elemental totem", 60.0f), NULL)));

	triggers.push_back(new TriggerNode(
        "party member low health",
		NextAction::array(0, new NextAction("lesser healing wave on party", 25.0f), NULL)));

	triggers.push_back(new TriggerNode(
		"heroism",
		NextAction::array(0, new NextAction("heroism", 31.0f), NULL)));

	triggers.push_back(new TriggerNode(
		"bloodlust",
		NextAction::array(0, new NextAction("bloodlust", 30.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "not facing target",
        NextAction::array(0, new NextAction("set facing", ACTION_NORMAL + 7), NULL)));
}

void ShamanBuffDpsStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    triggers.push_back(new TriggerNode(
        "lightning shield",
        NextAction::array(0, new NextAction("lightning shield", 22.0f), NULL)));
}

void ShamanBuffManaStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    triggers.push_back(new TriggerNode(
        "water shield",
        NextAction::array(0, new NextAction("water shield", 22.0f), NULL)));
}
