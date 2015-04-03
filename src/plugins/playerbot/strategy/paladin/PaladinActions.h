#pragma once
#include "../actions/GenericActions.h"

namespace ai
{
    class CastJudgementOfLightAction : public CastMeleeSpellAction
    {
    public:
        CastJudgementOfLightAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "judgement of light") {}
    };

    class CastJudgementOfWisdomAction : public CastMeleeSpellAction
    {
    public:
        CastJudgementOfWisdomAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "judgement of wisdom") {}
	virtual bool isUseful()
	{
		return AI_VALUE2(uint8, "mana", "self target") <= sPlayerbotAIConfig.almostFullMana;
		}
    };

    class CastRangedJudgementOfLightAction : public CastSpellAction
    {
    public:
        CastRangedJudgementOfLightAction(PlayerbotAI* ai) : CastSpellAction(ai, "judgement of light") {}
    };

    class CastRangedJudgementOfWisdomAction : public CastSpellAction
    {
    public:
        CastRangedJudgementOfWisdomAction(PlayerbotAI* ai) : CastSpellAction(ai, "judgement of wisdom") {}
	virtual bool isUseful()
	{
		return AI_VALUE2(uint8, "mana", "self target") <= sPlayerbotAIConfig.almostFullMana;
		}
    };

    class CastJudgementOfJusticeAction : public CastMeleeSpellAction
    {
    public:
        CastJudgementOfJusticeAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "judgement of justice") {}
    };

	class CastRighteousFuryAction : public CastBuffSpellAction
	{
	public:
		CastRighteousFuryAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "righteous fury") {}
	};

	class CastDevotionAuraAction : public CastBuffSpellAction
	{
	public:
		CastDevotionAuraAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "devotion aura") {}
	};

	class CastRetributionAuraAction : public CastBuffSpellAction
	{
	public:
		CastRetributionAuraAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "retribution aura") {}
	};

	class CastConcentrationAuraAction : public CastBuffSpellAction
	{
	public:
		CastConcentrationAuraAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "concentration aura") {}
	};

	class CastDivineStormAction : public CastBuffSpellAction
	{
	public:
		CastDivineStormAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "divine storm") {}
	};

	class CastCrusaderStrikeAction : public CastMeleeSpellAction
	{
	public:
		CastCrusaderStrikeAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "crusader strike") {}
	};

	class CastShadowResistanceAuraAction : public CastBuffSpellAction
	{
	public:
		CastShadowResistanceAuraAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "shadow resistance aura") {}
	};

	class CastFrostResistanceAuraAction : public CastBuffSpellAction
	{
	public:
		CastFrostResistanceAuraAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "frost resistance aura") {}
	};

	class CastFireResistanceAuraAction : public CastBuffSpellAction
	{
	public:
		CastFireResistanceAuraAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "fire resistance aura") {}
	};

	class CastCrusaderAuraAction : public CastBuffSpellAction
	{
	public:
		CastCrusaderAuraAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "crusader aura") {}
	};

	class CastSealOfRighteousnessAction : public CastBuffSpellAction
	{
	public:
		CastSealOfRighteousnessAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "seal of righteousness") {}
	};

	class CastSealOfJusticeAction : public CastBuffSpellAction
	{
	public:
		CastSealOfJusticeAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "seal of justice") {}
	};

	class CastSealOfLightAction : public CastBuffSpellAction
	{
	public:
		CastSealOfLightAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "seal of light") {}
		virtual bool isUseful();
	};

	class CastSealOfWisdomAction : public CastBuffSpellAction
	{
	public:
		CastSealOfWisdomAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "seal of wisdom") {}
		virtual bool isUseful();
	};

	class CastSealOfCommandAction : public CastBuffSpellAction
	{
	public:
		CastSealOfCommandAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "seal of command") {}
		virtual bool isUseful();
	};

	class CastSealOfVengeanceAction : public CastBuffSpellAction
	{
	public:
	    CastSealOfVengeanceAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "seal of vengeance") {}
	    virtual bool isUseful();
	};

	class CastBlessingOfMightAction : public CastBuffSpellAction
	{
	public:
		CastBlessingOfMightAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "blessing of might") {}
	};

	class CastBlessingOfMightOnPartyAction : public BuffOnPartyAction
	{
	public:
		CastBlessingOfMightOnPartyAction(PlayerbotAI* ai) : BuffOnPartyAction(ai, "blessing of might") {}
        virtual string getName() { return "blessing of might on party";}
        virtual bool isUseful();
	};

	class CastBlessingOfWisdomAction : public CastBuffSpellAction
	{
	public:
		CastBlessingOfWisdomAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "blessing of wisdom") {}
	};

	class CastBlessingOfWisdomOnPartyAction : public BuffOnPartyAction
	{
	public:
		CastBlessingOfWisdomOnPartyAction(PlayerbotAI* ai) : BuffOnPartyAction(ai, "blessing of wisdom") {}
        virtual string getName() { return "blessing of wisdom on party";}
        virtual bool isUseful();
	};

	class CastBlessingOfKingsAction : public CastBuffSpellAction
	{
	public:
		CastBlessingOfKingsAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "blessing of kings") {}
	};

	class CastBlessingOfKingsOnPartyAction : public BuffOnPartyAction
	{
	public:
		CastBlessingOfKingsOnPartyAction(PlayerbotAI* ai) : BuffOnPartyAction(ai, "blessing of kings") {}
        virtual string getName() { return "blessing of kings on party";}
	};

	class CastBlessingOfSanctuaryAction : public CastBuffSpellAction
	{
	public:
		CastBlessingOfSanctuaryAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "blessing of sanctuary") {}
	};

	class CastBlessingOfSanctuaryOnPartyAction : public BuffOnPartyAction
	{
	public:
		CastBlessingOfSanctuaryOnPartyAction(PlayerbotAI* ai) : BuffOnPartyAction(ai, "blessing of sanctuary") {}
        virtual string getName() { return "blessing of sanctuary on party";}
        virtual bool isUseful();
	};

    class CastBeaconOfLightActionOnMaster : public BuffOnMasterAction
    {
    public:
        CastBeaconOfLightActionOnMaster(PlayerbotAI* ai) : BuffOnMasterAction(ai, "beacon of light") {}
    };

	class CastBeaconOfLightActionOnParty : public BuffOnPartyAction
    {
    public:
        CastBeaconOfLightActionOnParty(PlayerbotAI* ai) : BuffOnPartyAction(ai, "beacon of light") {}
        virtual string getName() { return "beacon of light on party";}
        virtual bool isUseful();
    };


    class CastHolyLightAction : public CastHealingSpellAction
    {
    public:
        CastHolyLightAction(PlayerbotAI* ai) : CastHealingSpellAction(ai, "holy light") {}
    };

    class CastHolyLightOnPartyAction : public HealPartyMemberAction
    {
    public:
        CastHolyLightOnPartyAction(PlayerbotAI* ai) : HealPartyMemberAction(ai, "holy light") {}

        virtual string getName() { return "holy light on party"; }
    };

    class CastHolyLightOnMasterAction : public HealMasterAction
    {
    public:
        CastHolyLightOnMasterAction(PlayerbotAI* ai) : HealMasterAction(ai, "holy light") {}
    };


    class CastHolyShockAction : public CastHealingSpellAction
    {
    public:
        CastHolyShockAction(PlayerbotAI* ai) : CastHealingSpellAction(ai, "holy shock") {}

        virtual bool IsInstant() {return true;}
    };

    class CastHolyShockOnPartyAction : public HealPartyMemberAction
    {
    public:
        CastHolyShockOnPartyAction(PlayerbotAI* ai) : HealPartyMemberAction(ai, "shock shock") {}

        virtual string getName() { return "holy shock on party"; }
        virtual bool IsInstant() {return true;}
    };

    class CastHolyShockOnMasterAction : public HealMasterAction
    {
    public:
        CastHolyShockOnMasterAction(PlayerbotAI* ai) : HealMasterAction(ai, "shock shock") {}
        virtual bool IsInstant() {return true;}
    };

    class CastSacredShieldOnPartyAction : public HealPartyMemberAction
    {
    public:
        CastSacredShieldOnPartyAction(PlayerbotAI* ai) : HealPartyMemberAction(ai, "sacred shield") {}

        virtual string getName() { return "sacred shield on party"; }
    };

    class CastSacredShieldOnMasterAction : public HealMasterAction
    {
    public:
        CastSacredShieldOnMasterAction(PlayerbotAI* ai) : HealMasterAction(ai, "sacred shield") {}

    };

    class CastFlashOfLightAction : public CastHealingSpellAction
    {
    public:
        CastFlashOfLightAction(PlayerbotAI* ai) : CastHealingSpellAction(ai, "flash of light") {}
    };

    class CastFlashOfLightOnPartyAction : public HealPartyMemberAction
    {
    public:
        CastFlashOfLightOnPartyAction(PlayerbotAI* ai) : HealPartyMemberAction(ai, "flash of light") {}

        virtual string getName() { return "flash of light on party"; }
    };

    class CastFlashOfLightOnMasterAction : public HealMasterAction
    {
    public:
        CastFlashOfLightOnMasterAction(PlayerbotAI* ai) : HealMasterAction(ai, "flash of light") {}
    };

    class CastInstantFlashOfLightAction : public CastHealingSpellAction
    {
    public:
        CastInstantFlashOfLightAction(PlayerbotAI* ai) : CastHealingSpellAction(ai, "flash of light") {}
        virtual bool isUseful();
        virtual bool Execute(Event event);
    };

    class CastInstantFlashOfLightOnPartyAction : public HealPartyMemberAction
    {
    public:
        CastInstantFlashOfLightOnPartyAction(PlayerbotAI* ai) : HealPartyMemberAction(ai, "flash of light") {}

        virtual string getName() { return "instant flash of light on party"; }
        virtual bool isUseful();
        virtual bool Execute(Event event);
        virtual bool IsInstant() {return true;}
    };

   class CastInstantFlashOfLightOnMasterAction : public HealMasterAction
    {
    public:
        CastInstantFlashOfLightOnMasterAction(PlayerbotAI* ai) : HealMasterAction(ai, "flash of light") {}

        virtual string getName() { return "instant flash of light on master"; }
        virtual bool isUseful();
        virtual bool Execute(Event event);
        virtual bool IsInstant() {return true;}
    };

    class CastLayOnHandsAction : public CastHealingSpellAction
    {
    public:
        CastLayOnHandsAction(PlayerbotAI* ai) : CastHealingSpellAction(ai, "lay on hands") {}
        virtual bool IsInstant() {return true;}
    };

    class CastLayOnHandsOnPartyAction : public HealPartyMemberAction
    {
    public:
        CastLayOnHandsOnPartyAction(PlayerbotAI* ai) : HealPartyMemberAction(ai, "lay on hands") {}

        virtual string getName() { return "lay on hands on party"; }
        virtual bool IsInstant() {return true;}
    };

    class CastLayOnHandsOnMasterAction : public HealMasterAction
    {
    public:
        CastLayOnHandsOnMasterAction(PlayerbotAI* ai) : HealMasterAction(ai, "lay on hands") {}
        virtual bool IsInstant() {return true;}
    };

	class CastDivineProtectionAction : public CastBuffSpellAction
	{
	public:
		CastDivineProtectionAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "divine protection") {}
		virtual bool IsInstant() {return true;}
	};

    class CastDivineFavorAction : public CastBuffSpellAction
	{
	public:
		CastDivineFavorAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "divine favor") {}
	};

    class CastDivinePleaAction : public CastBuffSpellAction
	{
	public:
		CastDivinePleaAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "divine plea") {}
	};

    class CastDivineIlluminationAction : public CastBuffSpellAction
	{
	public:
		CastDivineIlluminationAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "divine illumination") {}
		virtual bool IsInstant() {return true;}
	};

    class CastAuraMasteryAction : public CastBuffSpellAction
	{
	public:
		CastAuraMasteryAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "aura mastery") {}
	};

	class CastAvengingWrathAction : public CastBuffSpellAction
	{
	public:
		CastAvengingWrathAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "avenging wrath") {}
		virtual bool IsInstant() {return true;}
	};

    class CastDivineProtectionOnPartyAction : public HealPartyMemberAction
    {
    public:
        CastDivineProtectionOnPartyAction(PlayerbotAI* ai) : HealPartyMemberAction(ai, "divine protection") {}

        virtual string getName() { return "divine protection on party"; }
        virtual bool IsInstant() {return true;}
    };

    class CastDivineProtectionOnMasterAction : public HealMasterAction
    {
    public:
        CastDivineProtectionOnMasterAction(PlayerbotAI* ai) : HealMasterAction(ai, "divine protection") {}
        virtual bool IsInstant() {return true;}
    };


	class CastDivineShieldAction: public CastBuffSpellAction
	{
	public:
		CastDivineShieldAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "divine shield") {}
		virtual bool IsInstant() {return true;}
	};

    class CastConsecrationAction : public CastMeleeSpellAction
    {
    public:
	    CastConsecrationAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "consecration") {}
	    virtual bool IsInstant() {return true;}
    };

    class CastHolyWrathAction : public CastMeleeSpellAction
    {
    public:
        CastHolyWrathAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "holy wrath") {}
    };

    class CastHammerOfJusticeAction : public CastMeleeSpellAction
    {
    public:
        CastHammerOfJusticeAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "hammer of justice") {}
        virtual bool IsInstant() {return true;}
    };

	class CastHammerOfWrathAction : public CastMeleeSpellAction
	{
	public:
		CastHammerOfWrathAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "hammer of wrath") {}
		virtual bool IsInstant() {return true;}
	};

	class CastHammerOfTheRighteousAction : public CastMeleeSpellAction
	{
	public:
		CastHammerOfTheRighteousAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "hammer of the righteous") {}
		virtual bool IsInstant() {return true;}
	};

	class CastPurifyPoisonAction : public CastCureSpellAction
	{
	public:
		CastPurifyPoisonAction(PlayerbotAI* ai) : CastCureSpellAction(ai, "purify") {}
		virtual bool IsInstant() {return true;}
	};

	class CastPurifyDiseaseAction : public CastCureSpellAction
	{
	public:
		CastPurifyDiseaseAction(PlayerbotAI* ai) : CastCureSpellAction(ai, "purify") {}
		virtual bool IsInstant() {return true;}
	};

    class CastPurifyPoisonOnPartyAction : public CurePartyMemberAction
    {
    public:
        CastPurifyPoisonOnPartyAction(PlayerbotAI* ai) : CurePartyMemberAction(ai, "purify", DISPEL_POISON) {}

        virtual string getName() { return "purify poison on party"; }
    };

	class CastPurifyDiseaseOnPartyAction : public CurePartyMemberAction
	{
	public:
		CastPurifyDiseaseOnPartyAction(PlayerbotAI* ai) : CurePartyMemberAction(ai, "purify", DISPEL_DISEASE) {}

		virtual string getName() { return "purify disease on party"; }
	};

	class CastHandOfReckoningAction : public CastSpellAction
	{
	public:
		CastHandOfReckoningAction(PlayerbotAI* ai) : CastSpellAction(ai, "hand of reckoning") {}
		virtual bool IsInstant() {return true;}
	};

//	class CastHandOfSalvationAction : public CastSpellAction
//	{
//	public:
//		CastHandOfSalvationAction(PlayerbotAI* ai) : CastSpellAction(ai, "hand of salvation") {}
//	};

	class CastHandOfSalvationOnPartyAction : public BuffOnPartyAction
	{
	public:
		CastHandOfSalvationOnPartyAction(PlayerbotAI* ai) : BuffOnPartyAction(ai, "hand of salvation") {}
        virtual string getName() { return "hand of salvation on party";}
        virtual bool IsInstant() {return true;}
	};

	class CastHandOfSalvationOnMasterAction : public BuffOnMasterAction
	{
	public:
		CastHandOfSalvationOnMasterAction(PlayerbotAI* ai) : BuffOnMasterAction(ai, "hand of salvation") {}
		virtual bool IsInstant() {return true;}
	};

	class CastHandOfFreedomAction : public CastSpellAction
	{
	public:
		CastHandOfFreedomAction(PlayerbotAI* ai) : CastSpellAction(ai, "hand of freedom") {}
		virtual bool IsInstant() {return true;}
	};

	class CastHandOfFreedomOnPartyAction : public DispelSnarePartyMemberAction
	{
	public:
		CastHandOfFreedomOnPartyAction(PlayerbotAI* ai) : DispelSnarePartyMemberAction(ai, "hand of freedom") {}
        virtual string getName() { return "hand of freedom on party";}
        virtual bool IsInstant() {return true;}
	};

	class CastHandOfSacrificeOnPartyAction : public BuffOnPartyAction
	{
	public:
		CastHandOfSacrificeOnPartyAction(PlayerbotAI* ai) : BuffOnPartyAction(ai, "hand of sacrifice") {}
        virtual string getName() { return "hand of sacrifice on party";}
        virtual bool IsInstant() {return true;}
	};

	class CastHandOfSacrificeOnMasterAction : public BuffOnMasterAction
	{
	public:
		CastHandOfSacrificeOnMasterAction(PlayerbotAI* ai) : BuffOnMasterAction(ai, "hand of sacrifice") {}
		virtual bool IsInstant() {return true;}
	};

	class CastHandOfProtectionOnPartyAction : public BuffOnPartyAction
	{
	public:
		CastHandOfProtectionOnPartyAction(PlayerbotAI* ai) : BuffOnPartyAction(ai, "hand of protection") {}
        virtual string getName() { return "hand of protection on party";}
        virtual bool IsInstant() {return true;}
	};

	class CastHandOfProtectionOnMasterAction : public BuffOnMasterAction
	{
	public:
		CastHandOfProtectionOnMasterAction(PlayerbotAI* ai) : BuffOnMasterAction(ai, "hand of protection") {}
		virtual bool IsInstant() {return true;}
	};

//	class CastHandOfSacrificeAction : public CastSpellAction
//	{
//	public:
//		CastHandOfSacrificeAction(PlayerbotAI* ai) : CastSpellAction(ai, "hand of sacrifice") {}
//	};

	class CastCleansePoisonAction : public CastCureSpellAction
	{
	public:
		CastCleansePoisonAction(PlayerbotAI* ai) : CastCureSpellAction(ai, "cleanse") {}
		virtual bool IsInstant() {return true;}
	};

	class CastCleanseDiseaseAction : public CastCureSpellAction
	{
	public:
		CastCleanseDiseaseAction(PlayerbotAI* ai) : CastCureSpellAction(ai, "cleanse") {}
		virtual bool IsInstant() {return true;}
	};

	class CastCleanseMagicAction : public CastCureSpellAction
	{
	public:
		CastCleanseMagicAction(PlayerbotAI* ai) : CastCureSpellAction(ai, "cleanse") {}
		virtual bool IsInstant() {return true;}
	};

    class CastCleansePoisonOnPartyAction : public CurePartyMemberAction
    {
    public:
        CastCleansePoisonOnPartyAction(PlayerbotAI* ai) : CurePartyMemberAction(ai, "cleanse", DISPEL_POISON) {}

        virtual string getName() { return "cleanse poison on party"; }
        virtual bool IsInstant() {return true;}
    };

	class CastCleanseDiseaseOnPartyAction : public CurePartyMemberAction
	{
	public:
		CastCleanseDiseaseOnPartyAction(PlayerbotAI* ai) : CurePartyMemberAction(ai, "cleanse", DISPEL_DISEASE) {}

		virtual string getName() { return "cleanse disease on party"; }
		virtual bool IsInstant() {return true;}
	};

	class CastCleanseMagicOnPartyAction : public CurePartyMemberAction
	{
	public:
		CastCleanseMagicOnPartyAction(PlayerbotAI* ai) : CurePartyMemberAction(ai, "cleanse", DISPEL_MAGIC) {}

		virtual string getName() { return "cleanse magic on party"; }
		virtual bool IsInstant() {return true;}
	};

    BEGIN_SPELL_ACTION(CastAvengersShieldAction, "avenger's shield")
    END_SPELL_ACTION()

	BEGIN_SPELL_ACTION(CastExorcismAction, "exorcism")
	END_SPELL_ACTION()

	class CastHolyShieldAction : public CastBuffSpellAction
	{
	public:
		CastHolyShieldAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "holy shield") {}
	};

	class CastRedemptionAction : public ResurrectPartyMemberAction
	{
	public:
		CastRedemptionAction(PlayerbotAI* ai) : ResurrectPartyMemberAction(ai, "redemption") {}
	};

    class CastHammerOfJusticeOnEnemyHealerAction : public CastSpellOnEnemyHealerAction
    {
    public:
        CastHammerOfJusticeOnEnemyHealerAction(PlayerbotAI* ai) : CastSpellOnEnemyHealerAction(ai, "hammer of justice") {}
    };

    class CastRepentanceAction : public CastSpellAction
    {
    public:
        CastRepentanceAction(PlayerbotAI* ai) : CastSpellAction(ai, "repentance on cc") {}
        virtual Value<Unit*>* GetTargetValue()
        {
            return context->GetValue<Unit*>("cc target", "repentance");
        }

        virtual bool Execute(Event event)
        {
            return ai->CastSpell("repentance", GetTarget());
        }
    };
}
