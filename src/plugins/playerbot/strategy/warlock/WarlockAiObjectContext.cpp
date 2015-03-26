#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "WarlockActions.h"
#include "WarlockAiObjectContext.h"
#include "DpsWarlockStrategy.h"
#include "GenericWarlockNonCombatStrategy.h"
#include "TankWarlockStrategy.h"
#include "../generic/PullStrategy.h"
#include "WarlockTriggers.h"
#include "../NamedObjectContext.h"
#include "../actions/UseItemAction.h"

using namespace ai;

namespace ai
{
    namespace warlock
    {
        using namespace ai;

        class StrategyFactoryInternal : public NamedObjectContext<Strategy>
        {
        public:
            StrategyFactoryInternal()
            {
                creators["nc"] = &warlock::StrategyFactoryInternal::nc;
                creators["pull"] = &warlock::StrategyFactoryInternal::pull;
                creators["aoe"] = &warlock::StrategyFactoryInternal::aoe;
                creators["fire aoe"] = &warlock::StrategyFactoryInternal::fire_aoe;
                creators["dps debuff"] = &warlock::StrategyFactoryInternal::dps_debuff;
                creators["debuff"] = &warlock::StrategyFactoryInternal::debuff;
                creators["imp"] = &warlock::StrategyFactoryInternal::nc_imp;
                creators["voidwalker"] = &warlock::StrategyFactoryInternal::nc_voidwalker;
                creators["succubus"] = &warlock::StrategyFactoryInternal::nc_succubus;
                creators["felhunter"] = &warlock::StrategyFactoryInternal::nc_felhunter;
                creators["felguard"] = &warlock::StrategyFactoryInternal::nc_felguard;
            }

        private:
            static Strategy* nc(PlayerbotAI* ai) { return new GenericWarlockNonCombatStrategy(ai); }
            static Strategy* aoe(PlayerbotAI* ai) { return new DpsAoeWarlockStrategy(ai); }
            static Strategy* fire_aoe(PlayerbotAI* ai) { return new DpsFireAoeWarlockStrategy(ai); }
            static Strategy* dps_debuff(PlayerbotAI* ai) { return new DpsWarlockDebuffStrategy(ai); }
            static Strategy* debuff(PlayerbotAI* ai) { return new WarlockDebuffStrategy(ai); }
            static Strategy* pull(PlayerbotAI* ai) { return new PullStrategy(ai, "shoot"); }
            static Strategy* nc_imp(PlayerbotAI* ai) { return new WarlockImpStrategy(ai); }
            static Strategy* nc_voidwalker(PlayerbotAI* ai) { return new WarlockVoidwalkerStrategy(ai); }
            static Strategy* nc_succubus(PlayerbotAI* ai) { return new WarlockSuccubusStrategy(ai); }
            static Strategy* nc_felhunter(PlayerbotAI* ai) { return new WarlockFelhunterStrategy(ai); }
            static Strategy* nc_felguard(PlayerbotAI* ai) { return new WarlockFelguardStrategy(ai); }
        };

        class CombatStrategyFactoryInternal : public NamedObjectContext<Strategy>
        {
        public:
            CombatStrategyFactoryInternal() : NamedObjectContext<Strategy>(false, true)
            {
                creators["dps"] = &warlock::CombatStrategyFactoryInternal::dps;
                creators["fire"] = &warlock::CombatStrategyFactoryInternal::fire_dps;
                creators["tank"] = &warlock::CombatStrategyFactoryInternal::tank;
            }

        private:
            static Strategy* tank(PlayerbotAI* ai) { return new TankWarlockStrategy(ai); }
            static Strategy* dps(PlayerbotAI* ai) { return new DpsWarlockStrategy(ai); }
            static Strategy* fire_dps(PlayerbotAI* ai) { return new DpsFireWarlockStrategy(ai); }
        };
    };
};

namespace ai
{
    namespace warlock
    {
        using namespace ai;

        class TriggerFactoryInternal : public NamedObjectContext<Trigger>
        {
        public:
            TriggerFactoryInternal()
            {
                creators["shadow trance"] = &TriggerFactoryInternal::shadow_trance;
                creators["demon armor"] = &TriggerFactoryInternal::demon_armor;
                creators["no healthstone"] = &TriggerFactoryInternal::HasHealthstone;
                creators["no firestone"] = &TriggerFactoryInternal::HasFirestone;
                creators["no spellstone"] = &TriggerFactoryInternal::HasSpellstone;
                creators["no soulstone"] = &TriggerFactoryInternal::HasSoulstone;
                creators["no corruption"] = &TriggerFactoryInternal::corruption;
                creators["corruption on attacker"] = &TriggerFactoryInternal::corruption_on_attacker;
                creators["curse of agony on attacker"] = &TriggerFactoryInternal::curse_of_agony_on_attacker;
                creators["immolate on attacker"] = &TriggerFactoryInternal::immolate_on_attacker;
                creators["no curse"] = &TriggerFactoryInternal::curse_of_agony;
                creators["banish"] = &TriggerFactoryInternal::banish;
             //   creators["spellstone"] = &TriggerFactoryInternal::spellstone;
             //   creators["firestone"] = &TriggerFactoryInternal::firestone;
                creators["soulstone on master"] = &TriggerFactoryInternal::soulstone_on_master;
                creators["backlash"] = &TriggerFactoryInternal::backlash;
                creators["molten core"] = &TriggerFactoryInternal::molten_core;
                creators["decimation"] = &TriggerFactoryInternal::decimation;
                creators["fear"] = &TriggerFactoryInternal::fear;
             //   creators["immolate"] = &TriggerFactoryInternal::immolate;
                creators["haunt"] = &TriggerFactoryInternal::haunt;
                creators["demon dead"] = &TriggerFactoryInternal::demon_dead;
                creators["demon low health"] = &TriggerFactoryInternal::demon_low_health;
            }

        private:
            static Trigger* shadow_trance(PlayerbotAI* ai) { return new ShadowTranceTrigger(ai); }
            static Trigger* molten_core(PlayerbotAI* ai) { return new MoltenCoreTrigger(ai); }
            static Trigger* decimation(PlayerbotAI* ai) { return new DecimationTrigger(ai); }
            static Trigger* demon_armor(PlayerbotAI* ai) { return new DemonArmorTrigger(ai); }
            static Trigger* HasHealthstone(PlayerbotAI* ai) { return new HasHealthstoneTrigger(ai); }
            static Trigger* HasFirestone(PlayerbotAI* ai) { return new HasFirestoneTrigger(ai); }
            static Trigger* HasSpellstone(PlayerbotAI* ai) { return new HasSpellstoneTrigger(ai); }
            static Trigger* HasSoulstone(PlayerbotAI* ai) { return new HasSoulstoneTrigger(ai); }
            static Trigger* soulstone_on_master(PlayerbotAI* ai) { return new SoulstoneOnMasterTrigger(ai); }
            static Trigger* corruption(PlayerbotAI* ai) { return new WarlockNoCorruptionTrigger(ai); }
            static Trigger* corruption_on_attacker(PlayerbotAI* ai) { return new CorruptionOnAttackerTrigger(ai); }
            static Trigger* immolate_on_attacker(PlayerbotAI* ai) { return new ImmolateOnAttackerTrigger(ai); }
            static Trigger* curse_of_agony_on_attacker(PlayerbotAI* ai) { return new CurseOfAgonyOnAttackerTrigger(ai); }
            static Trigger* curse_of_agony(PlayerbotAI* ai) { return new WarlockNoCurseTrigger(ai); }
            static Trigger* banish(PlayerbotAI* ai) { return new BanishTrigger(ai); }
       //     static Trigger* spellstone(PlayerbotAI* ai) { return new SpellstoneTrigger(ai); }
       //     static Trigger* firestone(PlayerbotAI* ai) { return new FirestoneTrigger(ai); }
            static Trigger* backlash(PlayerbotAI* ai) { return new BacklashTrigger(ai); }
            static Trigger* fear(PlayerbotAI* ai) { return new FearTrigger(ai); }
       //     static Trigger* immolate(PlayerbotAI* ai) { return new ImmolateTrigger(ai); }
            static Trigger* haunt(PlayerbotAI* ai) { return new HauntTrigger(ai); }
            static Trigger* demon_dead(PlayerbotAI* ai) { return new DemonDeadTrigger(ai); }
            static Trigger* demon_low_health(PlayerbotAI* ai) { return new DemonLowHealthTrigger(ai); }
        };
    };
};

namespace ai
{
    namespace warlock
    {
        using namespace ai;

        class AiObjectContextInternal : public NamedObjectContext<Action>
        {
        public:
            AiObjectContextInternal()
            {
                creators["summon imp"] = &AiObjectContextInternal::summon_imp;
                creators["fel armor"] = &AiObjectContextInternal::fel_armor;
                creators["demon armor"] = &AiObjectContextInternal::demon_armor;
                creators["demon skin"] = &AiObjectContextInternal::demon_skin;
                creators["create healthstone"] = &AiObjectContextInternal::create_healthstone;
                creators["create firestone"] = &AiObjectContextInternal::create_firestone;
                creators["create spellstone"] = &AiObjectContextInternal::create_spellstone;
                creators["create soulstone"] = &AiObjectContextInternal::create_soulstone;
                creators["spellstone"] = &AiObjectContextInternal::spellstone;
                creators["firestone"] = &AiObjectContextInternal::firestone;
                creators["soulstone on master"] = &AiObjectContextInternal::soulstone_on_master;
                creators["summon voidwalker"] = &AiObjectContextInternal::summon_voidwalker;
                creators["summon felguard"] = &AiObjectContextInternal::summon_felguard;
                creators["summon succubus"] = &AiObjectContextInternal::summon_succubus;
                creators["summon felhunter"] = &AiObjectContextInternal::summon_felhunter;
                creators["immolate"] = &AiObjectContextInternal::immolate;
                creators["corruption"] = &AiObjectContextInternal::corruption;
                //creators["death coil on attacker"] = &AiObjectContextInternal::death_coil_on_attacker;
                creators["curse of agony"] = &AiObjectContextInternal::curse_of_agony;
                creators["curse of agony on attacker"] = &AiObjectContextInternal::curse_of_agony_on_attacker;
                creators["corruption on attacker"] = &AiObjectContextInternal::corruption_on_attacker;
                creators["immolate on attacker"] = &AiObjectContextInternal::immolate_on_attacker;
                creators["curse of exhaustion"] = &AiObjectContextInternal::curse_of_exhaustion;
                creators["curse of the elements"] = &AiObjectContextInternal::curse_of_the_elements;
                creators["curse of doom"] = &AiObjectContextInternal::curse_of_doom;
                creators["curse of weakness"] = &AiObjectContextInternal::curse_of_weakness;
                creators["shadow bolt"] = &AiObjectContextInternal::shadow_bolt;
                creators["drain soul"] = &AiObjectContextInternal::drain_soul;
                creators["drain mana"] = &AiObjectContextInternal::drain_mana;
                creators["drain life"] = &AiObjectContextInternal::drain_life;
                creators["banish"] = &AiObjectContextInternal::banish;
                creators["banish on cc"] = &AiObjectContextInternal::banish_on_cc;
                creators["seed of corruption"] = &AiObjectContextInternal::seed_of_corruption;
                creators["rain of fire"] = &AiObjectContextInternal::rain_of_fire;
                creators["shadowfury"] = &AiObjectContextInternal::shadowfury;
                creators["chaos bolt"] = &AiObjectContextInternal::chaos_bolt;
                creators["haunt"] = &AiObjectContextInternal::haunt;
                creators["death coil"] = &AiObjectContextInternal::death_coil;
                creators["soul fire"] = &AiObjectContextInternal::soul_fire;
                creators["howl of terror"] = &AiObjectContextInternal::howl_of_terror;
                creators["shadowfury"] = &AiObjectContextInternal::shadowfury;
                creators["life tap"] = &AiObjectContextInternal::life_tap;
                creators["fear"] = &AiObjectContextInternal::fear;
                creators["fear on cc"] = &AiObjectContextInternal::fear_on_cc;
                creators["incinerate"] = &AiObjectContextInternal::incinerate;
                creators["conflagrate"] = &AiObjectContextInternal::conflagrate;
                creators["fel domination"] = &AiObjectContextInternal::fel_domination;
                creators["demonic empowerment"] = &AiObjectContextInternal::demonic_empowerment;
                creators["metamorphosis"] = &AiObjectContextInternal::metamorphosis;
                creators["shadow cleave"] = &AiObjectContextInternal::shadow_cleave;
                creators["immolation aura"] = &AiObjectContextInternal::immolation_aura;
                creators["demon charge"] = &AiObjectContextInternal::demon_charge;
                creators["challenging howl"] = &AiObjectContextInternal::challenging_howl;
                creators["soul shatter"] = &AiObjectContextInternal::soul_shatter;
            }

        private:
            static Action* conflagrate(PlayerbotAI* ai) { return new CastConflagrateAction(ai); }
            static Action* incinerate(PlayerbotAI* ai) { return new CastIncinerateAction(ai); }
            static Action* fear_on_cc(PlayerbotAI* ai) { return new CastFearOnCcAction(ai); }
            static Action* fear(PlayerbotAI* ai) { return new CastFearAction(ai); }
            static Action* immolate(PlayerbotAI* ai) { return new CastImmolateAction(ai); }
            static Action* summon_imp(PlayerbotAI* ai) { return new CastSummonImpAction(ai); }
            static Action* fel_armor(PlayerbotAI* ai) { return new CastFelArmorAction(ai); }
            static Action* demon_armor(PlayerbotAI* ai) { return new CastDemonArmorAction(ai); }
            static Action* demon_skin(PlayerbotAI* ai) { return new CastDemonSkinAction(ai); }
            static Action* create_healthstone(PlayerbotAI* ai) { return new CastCreateHealthstoneAction(ai); }
            static Action* create_firestone(PlayerbotAI* ai) { return new CastCreateFirestoneAction(ai); }
            static Action* create_spellstone(PlayerbotAI* ai) { return new CastCreateSpellstoneAction(ai); }
            static Action* create_soulstone(PlayerbotAI* ai) { return new CastCreateSoulstoneAction(ai); }
            static Action* spellstone(PlayerbotAI* ai) { return new UseSpellstoneMainhandAction(ai); }
            static Action* firestone(PlayerbotAI* ai) { return new UseFirestoneMainhandAction(ai); }
            static Action* soulstone_on_master(PlayerbotAI* ai) { return new UseSoulstoneOnMasterAction(ai); }
            static Action* summon_voidwalker(PlayerbotAI* ai) { return new CastSummonVoidwalkerAction(ai); }
            static Action* summon_succubus(PlayerbotAI* ai) { return new CastSummonSuccubusAction(ai); }
            static Action* summon_felguard(PlayerbotAI* ai) { return new CastSummonFelguardAction(ai); }
            static Action* summon_felhunter(PlayerbotAI* ai) { return new CastSummonFelhunterAction(ai); }
            static Action* corruption(PlayerbotAI* ai) { return new CastCorruptionAction(ai); }
            //static Action* death_coil_on_attacker(PlayerbotAI* ai) { return new CastDeathCoilOnAttackerAction(ai); }
            static Action* corruption_on_attacker(PlayerbotAI* ai) { return new CastCorruptionOnAttackerAction(ai); }
            static Action* immolate_on_attacker(PlayerbotAI* ai) { return new CastImmolateOnAttackerAction(ai); }
            static Action* curse_of_agony_on_attacker(PlayerbotAI* ai) { return new CastCurseOfAgonyOnAttackerAction(ai); }
            static Action* curse_of_agony(PlayerbotAI* ai) { return new CastCurseOfAgonyAction(ai); }
            static Action* curse_of_exhaustion(PlayerbotAI* ai) { return new CastCurseOfExhaustionAction(ai); }
            static Action* curse_of_doom(PlayerbotAI* ai) { return new CastCurseOfDoomAction(ai); }
            static Action* curse_of_the_elements(PlayerbotAI* ai) { return new CastCurseOfTheElementsAction(ai); }
            static Action* curse_of_weakness(PlayerbotAI* ai) { return new CastCurseOfWeaknessAction(ai); }
            static Action* shadow_bolt(PlayerbotAI* ai) { return new CastShadowBoltAction(ai); }
            static Action* haunt(PlayerbotAI* ai) { return new CastHauntAction(ai); }
            static Action* howl_of_terror(PlayerbotAI* ai) { return new CastHowlOfTerrorAction(ai); }
            static Action* death_coil(PlayerbotAI* ai) { return new CastDeathcoilAction(ai); }
            static Action* chaos_bolt(PlayerbotAI* ai) { return new CastChaosBoltAction(ai); }
            static Action* soul_fire(PlayerbotAI* ai) { return new CastSoulFireAction(ai); }
            static Action* drain_soul(PlayerbotAI* ai) { return new CastDrainSoulAction(ai); }
            static Action* drain_mana(PlayerbotAI* ai) { return new CastDrainManaAction(ai); }
            static Action* drain_life(PlayerbotAI* ai) { return new CastDrainLifeAction(ai); }
            static Action* banish(PlayerbotAI* ai) { return new CastBanishAction(ai); }
            static Action* banish_on_cc(PlayerbotAI* ai) { return new CastBanishCcAction(ai); }
            static Action* seed_of_corruption(PlayerbotAI* ai) { return new CastSeedOfCorruptionAction(ai); }
            static Action* rain_of_fire(PlayerbotAI* ai) { return new CastRainOfFireAction(ai); }
            static Action* shadowfury(PlayerbotAI* ai) { return new CastShadowfuryAction(ai); }
            static Action* life_tap(PlayerbotAI* ai) { return new CastLifeTapAction(ai); }
            static Action* fel_domination(PlayerbotAI* ai) { return new CastFelDominationAction(ai); }
            static Action* demonic_empowerment(PlayerbotAI* ai) { return new CastDemonicEmpowermentAction(ai); }
            static Action* metamorphosis(PlayerbotAI* ai) { return new CastMetamorphosisAction(ai); }
            static Action* shadow_cleave(PlayerbotAI* ai) { return new CastShadowCleaveAction(ai); }
            static Action* immolation_aura(PlayerbotAI* ai) { return new CastImmolationAuraAction(ai); }
            static Action* demon_charge(PlayerbotAI* ai) { return new CastDemonChargeAction(ai); }
            static Action* challenging_howl(PlayerbotAI* ai) { return new CastChallengingHowlAction(ai); }
            static Action* soul_shatter(PlayerbotAI* ai) { return new CastSoulShatterAction(ai); }
        };
    };
};



WarlockAiObjectContext::WarlockAiObjectContext(PlayerbotAI* ai) : AiObjectContext(ai)
{
    strategyContexts.Add(new ai::warlock::StrategyFactoryInternal());
    strategyContexts.Add(new ai::warlock::CombatStrategyFactoryInternal());
    actionContexts.Add(new ai::warlock::AiObjectContextInternal());
    triggerContexts.Add(new ai::warlock::TriggerFactoryInternal());
}
