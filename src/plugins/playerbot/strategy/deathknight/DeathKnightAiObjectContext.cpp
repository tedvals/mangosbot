#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "DeathKnightActions.h"
#include "DeathKnightAiObjectContext.h"
#include "GenericDeathKnightNonCombatStrategy.h"
#include "TankDeathKnightStrategy.h"
#include "DpsDeathKnightStrategy.h"
#include "../generic/PullStrategy.h"
#include "DeathKnightTriggers.h"
#include "../NamedObjectContext.h"

using namespace ai;


namespace ai
{
    namespace DeathKnight
    {
        using namespace ai;

        class StrategyFactoryInternal : public NamedObjectContext<Strategy>
        {
        public:
            StrategyFactoryInternal()
            {
                creators["nc"] = &DeathKnight::StrategyFactoryInternal::nc;
                creators["pull"] = &DeathKnight::StrategyFactoryInternal::pull;
                creators["aoe"] = &DeathKnight::StrategyFactoryInternal::aoe;
            }

        private:
            static Strategy* nc(PlayerbotAI* ai) { return new GenericDeathKnightNonCombatStrategy(ai); }
            static Strategy* aoe(PlayerbotAI* ai) { return new DpsDeathKnightAoeStrategy(ai); }
            static Strategy* pull(PlayerbotAI* ai) { return new PullStrategy(ai, "death grip"); }
        };

        class CombatStrategyFactoryInternal : public NamedObjectContext<Strategy>
        {
        public:
            CombatStrategyFactoryInternal() : NamedObjectContext<Strategy>(false, true)
            {
                creators["tank"] = &DeathKnight::CombatStrategyFactoryInternal::tank;
                creators["dps"] = &DeathKnight::CombatStrategyFactoryInternal::dps;
                creators["frost dps"] = &DeathKnight::CombatStrategyFactoryInternal::frost_dps;
                creators["blood dps"] = &DeathKnight::CombatStrategyFactoryInternal::blood_dps;
                creators["unholy dps"] = &DeathKnight::CombatStrategyFactoryInternal::unholy_dps;
            }

        private:
            static Strategy* tank(PlayerbotAI* ai) { return new TankDeathKnightStrategy(ai); }
            static Strategy* dps(PlayerbotAI* ai) { return new DpsDeathKnightStrategy(ai); }
            static Strategy* frost_dps(PlayerbotAI* ai) { return new DpsFrostDeathKnightStrategy(ai); }
            static Strategy* blood_dps(PlayerbotAI* ai) { return new DpsBloodDeathKnightStrategy(ai); }
            static Strategy* unholy_dps(PlayerbotAI* ai) { return new DpsUnholyDeathKnightStrategy(ai); }
        };
    };
};

namespace ai
{
    namespace DeathKnight
    {
        using namespace ai;

        class TriggerFactoryInternal : public NamedObjectContext<Trigger>
        {
        public:
            TriggerFactoryInternal()
            {
                creators["chains of ice"] = &TriggerFactoryInternal::chains_of_ice;
                creators["blood presence"] = &TriggerFactoryInternal::blood_presence;
                creators["frost presence"] = &TriggerFactoryInternal::frost_presence;
                creators["unholy presence"] = &TriggerFactoryInternal::unholy_presence;
                creators["horn of winter"] = &TriggerFactoryInternal::horn_of_winter;
                creators["bone shield"] = &TriggerFactoryInternal::bone_shield;
                creators["frost fever"] = &TriggerFactoryInternal::frost_fever;
                creators["blood plague"] = &TriggerFactoryInternal::blood_plague;
                creators["frost fever on attacker"] = &TriggerFactoryInternal::frost_fever_on_attacker;
                creators["mind freeze"] = &TriggerFactoryInternal::mind_freeze;
                creators["killing machine"] = &TriggerFactoryInternal::killing_machine;
                creators["freezing fog"] = &TriggerFactoryInternal::freezing_fog;
                creators["sudden doom"] = &TriggerFactoryInternal::sudden_doom;
                creators["strangulate on enemy healer"] = &TriggerFactoryInternal::strangulate_on_enemy_healer;

            }

        private:
            static Trigger* chains_of_ice(PlayerbotAI* ai) { return new ChainsOfIceTrigger(ai); }
            static Trigger* bone_shield(PlayerbotAI* ai) { return new BoneShieldTrigger(ai); }
            static Trigger* blood_presence(PlayerbotAI* ai) { return new BloodPresenceTrigger(ai); }
            static Trigger* frost_presence(PlayerbotAI* ai) { return new FrostPresenceTrigger(ai); }
            static Trigger* unholy_presence(PlayerbotAI* ai) { return new UnholyPresenceTrigger(ai); }
            static Trigger* frost_fever(PlayerbotAI* ai) { return new FrostFeverDebuffTrigger(ai); }
            static Trigger* horn_of_winter(PlayerbotAI* ai) { return new HornOfWinterTrigger(ai); }
            static Trigger* blood_plague(PlayerbotAI* ai) { return new BloodPlagueDebuffTrigger(ai); }
            static Trigger* frost_fever_on_attacker(PlayerbotAI* ai) { return new FrostFeverDebuffOnAttackerTrigger(ai); }
            static Trigger* mind_freeze(PlayerbotAI* ai) { return new MindFreezeInterruptSpellTrigger(ai); }
            static Trigger* sudden_doom(PlayerbotAI* ai) { return new SuddenDoomTrigger(ai); }
            static Trigger* killing_machine(PlayerbotAI* ai) { return new KillingMachineTrigger(ai); }
            static Trigger* freezing_fog(PlayerbotAI* ai) { return new FreezingFogTrigger(ai); }
            static Trigger* strangulate_on_enemy_healer(PlayerbotAI* ai) { return new StrangulateInterruptEnemyHealerSpellTrigger(ai); }
        };
    };
};


namespace ai
{
    namespace DeathKnight
    {
        using namespace ai;

        class AiObjectContextInternal : public NamedObjectContext<Action>
        {
        public:
            AiObjectContextInternal()
            {
                creators["blood strike"] = &AiObjectContextInternal::blood_strike;
                creators["rune strike"] = &AiObjectContextInternal::rune_strike;
                creators["frost strike"] = &AiObjectContextInternal::frost_strike;
                creators["boost"] = &AiObjectContextInternal::boost_deathknight;
                creators["burst"] = &AiObjectContextInternal::burst_deathknight;
                creators["pestilence"] = &AiObjectContextInternal::pestilence;
                creators["howling blast"] = &AiObjectContextInternal::howling_blast;
                creators["icy touch"] = &AiObjectContextInternal::icy_touch;
                creators["scourge strike"] = &AiObjectContextInternal::scourge_strike;
                creators["obliterate"] = &AiObjectContextInternal::obliterate;
                creators["plague strike"] = &AiObjectContextInternal::plague_strike;
                creators["chains of ice"] = &AiObjectContextInternal::chains_of_ice;
                creators["death strike"] = &AiObjectContextInternal::death_strike;
                creators["death coil"] = &AiObjectContextInternal::death_coil;
                creators["dark command"] = &AiObjectContextInternal::dark_command;
                creators["heart strike"] = &AiObjectContextInternal::heart_strike;
                creators["bone shield"] = &AiObjectContextInternal::bone_shield;
                creators["icebound fortitude"] = &AiObjectContextInternal::icebound_fortitude;
                creators["vampiric blood"] = &AiObjectContextInternal::vampiric_blood;
                creators["horn of winter"] = &AiObjectContextInternal::horn_of_winter;
                creators["blood boil"] = &AiObjectContextInternal::blood_boil;
                creators["corpse explosion"] = &AiObjectContextInternal::corpse_explosion;
                creators["raise dead"] = &AiObjectContextInternal::raise_dead;
                creators["army of the dead"] = &AiObjectContextInternal::army_of_the_dead;
                creators["rune tap"] = &AiObjectContextInternal::rune_tap;
                creators["death pact"] = &AiObjectContextInternal::death_pact;
                creators["mark of blood"] = &AiObjectContextInternal::mark_of_blood;
                creators["hungering cold"] = &AiObjectContextInternal::hungering_cold;
                creators["mind freeze"] = &AiObjectContextInternal::mind_freeze;
                creators["summon ghoul"] = &AiObjectContextInternal::summon_ghoul;
                creators["summon gargoyle"] = &AiObjectContextInternal::summon_gargoyle;
                creators["unbreakable armor"] = &AiObjectContextInternal::unbreakable_armor;
                creators["blood presence"] = &AiObjectContextInternal::blood_presence;
                creators["frost presence"] = &AiObjectContextInternal::frost_presence;
                creators["unholy presence"] = &AiObjectContextInternal::unholy_presence;
                creators["hysteria"] = &AiObjectContextInternal::hysteria;
                creators["hysteria on master"] = &AiObjectContextInternal::hysteria_on_master;
                creators["hysteria on party"] = &AiObjectContextInternal::hysteria_on_party;
                creators["death grip"] = &AiObjectContextInternal::death_grip;
                creators["ghoul frenzy"] = &AiObjectContextInternal::ghoul_frenzy;
                creators["lichborne"] = &AiObjectContextInternal::lichborne;
                creators["antimagic shell"] = &AiObjectContextInternal::antimagic_shell;
                creators["antimagic zone"] = &AiObjectContextInternal::antimagic_zone;
                creators["deathchill"] = &AiObjectContextInternal::deathchill;
                creators["dancing rune weapon"] = &AiObjectContextInternal::dancing_rune_weapon;
                creators["death and decay"] = &AiObjectContextInternal::death_and_decay;
                creators["empower rune weapon"] = &AiObjectContextInternal::empower_rune_weapon;
                creators["strangulate"] = &AiObjectContextInternal::strangulate;
                creators["mind freeze on enemy healer"] = &AiObjectContextInternal::mind_freeze_on_enemy_healer;
                creators["strangulate on enemy healer"] = &AiObjectContextInternal::strangulate_on_enemy_healer;
            }

        private:
            static Action* blood_strike(PlayerbotAI* ai) { return new CastBloodStrikeAction(ai); }
            static Action* rune_strike(PlayerbotAI* ai) { return new CastRuneStrikeAction(ai); }
            static Action* frost_strike(PlayerbotAI* ai) { return new CastFrostStrikeAction(ai); }
            static Action* howling_blast(PlayerbotAI* ai) { return new CastHowlingBlastAction(ai); }
            static Action* pestilence(PlayerbotAI* ai) { return new CastPestilenceAction(ai); }
            static Action* icy_touch(PlayerbotAI* ai) { return new CastIcyTouchAction(ai); }
            static Action* boost_deathknight(PlayerbotAI* ai) { return new CastUnbreakableArmorAction(ai); }
            static Action* burst_deathknight(PlayerbotAI* ai) { return new CastEmpowerRuneWeaponAction(ai); }
            static Action* scourge_strike(PlayerbotAI* ai) { return new CastScourgeStrikeAction(ai); }
            static Action* obliterate(PlayerbotAI* ai) { return new CastObliterateAction(ai); }
            static Action* chains_of_ice(PlayerbotAI* ai) { return new CastChainsOfIceAction(ai); }
            static Action* plague_strike(PlayerbotAI* ai) { return new CastPlagueStrikeAction(ai); }
            static Action* death_strike(PlayerbotAI* ai) { return new CastDeathStrikeAction(ai); }
            static Action* death_coil(PlayerbotAI* ai) { return new CastDeathCoilAction(ai); }
            static Action* heart_strike(PlayerbotAI* ai) { return new CastHeartStrikeAction(ai); }
            static Action* dark_command(PlayerbotAI* ai) { return new CastDarkCommandAction(ai); }
            static Action* bone_shield(PlayerbotAI* ai) { return new CastBoneShieldAction(ai); }
            static Action* icebound_fortitude(PlayerbotAI* ai) { return new CastIceboundFortitudeAction(ai); }
            static Action* vampiric_blood(PlayerbotAI* ai) { return new CastVampiricBloodAction(ai); }
            static Action* horn_of_winter(PlayerbotAI* ai) { return new  CastHornOfWinterAction(ai); }
            static Action* blood_boil(PlayerbotAI* ai) { return new CastBloodBoilAction(ai); }
            static Action* corpse_explosion(PlayerbotAI* ai) { return new CastCorpseExplosionAction(ai); }
            static Action* raise_dead(PlayerbotAI* ai) { return new CastRaiseDeadAction(ai); }
            static Action* army_of_the_dead(PlayerbotAI* ai) { return new CastArmyOfTheDeadAction(ai); }
            static Action* rune_tap(PlayerbotAI* ai) { return new CastRuneTapAction(ai); }
            static Action* death_pact(PlayerbotAI* ai) { return new CastDeathPactAction(ai); }
            static Action* mark_of_blood(PlayerbotAI* ai) { return new CastMarkOfBloodAction(ai); }
            static Action* hungering_cold(PlayerbotAI* ai) { return new CastHungeringColdAction(ai); }
            static Action* mind_freeze(PlayerbotAI* ai) { return new CastMindFreezeAction(ai); }
            static Action* summon_ghoul(PlayerbotAI* ai) { return new CastSummonGhoulAction(ai); }
            static Action* summon_gargoyle(PlayerbotAI* ai) { return new CastSummonGargoyleAction(ai); }
            static Action* unbreakable_armor(PlayerbotAI* ai) { return new CastUnbreakableArmorAction(ai); }
            static Action* blood_presence(PlayerbotAI* ai) { return new CastBloodPresenceAction(ai); }
            static Action* frost_presence(PlayerbotAI* ai) { return new CastFrostPresenceAction(ai); }
            static Action* unholy_presence(PlayerbotAI* ai) { return new CastUnholyPresenceAction(ai); }
            static Action* death_grip(PlayerbotAI* ai) { return new CastDeathGripAction(ai); }
            static Action* hysteria_on_master(PlayerbotAI* ai) { return new CastHysteriaOnMasterAction(ai); }
            static Action* hysteria_on_party(PlayerbotAI* ai) { return new CastHysteriaOnPartyAction(ai); }
            static Action* hysteria(PlayerbotAI* ai) { return new CastHysteriaAction(ai); }
            static Action* ghoul_frenzy(PlayerbotAI* ai) { return new CastGhoulFrenzyAction(ai); }
            static Action* lichborne(PlayerbotAI* ai) { return new CastLichborneAction(ai); }
            static Action* antimagic_shell(PlayerbotAI* ai) { return new  CastAntimagicShellAction(ai); }
            static Action* antimagic_zone(PlayerbotAI* ai) { return new  CastAntimagicZoneAction(ai); }
            static Action* deathchill(PlayerbotAI* ai) { return new CastDeathChillAction(ai); }
            static Action* dancing_rune_weapon(PlayerbotAI* ai) { return new CastDancingRuneWeaponAction(ai); }
            static Action* death_and_decay(PlayerbotAI* ai) { return new CastDeathAndDecayAction(ai); }
            static Action* empower_rune_weapon(PlayerbotAI* ai) { return new CastEmpowerRuneWeaponAction(ai); }
            static Action* strangulate(PlayerbotAI* ai) { return new CastStrangulateAction(ai); }
            static Action* mind_freeze_on_enemy_healer(PlayerbotAI* ai) { return new CastMindFreezeOnEnemyHealerAction(ai); }
            static Action* strangulate_on_enemy_healer(PlayerbotAI* ai) { return new CastStrangulateOnEnemyHealerAction(ai); }
        };
    };
};

DeathKnightAiObjectContext::DeathKnightAiObjectContext(PlayerbotAI* ai) : AiObjectContext(ai)
{
    strategyContexts.Add(new ai::DeathKnight::StrategyFactoryInternal());
    strategyContexts.Add(new ai::DeathKnight::CombatStrategyFactoryInternal());
    actionContexts.Add(new ai::DeathKnight::AiObjectContextInternal());
    triggerContexts.Add(new ai::DeathKnight::TriggerFactoryInternal());
}
