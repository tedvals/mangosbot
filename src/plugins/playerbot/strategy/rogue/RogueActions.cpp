#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "RogueActions.h"
#include "RogueOpeningActions.h"
#include "RogueFinishingActions.h"
#include "RogueComboActions.h"

using namespace ai;


NextAction** CastSapCcAction :: getAlternatives()
{
            return NextAction::merge( NextAction::array(0, new NextAction("garrote"), NULL), CastMeleeSpellAction::getAlternatives());
}

NextAction** CastAdrenalineRushAction :: getAlternatives()
{
            return NextAction::merge( NextAction::array(0, new NextAction("blade flurry"), NULL), CastBuffSpellAction::getAlternatives());
}

NextAction** CastBurstAction :: getAlternatives()
{
            return NextAction::merge( NextAction::array(0, new NextAction("shadow dance"), NULL), CastBuffSpellAction::getAlternatives());
}

NextAction** CastShadowDanceAction :: getAlternatives()
{
            return NextAction::merge( NextAction::array(0, new NextAction("cold blood"), NULL), CastBuffSpellAction::getAlternatives());
}


