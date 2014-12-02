#pragma once
#include "../actions/GenericActions.h"

namespace ai
{
    // battle
    class CastBattleMeleeSpellAction : public CastMeleeSpellAction {
    public:
        CastBattleMeleeSpellAction(PlayerbotAI* ai, string spell) : CastMeleeSpellAction(ai, spell) {}
        virtual NextAction** getPrerequisites() {
            return NextAction::merge( NextAction::array(0, new NextAction("battle stance"), NULL), CastMeleeSpellAction::getPrerequisites());
        }
    };

    //berserker
    class CastBerserkerMeleeSpellAction : public CastMeleeSpellAction {
    public:
        CastBerserkerMeleeSpellAction(PlayerbotAI* ai, string spell) : CastMeleeSpellAction(ai, spell) {}
        virtual NextAction** getPrerequisites() {
            return NextAction::merge( NextAction::array(0, new NextAction("berserker stance"), NULL), CastMeleeSpellAction::getPrerequisites());
        }
    };

    // defensive
    class CastDefensiveMeleeSpellAction : public CastMeleeSpellAction {
    public:
        CastDefensiveMeleeSpellAction(PlayerbotAI* ai, string spell) : CastMeleeSpellAction(ai, spell) {}
        virtual NextAction** getPrerequisites() {
            return NextAction::merge( NextAction::array(0, new NextAction("defensive stance"), NULL), CastMeleeSpellAction::getPrerequisites());
        }
    };

    // all
    class CastHeroicStrikeAction : public CastMeleeSpellAction {
    public:
        CastHeroicStrikeAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "heroic strike") {}
        virtual bool isUseful() { return CastMeleeSpellAction::isUseful() && AI_VALUE2(uint8, "rage", "self target") > 40; }
    };

    // all
    class CastCleaveAction : public CastMeleeSpellAction {
    public:
        CastCleaveAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "cleave") {}
    };

    // battle, berserker
    class CastMockingBlowAction : public CastMeleeSpellAction {
    public:
        CastMockingBlowAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "mocking blow") {}
    };

    class CastBloodthirstAction : public CastMeleeSpellAction {
    public:
        CastBloodthirstAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "bloodthirst") {}

        virtual NextAction** getAlternatives();
    };

    // battle, berserker
    class CastExecuteAction : public CastMeleeSpellAction {
    public:
        CastExecuteAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "execute") {}

        virtual bool isUseful()
	    {
	        return CastMeleeSpellAction::isUseful() && AI_VALUE2(uint8, "health", "current target") < 20;
	    }
    };

    // battle
    class CastOverpowerAction : public CastBattleMeleeSpellAction {
    public:
        CastOverpowerAction(PlayerbotAI* ai) : CastBattleMeleeSpellAction(ai, "overpower") {}
    };

    // battle, berserker
    class CastHamstringAction : public CastMeleeSpellAction {
    public:
        CastHamstringAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "hamstring") {}
    };
    // battle, berserker
    class CastMortalStrikeAction : public CastMeleeSpellAction {
    public:
        CastMortalStrikeAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "mortal strike") {}

        virtual NextAction** getAlternatives();
    };
    // berserker
    class CastWhirlwindAction : public CastBerserkerMeleeSpellAction {
    public:
        CastWhirlwindAction(PlayerbotAI* ai) : CastBerserkerMeleeSpellAction(ai, "whirlwind") {}
    };
    // Intercept
    class CastInterceptAction : public CastBerserkerMeleeSpellAction {
    public:
        CastInterceptAction(PlayerbotAI* ai) :CastBerserkerMeleeSpellAction(ai, "intercept") {}
    };

    // battle, berserker
    class CastBladestormAction : public CastMeleeSpellAction {
    public:
        CastBladestormAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "bladestorm") {}
    };

    // defensive
    class CastTauntAction : public CastSpellAction {
    public:
        CastTauntAction(PlayerbotAI* ai) : CastSpellAction(ai, "taunt") {}
        virtual NextAction** getPrerequisites() {
            return NextAction::merge( NextAction::array(0, new NextAction("defensive stance"), NULL), CastSpellAction::getPrerequisites());
        }
    };

    // defensive
    class CastShieldBlockAction : public CastBuffSpellAction {
    public:
        CastShieldBlockAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "shield block") {}
		virtual NextAction** getPrerequisites() {
			return NextAction::merge( NextAction::array(0, new NextAction("defensive stance"), NULL), CastSpellAction::getPrerequisites());
		}
    };

    // defensive
    class CastShieldWallAction : public CastDefensiveMeleeSpellAction {
    public:
        CastShieldWallAction(PlayerbotAI* ai) : CastDefensiveMeleeSpellAction(ai, "shield wall") {}
    };

    class CastBloodrageAction : public CastBuffSpellAction {
    public:
        CastBloodrageAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "bloodrage") {}
    };

    class CastRecklessnessAction : public CastBuffSpellAction {
    public:
        CastRecklessnessAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "recklessness") {}
    };

    class CastRetaliationAction : public CastBuffSpellAction {
    public:
        CastRetaliationAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "retaliation") {}
    };


    // defensive
    class CastDevastateAction : public CastDefensiveMeleeSpellAction {
    public:
        CastDevastateAction(PlayerbotAI* ai) : CastDefensiveMeleeSpellAction(ai, "devastate") {}
    };

    class CastSpellReflectAction : public CastDefensiveMeleeSpellAction {
    public:
        CastSpellReflectAction(PlayerbotAI* ai) : CastDefensiveMeleeSpellAction(ai, "spell reflect") {}
    };

    // all
    class CastSlamAction : public CastMeleeSpellAction {
    public:
        CastSlamAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "slam") {}
    };

	// all
	class CastShieldSlamAction : public CastMeleeSpellAction {
	public:
		CastShieldSlamAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "shield slam") {}
	};

    // after dodge
    BEGIN_MELEE_SPELL_ACTION(CastRevengeAction, "revenge")
        virtual NextAction** getPrerequisites();
    END_SPELL_ACTION()


    //debuffs
    BEGIN_DEBUFF_ACTION(CastRendAction, "rend")
        virtual NextAction** getPrerequisites();
    END_SPELL_ACTION()

    class CastRendOnAttackerAction : public CastDebuffSpellOnAttackerAction
    {
    public:
        CastRendOnAttackerAction(PlayerbotAI* ai) : CastDebuffSpellOnAttackerAction(ai, "rend") {}
        virtual NextAction** getPrerequisites();
    };

    BEGIN_DEBUFF_ACTION(CastDisarmAction, "disarm")
        virtual NextAction** getPrerequisites();
    END_SPELL_ACTION()

    BEGIN_DEBUFF_ACTION(CastSunderArmorAction, "sunder armor") // 5 times
        virtual NextAction** getPrerequisites();
    END_SPELL_ACTION()

    class CastDemoralizingShoutAction : public CastDebuffSpellAction {
    public:
        CastDemoralizingShoutAction(PlayerbotAI* ai) : CastDebuffSpellAction(ai, "demoralizing shout") {}
    };

    BEGIN_MELEE_SPELL_ACTION(CastChallengingShoutAction, "challenging shout")
    END_SPELL_ACTION()

    // stuns
    BEGIN_MELEE_SPELL_ACTION(CastShieldBashAction, "shield bash")
    END_SPELL_ACTION()

    BEGIN_MELEE_SPELL_ACTION(CastIntimidatingShoutAction, "intimidating shout")
    END_SPELL_ACTION()

    BEGIN_MELEE_SPELL_ACTION(CastThunderClapAction, "thunder clap")
    END_SPELL_ACTION()

    // buffs
	class CastBattleShoutAction : public CastBuffSpellAction {
	public:
		CastBattleShoutAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "battle shout") {}

        virtual NextAction** getAlternatives();
        virtual bool isUseful()
	    {
	        return !ai->HasAura("blessing of might", AI_VALUE(Unit*, "self target"));
	    }
	};

	class CastCommandingShoutAction : public CastBuffSpellAction {
	public:
		CastCommandingShoutAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "commanding shout") {}

        virtual NextAction** getAlternatives();
        virtual bool isUseful()
	    {
	        return !ai->HasAura("blood pact", AI_VALUE(Unit*, "self target"));
	    }
	};

    class CastSweepingStrikesAction : public CastBuffSpellAction {
	public:
		CastSweepingStrikesAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "sweeping strikes") {}
	};

	class CastDefensiveStanceAction : public CastBuffSpellAction {
	public:
		CastDefensiveStanceAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "defensive stance") {}
	};

	class CastBattleStanceAction : public CastBuffSpellAction {
	public:
		CastBattleStanceAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "battle stance") {}
	};

	class CastBerserkerStanceAction : public CastBuffSpellAction {
	public:
		CastBerserkerStanceAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "berserker stance") {}
	};

    BEGIN_RANGED_SPELL_ACTION(CastChargeAction, "charge")
    END_SPELL_ACTION()

    BEGIN_RANGED_SPELL_ACTION(CastShatteringThrowAction, "shattering throw")
    END_SPELL_ACTION()

    BEGIN_RANGED_SPELL_ACTION(CastHeroicThrowAction, "heroic throw")
    END_SPELL_ACTION()

	class CastDeathWishAction : public CastBuffSpellAction {
	public:
		CastDeathWishAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "death wish") {}
	};

	class CastBerserkerRageAction : public CastBuffSpellAction {
	public:
		CastBerserkerRageAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "berserker rage") {}
	};

	class CastHeroicFuryAction : public CastBuffSpellAction {
	public:
		CastHeroicFuryAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "heroic fury") {}
	};

	class CastLastStandAction : public CastBuffSpellAction {
	public:
		CastLastStandAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "last stand") {}
	};

	// defensive
	class CastShockwaveAction : public CastDefensiveMeleeSpellAction {
	public:
		CastShockwaveAction(PlayerbotAI* ai) : CastDefensiveMeleeSpellAction(ai, "shockwave") {}
	};

	// defensive
	class CastConcussionBlowAction : public CastDefensiveMeleeSpellAction {
	public:
		CastConcussionBlowAction(PlayerbotAI* ai) : CastDefensiveMeleeSpellAction(ai, "concussion blow") {}
	};

	BEGIN_MELEE_SPELL_ACTION(CastVictoryRushAction, "victory rush")
	END_SPELL_ACTION()

    class CastShieldBashOnEnemyHealerAction : public CastSpellOnEnemyHealerAction
    {
    public:
        CastShieldBashOnEnemyHealerAction(PlayerbotAI* ai) : CastSpellOnEnemyHealerAction(ai, "shield bash") {}
    };

    class CastInterveneOnPartyAction : public BuffOnPartyAction {
	public:
		CastInterveneOnPartyAction(PlayerbotAI* ai) : BuffOnPartyAction(ai, "intervene") {}
	};

	class CastVigilanceOnPartyAction : public BuffOnPartyAction {
	public:
		CastVigilanceOnPartyAction(PlayerbotAI* ai) : BuffOnPartyAction(ai, "vigilance") {}
	};
}
