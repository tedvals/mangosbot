#pragma once
#include "../triggers/GenericTriggers.h"

namespace ai {
    class MarkOfTheWildOnPartyTrigger : public BuffOnPartyTrigger
    {
    public:
        MarkOfTheWildOnPartyTrigger(PlayerbotAI* ai) : BuffOnPartyTrigger(ai, "mark of the wild") {}
    };

    class MarkOfTheWildTrigger : public BuffTrigger
    {
    public:
        MarkOfTheWildTrigger(PlayerbotAI* ai) : BuffTrigger(ai, "mark of the wild") {}
    };

    class ThornsTrigger : public BuffTrigger
    {
    public:
        ThornsTrigger(PlayerbotAI* ai) : BuffTrigger(ai, "thorns") {}
    };

    class RakeTrigger : public DebuffTrigger
    {
    public:
        RakeTrigger(PlayerbotAI* ai) : DebuffTrigger(ai, "rake") {}
    };

    class RipTrigger : public DebuffTrigger
    {
    public:
        RipTrigger(PlayerbotAI* ai) : DebuffTrigger(ai, "rip") {}
    };

    class PounceTrigger : public DebuffTrigger
    {
    public:
        PounceTrigger(PlayerbotAI* ai) : DebuffTrigger(ai, "pounce") {}
    };

    class InsectSwarmTrigger : public DebuffTrigger
    {
    public:
        InsectSwarmTrigger(PlayerbotAI* ai) : DebuffTrigger(ai, "insect swarm") {}
    };

    class MoonfireTrigger : public DebuffTrigger
    {
    public:
        MoonfireTrigger(PlayerbotAI* ai) : DebuffTrigger(ai, "moonfire") {}
    };

    class FaerieFireTrigger : public DebuffTrigger
    {
    public:
        FaerieFireTrigger(PlayerbotAI* ai) : DebuffTrigger(ai, "faerie fire") {}
    };

    class FaerieFireFeralTrigger : public DebuffTrigger
    {
    public:
        FaerieFireFeralTrigger(PlayerbotAI* ai) : DebuffTrigger(ai, "faerie fire (feral)") {}
    };

    class BashInterruptSpellTrigger : public InterruptSpellTrigger
    {
    public:
        BashInterruptSpellTrigger(PlayerbotAI* ai) : InterruptSpellTrigger(ai, "bash") {}
    };

    class TigersFuryTrigger : public BoostTrigger
    {
    public:
        TigersFuryTrigger(PlayerbotAI* ai) : BoostTrigger(ai, "tiger's fury") {}
    };

    class NaturesGraspTrigger : public BoostTrigger
    {
    public:
        NaturesGraspTrigger(PlayerbotAI* ai) : BoostTrigger(ai, "nature's grasp") {}
    };

    class EntanglingRootsTrigger : public HasCcTarget2Trigger
    {
    public:
        EntanglingRootsTrigger(PlayerbotAI* ai) : HasCcTarget2Trigger(ai, "entangling roots") {}
    };

    class HibernateTrigger : public HasCcTarget3Trigger
    {
    public:
        HibernateTrigger(PlayerbotAI* ai) : HasCcTarget3Trigger(ai, "hibernate") {}
    };

    class CurePoisonTrigger : public NeedCureTrigger
    {
    public:
        CurePoisonTrigger(PlayerbotAI* ai) : NeedCureTrigger(ai, "cure poison", DISPEL_POISON) {}
    };

    class PartyMemberCurePoisonTrigger : public PartyMemberNeedCureTrigger
    {
    public:
        PartyMemberCurePoisonTrigger(PlayerbotAI* ai) : PartyMemberNeedCureTrigger(ai, "cure poison", DISPEL_POISON) {}
    };

    class BearFormTrigger : public BuffTrigger
    {
    public:
        BearFormTrigger(PlayerbotAI* ai) : BuffTrigger(ai, "bear form") {}
        virtual bool IsActive() { return !ai->HasAnyAuraOf(bot, "bear form", "dire bear form", NULL); }
    };

    class TreeFormTrigger : public BuffTrigger
    {
    public:
        TreeFormTrigger(PlayerbotAI* ai) : BuffTrigger(ai, "tree of life") {}
        virtual bool IsActive() { return !ai->HasAura("tree of life", bot); }
    };

    class SavageRoarTrigger : public BuffTrigger
    {
    public:
        SavageRoarTrigger(PlayerbotAI* ai) : BuffTrigger(ai, "savage roar") {}
        virtual bool IsActive() { return !ai->HasAura("savage roar", bot) && !ai->HasAura("cat form", bot); }
    };

    class CatFormTrigger : public BuffTrigger
    {
    public:
        CatFormTrigger(PlayerbotAI* ai) : BuffTrigger(ai, "cat form") {}
        virtual bool IsActive() { return !ai->HasAura("cat form", bot); }
    };

    class ProwlTrigger : public BuffTrigger
    {
    public:
        ProwlTrigger(PlayerbotAI* ai) : BuffTrigger(ai, "prowl") {}
        virtual bool IsActive() { return !ai->HasAura("prowl", bot); }
    };

    class DashTrigger : public BuffTrigger
    {
    public:
        DashTrigger(PlayerbotAI* ai) : BuffTrigger(ai, "dash") {}
        virtual bool IsActive() { return !ai->HasAura("dash", bot); }
    };

    class PredatorySwiftnessTrigger : public HasAuraTrigger
    {
    public:
        PredatorySwiftnessTrigger(PlayerbotAI* ai) : HasAuraTrigger(ai, "Predatory Swiftness") {}
    };

    class EclipseSolarTrigger : public HasAuraTrigger
    {
    public:
        EclipseSolarTrigger(PlayerbotAI* ai) : HasAuraTrigger(ai, "eclipse (solar)") {}
    };

    class EclipseLunarTrigger : public HasAuraTrigger
    {
    public:
        EclipseLunarTrigger(PlayerbotAI* ai) : HasAuraTrigger(ai, "eclipse (lunar)") {}
    };

    class BashInterruptEnemyHealerSpellTrigger : public InterruptEnemyHealerTrigger
    {
    public:
        BashInterruptEnemyHealerSpellTrigger(PlayerbotAI* ai) : InterruptEnemyHealerTrigger(ai, "bash") {}
    };
}