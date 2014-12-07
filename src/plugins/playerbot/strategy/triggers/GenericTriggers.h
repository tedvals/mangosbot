#pragma once
#include "../Trigger.h"
#include "../../PlayerbotAIConfig.h"

#define BUFF_TRIGGER(clazz, spell, action) \
    class clazz : public BuffTrigger \
    { \
    public: \
        clazz(PlayerbotAI* ai) : BuffTrigger(ai, spell) {} \
    };

#define BUFF_ON_PARTY_TRIGGER(clazz, spell, action) \
    class clazz : public BuffOnPartyTrigger \
    { \
    public: \
        clazz(PlayerbotAI* ai) : BuffOnPartyTrigger(ai, spell) {}  \
    };

#define DEBUFF_TRIGGER(clazz, spell, action) \
    class clazz : public DebuffTrigger \
    { \
    public: \
        clazz(PlayerbotAI* ai) : DebuffTrigger(ai, spell) {} \
    };

namespace ai
{
	class StatAvailable : public Trigger
	{
	public:
		StatAvailable(PlayerbotAI* ai, int amount, string name = "stat available") : Trigger(ai, name)
		{
			this->amount = amount;
		}

	protected:
		int amount;
	};

	class RageAvailable : public StatAvailable
    {
    public:
        RageAvailable(PlayerbotAI* ai, int amount) : StatAvailable(ai, amount, "rage available") {}
        virtual bool IsActive();
    };

    class LightRageAvailableTrigger : public RageAvailable
    {
    public:
        LightRageAvailableTrigger(PlayerbotAI* ai) : RageAvailable(ai, 20) {}
    };

    class MediumRageAvailableTrigger : public RageAvailable
    {
    public:
        MediumRageAvailableTrigger(PlayerbotAI* ai) : RageAvailable(ai, 40) {}
    };

    class HighRageAvailableTrigger : public RageAvailable
    {
    public:
        HighRageAvailableTrigger(PlayerbotAI* ai) : RageAvailable(ai, 60) {}
    };

	class EnergyAvailable : public StatAvailable
	{
	public:
		EnergyAvailable(PlayerbotAI* ai, int amount) : StatAvailable(ai, amount, "energy available") {}
		virtual bool IsActive();
	};

    class LightEnergyAvailableTrigger : public EnergyAvailable
    {
    public:
        LightEnergyAvailableTrigger(PlayerbotAI* ai) : EnergyAvailable(ai, 20) {}
    };

    class MediumEnergyAvailableTrigger : public EnergyAvailable
    {
    public:
        MediumEnergyAvailableTrigger(PlayerbotAI* ai) : EnergyAvailable(ai, 40) {}
    };

    class HighEnergyAvailableTrigger : public EnergyAvailable
    {
    public:
        HighEnergyAvailableTrigger(PlayerbotAI* ai) : EnergyAvailable(ai, 60) {}
    };

	class ComboPointsAvailableTrigger : public StatAvailable
	{
	public:
	    ComboPointsAvailableTrigger(PlayerbotAI* ai, int amount = 5) : StatAvailable(ai, amount, "combo points available") {}
		virtual bool IsActive();
	};

	class ComboPointAvailableTrigger : public StatAvailable
	{
	public:
	    ComboPointAvailableTrigger(PlayerbotAI* ai, int amount = 1) : StatAvailable(ai, amount, "combo point available") {}
		virtual bool IsActive();
	};

	class LoseAggroTrigger : public Trigger {
	public:
		LoseAggroTrigger(PlayerbotAI* ai) : Trigger(ai, "lose aggro") {}
		virtual bool IsActive();
	};

	class HasAggroTrigger : public Trigger {
	public:
	    HasAggroTrigger(PlayerbotAI* ai) : Trigger(ai, "have aggro") {}
		virtual bool IsActive();
	};

	class SpellTrigger : public Trigger
	{
	public:
		SpellTrigger(PlayerbotAI* ai, string spell, int checkInterval = 1) : Trigger(ai, spell, checkInterval)
		{
			this->spell = spell;
		}

		virtual string GetTargetName() { return "current target"; }
		virtual string getName() { return spell; }
		virtual bool IsActive();

	protected:
		string spell;
	};

	class SpellCanBeCastTrigger : public SpellTrigger
	{
	public:
		SpellCanBeCastTrigger(PlayerbotAI* ai, string spell) : SpellTrigger(ai, spell) {}
		virtual bool IsActive();
	};

	// TODO: check other targets
    class InterruptSpellTrigger : public SpellTrigger
	{
    public:
        InterruptSpellTrigger(PlayerbotAI* ai, string spell) : SpellTrigger(ai, spell) {}
        virtual bool IsActive();
    };


    class AttackerCountTrigger : public Trigger
    {
    public:
        AttackerCountTrigger(PlayerbotAI* ai, int amount, float distance = sPlayerbotAIConfig.sightDistance) : Trigger(ai)
        {
            this->amount = amount;
            this->distance = distance;
        }
    public:
        virtual bool IsActive()
		{
            return AI_VALUE(uint8, "attacker count") >= amount;
        }
        virtual string getName() { return "attacker count"; }

    protected:
        int amount;
        float distance;
    };

    class HasAttackersTrigger : public AttackerCountTrigger
    {
    public:
        HasAttackersTrigger(PlayerbotAI* ai) : AttackerCountTrigger(ai, 1) {}
    };

    class MyAttackerCountTrigger : public AttackerCountTrigger
    {
    public:
        MyAttackerCountTrigger(PlayerbotAI* ai, int amount) : AttackerCountTrigger(ai, amount) {}
    public:
        virtual bool IsActive();
        virtual string getName() { return "my attacker count"; }
    };

    class MediumThreatTrigger : public MyAttackerCountTrigger
    {
    public:
        MediumThreatTrigger(PlayerbotAI* ai) : MyAttackerCountTrigger(ai, 2) {}
    };

    class AoeTrigger : public AttackerCountTrigger
    {
    public:
        AoeTrigger(PlayerbotAI* ai, int amount = 3, float range = 15.0f) : AttackerCountTrigger(ai, amount)
        {
            this->range = range;
        }
    public:
        virtual bool IsActive();
        virtual string getName() { return "aoe"; }

    private:
        float range;
    };

    class NoFoodTrigger : public Trigger {
    public:
        NoFoodTrigger(PlayerbotAI* ai) : Trigger(ai, "no food trigger") {}
        virtual bool IsActive() { return AI_VALUE2(list<Item*>, "inventory items", "food").empty(); }
    };

    class NoDrinkTrigger : public Trigger {
    public:
        NoDrinkTrigger(PlayerbotAI* ai) : Trigger(ai, "no drink trigger") {}
        virtual bool IsActive() { return AI_VALUE2(list<Item*>, "inventory items", "drink").empty(); }
    };

    class NoAoeTrigger : public AoeTrigger
    {
    public:
        NoAoeTrigger(PlayerbotAI* ai) : AoeTrigger(ai, 1, 12.0f) {}
    };

    class LightAoeTrigger : public AoeTrigger
    {
    public:
        LightAoeTrigger(PlayerbotAI* ai) : AoeTrigger(ai, 2, 15.0f) {}
    };

    class MediumAoeTrigger : public AoeTrigger
    {
    public:
        MediumAoeTrigger(PlayerbotAI* ai) : AoeTrigger(ai, 3, 17.0f) {}
    };

    class HighAoeTrigger : public AoeTrigger
    {
    public:
        HighAoeTrigger(PlayerbotAI* ai) : AoeTrigger(ai, 4, 20.0f) {}
    };

    class BuffTrigger : public SpellTrigger
    {
    public:
        BuffTrigger(PlayerbotAI* ai, string spell) : SpellTrigger(ai, spell, 5) {}
    public:
		virtual string GetTargetName() { return "self target"; }
        virtual bool IsActive();
    };

    class BuffOnPartyTrigger : public BuffTrigger
    {
    public:
        BuffOnPartyTrigger(PlayerbotAI* ai, string spell) : BuffTrigger(ai, spell) {}
    public:
		virtual Value<Unit*>* GetTargetValue();
    };

    BEGIN_TRIGGER(NoAttackersTrigger, Trigger)
    END_TRIGGER()

    BEGIN_TRIGGER(NoTargetTrigger, Trigger)
    END_TRIGGER()

    BEGIN_TRIGGER(InvalidTargetTrigger, Trigger)
    END_TRIGGER()

    class TargetInSightTrigger : public Trigger {
    public:
        TargetInSightTrigger(PlayerbotAI* ai) : Trigger(ai, "target in sight") {}
        virtual bool IsActive() { return AI_VALUE(Unit*, "grind target"); }
    };

    class DebuffTrigger : public BuffTrigger
    {
    public:
        DebuffTrigger(PlayerbotAI* ai, string spell) : BuffTrigger(ai, spell) {
			checkInterval = 1;
		}
    public:
		virtual string GetTargetName() { return "current target"; }
        virtual bool IsActive();
    };

    class DebuffOnAttackerTrigger : public DebuffTrigger
    {
    public:
        DebuffOnAttackerTrigger(PlayerbotAI* ai, string spell) : DebuffTrigger(ai, spell) {}
    public:
        virtual Value<Unit*>* GetTargetValue();
        virtual string getName() { return spell + " on attacker"; }
    };

	class BoostTrigger : public BuffTrigger
	{
	public:
		BoostTrigger(PlayerbotAI* ai, string spell, float balance = 50) : BuffTrigger(ai, spell)
		{
			this->balance = balance;
		}
	public:
		virtual bool IsActive();

	protected:
		float balance;
	};

    class RandomTrigger : public Trigger
    {
    public:
        RandomTrigger(PlayerbotAI* ai, int probability = 200) : Trigger(ai)
        {
            this->probability = probability;
        }
    public:
        virtual bool IsActive();
        virtual string getName() { return "random"; }

    protected:
        int probability;
    };

    class SeldomTrigger : public RandomTrigger
    {
    public:
        SeldomTrigger(PlayerbotAI* ai) : RandomTrigger(ai, 9000) {}
        virtual string getName() { return "seldom"; }
    };

    class OftenTrigger : public RandomTrigger
    {
    public:
        OftenTrigger(PlayerbotAI* ai) : RandomTrigger(ai, 50) {}
        virtual string getName() { return "often"; }
    };

    class AndTrigger : public Trigger
    {
    public:
        AndTrigger(PlayerbotAI* ai, Trigger* ls, Trigger* rs) : Trigger(ai)
        {
            this->ls = ls;
            this->rs = rs;
        }
        virtual ~AndTrigger()
        {
            delete ls;
            delete rs;
        }
    public:
        virtual bool IsActive();
        virtual string getName();

    protected:
        Trigger* ls;
        Trigger* rs;
    };

    class SnareTargetTrigger : public DebuffTrigger
    {
    public:
        SnareTargetTrigger(PlayerbotAI* ai, string aura) : DebuffTrigger(ai, aura) {}
    public:
        virtual bool IsActive();
        virtual string getName() { return "target is moving"; }
    };

	class LowManaTrigger : public Trigger
	{
	public:
		LowManaTrigger(PlayerbotAI* ai) : Trigger(ai, "low mana") {}

		virtual bool IsActive();
	};

	class MediumManaTrigger : public Trigger
	{
	public:
		MediumManaTrigger(PlayerbotAI* ai) : Trigger(ai, "medium mana") {}

		virtual bool IsActive();
	};

    BEGIN_TRIGGER(PanicTrigger, Trigger)
        virtual string getName() { return "panic"; }
    END_TRIGGER()


	class NoPetTrigger : public Trigger
	{
	public:
		NoPetTrigger(PlayerbotAI* ai) : Trigger(ai, "no pet", 5) {}

		virtual bool IsActive() {
			return !AI_VALUE(Unit*, "pet target") && !AI_VALUE2(bool, "mounted", "self target");
		}
	};

	class ItemCountTrigger : public Trigger {
	public:
		ItemCountTrigger(PlayerbotAI* ai, string item, int count) : Trigger(ai, item, 5) {
			this->item = item;
			this->count = count;
		}
	public:
		virtual bool IsActive();
		virtual string getName() { return "item count"; }

	protected:
		string item;
		int count;
	};

	class HasAuraTrigger : public Trigger {
	public:
		HasAuraTrigger(PlayerbotAI* ai, string spell) : Trigger(ai, spell, 5) {}

		virtual string GetTargetName() { return "self target"; }
		virtual bool IsActive();

	};

    class TimerTrigger : public Trigger
    {
    public:
        TimerTrigger(PlayerbotAI* ai, int checkInterval = 5) : Trigger(ai, "timer", checkInterval) {}

    public:
        virtual bool IsActive() { return true; }
    };

	class TankAoeTrigger : public NoAttackersTrigger
	{
	public:
		TankAoeTrigger(PlayerbotAI* ai) : NoAttackersTrigger(ai) {}

	public:
		virtual bool IsActive();

	};

    class IsBehindTargetTrigger : public Trigger
    {
    public:
        IsBehindTargetTrigger(PlayerbotAI* ai) : Trigger(ai) {}

    public:
        virtual bool IsActive();
    };

    class IsNotFacingTargetTrigger : public Trigger
    {
    public:
        IsNotFacingTargetTrigger(PlayerbotAI* ai) : Trigger(ai) {}

    public:
        virtual bool IsActive();
    };

    class HasCcTargetTrigger : public Trigger
    {
    public:
        HasCcTargetTrigger(PlayerbotAI* ai, string name) : Trigger(ai, name) {}

    public:
        virtual bool IsActive();
    };

	class NoMovementTrigger : public Trigger
	{
	public:
		NoMovementTrigger(PlayerbotAI* ai, string name) : Trigger(ai, name) {}

	public:
		virtual bool IsActive();
	};


    class NoPossibleTargetsTrigger : public Trigger
    {
    public:
        NoPossibleTargetsTrigger(PlayerbotAI* ai) : Trigger(ai, "no possible targets") {}

    public:
        virtual bool IsActive();
    };

    class NotLeastHpTargetActiveTrigger : public Trigger
    {
    public:
        NotLeastHpTargetActiveTrigger(PlayerbotAI* ai) : Trigger(ai, "not least hp target active") {}

    public:
        virtual bool IsActive();
    };

    class EnemyPlayerIsAttacking : public Trigger
    {
    public:
        EnemyPlayerIsAttacking(PlayerbotAI* ai) : Trigger(ai, "enemy player is attacking") {}

    public:
        virtual bool IsActive();
    };

    class IsSwimmingTrigger : public Trigger
    {
    public:
        IsSwimmingTrigger(PlayerbotAI* ai) : Trigger(ai, "swimming") {}

    public:
        virtual bool IsActive();
    };

    class HasNearestAddsTrigger : public Trigger
    {
    public:
        HasNearestAddsTrigger(PlayerbotAI* ai) : Trigger(ai, "has nearest adds") {}

    public:
        virtual bool IsActive();
    };

    class HasItemForSpellTrigger : public Trigger
    {
    public:
        HasItemForSpellTrigger(PlayerbotAI* ai, string spell) : Trigger(ai, spell) {}

    public:
        virtual bool IsActive();
    };

    class TargetChangedTrigger : public Trigger
    {
    public:
        TargetChangedTrigger(PlayerbotAI* ai) : Trigger(ai, "target changed") {}

    public:
        virtual bool IsActive();
    };

    class InterruptEnemyHealerTrigger : public SpellTrigger
    {
    public:
        InterruptEnemyHealerTrigger(PlayerbotAI* ai, string spell) : SpellTrigger(ai, spell) {}
    public:
        virtual Value<Unit*>* GetTargetValue();
        virtual string getName() { return spell + " on enemy healer"; }
    };

    class BleedingTrigger : public Trigger {
    public:
        BleedingTrigger(PlayerbotAI* ai) : Trigger(ai, "bleeding", 5) {}
        virtual string GetTargetName() { return "self target"; }
        virtual bool IsActive();
    };

    class PolymorphedTrigger : public Trigger {
    public:
        PolymorphedTrigger(PlayerbotAI* ai) : Trigger(ai, "polymorphed", 5) {}
        virtual string GetTargetName() { return "self target"; }
        virtual bool IsActive();
    };

    class TakesPeriodicDamageTrigger : public Trigger {
    public:
        TakesPeriodicDamageTrigger(PlayerbotAI* ai) : Trigger(ai, "takes periodic damage", 5) {}
        virtual string GetTargetName() { return "self target"; }
        virtual bool IsActive();
    };

    class SnaredTrigger : public Trigger {
    public:
        SnaredTrigger(PlayerbotAI* ai) : Trigger(ai, "snared", 5) {}
        virtual string GetTargetName() { return "self target"; }
        virtual bool IsActive();
    };

    class RootedTrigger : public Trigger {
    public:
        RootedTrigger(PlayerbotAI* ai) : Trigger(ai, "rooted", 5) {}
        virtual string GetTargetName() { return "self target"; }
        virtual bool IsActive();
    };

    class FrozenTrigger : public Trigger {
    public:
        FrozenTrigger(PlayerbotAI* ai) : Trigger(ai, "frozen", 5) {}
        virtual string GetTargetName() { return "self target"; }
        virtual bool IsActive();
    };

    class StunnedTrigger : public Trigger {
    public:
        StunnedTrigger(PlayerbotAI* ai) : Trigger(ai, "stunned", 5) {}
        virtual string GetTargetName() { return "self target"; }
        virtual bool IsActive();
    };

    class TargetSnaredTrigger : public Trigger {
    public:
        TargetSnaredTrigger(PlayerbotAI* ai) : Trigger(ai, "target snared", 5) {}
        virtual string GetTargetName() { return "current target"; }
        virtual bool IsActive();
    };

    class TargetRootedTrigger : public Trigger {
    public:
        TargetRootedTrigger(PlayerbotAI* ai) : Trigger(ai, "target rooted", 5) {}
        virtual string GetTargetName() { return "current target"; }
        virtual bool IsActive();
    };

    class TargetBleedingTrigger : public Trigger {
    public:
        TargetBleedingTrigger(PlayerbotAI* ai) : Trigger(ai, "target bleeding", 5) {}
        virtual string GetTargetName() { return "current target"; }
        virtual bool IsActive();
    };

    class TargetPolymorphedTrigger : public Trigger {
    public:
        TargetPolymorphedTrigger(PlayerbotAI* ai) : Trigger(ai, "target polymorphed", 5) {}
        virtual string GetTargetName() { return "current target"; }
        virtual bool IsActive();
    };

    class TargetFrozenTrigger : public Trigger {
    public:
        TargetFrozenTrigger(PlayerbotAI* ai) : Trigger(ai, "target frozen", 5) {}
        virtual string GetTargetName() { return "current target"; }
        virtual bool IsActive();
    };

    class TargetFleeingTrigger : public Trigger {
    public:
        TargetFleeingTrigger(PlayerbotAI* ai) : Trigger(ai, "target fleeing", 5) {}
        virtual string GetTargetName() { return "current target"; }
        virtual bool IsActive();
    };

    class TargetStunnedTrigger : public Trigger {
    public:
        TargetStunnedTrigger(PlayerbotAI* ai) : Trigger(ai, "target stunned", 5) {}
        virtual string GetTargetName() { return "current target"; }
        virtual bool IsActive();
    };

    class TargetNotSnaredTrigger : public Trigger {
    public:
        TargetNotSnaredTrigger(PlayerbotAI* ai) : Trigger(ai, "target not snared", 5) {}
        virtual string GetTargetName() { return "current target"; }
        virtual bool IsActive();
    };

    class TargetNotRootedTrigger : public Trigger {
    public:
        TargetNotRootedTrigger(PlayerbotAI* ai) : Trigger(ai, "target not rooted", 5) {}
        virtual string GetTargetName() { return "current target"; }
        virtual bool IsActive();
    };

    class TargetNotFrozenTrigger : public Trigger {
    public:
        TargetNotFrozenTrigger(PlayerbotAI* ai) : Trigger(ai, "target not frozen", 5) {}
        virtual string GetTargetName() { return "current target"; }
        virtual bool IsActive();
    };

    class TargetNotStunnedTrigger : public Trigger {
    public:
        TargetNotStunnedTrigger(PlayerbotAI* ai) : Trigger(ai, "target not stunned", 5) {}
        virtual string GetTargetName() { return "current target"; }
        virtual bool IsActive();
    };

    class TargetNotBleedingTrigger : public Trigger {
    public:
        TargetNotBleedingTrigger(PlayerbotAI* ai) : Trigger(ai, "target not bleeding", 5) {}
        virtual string GetTargetName() { return "current target"; }
        virtual bool IsActive();
    };

    class TargetNotPolymorphedTrigger : public Trigger {
    public:
        TargetNotPolymorphedTrigger(PlayerbotAI* ai) : Trigger(ai, "target not polymorphed", 5) {}
        virtual string GetTargetName() { return "current target"; }
        virtual bool IsActive();
    };

    class PartyMemberRootedTrigger : public Trigger {
	public:
		PartyMemberRootedTrigger(PlayerbotAI* ai) : Trigger(ai, "rooted", 5) {}
        virtual string GetTargetName() { return "party member rooted"; }
		virtual bool IsActive();
	};

	class PartyMemberSnaredTrigger : public Trigger {
	public:
		PartyMemberSnaredTrigger(PlayerbotAI* ai) : Trigger(ai, "snared", 5) {}
        virtual string GetTargetName() { return "party member snared"; }
		virtual bool IsActive();
	};

	class PartyMemberPolymorphedTrigger : public Trigger {
	public:
		PartyMemberPolymorphedTrigger(PlayerbotAI* ai) : Trigger(ai, "polymorphed", 5) {}
        virtual string GetTargetName() { return "party member polymorphed"; }
		virtual bool IsActive();
	};

	class PartyMemberFrozenTrigger : public Trigger {
	public:
		PartyMemberFrozenTrigger(PlayerbotAI* ai) : Trigger(ai, "frozen", 5) {}
        virtual string GetTargetName() { return "party member frozen"; }
		virtual bool IsActive();
	};
}

#include "RangeTriggers.h"
#include "HealthTriggers.h"
#include "CureTriggers.h"
