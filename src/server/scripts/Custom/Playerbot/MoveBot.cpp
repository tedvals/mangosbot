#include "MapManager.h"
#include "Language.h"


// possible spells:
// 27651, 897

class MoveBot_spell_place : public SpellScriptLoader
{
public:
    MoveBot_spell_place() : SpellScriptLoader("MoveBot_spell_place") { }

    class MoveBot_spellscript : public SpellScript
    {
        PrepareSpellScript(MoveBot_spellscript);

        void HandleAfterCast()
        {
            if (!GetCaster())
                return;

            Player* player = GetCaster()->ToPlayer();

            if (!player)
                return;

            const WorldLocation* summonPos = GetExplTargetDest();

            if (summonPos)
                player->SetMovePoint(summonPos->GetMapId(),summonPos->GetPositionX(), summonPos->GetPositionY(), summonPos->GetPositionZ());
        }

        void Register() override
        {
            AfterCast += SpellCastFn(MoveBot_spellscript::HandleAfterCast);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new MoveBot_spellscript();
    }
};

void AddSC_MoveBot_commandscript()
{
    new MoveBot_spell_place();
}
