#pragma once

#include "GenericDeathKnightStrategy.h"

namespace ai
{
    class DpsDeathKnightStrategy : public GenericDeathKnightStrategy
    {
    public:
        DpsDeathKnightStrategy(PlayerbotAI* ai);

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
        virtual string getName() { return "dps"; }
        virtual NextAction** getDefaultActions();
        virtual int GetType() { return STRATEGY_TYPE_COMBAT | STRATEGY_TYPE_DPS | STRATEGY_TYPE_MELEE; }
    };

    class DpsBloodDeathKnightStrategy : public GenericDeathKnightStrategy
    {
    public:
        DpsBloodDeathKnightStrategy(PlayerbotAI* ai);

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
        virtual string getName() { return "blood dps"; }
        virtual NextAction** getDefaultActions();
        virtual int GetType() { return STRATEGY_TYPE_COMBAT | STRATEGY_TYPE_DPS | STRATEGY_TYPE_MELEE; }
    };

    class DpsFrostDeathKnightStrategy : public GenericDeathKnightStrategy
    {
    public:
        DpsFrostDeathKnightStrategy(PlayerbotAI* ai);

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
        virtual string getName() { return "frost dps"; }
        virtual NextAction** getDefaultActions();
        virtual int GetType() { return STRATEGY_TYPE_COMBAT | STRATEGY_TYPE_DPS | STRATEGY_TYPE_MELEE; }
    };

    class DpsUnholyDeathKnightStrategy : public GenericDeathKnightStrategy
    {
    public:
        DpsUnholyDeathKnightStrategy(PlayerbotAI* ai);

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
        virtual string getName() { return "unholy dps"; }
        virtual NextAction** getDefaultActions();
        virtual int GetType() { return STRATEGY_TYPE_COMBAT | STRATEGY_TYPE_DPS | STRATEGY_TYPE_MELEE; }
    };

    class DpsDeathKnightAoeStrategy : public CombatStrategy
    {
    public:
        DpsDeathKnightAoeStrategy(PlayerbotAI* ai) : CombatStrategy(ai) {}

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
        virtual NextAction** getDefaultActions();
        virtual string getName() { return "aoe"; }
    };
}
