#pragma once
#include "../triggers/GenericTriggers.h"

namespace ai
{

    BUFF_TRIGGER(StealthTrigger, "stealth","stealth");
    BUFF_TRIGGER(RiposteTrigger, "riposte","riposte");
    DEBUFF_TRIGGER(GarroteTrigger, "garrote","garrote");
    DEBUFF_TRIGGER(SliceAndDiceTrigger, "slice and dice","slice and dice");
    DEBUFF_TRIGGER(RuptureTrigger, "rupture","rupture");
    DEBUFF_TRIGGER(HungerForBloodTrigger, "hunger for blood","hunger for blood");

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

    class KickInterruptEnemyHealerSpellTrigger : public InterruptEnemyHealerTrigger
    {
    public:
        KickInterruptEnemyHealerSpellTrigger(PlayerbotAI* ai) : InterruptEnemyHealerTrigger(ai, "kick") {}
    };
}
