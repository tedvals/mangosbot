#pragma once

std::vector<std::string> split(const std::string &s, char delim);
#ifndef WIN32
int strcmpi(std::string s1, std::string s2);
#endif
//#include "vld.h"
#include "../Spell.h"
#include "../../shared/Packets/WorldPacket.h"
#include "../Loot/LootMgr.h"
#include "../Entities/Creature/GossipDef.h"
#include "../Chat/Chat.h"
#include "../../shared/Common.h"
#include "../World/World.h"
#include "../Spells/SpellMgr.h"
#include "../Globals/ObjectMgr.h"
#include "../Entities/Unit/Unit.h"
#include "../Miscellaneous/SharedDefines.h"
#include "../Movement/MotionMaster.h"
#include "../Spells/Auras/SpellAuras.h"
#include "../Guilds/Guild.h"
#include "../Groups/Group.h"
#include "../../game/Accounts/AccountMgr.h"
#include "../../game/Globals/ObjectMgr.h"

#include "playerbotDefs.h"
#include "PlayerbotAIAware.h"
#include "PlayerbotMgr.h"
#include "RandomPlayerbotMgr.h"
#include "ChatHelper.h"
#include "PlayerbotAI.h"

//#define _CRTDBG_MAP_ALLOC
//#include <stdlib.h>
//#include <crtdbg.h>

//#ifdef _DEBUG
//#ifndef DBG_NEW
//#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
//#define new DBG_NEW
//#endif
//#endif  // _DEBUG
