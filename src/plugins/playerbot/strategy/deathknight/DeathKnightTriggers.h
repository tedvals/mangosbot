#pragma once
#include "../triggers/GenericTriggers.h"

namespace ai
{
    BUFF_TRIGGER(HornOfWinterTrigger, "horn of winter", "horn of winter")
    BUFF_TRIGGER(BoneShieldTrigger, "bone shield", "bone shield")
    BUFF_TRIGGER(BloodPresenceTrigger, "blood presence", "blood presence")
    BUFF_TRIGGER(FrostPresenceTrigger, "frost presence", "frost presence")
    BUFF_TRIGGER(UnholyPresenceTrigger, "unholy presence", "unholy presence")

    DEBUFF_TRIGGER(FrostFeverDebuffTrigger, "frost fever", "frost fever")
    DEBUFF_TRIGGER(BloodPlagueDebuffTrigger, "blood plague", "blood plague")


    class FrostFeverDebuffOnAttackerTrigger : public DebuffOnAttackerTrigger
    {
    public:
        FrostFeverDebuffOnAttackerTrigger(PlayerbotAI* ai) : DebuffOnAttackerTrigger(ai, "frost fever") {}
    };

    class MindFreezeInterruptSpellTrigger : public InterruptSpellTrigger
    {
    public:
        MindFreezeInterruptSpellTrigger(PlayerbotAI* ai) : InterruptSpellTrigger(ai, "mind freeze") {}
    };

    class SuddenDoomTrigger : public HasAuraTrigger
    {
    public:
        SuddenDoomTrigger(PlayerbotAI* ai) : HasAuraTrigger(ai, "sudden doom") {}
    };

    class KillingMachineTrigger : public HasAuraTrigger
    {
    public:
        KillingMachineTrigger(PlayerbotAI* ai) : HasAuraTrigger(ai, "killing machine") {}
    };

    class FreezingFogTrigger : public HasAuraTrigger
    {
    public:
        FreezingFogTrigger(PlayerbotAI* ai) : HasAuraTrigger(ai, "freezing fog") {}
    };

    class ChainsOfIceTrigger : public SnareTargetTrigger
    {
    public:
        ChainsOfIceTrigger(PlayerbotAI* ai) : SnareTargetTrigger(ai, "chains of ice") {}
    };

    //class DeathWishTrigger : public BoostTrigger
    //{
    //public:
    //    DeathWishTrigger(PlayerbotAI* ai) : BoostTrigger(ai, "death wish") {}
    //};

    class StrangulateInterruptEnemyHealerSpellTrigger : public InterruptEnemyHealerTrigger
    {
    public:
        StrangulateInterruptEnemyHealerSpellTrigger(PlayerbotAI* ai) : InterruptEnemyHealerTrigger(ai, "strangulate") {}
    };

	BEGIN_TRIGGER(GhoulPetDeadTrigger, Trigger)
    END_TRIGGER()
}
