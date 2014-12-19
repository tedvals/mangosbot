#pragma once
#include "../triggers/GenericTriggers.h"

namespace ai
{

    BUFF_TRIGGER(StealthTrigger, "stealth","stealth");
    BUFF_TRIGGER(RiposteTrigger, "riposte","riposte");
    BUFF_TRIGGER(SliceAndDiceTrigger, "slice and dice","slice and dice");
    DEBUFF_TRIGGER(RuptureTrigger, "rupture","rupture");
    DEBUFF_TRIGGER(PremeditationTrigger, "premeditation","premeditation");
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

    class GarroteTrigger : public DebuffTrigger
    {
    public:
        GarroteTrigger(PlayerbotAI* ai) : DebuffTrigger(ai, "garrote") {}
    };

    class KickInterruptEnemyHealerSpellTrigger : public InterruptEnemyHealerTrigger
    {
    public:
        KickInterruptEnemyHealerSpellTrigger(PlayerbotAI* ai) : InterruptEnemyHealerTrigger(ai, "kick") {}
    };

  //  class SapTrigger : public HasCcTarget4Trigger
  //  {
  //  public:
  //      SapTrigger(PlayerbotAI* ai) : HasCcTarget4Trigger(ai, "sap") {}
//};
}
