#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "ShamanMultipliers.h"
#include "HealShamanStrategy.h"

using namespace ai;

class HealShamanStrategyActionNodeFactory : public NamedObjectFactory<ActionNode>
{
public:
    HealShamanStrategyActionNodeFactory()
    {
        creators["flame shock"] = &flame_shock;
        creators["earth shock"] = &earth_shock;
        creators["earthliving weapon"] = &earthliving_weapon;
        creators["mana tide totem"] = &mana_tide_totem;
        creators["chain heal"] = &chain_heal;
        creators["riptide"] = &riptide;
        creators["chain heal on party"] = &chain_heal_on_party;
        creators["riptide on party"] = &riptide_on_party;
        creators["tidal force"] = &tidal_force;
        creators["nature's swiftness"] = &natures_swiftness;
        creators["lesser healing wave"] = &lesser_healing_wave;
        creators["lesser healing wave on party"] = &lesser_healing_wave_on_party;
    }
private:
     static ActionNode* flame_shock(PlayerbotAI* ai)
    {
        return new ActionNode ("flame shock",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("earth shock"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* earth_shock(PlayerbotAI* ai)
    {
        return new ActionNode ("earth shock",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("reach spell"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* earthliving_weapon(PlayerbotAI* ai)
    {
        return new ActionNode ("earthliving weapon",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("flametongue weapon"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* mana_tide_totem(PlayerbotAI* ai)
    {
        return new ActionNode ("mana tide totem",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("mana potion"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* chain_heal(PlayerbotAI* ai)
    {
        return new ActionNode ("chain heal",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("lesser healing wave"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* riptide(PlayerbotAI* ai)
    {
        return new ActionNode ("riptide",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("chain heal"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* chain_heal_on_party(PlayerbotAI* ai)
    {
        return new ActionNode ("chain heal on party",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("lesser healing wave on party"), NULL),
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
    static ActionNode* riptide_on_party(PlayerbotAI* ai)
    {
        return new ActionNode ("riptide on party",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("chain heal on party"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* tidal_force(PlayerbotAI* ai)
    {
        return new ActionNode ("tidal force",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("nature's swiftness"), NULL),
            /*C*/ NextAction::array(0, new NextAction("lesser healing wave"), NULL));
    }
    static ActionNode* natures_swiftness(PlayerbotAI* ai)
    {
        return new ActionNode ("nature's swiftness",
            /*P*/ NULL,
            /*A*/ NULL,
            /*C*/ NextAction::array(0, new NextAction("healing wave"), NULL));
    }
};

HealShamanStrategy::HealShamanStrategy(PlayerbotAI* ai) : GenericShamanStrategy(ai)
{
    actionNodeFactories.Add(new HealShamanStrategyActionNodeFactory());
}

void HealShamanStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    GenericShamanStrategy::InitTriggers(triggers);

      triggers.push_back(new TriggerNode(
        "shaman weapon",
        NextAction::array(0, new NextAction("earthliving weapon", 23.0f), NULL)));

      triggers.push_back(new TriggerNode(
        "mainhand not enhanced",
        NextAction::array(0, new NextAction("earthliving weapon", 23.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "shock",
        NextAction::array(0, new NextAction("flame shock", 20.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "earth shield on master",
        NextAction::array(0, new NextAction("earth shield on master", 40.0f), NULL)));

	triggers.push_back(new TriggerNode(
		"medium aoe heal",
		NextAction::array(0, new NextAction("chain heal", ACTION_NORMAL + 7), NULL)));

	triggers.push_back(new TriggerNode(
		"low health",
		NextAction::array(0, new NextAction("healing wave", ACTION_NORMAL + 8), NULL)));

    triggers.push_back(new TriggerNode(
		"medium health",
		NextAction::array(0, new NextAction("chain heal", ACTION_NORMAL + 5), NULL)));

    triggers.push_back(new TriggerNode(
        "party member medium health",
		NextAction::array(0, new NextAction("chain heal", ACTION_NORMAL + 6), NULL)));

    triggers.push_back(new TriggerNode(
		"almost full health",
		NextAction::array(0, new NextAction("riptide", ACTION_NORMAL + 1), NULL)));

    triggers.push_back(new TriggerNode(
        "party member almost full health",
		NextAction::array(0, new NextAction("riptide on party", ACTION_NORMAL), NULL)));

    triggers.push_back(new TriggerNode(
        "party member low health",
		NextAction::array(0, new NextAction("healing wave on party", ACTION_HIGH + 3), NULL)));

	triggers.push_back(new TriggerNode(
		"have aggro",
		NextAction::array(0, new NextAction("earth shield", ACTION_HIGH + 6), NULL)));

    triggers.push_back(new TriggerNode(
		"almost dead",
		NextAction::array(0, new NextAction("nature's swiftness", ACTION_EMERGENCY + 10), new NextAction("healing wave", ACTION_EMERGENCY + 10), NULL)));

    triggers.push_back(new TriggerNode(
		"critical health",
		NextAction::array(0, new NextAction("tidal force", ACTION_EMERGENCY + 8), new NextAction("low healing wave", ACTION_EMERGENCY + 8),NULL)));

    triggers.push_back(new TriggerNode(
		"party member almost dead",
		NextAction::array(0, new NextAction("nature's swiftness", ACTION_EMERGENCY + 9), new NextAction("healing wave", ACTION_EMERGENCY + 9),NULL)));

    triggers.push_back(new TriggerNode(
		"party member critical health",
		NextAction::array(0, new NextAction("tidal force", ACTION_EMERGENCY + 7), new NextAction("lesser healing wave", ACTION_EMERGENCY + 7), NULL)));

    triggers.push_back(new TriggerNode(
        "low mana",
        NextAction::array(0, new NextAction("mana tide totem", ACTION_EMERGENCY + 5), NULL)));

    triggers.push_back(new TriggerNode(
        "cleanse spirit poison",
        NextAction::array(0, new NextAction("cleanse spirit", 24.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "cleanse spirit curse",
        NextAction::array(0, new NextAction("cleanse spirit", 24.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "cleanse spirit disease",
        NextAction::array(0, new NextAction("cleanse spirit", 24.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "party member cleanse spirit poison",
        NextAction::array(0, new NextAction("cleanse spirit poison on party", 23.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "party member cleanse spirit curse",
        NextAction::array(0, new NextAction("cleanse spirit curse on party", 23.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "party member cleanse spirit disease",
        NextAction::array(0, new NextAction("cleanse spirit disease on party", 23.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "medium aoe",
        NextAction::array(0, new NextAction("healing stream totem", ACTION_LIGHT_HEAL), NULL)));
}
