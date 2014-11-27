#pragma once

namespace ai
{
	class CastSapAction : public CastMeleeSpellAction
    {
    public:
        CastSapAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "sap on cc") {}
        virtual Value<Unit*>* GetTargetValue()
        {
            return context->GetValue<Unit*>("cc target", "sap");
        }

        virtual bool Execute(Event event)
        {
            return ai->CastSpell("sap", GetTarget());
        }
    };


	class CastGarroteAction : public CastMeleeSpellAction
	{
	public:
		CastGarroteAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "garrote") {}

		virtual bool isUseful() {
            return CastMeleeSpellAction::isUseful() && ai->HasAura("stealth", AI_VALUE(Unit*, "self target"));
        }

        virtual NextAction** getPrerequisites()
        {
            return NextAction::merge( NextAction::array(0, new NextAction("reach melee"), NULL), CastMeleeSpellAction::getPrerequisites());
        }
	};

    class CastAmbushAction : public CastMeleeSpellAction
	{
	public:
		CastAmbushAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "ambush") {}

        virtual bool isUseful() {
            return CastMeleeSpellAction::isUseful() && ai->HasAura("stealth", AI_VALUE(Unit*, "self target"));
        }

        virtual NextAction** getPrerequisites()
        {
            return NextAction::merge( NextAction::array(0, new NextAction("reach melee"), NULL), CastMeleeSpellAction::getPrerequisites());
        }

        virtual NextAction** getAlternatives();
	};

	class CastCheapShotAction : public CastMeleeSpellAction
	{
	public:
		CastCheapShotAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "cheap shot") {}

        virtual bool isUseful() {
            return CastMeleeSpellAction::isUseful() && ai->HasAura("stealth", AI_VALUE(Unit*, "self target"));
        }

        virtual NextAction** getPrerequisites()
        {
            return NextAction::merge( NextAction::array(0, new NextAction("reach melee"), NULL), CastMeleeSpellAction::getPrerequisites());
        }
    };
}
