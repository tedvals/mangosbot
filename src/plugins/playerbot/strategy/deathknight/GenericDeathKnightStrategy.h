#pragma once

#include "../Strategy.h"
#include "../generic/MeleeCombatStrategy.h"

namespace ai
{
    class AiObjectContext;

    class GenericDeathKnightStrategy : public MeleeCombatStrategy
    {
    public:
        GenericDeathKnightStrategy(PlayerbotAI* ai);

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
        virtual string getName() { return "death knight"; }
    };


    class DeathKnightBuffDpsStrategy : public Strategy
    {
    public:
        DeathKnightBuffDpsStrategy(PlayerbotAI* ai) : Strategy(ai) {}

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
        virtual string getName() { return "bdps"; }
    };

    class DeathKnightBuffHealthStrategy : public Strategy
    {
    public:
	DeathKnightBuffHealthStrategy(PlayerbotAI* ai) : Strategy(ai) {}

    public:
	virtual void InitTriggers(std::list<TriggerNode*> &triggers);
	virtual string getName() { return "bhealth"; }
	};

    class DeathKnightBuffSpeedStrategy : public Strategy
    {
    public:
	DeathKnightBuffSpeedStrategy(PlayerbotAI* ai) : Strategy(ai) {}

    public:
	virtual void InitTriggers(std::list<TriggerNode*> &triggers);
	virtual string getName() { return "bspeed"; }
	};

}
