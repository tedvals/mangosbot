#pragma once
#include "../triggers/GenericTriggers.h"

namespace ai
{
    BUFF_TRIGGER(BattleShoutTrigger, "battle shout", "battle shout")
    BUFF_TRIGGER(VigilanceOnMasterTrigger, "vigilance", "vigilance on master")

    DEBUFF_TRIGGER(RendDebuffTrigger, "rend", "rend")
    DEBUFF_TRIGGER(DemoralizingShoutDebuffTrigger, "demoralizing shout", "demoralizing shout")
    DEBUFF_TRIGGER(DisarmDebuffTrigger, "disarm", "disarm")
    DEBUFF_TRIGGER(SunderArmorDebuffTrigger, "sunder armor", "sunder armor")

    class RendDebuffOnAttackerTrigger : public DebuffOnAttackerTrigger
    {
    public:
        RendDebuffOnAttackerTrigger(PlayerbotAI* ai) : DebuffOnAttackerTrigger(ai, "rend") {}
    };

	class RevengeAvailableTrigger : public SpellCanBeCastTrigger
	{
	public:
		RevengeAvailableTrigger(PlayerbotAI* ai) : SpellCanBeCastTrigger(ai, "revenge") {}
	};

    class BloodrageDebuffTrigger : public DebuffTrigger
    {
    public:
        BloodrageDebuffTrigger(PlayerbotAI* ai) : DebuffTrigger(ai, "bloodrage") {}
        virtual bool IsActive()
        {
            return DebuffTrigger::IsActive() &&
                AI_VALUE2(uint8, "health", "self target") >= 75 &&
                AI_VALUE2(uint8, "rage", "self target") < 20;
        }
    };

    class ShieldBashInterruptSpellTrigger : public InterruptSpellTrigger
    {
    public:
        ShieldBashInterruptSpellTrigger(PlayerbotAI* ai) : InterruptSpellTrigger(ai, "shield bash") {}
    };

    class BloodsurgeTrigger : public HasAuraTrigger
    {
    public:
        BloodsurgeTrigger(PlayerbotAI* ai) : HasAuraTrigger(ai, "bloodsurge") {}
    };

    class TasteForBloodTrigger : public HasAuraTrigger
    {
    public:
        TasteForBloodTrigger(PlayerbotAI* ai) : HasAuraTrigger(ai, "taste for blood") {}
    };

    class SuddenDeathTrigger : public HasAuraTrigger
    {
    public:
        SuddenDeathTrigger(PlayerbotAI* ai) : HasAuraTrigger(ai, "sudden death") {}
    };

    class VictoryRushTrigger : public HasAuraTrigger
    {
    public:
        VictoryRushTrigger(PlayerbotAI* ai) : HasAuraTrigger(ai, "victory rush") {}
    };

    class SwordAndBoardTrigger : public HasAuraTrigger
    {
    public:
        SwordAndBoardTrigger(PlayerbotAI* ai) : HasAuraTrigger(ai, "sword and board") {}
    };

    class ConcussionBlowTrigger : public SnareTargetTrigger
    {
    public:
        ConcussionBlowTrigger(PlayerbotAI* ai) : SnareTargetTrigger(ai, "concussion blow") {}
    };

    class HamstringTrigger : public SnareTargetTrigger
    {
    public:
        HamstringTrigger(PlayerbotAI* ai) : SnareTargetTrigger(ai, "hamstring") {}
    };

    //class DeathWishTrigger : public BoostTrigger
    //{
    //public:
    //    DeathWishTrigger(PlayerbotAI* ai) : BoostTrigger(ai, "death wish") {}
    //};

    class ShieldBashInterruptEnemyHealerSpellTrigger : public InterruptEnemyHealerTrigger
    {
    public:
        ShieldBashInterruptEnemyHealerSpellTrigger(PlayerbotAI* ai) : InterruptEnemyHealerTrigger(ai, "shield bash") {}
    };

}