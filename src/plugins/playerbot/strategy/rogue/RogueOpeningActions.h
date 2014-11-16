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
        virtual bool isPossible() {return ai->HasAura("stealth",ai->GetUnitBot());}

        virtual bool Execute(Event event)
        {
            return ai->CastSpell("sap", GetTarget());
        }
    };


	class CastGarroteAction : public CastMeleeSpellAction
	{
	public:
		CastGarroteAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "garrote") {}

        virtual bool isPossible() {return ai->HasAura("stealth",ai->GetUnitBot());}

        virtual NextAction** getPrerequisites()
        {
            return NextAction::merge( NextAction::array(0, new NextAction("reach melee"), NULL), CastMeleeSpellAction::getPrerequisites());
        }
	};

    class CastAmbushAction : public CastMeleeSpellAction
	{
	public:
		CastAmbushAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "ambush") {}

        virtual bool isPossible() {return ai->HasAura("stealth",ai->GetUnitBot());}
        virtual NextAction** getPrerequisites()
        {
            return NextAction::merge( NextAction::array(0, new NextAction("reach melee"), NULL), CastMeleeSpellAction::getPrerequisites());
        }
	};

	class CastCheapShotAction : public CastMeleeSpellAction
	{
	public:
		CastCheapShotAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "cheap shot") {}

        virtual bool isPossible() {return ai->HasAura("stealth",ai->GetUnitBot());}
        virtual NextAction** getPrerequisites()
        {
            return NextAction::merge( NextAction::array(0, new NextAction("reach melee"), NULL), CastMeleeSpellAction::getPrerequisites());
        }
    };
}
