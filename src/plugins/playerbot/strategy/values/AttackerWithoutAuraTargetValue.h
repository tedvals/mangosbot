#pragma once
#include "../Value.h"

namespace ai
{
    class AttackerWithoutAuraTargetValue : public UnitCalculatedValue, public Qualified
	{
	public:
        AttackerWithoutAuraTargetValue(PlayerbotAI* ai) :
            UnitCalculatedValue(ai, "attacker without aura") {}

    protected:
        virtual Unit* Calculate();
	};

    class AttackerWithoutOwnAuraTargetValue : public UnitCalculatedValue, public Qualified
	{
	public:
        AttackerWithoutOwnAuraTargetValue(PlayerbotAI* ai) :
            UnitCalculatedValue(ai, "attacker without aura") {}

    protected:
        virtual Unit* Calculate();
	};
}
