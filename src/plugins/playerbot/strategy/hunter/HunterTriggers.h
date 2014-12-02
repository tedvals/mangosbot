#pragma once

#include "../triggers/GenericTriggers.h"

namespace ai
{
    BEGIN_TRIGGER(HunterNoStingsActiveTrigger, Trigger)
    END_TRIGGER()

    class HunterAspectOfTheHawkTrigger : public BuffTrigger
    {
    public:
        HunterAspectOfTheHawkTrigger(PlayerbotAI* ai) : BuffTrigger(ai, "aspect of the hawk") {
			checkInterval = 1;
		}
    };

    class HunterAspectOfTheDragonHawkTrigger : public BuffTrigger
    {
    public:
        HunterAspectOfTheDragonHawkTrigger(PlayerbotAI* ai) : BuffTrigger(ai, "aspect of the dragonhawk") {
			checkInterval = 1;
		}
    };

	class HunterAspectOfTheWildTrigger : public BuffTrigger
	{
	public:
		HunterAspectOfTheWildTrigger(PlayerbotAI* ai) : BuffTrigger(ai, "aspect of the wild") {
			checkInterval = 1;
		}
	};

    class HunterAspectOfTheViperTrigger : public BuffTrigger
    {
    public:
        HunterAspectOfTheViperTrigger(PlayerbotAI* ai) : BuffTrigger(ai, "aspect of the viper") {}
        virtual bool IsActive()
        {
            return SpellTrigger::IsActive() && !ai->HasAura(spell, GetTarget());
        }
    };

    class HunterAspectOfThePackTrigger : public BuffTrigger
    {
    public:
        HunterAspectOfThePackTrigger(PlayerbotAI* ai) : BuffTrigger(ai, "aspect of the pack") {}
        virtual bool IsActive() {
			return BuffTrigger::IsActive() && !ai->HasAura("aspect of the cheetah", GetTarget());
        };
    };

    BEGIN_TRIGGER(HuntersPetDeadTrigger, Trigger)
    END_TRIGGER()

    BEGIN_TRIGGER(HuntersPetLowHealthTrigger, Trigger)
    END_TRIGGER()

    DEBUFF_TRIGGER(BlackArrowTrigger, "black arrow", "black arrow")
    DEBUFF_TRIGGER(HuntersMarkTrigger, "hunter's mark", "hunter's mark")

    class FreezingTrapTrigger : public HasCcTargetTrigger
    {
    public:
        FreezingTrapTrigger(PlayerbotAI* ai) : HasCcTargetTrigger(ai, "freezing trap") {}
    };

    class RapidFireTrigger : public BoostTrigger
    {
    public:
        RapidFireTrigger(PlayerbotAI* ai) : BoostTrigger(ai, "rapid fire") {}
    };

    class KillCommandTrigger : public BoostTrigger
    {
    public:
        KillCommandTrigger(PlayerbotAI* ai) : BoostTrigger(ai, "kill command") {}
    };

    class KillShotTrigger : public BoostTrigger
    {
    public:
        KillShotTrigger(PlayerbotAI* ai) : BoostTrigger(ai, "kill shot") {}
    };

    class CounterstrikeTrigger : public BuffTrigger
    {
    public:
        CounterstrikeTrigger(PlayerbotAI* ai) : BuffTrigger(ai, "counterstrike") {}
    };

    class TrueshotAuraTrigger : public BuffTrigger
    {
    public:
        TrueshotAuraTrigger(PlayerbotAI* ai) : BuffTrigger(ai, "trueshot aura") {}
    };

    class SerpentStingOnAttackerTrigger : public DebuffOnAttackerTrigger
    {
    public:
        SerpentStingOnAttackerTrigger(PlayerbotAI* ai) : DebuffOnAttackerTrigger(ai, "serpent sting") {}
    };

    class ArcaneShotOnAttackerTrigger : public TargetAuraDispelTrigger
    {
    public:
        ArcaneShotOnAttackerTrigger(PlayerbotAI* ai) : TargetAuraDispelTrigger(ai, "arcane shot", DISPEL_MAGIC) {}
    };

    class SilencingShotEnemyHealerTrigger : public InterruptEnemyHealerTrigger
    {
    public:
        SilencingShotEnemyHealerTrigger(PlayerbotAI* ai) : InterruptEnemyHealerTrigger(ai, "silencing shot") {}
    };

    class WyvernStingTrigger : public HasCcTargetTrigger
    {
    public:
        WyvernStingTrigger(PlayerbotAI* ai) : HasCcTargetTrigger(ai, "wyvern sting") {}
    };
}
