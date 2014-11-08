#pragma once

namespace ai {

    class CastCatComboAction : public CastMeleeSpellAction
	{
	public:
	    CastCatComboAction(PlayerbotAI* ai, string name) : CastMeleeSpellAction(ai, name) {}

	    virtual bool isUseful()
	    {
	        return CastMeleeSpellAction::isUseful() && AI_VALUE2(uint8, "combo", "self target") <= 5;
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

	class CastBerserkAction : public CastBuffSpellAction
	{
	public:
		CastBerserkAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "berserk") {}
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
	};

    class CastShredAction : public CastCatComboAction {
	public:
		CastShredAction(PlayerbotAI* ai) : CastCatComboAction(ai, "shred") {}
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
	        return CastMeleeSpellAction::isUseful() && AI_VALUE2(uint8, "energy", "self target") > 50;
	    }
	};

	class CastPounceAction : public CastMeleeSpellAction {
	public:
		CastPounceAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "pounce") {}

        virtual NextAction** getPrerequisites()
        {
            return NextAction::merge( NextAction::array(0, new NextAction("stealth"), NULL), CastMeleeSpellAction::getPrerequisites());
        }
	};

	class CastRavageAction : public CastMeleeSpellAction {
	public:
		CastRavageAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "ravage") {}

		virtual NextAction** getPrerequisites()
        {
            return NextAction::merge( NextAction::array(0, new NextAction("stealth"), NULL), CastMeleeSpellAction::getPrerequisites());
        }
	};

}
