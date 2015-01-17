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

      if (horde_areas.empty())
    {
        // insert line by line, so names can be added as comments
        horde_areas.push_back(14);
        horde_areas.push_back(85);
		horde_areas.push_back(153);
		horde_areas.push_back(154);
		horde_areas.push_back(155);
		horde_areas.push_back(156);
		horde_areas.push_back(157);
		horde_areas.push_back(158);
		horde_areas.push_back(159);
		horde_areas.push_back(160);
		horde_areas.push_back(161);
		horde_areas.push_back(162);
		horde_areas.push_back(163);
		horde_areas.push_back(164);
		horde_areas.push_back(165);
		horde_areas.push_back(166);
		horde_areas.push_back(167);
		horde_areas.push_back(168);
		horde_areas.push_back(169);
		horde_areas.push_back(170);
		horde_areas.push_back(173);
		horde_areas.push_back(215);
		horde_areas.push_back(219);
		horde_areas.push_back(220);
		horde_areas.push_back(221);
		horde_areas.push_back(222);
		horde_areas.push_back(223);
		horde_areas.push_back(224);
		horde_areas.push_back(225);
		horde_areas.push_back(226);
		horde_areas.push_back(227);
		horde_areas.push_back(228);
		horde_areas.push_back(231);
		horde_areas.push_back(232);
		horde_areas.push_back(233);
		horde_areas.push_back(236);
		horde_areas.push_back(237);
		horde_areas.push_back(238);
		horde_areas.push_back(239);
		horde_areas.push_back(240);
		horde_areas.push_back(272);
		horde_areas.push_back(231);
		horde_areas.push_back(362);
		horde_areas.push_back(363);
		horde_areas.push_back(364);
		horde_areas.push_back(365);
		horde_areas.push_back(366);
		horde_areas.push_back(367);
		horde_areas.push_back(368);
		horde_areas.push_back(369);
		horde_areas.push_back(370);
		horde_areas.push_back(371);
		horde_areas.push_back(372);
		horde_areas.push_back(373);
		horde_areas.push_back(374);
		horde_areas.push_back(375);
		horde_areas.push_back(377);
		horde_areas.push_back(378);
		horde_areas.push_back(379);
		horde_areas.push_back(380);
		horde_areas.push_back(396);
		horde_areas.push_back(397);
		horde_areas.push_back(398);
		horde_areas.push_back(407);
		horde_areas.push_back(460);
		horde_areas.push_back(470);
		horde_areas.push_back(471);
		horde_areas.push_back(472);
		horde_areas.push_back(473);
		horde_areas.push_back(474);
		horde_areas.push_back(475);
		horde_areas.push_back(476);
		horde_areas.push_back(637);
		horde_areas.push_back(638);
		horde_areas.push_back(639);
		horde_areas.push_back(696);
		horde_areas.push_back(697);
		horde_areas.push_back(698);
		horde_areas.push_back(699);
		horde_areas.push_back(700);
		horde_areas.push_back(701);
		horde_areas.push_back(702);
		horde_areas.push_back(810);
		horde_areas.push_back(811);
		horde_areas.push_back(812);
		horde_areas.push_back(813);
		horde_areas.push_back(814);
		horde_areas.push_back(815);
		horde_areas.push_back(816);
		horde_areas.push_back(817);
		horde_areas.push_back(818);
		horde_areas.push_back(819);
		horde_areas.push_back(820);
		horde_areas.push_back(821);
		horde_areas.push_back(1099);
		horde_areas.push_back(1497);
		horde_areas.push_back(1637);
		horde_areas.push_back(1617);
		horde_areas.push_back(1638);
		horde_areas.push_back(1639);
		horde_areas.push_back(1640);
		horde_areas.push_back(1641);
		horde_areas.push_back(2118);
		horde_areas.push_back(2119);
		horde_areas.push_back(2197);
		horde_areas.push_back(2237);
		horde_areas.push_back(3460);
		horde_areas.push_back(3461);
		horde_areas.push_back(3462);
		horde_areas.push_back(3463);
		horde_areas.push_back(3464);
		horde_areas.push_back(3465);
		horde_areas.push_back(3466);
		horde_areas.push_back(3467);
		horde_areas.push_back(3468);
		horde_areas.push_back(3469);
		horde_areas.push_back(3470);
		horde_areas.push_back(3471);
		horde_areas.push_back(3472);
		horde_areas.push_back(3473);
		horde_areas.push_back(3474);
		horde_areas.push_back(3475);
		horde_areas.push_back(3476);
		horde_areas.push_back(3479);
		horde_areas.push_back(3480);
		horde_areas.push_back(3481);
		horde_areas.push_back(3482);
		horde_areas.push_back(3483);
		horde_areas.push_back(3484);
		horde_areas.push_back(3485);
		horde_areas.push_back(3486);
		horde_areas.push_back(3487);
		horde_areas.push_back(3488);
		horde_areas.push_back(3489);
		horde_areas.push_back(3531);
		horde_areas.push_back(3532);
		horde_areas.push_back(3533);
		horde_areas.push_back(3434);
		horde_areas.push_back(3436);
		horde_areas.push_back(3489);
    }

    if (alliance_areas.empty())
    {
        alliance_areas.push_back(2);
		alliance_areas.push_back(9);
		alliance_areas.push_back(12);
		alliance_areas.push_back(20);
		alliance_areas.push_back(23);
		alliance_areas.push_back(24);
		alliance_areas.push_back(34);
		alliance_areas.push_back(38);
		alliance_areas.push_back(40);
		alliance_areas.push_back(57);
		alliance_areas.push_back(59);
		alliance_areas.push_back(60);
		alliance_areas.push_back(62);
		alliance_areas.push_back(63);
		alliance_areas.push_back(64);
		alliance_areas.push_back(68);
		alliance_areas.push_back(69);
		alliance_areas.push_back(77);
		alliance_areas.push_back(80);
		alliance_areas.push_back(86);
		alliance_areas.push_back(87);
		alliance_areas.push_back(88);
		alliance_areas.push_back(99);
		alliance_areas.push_back(107);
		alliance_areas.push_back(108);
		alliance_areas.push_back(109);
		alliance_areas.push_back(111);
		alliance_areas.push_back(113);
		alliance_areas.push_back(115);
		alliance_areas.push_back(120);
		alliance_areas.push_back(131);
		alliance_areas.push_back(132);
		alliance_areas.push_back(133);
		alliance_areas.push_back(134);
		alliance_areas.push_back(135);
		alliance_areas.push_back(136);
		alliance_areas.push_back(137);
		alliance_areas.push_back(138);
		alliance_areas.push_back(140);
		alliance_areas.push_back(142);
		alliance_areas.push_back(144);
		alliance_areas.push_back(150);
		alliance_areas.push_back(186);
		alliance_areas.push_back(187);
		alliance_areas.push_back(188);
		alliance_areas.push_back(189);
		alliance_areas.push_back(192);
		alliance_areas.push_back(271);
		alliance_areas.push_back(298);
		alliance_areas.push_back(299);
		alliance_areas.push_back(320);
		alliance_areas.push_back(415);
		alliance_areas.push_back(442);
		alliance_areas.push_back(608);
		alliance_areas.push_back(800);
		alliance_areas.push_back(801);
		alliance_areas.push_back(802);
		alliance_areas.push_back(803);
		alliance_areas.push_back(804);
		alliance_areas.push_back(805);
		alliance_areas.push_back(806);
		alliance_areas.push_back(807);
		alliance_areas.push_back(808);
		alliance_areas.push_back(809);
		alliance_areas.push_back(1657);
		alliance_areas.push_back(1658);
		alliance_areas.push_back(1659);
		alliance_areas.push_back(1660);
		alliance_areas.push_back(1661);
		alliance_areas.push_back(1662);
		alliance_areas.push_back(2101);
		alliance_areas.push_back(2102);
		alliance_areas.push_back(2103);
		alliance_areas.push_back(2104);
		alliance_areas.push_back(2257);
		alliance_areas.push_back(3524);
		alliance_areas.push_back(3525);
		alliance_areas.push_back(3526);
		alliance_areas.push_back(3527);
		alliance_areas.push_back(3528);
		alliance_areas.push_back(3529);
		alliance_areas.push_back(3530);
		alliance_areas.push_back(3531);
		alliance_areas.push_back(3532);
		alliance_areas.push_back(3524);
		alliance_areas.push_back(3538);
		alliance_areas.push_back(3557);
		alliance_areas.push_back(3558);
		alliance_areas.push_back(3559);
		alliance_areas.push_back(3560);
		alliance_areas.push_back(3564);
		alliance_areas.push_back(3567);
		alliance_areas.push_back(3568);
		alliance_areas.push_back(3569);
		alliance_areas.push_back(3570);
		alliance_areas.push_back(3571);
		alliance_areas.push_back(3572);
		alliance_areas.push_back(3573);
		alliance_areas.push_back(3574);
		alliance_areas.push_back(3575);
		alliance_areas.push_back(3576);
		alliance_areas.push_back(3577);
		alliance_areas.push_back(3578);
		alliance_areas.push_back(3579);
        }

    sLog->outMessage("playerbot", LOG_LEVEL_INFO, "Initializing areas...");
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

        if (map->IsBattlegroundOrArena()||map->IsDungeon()||map->IsRaidOrHeroicDungeon())
            continue;

        uint32 areaId = map->GetAreaId(x, y, z);

        if (!areaId)
            continue;

    //Some exceptions:
        if (IsAlliance(bot->getRace()))
        {
            list<uint>::iterator i = find(horde_areas.begin(), horde_areas.end(), areaId);

            if (i != horde_areas.end())
                continue;
        }
        else //horde
        {

           list<uint>::iterator i1 = find(alliance_areas.begin(), alliance_areas.end(), areaId);

            if (i1 != alliance_areas.end())
                continue;
        }

        AreaTableEntry const* area = sAreaStore.LookupEntry(areaId);
        if (!area)
            continue;

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
