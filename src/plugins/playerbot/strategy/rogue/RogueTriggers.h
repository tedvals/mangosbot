#pragma once
#include "../triggers/GenericTriggers.h"

namespace ai
{

    class StealthTrigger : public BuffTrigger
	{
	public:
		StealthTrigger(PlayerbotAI* ai) : BuffTrigger(ai, "stealth") {}
        virtual bool IsActive() { return BuffTrigger::IsActive() && !AI_VALUE2(bool, "combat", "self target"); }
    };

    BUFF_TRIGGER(RiposteTrigger, "riposte","riposte");
    BUFF_TRIGGER(SliceAndDiceTrigger, "slice and dice","slice and dice");

    class RuptureTrigger : public DebuffTrigger
	{
	public:
		RuptureTrigger(PlayerbotAI* ai) : DebuffTrigger(ai, "rupture") {}
		virtual bool IsActive() { return DebuffTrigger::IsActive() && ai->HasAura("slice and dice", bot);}
	};

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
	virtual bool IsActive() { return DebuffTrigger::IsActive() && !ai->HasAura("sunder armor", bot) && (AI_VALUE2(bool, "target boss", "current target"));}
    };

    class GarroteTrigger : public DebuffTrigger
    {
    public:
        GarroteTrigger(PlayerbotAI* ai) : DebuffTrigger(ai, "garrote") {}
        virtual bool IsActive() { return DebuffTrigger::IsActive() && ai->HasAura("stealth", bot);}
    };

    class KickInterruptEnemyHealerSpellTrigger : public InterruptEnemyHealerTrigger
    {
    public:
        KickInterruptEnemyHealerSpellTrigger(PlayerbotAI* ai) : InterruptEnemyHealerTrigger(ai, "kick") {}
    };

    class SapTrigger : public HasCcTarget4Trigger
    {
    public:
        SapTrigger(PlayerbotAI* ai) : HasCcTarget4Trigger(ai, "sap") {}
    };
}
