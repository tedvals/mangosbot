#pragma once

#include "../actions/GenericActions.h"

namespace ai
{
    BEGIN_RANGED_SPELL_ACTION(CastHuntersMarkAction, "hunter's mark")
    END_SPELL_ACTION()

    BEGIN_RANGED_SPELL_ACTION(CastAutoShotAction, "auto shot")
    END_SPELL_ACTION()

    BEGIN_RANGED_SPELL_ACTION(CastArcaneShotAction, "arcane shot")
    END_SPELL_ACTION()

    BEGIN_RANGED_SPELL_ACTION(CastExplosiveShotAction, "explosive shot")
    END_SPELL_ACTION()

    BEGIN_RANGED_SPELL_ACTION(CastSteadyShotAction, "steady shot")
    END_SPELL_ACTION()

    BEGIN_RANGED_SPELL_ACTION(CastAimedShotAction, "aimed shot")
    END_SPELL_ACTION()

    BEGIN_RANGED_SPELL_ACTION(CastChimeraShotAction, "chimera shot")
    END_SPELL_ACTION()

    BEGIN_RANGED_SPELL_ACTION(CastConcussiveShotAction, "concussive shot")
    END_SPELL_ACTION()

    BEGIN_RANGED_SPELL_ACTION(CastDistractingShotAction, "distracting shot")
    END_SPELL_ACTION()

    BEGIN_RANGED_SPELL_ACTION(CastSilencingShotAction, "silencing shot")
    END_SPELL_ACTION()

    BEGIN_RANGED_SPELL_ACTION(CastMisdirectionAction, "misdirection")
    END_SPELL_ACTION()

    BEGIN_RANGED_SPELL_ACTION(CastMultiShotAction, "multi-shot")
    END_SPELL_ACTION()

	BEGIN_RANGED_SPELL_ACTION(CastVolleyAction, "volley")
	END_SPELL_ACTION()

    BEGIN_RANGED_SPELL_ACTION(CastSerpentStingAction, "serpent sting")
    virtual bool isUseful();
    END_SPELL_ACTION()

    BEGIN_RANGED_SPELL_ACTION(CastWyvernStingAction, "wyvern sting")
    END_SPELL_ACTION()

    class CastWyvernStingCcAction : public CastBuffSpellAction
    {
    public:
        CastWyvernStingCcAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "wyvern sting on cc") {}
        virtual Value<Unit*>* GetTargetValue();
    };

    BEGIN_RANGED_SPELL_ACTION(CastViperStingAction, "viper sting")
    virtual bool isUseful();
    END_SPELL_ACTION()

    BEGIN_RANGED_SPELL_ACTION(CastScorpidStingAction, "scorpid sting")
    END_SPELL_ACTION()

	class CastAspectOfTheHawkAction : public CastBuffSpellAction
	{
	public:
		CastAspectOfTheHawkAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "aspect of the hawk") {}
	};

	class CastAspectOfTheDragonHawkAction : public CastBuffSpellAction
	{
	public:
		CastAspectOfTheDragonHawkAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "aspect of the dragonhawk") {}
	};

	class CastAspectOfTheWildAction : public CastBuffSpellAction
	{
	public:
		CastAspectOfTheWildAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "aspect of the wild") {}
	};

	class CastAspectOfTheCheetahAction : public CastBuffSpellAction
	{
	public:
		CastAspectOfTheCheetahAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "aspect of the cheetah") {}
		virtual bool isUseful();
	};

	class CastAspectOfThePackAction : public CastBuffSpellAction
	{
	public:
		CastAspectOfThePackAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "aspect of the pack") {}
	};

	class CastAspectOfTheViperAction : public CastBuffSpellAction
	{
	public:
		CastAspectOfTheViperAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "aspect of the viper") {}
	};

	class CastAspectOfTheMonkeyAction : public CastBuffSpellAction
	{
	public:
		CastAspectOfTheMonkeyAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "aspect of the monkey") {}
	};

	class CastCallPetAction : public CastBuffSpellAction
	{
	public:
		CastCallPetAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "call pet") {}
	};

	class CastMendPetAction : public CastAuraSpellAction
	{
	public:
		CastMendPetAction(PlayerbotAI* ai) : CastAuraSpellAction(ai, "mend pet") {}
		virtual string GetTargetName() { return "pet target"; }
	};

	class CastRevivePetAction : public CastBuffSpellAction
	{
	public:
		CastRevivePetAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "revive pet") {}
	};

    class CastTrueshotAuraAction : public CastBuffSpellAction
    {
    public:
        CastTrueshotAuraAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "trueshot aura") {}
    };

    class CastFeignDeathAction : public CastBuffSpellAction
    {
    public:
        CastFeignDeathAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "feign death") {}
    };

    class CastDisengageAction : public CastBuffSpellAction
    {
    public:
        CastDisengageAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "disengage") {}
    };

    class CastDeterrenceAction : public CastBuffSpellAction
    {
    public:
        CastDeterrenceAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "deterrence") {}
    };

	class CastRapidFireAction : public CastBuffSpellAction
	{
	public:
		CastRapidFireAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "rapid fire") {}
	};

	class CastReadinessAction : public CastBuffSpellAction
	{
	public:
		CastReadinessAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "readiness") {}
	};

	class CastBestialWrathAction : public CastBuffSpellAction
	{
	public:
		CastBestialWrathAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "bestial wrath") {}
	};

	class CastIntimidationAction : public CastBuffSpellAction
	{
	public:
		CastIntimidationAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "intimidation") {}
	};

	class CastKillCommandAction : public CastBuffSpellAction
	{
	public:
		CastKillCommandAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "kill command") {}
	};

	class CastKillShotAction : public CastBuffSpellAction
	{
	public:
		CastKillShotAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "kill shot") {}
	};

	class CastBlackArrow : public CastDebuffSpellAction
	{
	public:
		CastBlackArrow(PlayerbotAI* ai) : CastDebuffSpellAction(ai, "black arrow") {}
	};

    class CastFreezingTrap : public CastDebuffSpellAction
    {
    public:
        CastFreezingTrap(PlayerbotAI* ai) : CastDebuffSpellAction(ai, "freezing trap") {}
        virtual Value<Unit*>* GetTargetValue();
    };

    class CastWingClipAction : public CastMeleeSpellAction
    {
    public:
        CastWingClipAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "wing clip") {}
        virtual bool isUseful()
        {
           // return CastMeleeSpellAction::isUseful() && !ai->HasAura("wing clip"), GetTarget());
           return CastMeleeSpellAction::isUseful() && !ai->HasAnyAuraOf(GetTarget(), "slow", "wing clip", "frost shock", "crippling poison", "hamstring", NULL);
        }

   //     NextAction** getContinuers()
   //     {
    //        return NextAction::merge( NextAction::array(0, new NextAction("flee"), NULL), CastMeleeSpellAction::getContinuers());
    //    }
    };

  class CastSnakeTrapAction : public CastMeleeSpellAction
    {
    public:
        CastSnakeTrapAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "snake trap") {}
        virtual bool isUseful()
        {
            return CastMeleeSpellAction::isUseful();
        }
    };

    class CastImmolationTrapAction : public CastMeleeSpellAction
    {
    public:
        CastImmolationTrapAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "immolation trap") {}
        virtual bool isUseful()
        {
            return CastMeleeSpellAction::isUseful();
        }
    };

    class CastExplosiveTrapAction : public CastMeleeSpellAction
    {
    public:
        CastExplosiveTrapAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "explosive trap") {}
        virtual bool isUseful()
        {
            return CastMeleeSpellAction::isUseful();
        }
    };

    class CastCounterAttackAction : public CastMeleeSpellAction
    {
    public:
        CastCounterAttackAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "counterattack") {}
        virtual bool isUseful()
        {
            return CastMeleeSpellAction::isUseful();
        }
    };


    class CastScatterShotAction : public CastMeleeSpellAction
    {
    public:
        CastScatterShotAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "counterattack") {}
        virtual bool isUseful()
        {
            return CastMeleeSpellAction::isUseful();
        }
    };

    class CastSerpentStingOnAttackerAction : public CastDebuffSpellOnAttackerAction
    {
    public:
        CastSerpentStingOnAttackerAction(PlayerbotAI* ai) : CastDebuffSpellOnAttackerAction(ai, "serpent sting") {}
    };

    class CastHuntersMarkActionOnAttackerAction : public CastDebuffSpellOnAttackerAction
    {
    public:
        CastHuntersMarkActionOnAttackerAction(PlayerbotAI* ai) : CastDebuffSpellOnAttackerAction(ai, "hunter's mark") {}
    };
}
