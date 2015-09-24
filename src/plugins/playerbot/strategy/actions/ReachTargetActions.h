#pragma once

#include "../Action.h"
#include "MovementActions.h"
#include "../../PlayerbotAIConfig.h"

namespace ai
{
    class ReachTargetAction : public MovementAction
    {
    public:
        ReachTargetAction(PlayerbotAI* ai, string name, float distance) : MovementAction(ai, name)
		{
            this->distance = distance;
        }
        virtual bool Execute(Event event)
		{
		    if (distance <= sPlayerbotAIConfig.meleeDistance)
                return MoveToUnit(AI_VALUE(Unit*, "current target"));
            else
                return MoveTo(AI_VALUE(Unit*, "current target"), distance);
        }
        virtual bool IsInstant() {return false;}

        virtual bool isUseful()
		{
            Unit* target = AI_VALUE(Unit*, "current target");

            if (!target)
                return false;

            if (target && target->IsFriendlyTo(bot))
                return AI_VALUE2(float, "distance", "current target") > distance;

		    list<ObjectGuid> targets = AI_VALUE(list<ObjectGuid>, "possible targets");
            list<ObjectGuid> attackers = AI_VALUE(list<ObjectGuid>, "attackers");

            if (targets.size() == attackers.size() || ai->IsTank(bot))
                return AI_VALUE2(float, "distance", "current target") > distance;
            else
            {
                for (list<ObjectGuid>::iterator i = targets.begin(); i != targets.end(); ++i)
                {
                    Unit* unit = bot->GetPlayerbotAI()->GetUnit(*i);

                    if (!unit)
                        continue;

                    if (target && unit->GetGUID() == target->GetGUID())
                        continue;

                    if (unit->IsInCombat())
                        continue;

                    float d = unit->GetDistance(target);
                    if (d <= sPlayerbotAIConfig.aggroDistance)
                        return false;
                }
                    return AI_VALUE2(float, "distance", "current target") > distance;
            }


        }
        virtual string GetTargetName() { return "current target"; }

    protected:
        float distance;
    };

    class CastReachTargetSpellAction : public CastSpellAction
    {
    public:
        CastReachTargetSpellAction(PlayerbotAI* ai, string spell, float distance) : CastSpellAction(ai, spell)
		{
            this->distance = distance;
        }
		virtual bool isUseful()
		{
			return AI_VALUE2(float, "distance", "current target") > distance;
		}

    protected:
        float distance;
    };

    class ReachMeleeAction : public ReachTargetAction
	{
    public:
        ReachMeleeAction(PlayerbotAI* ai) : ReachTargetAction(ai, "reach melee", sPlayerbotAIConfig.meleeDistance) {}
    };

    class ReachSpellAction : public ReachTargetAction
	{
    public:
        ReachSpellAction(PlayerbotAI* ai, float distance = sPlayerbotAIConfig.spellDistance) : ReachTargetAction(ai, "reach spell", distance) {}
    };
}
