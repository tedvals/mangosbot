#pragma once

#include "GenericDeathKnightStrategy.h"

namespace ai
{
    class TankDeathKnightStrategy : public GenericDeathKnightStrategy
    {
    public:
        TankDeathKnightStrategy(PlayerbotAI* ai);

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
        virtual string getName() { return "tank"; }
        virtual NextAction** getDefaultActions();
        virtual int GetType() { return STRATEGY_TYPE_TANK | STRATEGY_TYPE_MELEE; }
    };
}
