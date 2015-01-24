#pragma once

namespace ai
{
	class CastEviscerateAction : public CastMeleeSpellAction
	{
	public:
		CastEviscerateAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "eviscerate") {}

		virtual bool isUseful()
	    {
	         return AI_VALUE2(uint8, "combo", "current target") >= 3 || AI_VALUE2(uint8, "health", "current target") < sPlayerbotAIConfig.almostDead;
	    }
	};

    class CastEnvenomAction : public CastMeleeSpellAction
	{
	public:
		CastEnvenomAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "envenom") {}

    virtual NextAction** getAlternatives();
        virtual bool isUseful()
	    {
	         return AI_VALUE2(uint8, "combo", "current target") >= 3 || AI_VALUE2(uint8, "health", "current target") < sPlayerbotAIConfig.almostDead;
	    }
	};

	class CastSliceAndDiceAction : public CastMeleeSpellAction
	{
	public:
		CastSliceAndDiceAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "slice and dice") {}
		virtual NextAction** getAlternatives();

		virtual bool isUseful()
	    {
	        return !ai->HasAura(spell, AI_VALUE(Unit*, "self target"));
	    }

	};

	class CastExposeArmorAction : public CastMeleeSpellAction
	{
	public:
		CastExposeArmorAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "expose armor") {}

		virtual bool isUseful()
	    {
	        return AI_VALUE2(uint8, "health", "current target") > sPlayerbotAIConfig.almostDead && (AI_VALUE2(bool, "target elite", "current target") || AI_VALUE2(bool, "target player", "current target"));
	    }
	};

	class CastDeadlyThrowAction : public CastMeleeSpellAction
	{
	public:
		CastDeadlyThrowAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "deadly throw") {}
	};

	class CastRuptureAction : public CastDebuffSpellAction
	{
	public:
		CastRuptureAction(PlayerbotAI* ai) : CastDebuffSpellAction(ai, "rupture") {}

		virtual NextAction** getAlternatives();

		virtual bool isUseful()
	    {
	        return AI_VALUE2(uint8, "health", "current target") > sPlayerbotAIConfig.almostDead && ((AI_VALUE2(bool, "target elite", "current target") || AI_VALUE2(bool, "target player", "current target")));
	    }
	};

	class CastKidneyShotAction : public CastMeleeSpellAction
	{
	public:
		CastKidneyShotAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "kidney shot") {}
	};

}
