/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ScriptLoader.h"
#include "World.h"
#include "../../../src/plugins/playerbot/playerbot.h"

void AddSpellsScripts();
void AddSC_SmartScripts();
void AddCommandsScripts();

#ifdef SCRIPTS
void AddWorldScripts();
void AddEasternKingdomsScripts();
void AddKalimdorScripts();
void AddOutlandScripts();
void AddNorthrendScripts();
void AddEventsScripts();
void AddPetScripts();
void AddOutdoorPvPScripts();
void AddCustomScripts();
#endif

void AddScripts()
{
    AddSpellsScripts();
    AddSC_SmartScripts();
    AddCommandsScripts();
#ifdef SCRIPTS
    AddWorldScripts();
    AddEasternKingdomsScripts();
    AddKalimdorScripts();
    AddOutlandScripts();
    AddNorthrendScripts();
    AddEventsScripts();
    AddPetScripts();
    AddOutdoorPvPScripts();
    AddCustomScripts();
#endif
}

#ifdef SCRIPTS
/* This is where custom scripts' loading functions should be declared. */

void AddSC_PWS_Transmogrification();
void AddSC_CS_Transmogrification();
void AddSC_REFORGER_NPC();
void AddSC_GOMove_commandscript();
void AddSC_MoveBot_commandscript();
    // GuildHouse NPC
void    AddSC_guildmaster();
#endif

void AddCustomScripts()
{
#ifdef SCRIPTS
    /* This is where custom scripts should be added. */

    AddSC_PWS_Transmogrification();
    AddSC_CS_Transmogrification();
    AddSC_REFORGER_NPC();
    AddSC_GOMove_commandscript();
    AddSC_MoveBot_commandscript();
     // GuildHouse NPC
    AddSC_guildmaster();
#endif
}
