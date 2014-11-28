#pragma once

#include "../actions/GenericActions.h"

namespace ai
{
	class CastDemonSkinAction : public CastBuffSpellAction {
	public:
		CastDemonSkinAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "demon skin") {}
	};

	class CastDemonArmorAction : public CastBuffSpellAction
	{
	public:
		CastDemonArmorAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "demon armor") {}
	};

	class CastFelArmorAction : public CastBuffSpellAction
	{
	public:
		CastFelArmorAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "fel armor") {}
	};

    BEGIN_RANGED_SPELL_ACTION(CastShadowBoltAction, "shadow bolt")
    END_SPELL_ACTION()

	class CastDrainSoulAction : public CastSpellAction
	{
	public:
		CastDrainSoulAction(PlayerbotAI* ai) : CastSpellAction(ai, "drain soul") {}
		virtual bool isUseful()
		{
			return AI_VALUE2(uint8, "item count", "soul shard") < 10;
		}
	};

	class CastDrainManaAction : public CastSpellAction
	{
	public:
		CastDrainManaAction(PlayerbotAI* ai) : CastSpellAction(ai, "drain mana") {}
	};

	class CastDrainLifeAction : public CastSpellAction
	{
	public:
		CastDrainLifeAction(PlayerbotAI* ai) : CastSpellAction(ai, "drain life") {}

		virtual bool isUseful()
	    {
	        return CastSpellAction::isUseful() && AI_VALUE2(uint8, "health", "current target") < 20;
	    }
	};

	class CastCurseOfAgonyAction : public CastDebuffSpellAction
	{
	public:
		CastCurseOfAgonyAction(PlayerbotAI* ai) : CastDebuffSpellAction(ai, "curse of agony") {}

        virtual bool IsActive()
        {
            Unit* target = GetTarget();
            return !ai->HasAura("curse of the elements", target) &&
            !ai->HasAura("curse of weakness", target) &&
            !ai->HasAura("curse of exhaustion", target) &&
            !ai->HasAura("curse of agony", target) &&
            !ai->HasAura("curse of doom", target);
        }
	};

	class CastCurseOfWeaknessAction : public CastDebuffSpellAction
	{
	public:
		CastCurseOfWeaknessAction(PlayerbotAI* ai) : CastDebuffSpellAction(ai, "curse of weakness") {}

    virtual bool IsActive()
        {
            Unit* target = GetTarget();
            return !ai->HasAura("curse of the elements", target) &&
            !ai->HasAura("curse of weakness", target) &&
            !ai->HasAura("curse of exhaustion", target) &&
            !ai->HasAura("curse of agony", target) &&
            !ai->HasAura("curse of doom", target);
        }
	};

	class CastCurseOfTheElementsAction : public CastDebuffSpellAction
	{
	public:
		CastCurseOfTheElementsAction(PlayerbotAI* ai) : CastDebuffSpellAction(ai, "curse of the elements") {}

        virtual bool IsActive()
        {
            Unit* target = GetTarget();
            return !ai->HasAura("curse of the elements", target) &&
            !ai->HasAura("curse of weakness", target) &&
            !ai->HasAura("curse of exhaustion", target) &&
            !ai->HasAura("curse of agony", target) &&
            !ai->HasAura("curse of doom", target);
        }
	};

	class CastCorruptionAction : public CastDebuffSpellAction
	{
	public:
		CastCorruptionAction(PlayerbotAI* ai) : CastDebuffSpellAction(ai, "corruption") {}

    virtual bool IsActive()
        {
            Unit* target = GetTarget();
            return !ai->HasAura("corruption", target) &&
            !ai->HasAura("seed of corruption", target);
        }
	};

	class CastCorruptionOnAttackerAction : public CastDebuffSpellOnAttackerAction
	{
	public:
	    CastCorruptionOnAttackerAction(PlayerbotAI* ai) : CastDebuffSpellOnAttackerAction(ai, "corruption") {}
	};


	class CastSummonVoidwalkerAction : public CastBuffSpellAction
	{
	public:
		CastSummonVoidwalkerAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "summon voidwalker") {}
        virtual bool isUseful()
		{
			return AI_VALUE2(uint8, "item count", "soul shard") > 0;
		}
	};

	class CastSummonFelhunterAction : public CastBuffSpellAction
	{
	public:
		CastSummonFelhunterAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "summon felhunter") {}
        virtual bool isUseful()
		{
			return AI_VALUE2(uint8, "item count", "soul shard") > 0;
		}
	};

	class CastSummonSuccubusAction : public CastBuffSpellAction
	{
	public:
		CastSummonSuccubusAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "summon succubus") {}
        virtual bool isUseful()
		{
			return AI_VALUE2(uint8, "item count", "soul shard") > 0;
		}
	};

	class CastSummonFelguardAction : public CastBuffSpellAction
	{
	public:
		CastSummonFelguardAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "summon felguard") {}
		virtual bool isUseful()
		{
			return AI_VALUE2(uint8, "item count", "soul shard") > 0;
		}
	};

	class CastSummonImpAction : public CastBuffSpellAction
	{
	public:
		CastSummonImpAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "summon imp") {}
	};

	class CastCreateHealthstoneAction : public CastBuffSpellAction
	{
	public:
		CastCreateHealthstoneAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "create healthstone") {}
		virtual bool isUseful()
		{
			return AI_VALUE2(uint8, "item count", "soul shard") > 0;
		}
	};

    class CastDemonicEmpowermentAction : public CastBuffSpellAction
	{
	public:
		CastDemonicEmpowermentAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "demonic empowerment") {}
	};

    class CastFelDominationAction : public CastBuffSpellAction
	{
	public:
		CastFelDominationAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "fel domination") {}
	};

    class CastMetamorphosisAction : public CastBuffSpellAction
	{
	public:
		CastMetamorphosisAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "metamorphosis") {}
	};

	class CastShadowCleaveAction : public CastSpellAction
	{
	public:
		CastShadowCleaveAction(PlayerbotAI* ai) : CastSpellAction(ai, "shadow cleave") {}

		virtual bool isUseful() {
            return ai->HasAura("metamorphosis", AI_VALUE(Unit*, "self target"));
        }
	};

	class CastImmolationAuraAction : public CastBuffSpellAction
	{
	public:
		CastImmolationAuraAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "immolation aura") {}

     virtual bool isUseful() {
            return ai->HasAura("metamorphosis", AI_VALUE(Unit*, "self target"));
        }
	};

	class CastChallengingHowlAction : public CastMeleeSpellAction
	{
	public:
		CastChallengingHowlAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "challenging howl") {}
        virtual bool isUseful() {
            return ai->HasAura("metamorphosis", AI_VALUE(Unit*, "self target"));
        }
	};

	class CastDemonChargeAction : public CastSpellAction
	{
	public:
		CastDemonChargeAction(PlayerbotAI* ai) : CastSpellAction(ai, "demon charge") {}

		virtual bool isUseful() {
            return ai->HasAura("metamorphosis", AI_VALUE(Unit*, "self target"));
        }
	};

	class CastCreateFirestoneAction : public CastBuffSpellAction
	{
	public:
		CastCreateFirestoneAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "create firestone") {}
	};

	class CastCreateSpellstoneAction : public CastBuffSpellAction
	{
	public:
		CastCreateSpellstoneAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "create spellstone") {}
	};

    class CastSoulShatterAction : public CastBuffSpellAction
	{
	public:
		CastSoulShatterAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "soul shatter") {}
	};

    class CastBanishAction : public CastBuffSpellAction
    {
    public:
        CastBanishAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "banish on cc") {}
        virtual Value<Unit*>* GetTargetValue() { return context->GetValue<Unit*>("cc target", "banish"); }
        virtual bool Execute(Event event) { return ai->CastSpell("banish", GetTarget()); }
    };

    class CastSeedOfCorruptionAction : public CastDebuffSpellAction
    {
    public:
        CastSeedOfCorruptionAction(PlayerbotAI* ai) : CastDebuffSpellAction(ai, "seed of corruption") {}
    };

    class CastRainOfFireAction : public CastSpellAction
    {
    public:
        CastRainOfFireAction(PlayerbotAI* ai) : CastSpellAction(ai, "rain of fire") {}
    };

    class CastShadowfuryAction : public CastSpellAction
    {
    public:
        CastShadowfuryAction(PlayerbotAI* ai) : CastSpellAction(ai, "shadowfury") {}
        virtual bool isUseful() { return AI_VALUE2(float, "distance", GetTargetName()) <= sPlayerbotAIConfig.tooCloseDistance; }
    };

    class CastImmolateAction : public CastDebuffSpellAction
    {
    public:
        CastImmolateAction(PlayerbotAI* ai) : CastDebuffSpellAction(ai, "immolate") {}
        //virtual bool isUseful() {
        //    return !ai->HasAura("shadowform", AI_VALUE(Unit*, "self target"));
        //}
    };

    class CastConflagrateAction : public CastSpellAction
    {
    public:
        CastConflagrateAction(PlayerbotAI* ai) : CastSpellAction(ai, "conflagrate") {}

        virtual NextAction** getAlternatives()
        {
            return NextAction::merge( NextAction::array(0, new NextAction("shadow bolt"), NULL), CastSpellAction::getAlternatives());
        }
    };

    class CastIncinerateAction : public CastSpellAction
    {
    public:
        CastIncinerateAction(PlayerbotAI* ai) : CastSpellAction(ai, "incinerate") {}

        virtual NextAction** getAlternatives()
        {
            return NextAction::merge( NextAction::array(0, new NextAction("shadow bolt"), NULL), CastSpellAction::getAlternatives());
        }
    };

    class CastSoulFireAction : public CastSpellAction
    {
    public:
        CastSoulFireAction(PlayerbotAI* ai) : CastSpellAction(ai, "soul fire") {}
    };

    class CastChaosBoltAction : public CastSpellAction
    {
    public:
        CastChaosBoltAction(PlayerbotAI* ai) : CastSpellAction(ai, "chaos bolt") {}
        virtual NextAction** getAlternatives()
        {
            return NextAction::merge( NextAction::array(0, new NextAction("shadow bolt"), NULL), CastSpellAction::getAlternatives());
        }

    };

    class CastHauntAction : public CastDebuffSpellAction
    {
    public:
        CastHauntAction(PlayerbotAI* ai) : CastDebuffSpellAction(ai, "haunt") {}
    };

    class CastHowlOfTerrorAction : public CastDebuffSpellAction
    {
    public:
        CastHowlOfTerrorAction(PlayerbotAI* ai) : CastDebuffSpellAction(ai, "howl of terror") {}
        virtual bool isUseful() { return AI_VALUE2(float, "distance", GetTargetName()) <= sPlayerbotAIConfig.tooCloseDistance; }
    };

    class CastDeathcoilAction : public CastDebuffSpellAction
    {
    public:
        CastDeathcoilAction(PlayerbotAI* ai) : CastDebuffSpellAction(ai, "death coil") {}
    };

    class CastUnstableAfflictionAction : public CastDebuffSpellAction
    {
    public:
        CastUnstableAfflictionAction(PlayerbotAI* ai) : CastDebuffSpellAction(ai, "unstable affliction") {}
    };

    class CastFearAction : public CastDebuffSpellAction
    {
    public:
        CastFearAction(PlayerbotAI* ai) : CastDebuffSpellAction(ai, "fear") {}
    };

    class CastFearOnCcAction : public CastBuffSpellAction
    {
    public:
        CastFearOnCcAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "fear on cc") {}
        virtual Value<Unit*>* GetTargetValue() { return context->GetValue<Unit*>("cc target", "fear"); }
        virtual bool Execute(Event event) { return ai->CastSpell("fear", GetTarget()); }
    };

    class CastLifeTapAction: public CastSpellAction
    {
    public:
        CastLifeTapAction(PlayerbotAI* ai) : CastSpellAction(ai, "life tap") {}
        virtual string GetTargetName() { return "self target"; }
        virtual bool isUseful() { return AI_VALUE2(uint8, "health", "self target") > sPlayerbotAIConfig.lowHealth; }
    };

}
