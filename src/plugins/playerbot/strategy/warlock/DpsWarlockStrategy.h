#pragma once

#include "GenericWarlockStrategy.h"
#include "../generic/CombatStrategy.h"

namespace ai
{
    class DpsWarlockStrategy : public GenericWarlockStrategy
    {
    public:
        DpsWarlockStrategy(PlayerbotAI* ai);
        virtual string getName() { return "dps"; }

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
        virtual NextAction** getDefaultActions();
    };

    class DpsAoeWarlockStrategy : public CombatStrategy
    {
    public:
        DpsAoeWarlockStrategy(PlayerbotAI* ai) : CombatStrategy(ai) {}

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
        virtual string getName() { return "aoe"; }
    };

    class DpsFireWarlockStrategy : public GenericWarlockStrategy
    {
    public:
        DpsFireWarlockStrategy(PlayerbotAI* ai);
        virtual string getName() { return "fire"; }

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
        virtual NextAction** getDefaultActions();
    };

    class DpsFireAoeWarlockStrategy : public CombatStrategy
    {
    public:
        DpsFireAoeWarlockStrategy(PlayerbotAI* ai) : CombatStrategy(ai) {}

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
        virtual string getName() { return "fire aoe"; }
    };

    class DpsWarlockDebuffStrategy : public CombatStrategy
    {
    public:
        DpsWarlockDebuffStrategy(PlayerbotAI* ai);

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
        virtual string getName() { return "dps debuff"; }
    };

    class WarlockDebuffStrategy : public CombatStrategy
    {
    public:
        WarlockDebuffStrategy(PlayerbotAI* ai);

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
        virtual string getName() { return "debuff"; }
    };

}
