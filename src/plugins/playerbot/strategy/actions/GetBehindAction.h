#pragma once

#include "../Action.h"
#include "MovementActions.h"

namespace ai
{
	class GetBehindAction : public MovementAction {
	public:
		GetBehindAction(PlayerbotAI* ai) : MovementAction(ai, "get behind") {}
		virtual bool Execute(Event event);
        virtual bool isUseful();
	};
}
