#pragma once

#include "HealthTriggers.h"
#include "GenericTriggers.h"
#include "LootTriggers.h"
#include "../triggers/GenericTriggers.h"
#include "LfgTriggers.h"

namespace ai
{

    class TriggerContext : public NamedObjectContext<Trigger>
    {
    public:
        TriggerContext()
        {
            creators["timer"] = &TriggerContext::Timer;
            creators["random"] = &TriggerContext::Random;
            creators["seldom"] = &TriggerContext::seldom;
            creators["often"] = &TriggerContext::often;

            creators["target critical health"] = &TriggerContext::TargetCriticalHealth;
            creators["target almost dead"] = &TriggerContext::TargetAlmostDead;

            creators["critical health"] = &TriggerContext::CriticalHealth;
            creators["low health"] = &TriggerContext::LowHealth;
            creators["medium health"] = &TriggerContext::MediumHealth;
            creators["high health"] = &TriggerContext::HighHealth;
            creators["almost full health"] = &TriggerContext::AlmostFullHealth;
            creators["almost dead"] = &TriggerContext::AlmostDead;

            creators["low mana"] = &TriggerContext::LowMana;
            creators["medium mana"] = &TriggerContext::MediumMana;

            creators["party member almost dead"] = &TriggerContext::PartyMemberAlmostDead;
            creators["party member critical health"] = &TriggerContext::PartyMemberCriticalHealth;
            creators["party member low health"] = &TriggerContext::PartyMemberLowHealth;
            creators["party member medium health"] = &TriggerContext::PartyMemberMediumHealth;
            creators["party member high health"] = &TriggerContext::PartyMemberHighHealth;
            creators["party member almost full health"] = &TriggerContext::PartyMemberAlmostFullHealth;

            creators["light rage available"] = &TriggerContext::LightRageAvailable;
            creators["medium rage available"] = &TriggerContext::MediumRageAvailable;
            creators["high rage available"] = &TriggerContext::HighRageAvailable;

            creators["light energy available"] = &TriggerContext::LightEnergyAvailable;
            creators["medium energy available"] = &TriggerContext::MediumEnergyAvailable;
            creators["high energy available"] = &TriggerContext::HighEnergyAvailable;

            creators["loot available"] = &TriggerContext::LootAvailable;
            creators["no attackers"] = &TriggerContext::NoAttackers;
            creators["no target"] = &TriggerContext::NoTarget;
            creators["target in sight"] = &TriggerContext::TargetInSight;
            creators["not least hp target active"] = &TriggerContext::not_least_hp_target_active;
            creators["has nearest adds"] = &TriggerContext::has_nearest_adds;
            creators["enemy player is attacking"] = &TriggerContext::enemy_player_is_attacking;

            creators["tank aoe"] = &TriggerContext::TankAoe;
            creators["lose aggro"] = &TriggerContext::LoseAggro;
            creators["have aggro"] = &TriggerContext::HasAggro;

            creators["no aoe"] = &TriggerContext::NoAoe;
            creators["light aoe"] = &TriggerContext::LightAoe;
            creators["medium aoe"] = &TriggerContext::MediumAoe;
            creators["high aoe"] = &TriggerContext::HighAoe;

            creators["enemy out of melee"] = &TriggerContext::EnemyOutOfMelee;
            creators["enemy out of spell"] = &TriggerContext::EnemyOutOfSpell;
            creators["enemy too close for spell"] = &TriggerContext::enemy_too_close_for_spell;
            creators["enemy too close for melee"] = &TriggerContext::enemy_too_close_for_melee;

            creators["combo points available"] = &TriggerContext::ComboPointsAvailable;
            creators["combo point available"] = &TriggerContext::ComboPointAvailable;

            creators["medium threat"] = &TriggerContext::MediumThreat;

            creators["dead"] = &TriggerContext::Dead;
            creators["is rooted"] = &TriggerContext::Rooted;
            creators["is frozen"] = &TriggerContext::Frozen;
            creators["is snared"] = &TriggerContext::Snared;
            creators["is bleeding"] = &TriggerContext::Bleeding;
            creators["is stunned"] = &TriggerContext::Stunned;
            creators["is disoriented"] = &TriggerContext::Disoriented;
            creators["is possessed"] = &TriggerContext::Possessed;
            creators["is charmed"] = &TriggerContext::Charmed;
            creators["is silenced"] = &TriggerContext::Silenced;

            creators["is polymorphed"] = &TriggerContext::Polymorphed;
            creators["takes periodic damage"] = &TriggerContext::TakesPeriodicDamage;

            creators["party member dead"] = &TriggerContext::PartyMemberDead;
            creators["no pet"] = &TriggerContext::no_pet;
            creators["has attackers"] = &TriggerContext::has_attackers;
            creators["no possible targets"] = &TriggerContext::no_possible_targets;

            creators["no drink"] = &TriggerContext::no_drink;
            creators["no food"] = &TriggerContext::no_food;

            creators["mainhand not enhanced"] = &TriggerContext::Mainhand_not_enhanced;
            creators["offhand not enhanced"] = &TriggerContext::Offhand_not_enhanced;

            creators["panic"] = &TriggerContext::panic;
            creators["behind target"] = &TriggerContext::behind_target;
            creators["not facing target"] = &TriggerContext::not_facing_target;
            creators["far from master"] = &TriggerContext::far_from_master;
            creators["far from loot target"] = &TriggerContext::far_from_loot_target;
            creators["can loot"] = &TriggerContext::can_loot;
            creators["swimming"] = &TriggerContext::swimming;
            creators["target changed"] = &TriggerContext::target_changed;

            creators["enemy rooted"] = &TriggerContext::Target_Rooted;
            creators["enemy frozen"] = &TriggerContext::Target_Frozen;
            creators["enemy snared"] = &TriggerContext::Target_Snared;
            creators["enemy bleeding"] = &TriggerContext::Target_Bleeding;
            creators["enemy stunned"] = &TriggerContext::Target_Stunned;
            creators["enemy polymorphed"] = &TriggerContext::Target_Polymorphed;
            creators["enemy disoriented"] = &TriggerContext::Target_Disoriented;
            creators["enemy possessed"] = &TriggerContext::Target_Possessed;
            creators["enemy charmed"] = &TriggerContext::Target_Charmed;
            creators["enemy silenced"] = &TriggerContext::Target_Silenced;

            creators["party member rooted"] = &TriggerContext::Party_Member_Rooted;
            creators["party member frozen"] = &TriggerContext::Party_Member_Frozen;
            creators["party member snared"] = &TriggerContext::Party_Member_Snared;
            creators["party member polymorphed"] = &TriggerContext::Party_Member_Polymorphed;
            creators["party member charmed"] = &TriggerContext::Party_Member_Charmed;
            creators["party member possessed"] = &TriggerContext::Party_Member_Possessed;

            creators["target not rooted"] = &TriggerContext::Target_NotRooted;
            creators["target not frozen"] = &TriggerContext::Target_NotFrozen;
            creators["target not snared"] = &TriggerContext::Target_NotSnared;
            creators["target not bleeding"] = &TriggerContext::Target_NotBleeding;
            creators["target not stunned"] = &TriggerContext::Target_NotStunned;

            creators["critical aoe heal"] = &TriggerContext::critical_aoe_heal;
            creators["low aoe heal"] = &TriggerContext::low_aoe_heal;
            creators["medium aoe heal"] = &TriggerContext::medium_aoe_heal;
            creators["almost full aoe heal"] = &TriggerContext::almost_full_aoe_heal;
            creators["invalid target"] = &TriggerContext::invalid_target;
            creators["lfg proposal active"] = &TriggerContext::lfg_proposal_active;
        }

    private:
        static Trigger* lfg_proposal_active(PlayerbotAI* ai) { return new LfgProposalActiveTrigger(ai); }
        static Trigger* invalid_target(PlayerbotAI* ai) { return new InvalidTargetTrigger(ai); }
        static Trigger* critical_aoe_heal(PlayerbotAI* ai) { return new AoeHealTrigger(ai, "critical aoe heal", "critical", 2); }
        static Trigger* low_aoe_heal(PlayerbotAI* ai) { return new AoeHealTrigger(ai, "low aoe heal", "low", 2); }
        static Trigger* medium_aoe_heal(PlayerbotAI* ai) { return new AoeHealTrigger(ai, "medium aoe heal", "medium", 2); }
        static Trigger* almost_full_aoe_heal(PlayerbotAI* ai) { return new AoeHealTrigger(ai, "almost full aoe heal", "almost full", 2); }
        static Trigger* target_changed(PlayerbotAI* ai) { return new TargetChangedTrigger(ai); }
        static Trigger* swimming(PlayerbotAI* ai) { return new IsSwimmingTrigger(ai); }
        static Trigger* no_possible_targets(PlayerbotAI* ai) { return new NoPossibleTargetsTrigger(ai); }
        static Trigger* can_loot(PlayerbotAI* ai) { return new CanLootTrigger(ai); }
        static Trigger* far_from_loot_target(PlayerbotAI* ai) { return new FarFromCurrentLootTrigger(ai); }
        static Trigger* far_from_master(PlayerbotAI* ai) { return new FarFromMasterTrigger(ai); }
        static Trigger* behind_target(PlayerbotAI* ai) { return new IsBehindTargetTrigger(ai); }
        static Trigger* not_facing_target(PlayerbotAI* ai) { return new IsNotFacingTargetTrigger(ai); }
        static Trigger* panic(PlayerbotAI* ai) { return new PanicTrigger(ai); }
        static Trigger* no_drink(PlayerbotAI* ai) { return new NoDrinkTrigger(ai); }
        static Trigger* no_food(PlayerbotAI* ai) { return new NoFoodTrigger(ai); }
        static Trigger* NoAoe(PlayerbotAI* ai) { return new NoAoeTrigger(ai); }
        static Trigger* LightAoe(PlayerbotAI* ai) { return new LightAoeTrigger(ai); }
        static Trigger* MediumAoe(PlayerbotAI* ai) { return new MediumAoeTrigger(ai); }
        static Trigger* HighAoe(PlayerbotAI* ai) { return new HighAoeTrigger(ai); }
        static Trigger* LoseAggro(PlayerbotAI* ai) { return new LoseAggroTrigger(ai); }
        static Trigger* HasAggro(PlayerbotAI* ai) { return new HasAggroTrigger(ai); }
        static Trigger* LowHealth(PlayerbotAI* ai) { return new LowHealthTrigger(ai); }
        static Trigger* MediumHealth(PlayerbotAI* ai) { return new MediumHealthTrigger(ai); }
        static Trigger* AlmostFullHealth(PlayerbotAI* ai) { return new AlmostFullHealthTrigger(ai); }
        static Trigger* HighHealth(PlayerbotAI* ai) { return new HighHealthTrigger(ai); }
        static Trigger* AlmostDead(PlayerbotAI* ai) { return new AlmostDeadTrigger(ai); }
        static Trigger* CriticalHealth(PlayerbotAI* ai) { return new CriticalHealthTrigger(ai); }
        static Trigger* TargetCriticalHealth(PlayerbotAI* ai) { return new TargetCriticalHealthTrigger(ai); }
        static Trigger* TargetAlmostDead(PlayerbotAI* ai) { return new TargetAlmostDeadTrigger(ai); }
        static Trigger* LowMana(PlayerbotAI* ai) { return new LowManaTrigger(ai); }
        static Trigger* MediumMana(PlayerbotAI* ai) { return new MediumManaTrigger(ai); }
        static Trigger* LightRageAvailable(PlayerbotAI* ai) { return new LightRageAvailableTrigger(ai); }
        static Trigger* MediumRageAvailable(PlayerbotAI* ai) { return new MediumRageAvailableTrigger(ai); }
        static Trigger* HighRageAvailable(PlayerbotAI* ai) { return new HighRageAvailableTrigger(ai); }
        static Trigger* LightEnergyAvailable(PlayerbotAI* ai) { return new LightEnergyAvailableTrigger(ai); }
        static Trigger* MediumEnergyAvailable(PlayerbotAI* ai) { return new MediumEnergyAvailableTrigger(ai); }
        static Trigger* HighEnergyAvailable(PlayerbotAI* ai) { return new HighEnergyAvailableTrigger(ai); }
        static Trigger* LootAvailable(PlayerbotAI* ai) { return new LootAvailableTrigger(ai); }
        static Trigger* NoAttackers(PlayerbotAI* ai) { return new NoAttackersTrigger(ai); }
        static Trigger* TankAoe(PlayerbotAI* ai) { return new TankAoeTrigger(ai); }
        static Trigger* Timer(PlayerbotAI* ai) { return new TimerTrigger(ai); }
        static Trigger* NoTarget(PlayerbotAI* ai) { return new NoTargetTrigger(ai); }
        static Trigger* TargetInSight(PlayerbotAI* ai) { return new TargetInSightTrigger(ai); }
        static Trigger* not_least_hp_target_active(PlayerbotAI* ai) { return new NotLeastHpTargetActiveTrigger(ai); }
        static Trigger* has_nearest_adds(PlayerbotAI* ai) { return new HasNearestAddsTrigger(ai); }
        static Trigger* enemy_player_is_attacking(PlayerbotAI* ai) { return new EnemyPlayerIsAttacking(ai); }
        static Trigger* Random(PlayerbotAI* ai) { return new RandomTrigger(ai); }
        static Trigger* seldom(PlayerbotAI* ai) { return new SeldomTrigger(ai); }
        static Trigger* often(PlayerbotAI* ai) { return new OftenTrigger(ai); }
        static Trigger* EnemyOutOfMelee(PlayerbotAI* ai) { return new EnemyOutOfMeleeTrigger(ai); }
        static Trigger* EnemyOutOfSpell(PlayerbotAI* ai) { return new EnemyOutOfSpellRangeTrigger(ai); }
        static Trigger* enemy_too_close_for_spell(PlayerbotAI* ai) { return new EnemyTooCloseForSpellTrigger(ai); }
        static Trigger* enemy_too_close_for_melee(PlayerbotAI* ai) { return new EnemyTooCloseForMeleeTrigger(ai); }
        static Trigger* ComboPointsAvailable(PlayerbotAI* ai) { return new ComboPointsAvailableTrigger(ai); }
        static Trigger* ComboPointAvailable(PlayerbotAI* ai) { return new ComboPointAvailableTrigger(ai); }
        static Trigger* MediumThreat(PlayerbotAI* ai) { return new MediumThreatTrigger(ai); }
        static Trigger* Dead(PlayerbotAI* ai) { return new DeadTrigger(ai); }
        static Trigger* Mainhand_not_enhanced(PlayerbotAI* ai) { return new MainhandEnhanceTrigger(ai); }
        static Trigger* Offhand_not_enhanced(PlayerbotAI* ai) { return new OffhandEnhanceTrigger(ai); }
        static Trigger* Rooted(PlayerbotAI* ai) { return new RootedTrigger(ai); }
        static Trigger* Frozen(PlayerbotAI* ai) { return new FrozenTrigger(ai); }
        static Trigger* Snared(PlayerbotAI* ai) { return new SnaredTrigger(ai); }
        static Trigger* Bleeding(PlayerbotAI* ai) { return new BleedingTrigger(ai); }
        static Trigger* Stunned(PlayerbotAI* ai) { return new StunnedTrigger(ai); }
        static Trigger* Polymorphed(PlayerbotAI* ai) { return new PolymorphedTrigger(ai); }
        static Trigger* Possessed(PlayerbotAI* ai) { return new PossessedTrigger(ai); }
        static Trigger* Feared(PlayerbotAI* ai) { return new FearedTrigger(ai); }
        static Trigger* Silenced(PlayerbotAI* ai) { return new SilencedTrigger(ai); }
        static Trigger* Disoriented(PlayerbotAI* ai) { return new DisorientedTrigger(ai); }
        static Trigger* Charmed(PlayerbotAI* ai) { return new CharmedTrigger(ai); }
        static Trigger* Target_Rooted(PlayerbotAI* ai) { return new TargetRootedTrigger(ai); }
        static Trigger* Target_Frozen(PlayerbotAI* ai) { return new TargetFrozenTrigger(ai); }
        static Trigger* Target_Snared(PlayerbotAI* ai) { return new TargetSnaredTrigger(ai); }
        static Trigger* Target_Possessed(PlayerbotAI* ai) { return new TargetPossessedTrigger(ai); }
        static Trigger* Target_Charmed(PlayerbotAI* ai) { return new TargetCharmedTrigger(ai); }
        static Trigger* Target_Disoriented(PlayerbotAI* ai) { return new TargetDisorientedTrigger(ai); }
        static Trigger* Target_Bleeding(PlayerbotAI* ai) { return new TargetBleedingTrigger(ai); }
        static Trigger* Target_Stunned(PlayerbotAI* ai) { return new TargetStunnedTrigger(ai); }
        static Trigger* Target_Feared(PlayerbotAI* ai) { return new TargetFearedTrigger(ai); }
        static Trigger* Target_Silenced(PlayerbotAI* ai) { return new TargetSilencedTrigger(ai); }
        static Trigger* Target_Polymorphed(PlayerbotAI* ai) { return new TargetPolymorphedTrigger(ai); }
        static Trigger* Party_Member_Rooted(PlayerbotAI* ai) { return new PartyMemberRootedTrigger(ai); }
        static Trigger* Party_Member_Frozen(PlayerbotAI* ai) { return new PartyMemberFrozenTrigger(ai); }
        static Trigger* Party_Member_Feared(PlayerbotAI* ai) { return new PartyMemberFearedTrigger(ai); }
        static Trigger* Party_Member_Snared(PlayerbotAI* ai) { return new PartyMemberSnaredTrigger(ai); }
        static Trigger* Party_Member_Polymorphed(PlayerbotAI* ai) { return new PartyMemberPolymorphedTrigger(ai); }
        static Trigger* Party_Member_Charmed(PlayerbotAI* ai) { return new PartyMemberCharmedTrigger(ai); }
        static Trigger* Party_Member_Possessed(PlayerbotAI* ai) { return new PartyMemberPossessedTrigger(ai); }
        static Trigger* Target_NotRooted(PlayerbotAI* ai) { return new TargetNotRootedTrigger(ai); }
        static Trigger* Target_NotFrozen(PlayerbotAI* ai) { return new TargetNotFrozenTrigger(ai); }
        static Trigger* Target_NotSnared(PlayerbotAI* ai) { return new TargetNotSnaredTrigger(ai); }
        static Trigger* Target_NotBleeding(PlayerbotAI* ai) { return new TargetNotBleedingTrigger(ai); }
        static Trigger* Target_NotStunned(PlayerbotAI* ai) { return new TargetNotStunnedTrigger(ai); }
        static Trigger* TakesPeriodicDamage(PlayerbotAI* ai) { return new TakesPeriodicDamageTrigger(ai); }
        static Trigger* PartyMemberDead(PlayerbotAI* ai) { return new PartyMemberDeadTrigger(ai); }
        static Trigger* PartyMemberAlmostDead(PlayerbotAI* ai) { return new PartyMemberAlmostDeadTrigger(ai); }
        static Trigger* PartyMemberLowHealth(PlayerbotAI* ai) { return new PartyMemberLowHealthTrigger(ai); }
        static Trigger* PartyMemberMediumHealth(PlayerbotAI* ai) { return new PartyMemberMediumHealthTrigger(ai); }
        static Trigger* PartyMemberHighHealth(PlayerbotAI* ai) { return new PartyMemberHighHealthTrigger(ai); }
        static Trigger* PartyMemberAlmostFullHealth(PlayerbotAI* ai) { return new PartyMemberAlmostFullHealthTrigger(ai); }
        static Trigger* PartyMemberCriticalHealth(PlayerbotAI* ai) { return new PartyMemberCriticalHealthTrigger(ai); }
        static Trigger* no_pet(PlayerbotAI* ai) { return new NoPetTrigger(ai); }
        static Trigger* has_attackers(PlayerbotAI* ai) { return new HasAttackersTrigger(ai); }

    };
};
