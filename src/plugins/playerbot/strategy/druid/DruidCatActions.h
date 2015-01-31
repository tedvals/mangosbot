#pragma once

namespace ai {

    class CastCatComboAction : public CastMeleeSpellAction
	{
	public:
	    CastCatComboAction(PlayerbotAI* ai, string name) : CastMeleeSpellAction(ai, name) {}

	    virtual bool isUseful()
	    {
	        return CastMeleeSpellAction::isUseful() && AI_VALUE2(uint8, "combo", "current target") <= 5;
	    }
	};

	class CastFeralChargeCatAction : public CastReachTargetSpellAction
	{
	public:
		CastFeralChargeCatAction(PlayerbotAI* ai) : CastReachTargetSpellAction(ai, "feral charge - cat", 3.0f) {}

		//virtual bool isUseful()
	    //{
	    //    return CastReachTargetSpellAction::isUseful() && AI_VALUE2(bool, "combat", "self target");
	    //}
	};

	class CastCowerAction : public CastBuffSpellAction
	{
	public:
		CastCowerAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "cower") {}
	};

	class CastDashAction : public CastBuffSpellAction
	{
	public:
		CastDashAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "dash") {}
	};

    class CastProwlAction : public CastBuffSpellAction
	{
	public:
		CastProwlAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "prowl") {}
	};

	class CastSavageRoarAction : public CastBuffSpellAction
	{
	public:
		CastSavageRoarAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "savage roar") {}
	};

	class CastTigersFuryAction : public CastBuffSpellAction
	{
	public:
		CastTigersFuryAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "tiger's fury") {}
	};

	class CastRakeAction : public CastDebuffSpellAction
	{
	public:
		CastRakeAction(PlayerbotAI* ai) : CastDebuffSpellAction(ai, "rake") {}

        virtual NextAction** getPrerequisites()
        {
            return NextAction::merge( NextAction::array(0, new NextAction("move behind"), NULL), CastDebuffSpellAction::getPrerequisites());
        }

        virtual bool isUseful()
	    {
	        return CastDebuffSpellAction::isUseful() && !ai->HasAura("prowl", bot);
	    }
	};

    class CastRipAction : public CastDebuffSpellAction {
	public:
		CastRipAction(PlayerbotAI* ai) : CastDebuffSpellAction(ai, "rip") {}
		virtual bool isUseful()
	    {
	        return  CastDebuffSpellAction::isUseful() &&  (AI_VALUE2(uint8, "health", "current target") > sPlayerbotAIConfig.criticalHealth) && (AI_VALUE2(uint8, "combo", "current target") >= 2);
	    }
	};

    class CastShredAction : public CastCatComboAction {
	public:
		CastShredAction(PlayerbotAI* ai) : CastCatComboAction(ai, "shred") {}
		virtual bool isUseful()
	    {
            return CastCatComboAction::isUseful() && AI_VALUE2(bool, "behind", "current target");
	    }
	};

	class CastClawAction : public  CastCatComboAction {
	public:
		CastClawAction(PlayerbotAI* ai) : CastCatComboAction(ai, "claw") {}
	};

	class CastMangleCatAction : public  CastCatComboAction {
	public:
		CastMangleCatAction(PlayerbotAI* ai) : CastCatComboAction(ai, "mangle (cat)") {}
	};

	class CastSwipeCatAction : public  CastCatComboAction {
	public:
		CastSwipeCatAction(PlayerbotAI* ai) : CastCatComboAction(ai, "swipe (cat)") {}
	};

	class CastFerociousBiteAction : public CastMeleeSpellAction {
	public:
		CastFerociousBiteAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "ferocious bite") {}

		virtual bool isUseful()
	    {
	         return AI_VALUE2(uint8, "combo", "current target") > 4 || AI_VALUE2(uint8, "health", "current target") < sPlayerbotAIConfig.almostDead;
	    }
	};

	class CastPounceAction : public CastMeleeSpellAction {
	public:
		CastPounceAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "pounce") {}

		virtual bool isUseful() {
            return CastMeleeSpellAction::isUseful() && ai->HasAura("prowl", AI_VALUE(Unit*, "self target"));
        }

        virtual NextAction** getPrerequisites()
        {
            return NextAction::merge( NextAction::array(0, new NextAction("move behind"), NULL), CastMeleeSpellAction::getPrerequisites());
        }
	};

	class CastRavageAction : public CastMeleeSpellAction {
	public:
		CastRavageAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "ravage") {}

		virtual bool isUseful() {
            return CastMeleeSpellAction::isUseful() &&  ai->HasAura("prowl", AI_VALUE(Unit*, "self target")) && AI_VALUE2(bool, "target normal", "current target");
        }

        virtual NextAction** getPrerequisites()
        {
            return NextAction::merge( NextAction::array(0, new NextAction("move behind"), NULL), CastMeleeSpellAction::getPrerequisites());
        }

	};

}
