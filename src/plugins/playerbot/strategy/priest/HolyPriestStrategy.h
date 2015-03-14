#pragma once

#include "HealPriestStrategy.h"

namespace ai
{
    class HolyPriestStrategy : public GenericPriestStrategy
    {
    public:
        HolyPriestStrategy(PlayerbotAI* ai);

    public:
        virtual NextAction** getDefaultActions();
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
        virtual string getName() { return "holy"; }
        virtual int GetType() { return STRATEGY_TYPE_HEAL; }
    };

    class DpsHolyPriestStrategy : public GenericPriestStrategy
    {
    public:
        DpsHolyPriestStrategy(PlayerbotAI* ai);

    public:
        virtual NextAction** getDefaultActions();
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
        virtual string getName() { return "holy dps"; }
        virtual int GetType() { return STRATEGY_TYPE_DPS|STRATEGY_TYPE_RANGED; }
    };
}
