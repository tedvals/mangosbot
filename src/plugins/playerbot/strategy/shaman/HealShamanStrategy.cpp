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
        creators["earthliving weapon"] = &earthliving_weapon;
        creators["mana tide totem"] = &mana_tide_totem;
        creators["chain heal"] = &chain_heal;
        creators["riptide"] = &riptide;
        creators["chain heal on party"] = &chain_heal_on_party;
        creators["riptide on party"] = &riptide_on_party;
        creators["nature's swiftness"] = &natures_swiftness;
    }
private:
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
    static ActionNode* riptide_on_party(PlayerbotAI* ai)
    {
        return new ActionNode ("riptide on party",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("chain heal on party"), NULL),
            /*C*/ NULL);
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
		"medium aoe heal",
		NextAction::array(0, new NextAction("chain heal", 27.0f), NULL)));

	triggers.push_back(new TriggerNode(
		"medium health",
		NextAction::array(0, new NextAction("healing wave", 26.0f), NULL)));

    triggers.push_back(new TriggerNode(
		"low health",
		NextAction::array(0, new NextAction("riptide", ACTION_EMERGENCY), NULL)));

    triggers.push_back(new TriggerNode(
        "party member low health",
		NextAction::array(0, new NextAction("riptide on party", ACTION_EMERGENCY), NULL)));

    triggers.push_back(new TriggerNode(
        "party member medium health",
		NextAction::array(0, new NextAction("healing wave on party", 25.0f), NULL)));

	//triggers.push_back(new TriggerNode(
	//	"almost full health",
	//	NextAction::array(0, new NextAction("earth shield", 26.0f), NULL)));

    triggers.push_back(new TriggerNode(
		"critical health",
		NextAction::array(0, new NextAction("nature's swiftness", ACTION_EMERGENCY + 8), NULL)));

    triggers.push_back(new TriggerNode(
        "enemy out of spell",
        NextAction::array(0, new NextAction("reach spell", ACTION_NORMAL + 9), NULL)));

    triggers.push_back(new TriggerNode(
        "shaman weapon",
        NextAction::array(0, new NextAction("earthliving weapon", 22.0f), NULL)));

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
