#pragma once
#include "../triggers/GenericTriggers.h"

namespace ai
{

    BUFF_TRIGGER(StealthTrigger, "stealth","stealth");
    BUFF_TRIGGER(RiposteTrigger, "riposte","riposte");
    BUFF_TRIGGER(SliceAndDiceTrigger, "slice and dice","slice and dice");
    DEBUFF_TRIGGER(RuptureTrigger, "rupture","rupture");
    DEBUFF_TRIGGER(HungerForBloodTrigger, "hunger for blood","hunger for blood");

    class PoisonWeaponTrigger : public BuffTrigger {
    public:
        PoisonWeaponTrigger(PlayerbotAI* ai) : BuffTrigger(ai, "instant poison") {}
        virtual bool IsActive();
    private:
        static list<string> spells;
    };

    class KickInterruptSpellTrigger : public InterruptSpellTrigger
    {
    public:
        KickInterruptSpellTrigger(PlayerbotAI* ai) : InterruptSpellTrigger(ai, "kick") {}
    };

    class GougeInterruptSpellTrigger : public InterruptSpellTrigger
    {
    public:
        GougeInterruptSpellTrigger(PlayerbotAI* ai) : InterruptSpellTrigger(ai, "gauge") {}
    };

    class ExposeArmorTrigger : public DebuffTrigger
    {
    public:
        ExposeArmorTrigger(PlayerbotAI* ai) : DebuffTrigger(ai, "expose armor") {}
    };

    class GarroteTrigger : public DebuffTrigger
    {
    public:
        GarroteTrigger(PlayerbotAI* ai) : DebuffTrigger(ai, "garrote") {}
        virtual bool IsActive()
        {
            return DebuffTrigger::IsActive() &&
                ai->HasAura("stealth", AI_VALUE(Unit*, "self target"));
        }
    };

    class KickInterruptEnemyHealerSpellTrigger : public InterruptEnemyHealerTrigger
    {
    public:
        KickInterruptEnemyHealerSpellTrigger(PlayerbotAI* ai) : InterruptEnemyHealerTrigger(ai, "kick") {}
    };
}
