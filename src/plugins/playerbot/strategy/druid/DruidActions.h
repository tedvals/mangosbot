#pragma once

#include "../actions/GenericActions.h"
#include "DruidShapeshiftActions.h"
#include "DruidBearActions.h"
#include "DruidCatActions.h"

namespace ai
{
	class CastFaerieFireAction : public CastSpellAction
	{
	public:
		CastFaerieFireAction(PlayerbotAI* ai) : CastSpellAction(ai, "faerie fire") {}
	};

    class CastFaerieFireFeralAction : public CastSpellAction
    {
    public:
        CastFaerieFireFeralAction(PlayerbotAI* ai) : CastSpellAction(ai, "faerie fire (feral)") {}
    };

	class CastRejuvenationAction : public CastHealingSpellAction {
	public:
		CastRejuvenationAction(PlayerbotAI* ai) : CastHealingSpellAction(ai, "rejuvenation") {}
	};

	class CastSwiftmendAction : public CastHealingSpellAction {
	public:
		CastSwiftmendAction(PlayerbotAI* ai) : CastHealingSpellAction(ai, "swiftmend") {}
	};

	class CastRegrowthAction : public CastHealingSpellAction {
	public:
		CastRegrowthAction(PlayerbotAI* ai) : CastHealingSpellAction(ai, "regrowth") {}

	};

    class CastNourishAction : public CastHealingSpellAction {
	public:
		CastNourishAction(PlayerbotAI* ai) : CastHealingSpellAction(ai, "nourish") {}
	};

	class CastWildGrowthAction : public HealPartyMemberAction {
	public:
		CastWildGrowthAction(PlayerbotAI* ai) : HealPartyMemberAction(ai, "wild growth") {}
	};

    class CastHealingTouchAction : public CastHealingSpellAction {
    public:
        CastHealingTouchAction(PlayerbotAI* ai) : CastHealingSpellAction(ai, "healing touch") {}
    };

    class CastLifeBloomAction : public CastHealingSpellAction {
    public:
        CastLifeBloomAction(PlayerbotAI* ai) : CastHealingSpellAction(ai, "lifebloom") {}
    };

    class CastRejuvenationOnPartyAction : public HealPartyMemberAction
    {
    public:
        CastRejuvenationOnPartyAction(PlayerbotAI* ai) : HealPartyMemberAction(ai, "rejuvenation") {}
    };

    class CastRegrowthOnPartyAction : public HealPartyMemberAction
    {
    public:
        CastRegrowthOnPartyAction(PlayerbotAI* ai) : HealPartyMemberAction(ai, "regrowth") {}
    };

    class CastNourishOnPartyAction : public HealPartyMemberAction
    {
    public:
        CastNourishOnPartyAction(PlayerbotAI* ai) : HealPartyMemberAction(ai, "nourish") {}
    };

    class CastLifebloomOnPartyAction : public HealPartyMemberAction
    {
    public:
        CastLifebloomOnPartyAction(PlayerbotAI* ai) : HealPartyMemberAction(ai, "lifebloom") {}
    };

    class CastSwiftmendOnPartyAction : public HealPartyMemberAction
    {
    public:
        CastSwiftmendOnPartyAction(PlayerbotAI* ai) : HealPartyMemberAction(ai, "swiftmend") {}
    };

    class CastWildGrowthOnPartyAction : public HealPartyMemberAction
    {
    public:
        CastWildGrowthOnPartyAction(PlayerbotAI* ai) : HealPartyMemberAction(ai, "wild growth") {}
    };

    class CastHealingTouchOnPartyAction : public HealPartyMemberAction
    {
    public:
        CastHealingTouchOnPartyAction(PlayerbotAI* ai) : HealPartyMemberAction(ai, "healing touch") {}
    };

	class CastReviveAction : public ResurrectPartyMemberAction
	{
	public:
		CastReviveAction(PlayerbotAI* ai) : ResurrectPartyMemberAction(ai, "revive") {}

		virtual NextAction** getPrerequisites() {
			return NextAction::merge( NextAction::array(0, new NextAction("caster form"), NULL), ResurrectPartyMemberAction::getPrerequisites());
		}
	};

	class CastRebirthAction : public ResurrectPartyMemberAction
	{
	public:
		CastRebirthAction(PlayerbotAI* ai) : ResurrectPartyMemberAction(ai, "rebirth") {}

		virtual NextAction** getPrerequisites() {
			return NextAction::merge( NextAction::array(0, new NextAction("caster form"), NULL), ResurrectPartyMemberAction::getPrerequisites());
		}
	};

	class CastMarkOfTheWildAction : public CastBuffSpellAction {
	public:
		CastMarkOfTheWildAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "mark of the wild") {}
	};

	class CastMarkOfTheWildOnPartyAction : public BuffOnPartyAction {
	public:
		CastMarkOfTheWildOnPartyAction(PlayerbotAI* ai) : BuffOnPartyAction(ai, "mark of the wild") {}
	};

	class CastSurvivalInstinctsAction : public CastBuffSpellAction {
	public:
		CastSurvivalInstinctsAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "survival instincts") {}
	};

	class CastThornsAction : public CastBuffSpellAction {
	public:
		CastThornsAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "thorns") {}
	};

	class CastWrathAction : public CastSpellAction
	{
	public:
		CastWrathAction(PlayerbotAI* ai) : CastSpellAction(ai, "wrath") {}
	};

	class CastStarfallAction : public CastSpellAction
	{
	public:
		CastStarfallAction(PlayerbotAI* ai) : CastSpellAction(ai, "starfall") {}
	};

    class CastTyphoonAction : public CastSpellAction
	{
	public:
		CastTyphoonAction(PlayerbotAI* ai) : CastSpellAction(ai, "typhoon") {}
		virtual bool isUseful() { return AI_VALUE2(float, "distance", GetTargetName()) <= sPlayerbotAIConfig.tooCloseDistance;}
	};

	class CastHurricaneAction : public CastSpellAction
	{
	public:
	    CastHurricaneAction(PlayerbotAI* ai) : CastSpellAction(ai, "hurricane") {}
	};

	class CastMoonfireAction : public CastDebuffSpellAction
	{
	public:
		CastMoonfireAction(PlayerbotAI* ai) : CastDebuffSpellAction(ai, "moonfire") {}
	};

	class CastInsectSwarmAction : public CastDebuffSpellAction
	{
	public:
		CastInsectSwarmAction(PlayerbotAI* ai) : CastDebuffSpellAction(ai, "insect swarm") {}
	};

	class CastStarfireAction : public CastSpellAction
	{
	public:
		CastStarfireAction(PlayerbotAI* ai) : CastSpellAction(ai, "starfire") {}
	};

	class CastEntanglingRootsAction : public CastSpellAction
	{
	public:
		CastEntanglingRootsAction(PlayerbotAI* ai) : CastSpellAction(ai, "entangling roots") {}
	};

    class CastEntanglingRootsCcAction : public CastSpellAction
    {
    public:
        CastEntanglingRootsCcAction(PlayerbotAI* ai) : CastSpellAction(ai, "entangling roots on cc") {}
        virtual Value<Unit*>* GetTargetValue();
        virtual bool Execute(Event event);
    };

	class CastNaturesGraspAction : public CastBuffSpellAction
	{
	public:
		CastNaturesGraspAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "nature's grasp") {}
		virtual bool isUseful() { return AI_VALUE2(float, "distance", GetTargetName()) <= sPlayerbotAIConfig.tooCloseDistance;}
	};

	class CastForceofNatureAction : public CastBuffSpellAction
	{
	public:
		CastForceofNatureAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "force of nature") {}
	};

	class CastNaturesSwiftnessAction : public CastBuffSpellAction
	{
	public:
		CastNaturesSwiftnessAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "nature's swiftness") {}
	};

	class CastHibernateAction : public CastSpellAction
	{
	public:
		CastHibernateAction(PlayerbotAI* ai) : CastSpellAction(ai, "hibernate") {}
	};

	class CastCurePoisonAction : public CastCureSpellAction
	{
	public:
		CastCurePoisonAction(PlayerbotAI* ai) : CastCureSpellAction(ai, "cure poison") {}
	};

    class CastCurePoisonOnPartyAction : public CurePartyMemberAction
    {
    public:
        CastCurePoisonOnPartyAction(PlayerbotAI* ai) : CurePartyMemberAction(ai, "cure poison", DISPEL_POISON) {}
    };

	class CastAbolishPoisonAction : public CastCureSpellAction
	{
	public:
		CastAbolishPoisonAction(PlayerbotAI* ai) : CastCureSpellAction(ai, "abolish poison") {}
		virtual NextAction** getAlternatives();
	};

    class CastAbolishPoisonOnPartyAction : public CurePartyMemberAction
    {
    public:
        CastAbolishPoisonOnPartyAction(PlayerbotAI* ai) : CurePartyMemberAction(ai, "abolish poison", DISPEL_POISON) {}

        virtual NextAction** getAlternatives();
    };

    class CastBerserkAction : public CastBuffSpellAction
	{
	public:
		CastBerserkAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "berserk") {}
	};


    class CastBoostAction : public CastBuffSpellAction
	{
	public:
		CastBoostAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "berserk") {}

		virtual NextAction** getAlternatives();
	};

	class CastBurstAction : public CastBuffSpellAction
	{
	public:
		CastBurstAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "tiger's fury") {}
	};

    class CastBarskinAction : public CastBuffSpellAction
    {
    public:
        CastBarskinAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "barskin") {}
    };

    class CastInnervateAction : public CastSpellAction
    {
    public:
        CastInnervateAction(PlayerbotAI* ai) : CastSpellAction(ai, "innervate") {}

        virtual string GetTargetName() { return "self target"; }
    };

    class CastTranquilityAction : public CastAoeHealSpellAction
    {
    public:
        CastTranquilityAction(PlayerbotAI* ai) : CastAoeHealSpellAction(ai, "tranquility") {}
    };
}
