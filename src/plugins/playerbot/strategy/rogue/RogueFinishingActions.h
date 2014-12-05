#pragma once

namespace ai
{
	class CastEviscerateAction : public CastMeleeSpellAction
	{
	public:
		CastEviscerateAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "eviscerate") {}

		//virtual bool isUseful()
	    //{
	    //    return AI_VALUE2(uint8, "combo", "self target") > 2;
	    //}
	};

    class CastEnvenomAction : public CastMeleeSpellAction
	{
	public:
		CastEnvenomAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "envenom") {}

		virtual NextAction** getAlternatives();

        //virtual bool isUseful()
	   // {
	   //     return AI_VALUE2(uint8, "combo", "self target") > 2;
	   // }
	};

	class CastSliceAndDiceAction : public CastMeleeSpellAction
	{
	public:
		CastSliceAndDiceAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "slice and dice") {}
		virtual bool isUseful()
	    {
	        return !ai->HasAura(spell, AI_VALUE(Unit*, "self target"));
	    }
	};

	class CastExposeArmorAction : public CastMeleeSpellAction
	{
	public:
		CastExposeArmorAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "expose armor") {}
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

		virtual bool isUseful()
	    {
	        return AI_VALUE2(uint8, "health", "current target") > 20;
	    }
	};

	class CastKidneyShotAction : public CastMeleeSpellAction
	{
	public:
		CastKidneyShotAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "kidney shot") {}
	};

}
