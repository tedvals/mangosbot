#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "GenericActions.h"

using namespace ai;

bool CastSpellAction::Execute(Event event)
{
	return ai->CastSpell(spell, GetTarget());
}

bool CastSpellAction::isPossible()
{
    if (AI_VALUE2(float, "distance", GetTargetName()) > range)
        return false;

	return ai->CanCastSpell(spell, GetTarget());
}

bool CastSpellAction::isUseful()
{
	return GetTarget() && AI_VALUE2(bool, "spell cast useful", spell);
}

bool CastAuraSpellAction::isUseful()
{
	return CastSpellAction::isUseful() && !ai->HasAura(spell, GetTarget());
}

bool CastDebuffSpellAction::isUseful()
{
	return CastDebuffSpellAction::isUseful() && !ai->HasAura(spell, GetTarget(), BOT_AURA_DAMAGE);
}

bool CastDebuffSpellOnAttackerAction::isUseful()
{
	return CastDebuffSpellOnAttackerAction::isUseful() && !ai->HasAura(spell, GetTarget(), BOT_AURA_DAMAGE);
}

bool CastHotSpellAction::isUseful()
{
	return CastHotSpellAction::isUseful() && !ai->HasAura(spell, GetTarget(), BOT_AURA_HEAL);
}

bool CastEnchantItemAction::isUseful()
{
    if (!CastSpellAction::isUseful())
        return false;

    uint32 spellId = AI_VALUE2(uint32, "spell id", spell);
    return spellId && AI_VALUE2(Item*, "item for spell", spellId);
}

bool CastHealingSpellAction::isUseful()
{
	return CastAuraSpellAction::isUseful() && AI_VALUE2(uint8, "health", GetTargetName()) < (100 - estAmount);
}

bool CastAoeHealSpellAction::isUseful()
{
	return CastSpellAction::isUseful() && AI_VALUE2(uint8, "aoe heal", "medium") > 0;
}


Value<Unit*>* CurePartyMemberAction::GetTargetValue()
{
    return context->GetValue<Unit*>("party member to dispel", dispelType);
}

Value<Unit*>* DispelFrozenPartyMemberAction::GetTargetValue()
{
    return context->GetValue<Unit*>("party member dispel frozen");
}

Value<Unit*>* DispelRootPartyMemberAction::GetTargetValue()
{
    return context->GetValue<Unit*>("party member dispel root");
}

Value<Unit*>* DispelSnarePartyMemberAction::GetTargetValue()
{
    return context->GetValue<Unit*>("party member dispel snare");
}

Value<Unit*>* DispelCharmPartyMemberAction::GetTargetValue()
{
    return context->GetValue<Unit*>("party member dispel charm");
}

Value<Unit*>* DispelPossessPartyMemberAction::GetTargetValue()
{
    return context->GetValue<Unit*>("party member dispel possess");
}

Value<Unit*>* DispelPolymorphPartyMemberAction::GetTargetValue()
{
    return context->GetValue<Unit*>("party member dispel polymorph");
}

Value<Unit*>* DispelFearPartyMemberAction::GetTargetValue()
{
    return context->GetValue<Unit*>("party member dispel fear");
}

Value<Unit*>* BuffOnPartyAction::GetTargetValue()
{
    return context->GetValue<Unit*>("party member without aura", spell);
}
