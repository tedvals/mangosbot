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
		CastFeralChargeCatAction(PlayerbotAI* ai) : CastReachTargetSpellAction(ai, "feral charge - cat", 1.5f) {}
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
            return NextAction::merge( NextAction::array(0, new NextAction("reach melee"), NULL), CastDebuffSpellAction::getPrerequisites());
        }
	};

    class CastRipAction : public CastDebuffSpellAction {
	public:
		CastRipAction(PlayerbotAI* ai) : CastDebuffSpellAction(ai, "rip") {}
		virtual bool isUseful()
	    {
	        return  CastDebuffSpellAction::isUseful() &&  AI_VALUE2(uint8, "health", "current target") > sPlayerbotAIConfig.criticalHealth/2 && (AI_VALUE2(uint8, "combo", "current target") >= 4);
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
	        return (CastMeleeSpellAction::isUseful() && AI_VALUE2(uint8, "energy", "self target") > 30) || (AI_VALUE2(uint8, "health", "target") < sPlayerbotAIConfig.criticalHealth/2);
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
            return NextAction::merge( NextAction::array(0, new NextAction("reach melee"), NULL), CastMeleeSpellAction::getPrerequisites());
        }
	};

	class CastRavageAction : public CastMeleeSpellAction {
	public:
		CastRavageAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "ravage") {}

		virtual bool isUseful() {
            return CastMeleeSpellAction::isUseful() &&  ai->HasAura("prowl", AI_VALUE(Unit*, "self target"));
        }

        virtual NextAction** getPrerequisites()
        {
            return NextAction::merge( NextAction::array(0, new NextAction("reach melee"), NULL), CastMeleeSpellAction::getPrerequisites());
        }

	};

}
