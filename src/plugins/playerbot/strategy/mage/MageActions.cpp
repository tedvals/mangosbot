#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "MageActions.h"

using namespace ai;

Value<Unit*>* CastPolymorphAction::GetTargetValue()
{
    return context->GetValue<Unit*>("cc target", getName());
}
bool CastPolymorphAction::Execute(Event event)
{
    return ai->CastSpell("entangling roots", GetTarget());
}

bool CastScorchAction::isUseful()
{
    return !ai->HasAnyAuraOf(GetTarget(), "shadow mastery", "improved scorch", NULL);
}

bool CastFocusMagicOnPartyAction::isUseful()
{
    return !ai->HasAura("focus magic", AI_VALUE(Unit*, "self target"));
}
