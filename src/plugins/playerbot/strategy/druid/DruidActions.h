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
		CastRejuvenationAction(PlayerbotAI* ai) : CastHealingSpellAction(ai, "rejuvenation",5) {}

		virtual bool IsInstant() {return true;}
	};

	class CastSwiftmendAction : public CastHealingSpellAction {
	public:
		CastSwiftmendAction(PlayerbotAI* ai) : CastHealingSpellAction(ai, "swiftmend",15) {}

		virtual bool IsInstant() {return true;}
	};

	class CastRegrowthAction : public CastHealingSpellAction {
	public:
		CastRegrowthAction(PlayerbotAI* ai) : CastHealingSpellAction(ai, "regrowth",15) {}

		virtual bool isPossible() {
			return CastHealingSpellAction::isPossible() && !ai->HasAura("dire bear form", GetTarget()) && !ai->HasAura("bear form", GetTarget());
		}
	};

    class CastNourishAction : public CastHealingSpellAction {
	public:
		CastNourishAction(PlayerbotAI* ai) : CastHealingSpellAction(ai, "nourish",10) {}
	};

	class CastWildGrowthAction : public HealPartyMemberAction {
	public:
		CastWildGrowthAction(PlayerbotAI* ai) : HealPartyMemberAction(ai, "wild growth",5) {}

		virtual bool IsInstant() {return true;}
	};

    class CastHealingTouchAction : public CastHealingSpellAction {
    public:
        CastHealingTouchAction(PlayerbotAI* ai) : CastHealingSpellAction(ai, "healing touch",25) {}
    };

    class CastLifeBloomAction : public CastHealingSpellAction {
    public:
        CastLifeBloomAction(PlayerbotAI* ai) : CastHealingSpellAction(ai, "lifebloom",5) {}

        virtual bool IsInstant() {return true;}
    };

    class CastRejuvenationOnPartyAction : public HealPartyMemberAction
    {
    public:
        CastRejuvenationOnPartyAction(PlayerbotAI* ai) : HealPartyMemberAction(ai, "rejuvenation",5) {}

        virtual bool IsInstant() {return true;}
    };

    class CastRegrowthOnPartyAction : public HealPartyMemberAction
    {
    public:
        CastRegrowthOnPartyAction(PlayerbotAI* ai) : HealPartyMemberAction(ai, "regrowth",15) {}

         virtual bool isPossible() {
			return HealPartyMemberAction::isPossible() && !ai->HasAura("dire bear form", GetTarget()) && !ai->HasAura("bear form", GetTarget());
		}
    };

    class CastNourishOnPartyAction : public HealPartyMemberAction
    {
    public:
        CastNourishOnPartyAction(PlayerbotAI* ai) : HealPartyMemberAction(ai, "nourish",10) {}
    };

    class CastLifebloomOnPartyAction : public HealPartyMemberAction
    {
    public:
        CastLifebloomOnPartyAction(PlayerbotAI* ai) : HealPartyMemberAction(ai, "lifebloom",5) {}

        virtual bool IsInstant() {return true;}
    };

    class CastSwiftmendOnPartyAction : public HealPartyMemberAction
    {
    public:
        CastSwiftmendOnPartyAction(PlayerbotAI* ai) : HealPartyMemberAction(ai, "swiftmend",15) {}

        virtual bool IsInstant() {return true;}
    };

    class CastWildGrowthOnPartyAction : public HealPartyMemberAction
    {
    public:
        CastWildGrowthOnPartyAction(PlayerbotAI* ai) : HealPartyMemberAction(ai, "wild growth",5) {}

        virtual bool IsInstant() {return true;}
    };

    class CastHealingTouchOnPartyAction : public HealPartyMemberAction
    {
    public:
        CastHealingTouchOnPartyAction(PlayerbotAI* ai) : HealPartyMemberAction(ai, "healing touch",25) {}
    };

    class CastInstantRegrowthAction : public CastHealingSpellAction {
	public:
		CastInstantRegrowthAction(PlayerbotAI* ai) : CastHealingSpellAction(ai, "regrowth",5) {}

		virtual bool isUseful() {return CastHealingSpellAction::isUseful() && ai->HasAura(69369, bot);}

		virtual bool IsInstant() {return true;}
	};

	class CastInstantRegrowthOnPartyAction : public HealPartyMemberAction
    {
    public:
        CastInstantRegrowthOnPartyAction(PlayerbotAI* ai) : HealPartyMemberAction(ai, "regrowth",5) {}

        virtual bool isUseful() {return HealPartyMemberAction::isUseful() && ai->HasAura(69369, bot);}
        virtual bool IsInstant() {return true;}
    };

    class CastInstantHealingTouchAction : public CastHealingSpellAction {
    public:
        CastInstantHealingTouchAction(PlayerbotAI* ai) : CastHealingSpellAction(ai, "healing touch",10) {}

        virtual bool isUseful() {return CastHealingSpellAction::isUseful() && ai->HasAura(69369, bot);}
        virtual bool IsInstant() {return true;}
    };

    class CastInstantHealingTouchOnPartyAction : public HealPartyMemberAction
    {
    public:
        CastInstantHealingTouchOnPartyAction(PlayerbotAI* ai) : HealPartyMemberAction(ai, "healing touch",10) {}

        virtual bool isUseful() {return HealPartyMemberAction::isUseful() && ai->HasAura(69369, bot);}
        virtual bool IsInstant() {return true;}
    };

	class CastReviveAction : public ResurrectPartyMemberAction
	{
	public:
		CastReviveAction(PlayerbotAI* ai) : ResurrectPartyMemberAction(ai, "revive") {}

		virtual NextAction** getPrerequisites() {
			return NextAction::merge( NextAction::array(0, new NextAction("caster form"), NULL), ResurrectPartyMemberAction::getPrerequisites());
		}
	};

    class CastRejuvenationOnMasterAction : public HealMasterAction
    {
    public:
        CastRejuvenationOnMasterAction(PlayerbotAI* ai) : HealMasterAction(ai, "rejuvenation",10) {}

        virtual bool IsInstant() {return true;}
    };

    class CastRegrowthOnMasterAction : public HealMasterAction
    {
    public:
        CastRegrowthOnMasterAction(PlayerbotAI* ai) : HealMasterAction(ai, "regrowth",20) {}

        virtual bool isPossible() {
			return HealMasterAction::isPossible() && !ai->HasAura("dire bear form", GetTarget()) && !ai->HasAura("bear form", GetTarget());
		}
    };

    class CastNourishOnMasterAction : public HealMasterAction
    {
    public:
        CastNourishOnMasterAction(PlayerbotAI* ai) : HealMasterAction(ai, "nourish",15) {}
    };

    class CastLifebloomOnMasterAction : public HealMasterAction
    {
    public:
        CastLifebloomOnMasterAction(PlayerbotAI* ai) : HealMasterAction(ai, "lifebloom",5) {}

        virtual bool IsInstant() {return true;}
    };

    class CastSwiftmendOnMasterAction : public HealMasterAction
    {
    public:
        CastSwiftmendOnMasterAction(PlayerbotAI* ai) : HealMasterAction(ai, "swiftmend",15) {}
        virtual bool IsInstant() {return true;}
    };

    class CastWildGrowthOnMasterAction : public HealMasterAction
    {
    public:
        CastWildGrowthOnMasterAction(PlayerbotAI* ai) : HealMasterAction(ai, "wild growth",5) {}
        virtual bool IsInstant() {return true;}
    };

    class CastHealingTouchOnMasterAction : public HealMasterAction
    {
    public:
        CastHealingTouchOnMasterAction(PlayerbotAI* ai) : HealMasterAction(ai, "healing touch",25) {}
    };

	class CastRebirthAction : public ResurrectPartyMemberAction
	{
	public:
		CastRebirthAction(PlayerbotAI* ai) : ResurrectPartyMemberAction(ai, "rebirth") {}

		virtual NextAction** getPrerequisites() {
			return NextAction::merge( NextAction::array(0, new NextAction("caster form"), NULL), ResurrectPartyMemberAction::getPrerequisites());
		}
	};
//Predator's swiftness aura
	class CastInstantRegrowthOnMasterAction : public HealMasterAction
    {
    public:
        CastInstantRegrowthOnMasterAction(PlayerbotAI* ai) : HealMasterAction(ai, "regrowth",10) {}

        bool isUseful() {return HealMasterAction::isUseful() && ai->HasAura(69369, bot);}
        virtual bool IsInstant() {return true;}
    };

    class CastInstantHealingTouchOnMasterAction : public HealMasterAction
    {
    public:
        CastInstantHealingTouchOnMasterAction(PlayerbotAI* ai) : HealMasterAction(ai, "healing touch",20) {}

        bool isUseful() {return HealMasterAction::isUseful() && ai->HasAura(69369, bot);}
        virtual bool IsInstant() {return true;}
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

		virtual bool IsInstant() {return true;}
	};

	class CastThornsAction : public CastBuffSpellAction {
	public:
		CastThornsAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "thorns") {}
		virtual bool isUseful() {return ai->HasAnyAuraOf(bot, "bear form", "dire bear form", "moonkin form", NULL);}
	};

	class CastThornsOnMasterAction : public BuffOnMasterAction {
	public:
		CastThornsOnMasterAction(PlayerbotAI* ai) : BuffOnMasterAction(ai, "thorns") {}

		virtual NextAction** getPrerequisites() {
			return NextAction::merge( NextAction::array(0, new NextAction("caster form"), NULL), BuffOnMasterAction::getPrerequisites());
		}
	};

	class CastThornsOnPartyAction : public BuffOnPartyAction {
	public:
		CastThornsOnPartyAction(PlayerbotAI* ai) : BuffOnPartyAction(ai, "thorns") {}
		virtual bool isUseful();

		virtual NextAction** getPrerequisites() {
			return NextAction::merge( NextAction::array(0, new NextAction("caster form"), NULL), BuffOnPartyAction::getPrerequisites());
		}
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
		virtual bool IsInstant() {return true;}
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

		virtual bool IsInstant() {return true;}
	};

	class CastInsectSwarmAction : public CastDebuffSpellAction
	{
	public:
		CastInsectSwarmAction(PlayerbotAI* ai) : CastDebuffSpellAction(ai, "insect swarm") {}

		virtual bool IsInstant() {return true;}
	};

	class CastStarfireAction : public CastSpellAction
	{
	public:
		CastStarfireAction(PlayerbotAI* ai) : CastSpellAction(ai, "starfire") {}
	};

	class CastEntanglingRootsAction : public CastDebuffSpellAction
	{
	public:
		CastEntanglingRootsAction(PlayerbotAI* ai) : CastDebuffSpellAction(ai, "entangling roots") {}
	};

	class CastWrathAction2 : public CastSpellAction
    	{
    	public:
        	CastWrathAction2(PlayerbotAI* ai) : CastSpellAction(ai, "wrath") {}
        	virtual bool isUseful() {
            	return (CastSpellAction::isUseful() && AI_VALUE2(uint8, "mana", "self target") > 75);
        	}
    	};

	class CastMoonfireAction2 : public CastSpellAction
    	{
    	public:
        	CastMoonfireAction2(PlayerbotAI* ai) : CastSpellAction(ai, "moonfire") {}
        	virtual bool isUseful() {
            	return (CastSpellAction::isUseful() && AI_VALUE2(uint8, "mana", "self target") > 75);
        	}
    	};

    class CastEntanglingRootsCcAction : public CastDebuffSpellAction
    {
    public:
        CastEntanglingRootsCcAction(PlayerbotAI* ai) : CastDebuffSpellAction(ai, "entangling roots on cc") {}
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
		virtual bool IsInstant() {return true;}
	};

	class CastNaturesSwiftnessAction : public CastBuffSpellAction
	{
	public:
		CastNaturesSwiftnessAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "nature's swiftness") {}
		virtual bool IsInstant() {return true;}
	};

	class CastNaturesSwiftnessAction : public CastBuffSpellAction
	{
	public:
		CastNaturesSwiftnessAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "nature's swiftness") {}
		virtual bool IsInstant() {return true;}
	};

	class CastNaturesSwiftnessOnMasterAction : public CastBuffSpellAction
	{
	public:
		CastNaturesSwiftnessOnMasterAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "nature's swiftness on master") {}
		virtual bool Execute(Event event);
		virtual bool IsInstant() {return true;}
	};

	class CastNaturesSwiftnessOnPartyAction : public CastBuffSpellAction
	{
	public:
		CastNaturesSwiftnessOnPartyAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "nature's swiftness on party") {}
		virtual bool Execute(Event event);
		virtual bool IsInstant() {return true;}
	};

	class CastHibernateAction : public CastSpellAction
	{
	public:
		CastHibernateAction(PlayerbotAI* ai) : CastSpellAction(ai, "hibernate") {}
	};

    class CastHibernateCcAction : public CastSpellAction
    {
    public:
        CastHibernateCcAction(PlayerbotAI* ai) : CastSpellAction(ai, "hibernate on cc") {}
        virtual Value<Unit*>* GetTargetValue();
        virtual bool Execute(Event event);
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

    class CastBarkskinAction : public CastBuffSpellAction
    {
    public:
        CastBarkskinAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "barkskin") {}
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
