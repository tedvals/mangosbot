#include "pch.h"
#include "../../plugins/playerbot/PlayerbotAIConfig.h"
#include "../../plugins/ahbot/AhBot.h"

WorldDatabaseWorkerPool WorldDatabase;                      ///< Accessor to the world database
CharacterDatabaseWorkerPool CharacterDatabase;              ///< Accessor to the character database
LoginDatabaseWorkerPool LoginDatabase;                      ///< Accessor to the realm/login database
uint32 realmID;                                             ///< Id of the realm

int main(int argc, char* argv[])
{

<<<<<<< HEAD
 //   std::string configError;
=======
    /*std::string configError;
>>>>>>> 55b583d1726fe70d55c4b9efab476d3fa0710ae4
    if (!sConfigMgr->LoadInitial("worldserver.conf", configError))
    {
        printf("Error in config file: %s\n", configError.c_str());
        return 1;
    }

    MySQL::Library_Init();

    WorldDatabase.SetConnectionInfo(sConfigMgr->GetStringDefault("WorldDatabaseInfo", ""), 1, 1);
    if (!WorldDatabase.Open())
    {
<<<<<<< HEAD
        printf(("server.worldserver", "Cannot connect to world database");
=======
        printf("Cannot connect to world database");
>>>>>>> 55b583d1726fe70d55c4b9efab476d3fa0710ae4
        return false;
    }
    CharacterDatabase.SetConnectionInfo(sConfigMgr->GetStringDefault("CharacterDatabaseInfo", ""), 1, 1);
    if (!CharacterDatabase.Open())
    {
<<<<<<< HEAD
        printf(("server.worldserver", "Cannot connect to Character database");
=======
        printf("Cannot connect to Character database");
>>>>>>> 55b583d1726fe70d55c4b9efab476d3fa0710ae4
        return false;
    }
    LoginDatabase.SetConnectionInfo(sConfigMgr->GetStringDefault("LoginDatabaseInfo", ""), 1, 1);
    if (!LoginDatabase.Open())
    {
<<<<<<< HEAD
        printf(("server.worldserver", "Cannot connect to Login database");
=======
        printf("Cannot connect to Login database");
>>>>>>> 55b583d1726fe70d55c4b9efab476d3fa0710ae4
        return false;
    }

    //sWorld->SetInitialWorldSettings();
    std::string dataPath = sConfigMgr->GetStringDefault("DataDir", "./");
    if (dataPath.empty() || (dataPath.at(dataPath.length()-1) != '/' && dataPath.at(dataPath.length()-1) != '\\'))
        dataPath.push_back('/');

    ///- Load the DBC files
     TC_LOG_INFO("server.loading", "Initialize data stores...");
     LoadDBCStores(dataPath);

     auctionbot.Init();
*/

    //sPlayerbotAIConfig.Initialize();
    sPlayerbotAIConfig.enabled = true;
    sPlayerbotAIConfig.globalCoolDown = 1000;
    sPlayerbotAIConfig.reactDelay = 100;
    sPlayerbotAIConfig.sightDistance = 40.0f;
    sPlayerbotAIConfig.spellDistance = 25.0f;
    sPlayerbotAIConfig.reactDistance = 100.0f;
    sPlayerbotAIConfig.grindDistance = 50.0f;
    sPlayerbotAIConfig.meleeDistance = ATTACK_DISTANCE;
    sPlayerbotAIConfig.followDistance = ATTACK_DISTANCE;
    sPlayerbotAIConfig.tooCloseDistance = ATTACK_DISTANCE;
    sPlayerbotAIConfig.contactDistance = CONTACT_DISTANCE;
    sPlayerbotAIConfig.lootDistance = 20.0f;
    sPlayerbotAIConfig.criticalHealth = 25;
    sPlayerbotAIConfig.lowHealth = 40;
    sPlayerbotAIConfig.mediumHealth = 60;
    sPlayerbotAIConfig.almostFullHealth = 80;
    sPlayerbotAIConfig.lowMana = 40;
    sPlayerbotAIConfig.mediumMana = 60;
    sPlayerbotAIConfig.iterationsPerTick = 10;
    sPlayerbotAIConfig.randomChangeMultiplier = 1;

    // Create the event manager and test controller
    CPPUNIT_NS::TestResult controller;

    // Add a listener that colllects test result
    CPPUNIT_NS::TestResultCollector result;
    controller.addListener( &result );

    // Add a listener that print dots as test run.
    CPPUNIT_NS::BriefTestProgressListener progress;
    controller.addListener( &progress );

    // Add the top suite to the test runner
    CPPUNIT_NS::TestRunner runner;

    runner.addTest( CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest() );
    runner.run( controller, argc > 1 ? argv[1] : "" );

    // Print test in a compiler compatible format.
    CPPUNIT_NS::CompilerOutputter outputter( &result, CPPUNIT_NS::stdCOut() );
    outputter.write();

    cout.flush();
    return result.wasSuccessful() ? 0 : 1;
}
