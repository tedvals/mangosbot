#pragma once

namespace ai
{
	class CastSapAction : public CastMeleeSpellAction
	{
	public:
		CastSapAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "sap") {}
	};

	class CastGarroteAction : public CastMeleeSpellAction
	{
	public:
		CastGarroteAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "garrote") {}

        virtual NextAction** getPrerequisites()
        {
            return NextAction::merge( NextAction::array(0, new NextAction("reach melee"), NULL), CastMeleeSpellAction::getPrerequisites());
        }
	};

    class CastAmbushAction : public CastMeleeSpellAction
	{
	public:
		CastAmbushAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "ambush") {}

        virtual NextAction** getPrerequisites()
        {
            return NextAction::merge( NextAction::array(0, new NextAction("reach melee"), NULL), CastMeleeSpellAction::getPrerequisites());
        }
	};

	class CastCheapShotAction : public CastMeleeSpellAction
	{
	public:
		CastCheapShotAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "cheap shot") {}
	};

}
