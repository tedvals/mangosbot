#pragma once

#include "../generic/NonCombatStrategy.h"

namespace ai
{
    class GenericDeathKnightNonCombatStrategy : public NonCombatStrategy
    {
    public:
        GenericDeathKnightNonCombatStrategy(PlayerbotAI* ai) : NonCombatStrategy(ai) {}
        virtual string getName() { return "nc"; }

        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
   };
}
