#include "../pchdef.h"
#include "playerbot.h"
#include "PlayerbotAIConfig.h"
#include "PlayerbotFactory.h"
#include "../../shared/Database/DatabaseEnv.h"
#include "PlayerbotAI.h"
#include "AiFactory.h"
#include "../../game/Maps/MapManager.h"
#include "PlayerbotCommandServer.h"
#include "GuildTaskMgr.h"
#include <thread>

RandomPlayerbotMgr::RandomPlayerbotMgr() : PlayerbotHolder(), processTicks(0)
{
    sPlayerbotCommandServer.Start();
}

RandomPlayerbotMgr::~RandomPlayerbotMgr()
{
}

void RandomPlayerbotMgr::UpdateAIInternal(uint32 elapsed)
{
    SetNextCheckDelay(sPlayerbotAIConfig.randomBotUpdateInterval * 1000);

    if (!sPlayerbotAIConfig.randomBotAutologin || !sPlayerbotAIConfig.enabled)
        return;

    sLog->outMessage("playerbot", LOG_LEVEL_INFO, "Processing random bots...");

    int maxAllowedBotCount = GetEventValue(0, "bot_count");
    if (!maxAllowedBotCount)
    {
        maxAllowedBotCount = urand(sPlayerbotAIConfig.minRandomBots, sPlayerbotAIConfig.maxRandomBots);
        SetEventValue(0, "bot_count", maxAllowedBotCount,
                urand(sPlayerbotAIConfig.randomBotCountChangeMinInterval, sPlayerbotAIConfig.randomBotCountChangeMaxInterval));
    }

    list<uint32> bots = GetBots();
    int botCount = bots.size();
    int allianceNewBots = 0, hordeNewBots = 0;
    int randomBotsPerInterval = (int)urand(sPlayerbotAIConfig.minRandomBotsPerInterval, sPlayerbotAIConfig.maxRandomBotsPerInterval);
    if (!processTicks)
    {
        if (sPlayerbotAIConfig.randomBotLoginAtStartup)
            randomBotsPerInterval = bots.size();
    }

    while (botCount++ < maxAllowedBotCount)
    {
        bool alliance = botCount % 2;
        uint32 bot = AddRandomBot(alliance);
        if (bot)
        {
            if (alliance)
                allianceNewBots++;
            else
                hordeNewBots++;

            bots.push_back(bot);
        }
        else
            break;
    }

    int botProcessed = 0;
    for (list<uint32>::iterator i = bots.begin(); i != bots.end(); ++i)
    {
        uint32 bot = *i;
        if (ProcessBot(bot))
            botProcessed++;

        if (botProcessed >= randomBotsPerInterval)
            break;
    }

    sLog->outMessage("playerbot", LOG_LEVEL_INFO, "%d bots processed. %d alliance and %d horde bots added. %d bots online. Next check in %d seconds",
            botProcessed, allianceNewBots, hordeNewBots, playerBots.size(), sPlayerbotAIConfig.randomBotUpdateInterval);

    if (processTicks++ == 1)
        PrintStats();
}

uint32 RandomPlayerbotMgr::AddRandomBot(bool alliance)
{
    vector<uint32> bots = GetFreeBots(alliance);
    if (bots.size() == 0)
        return 0;

    int index = urand(0, bots.size() - 1);
    uint32 bot = bots[index];
    SetEventValue(bot, "add", 1, urand(sPlayerbotAIConfig.minRandomBotInWorldTime, sPlayerbotAIConfig.maxRandomBotInWorldTime));
    uint32 randomTime = 30 + urand(sPlayerbotAIConfig.randomBotUpdateInterval, sPlayerbotAIConfig.randomBotUpdateInterval * 3);
    ScheduleRandomize(bot, randomTime);
    sLog->outMessage("playerbot", LOG_LEVEL_DEBUG, "Random bot %d added", bot);
    return bot;
}

void RandomPlayerbotMgr::ScheduleRandomize(uint32 bot, uint32 time)
{
    SetEventValue(bot, "randomize", 1, time);
    SetEventValue(bot, "logout", 1, time + 30 + urand(sPlayerbotAIConfig.randomBotUpdateInterval, sPlayerbotAIConfig.randomBotUpdateInterval * 3));
}

void RandomPlayerbotMgr::ScheduleTeleport(uint32 bot)
{
    SetEventValue(bot, "teleport", 1, 60 + urand(sPlayerbotAIConfig.randomBotUpdateInterval, sPlayerbotAIConfig.randomBotUpdateInterval * 3));
}

bool RandomPlayerbotMgr::ProcessBot(uint32 bot)
{
    uint32 isValid = GetEventValue(bot, "add");
    if (!isValid)
    {
		Player* player = GetPlayerBot(bot);
		if (!player || !player->GetGroup())
		{
			sLog->outMessage("playerbot", LOG_LEVEL_INFO, "Bot %d expired", bot);
			SetEventValue(bot, "add", 0, 0);
		}
        return true;
    }

    if (!GetPlayerBot(bot))
    {
        sLog->outMessage("playerbot", LOG_LEVEL_INFO, "Bot %d logged in", bot);
        AddPlayerBot(bot, 0);
        if (!GetEventValue(bot, "online"))
        {
            SetEventValue(bot, "online", 1, sPlayerbotAIConfig.minRandomBotInWorldTime);
        }
        return true;
    }

    Player* player = GetPlayerBot(bot);
    if (!player)
        return false;

    PlayerbotAI* ai = player->GetPlayerbotAI();
    if (!ai)
        return false;

    if (player->GetGroup())
    {
        sLog->outMessage("playerbot", LOG_LEVEL_INFO, "Skipping bot %d as it is in group", bot);
        return false;
    }

    if (player->isDead())
    {
        if (!GetEventValue(bot, "dead"))
        {
            sLog->outMessage("playerbot", LOG_LEVEL_INFO, "Setting dead flag for bot %d", bot);
            uint32 randomTime = urand(sPlayerbotAIConfig.minRandomBotReviveTime, sPlayerbotAIConfig.maxRandomBotReviveTime);
            SetEventValue(bot, "dead", 1, randomTime);
            SetEventValue(bot, "revive", 1, randomTime - 60);
            return false;
        }

        if (!GetEventValue(bot, "revive"))
        {
            sLog->outMessage("playerbot", LOG_LEVEL_INFO, "Reviving dead bot %d", bot);
            SetEventValue(bot, "dead", 0, 0);
            SetEventValue(bot, "revive", 0, 0);
            std::thread random_tele(&RandomPlayerbotMgr::RandomTeleporting,this,player,player->GetMapId(), player->GetPositionX(), player->GetPositionY(), player->GetPositionZ());
            random_tele.detach();
            //RandomTeleport(player, player->GetMapId(), player->GetPositionX(), player->GetPositionY(), player->GetPositionZ());
            return true;
        }

        return false;
    }

    if (player->GetGuild() && player->GetGuild()->GetLeaderGUID() == player->GetGUID())
    {
        for (vector<Player*>::iterator i = players.begin(); i != players.end(); ++i)
            sGuildTaskMgr.Update(*i, player);
    }

    uint32 randomize = GetEventValue(bot, "randomize");
    if (!randomize)
    {
        sLog->outMessage("playerbot", LOG_LEVEL_INFO, "Randomizing bot %d", bot);
        //Randomize(player);
        std::thread randomize(&RandomPlayerbotMgr::Randomize,this,player);
        randomize.detach();
        uint32 randomTime = urand(sPlayerbotAIConfig.minRandomBotRandomizeTime, sPlayerbotAIConfig.maxRandomBotRandomizeTime);
        ScheduleRandomize(bot, randomTime);
        return true;
    }

    uint32 logout = GetEventValue(bot, "logout");
    if (!logout)
    {
        sLog->outMessage("playerbot", LOG_LEVEL_INFO, "Logging out bot %d", bot);
        LogoutPlayerBot(bot);
        SetEventValue(bot, "logout", 1, sPlayerbotAIConfig.maxRandomBotInWorldTime);
        return true;
    }

    uint32 teleport = GetEventValue(bot, "teleport");
    if (!teleport)
    {
        sLog->outMessage("playerbot", LOG_LEVEL_INFO, "Random teleporting bot %d", bot);
        //RandomTeleportForLevel(ai->GetBot());
        std::thread random_tele_level(&RandomPlayerbotMgr::RandomTeleportForLevel,this,ai->GetBot());
        random_tele_level.detach();
        SetEventValue(bot, "teleport", 1, sPlayerbotAIConfig.maxRandomBotInWorldTime);
        return true;
    }

    return false;
}

void RandomPlayerbotMgr::RandomTeleport(Player* bot, vector<WorldLocation> &locs)
{
    if (bot->IsBeingTeleported())
        return;

    if (locs.empty())
    {
        sLog->outMessage("playerbot", LOG_LEVEL_ERROR, "Cannot teleport bot %s - no locations available", bot->GetName().c_str());
        return;
    }

    for (int attemtps = 0; attemtps < 10; ++attemtps)
    {
        int index = urand(0, locs.size() - 1);
        WorldLocation loc = locs[index];
        float x = loc.m_positionX + urand(0, sPlayerbotAIConfig.grindDistance) - sPlayerbotAIConfig.grindDistance / 2;
        float y = loc.m_positionY + urand(0, sPlayerbotAIConfig.grindDistance) - sPlayerbotAIConfig.grindDistance / 2;
        float z = loc.m_positionZ;

        Map* map = sMapMgr->FindMap(loc.GetMapId(), 0);
        if (!map)
            continue;

        if (!map->IsOutdoors(x, y, z) ||
                map->IsInWater(x, y, z))
            continue;

        if (map->Instanceable()||map->IsBattlegroundOrArena()||map->IsDungeon()||map->IsRaidOrHeroicDungeon())
            continue;

        uint32 areaId = map->GetAreaId(x, y, z);

        if (!areaId)
            continue;

        AreaTableEntry const* area = sAreaStore.LookupEntry(areaId);
        if (!area)
            continue;

    //Some exceptions:
        if (IsAlliance(bot->getRace()))
        {
            switch (areaId)
            {
                case 14:
		case 85:
		case 153:
		case 154:
		case 155:
		case 156:
		case 157:
		case 158:
		case 159:
		case 160:
		case 161:
		case 162:
		case 163:
		case 164:
		case 165:
		case 166:
		case 167:
		case 168:
		case 169:
		case 170:
		case 173:
		case 215:
		case 219:
		case 220:
		case 221:
		case 222:
		case 223:
		case 224:
		case 225:
		case 226:
		case 227:
		case 228:
		case 231:
		case 232:
		case 233:
		case 236:
		case 237:
		case 238:
		case 239:
		case 240:
		case 272:
		case 231:
		case 362:
		case 363:
		case 364:
		case 365:
		case 366:
		case 367:
		case 368:
		case 369:
		case 370:
		case 371:
		case 372:
		case 373:
		case 374:
		case 375:
		case 377:
		case 378:
		case 379:
		case 380:
		case 396:
		case 397:
		case 398:
		case 407:
		case 460:
		case 470:
		case 471:
		case 472:
		case 473:
		case 474:
		case 475:
		case 476:
		case 637:
		case 638:
		case 639:
		case 696:
		case 697:
		case 698:
		case 699:
		case 700:
		case 701:
		case 702:
		case 810:
		case 811:
		case 812:
		case 813:
		case 814:
		case 815:
		case 816:
		case 817:
		case 818:
		case 819:
		case 820:
		case 821:
		case 1099:
		case 1497:
		case 1637:
		case 1617:
		case 1638:
		case 1639:
		case 1640:
		case 1641:
		case 2118:
		case 2119:
		case 2197:
		case 2237:
		case 3460:
		case 3461:
		case 3462:
		case 3463:
		case 3464:
		case 3465:
		case 3466:
		case 3467:
		case 3468:
		case 3469:
		case 3470:
		case 3471:
		case 3472:
		case 3473:
		case 3474:
		case 3475:
		case 3476:
		case 3479:
		case 3480:
		case 3481:
		case 3482:
		case 3483:
		case 3484:
		case 3485:
		case 3486:
		case 3487:
		case 3488:
		case 3489:
		case 3531:
		case 3532:
		case 3533:
		case 3434:
		case 3436:
		case 3489:
                continue;
                }
        }
        else //horde
        {
            switch (areaId)
            {
                case 1:
		case 2:
		case 9:
		case 12:
		case 20:
		case 23:
		case 24:
		case 34:
		case 38:
		case 40:
		case 57:
		case 59:
		case 60:
		case 62:
		case 63:
		case 64:
		case 68:
		case 69:
		case 77:
		case 80:
		case 86:
		case 87:
		case 88:
		case 99:
		case 107:
		case 108:
		case 109:
		case 111:
		case 113:
		case 115:
		case 120:
		case 131:
		case 132:
		case 133:
		case 134:
		case 135:
		case 136:
		case 137:
		case 138:
		case 140:
		case 142:
		case 144:
		case 150:
		case 186:
		case 187:
		case 188:
		case 189:
		case 192:
		case 271:
		case 298:
		case 299:
		case 320:
		case 415:
		case 442:
		case 608:
		case 800:
		case 801:
		case 802:
		case 803:
		case 804:
		case 805:
		case 806:
		case 807:
		case 808:
		case 809:
		case 1657:
		case 1658:
		case 1659:
		case 1660:
		case 1661:
		case 1662:
		case 2101:
		case 2102:
		case 2103:
		case 2104:
		case 2257:
		case 3524:
		case 3525:
		case 3526:
		case 3527:
		case 3528:
		case 3529:
		case 3530:
		case 3531:
		case 3532:
		case 3524:
		case 3538:
		case 3557:
		case 3558:
		case 3559:
		case 3560:
		case 3564:
		case 3567:
		case 3568:
		case 3569:
		case 3570:
		case 3571:
		case 3572:
		case 3573:	
		case 3574:
		case 3575:
		case 3576:
		case 3577:
		case 3578:	
		case 3579:
                continue;
                }
        }

        float ground = map->GetHeight(x, y, z + 0.5f);
        if (ground <= INVALID_HEIGHT)
            continue;

        z = 0.05f + ground;
        sLog->outMessage("playerbot", LOG_LEVEL_INFO, "Random teleporting bot %s to %s %f,%f,%f", bot->GetName().c_str(), area->area_name[0], x, y, z);

        bot->GetMotionMaster()->Clear();
        bot->TeleportTo(loc.GetMapId(), x, y, z, 0);
        return;
    }

    sLog->outMessage("playerbot", LOG_LEVEL_ERROR, "Cannot teleport bot %s - no locations available", bot->GetName().c_str());
}

void RandomPlayerbotMgr::RandomTeleportForLevel(Player* bot)
{
    vector<WorldLocation> locs;
    sLog->outMessage("playerbot", LOG_LEVEL_INFO, "Finding a place for %s...", bot->GetName().c_str());
    QueryResult results = WorldDatabase.PQuery("select map, position_x, position_y, position_z "
        "from (select map, position_x, position_y, position_z, avg(t.maxlevel), avg(t.minlevel), "
        "%u - (avg(t.maxlevel) + avg(t.minlevel)) / 2 delta "
        "from creature c inner join creature_template t on c.id = t.entry group by t.entry) q "
        "where delta >= 0 and delta <= %u and map in (%s) and not exists ( "
        "select map, position_x, position_y, position_z from "
        "("
        "select map, c.position_x, c.position_y, c.position_z, avg(t.maxlevel), avg(t.minlevel), "
        "%u - (avg(t.maxlevel) + avg(t.minlevel)) / 2 delta "
        "from creature c "
        "inner join creature_template t on c.id = t.entry group by t.entry "
        ") q1 "
        "where delta > %u and q1.map = q.map "
        "and sqrt("
        "(q1.position_x - q.position_x)*(q1.position_x - q.position_x) +"
        "(q1.position_y - q.position_y)*(q1.position_y - q.position_y) +"
        "(q1.position_z - q.position_z)*(q1.position_z - q.position_z)"
        ") < %u)",
        bot->getLevel(),
        sPlayerbotAIConfig.randomBotTeleLevel,
        sPlayerbotAIConfig.randomBotMapsAsString.c_str(),
        bot->getLevel(),
        sPlayerbotAIConfig.randomBotTeleLevel,
        sPlayerbotAIConfig.sightDistance
        );
    if (results)
    {
        do
        {
            Field* fields = results->Fetch();
            uint16 mapId = fields[0].GetUInt16();
            float x = fields[1].GetFloat();
            float y = fields[2].GetFloat();
            float z = fields[3].GetFloat();
            WorldLocation loc(mapId, x, y, z, 0);
            locs.push_back(loc);
        } while (results->NextRow());
    }
    sLog->outMessage("playerbot", LOG_LEVEL_INFO, "Found...");
    RandomTeleport(bot, locs);
}

void RandomPlayerbotMgr::RandomTeleporting(Player* bot, uint16 mapId, float teleX, float teleY, float teleZ)
{
    vector<WorldLocation> locs;
    QueryResult results = WorldDatabase.PQuery("select position_x, position_y, position_z from creature where map = '%u' and abs(position_x - '%f') < '%u' and abs(position_y - '%f') < '%u'",
            mapId, teleX, sPlayerbotAIConfig.randomBotTeleportDistance / 2, teleY, sPlayerbotAIConfig.randomBotTeleportDistance / 2);
    if (results)
    {
        do
        {
            Field* fields = results->Fetch();
            float x = fields[0].GetFloat();
            float y = fields[1].GetFloat();
            float z = fields[2].GetFloat();
            WorldLocation loc(mapId, x, y, z, 0);
            locs.push_back(loc);
        } while (results->NextRow());
    }

    RandomTeleport(bot, locs);
    Refresh(bot);
}

void RandomPlayerbotMgr::Randomize(Player* bot)
{
    if (bot->getLevel() == 1)
        RandomizeFirst(bot);
    else
        IncreaseLevel(bot);
}

void RandomPlayerbotMgr::IncreaseLevel(Player* bot)
{
    uint32 maxLevel = sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL);
    uint32 level = min((uint32)(bot->getLevel() + 1), maxLevel);
    PlayerbotFactory factory(bot, level);
    if (bot->GetGuildId())
        factory.Refresh();
    else
        factory.Randomize();
    RandomTeleportForLevel(bot);
}

void RandomPlayerbotMgr::RandomizeFirst(Player* bot)
{
    uint32 maxLevel = sPlayerbotAIConfig.randomBotMaxLevel;
    if (maxLevel > sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL))
        maxLevel = sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL);

    for (int attempt = 0; attempt < 100; ++attempt)
    {
        int index = urand(0, sPlayerbotAIConfig.randomBotMaps.size() - 1);
        uint16 mapId = sPlayerbotAIConfig.randomBotMaps[index];

        vector<GameTele const*> locs;
        GameTeleContainer const & teleMap = sObjectMgr->GetGameTeleMap();
        for(GameTeleContainer::const_iterator itr = teleMap.begin(); itr != teleMap.end(); ++itr)
        {
            GameTele const* tele = &itr->second;
            if (tele->mapId == mapId)
                locs.push_back(tele);
        }

        index = urand(0, locs.size() - 1);
        GameTele const* tele = locs[index];
        uint32 level = GetZoneLevel(tele->mapId, tele->position_x, tele->position_y, tele->position_z);
        if (level > maxLevel + 5)
            continue;

        level = min(level, maxLevel);
        if (!level) level = 1;

        if (urand(0, 100) < 100 * sPlayerbotAIConfig.randomBotMaxLevelChance)
            level = maxLevel;

        if (level < sPlayerbotAIConfig.randomBotMinLevel)
            continue;

        PlayerbotFactory factory(bot, level);
        factory.CleanRandomize();
        RandomTeleporting(bot, tele->mapId, tele->position_x, tele->position_y, tele->position_z);
        break;
    }
}

uint32 RandomPlayerbotMgr::GetZoneLevel(uint16 mapId, float teleX, float teleY, float teleZ)
{
    uint32 maxLevel = sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL);

	uint32 level;
    QueryResult results = WorldDatabase.PQuery("select avg(t.minlevel) minlevel, avg(t.maxlevel) maxlevel from creature c "
            "inner join creature_template t on c.id = t.entry "
            "where map = '%u' and minlevel > 1 and abs(position_x - '%f') < '%u' and abs(position_y - '%f') < '%u'",
            mapId, teleX, sPlayerbotAIConfig.randomBotTeleportDistance / 2, teleY, sPlayerbotAIConfig.randomBotTeleportDistance / 2);

    if (results)
    {
        Field* fields = results->Fetch();
        uint8 minLevel = fields[0].GetUInt8();
        uint8 maxLevel = fields[1].GetUInt8();
        level = urand(minLevel, maxLevel);
        if (level > maxLevel)
            level = maxLevel;
    }
    else
    {
        level = urand(1, maxLevel);
    }

    return level;
}

void RandomPlayerbotMgr::Refresh(Player* bot)
{
    if (bot->isDead())
    {
        bot->ResurrectPlayer(1.0f);
        bot->SpawnCorpseBones();
        bot->SaveToDB();
        bot->GetPlayerbotAI()->ResetStrategies();
    }

    bot->GetPlayerbotAI()->Reset();

    HostileReference *ref = bot->getHostileRefManager().getFirst();
    while( ref )
    {
        ThreatManager *threatManager = ref->GetSource();
        Unit *unit = threatManager->GetOwner();
        float threat = ref->getThreat();

        unit->RemoveAllAttackers();
        unit->ClearInCombat();

        ref = ref->next();
    }

    bot->RemoveAllAttackers();
    bot->ClearInCombat();

    bot->DurabilityRepairAll(false, 1.0f, false);
    bot->SetFullHealth();
    bot->SetPvP(true);

    if (bot->GetMaxPower(POWER_MANA) > 0)
        bot->SetPower(POWER_MANA, bot->GetMaxPower(POWER_MANA));

    if (bot->GetMaxPower(POWER_ENERGY) > 0)
        bot->SetPower(POWER_ENERGY, bot->GetMaxPower(POWER_ENERGY));
}


bool RandomPlayerbotMgr::IsRandomBot(Player* bot)
{
    return IsRandomBot(bot->GetGUID());
}

bool RandomPlayerbotMgr::IsRandomBot(uint32 bot)
{
    return GetEventValue(bot, "add");
}

list<uint32> RandomPlayerbotMgr::GetBots()
{
    list<uint32> bots;

    QueryResult results = CharacterDatabase.Query(
            "select bot from ai_playerbot_random_bots where owner = 0 and event = 'add'");

    if (results)
    {
        do
        {
            Field* fields = results->Fetch();
            uint32 bot = fields[0].GetUInt32();
            bots.push_back(bot);
        } while (results->NextRow());
    }

    return bots;
}

vector<uint32> RandomPlayerbotMgr::GetFreeBots(bool alliance)
{
    set<uint32> bots;

    QueryResult results = CharacterDatabase.PQuery(
            "select `bot` from ai_playerbot_random_bots where event = 'add'");

    if (results)
    {
        do
        {
            Field* fields = results->Fetch();
            uint32 bot = fields[0].GetUInt32();
            bots.insert(bot);
        } while (results->NextRow());
    }

    vector<uint32> guids;
    for (list<uint32>::iterator i = sPlayerbotAIConfig.randomBotAccounts.begin(); i != sPlayerbotAIConfig.randomBotAccounts.end(); i++)
    {
        uint32 accountId = *i;
        if (!sAccountMgr->GetCharactersCount(accountId))
            continue;

        QueryResult result = CharacterDatabase.PQuery("SELECT guid, race FROM characters WHERE account = '%u'", accountId);
        if (!result)
            continue;

        do
        {
            Field* fields = result->Fetch();
            uint32 guid = fields[0].GetUInt32();
            uint8 race = fields[1].GetUInt8();
            if (bots.find(guid) == bots.end() &&
                    ((alliance && IsAlliance(race)) || ((!alliance && !IsAlliance(race))
            )))
                guids.push_back(guid);
        } while (result->NextRow());
    }


    return guids;
}

uint32 RandomPlayerbotMgr::GetEventValue(uint32 bot, string event)
{
    uint32 value = 0;

    QueryResult results = CharacterDatabase.PQuery(
            "select `value`, `time`, validIn from ai_playerbot_random_bots where owner = 0 and bot = '%u' and event = '%s'",
            bot, event.c_str());

    if (results)
    {
        Field* fields = results->Fetch();
        value = fields[0].GetUInt32();
        uint32 lastChangeTime = fields[1].GetUInt32();
        uint32 validIn = fields[2].GetUInt32();
        if ((time(0) - lastChangeTime) >= validIn)
            value = 0;
    }

    return value;
}

uint32 RandomPlayerbotMgr::SetEventValue(uint32 bot, string event, uint32 value, uint32 validIn)
{
    CharacterDatabase.PExecute("delete from ai_playerbot_random_bots where owner = 0 and bot = '%u' and event = '%s'",
            bot, event.c_str());
    if (value)
    {
        CharacterDatabase.PExecute(
                "insert into ai_playerbot_random_bots (owner, bot, `time`, validIn, event, `value`) values ('%u', '%u', '%u', '%u', '%s', '%u')",
                0, bot, (uint32)time(0), validIn, event.c_str(), value);
    }

    return value;
}

bool RandomPlayerbotMgr::HandlePlayerbotConsoleCommand(ChatHandler* handler, char const* args)
{
    if (!sPlayerbotAIConfig.enabled)
    {
        sLog->outMessage("playerbot", LOG_LEVEL_ERROR, "Playerbot system is currently disabled!");
        return false;
    }

    if (!args || !*args)
    {
        sLog->outMessage("playerbot", LOG_LEVEL_ERROR, "Usage: rndbot stats/update/reset/init/refresh/add/remove");
        return false;
    }

    string cmd = args;

    if (cmd == "reset")
    {
        CharacterDatabase.PExecute("delete from ai_playerbot_random_bots");
        sLog->outMessage("playerbot", LOG_LEVEL_INFO, "Random bots were reset for all players");
        return true;
    }
    else if (cmd == "stats")
    {
        sRandomPlayerbotMgr.PrintStats();
        return true;
    }
    else if (cmd == "update")
    {
        sRandomPlayerbotMgr.UpdateAIInternal(0);
        return true;
    }
    else if (cmd == "init" || cmd == "refresh" || cmd == "teleport")
    {
		sLog->outMessage("playerbot", LOG_LEVEL_INFO, "Randomizing bots for %d accounts", sPlayerbotAIConfig.randomBotAccounts.size());
        for (list<uint32>::iterator i = sPlayerbotAIConfig.randomBotAccounts.begin(); i != sPlayerbotAIConfig.randomBotAccounts.end(); ++i)
        {
            uint32 account = *i;
            if (QueryResult results = CharacterDatabase.PQuery("SELECT guid FROM characters where account = '%u'", account))
            {
                do
                {
                    Field* fields = results->Fetch();
                    ObjectGuid guid = ObjectGuid(HIGHGUID_PLAYER, fields[0].GetUInt32());
                    Player* bot = sObjectMgr->GetPlayerByLowGUID(guid);
                    if (!bot)
                        continue;

                    if (cmd == "init")
                    {
                        sLog->outMessage("playerbot", LOG_LEVEL_INFO, "Randomizing bot %s for account %u", bot->GetName().c_str(), account);
                        sRandomPlayerbotMgr.RandomizeFirst(bot);
                    }
                    else if (cmd == "teleport")
                    {
                        sLog->outMessage("playerbot", LOG_LEVEL_INFO, "Random teleporting bot %s for account %u", bot->GetName().c_str(), account);
                        sRandomPlayerbotMgr.RandomTeleportForLevel(bot);
                    }
                    else
                    {
                        sLog->outMessage("playerbot", LOG_LEVEL_INFO, "Refreshing bot %s for account %u", bot->GetName().c_str(), account);
                        bot->SetLevel(bot->getLevel() - 1);
                        sRandomPlayerbotMgr.IncreaseLevel(bot);
                    }
                    uint32 randomTime = urand(sPlayerbotAIConfig.minRandomBotRandomizeTime, sPlayerbotAIConfig.maxRandomBotRandomizeTime);
                    CharacterDatabase.PExecute("update ai_playerbot_random_bots set validIn = '%u' where event = 'randomize' and bot = '%u'",
                            randomTime, bot->GetGUIDLow());
                    CharacterDatabase.PExecute("update ai_playerbot_random_bots set validIn = '%u' where event = 'logout' and bot = '%u'",
                            sPlayerbotAIConfig.maxRandomBotInWorldTime, bot->GetGUIDLow());
                } while (results->NextRow());
            }
        }
        return true;
    }
    else
    {
        list<string> messages = sRandomPlayerbotMgr.HandlePlayerbotCommand(args, NULL);
        for (list<string>::iterator i = messages.begin(); i != messages.end(); ++i)
        {
            sLog->outMessage("playerbot", LOG_LEVEL_INFO, i->c_str());
        }
        return true;
    }

    return false;
}

void RandomPlayerbotMgr::HandleCommand(uint32 type, const string& text, Player& fromPlayer)
{
    for (PlayerBotMap::const_iterator it = GetPlayerBotsBegin(); it != GetPlayerBotsEnd(); ++it)
    {
        Player* const bot = it->second;
        bot->GetPlayerbotAI()->HandleCommand(type, text, fromPlayer);
    }
}

void RandomPlayerbotMgr::OnPlayerLogout(Player* player)
{
    for (PlayerBotMap::const_iterator it = GetPlayerBotsBegin(); it != GetPlayerBotsEnd(); ++it)
    {
        Player* const bot = it->second;
        PlayerbotAI* ai = bot->GetPlayerbotAI();
        if (player == ai->GetMaster())
        {
            ai->SetMaster(NULL);
            ai->ResetStrategies();
        }
    }

    if (!player->GetPlayerbotAI())
    {
        vector<Player*>::iterator i = find(players.begin(), players.end(), player);
        if (i != players.end())
            players.erase(i);
    }
}

void RandomPlayerbotMgr::OnPlayerLogin(Player* player)
{
    for (PlayerBotMap::const_iterator it = GetPlayerBotsBegin(); it != GetPlayerBotsEnd(); ++it)
    {
        Player* const bot = it->second;
        if (player == bot || player->GetPlayerbotAI())
            continue;

        Group* group = bot->GetGroup();
        if (!group)
            continue;

        for (GroupReference *gref = group->GetFirstMember(); gref; gref = gref->next())
        {
            Player* member = gref->GetSource();
            PlayerbotAI* ai = bot->GetPlayerbotAI();
            if (member == player && (!ai->GetMaster() || ai->GetMaster()->GetPlayerbotAI()))
            {
                ai->SetMaster(player);
                ai->ResetStrategies();
                ai->TellMaster("Hello");
                break;
            }
        }
    }

    if (player->GetPlayerbotAI())
        return;

    players.push_back(player);
}

Player* RandomPlayerbotMgr::GetRandomPlayer()
{
    if (players.empty())
        return NULL;

    uint32 index = urand(0, players.size() - 1);
    return players[index];
}

void RandomPlayerbotMgr::PrintStats()
{
    sLog->outMessage("playerbot", LOG_LEVEL_INFO, "%d Random Bots online", playerBots.size());

    map<uint32, int> alliance, horde;
    for (uint32 i = 0; i < 10; ++i)
    {
        alliance[i] = 0;
        horde[i] = 0;
    }

    map<uint8, int> perRace, perClass;
    for (uint8 race = RACE_HUMAN; race < MAX_RACES; ++race)
    {
        perRace[race] = 0;
    }
    for (uint8 cls = CLASS_WARRIOR; cls < MAX_CLASSES; ++cls)
    {
        perClass[cls] = 0;
    }

    int dps = 0, heal = 0, tank = 0;
    for (PlayerBotMap::iterator i = playerBots.begin(); i != playerBots.end(); ++i)
    {
        Player* bot = i->second;
        if (IsAlliance(bot->getRace()))
            alliance[bot->getLevel() / 10]++;
        else
            horde[bot->getLevel() / 10]++;

        perRace[bot->getRace()]++;
        perClass[bot->getClass()]++;

        int spec = AiFactory::GetPlayerSpecTab(bot);
        switch (bot->getClass())
        {
        case CLASS_DRUID:
            if (spec == 2)
                heal++;
            else
                dps++;
            break;
        case CLASS_PALADIN:
            if (spec == 1)
                tank++;
            else if (spec == 0)
                heal++;
            else
                dps++;
            break;
        case CLASS_PRIEST:
            if (spec != 2)
                heal++;
            else
                dps++;
            break;
        case CLASS_SHAMAN:
            if (spec == 2)
                heal++;
            else
                dps++;
            break;
        case CLASS_WARRIOR:
            if (spec == 2)
                tank++;
            else
                dps++;
            break;
        default:
            dps++;
            break;
        }
    }

    sLog->outMessage("playerbot", LOG_LEVEL_INFO, "Per level:");
    uint32 maxLevel = sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL);
    for (uint32 i = 0; i < 10; ++i)
    {
        if (!alliance[i] && !horde[i])
            continue;

        uint32 from = i*10;
        uint32 to = min(from + 9, maxLevel);
        if (!from) from = 1;
        sLog->outMessage("playerbot", LOG_LEVEL_INFO, "    %d..%d: %d alliance, %d horde", from, to, alliance[i], horde[i]);
    }
    sLog->outMessage("playerbot", LOG_LEVEL_INFO, "Per race:");
    for (uint8 race = RACE_HUMAN; race < MAX_RACES; ++race)
    {
        if (perRace[race])
            sLog->outMessage("playerbot", LOG_LEVEL_INFO, "    %s: %d", ChatHelper::formatRace(race).c_str(), perRace[race]);
    }
    sLog->outMessage("playerbot", LOG_LEVEL_INFO, "Per class:");
    for (uint8 cls = CLASS_WARRIOR; cls < MAX_CLASSES; ++cls)
    {
        if (perClass[cls])
            sLog->outMessage("playerbot", LOG_LEVEL_INFO, "    %s: %d", ChatHelper::formatClass(cls).c_str(), perClass[cls]);
    }
    sLog->outMessage("playerbot", LOG_LEVEL_INFO, "Per role:");
    sLog->outMessage("playerbot", LOG_LEVEL_INFO, "    tank: %d", tank);
    sLog->outMessage("playerbot", LOG_LEVEL_INFO, "    heal: %d", heal);
    sLog->outMessage("playerbot", LOG_LEVEL_INFO, "    dps: %d", dps);
}

double RandomPlayerbotMgr::GetBuyMultiplier(Player* bot)
{
    uint32 id = bot->GetGUID();
    uint32 value = GetEventValue(id, "buymultiplier");
    if (!value)
    {
        value = urand(1, 120);
        uint32 validIn = urand(sPlayerbotAIConfig.minRandomBotsPriceChangeInterval, sPlayerbotAIConfig.maxRandomBotsPriceChangeInterval);
        SetEventValue(id, "buymultiplier", value, validIn);
    }

    return (double)value / 100.0;
}

double RandomPlayerbotMgr::GetSellMultiplier(Player* bot)
{
    uint32 id = bot->GetGUID();
    uint32 value = GetEventValue(id, "sellmultiplier");
    if (!value)
    {
        value = urand(80, 250);
        uint32 validIn = urand(sPlayerbotAIConfig.minRandomBotsPriceChangeInterval, sPlayerbotAIConfig.maxRandomBotsPriceChangeInterval);
        SetEventValue(id, "sellmultiplier", value, validIn);
    }

    return (double)value / 100.0;
}

uint32 RandomPlayerbotMgr::GetLootAmount(Player* bot)
{
    uint32 id = bot->GetGUID();
    return GetEventValue(id, "lootamount");
}

void RandomPlayerbotMgr::SetLootAmount(Player* bot, uint32 value)
{
    uint32 id = bot->GetGUID();
    SetEventValue(id, "lootamount", value, 24 * 3600);
}

uint32 RandomPlayerbotMgr::GetTradeDiscount(Player* bot)
{
    Group* group = bot->GetGroup();
    return GetLootAmount(bot) / (group ? group->GetMembersCount() : 10);
}

string RandomPlayerbotMgr::HandleRemoteCommand(string request)
{
    string::iterator pos = find(request.begin(), request.end(), ',');
    if (pos == request.end())
    {
        ostringstream out; out << "invalid request: " << request;
        return out.str();
    }

    string command = string(request.begin(), pos);
    uint64 guid = atoi(string(pos + 1, request.end()).c_str());
    Player* bot = GetPlayerBot(guid);
    if (!bot)
        return "invalid guid";

    PlayerbotAI *ai = bot->GetPlayerbotAI();
    if (!ai)
        return "invalid guid";

    return ai->HandleRemoteCommand(command);
}
