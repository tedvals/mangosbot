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

		virtual NextAction** getAlternatives();
	};

	class CastExposeArmorAction : public CastMeleeSpellAction
	{
	public:
		CastExposeArmorAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "expose armor") {}
	};

	class CastRuptureAction : public CastMeleeSpellAction
	{
	public:
		CastRuptureAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "rupture") {}

		virtual bool isUseful()
	    {
	        return AI_VALUE2(uint8, "health", "current target") > 20;
	    }

	    virtual NextAction** getAlternatives();
	};

	class CastKidneyShotAction : public CastMeleeSpellAction
	{
	public:
		CastKidneyShotAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "kidney shot") {}
	};

}
