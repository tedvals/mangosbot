#pragma once

#include "../actions/GenericActions.h"

namespace ai
{
    class CastLesserHealingWaveAction : public CastHealingSpellAction {
    public:
        CastLesserHealingWaveAction(PlayerbotAI* ai) : CastHealingSpellAction(ai, "lesser healing wave") {}

        virtual NextAction** getAlternatives()
        {
            return NextAction::merge( NextAction::array(0, new NextAction("healing wave"), NULL), CastHealingSpellAction::getAlternatives());
        }
    };

    class CastLesserHealingWaveOnPartyAction : public HealPartyMemberAction
    {
    public:
        CastLesserHealingWaveOnPartyAction(PlayerbotAI* ai) : HealPartyMemberAction(ai, "lesser healing wave") {}

        virtual NextAction** getAlternatives()
        {
            return NextAction::merge( NextAction::array(0, new NextAction("healing wave on party"), NULL), HealPartyMemberAction::getAlternatives());
        }
    };

    class CastHealingWaveAction : public CastHealingSpellAction {
    public:
        CastHealingWaveAction(PlayerbotAI* ai) : CastHealingSpellAction(ai, "healing wave") {}
    };

    class CastHealingWaveOnPartyAction : public HealPartyMemberAction
    {
    public:
        CastHealingWaveOnPartyAction(PlayerbotAI* ai) : HealPartyMemberAction(ai, "healing wave") {}
    };

    class CastChainHealAction : public CastAoeHealSpellAction {
    public:
        CastChainHealAction(PlayerbotAI* ai) : CastAoeHealSpellAction(ai, "chain heal") {}
    };

    class CastRiptideAction : public CastHealingSpellAction {
    public:
        CastRiptideAction(PlayerbotAI* ai) : CastHealingSpellAction(ai, "riptide") {}
    };

    class CastRiptideOnPartyAction : public HealPartyMemberAction
    {
    public:
        CastRiptideOnPartyAction(PlayerbotAI* ai) : HealPartyMemberAction(ai, "riptide") {}
    };


    class CastEarthShieldAction : public CastBuffSpellAction {
    public:
        CastEarthShieldAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "earth shield") {}
    };

    class CastEarthShieldOnPartyAction : public BuffOnPartyAction
    {
    public:
        CastEarthShieldOnPartyAction(PlayerbotAI* ai) : BuffOnPartyAction(ai, "earth shield") {}
        virtual bool isUseful();
    };

    class CastEarthShieldOnMasterAction : public BuffOnPartyAction
    {
    public:
        CastEarthShieldOnMasterAction(PlayerbotAI* ai) : BuffOnPartyAction(ai, "earth shield") {}
        virtual string getName() { return "earth shield on master";}
        virtual string GetTargetName() { return "master target";}
    };

    class CastWaterShieldAction : public CastBuffSpellAction {
    public:
        CastWaterShieldAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "water shield") {}
    };

	class CastLightningShieldAction : public CastBuffSpellAction {
	public:
		CastLightningShieldAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "lightning shield") {}
	};

    class CastEarthlivingWeaponAction : public CastEnchantItemAction {
    public:
        CastEarthlivingWeaponAction(PlayerbotAI* ai) : CastEnchantItemAction(ai, "earthliving weapon") {}

        virtual NextAction** getAlternatives()
        {
            return NextAction::merge( NextAction::array(0, new NextAction("flametongue weapon"), NULL), CastEnchantItemAction::getAlternatives());
        }
    };

    class CastRockbiterWeaponAction : public CastEnchantItemAction {
    public:
        CastRockbiterWeaponAction(PlayerbotAI* ai) : CastEnchantItemAction(ai, "rockbiter weapon") {}
    };

    class CastFlametongueWeaponAction : public CastEnchantItemAction {
    public:
        CastFlametongueWeaponAction(PlayerbotAI* ai) : CastEnchantItemAction(ai, "flametongue weapon") {}
    };

    class CastFrostbrandWeaponAction : public CastEnchantItemAction {
    public:
        CastFrostbrandWeaponAction(PlayerbotAI* ai) : CastEnchantItemAction(ai, "frostbrand weapon") {}
    };

    class CastWindfuryWeaponAction : public CastEnchantItemAction {
    public:
        CastWindfuryWeaponAction(PlayerbotAI* ai) : CastEnchantItemAction(ai, "windfury weapon") {}

        virtual NextAction** getAlternatives()
        {
            return NextAction::merge( NextAction::array(0, new NextAction("flametongue weapon"), NULL), CastEnchantItemAction::getAlternatives());
        }
    };

    class CastTotemAction : public CastBuffSpellAction
    {
    public:
        CastTotemAction(PlayerbotAI* ai, string spell) : CastBuffSpellAction(ai, spell) {}
        virtual bool isUseful() { return CastBuffSpellAction::isUseful() && !AI_VALUE2(bool, "has totem", name); }
    };

    class CastStoneskinTotemAction : public CastTotemAction
    {
    public:
        CastStoneskinTotemAction(PlayerbotAI* ai) : CastTotemAction(ai, "stoneskin totem") {}
        virtual bool isUseful() { return !ai->HasAnyAuraOf(GetTarget(), "devotion aura", NULL);}
    };

    class CastEarthbindTotemAction : public CastBuffSpellAction
    {
    public:
        CastEarthbindTotemAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "earthbind totem") {}
    };

    class CastTremorTotemAction : public CastBuffSpellAction
    {
    public:
        CastTremorTotemAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "tremor totem") {}
    };

    class CastStoneclawTotemAction : public CastBuffSpellAction
    {
    public:
        CastStoneclawTotemAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "stoneclaw totem") {}
    };

    class CastTremorTotemOnPartyAction : public DispelCharmPartyMemberAction
    {
    public:
        CastTremorTotemOnPartyAction(PlayerbotAI* ai) : DispelCharmPartyMemberAction(ai, "tremor totem on party") {}
    };

    class CastStrengthOfEarthTotemAction : public CastTotemAction
    {
    public:
        CastStrengthOfEarthTotemAction(PlayerbotAI* ai) : CastTotemAction(ai, "strength of earth totem") {}
    };

    class CastManaSpringTotemAction : public CastTotemAction
    {
    public:
        CastManaSpringTotemAction(PlayerbotAI* ai) : CastTotemAction(ai, "mana spring totem") {}
    };

	class CastManaTideTotemAction : public CastTotemAction
	{
	public:
		CastManaTideTotemAction(PlayerbotAI* ai) : CastTotemAction(ai, "mana tide totem") {}
		virtual string GetTargetName() { return "self target"; }
	};

	class CastHealingStreamTotemAction : public CastTotemAction
	{
	public:
		CastHealingStreamTotemAction(PlayerbotAI* ai) : CastTotemAction(ai, "healing stream totem") {}
	};

    class CastCleansingTotemAction : public CastBuffSpellAction
    {
    public:
        CastCleansingTotemAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "cleansing totem") {}
    };

    class CastCallOfTheElementsTotemAction : public CastBuffSpellAction
    {
    public:
        CastCallOfTheElementsTotemAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "call of the elements") {}
    };

    class CastCallOfTheAncestorsTotemAction : public CastBuffSpellAction
    {
    public:
        CastCallOfTheAncestorsTotemAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "call of the ancestors") {}
    };

    class CastCallOfTheSpiritsTotemAction : public CastBuffSpellAction
    {
    public:
        CastCallOfTheSpiritsTotemAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "call of the spirits") {}
    };

    class CastFlametongueTotemAction : public CastTotemAction
    {
    public:
        CastFlametongueTotemAction(PlayerbotAI* ai) : CastTotemAction(ai, "flametongue totem") {}
    };

    class CastWindfuryTotemAction : public CastTotemAction
    {
    public:
        CastWindfuryTotemAction(PlayerbotAI* ai) : CastTotemAction(ai, "windfury totem") {}
    };

    class CastTotemOfWrathAction : public CastTotemAction
    {
    public:
        CastTotemOfWrathAction(PlayerbotAI* ai) : CastTotemAction(ai, "totem of wrath") {}
    };

    class CastWrathOfAirTotemAction : public CastTotemAction
    {
    public:
        CastWrathOfAirTotemAction(PlayerbotAI* ai) : CastTotemAction(ai, "wrath of air totem") {}
    };

    class CastSearingTotemAction : public CastTotemAction
    {
    public:
        CastSearingTotemAction(PlayerbotAI* ai) : CastTotemAction(ai, "searing totem") {}
        virtual string GetTargetName() { return "self target"; }
    };

    class CastMagmaTotemAction : public CastMeleeSpellAction
    {
    public:
        CastMagmaTotemAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "magma totem") {}
        virtual string GetTargetName() { return "self target"; }
        virtual bool isUseful() { return CastMeleeSpellAction::isUseful() && !AI_VALUE2(bool, "has totem", name); }
    };

    class CastFireNovaAction : public CastSpellAction {
    public:
        CastFireNovaAction(PlayerbotAI* ai) : CastSpellAction(ai, "fire nova") {}
    };

    class CastWindShearAction : public CastSpellAction {
    public:
        CastWindShearAction(PlayerbotAI* ai) : CastSpellAction(ai, "wind shear") {}
    };

	class CastAncestralSpiritAction : public ResurrectPartyMemberAction
	{
	public:
		CastAncestralSpiritAction(PlayerbotAI* ai) : ResurrectPartyMemberAction(ai, "ancestral spirit") {}
	};

	class CastPurgeAction : public CastSpellAction
	{
	public:
		CastPurgeAction(PlayerbotAI* ai) : CastSpellAction(ai, "purge") {}
	};

	class CastStormstrikeAction : public CastMeleeSpellAction {
	public:
		CastStormstrikeAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "stormstrike") {}
	};

	class CastLavaLashAction : public CastMeleeSpellAction {
	public:
		CastLavaLashAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "lava lash") {}
	};

    class CastWaterBreathingAction : public CastBuffSpellAction {
    public:
        CastWaterBreathingAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "water breathing") {}
    };

    class CastWaterWalkingAction : public CastBuffSpellAction {
    public:
        CastWaterWalkingAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "water walking") {}
    };

    class CastWaterBreathingOnPartyAction : public BuffOnPartyAction {
    public:
        CastWaterBreathingOnPartyAction(PlayerbotAI* ai) : BuffOnPartyAction(ai, "water breathing") {}
    };

    class CastWaterWalkingOnPartyAction : public BuffOnPartyAction {
    public:
        CastWaterWalkingOnPartyAction(PlayerbotAI* ai) : BuffOnPartyAction(ai, "water walking") {}
    };


    class CastCleanseSpiritAction : public CastCureSpellAction {
    public:
        CastCleanseSpiritAction(PlayerbotAI* ai) : CastCureSpellAction(ai, "cleanse spirit") {}
    };

    class CastCleanseSpiritPoisonOnPartyAction : public CurePartyMemberAction
    {
    public:
        CastCleanseSpiritPoisonOnPartyAction(PlayerbotAI* ai) : CurePartyMemberAction(ai, "cleanse spirit", DISPEL_POISON) {}

        virtual string getName() { return "cleanse spirit poison on party"; }
    };
    class CastCleanseSpiritCurseOnPartyAction : public CurePartyMemberAction
    {
    public:
        CastCleanseSpiritCurseOnPartyAction(PlayerbotAI* ai) : CurePartyMemberAction(ai, "cleanse spirit", DISPEL_CURSE) {}

        virtual string getName() { return "cleanse spirit curse on party"; }
    };
    class CastCleanseSpiritDiseaseOnPartyAction : public CurePartyMemberAction
    {
    public:
        CastCleanseSpiritDiseaseOnPartyAction(PlayerbotAI* ai) : CurePartyMemberAction(ai, "cleanse spirit", DISPEL_DISEASE) {}

        virtual string getName() { return "cleanse spirit disease on party"; }
    };

    class CastFlameShockAction : public CastDebuffSpellAction
    {
    public:
        CastFlameShockAction(PlayerbotAI* ai) : CastDebuffSpellAction(ai, "flame shock") {}
    };

    class CastEarthShockAction : public CastDebuffSpellAction
    {
    public:
        CastEarthShockAction(PlayerbotAI* ai) : CastDebuffSpellAction(ai, "earth shock") {}
    };

    class CastFrostShockAction : public CastDebuffSpellAction
    {
    public:
        CastFrostShockAction(PlayerbotAI* ai) : CastDebuffSpellAction(ai, "frost shock") {}

         virtual bool isUseful()
        {
           return CastDebuffSpellAction::isUseful() && !ai->HasAnyAuraOf(GetTarget(), "slow", "wing clip", "frost shock", "crippling poison", "hamstring", NULL);
        }
    };

    class CastChainLightningAction : public CastSpellAction
    {
    public:
        CastChainLightningAction(PlayerbotAI* ai) : CastSpellAction(ai, "chain lightning") {}
    };

    class CastLightningBoltAction : public CastSpellAction
    {
    public:
        CastLightningBoltAction(PlayerbotAI* ai) : CastSpellAction(ai, "lightning bolt") {}
    };

     class CastLavaBurstAction : public CastSpellAction
    {
    public:
        CastLavaBurstAction(PlayerbotAI* ai) : CastSpellAction(ai, "lava burst") {}
    };

    class CastThunderstormAction : public CastMeleeSpellAction
    {
    public:
        CastThunderstormAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "thunderstorm") {}
    };

    class CastHeroismAction : public CastBuffSpellAction
    {
    public:
        CastHeroismAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "heroism") {}
        NextAction** getAlternatives()
        {
            return NextAction::merge( NextAction::array(0, new NextAction("bloodlust"), NULL), CastBuffSpellAction::getPrerequisites());
        }
    };

    class CastBloodlustAction : public CastBuffSpellAction
    {
    public:
        CastBloodlustAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "bloodlust") {}
        NextAction** getAlternatives()
        {
            return NextAction::merge( NextAction::array(0, new NextAction("heroism"), NULL), CastBuffSpellAction::getPrerequisites());
        }
    };

    class CastWindShearOnEnemyHealerAction : public CastSpellOnEnemyHealerAction
    {
    public:
        CastWindShearOnEnemyHealerAction(PlayerbotAI* ai) : CastSpellOnEnemyHealerAction(ai, "wind shear") {}
    };

    class CastSummonEarthElementalAction : public CastBuffSpellAction
    {
    public:
        CastSummonEarthElementalAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "earth elemental totem") {}
    };

    class CastSummonFireElementalAction : public CastBuffSpellAction
    {
    public:
        CastSummonFireElementalAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "fire elemental totem") {}
    };

    class CastElementalMasteryAction : public CastBuffSpellAction
    {
    public:
        CastElementalMasteryAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "elemental mastery") {}
    };

    class CastFeralSpiritAction : public CastBuffSpellAction
    {
    public:
        CastFeralSpiritAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "feral spirit") {}
    };

    class CastTidalForceAction : public CastBuffSpellAction
    {
    public:
        CastTidalForceAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "tidal force") {}
    };

    class CastShamanisticRageAction : public CastBuffSpellAction
    {
    public:
        CastShamanisticRageAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "shamanistic rage") {}
    };

    class CastNaturesSwiftnessAction : public CastBuffSpellAction
    {
    public:
        CastNaturesSwiftnessAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "nature's swiftness") {}
    };

    class CastHexAction : public CastDebuffSpellAction
    {
    public:
        CastHexAction(PlayerbotAI* ai) : CastDebuffSpellAction(ai, "hex") {}
    };

    class CastHexCcAction : public CastSpellAction
    {
    public:
        CastHexCcAction(PlayerbotAI* ai) : CastSpellAction(ai, "hex on cc") {}
        virtual Value<Unit*>* GetTargetValue()
        {
            return context->GetValue<Unit*>("cc target", "hex");
        }
        virtual bool Execute(Event event)
        {
            return ai->CastSpell("hex", GetTarget());
        }
    };

}