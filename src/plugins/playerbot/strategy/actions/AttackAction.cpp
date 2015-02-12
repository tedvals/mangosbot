#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "AttackAction.h"
#include "../../../Movement/MovementGenerator.h"
#include "../../../game/AI/CreatureAI.h"
#include "../../../Entities/Pet/Pet.h"
#include "../../LootObjectStack.h"

using namespace ai;

bool AttackAction::Execute(Event event)
{
    Unit* target = GetTarget();

    if (!target)
        return false;

    return Attack(target);
}

bool AttackMyTargetAction::Execute(Event event)
{
    Player* master = GetMaster();
    if (!master)
        return false;

    Unit* target = master->GetSelectedUnit();
    if (!target)
    {
        if (verbose) ai->TellMaster("You have no target");
        return false;
    }

    return Attack(target);
}

bool AttackAction::Attack(Unit* target)
{
    MotionMaster &mm = *bot->GetMotionMaster();
    if (bot->IsFlying())
    {
        if (verbose) ai->TellMaster("I cannot attack in flight");
        return false;
    }

    if (!target)
    {
        if (verbose) ai->TellMaster("I have no target");
        return false;
    }

    ostringstream msg;
    msg << target->GetName();
    if (bot->IsFriendlyTo(target))
    {
        msg << " is friendly to me";
        if (verbose) ai->TellMaster(msg.str());
        return false;
    }
    if (!bot->IsWithinLOSInMap(target))
    {
        msg << " is not on my sight";
        if (verbose) ai->TellMaster(msg.str());
        return false;
    }

    if (bot->IsMounted())
    {
        WorldPacket emptyPacket;
        bot->GetSession()->HandleCancelMountAuraOpcode(emptyPacket);
    }

    ObjectGuid guid = target->GetGUID();
    bot->SetSelection(target->GetGUID());

    Unit* oldTarget = context->GetValue<Unit*>("current target")->Get();
    context->GetValue<Unit*>("old target")->Set(oldTarget);

    context->GetValue<Unit*>("current target")->Set(target);
    context->GetValue<LootObjectStack*>("available loot")->Get()->Add(guid);

    Pet* pet = bot->GetPet();
    if (pet)
    {
        pet->SetTarget(target->GetGUID());
        pet->AI()->EnterCombat(target);
		pet->GetCharmInfo()->SetIsCommandAttack(true);
		pet->AI()->AttackStart(target);
    }
//needs testing to prevent melee hits from stealth
/*
    if (name != "attack" && name != "attack least hp target" && name != "attack my target" && name != "attack rti target" && name != "attack duel target" && name != "attack anything" && name != "attack duel target" && name != "reach melee" && name != "shadowstep" && name != "get behind" )
    {

        if (bot->getLevel() > 19 && ai->HasAura("stealth",bot) && (name != "shadowstep" && name != "ambush" && name != "garrote" && name != "cheap shot" && name != "sap"))
            return false;

        if (bot->getLevel() > 31 && ai->HasAura("prowl",bot) && (name != "ravage" && name != "pounce"))
            return false;
    }
*/
    if (!((bot->getLevel() > 19 && ai->HasAura("stealth",bot)) || (bot->getLevel() > 31 && ai->HasAura("prowl",bot))))
        bot->Attack(target, true);
    //else bot->Attack(target, false);

    ai->ChangeEngine(BOT_STATE_COMBAT);
    return true;
}

bool AttackDuelOpponentAction::isUseful()
{
    return AI_VALUE(Unit*, "duel target");
}

bool AttackDuelOpponentAction::Execute(Event event)
{
    return Attack(AI_VALUE(Unit*, "duel target"));
}
