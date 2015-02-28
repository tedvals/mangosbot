#pragma once
#include "../actions/GenericActions.h"

namespace ai
{
    //frost
    class CastFrostMeleeSpellAction : public CastMeleeSpellAction {
    public:
        CastFrostMeleeSpellAction(PlayerbotAI* ai, string spell) : CastMeleeSpellAction(ai, spell) {}
        virtual bool IsInstant() {return true;}
        virtual NextAction** getPrerequisites() {
            return NextAction::merge( NextAction::array(0, new NextAction("frost presense"), NULL), CastMeleeSpellAction::getPrerequisites());
        }
    };

    //blood
    class CastBloodMeleeSpellAction : public CastMeleeSpellAction {
    public:
        CastBloodMeleeSpellAction(PlayerbotAI* ai, string spell) : CastMeleeSpellAction(ai, spell) {}
        virtual bool IsInstant() {return true;}
        virtual NextAction** getPrerequisites() {
            return NextAction::merge( NextAction::array(0, new NextAction("blood presense"), NULL), CastMeleeSpellAction::getPrerequisites());
        }
    };

    // unholy
    class CastUnholyMeleeSpellAction : public CastMeleeSpellAction {
    public:
        CastUnholyMeleeSpellAction(PlayerbotAI* ai, string spell) : CastMeleeSpellAction(ai, spell) {}
        virtual bool IsInstant() {return true;}
        virtual NextAction** getPrerequisites() {
            return NextAction::merge( NextAction::array(0, new NextAction("unholy presence"), NULL), CastMeleeSpellAction::getPrerequisites());
        }
    };

    // all
    class CastBloodStrikeAction : public CastMeleeSpellAction {
    public:
        CastBloodStrikeAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "blood strike") {}
        virtual bool IsInstant() {return true;}
        virtual bool isUseful() { return CastMeleeSpellAction::isUseful()}
    };

    class CastRuneStrikeAction : public CastMeleeSpellAction {
    public:
        CastRuneStrikeAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "rune strike") {}
        virtual bool IsInstant() {return true;}
	virtual NextAction** getAlternatives();
        virtual bool isUseful() { return CastMeleeSpellAction::isUseful() && AI_VALUE2(uint8, "runic power", "self target") > 40; }
    };

    class CastFrostStrikeAction : public CastMeleeSpellAction {
    public:
        CastFrostStrikeAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "frost strike") {}
        virtual bool IsInstant() {return true;}
	virtual NextAction** getAlternatives();        
	virtual bool isUseful() { return CastMeleeSpellAction::isUseful() && AI_VALUE2(uint8, "runic power", "self target") > 40; }
    };

    
    class CastHowlingBlastAction : public CastMeleeSpellAction {
    public:
        CastHowlingBlastAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "howling blast") {}

        virtual bool IsInstant() {return true;}
	virtual NextAction** getAlternatives();
        virtual bool isUseful() { return CastMeleeSpellAction::isUseful() && AI_VALUE(uint8, "melee attacker count") > 1; }
    };

    class CastPestilenceAction : public CastSpellAction {
    public:
        CastPestilenceAction(PlayerbotAI* ai) : CastSpellAction(ai, "pestilence") {}

        virtual bool IsInstant() {return true;}
        virtual bool isUseful() { return CastSpellAction::isUseful() && AI_VALUE(uint8, "melee attacker count") > 1 && ai->HasAura("frost fever", getTarget()) && ai->HasAura("blood plague", getTarget()); }
    };

    class CastIcyTouchAction : public CastSpellAction {
    public:
        CastIcyTouchAction(PlayerbotAI* ai) : CastSpellAction(ai, "icy touch") {}
        virtual bool IsInstant() {return true;}
    };

    class CastScourgeStrikeAction : public CastMeleeSpellAction {
    public:
        CastScourgeStrikeAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "scourge strike") {}
        virtual bool IsInstant() {return true;}
	virtual NextAction** getPrerequisites();
	virtual NextAction** getAlternatives();
    };

    class CastObliterateAction : public CastMeleeSpellAction {
    public:
        CastObliterateAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "obliterate") {}
	virtual NextAction** getPrerequisites();
	virtual bool IsInstant() {return true;}
    };
    
    class CastChainsOfIceAction : public CastSpellAction {
    public:
        CastChainsOfIceAction(PlayerbotAI* ai) : CastSpellAction(ai, "chains of ice") {}

        virtual bool isUseful()
        {
           return CastMeleeAction::isUseful() && !ai->HasAnyAuraOf(GetTarget(), "slow", "wing clip", "frost shock", "crippling poison", "hamstring", NULL);
        }
        virtual bool IsInstant() {return true;}
    };

    class CastPlagueStrikeAction : public CastMeleeSpellAction {
    public:
        CastPlagueStrikeAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "plague strike") {}
	virtual NextAction** getPrerequisites();
        virtual bool IsInstant() {return true;}
    };

    class CastDeathStrikeAction : public CastMeleeSpellAction {
    public:
        CastDeathStrikeAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "death strike") {}
	virtual NextAction** getPrerequisites();
        virtual bool IsInstant() {return true;}
    };
    
    class CastDeathCoilAction : public CastSpellAction {
    public:
        CastDeathCoilAction(PlayerbotAI* ai) :CastSpellAction(ai, "death coil") {}
        virtual bool IsInstant() {return true;}
    };

    class CastHeartStrikeAction : public CastMeleeSpellAction {
    public:
        CastHeartStrikeAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "heart strike") {}
        virtual bool IsInstant() {return true;}
    };

    class CastDarkCommandAction : public CastSpellAction {
    public:
        CastDarkCommandAction(PlayerbotAI* ai) : CastSpellAction(ai, "dark command") {}
        virtual bool IsInstant() {return true;}
    };

    // defensive
    class CastBoneShieldAction : public CastBuffSpellAction {
    public:
        CastBoneShieldAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "bone shield") {}
        virtual bool IsInstant() {return true;}
    };

    class CastIceboundFortitudeAction : public CastBuffSpellAction {
    public:
        CastIceboundFortitude(PlayerbotAI* ai) : CastBuffSpellAction(ai, "icebound fortitude") {}
        virtual bool IsInstant() {return true;}
    };

    class CastVampiricBloodAction : public CastBuffSpellAction {
    public:
        CastVampiricBloodAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "vampiric blood") {}
	virtual NextAction** getAlternatives();        
	virtual bool IsInstant() {return true;}
    };

    class CastHornOfWinterAction : public CastBuffSpellAction {
    public:
        CastHornOfWinterAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "horn of winter") {}
        virtual bool IsInstant() {return true;}
    };

    class CastBloodBoilAction : public CastMeleeSpellAction {
    public:
        CastBloodBoilAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "blood boil") {}
        virtual bool IsInstant() {return true;}

	virtual bool isUseful() { return CastMeleeSpellAction::isUseful() && AI_VALUE(uint8, "melee attacker count") > 2; }
    };

    class CastCorpseExplosionAction : public CastSpellAction {
    public:
        CastCorspeExplosionAction(PlayerbotAI* ai) : CastDefensiveMeleeSpellAction(ai, "corpse explosion") {}
        virtual bool IsInstant() {return true;}
    };

    // all
    class CastRaiseDeadAction : public CastSpellAction {
    public:
        CastRaiseDeadAction(PlayerbotAI* ai) : CastSpellAction(ai, "raise dead") {}
    };


    class CastArmyOfTheDeadAction : public CastSpellAction {
    public:
        CastArmyOfTheDeadAction(PlayerbotAI* ai) : CastSpellAction(ai, "army of the dead") {}
    };

	// all
	class CastRuneTapAction : public CastHealingSpellAction {
	public:
		CastRuneTapAction(PlayerbotAI* ai) : CastHealingSpellAction(ai, "rune tap") {}
		virtual bool IsInstant() {return true;}
	};

	// all
	class CastDeathPactAction : public CastHealingSpellAction {
	public:
		CastDeathPactAction(PlayerbotAI* ai) : CastHealingSpellAction(ai, "death pact") {}
		virtual bool IsInstant() {return true;}
	};


    //debuffs
    BEGIN_DEBUFF_ACTION(CastMarkOfBloodAction, "mark of blood")
        virtual bool IsInstant() {return true;}
    END_SPELL_ACTION()

    class CastHungeringColdAction : public CastDebuffSpellAction {
    public:
        CastHungeringColdAction(PlayerbotAI* ai) : CastDebuffSpellAction(ai, "hungering cold") {}
        virtual bool IsInstant() {return true;}
    };

    
    BEGIN_SPELL_ACTION(CastMindFreezeAction, "mind freeze")
    virtual bool IsInstant() {return true;}
    virtual NextAction** getAlternatives();
    virtual bool isUseful() { return CastMeleeSpellAction::isUseful() && AI_VALUE2(uint8, "runic power", "self target") > 20; }
    END_SPELL_ACTION()

    BEGIN_SPELL_ACTION(CastStrangulateAction, "strangulate")
    virtual bool IsInstant() {return true;}
    END_SPELL_ACTION()

    BEGIN_SPELL_ACTION(CastEmpowerRuneWeaponAction, "empower rune weapon")
    virtual bool IsInstant() {return true;}
    END_SPELL_ACTION()

    // buffs
	class CastSummonGhoulAction : public CastSpellAction {
	public:
		CastSummonGhoulAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "summon ghoul") {}

        virtual bool IsInstant() {return true;}
	};

	class CastSummonGargoyleAction : public CastBuffSpellAction {
	public:
		CastSummonGargoyleAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "summon gargoyle") {}

        virtual bool IsInstant() {return true;}
       	};

    	class CastUnbreakableArmorAction : public CastBuffSpellAction {
	public:
		CastUnbreakableArmorAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "unbreakable armor") {}
		virtual bool IsInstant() {return true;}
	};

	class CastBloodPresenceAction : public CastBuffSpellAction {
	public:
		CastBloodPresenceAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "blood presence") {}
		virtual bool IsInstant() {return true;}
	};

	class CastFrostPresenceAction : public CastBuffSpellAction {
	public:
		CastFrostPresenceAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "frost presence") {}
		virtual bool IsInstant() {return true;}
	};

	class CastUnholyPresenceAction : public CastBuffSpellAction {
	public:
		UnholyPresence(PlayerbotAI* ai) : CastBuffSpellAction(ai, "unholy presence") {}
		virtual bool IsInstant() {return true;}
	};

    BEGIN_RANGED_SPELL_ACTION(CastDeathGripAction, "death grip")
    virtual bool IsInstant() {return true;}
    END_SPELL_ACTION()

	class CastHysteriaAction : public CastBuffSpellAction {
	public:
		CastHysteriaAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "hysteria") {}
		virtual bool IsInstant() {return true;}
	};

	class CastGhoulFrenzyAction : public CastBuffSpellAction {
	public:
		CastGhoulFrenzyAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "ghoul frenzy") {}
		virtual bool IsInstant() {return true;}
	};

	class CastLichborneAction : public CastBuffSpellAction {
	public:
		CastLichborneAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "lichborne") {}
		virtual bool IsInstant() {return true;}
	};

	class CastAntimagicShellAction : public CastBuffSpellAction {
	public:
		CastAntimagicShellAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "anti-magic shell") {}
		virtual bool IsInstant() {return true;}
	};

	class CastAntimagicZoneAction : public CastBuffSpellAction {
	public:
		CastAntimagicZoneAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "anti-magic zone") {}
		virtual bool IsInstant() {return true;}
	};

	class CastDeathChillAction : public CastBuffSpellAction {
	public:
		CastDeathChillAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "deathchill") {}
		virtual bool IsInstant() {return true;}
	};

	class CastDancingRuneWeaponAction : public CastBuffSpellAction {
	public:
		CastDancingRuneWeapon(PlayerbotAI* ai) : CastBuffSpellAction(ai, "dancing rune weapon") {}
		virtual bool IsInstant() {return true;}
	};

	class CastDeathAndDecayAction : public CastSpellAction {
	public:
		CastDeathAndDecayAction(PlayerbotAI* ai) : CastSpellAction(ai, "death and decay") {}
		virtual bool IsInstant() {return true;}
	};

    class CastMindFreezeOnEnemyHealerAction : public CastSpellOnEnemyHealerAction
    {
    public:
        CastMindFreezeOnEnemyHealerAction(PlayerbotAI* ai) : CastSpellOnEnemyHealerAction(ai, "mind freeze") {}
        virtual bool IsInstant() {return true;}
    };

    class CastStrangulateOnEnemyHealerAction : public CastSpellOnEnemyHealerAction
    {
    public:
        CastStrangulateOnEnemyHealerAction(PlayerbotAI* ai) : CastSpellOnEnemyHealerAction(ai, "strangulate") {}
        virtual bool IsInstant() {return true;}
    };

    class CastHysteriaOnMasterAction : public BuffOnPartyAction
    {
    public:
        CastHysteriaOnMasterAction(PlayerbotAI* ai) : BuffOnPartyAction(ai, "hysteria") {}
        virtual string getName() { return "hysteria on master";}
        virtual string GetTargetName() { return "master target";}
        virtual bool IsInstant() {return true;}
    };

	class CastHysteriaOnPartyAction : public BuffOnPartyAction {
	public:
		CastHysteriaOnPartyAction(PlayerbotAI* ai) : BuffOnPartyAction(ai, "hysteria") {}
		virtual bool IsInstant() {return true;}
	};
}
