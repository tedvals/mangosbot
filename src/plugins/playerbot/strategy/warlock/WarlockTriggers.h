#pragma once
#include "../triggers/GenericTriggers.h"

namespace ai
{
	class DemonArmorTrigger : public BuffTrigger
	{
	public:
		DemonArmorTrigger(PlayerbotAI* ai) : BuffTrigger(ai, "demon armor") {}
		virtual bool IsActive();
	};

    class SpellstoneTrigger : public BuffTrigger
    {
    public:
        SpellstoneTrigger(PlayerbotAI* ai) : BuffTrigger(ai, "spellstone") {}
        virtual bool IsActive();
    };

    //BEGIN_TRIGGER(WarlockNoCurseTrigger, Trigger)
    //END_TRIGGER()

    //BEGIN_TRIGGER(WarlockNoCorruptionTrigger, Trigger)
    //END_TRIGGER()

    //DEBUFF_TRIGGER(CurseOfAgonyTrigger, "curse of agony", "curse of agony");
    //DEBUFF_TRIGGER(CorruptionTrigger, "corruption", "corruption");


    //class DeathCoilOnAttackerTrigger : public DebuffOnAttackerTrigger
    //{
    //public:
    //    DeathCoilOnAttackerTrigger(PlayerbotAI* ai) : DebuffOnAttackerTrigger(ai, "corruption") {}
    //};


    //BEGIN_TRIGGER(ImmolateTrigger, Trigger);
    //END_TRIGGER()

    class WarlockNoCurseTrigger : public DebuffTrigger
	{
	public:
		WarlockNoCurseTrigger(PlayerbotAI* ai) : DebuffTrigger(ai, "curse of agony") {}
		virtual bool IsActive();
	};

    class WarlockNoCorruptionTrigger : public DebuffTrigger
	{
	public:
		WarlockNoCorruptionTrigger(PlayerbotAI* ai) : DebuffTrigger(ai, "corruption") {}
		virtual bool IsActive();
	};

    class CorruptionOnAttackerTrigger : public DebuffOnAttackerTrigger
    {
    public:
        CorruptionOnAttackerTrigger(PlayerbotAI* ai) : DebuffOnAttackerTrigger(ai, "corruption on attacker") {}
        virtual bool IsActive();
    };


    class CurseOfAgonyOnAttackerTrigger : public DebuffTrigger
	{
	public:
		CurseOfAgonyOnAttackerTrigger(PlayerbotAI* ai) : DebuffTrigger(ai, "curse of agony on attacker") {}
		virtual bool IsActive();
	};


    //DEBUFF_TRIGGER(WarlockNoCurseTrigger, "curse of agony", "curse of agony");
    //DEBUFF_TRIGGER(WarlockNoCorruptionTrigger, "corruption", "corruption");
    DEBUFF_TRIGGER(ImmolateTrigger, "immolate", "immolate");
    DEBUFF_TRIGGER(HauntTrigger, "haunt", "haunt");
    DEBUFF_TRIGGER(ImprovedShadowbolt, "shadow Mastery", "shadow Mastery")

    class ShadowTranceTrigger : public HasAuraTrigger
    {
    public:
        ShadowTranceTrigger(PlayerbotAI* ai) : HasAuraTrigger(ai, "shadow trance") {}
    };

    class MoltenCoreTrigger : public HasAuraTrigger
    {
    public:
        MoltenCoreTrigger(PlayerbotAI* ai) : HasAuraTrigger(ai, "molten core") {}
    };

    class DecimationTrigger : public HasAuraTrigger
    {
    public:
        DecimationTrigger(PlayerbotAI* ai) : HasAuraTrigger(ai, "decimation") {}
    };

    class BacklashTrigger : public HasAuraTrigger
    {
    public:
        BacklashTrigger(PlayerbotAI* ai) : HasAuraTrigger(ai, "backlash") {}
    };

    class BanishTrigger : public HasCcTargetTrigger
    {
    public:
        BanishTrigger(PlayerbotAI* ai) : HasCcTargetTrigger(ai, "banish") {}
    };

    class WarlockConjuredItemTrigger : public ItemCountTrigger
    {
    public:
        WarlockConjuredItemTrigger(PlayerbotAI* ai, string item) : ItemCountTrigger(ai, item, 1) {}

        virtual bool IsActive() { return ItemCountTrigger::IsActive() && AI_VALUE2(uint8, "item count", "soul shard") > 0; }
    };

    class HasSpellstoneTrigger : public WarlockConjuredItemTrigger
    {
    public:
        HasSpellstoneTrigger(PlayerbotAI* ai) : WarlockConjuredItemTrigger(ai, "spellstone") {}
    };

    class HasFirestoneTrigger : public WarlockConjuredItemTrigger
    {
    public:
        HasFirestoneTrigger(PlayerbotAI* ai) : WarlockConjuredItemTrigger(ai, "firestone") {}
    };

    class HasHealthstoneTrigger : public WarlockConjuredItemTrigger
    {
    public:
        HasHealthstoneTrigger(PlayerbotAI* ai) : WarlockConjuredItemTrigger(ai, "healthstone") {}
    };

    class FearTrigger : public HasCcTargetTrigger
    {
    public:
        FearTrigger(PlayerbotAI* ai) : HasCcTargetTrigger(ai, "fear") {}
    };

}
