#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "RogueTriggers.h"
#include "RogueActions.h"

using namespace ai;

    list<string> PoisonWeaponTrigger::spells;

    bool PoisonWeaponTrigger::IsActive()
    {
    if (spells.empty())
    {
        spells.push_back("instant poison");
        spells.push_back("deadly poison");
        spells.push_back("crippling poison");
        spells.push_back("mind-numbing poison");
        spells.push_back("wound poison");
    }

    for (list<string>::iterator i = spells.begin(); i != spells.end(); ++i)
    {
        uint32 spellId = AI_VALUE2(uint32, "spell id", spell);
        if (!spellId)
            continue;

        if (AI_VALUE2(Item*, "item for spell", spellId))
            return true;
    }

    return false;
}
