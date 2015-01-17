#pragma once

namespace ai
{
    class CastSapAction : public CastMeleeSpellAction
	{
	public:
		CastSapAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "sap") {}

		virtual bool isUseful() {
            return CastMeleeSpellAction::isUseful() && ai->HasAura("stealth", AI_VALUE(Unit*, "self target"));
        }

        virtual NextAction** getPrerequisites()
        {
            return NextAction::merge( NextAction::array(0, new NextAction("move behind"), NULL), CastMeleeSpellAction::getPrerequisites());
        }
	};

	class CastSapCcAction : public CastMeleeSpellAction
    {
    public:
        CastSapCcAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "sap on cc") {}

        virtual bool isUseful() {
            return CastMeleeSpellAction::isUseful() && !AI_VALUE2(bool, "combat", "current target") && ai->HasAura("stealth", AI_VALUE(Unit*, "self target"));
        }

        virtual Value<Unit*>* GetTargetValue()
        {
            return context->GetValue<Unit*>("cc target4", "sap");
        }

        virtual bool Execute(Event event)
        {
            return ai->CastSpell("sap", GetTarget());
        }

        virtual NextAction** getPrerequisites()
        {
            return NextAction::merge( NextAction::array(0, new NextAction("move behind"), NULL), CastMeleeSpellAction::getPrerequisites());
        }

        virtual NextAction** getAlternatives();
    };


	class CastGarroteAction : public CastMeleeSpellAction
	{
	public:
		CastGarroteAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "garrote") {}

        virtual bool isUseful() {
            return CastMeleeSpellAction::isUseful() && ai->HasAura("stealth", AI_VALUE(Unit*, "self target"))
             && (!AI_VALUE2(bool, "target normal", "current target"));

        }

        virtual NextAction** getPrerequisites()
        {
            return NextAction::merge( NextAction::array(0, new NextAction("move behind"), NULL), CastMeleeSpellAction::getPrerequisites());
        }

        virtual NextAction** getAlternatives()
        {
            return NextAction::merge( NextAction::array(0, new NextAction("ambush"), NULL), CastMeleeSpellAction::getAlternatives());
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
            return NextAction::merge( NextAction::array(0, new NextAction("move behind"), NULL), CastMeleeSpellAction::getPrerequisites());
        }

	};

	class CastCheapShotAction : public CastMeleeSpellAction
	{
	public:
		CastCheapShotAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "cheap shot") {}

        virtual bool isUseful() {
            return CastMeleeSpellAction::isUseful() && AI_VALUE2(bool, "target normal", "current target") && ai->HasAura("stealth", AI_VALUE(Unit*, "self target"));
        }

        virtual NextAction** getPrerequisites()
        {
            return NextAction::merge( NextAction::array(0, new NextAction("reach melee"), NULL), CastMeleeSpellAction::getPrerequisites());
        }
    };
}
