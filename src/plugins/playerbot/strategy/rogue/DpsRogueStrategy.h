#pragma once

#include "../Strategy.h"
#include "../generic/MeleeCombatStrategy.h"

namespace ai
{
    class DpsRogueStrategy : public MeleeCombatStrategy
    {
    public:
        DpsRogueStrategy(PlayerbotAI* ai);

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
        virtual string getName() { return "dps"; }
        virtual NextAction** getDefaultActions();
    };

    class DpsSwordRogueStrategy : public DpsRogueStrategy
    {
    public:
        DpsSwordRogueStrategy(PlayerbotAI* ai);

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
        virtual string getName() { return "sword"; }
        virtual NextAction** getDefaultActions();
    };

     class DpsDaggerRogueStrategy : public DpsRogueStrategy
    {
    public:
        DpsDaggerRogueStrategy(PlayerbotAI* ai);

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
        virtual string getName() { return "dagger"; }
        virtual NextAction** getDefaultActions();
    };
}
