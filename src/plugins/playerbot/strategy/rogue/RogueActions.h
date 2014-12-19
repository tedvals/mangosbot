#pragma once

#include "../actions/GenericActions.h"
#include "../actions/UseItemAction.h"
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

    class UseInstantPoisonMainhandAction : public UseItemAction
    {
    public:
        UseInstantPoisonMainhandAction(PlayerbotAI* ai) : UseItemAction(ai, "instant poison mainhand") {setTargetMainhand();}
    };

    class UseInstantPoisonOffhandAction : public UseItemAction
    {
    public:
        UseInstantPoisonOffhandAction(PlayerbotAI* ai) : UseItemAction(ai, "instant poison offhand") {setTargetOffhand();}
    };

    class UseDeadlyPoisonMainhandAction : public UseItemAction
    {
    public:
        UseDeadlyPoisonMainhandAction(PlayerbotAI* ai) : UseItemAction(ai, "deadly poison mainhand") {setTargetMainhand();}
    };

    class UseDeadlyPoisonOffhandAction : public UseItemAction
    {
    public:
        UseDeadlyPoisonOffhandAction(PlayerbotAI* ai) : UseItemAction(ai, "deadly poison offhand") {setTargetOffhand();}
    };

    class UseWoundPoisonMainhandAction : public UseItemAction
    {
    public:
        UseWoundPoisonMainhandAction(PlayerbotAI* ai) : UseItemAction(ai, "wound poison mainhand") {setTargetMainhand();}
    };

    class UseWoundPoisonOffhandAction : public UseItemAction
    {
    public:
        UseWoundPoisonOffhandAction(PlayerbotAI* ai) : UseItemAction(ai, "wound poison offhand") {setTargetOffhand();}
    };

    class UseCripplingPoisonMainhandAction : public UseItemAction
    {
    public:
        UseCripplingPoisonMainhandAction(PlayerbotAI* ai) : UseItemAction(ai, "crippling poison mainhand") {setTargetMainhand();}
    };

    class UseCripplingPoisonOffhandAction : public UseItemAction
    {
    public:
        UseCripplingPoisonOffhandAction(PlayerbotAI* ai) : UseItemAction(ai, "crippling poison offhand") {setTargetOffhand();}
    };

    class UseMindNumbingPoisonMainhandAction : public UseItemAction
    {
    public:
        UseMindNumbingPoisonMainhandAction(PlayerbotAI* ai) : UseItemAction(ai, "mind-numbing poison mainhand") {setTargetMainhand();}
    };

    class UseMindNumbingPoisonOffhandAction : public UseItemAction
    {
    public:
        UseMindNumbingPoisonOffhandAction(PlayerbotAI* ai) : UseItemAction(ai, "mind-numbing poison offhand") {setTargetOffhand();}
    };

}
