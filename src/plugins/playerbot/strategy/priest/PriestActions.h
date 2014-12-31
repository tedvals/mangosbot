#pragma once

#include "../actions/GenericActions.h"

namespace ai
{
    class CastGreaterHealAction : public CastHealingSpellAction {
    public:
        CastGreaterHealAction(PlayerbotAI* ai) : CastHealingSpellAction(ai, "greater heal") {}
    };

    class CastGreaterHealOnPartyAction : public HealPartyMemberAction
    {
    public:
        CastGreaterHealOnPartyAction(PlayerbotAI* ai) : HealPartyMemberAction(ai, "greater heal") {}

        virtual string getName() { return "greater heal on party"; }
    };

    class CastLesserHealAction : public CastHealingSpellAction {
    public:
        CastLesserHealAction(PlayerbotAI* ai) : CastHealingSpellAction(ai, "lesser heal") {}
    };

    class CastLesserHealOnPartyAction : public HealPartyMemberAction
    {
    public:
        CastLesserHealOnPartyAction(PlayerbotAI* ai) : HealPartyMemberAction(ai, "lesser heal") {}

        virtual string getName() { return "lesser heal on party"; }
    };

    class CastFlashHealAction : public CastHealingSpellAction {
    public:
        CastFlashHealAction(PlayerbotAI* ai) : CastHealingSpellAction(ai, "flash heal") {}
    };

    class CastFlashHealOnPartyAction : public HealPartyMemberAction
    {
    public:
        CastFlashHealOnPartyAction(PlayerbotAI* ai) : HealPartyMemberAction(ai, "flash heal") {}

        virtual string getName() { return "flash heal on party"; }
    };

    class CastPenanceHealAction : public CastHealingSpellAction {
    public:
        CastPenanceHealAction(PlayerbotAI* ai) : CastHealingSpellAction(ai, "penance") {}
    };

    class CastPenanceOnAttackerAction : public CastSpellAction
	{
    public:
	    CastPenanceOnAttackerAction(PlayerbotAI* ai) : CastSpellAction(ai, "shadow word: pain") {}
	};

    class CastPenanceHealOnPartyAction : public HealPartyMemberAction
    {
    public:
        CastPenanceHealOnPartyAction(PlayerbotAI* ai) : HealPartyMemberAction(ai, "penance") {}

        virtual string getName() { return "penance on party"; }
    };

    class CastHealAction : public CastHealingSpellAction {
    public:
        CastHealAction(PlayerbotAI* ai) : CastHealingSpellAction(ai, "heal") {}
    };

    class CastHealOnPartyAction : public HealPartyMemberAction
    {
    public:
        CastHealOnPartyAction(PlayerbotAI* ai) : HealPartyMemberAction(ai, "heal") {}

        virtual string getName() { return "heal on party"; }
    };

    class CastRenewAction : public CastHealingSpellAction {
    public:
        CastRenewAction(PlayerbotAI* ai) : CastHealingSpellAction(ai, "renew") {}
    };

    class CastDesperatePrayerAction : public CastHealingSpellAction {
    public:
        CastDesperatePrayerAction(PlayerbotAI* ai) : CastHealingSpellAction(ai, "desperate prayer") {}

        virtual NextAction** getAlternatives();
    };

    class CastRenewOnPartyAction : public HealPartyMemberAction
    {
    public:
        CastRenewOnPartyAction(PlayerbotAI* ai) : HealPartyMemberAction(ai, "renew") {}

        virtual string getName() { return "renew on party"; }
    };

    class CastPrayerOfHealingAction : public CastAoeHealSpellAction {
    public:
        CastPrayerOfHealingAction(PlayerbotAI* ai) : CastAoeHealSpellAction(ai, "prayer of healing") {}
    };

    class CastDivineHymnAction : public CastAoeHealSpellAction {
    public:
        CastDivineHymnAction(PlayerbotAI* ai) : CastAoeHealSpellAction(ai, "divine hymn") {}
    };

    class CastHymnOfHopeAction : public CastBuffSpellAction {
    public:
        CastHymnOfHopeAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "hymn of hope") {}
    };

    class CastInnerFocusAction : public CastBuffSpellAction {
    public:
        CastInnerFocusAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "inner focus") {}
    };

    class CastFadeAction : public CastBuffSpellAction {
    public:
        CastFadeAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "fade") {}
    };

    class CastPrayerOfMendingAction : public CastHealingSpellAction {
    public:
        CastPrayerOfMendingAction(PlayerbotAI* ai) : CastHealingSpellAction(ai, "prayer of mending") {}
    };

    class CastPrayerOfMendingOnPartyAction : public HealPartyMemberAction
    {
    public:
        CastPrayerOfMendingOnPartyAction(PlayerbotAI* ai) : HealPartyMemberAction(ai, "prayer of mending") {}

        virtual string getName() { return "prayer of mending on party"; }
    };

    class CastBindingHealOnPartyAction : public HealPartyMemberAction
    {
    public:
        CastBindingHealOnPartyAction(PlayerbotAI* ai) : HealPartyMemberAction(ai, "binding heal") {}

        virtual string getName() { return "binding heal on party"; }
    };

    class CastShadowformAction : public CastBuffSpellAction {
    public:
        CastShadowformAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "shadowform") {}
    };

    class CastShadowfiendAction : public CastBuffSpellAction {
    public:
        CastShadowfiendAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "shadowfiend") {}
    };


    class CastRemoveShadowformAction : public Action {
    public:
        CastRemoveShadowformAction(PlayerbotAI* ai) : Action(ai, "remove shadowform") {}
        virtual bool isUseful() { return ai->HasAura("shadowform", AI_VALUE(Unit*, "self target")); }
        virtual bool isPossible() { return true; }
        virtual bool Execute(Event event) {
            ai->RemoveAura("shadowform");
            return true;
        }
    };

	class CastVampiricEmbraceAction : public CastBuffSpellAction {
	public:
		CastVampiricEmbraceAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "vampiric embrace") {}
	};

	class CastPowerWordShieldAction : public CastBuffSpellAction {
	public:
		CastPowerWordShieldAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "power word: shield") {}
	};

    class CastPowerWordShieldOnPartyAction : public HealPartyMemberAction
    {
    public:
        CastPowerWordShieldOnPartyAction(PlayerbotAI* ai) : HealPartyMemberAction(ai, "power word: shield") {}

        virtual string getName() { return "power word: shield on party"; }
    };

    class CastPowerWordShieldOnMasterAction : public BuffOnPartyAction {
	public:
		CastPowerWordShieldOnMasterAction(PlayerbotAI* ai) : BuffOnPartyAction(ai, "power word: shield") {}
		virtual string getName() { return "power word: shield on master";}
        virtual string GetTargetName() { return "master target";}
	};

    class CastPainSuppressionAction : public CastBuffSpellAction {
	public:
		CastPainSuppressionAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "pain suppression") {}
	};

    class CastPainSuppressionOnPartyAction : public HealPartyMemberAction
    {
    public:
        CastPainSuppressionOnPartyAction(PlayerbotAI* ai) : HealPartyMemberAction(ai, "pain suppression") {}

        virtual string getName() { return "pain suppression on party"; }
    };

    class CastGuardianSpiritAction : public CastBuffSpellAction {
	public:
		CastGuardianSpiritAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "guardian spirit") {}
	};

    class CastGuardianSpiritOnPartyAction : public HealPartyMemberAction
    {
    public:
        CastGuardianSpiritOnPartyAction(PlayerbotAI* ai) : HealPartyMemberAction(ai, "guardian spirit") {}

        virtual string getName() { return "guardian spirit on party"; }
    };

    class CastPowerInfusionAction : public CastBuffSpellAction {
	public:
		CastPowerInfusionAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "power infusion") {}
	};

    class CastPowerInfusionOnPartyAction : public BuffOnPartyAction
    {
    public:
        CastPowerInfusionOnPartyAction(PlayerbotAI* ai) : BuffOnPartyAction(ai, "power infusion") {}

        virtual string getName() { return "power infusion on party"; }
    };

	class CastPowerWordFortitudeAction : public CastBuffSpellAction {
	public:
		CastPowerWordFortitudeAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "power word: fortitude") {}
	};

	class CastPrayerOfShadowProtectionAction : public CastBuffSpellAction {
	public:
		CastPrayerOfShadowProtectionAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "prayer of shadow protection") {}
	};

	class CastFearWardAction : public CastBuffSpellAction {
	public:
		CastFearWardAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "fear ward") {}
	};

	class CastFearWardOnPartyAction : public BuffOnPartyAction {
	public:
		CastFearWardOnPartyAction(PlayerbotAI* ai) : BuffOnPartyAction(ai, "fear ward on party") {}
	};

    class CastFearWardOnMasterAction : public BuffOnPartyAction {
	public:
		CastFearWardOnMasterAction(PlayerbotAI* ai) : BuffOnPartyAction(ai, "fear ward") {}
		virtual string getName() { return "fear ward on master";}
        virtual string GetTargetName() { return "master target";}
	};

	class CastDivineSpiritAction : public CastBuffSpellAction {
	public:
		CastDivineSpiritAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "divine spirit") {}
	};

	class CastInnerFireAction : public CastBuffSpellAction {
	public:
		CastInnerFireAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "inner fire") {}
	};

    BEGIN_SPELL_ACTION(CastHolyNovaAction, "holy nova")
    virtual bool isUseful() {
        return !ai->HasAura("shadowform", AI_VALUE(Unit*, "self target")) && AI_VALUE2(float, "distance", GetTargetName()) <= sPlayerbotAIConfig.tooCloseDistance;
    }
    END_SPELL_ACTION()

    BEGIN_RANGED_SPELL_ACTION(CastHolyFireAction, "holy fire")
        virtual bool isUseful() {
            return !ai->HasAura("shadowform", AI_VALUE(Unit*, "self target"));
        }
    END_SPELL_ACTION()

    BEGIN_RANGED_SPELL_ACTION(CastSmiteAction, "smite")
        virtual bool isUseful() {
			return !ai->HasAura("shadowform", AI_VALUE(Unit*, "self target")) && AI_VALUE2(uint8, "mana", "self target") > 75;
        }
    END_SPELL_ACTION()

	class CastPowerWordFortitudeOnPartyAction : public BuffOnPartyAction {
	public:
		CastPowerWordFortitudeOnPartyAction(PlayerbotAI* ai) : BuffOnPartyAction(ai, "power word: fortitude") {}
	};

	class CastPrayerOfShadowProtectionOnPartyAction : public BuffOnPartyAction {
	public:
		CastPrayerOfShadowProtectionOnPartyAction(PlayerbotAI* ai) : BuffOnPartyAction(ai, "prayer of shadow protection") {}
	};

	class CastDivineSpiritOnPartyAction : public BuffOnPartyAction {
	public:
		CastDivineSpiritOnPartyAction(PlayerbotAI* ai) : BuffOnPartyAction(ai, "divine spirit") {}
	};

	class CastPowerWordPainAction : public CastDebuffSpellAction
	{
    public:
	    CastPowerWordPainAction(PlayerbotAI* ai) : CastDebuffSpellAction(ai, "shadow word: pain") {}
	};

	class CastPowerWordPainOnAttackerAction : public CastDebuffSpellOnAttackerAction
	{
    public:
	    CastPowerWordPainOnAttackerAction(PlayerbotAI* ai) : CastDebuffSpellOnAttackerAction(ai, "shadow word: pain") {}
	};

    BEGIN_DEBUFF_ACTION(CastDevouringPlagueAction, "devouring plague")
    END_SPELL_ACTION()

    BEGIN_DEBUFF_ACTION(CastVampiricTouchAction, "vampiric touch")
    END_SPELL_ACTION()

    BEGIN_RANGED_SPELL_ACTION(CastMindBlastAction, "mind blast")
    END_SPELL_ACTION()

    BEGIN_RANGED_SPELL_ACTION(CastMindFlayAction, "mind flay")
    END_SPELL_ACTION()

    BEGIN_RANGED_SPELL_ACTION(CastPowerWordDeathAction, "power word: death")
    END_SPELL_ACTION()

	class CastCureDiseaseAction : public CastCureSpellAction {
	public:
		CastCureDiseaseAction(PlayerbotAI* ai) : CastCureSpellAction(ai, "cure disease") {}
	};

    class CastCureDiseaseOnPartyAction : public CurePartyMemberAction
    {
    public:
        CastCureDiseaseOnPartyAction(PlayerbotAI* ai) : CurePartyMemberAction(ai, "cure disease", DISPEL_DISEASE) {}
        virtual string getName() { return "cure disease on party"; }
    };

	class CastAbolishDiseaseAction : public CastCureSpellAction {
	public:
		CastAbolishDiseaseAction(PlayerbotAI* ai) : CastCureSpellAction(ai, "abolish disease") {}
		virtual NextAction** getAlternatives();
	};

    class CastAbolishDiseaseOnPartyAction : public CurePartyMemberAction
    {
    public:
        CastAbolishDiseaseOnPartyAction(PlayerbotAI* ai) : CurePartyMemberAction(ai, "abolish disease", DISPEL_DISEASE) {}
        virtual string getName() { return "abolish disease on party"; }
        virtual NextAction** getAlternatives();
    };

	class CastDispelMagicAction : public CastCureSpellAction {
	public:
		CastDispelMagicAction(PlayerbotAI* ai) : CastCureSpellAction(ai, "dispel magic") {}
	};

    class CastDispelMagicOnTargetAction : public CastSpellAction {
    public:
        CastDispelMagicOnTargetAction(PlayerbotAI* ai) : CastSpellAction(ai, "dispel magic") {}
    };

    class CastDispelMagicOnPartyAction : public CurePartyMemberAction
    {
    public:
        CastDispelMagicOnPartyAction(PlayerbotAI* ai) : CurePartyMemberAction(ai, "dispel magic", DISPEL_MAGIC) {}
        virtual string getName() { return "dispel magic on party"; }
    };

	class CastResurrectionAction : public ResurrectPartyMemberAction
	{
	public:
		CastResurrectionAction(PlayerbotAI* ai) : ResurrectPartyMemberAction(ai, "resurrection") {}
	};

	class CastCircleOfHealingAction : public CastAoeHealSpellAction
	{
	public:
		CastCircleOfHealingAction(PlayerbotAI* ai) : CastAoeHealSpellAction(ai, "circle of healing") {}
	};

	class CastPsychicScreamAction : public CastSpellAction
	{
	public:
	    CastPsychicScreamAction(PlayerbotAI* ai) : CastSpellAction(ai, "psychic scream") {}
	};

	class CastPsychicHorrorAction : public CastSpellAction
	{
	public:
	    CastPsychicHorrorAction(PlayerbotAI* ai) : CastSpellAction(ai, "psychic horror") {}
	};

	class CastDispersionAction : public CastSpellAction
	{
	public:
	    CastDispersionAction(PlayerbotAI* ai) : CastSpellAction(ai, "dispersion") {}
	    virtual string GetTargetName() { return "self target"; }
	};

	class CastMindShearAction : public CastSpellAction
	{
	public:
		CastMindShearAction(PlayerbotAI* ai) : CastSpellAction(ai, "mind shear") {}
	};

    class CastSilenceAction : public CastSpellAction {
    public:
        CastSilenceAction(PlayerbotAI* ai) : CastSpellAction(ai, "silence") {}
    };

    class CastShackleUndeadAction : public CastSpellAction
	{
	public:
		CastShackleUndeadAction(PlayerbotAI* ai) : CastSpellAction(ai, "shackle undead") {}
	};

    class CastShackleUndeadCcAction : public CastDebuffSpellAction
    {
    public:
        CastShackleUndeadCcAction(PlayerbotAI* ai) : CastDebuffSpellAction(ai, "shackle undead on cc") {}
        virtual Value<Unit*>* GetTargetValue();
        virtual bool Execute(Event event);
    };

}
