#include "../pchdef.h"
#include "playerbot.h"
#include "AiFactory.h"
#include "strategy/Engine.h"

#include "strategy/priest/PriestAiObjectContext.h"
#include "strategy/mage/MageAiObjectContext.h"
#include "strategy/warlock/WarlockAiObjectContext.h"
#include "strategy/warrior/WarriorAiObjectContext.h"
#include "strategy/shaman/ShamanAiObjectContext.h"
#include "strategy/paladin/PaladinAiObjectContext.h"
#include "strategy/druid/DruidAiObjectContext.h"
#include "strategy/hunter/HunterAiObjectContext.h"
#include "strategy/rogue/RogueAiObjectContext.h"
#include "strategy/deathknight/DeathKnightAiObjectContext.h"
#include "../Entities/Player/Player.h"
#include "PlayerbotAIConfig.h"
#include "RandomPlayerbotMgr.h"


AiObjectContext* AiFactory::createAiObjectContext(Player* player, PlayerbotAI* ai)
{
    switch (player->getClass())
    {
    case CLASS_PRIEST:
        return new PriestAiObjectContext(ai);
        break;
    case CLASS_MAGE:
        return new MageAiObjectContext(ai);
        break;
    case CLASS_WARLOCK:
        return new WarlockAiObjectContext(ai);
        break;
    case CLASS_WARRIOR:
        return new WarriorAiObjectContext(ai);
        break;
    case CLASS_SHAMAN:
        return new ShamanAiObjectContext(ai);
        break;
    case CLASS_PALADIN:
        return new PaladinAiObjectContext(ai);
        break;
    case CLASS_DRUID:
        return new DruidAiObjectContext(ai);
        break;
    case CLASS_HUNTER:
        return new HunterAiObjectContext(ai);
        break;
    case CLASS_ROGUE:
        return new RogueAiObjectContext(ai);
        break;
    case CLASS_DEATH_KNIGHT:
        return new DeathKnightAiObjectContext(ai);
        break;
    }
    return new AiObjectContext(ai);
}

int AiFactory::GetPlayerSpecTab(Player* player)
{
    int c0 = 0, c1 = 0, c2 = 0;
    PlayerTalentMap& talentMap = player->GetTalentMap(0);
    for (PlayerTalentMap::iterator i = talentMap.begin(); i != talentMap.end(); ++i)
    {
        uint32 spellId = i->first;
        TalentSpellPos const* talentPos = GetTalentSpellPos(spellId);
        if(!talentPos)
            continue;

        TalentEntry const* talentInfo = sTalentStore.LookupEntry(talentPos->talent_id);
        if (!talentInfo)
            continue;

        uint32 const* talentTabIds = GetTalentTabPages(player->getClass());
        if (talentInfo->TalentTab == talentTabIds[0]) c0++;
        if (talentInfo->TalentTab == talentTabIds[1]) c1++;
        if (talentInfo->TalentTab == talentTabIds[2]) c2++;
    }

    if (c0 >= c1 && c0 >= c2)
        return 0;

    if (c1 >= c0 && c1 >= c2)
        return 1;

    return 2;
}

void AiFactory::AddDefaultCombatStrategies(Player* player, PlayerbotAI* const facade, Engine* engine)
{
    int tab = GetPlayerSpecTab(player);

    engine->addStrategies("attack weak", "racials", "chat", "default", "aoe", "potions", "cast time", "conserve mana", "duel", "pvp", NULL);

    switch (player->getClass())
    {
        case CLASS_DEATH_KNIGHT:
            if ((rand() % 2))
            {
                if (tab == 0)
                    engine->addStrategies("blood dps", "aoe", "threat", "bdps", NULL);
                else if (tab == 1)
                    engine->addStrategies("frost dps", "aoe", "threat", "bdps", NULL);
                else
                    engine->addStrategies("unholy dps", "aoe", "threat", "bdps", NULL);
            }
            else
            {
                 engine->addStrategies("tank", "tank aoe", "bhealth", NULL);
            }
            break;
        case CLASS_PRIEST:
            if (tab == 2)
            {
                engine->addStrategies("dps", "threat", NULL);
                if (player->getLevel() > 19)
                    engine->addStrategy("dps debuff");
            }
            else if (tab == 1)
                engine->addStrategies("holy","holy dps",NULL);
            else
                engine->addStrategy("heal");

            engine->addStrategy("flee");
            break;
        case CLASS_MAGE:
            if (tab == 0)
                engine->addStrategies("arcane", "arcane aoe", "threat", "bmana", NULL);
            else if (tab == 1)
                engine->addStrategies("fire", "fire aoe", "threat", "bdps", NULL);
            else
                engine->addStrategies("frost", "frost aoe", "threat", "bdps", NULL);

            engine->addStrategy("flee");
            break;
        case CLASS_WARRIOR:
            if (tab == 2)
                engine->addStrategies("tank", "tank aoe", NULL);
            else if (tab == 1)
                engine->addStrategies("fury", "dps", "threat", NULL);
            else
                engine->addStrategies("arms", "dps", "threat", NULL);
            break;
        case CLASS_SHAMAN:
            if (tab == 0)
                engine->addStrategies("caster", "caster aoe", "bmana", "totems", "threat", "flee", NULL);
            else if (tab == 2)
                engine->addStrategies("heal", "bmana", "flee", "totems", NULL);
            else
                engine->addStrategies("dps", "melee aoe", "bdps", "threat", "totems", NULL);
            break;
        case CLASS_PALADIN:
            if (tab == 0)
                if (player->getLevel() > 59)
                    engine->addStrategies("heal", "bmana", "threat", "flee", NULL);
                else
                    engine->addStrategies("melee heal", "bmana", "threat", NULL);
            else if (tab == 1)
                engine->addStrategies("tank", "tank aoe", "barmor", NULL);
            else
                engine->addStrategies("dps", "bdps", "threat", NULL);
            break;
        case CLASS_DRUID:
            if (tab == 0)
            {
                engine->addStrategies("caster", "caster aoe", "threat", "flee", NULL);
                if (player->getLevel() > 19)
                    engine->addStrategy("caster debuff");
            }
            else if (tab == 2)
                engine->addStrategies("heal", "flee", NULL);
            else
                engine->addStrategies("bear", "tank aoe", "threat", "flee", NULL);
            break;
        case CLASS_HUNTER:
            engine->addStrategies("dps", "bdps", "threat", "flee", NULL);
            if (player->getLevel() > 19)
                engine->addStrategy("dps debuff");
            break;
        case CLASS_ROGUE:
            if (tab == 1)
                engine->addStrategies("dps", "sword", "threat", NULL);
            else
                engine->addStrategies("dps", "dagger", "threat", NULL);
            break;
        case CLASS_WARLOCK:
            if (tab == 0)
            {
                engine->addStrategies("dps", "threat", "dps debuff", NULL);
            }
            else if (tab == 1)
                engine->addStrategies("tank", "threat", "dps debuff", NULL);
            else
            {
                engine->addStrategies("fire", "threat", "debuff", NULL);
            }

            engine->addStrategy("flee");
            break;
    }

    if (sRandomPlayerbotMgr.IsRandomBot(player) && !player->GetGroup())
    {
        engine->ChangeStrategy(sPlayerbotAIConfig.randomBotCombatStrategies);
        if (player->getClass() == CLASS_DRUID && player->getLevel() < 20)
            engine->addStrategies("bear", "threat", NULL);
    }
}

Engine* AiFactory::createCombatEngine(Player* player, PlayerbotAI* const facade, AiObjectContext* AiObjectContext) {
	Engine* engine = new Engine(facade, AiObjectContext);
    AddDefaultCombatStrategies(player, facade, engine);
    return engine;
}

Engine* AiFactory::createMobileEngine(Player* player, PlayerbotAI* const facade, AiObjectContext* AiObjectContext) {
	Engine* engine = new Engine(facade, AiObjectContext);
    AddDefaultMobileStrategies(player, facade, engine);
    return engine;
}

void AiFactory::AddDefaultNonCombatStrategies(Player* player, PlayerbotAI* const facade, Engine* nonCombatEngine)
{
    int tab = GetPlayerSpecTab(player);

    switch (player->getClass()){
        case CLASS_DEATH_KNIGHT:
            nonCombatEngine->addStrategy("bspeed");
            break;
        case CLASS_PALADIN:
        case CLASS_HUNTER:
        case CLASS_SHAMAN:
            nonCombatEngine->addStrategy("bmana");
            break;
        case CLASS_ROGUE:
            nonCombatEngine->addStrategy("stealth");
            break;
        case CLASS_MAGE:
            if (tab > 1)
                nonCombatEngine->addStrategy("bdps");
            else
                nonCombatEngine->addStrategy("bmana");
            break;
        case CLASS_WARLOCK:
            if (tab == 0)
            {
                if (player->getLevel() > 30)
                    nonCombatEngine->addStrategies("felhunter", NULL);
                else
                    nonCombatEngine->addStrategies("imp", NULL);
            }
            if (tab == 1)
            {
             if (player->getLevel() >= 50)
                    nonCombatEngine->addStrategies("felguard", NULL);
                else nonCombatEngine->addStrategies("voidwalker", NULL);
            }
            else
            {
                nonCombatEngine->addStrategies("imp", NULL);
            }
    }
    nonCombatEngine->addStrategies("nc", "attack weak", "food", "stay", "chat",
            "default", "quest", "loot", "gather", "duel", "emote", NULL);

    if (sRandomPlayerbotMgr.IsRandomBot(player) && !player->GetGroup())
    {
        //nonCombatEngine->ChangeStrategy(sPlayerbotAIConfig.randomBotNonCombatStrategies);
        //debug only
        nonCombatEngine->addStrategies("move random", "grind", "food", NULL);
    }

}

Engine* AiFactory::createNonCombatEngine(Player* player, PlayerbotAI* const facade, AiObjectContext* AiObjectContext) {
	Engine* nonCombatEngine = new Engine(facade, AiObjectContext);

    AddDefaultNonCombatStrategies(player, facade, nonCombatEngine);
	return nonCombatEngine;
}

void AiFactory::AddDefaultDeadStrategies(Player* player, PlayerbotAI* const facade, Engine* deadEngine)
{
    deadEngine->addStrategies("dead", "stay", "chat", "default", "follow", NULL);
    if (sRandomPlayerbotMgr.IsRandomBot(player) && !player->GetGroup())
    {
        deadEngine->removeStrategy("follow");
    }
}

void AiFactory::AddDefaultMobileStrategies(Player* player, PlayerbotAI* const facade, Engine* mobileEngine)
{
    mobileEngine->addStrategies("mobile", "stay", "chat", "default", "follow", NULL);
}


Engine* AiFactory::createDeadEngine(Player* player, PlayerbotAI* const facade, AiObjectContext* AiObjectContext) {
    Engine* deadEngine = new Engine(facade, AiObjectContext);
    AddDefaultDeadStrategies(player, facade, deadEngine);
    return deadEngine;
}
