#pragma once

namespace ai
{
	class CastComboAction : public CastMeleeSpellAction
	{
	public:
	    CastComboAction(PlayerbotAI* ai, string name) : CastMeleeSpellAction(ai, name) {}

	    virtual bool isUseful()
	    {
	        return CastMeleeSpellAction::isUseful() && !ai->HasAura("stealth", AI_VALUE(Unit*, "self target")) && AI_VALUE2(uint8, "combo", "current target") < 5;
	    }

        virtual NextAction** getPrerequisites()
        {
            return NextAction::merge( NextAction::array(0, new NextAction("reach melee"), NULL), CastMeleeSpellAction::getPrerequisites());
        }
	};

	class CastSinisterStrikeAction : public CastComboAction
	{
	public:
		CastSinisterStrikeAction(PlayerbotAI* ai) : CastComboAction(ai, "sinister strike") {}
	};

    class CastMutilateAction : public CastComboAction
    {
    public:
        CastMutilateAction(PlayerbotAI* ai) : CastComboAction(ai, "mutilate") {}

        virtual NextAction** getAlternatives();
    };

    class CastFanOfKnivesAction : public CastComboAction
    {
    public:
        CastFanOfKnivesAction(PlayerbotAI* ai) : CastComboAction(ai, "fan of knives") {}
    };

    class CastRiposteAction : public CastComboAction
    {
    public:
        CastRiposteAction(PlayerbotAI* ai) : CastComboAction(ai, "riposte") {}
    };

	class CastGougeAction : public CastComboAction
	{
	public:
		CastGougeAction(PlayerbotAI* ai) : CastComboAction(ai, "gouge") {}
	};

    class CastBackstabAction : public CastComboAction
    {
    public:
        CastBackstabAction(PlayerbotAI* ai) : CastComboAction(ai, "backstab") {}

        virtual NextAction** getAlternatives();
    };

    class CastHemorrhageAction : public CastComboAction
    {
    public:
        CastHemorrhageAction(PlayerbotAI* ai) : CastComboAction(ai, "hemorrhage") {}
    };

    class CastGhostlyStrikeAction : public CastComboAction
    {
    public:
        CastGhostlyStrikeAction(PlayerbotAI* ai) : CastComboAction(ai, "ghostly strike") {}
    };
}