#pragma once

#include "../actions/GenericActions.h"
#include "RogueComboActions.h"
#include "RogueOpeningActions.h"
#include "RogueFinishingActions.h"

namespace ai
{
	class CastStealthAction : public CastBuffSpellAction
	{
	public:
		CastStealthAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "stealth") {}
	};

	class CastEvasionAction : public CastBuffSpellAction
	{
	public:
		CastEvasionAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "evasion") {}
	};

	class CastSprintAction : public CastBuffSpellAction
	{
	public:
		CastSprintAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "sprint") {}
	};

	class CastPremeditationAction : public CastBuffSpellAction
	{
	public:
		CastPremeditationAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "premeditation") {}
	};

	class CastPreparationAction : public CastBuffSpellAction
	{
	public:
		CastPreparationAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "preparation") {}
	};

	class CastKickAction : public CastSpellAction
	{
	public:
		CastKickAction(PlayerbotAI* ai) : CastSpellAction(ai, "kick") {}
	};

	class CastFeintAction : public CastBuffSpellAction
	{
	public:
		CastFeintAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "feint") {}
	};

	class CastDismantleAction : public CastSpellAction
	{
	public:
		CastDismantleAction(PlayerbotAI* ai) : CastSpellAction(ai, "dismantle") {}
	};

	class CastDistractAction : public CastSpellAction
	{
	public:
		CastDistractAction(PlayerbotAI* ai) : CastSpellAction(ai, "distract") {}
	};

	class CastVanishAction : public CastBuffSpellAction
	{
	public:
		CastVanishAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "vanish") {}
	};

	class CastCloakOfShadowsAction : public CastBuffSpellAction
	{
	public:
		CastCloakOfShadowsAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "cloak of shadows") {}
	};

	class CastTricksOfTradeOnPartyAction : public  BuffOnPartyAction
	{
	public:
		CastTricksOfTradeOnPartyAction(PlayerbotAI* ai) :  BuffOnPartyAction(ai, "tricks of trade") {}
	};

	class CastBlindAction : public CastDebuffSpellAction
	{
	public:
		CastBlindAction(PlayerbotAI* ai) : CastDebuffSpellAction(ai, "blind") {}
	};

    class CastShadowstepAction : public CastReachTargetSpellAction
	{
	public:
		CastShadowstepAction(PlayerbotAI* ai) : CastReachTargetSpellAction(ai, "shadowstep", 1.5f) {}
	};

    class CastColdBloodAction : public CastBuffSpellAction
	{
	public:
		CastColdBloodAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "cold blood") {}
	};

    class CastHungerForBloodAction : public CastBuffSpellAction
	{
	public:
		CastHungerForBloodAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "hunger for blood") {}
	};

	class CastBladeFlurryAction : public CastBuffSpellAction
	{
	public:
		CastBladeFlurryAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "blade flurry") {}
	};

	class CastAdrenalineRushAction : public CastBuffSpellAction
	{
	public:
		CastAdrenalineRushAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "adrenaline rush") {}
		virtual NextAction** getAlternatives();
	};

	class CastBurstAction : public CastBuffSpellAction
	{
	public:
		CastBurstAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "killing spree") {}
		virtual NextAction** getAlternatives();
	};

	class CastKillingSpreeAction : public CastBuffSpellAction
	{
	public:
		CastKillingSpreeAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "killing spree") {}
	};

    class CastShadowDanceAction : public CastBuffSpellAction
	{
	public:
		CastShadowDanceAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "shadow dance") {}
		virtual NextAction** getAlternatives();
	};

    class CastKickOnEnemyHealerAction : public CastSpellOnEnemyHealerAction
    {
    public:
        CastKickOnEnemyHealerAction(PlayerbotAI* ai) : CastSpellOnEnemyHealerAction(ai, "kick") {}
    };

    class CastInstantPoisonAction : public CastEnchantItemAction {
    public:
        CastInstantPoisonAction(PlayerbotAI* ai) : CastEnchantItemAction(ai, "instant poison") {}
    };

    class CastWoundPoisonAction : public CastEnchantItemAction {
    public:
        CastWoundPoisonAction(PlayerbotAI* ai) : CastEnchantItemAction(ai, "wound poison") {}
    };

    class CastMindNumbingPoisonAction : public CastEnchantItemAction {
    public:
        CastMindNumbingPoisonAction(PlayerbotAI* ai) : CastEnchantItemAction(ai, "mind-numbing poison") {}
    };

    class CastCripplingPoisonAction : public CastEnchantItemAction {
    public:
        CastCripplingPoisonAction(PlayerbotAI* ai) : CastEnchantItemAction(ai, "crippling poison") {}
    };

    class CastDeadlyPoisonAction : public CastEnchantItemAction {
    public:
        CastDeadlyPoisonAction(PlayerbotAI* ai) : CastEnchantItemAction(ai, "deadly poison") {}
    };

}
