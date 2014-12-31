#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "RogueActions.h"
#include "RogueTriggers.h"
#include "RogueAiObjectContext.h"
#include "DpsRogueStrategy.h"
#include "GenericRogueNonCombatStrategy.h"
#include "../generic/PullStrategy.h"
#include "../NamedObjectContext.h"

using namespace ai;


namespace ai
{
    namespace rogue
    {
        using namespace ai;

        class StrategyFactoryInternal : public NamedObjectContext<Strategy>
        {
        public:
            StrategyFactoryInternal()
            {
                creators["dps"] = &rogue::StrategyFactoryInternal::dps;
                creators["sword"] = &rogue::StrategyFactoryInternal::sword_dps;
                creators["dagger"] = &rogue::StrategyFactoryInternal::dagger_dps;
                creators["nc"] = &rogue::StrategyFactoryInternal::nc;
                creators["stealth"] = &rogue::StrategyFactoryInternal::stealth;
                creators["pull"] = &rogue::StrategyFactoryInternal::pull;
            }

        private:
            static Strategy* dps(PlayerbotAI* ai) { return new DpsRogueStrategy(ai); }
            static Strategy* sword_dps(PlayerbotAI* ai) { return new DpsSwordRogueStrategy(ai); }
            static Strategy* dagger_dps(PlayerbotAI* ai) { return new DpsDaggerRogueStrategy(ai); }
            static Strategy* nc(PlayerbotAI* ai) { return new GenericRogueNonCombatStrategy(ai); }
            static Strategy* stealth(PlayerbotAI* ai) { return new GenericRogueNonCombatStealthStrategy(ai); }
            static Strategy* pull(PlayerbotAI* ai) { return new PullStrategy(ai, "shoot"); }
        };
    };
};

namespace ai
{
    namespace rogue
    {
        using namespace ai;

        class TriggerFactoryInternal : public NamedObjectContext<Trigger>
        {
        public:
            TriggerFactoryInternal()
            {
                creators["riposte"] = &TriggerFactoryInternal::riposte;
                creators["kick"] = &TriggerFactoryInternal::kick;
                creators["stealth"] = &TriggerFactoryInternal::stealth;
                creators["garrote"] = &TriggerFactoryInternal::garrote;
                creators["rupture"] = &TriggerFactoryInternal::rupture;
      //          creators["sap"] = &TriggerFactoryInternal::sap;
                creators["hunger for blood"] = &TriggerFactoryInternal::hunger_for_blood;
                creators["slice and dice"] = &TriggerFactoryInternal::slice_and_dice;
                creators["expose armor"] = &TriggerFactoryInternal::expose_armor;
                creators["kick on enemy healer"] = &TriggerFactoryInternal::kick_on_enemy_healer;
                creators["premeditation"] = &TriggerFactoryInternal::premeditation;

            }

        private:
            static Trigger* riposte(PlayerbotAI* ai) { return new RiposteTrigger(ai); }
            static Trigger* kick(PlayerbotAI* ai) { return new KickInterruptSpellTrigger(ai); }
            static Trigger* stealth(PlayerbotAI* ai) { return new StealthTrigger(ai); }
            static Trigger* garrote(PlayerbotAI* ai) { return new GarroteTrigger(ai); }
            static Trigger* rupture(PlayerbotAI* ai) { return new RuptureTrigger(ai); }
   //         static Trigger* sap(PlayerbotAI* ai) { return new SapTrigger(ai); }
            static Trigger* hunger_for_blood(PlayerbotAI* ai) { return new HungerForBloodTrigger(ai); }
            static Trigger* slice_and_dice(PlayerbotAI* ai) { return new SliceAndDiceTrigger(ai); }
            static Trigger* expose_armor(PlayerbotAI* ai) { return new ExposeArmorTrigger(ai); }
            static Trigger* premeditation(PlayerbotAI* ai) { return new PremeditationTrigger(ai); }
            static Trigger* kick_on_enemy_healer(PlayerbotAI* ai) { return new KickInterruptEnemyHealerSpellTrigger(ai); }
        };
    };
};


namespace ai
{
    namespace rogue
    {
        using namespace ai;

        class AiObjectContextInternal : public NamedObjectContext<Action>
        {
        public:
            AiObjectContextInternal()
            {
                creators["riposte"] = &AiObjectContextInternal::riposte;
                creators["mutilate"] = &AiObjectContextInternal::mutilate;
                creators["sinister strike"] = &AiObjectContextInternal::sinister_strike;
                creators["kidney shot"] = &AiObjectContextInternal::kidney_shot;
                creators["rupture"] = &AiObjectContextInternal::rupture;
                creators["slice and dice"] = &AiObjectContextInternal::slice_and_dice;
                creators["eviscerate"] = &AiObjectContextInternal::eviscerate;
                creators["finish target"] = &AiObjectContextInternal::eviscerate;
                creators["envenom"] = &AiObjectContextInternal::envenom;
                creators["vanish"] = &AiObjectContextInternal::vanish;
                creators["evasion"] = &AiObjectContextInternal::evasion;
                creators["kick"] = &AiObjectContextInternal::kick;
                creators["feint"] = &AiObjectContextInternal::feint;
                creators["backstab"] = &AiObjectContextInternal::backstab;
                creators["adrenaline rush"] = &AiObjectContextInternal::adrenaline_rush;
                creators["blade flurry"] = &AiObjectContextInternal::blade_flurry;
                creators["killing spree"] = &AiObjectContextInternal::killing_spree;
                creators["shadow dance"] = &AiObjectContextInternal::shadow_dance;
                creators["hunger for blood"] = &AiObjectContextInternal::hunger_for_blood;
                creators["hemorrhage"] = &AiObjectContextInternal::hemorrhage;
                creators["shadowstep"] = &AiObjectContextInternal::shadowstep;
                creators["stealth"] = &AiObjectContextInternal::stealth;
                creators["prepare attack"] = &AiObjectContextInternal::stealth;
                creators["garrote"] = &AiObjectContextInternal::garrote;
                creators["ambush"] = &AiObjectContextInternal::ambush;
                creators["preparation"] = &AiObjectContextInternal::preparation;
                creators["fan of knives"] = &AiObjectContextInternal::fan_of_knives;
                creators["premeditation"] = &AiObjectContextInternal::premeditation;
                creators["dismantle"] = &AiObjectContextInternal::dismantle;
                creators["deadly throw"] = &AiObjectContextInternal::deadly_throw;
                creators["blind"] = &AiObjectContextInternal::blind;
                creators["wound poison mainhand"] = &AiObjectContextInternal::wound_poison_mh;
                creators["instant poison mainhand"] = &AiObjectContextInternal::instant_poison_mh;
                creators["deadly poison mainhand"] = &AiObjectContextInternal::deadly_poison_mh;
                creators["crippling poison mainhand"] = &AiObjectContextInternal::crippling_poison_mh;
                creators["mind-numbing poison mainhand"] = &AiObjectContextInternal::mindnumbing_poison_mh;
                creators["wound poison offhand"] = &AiObjectContextInternal::wound_poison_oh;
                creators["instant poison offhand"] = &AiObjectContextInternal::instant_poison_oh;
                creators["deadly poison offhand"] = &AiObjectContextInternal::deadly_poison_oh;
                creators["crippling poison offhand"] = &AiObjectContextInternal::crippling_poison_oh;
                creators["mind-numbing poison offhand"] = &AiObjectContextInternal::mindnumbing_poison_oh;
                creators["cloak of shadows"] = &AiObjectContextInternal::cloak_of_shadows;
                creators["sap"] = &AiObjectContextInternal::sap;
                creators["sap on cc"] = &AiObjectContextInternal::sap_on_cc;
                creators["expose armor"] = &AiObjectContextInternal::expose_armor;
                creators["kick on enemy healer"] = &AiObjectContextInternal::kick_on_enemy_healer;
                creators["boost"] = &AiObjectContextInternal::adrenaline_rush;
                creators["burst"] = &AiObjectContextInternal::killing_spree;
            }

        private:
            static Action* riposte(PlayerbotAI* ai) { return new CastRiposteAction(ai); }
            static Action* mutilate(PlayerbotAI* ai) { return new CastMutilateAction(ai); }
            static Action* sinister_strike(PlayerbotAI* ai) { return new CastSinisterStrikeAction(ai); }
            static Action* fan_of_knives(PlayerbotAI* ai) { return new CastFanOfKnivesAction(ai); }
            static Action* kidney_shot(PlayerbotAI* ai) { return new CastKidneyShotAction(ai); }
            static Action* rupture(PlayerbotAI* ai) { return new CastRuptureAction(ai); }
            static Action* slice_and_dice(PlayerbotAI* ai) { return new CastSliceAndDiceAction(ai); }
            static Action* eviscerate(PlayerbotAI* ai) { return new CastEviscerateAction(ai); }
            static Action* envenom(PlayerbotAI* ai) { return new CastEnvenomAction(ai); }
            static Action* vanish(PlayerbotAI* ai) { return new CastVanishAction(ai); }
            static Action* evasion(PlayerbotAI* ai) { return new CastEvasionAction(ai); }
            static Action* kick(PlayerbotAI* ai) { return new CastKickAction(ai); }
            static Action* feint(PlayerbotAI* ai) { return new CastFeintAction(ai); }
            static Action* backstab(PlayerbotAI* ai) { return new CastBackstabAction(ai); }
            static Action* adrenaline_rush(PlayerbotAI* ai) { return new CastAdrenalineRushAction(ai); }
            static Action* blade_flurry(PlayerbotAI* ai) { return new CastBladeFlurryAction(ai); }
            static Action* killing_spree(PlayerbotAI* ai) { return new CastKillingSpreeAction(ai); }
            static Action* shadow_dance(PlayerbotAI* ai) { return new CastShadowDanceAction(ai); }
            static Action* hunger_for_blood(PlayerbotAI* ai) { return new CastHungerForBloodAction(ai); }
            static Action* deadly_throw(PlayerbotAI* ai) { return new CastDeadlyThrowAction(ai); }
            static Action* hemorrhage(PlayerbotAI* ai) { return new CastHemorrhageAction(ai); }
            static Action* shadowstep(PlayerbotAI* ai) { return new CastShadowDanceAction(ai); }
            static Action* stealth(PlayerbotAI* ai) { return new CastStealthAction(ai); }
            static Action* garrote(PlayerbotAI* ai) { return new CastGarroteAction(ai); }
            static Action* ambush(PlayerbotAI* ai) { return new CastAmbushAction(ai); }
            static Action* preparation(PlayerbotAI* ai) { return new CastPreparationAction(ai); }
            static Action* premeditation(PlayerbotAI* ai) { return new CastPremeditationAction(ai); }
            static Action* dismantle(PlayerbotAI* ai) { return new CastDismantleAction(ai); }
            static Action* blind(PlayerbotAI* ai) { return new CastBlindAction(ai); }
            static Action* sap(PlayerbotAI* ai) { return new CastSapAction(ai); }
            static Action* deadly_poison_mh(PlayerbotAI* ai) { return new UseDeadlyPoisonMainhandAction(ai); }
            static Action* instant_poison_mh(PlayerbotAI* ai) { return new UseInstantPoisonMainhandAction(ai); }
            static Action* wound_poison_mh(PlayerbotAI* ai) { return new UseWoundPoisonMainhandAction(ai); }
            static Action* mindnumbing_poison_mh(PlayerbotAI* ai) { return new UseMindNumbingPoisonMainhandAction(ai); }
            static Action* crippling_poison_mh(PlayerbotAI* ai) { return new UseCripplingPoisonMainhandAction(ai); }
            static Action* deadly_poison_oh(PlayerbotAI* ai) { return new UseDeadlyPoisonOffhandAction(ai); }
            static Action* instant_poison_oh(PlayerbotAI* ai) { return new UseInstantPoisonOffhandAction(ai); }
            static Action* wound_poison_oh(PlayerbotAI* ai) { return new UseWoundPoisonOffhandAction(ai); }
            static Action* mindnumbing_poison_oh(PlayerbotAI* ai) { return new UseMindNumbingPoisonOffhandAction(ai); }
            static Action* crippling_poison_oh(PlayerbotAI* ai) { return new UseCripplingPoisonOffhandAction(ai); }
            static Action* sap_on_cc(PlayerbotAI* ai) { return new CastSapCcAction(ai); }
            static Action* cloak_of_shadows(PlayerbotAI* ai) { return new CastCloakOfShadowsAction(ai); }
            static Action* expose_armor(PlayerbotAI* ai) { return new CastExposeArmorAction(ai); }
            static Action* kick_on_enemy_healer(PlayerbotAI* ai) { return new CastKickOnEnemyHealerAction(ai); }
        };
    };
};

RogueAiObjectContext::RogueAiObjectContext(PlayerbotAI* ai) : AiObjectContext(ai)
{
    strategyContexts.Add(new ai::rogue::StrategyFactoryInternal());
    actionContexts.Add(new ai::rogue::AiObjectContextInternal());
    triggerContexts.Add(new ai::rogue::TriggerFactoryInternal());
}
